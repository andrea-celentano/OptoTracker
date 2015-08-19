#include <iostream>
#include <string>
#include <cmath>

#include "TFile.h"
#include "TTree.h"
#include "TH1D.h"
#include "TH2D.h"
#include "TF1.h"
#include "TCanvas.h"
#include "TLine.h"
#include "TApplication.h"
#include "TROOT.h"
#include "TVector3.h"
#include "TTree.h"
#include "TChain.h"
#include "TSystem.h"
#include "Cintex/Cintex.h"

#include "MarocSetupHandler.hh"
#include "TOpNoviceDetectorLight.hh"
#include "TRecon.hh"
#include "TReconInput.hh"
#include "TReconDefs.hh"

#include "OpNoviceDetectorHit.hh"
#include "OpNoviceDigi.hh"

using namespace std;

#define N0 2048
#define Ntot 128

/*From the command line*/
string fSigName,fBckName,fDetName,fSetupName,fReconName;
string fOutNameRoot,fOutNamePS,fOutName;
int fDoBatch=0;
int fDoRoot=0;
void ParseCommandLine(int argc,char **argv);
void PrintHelp();
TApplication gui("GUI",0,NULL);

double CorrectionPixel(const TVector3 &v0,int iface,int idetector,int ipixel,const TOpNoviceDetectorLight *m_detector);
double poissonf(Double_t*x,Double_t*par){
	return par[0]*TMath::Poisson(x[0],par[1]);
}

int main(int argc,char **argv){
	if (argc==0){
		PrintHelp();
		exit(1);
	}
	ParseCommandLine(argc,argv);
	//Load Cintex and the shared library
	ROOT::Cintex::Cintex::Enable();
	gSystem->Load("libGeometryClassesDict.so");
	gSystem->Load("libOpNoviceClassesDict.so");
	gSystem->Load("libReconstructionClassesDict.so");

	if (fDoBatch)  gROOT->SetBatch();



	if (fSigName.length()==0){
		cerr<<"Missing SIGNAL file name!"<<endl;
		return -1;
	}
	if (fBckName.length()==0){
		cerr<<"Missing BCK file name!"<<endl;
		return -1;
	}
	if (fDetName.length()==0){
		cerr<<"Missing DET file name"<<endl;
		return -1;
	}
	if (fSetupName.length()==0){
		cerr<<"Missing Setup file name"<<endl;
		return -1;
	}
	if (fReconName.length()==0){
		cerr<<"Missing Recon file name"<<endl;
		return -1;
	}
	else if (fReconName.find(".root")!=std::string::npos){
		cout<<"ROOT mode"<<endl;
		fDoRoot=1;
	}
	else{
		cout<<"Model mode";
		fDoRoot=0;
	}
	if (fOutName.length()==0){
		cout<<"Missing OUT file name, auto-selecting"<<endl;
		fOutName=fSigName+".out";
	}
	fOutNameRoot=fOutName+".root";
	fOutNamePS=fOutName+".ps";
	TFile *f1=new TFile(fSigName.c_str());
	TFile *f2=new TFile(fBckName.c_str());

	TFile *fOut=new TFile(fOutNameRoot.c_str(),"recreate");


	TTree *tSig=(TTree*)f1->Get("fTdata");
	TTree *tBck=(TTree*)f2->Get("fTdata");

	Float_t ADC[4096];
	Bool_t hit[4096];
	double PedSig[4096],PedBck[4096];

	double fExp[6][MAX_DETECTORS][64];double fNormExp;
	double fTeo[6][MAX_DETECTORS][64];double fNormTeo;

	Int_t EvtMultiplicity;
	int Nb,Ns,Nped;
	int id;
	int ix,iy,iH8500,iMarocChannel,iMarocCard,iRealDet,iReconDet,iReconFace,iReconPixel;
	int iPad;

	int flagQcut;
	double Q,QSigTot,QBckTot;
	double QSigTotL,QBckTotL;
	double QSigTotR,QBckTotR;

	const double QTotThr=15E3;
	const double QTotLThr=0;
	const double QTotRThr=0;

	double Scale;
	double MeanSig,MeanBck,MeanDiff,MeanDiffCorrected;
	double Gain,F,Corr;
	double min,max;
	TVector3 vin;


	int Nx,Ny;
	TOpNoviceDetectorLight *m_detector=new TOpNoviceDetectorLight(fDetName);
	MarocSetupHandler *m_setup=new MarocSetupHandler(fSetupName);
	TReconInput *m_reconInput=0;
	TRecon *m_recon=0;

	/*MC DATA INPUT CASE*/
	TChain *cMC;
	TF1 *fPoisson;
	vector < TH1D* > hChargeMC[6][MAX_DETECTORS];
	vector<OpNoviceDigi*> *digi=NULL;
	int NeventsMC;
	int Nhits,faceNumber,detNumber,pixelNumber;
	double qMeanMC;


	m_setup->Print(1);

	m_detector->Print();

	if (fDoRoot){
		cMC=new TChain("DetDigi"); //must have the TTree name I am going to read
		cMC->Add(fReconName.c_str());
		NeventsMC=cMC->GetEntries(); //1 entry=1 event
		cMC->SetBranchAddress("DetDigi", &digi);


		fPoisson=new TF1("poisson",poissonf,0,1000,2);
		fPoisson->SetNpx(1000);
	}
	else{
		m_reconInput=new TReconInput(fReconName);
		m_recon=new TRecon(m_detector,m_reconInput);
		m_reconInput->Print();
	}


	/*Set the first gain, i.e. the Hamamatsu one. The index is the H8500ID!!!*/
	double PmtDA0359[MarocSetupHandler::nH8500Pixels]={76,79,86,96,100,95,88,83,76,71,80,89,95,89,87,82,75,68,82,87,92,91,81,77,71,64,79,83,88,88,75,74,69,63,74,79,78,83,73,70,68,61,71,75,76,73,68,65,63,60,65,69,66,62,59,60,61,64,66,70,65,60,56,52};
	double PmtDA0361[MarocSetupHandler::nH8500Pixels]={56,71,76,81,89,87,78,82,61,66,72,77,82,78,76,85,60,64,72,74,75,81,80,88,61,65,70,72,73,82,82,93,63,66,71,72,73,85,86,99,68,68,77,75,82,91,89,100,73,75,83,88,95,97,92,99,60,73,80,85,92,99,90,71};

	for (int ii=0;ii<MarocSetupHandler::nH8500Pixels;ii++){
		iReconPixel=m_setup->getPixelReconId(32,ii);
		iMarocChannel=m_setup->getMarocChannelFromH8500(ii);
		iReconFace=m_setup->getReconstructionDetectorFace(32);
		iReconDet=m_setup->getReconstructionDetectorID(32);
		m_setup->setPixelGain(iReconFace,iReconDet,iReconPixel,1,PmtDA0359[ii]/100.);
		m_setup->setPixelGain(iReconFace,iReconDet,iReconPixel,3,0.718); /*This is the gain configuration PMT359 vs PMT361*/

		m_setup->setPixelGain(iReconFace,iReconDet,iReconPixel,2,.5);

		//	if (iMarocChannel<=31)			m_setup->setPixelGain(iReconFace,iReconDet,iReconPixel,2,.5);
		//	else if (iMarocChannel<=47)		m_setup->setPixelGain(iReconFace,iReconDet,iReconPixel,2,.375);
		//	else if (iMarocChannel<=63)		m_setup->setPixelGain(iReconFace,iReconDet,iReconPixel,2,.25);



		iReconPixel=m_setup->getPixelReconId(33,ii);
		iMarocChannel=m_setup->getMarocChannelFromH8500(ii);
		iReconFace=m_setup->getReconstructionDetectorFace(33);
		iReconDet=m_setup->getReconstructionDetectorID(33);
		m_setup->setPixelGain(iReconFace,iReconDet,iReconPixel,1,PmtDA0361[ii]/100.);
		m_setup->setPixelGain(iReconFace,iReconDet,iReconPixel,3,1.); /*This is the gain configuration PMT359 vs PMT361*/

		m_setup->setPixelGain(iReconFace,iReconDet,iReconPixel,2,.5);
		//	if (iMarocChannel<=31)			m_setup->setPixelGain(iReconFace,iReconDet,iReconPixel,2,.5);
		//	else if (iMarocChannel<=47)		m_setup->setPixelGain(iReconFace,iReconDet,iReconPixel,2,.375);
		//	else if (iMarocChannel<=63)		m_setup->setPixelGain(iReconFace,iReconDet,iReconPixel,2,.25);

	}


	m_setup->Print(1);




	/*Define here the histograms*/
	/*These are indexed by the real pixel id*/
	TH1D **hChargeSig=new TH1D*[Ntot];  TH1D **hChargeSigCorr=new TH1D*[Ntot];  TH1D **hChargeHitSig=new TH1D*[Ntot];
	TH1D **hChargeBck=new TH1D*[Ntot];  TH1D **hChargeBckCorr=new TH1D*[Ntot];  TH1D **hChargeHitBck=new TH1D*[Ntot];
	TH1D **hChargeDiff=new TH1D*[Ntot];

	TH2D **hChargeSigVsTot=new TH2D*[Ntot];
	TH2D **hChargeBckVsTot=new TH2D*[Ntot];




	TH2D *hGrid=new TH2D("hGrid","hGrid",16,-8.5,7.5,8,-0.5,7.5);
	TH2D *hGainMap=new TH2D("hGainMap","hGainMap",16,-8.5,7.5,8,-0.5,7.5);
	TH2D *hMeanSig=new TH2D("hMeanSig","hMeanSig",16,-8.5,7.5,8,-0.5,7.5);
	TH2D *hMeanBck=new TH2D("hMeanBck","hMeanBck",16,-8.5,7.5,8,-0.5,7.5);
	TH2D *hMeanDiff=new TH2D("hMeanDiff","hMeanDiff",16,-8.5,7.5,8,-0.5,7.5);

	TH2D *hHitSig=new TH2D("hHitSig","hHitSig",16,-8.5,7.5,8,-0.5,7.5);
	TH2D *hHitBck=new TH2D("hHitBck","hHitBck",16,-8.5,7.5,8,-0.5,7.5);
	TH2D *hHitDiff=new TH2D("hHitDiff","hHitDiff",16,-8.5,7.5,8,-0.5,7.5);


	TH1D* hChargeExp[6][MAX_DETECTORS];
	TH1D* hChargeTeo[6][MAX_DETECTORS];

	TH1D* hChargeSigTot=new TH1D("hChargeSigTot","hChargeSigTot",5000,-10E3,200E3);
	TH1D* hChargeBckTot=new TH1D("hChargeBckTot","hChargeBckTot",5000,-10E3,200E3);
	TH1D* hChargeDiffTot=new TH1D("hChargeDiffTot","hChargeDiffTot",5000,-10E3,200E3);

	TH1D* hChargeSigTotR=new TH1D("hChargeSigTotR","hChargeSigTotR",5000,-10E3,200E3);
	TH1D* hChargeBckTotR=new TH1D("hChargeBckTotR","hChargeBckTotR",5000,-10E3,200E3);
	TH1D* hChargeDiffTotR=new TH1D("hChargeDiffTotR","hChargeDiffTotR",5000,-10E3,200E3);

	TH1D* hChargeSigTotL=new TH1D("hChargeSigTotL","hChargeSigTotL",5000,-10E3,200E3);
	TH1D* hChargeBckTotL=new TH1D("hChargeBckTotL","hChargeBckTotL",5000,-10E3,200E3);
	TH1D* hChargeDiffTotL=new TH1D("hChargeDiffTotL","hChargeDiffTotL",5000,-10E3,200E3);

	TH2D* hChargeSigTotLR=new TH2D("hChargeSigTotLR","hChargeSigTotLR",2000,-10E3,200E3,2000,-10E3,200E3);
	TH2D* hChargeBckTotLR=new TH2D("hChargeBckTotLR","hChargeBckTotLR",2000,-10E3,200E3,2000,-10E3,200E3);


	cout<<"Creating channel histograms"<<endl;
	for (int ii=0;ii<Ntot;ii++){
		iH8500=m_setup->getH8500IdFromGlobal(ii+N0);

		hChargeSig[ii]=new TH1D(Form("hChargeSig%i",ii),Form("hChargeSig%i:H8500_%i",ii,iH8500),4096,-0.5,4095.5);
		hChargeBck[ii]=new TH1D(Form("hChargeBck%i",ii),Form("hChargeBck%i:H8500_%i",ii,iH8500),4096,-0.5,4095.5);
		hChargeDiff[ii]=new TH1D(Form("hChargeDiff%i",ii),Form("hChargeDiff%i:H8500_%i",ii,iH8500),5000,-1000.5,3999.5);

		hChargeSigCorr[ii]=new TH1D(Form("hChargeSigCorr%i",ii),Form("hChargeSigCorr%i:H8500_%i",ii,iH8500),5096,-1000.5,4095.5);
		hChargeBckCorr[ii]=new TH1D(Form("hChargeBckCorr%i",ii),Form("hChargeBckCorr%i:H8500_%i",ii,iH8500),5096,-1000.5,4095.5);

		hChargeHitSig[ii]=new TH1D(Form("hChargeHitSig%i",ii),Form("hChargeHitSig%i:H8500_%i",ii,iH8500),4096,-0.5,4095.5);
		hChargeHitBck[ii]=new TH1D(Form("hChargeHitBck%i",ii),Form("hChargeHitBck%i:H8500_%i",ii,iH8500),4096,-0.5,4095.5);

		hChargeSigVsTot[ii]=new TH2D(Form("hChargeSigVsTot%i",ii),Form("hChargeSigVsTot%i",ii),500,-1000.5,5095.5,500,-10E3,200E3);
		hChargeBckVsTot[ii]=new TH2D(Form("hChargeBckVsTot%i",ii),Form("hChargeBckVsTot%i",ii),500,-1000.5,4095.5,500,-10E3,200E3);
	}
	cout<<"Done"<<endl;
	cout<<"Creating comparison histograms"<<endl;
	for (int ii=0;ii<6;ii++){
		for (int jj=0;jj<m_detector->getNdet(ii);jj++){
			if (m_detector->isDetPresent(ii,jj)){
				Nx=m_detector->getNPixelsX(ii,jj);
				Ny=m_detector->getNPixelsY(ii,jj);
				hChargeExp[ii][jj]=new TH1D(Form("hChargeTeo%i_%i",ii,jj),Form("hChargeExp%i_%i",ii,jj),Nx*Ny,-0.5,Nx*Ny-0.5);
				hChargeTeo[ii][jj]=new TH1D(Form("hChargeExp%i_%i",ii,jj),Form("hChargeTeo%i_%i",ii,jj),Nx*Ny,-0.5,Nx*Ny-0.5);
				if (fDoRoot){
					for (int kk=0;kk<Nx*Ny;kk++){
						hChargeMC[ii][jj].push_back(new TH1D(Form("hChargeMC_%i_%i_%i",ii,jj,kk),Form("hCharge_%i_%i_%i",ii,jj,kk),1000,-0.5,999.5));
					}
				}
			}
		}
	}
	cout<<"Done creating histograms"<<endl;

	/*Process the signal*/
	tSig->SetBranchAddress("ADC",ADC);
	tSig->SetBranchAddress("EvtMultiplicity",&EvtMultiplicity);
	tSig->SetBranchAddress("hit",hit);


	Ns=tSig->GetEntries();
	cout<<"There are "<<Ns<<" signals "<<endl;
	for (int ii=0;ii<Ns;ii++){
		tSig->GetEntry(ii);
		for (int jj=0;jj<Ntot;jj++){
			id=jj+N0;


			iRealDet=m_setup->getMarocCard(id);
			iH8500=m_setup->getH8500IdFromGlobal(id);
			iMarocChannel=m_setup->getMarocChannelFromGlobal(id);
			iReconDet=m_setup->getReconstructionDetectorID(iRealDet);
			iReconFace=m_setup->getReconstructionDetectorFace(iRealDet);
			iReconPixel=m_setup->getPixelReconId(id);
			if (iRealDet==32){
				ix=iH8500%8;
			}
			else {
				ix=-iH8500%8-1;
			}
			iy=7-iH8500/8;
			Gain=m_setup->getPixelGain(iReconFace,iReconDet,iReconPixel);
			Q=ADC[id];
			hChargeSig[jj]->Fill(Q);
			if (hit[id]){
				hHitSig->Fill(ix,iy,+1);
				hHitDiff->Fill(ix,iy,+1);
				hChargeHitSig[jj]->Fill(Q);
			}





			//  hChargeDiff[jj]->Fill(Q,+1);
		}
	}

	/*Process the background*/
	tBck->SetBranchAddress("ADC",ADC);
	tBck->SetBranchAddress("EvtMultiplicity",&EvtMultiplicity);
	tBck->SetBranchAddress("hit",hit);

	Nb=tBck->GetEntries();
	cout<<"There are "<<Nb<<" backgrounds"<<endl;
	for (int ii=0;ii<Nb;ii++){
		tBck->GetEntry(ii);
		for (int jj=0;jj<Ntot;jj++){
			id=jj+N0;

			iRealDet=m_setup->getMarocCard(id);
			iH8500=m_setup->getH8500IdFromGlobal(id);
			iMarocChannel=m_setup->getMarocChannelFromGlobal(id);
			iReconDet=m_setup->getReconstructionDetectorID(iRealDet);
			iReconFace=m_setup->getReconstructionDetectorFace(iRealDet);
			iReconPixel=m_setup->getPixelReconId(id);
			Gain=m_setup->getPixelGain(iReconFace,iReconDet,iReconPixel);

			if (iRealDet==32){
				ix=iH8500%8;
			}
			else {
				ix=-iH8500%8-1;
			}
			iy=7-iH8500/8;
			Gain=m_setup->getPixelGain(iReconFace,iReconDet,iReconPixel);
			Q=ADC[id];
			hChargeBck[jj]->Fill(Q);

			if (hit[id]){
				hHitBck->Fill(ix,iy,+1);
				hHitDiff->Fill(ix,iy,-1);
				hChargeHitBck[jj]->Fill(Q);
			}

		}
	}
	/*Compute the pedestals*/
	for (int jj=0;jj<Ntot;jj++){
		min=hChargeSig[jj]->GetBinCenter(hChargeSig[jj]->GetMaximumBin());
		max=min;
		min-=15;
		max+=15;
		hChargeSig[jj]->Fit("gaus","RL","",min,max);

		min=hChargeBck[jj]->GetBinCenter(hChargeBck[jj]->GetMaximumBin());
		max=min;
		min-=15;
		max+=15;
		hChargeBck[jj]->Fit("gaus","RL","",min,max);
		PedSig[jj]=hChargeSig[jj]->GetFunction("gaus")->GetParameter(1);
		PedBck[jj]=hChargeBck[jj]->GetFunction("gaus")->GetParameter(1);
	}




	/*Process the signal, again*/
	tSig->SetBranchAddress("ADC",ADC);
	tSig->SetBranchAddress("EvtMultiplicity",&EvtMultiplicity);
	tSig->SetBranchAddress("hit",hit);
	Ns=tSig->GetEntries();

	for (int ii=0;ii<Ns;ii++){
		QSigTot=0;
		QSigTotL=0;
		QSigTotR=0;
		tSig->GetEntry(ii);
		for (int jj=0;jj<Ntot;jj++){
			id=jj+N0;

			iRealDet=m_setup->getMarocCard(id);
			iH8500=m_setup->getH8500IdFromGlobal(id);
			iMarocChannel=m_setup->getMarocChannelFromGlobal(id);
			iReconDet=m_setup->getReconstructionDetectorID(iRealDet);
			iReconFace=m_setup->getReconstructionDetectorFace(iRealDet);
			iReconPixel=m_setup->getPixelReconId(id);
			Gain=m_setup->getPixelGain(iReconFace,iReconDet,iReconPixel);
			Q=ADC[id]-PedSig[jj];
			QSigTot+=Q/Gain;
			if (jj<Ntot/2) QSigTotL+=Q/Gain;
			else QSigTotR+=Q/Gain;
		}
		hChargeSigTot->Fill(QSigTot);
		hChargeSigTotL->Fill(QSigTotL);
		hChargeSigTotR->Fill(QSigTotR);
		hChargeSigTotLR->Fill(QSigTotR,QSigTotL);

		hChargeDiffTot->Fill(QSigTot,+1);
		hChargeDiffTotR->Fill(QSigTotR,+1);
		hChargeDiffTotL->Fill(QSigTotL,+1);


		flagQcut=1;
		if (QSigTot<QTotThr) flagQcut=0;
		for (int jj=0;jj<Ntot;jj++){
			id=jj+N0;

			iRealDet=m_setup->getMarocCard(id);
			iH8500=m_setup->getH8500IdFromGlobal(id);
			iMarocChannel=m_setup->getMarocChannelFromGlobal(id);
			iReconDet=m_setup->getReconstructionDetectorID(iRealDet);
			iReconFace=m_setup->getReconstructionDetectorFace(iRealDet);
			iReconPixel=m_setup->getPixelReconId(id);
			Gain=m_setup->getPixelGain(iReconFace,iReconDet,iReconPixel);

			Q=ADC[id]-PedSig[jj];

			//			hChargeSigVsTot[jj]->Fill(Q,QSigTot);


			if (flagQcut){
				hChargeDiff[jj]->Fill(Q,+1);
				hChargeSigCorr[jj]->Fill(Q);
			}
		}
	}


	/*Process the bck, again*/
	tBck->SetBranchAddress("ADC",ADC);
	tBck->SetBranchAddress("EvtMultiplicity",&EvtMultiplicity);
	tBck->SetBranchAddress("hit",hit);

	for (int ii=0;ii<Nb;ii++){
		QBckTot=0;
		QBckTotR=0;
		QBckTotL=0;
		tBck->GetEntry(ii);
		for (int jj=0;jj<Ntot;jj++){
			id=jj+N0;

			iRealDet=m_setup->getMarocCard(id);
			iH8500=m_setup->getH8500IdFromGlobal(id);
			iMarocChannel=m_setup->getMarocChannelFromGlobal(id);
			iReconDet=m_setup->getReconstructionDetectorID(iRealDet);
			iReconFace=m_setup->getReconstructionDetectorFace(iRealDet);
			iReconPixel=m_setup->getPixelReconId(id);
			Gain=m_setup->getPixelGain(iReconFace,iReconDet,iReconPixel);
			Q=ADC[id]-PedBck[jj];
			QBckTot+=Q/Gain;


			if (jj<Ntot/2) QBckTotL+=Q/Gain;
			else QBckTotR+=Q/Gain;
		}
		hChargeBckTot->Fill(QBckTot);
		hChargeDiffTot->Fill(QBckTot,-1);

		hChargeBckTotL->Fill(QBckTotL);
		hChargeBckTotR->Fill(QBckTotR);
		hChargeBckTotLR->Fill(QBckTotR,QBckTotL);

		hChargeDiffTotR->Fill(QBckTotR,-1);
		hChargeDiffTotL->Fill(QBckTotL,-1);


		flagQcut=1;
		if (QBckTot<QTotThr) flagQcut=0;

		for (int jj=0;jj<Ntot;jj++){
			id=jj+N0;

			iRealDet=m_setup->getMarocCard(id);
			iH8500=m_setup->getH8500IdFromGlobal(id);
			iMarocChannel=m_setup->getMarocChannelFromGlobal(id);
			iReconDet=m_setup->getReconstructionDetectorID(iRealDet);
			iReconFace=m_setup->getReconstructionDetectorFace(iRealDet);
			iReconPixel=m_setup->getPixelReconId(id);
			Gain=m_setup->getPixelGain(iReconFace,iReconDet,iReconPixel);

			Q=ADC[id]-PedBck[jj];
			//hChargeBckVsTot[jj]->Fill(Q,QBckTot);

			if (flagQcut){
				hChargeBckCorr[jj]->Fill(Q);
				hChargeDiff[jj]->Fill(Q,-1);
			}
		}
	}


	if (fDoRoot){
		cout<<"Geant4 recon: start filling histograms"<<endl;
		cout<<"There are: "<<NeventsMC<<" MonteCarlo events"<<endl;
		for (int ii=0;ii<NeventsMC;ii++){
			cMC->GetEntry(ii);
			Nhits=digi->size();
			for (int jj=0;jj<Nhits;jj++){
				faceNumber=digi->at(jj)-> GetFaceNumber();
				detNumber=digi->at(jj)-> GetDetectorNumber();
				pixelNumber=digi->at(jj)-> GetPixelNumber();
				hChargeMC[faceNumber][detNumber].at(pixelNumber)->Fill(digi->at(jj)->GetPheCount());
			}
		}
		cout<<"Geant4 recon: fits"<<endl;
		for (int ii=0;ii<6;ii++){
			for (int jj=0;jj<m_detector->getNdet(ii);jj++){
				if (m_detector->isDetPresent(ii,jj)){
					for (int kk=0;kk<m_detector->getNPixels(ii,jj);kk++){
						cout<<"Doing fit "<<ii<<" "<<jj<<" "<<kk<<endl;
						fPoisson->SetParameter(0,hChargeMC[ii][jj].at(kk)->GetEntries());
						fPoisson->SetParameter(1,hChargeMC[ii][jj].at(kk)->GetMean());
						hChargeMC[ii][jj].at(kk)->Fit("poisson");
						qMeanMC=fPoisson->GetParameter(1);
						fTeo[ii][jj][kk]=qMeanMC;
					}
				}
			}
		}
	}



	cout<<"Comparison, fixing normalization"<<endl;
	for (int iGlobal=N0;iGlobal<(Ntot+N0);iGlobal++){
		iRealDet=m_setup->getMarocCard(iGlobal);
		iH8500=m_setup->getH8500IdFromGlobal(iGlobal);
		iMarocChannel=m_setup->getMarocChannelFromGlobal(iGlobal);

		iReconDet=m_setup->getReconstructionDetectorID(iRealDet);
		iReconFace=m_setup->getReconstructionDetectorFace(iRealDet);
		iReconPixel=m_setup->getPixelReconId(iGlobal);

		if (iRealDet==32){
			ix=iH8500%8;
		}
		else {
			ix=-iH8500%8-1;
		}
		iy=7-iH8500/8;
		MeanSig=hChargeSig[iGlobal-N0]->GetMean();
		MeanBck=hChargeBck[iGlobal-N0]->GetMean();
		MeanDiff=hChargeDiff[iGlobal-N0]->GetMean();


		Gain=m_setup->getPixelGain(iReconFace,iReconDet,iReconPixel);

		MeanDiffCorrected=MeanDiff/Gain;


		hGrid->Fill(ix,iy,iGlobal-N0);
		hGainMap->Fill(ix,iy,Gain);
		hMeanSig->Fill(ix,iy,MeanSig);
		hMeanBck->Fill(ix,iy,MeanBck);
		hMeanDiff->Fill(ix,iy,MeanDiffCorrected);



		hChargeDiff[iGlobal-N0]->Fit("pol1","LQ","R",0.5E3,.9E3);
		hChargeDiff[iGlobal-N0]->GetFunction("pol1")->SetLineColor(2);

		fExp[iReconFace][iReconDet][iReconPixel]=MeanDiffCorrected;

	}



	/*From reconstruction, for the non-geant4 case*/
	if (fDoRoot!=1){
		vin.SetXYZ(m_reconInput->getParVal(k_x0),m_reconInput->getParVal(k_y0),m_reconInput->getParVal(k_z0));

		for (int ii=0;ii<6;ii++){
			for (int jj=0;jj<m_detector->getNdet(ii);jj++){
				if (m_detector->isDetPresent(ii,jj)){
					for (int kk=0;kk<m_detector->getNPixels(ii,jj);kk++){
						F=m_recon->SinglePixelAverageCharge(vin,ii,jj,kk);
						Corr=CorrectionPixel(vin,ii,jj,kk,m_detector);
						//Corr=1;
						fTeo[ii][jj][kk]=F*Corr;
					}
				}
			}
		}
	}
	/*Now compute normalization and fill histograms*/
	fNormTeo=fNormExp=0;
	for (int iface=0;iface<6;iface++){
		for (int idetector=0;idetector<m_detector->getNdet(iface);idetector++){
			if (m_detector->isDetPresent(iface,idetector)){
				for (int ipixel=0;ipixel<m_detector->getNPixels(iface,idetector);ipixel++){
					fNormTeo+=fTeo[iface][idetector][ipixel];
					fNormExp+=fExp[iface][idetector][ipixel];
					hChargeTeo[iface][idetector]->Fill(ipixel,fTeo[iface][idetector][ipixel]);
					hChargeExp[iface][idetector]->Fill(ipixel,fExp[iface][idetector][ipixel]);
				}
			}
		}
	}


	/*Histograms have been filled. Scale them to compare*/
	for (int ii=0;ii<6;ii++){
		for (int jj=0;jj<m_detector->getNdet(ii);jj++){
			if (m_detector->isDetPresent(ii,jj)){
				hChargeExp[ii][jj]->Scale(1./fNormExp);
				hChargeTeo[ii][jj]->Scale(1./fNormTeo);
			}
		}
	}
	/*Plots*/
	TCanvas **c=new TCanvas*[Ntot];


	for (int iGlobal=N0;iGlobal<(Ntot+N0);iGlobal++){
		iRealDet=m_setup->getMarocCard(iGlobal);
		iH8500=m_setup->getH8500IdFromGlobal(iGlobal);
		iMarocChannel=m_setup->getMarocChannelFromGlobal(iGlobal);

		iReconDet=m_setup->getReconstructionDetectorID(iRealDet);
		iReconFace=m_setup->getReconstructionDetectorFace(iRealDet);
		iReconPixel=m_setup->getPixelReconId(iGlobal);



		c[iGlobal-N0]=new TCanvas(Form("c%i",(iGlobal-N0)),Form("c%i:H8500_%i",(iGlobal-N0),iH8500));
		c[iGlobal-N0]->Divide(3,3);
		c[iGlobal-N0]->cd(1)->SetLogy();


		c[iGlobal-N0]->cd(1)->SetLogy();
		hChargeSig[iGlobal-N0]->GetXaxis()->SetRangeUser(1250,3000);

		hChargeSig[iGlobal-N0]->SetLineColor(1);
		hChargeSig[iGlobal-N0]->Draw();
		hChargeHitSig[iGlobal-N0]->SetLineColor(4);
		hChargeHitSig[iGlobal-N0]->Draw("SAMES");

		c[iGlobal-N0]->cd(2)->SetLogy();
		hChargeBck[iGlobal-N0]->GetXaxis()->SetRangeUser(1250,3000);
		hChargeBck[iGlobal-N0]->SetLineColor(2);
		hChargeBck[iGlobal-N0]->Draw();
		hChargeHitBck[iGlobal-N0]->SetLineColor(6);
		hChargeHitBck[iGlobal-N0]->Draw("SAMES");

		c[iGlobal-N0]->cd(3)->SetLogy();
		hChargeSig[iGlobal-N0]->GetXaxis()->SetRangeUser(1250,3000);
		hChargeSig[iGlobal-N0]->Draw();
		hChargeBck[iGlobal-N0]->Draw("SAMES");

		c[iGlobal-N0]->cd(4)->SetLogy();
		//	hChargeSigCorr[iGlobal-N0]->GetXaxis()->SetRangeUser(1250,3000);
		hChargeSigCorr[iGlobal-N0]->SetFillColor(kYellow-9);
		hChargeSigCorr[iGlobal-N0]->Draw();
		hChargeBckCorr[iGlobal-N0]->SetLineColor(2);
		hChargeBckCorr[iGlobal-N0]->SetFillColor(kRed-9);
		hChargeBckCorr[iGlobal-N0]->Draw("SAMES");

		c[iGlobal-N0]->cd(5)->SetLogy();
		hChargeDiff[iGlobal-N0]->GetXaxis()->SetRangeUser(-500,1600);
		hChargeDiff[iGlobal-N0]->Draw();

		c[iGlobal-N0]->cd(5)->SetLogy();
		//hChargeDiffCorr[iGlobal-N0]->GetXaxis()->SetRangeUser(-500,1600);
		//	hChargeDiffCorr[iGlobal-N0]->Draw();

		c[iGlobal-N0]->cd(7);
		//hChargeSigVsTot[iGlobal-N0]->Draw("colz");

		c[iGlobal-N0]->cd(8);
		//hChargeBckVsTot[iGlobal-N0]->Draw("colz");

		c[iGlobal-N0]->cd(9);





		if ((iGlobal-N0)==0) c[iGlobal-N0]->Print((fOutNamePS+"(").c_str());
		else  c[iGlobal-N0]->Print(fOutNamePS.c_str());
		fOut->cd();
		c[iGlobal-N0]->Write();
	}

	TLine *l=new TLine(-0.5,-0.5,-0.5,7.5);l->SetLineWidth(2);l->SetLineColor(2);



	TCanvas *ca=new TCanvas("ca","ca");
	ca->Divide(3,3);
	ca->cd(1);
	hGainMap->GetXaxis()->SetRangeUser(1000,2000);
	hGainMap->Draw("colz");
	hGrid->SetMarkerSize(1.8);hGrid->SetMarkerColor(0);
	hGrid->Draw("TEXTSAME");
	l->Draw("SAME");


	ca->cd(2);
	hMeanSig->SetStats(0);
	hMeanSig->Draw("colz");
	hGrid->Draw("TEXTSAME");
	l->Draw("SAME");

	ca->cd(3);
	hMeanBck->SetStats(0);
	hMeanBck->Draw("colz");
	hGrid->Draw("TEXTSAME");

	ca->cd(4);
	hMeanDiff->SetStats(0);
	hMeanDiff->Draw("colz");
	hGrid->Draw("TEXTSAME");
	l->Draw("SAME");

	ca->cd(7);
	hHitSig->SetStats(0);
	hHitSig->Draw("colz");
	hGrid->Draw("TEXTSAME");

	ca->cd(8);
	hHitBck->SetStats(0);
	hHitBck->Draw("colz");
	hGrid->Draw("TEXTSAME");


	ca->cd(9);
	hHitDiff->SetStats(0);
	hHitDiff->Draw("colz");
	hGrid->Draw("TEXTSAME");

	ca->Print(fOutNamePS.c_str());
	fOut->cd();
	ca->Write();

	TCanvas *ctot=new TCanvas("ctot","ctot");
	ctot->Divide(3,3);
	ctot->cd(1);
	hChargeSigTot->Draw();
	hChargeBckTot->SetLineColor(2);
	hChargeBckTot->Draw("SAMES");
	ctot->cd(2);
	hChargeSigTotL->Draw();
	hChargeBckTotL->SetLineColor(2);
	hChargeBckTotL->Draw("SAMES");
	ctot->cd(3);
	hChargeSigTotR->Draw();
	hChargeBckTotR->SetLineColor(2);
	hChargeBckTotR->Draw("SAMES");



	ctot->cd(4);
	hChargeDiffTot->Draw();
	ctot->cd(5);
	hChargeDiffTotL->Draw();
	ctot->cd(6);
	hChargeDiffTotR->Draw();

	ctot->cd(7);
	hChargeSigTotLR->Draw("colz");

	ctot->cd(8);
	hChargeBckTotLR->Draw("colz");



	ctot->Print(fOutNamePS.c_str());
	fOut->cd();
	ctot->Write();



	TCanvas *cRecon01=new TCanvas("cRecon01","cRecon01");
	cRecon01->Divide(2,2);
	iPad=0;
	for (int ii=0;ii<6;ii++){
		for (int jj=0;jj<m_detector->getNdet(ii);jj++){
			if (m_detector->isDetPresent(ii,jj)){
				cRecon01->cd(1+iPad)->SetGridx();
				cRecon01->cd(1+iPad)->SetGridy();

				hChargeExp[ii][jj]->SetStats(0);
				hChargeExp[ii][jj]->SetLineWidth(2);
				//hChargeExp[ii][jj]->GetYaxis()->SetRangeUser(0.,2);
				hChargeExp[ii][jj]->Draw();
				//hChargeExp[ii][jj]->GetYaxis()->SetRangeUser(0.,2);


				hChargeTeo[ii][jj]->SetStats(0);
				hChargeTeo[ii][jj]->SetLineWidth(2);
				hChargeTeo[ii][jj]->SetLineColor(2);
				hChargeTeo[ii][jj]->Draw("SAME");

				iPad++;
			}
		}
	}


	cRecon01->Print((fOutNamePS+")").c_str());
	fOut->cd();
	cRecon01->Write();
	if (fDoBatch==0){
		gui.Run(1);
	}




	cout<<"Done"<<endl;
}



void ParseCommandLine(int argc,char **argv){
	for (int ii=0;ii<argc;ii++){
		if ((strcmp(argv[ii],"-s")==0)||(strcmp(argv[ii],"-signal")==0)){
			fSigName=string(argv[ii+1]);
		}

		else if ((strcmp(argv[ii],"-b")==0)||(strcmp(argv[ii],"-background")==0)){
			fBckName=string(argv[ii+1]);
		}

		else if ((strcmp(argv[ii],"-o")==0)||(strcmp(argv[ii],"-out")==0)){
			fOutName=string(argv[ii+1]);
		}
		else if ((strcmp(argv[ii],"-d")==0)||(strcmp(argv[ii],"-det")==0)){
			fDetName=string(argv[ii+1]);
		}
		else if ((strcmp(argv[ii],"-r")==0)){
			fReconName=string(argv[ii+1]);
		}
		else if ((strcmp(argv[ii],"-ss")==0)||(strcmp(argv[ii],"-setup")==0)){
			fSetupName=string(argv[ii+1]);
		}
		else if ((strcmp(argv[ii],"-h")==0)||(strcmp(argv[ii],"-help")==0)){
			PrintHelp();
		}
		else if (strcmp(argv[ii],"-batch")==0){
			fDoBatch=true;
		}

	}

}



void PrintHelp(){
	cout<<"-s or -signal: signal file name"<<endl;
	cout<<"-b or -background: bck file name"<<endl;
	cout<<"-d or -det: detector file name"<<endl;
	cout<<"-ss or -setup: setup file name"<<endl;
	cout<<"-r: recon file name OR root file name with MC results"<<endl;
	cout<<"-o or -out: output file name"<<endl;
	cout<<"-batch: batch mode"<<endl;
}


double CorrectionPixel(const TVector3 &v0,int iface,int idetector,int ipixel,const TOpNoviceDetectorLight *m_detector){
	double ret=0;

	double n1=1.58;
	double n2=1;

	TVector3 vp,vn,vrel;

	double theta1,theta2;
	double stheta1,stheta2;
	double ctheta1,ctheta2;
	double tpara,tperp;

	vn=m_detector->getFaceNormal(iface);
	vn=-vn; //entering normal

	vp=m_detector->getPosPixel(iface,idetector,ipixel);
	vrel=vp-v0;

	theta1=vrel.Angle(vn);
	stheta1=sin(theta1);
	ctheta1=cos(theta2);

	stheta2=n1*stheta1/n2;
	if (stheta2>1) ret=0;
	else{
		ctheta2=sqrt(1-stheta2*stheta2);
		theta2=asin(stheta2); //for print
		tpara=((n2*ctheta2)/(n1*ctheta1))*((2*n1*ctheta1)/(n2*ctheta1+n1*ctheta2))*((2*n1*ctheta1)/(n2*ctheta1+n1*ctheta2));
		tperp=((n2*ctheta2)/(n1*ctheta1))*((2*n1*ctheta1)/(n1*ctheta1+n2*ctheta2))*((2*n1*ctheta1)/(n1*ctheta1+n2*ctheta2));
		ret=0.5*(tpara+tperp);
	}
	return ret;
}

