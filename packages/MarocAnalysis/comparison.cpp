#include <iostream>
#include <string>

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

#include "MarocSetupHandler.hh"
#include "TDetectorLight.hh"
#include "TRecon.hh"

using namespace std;

#define N0 2048
#define Ntot 64


/*From the command line*/
string fFileName1,fFileName2;
string fOutNameRoot,fOutNamePS,fOutName;
int iCard1,iCard2;
int iPMT1,iPMT2;

int fDoBatch=0;
void ParseCommandLine(int argc,char **argv);
void PrintHelp();
TApplication gui("GUI",0,NULL);


int main(int argc,char **argv){
	if (argc==0){
		PrintHelp();
		exit(1);
	}
	ParseCommandLine(argc,argv);


	if (fDoBatch)  gROOT->SetBatch();
	if (fFileName1.length()==0){
		cerr<<"Missing data file name 1"<<endl;
		return -1;
	}

	if (fFileName2.length()==0){
		cerr<<"Missing data file name 2"<<endl;
		return -1;
	}



	if (fOutName.length()==0){
		cerr<<"Missing OUT file name, auto-selecting"<<endl;
		fOutName="MarocComparison.out";
	}
	fOutNameRoot=fOutName+".root";
	fOutNamePS=fOutName+".ps";

	TTree *t;
	TFile *f;
	TFile *fOut=new TFile(fOutNameRoot.c_str(),"recreate");

	Float_t ADC[4096];
	Bool_t hit[4096];

	double ped1[Ntot],ped2[Ntot];
	double mean1[Ntot],mean2[Ntot];
	double min,max;
	int imin,imax;
	int N0_1;
	int N0_2;
	int id,iGlobal;

	int ix,iy,iH8500,iMarocChannel,iMarocCard;
	int iPad;
	double Q,gain;
	int N;


	MarocSetupHandler *m_setup=new MarocSetupHandler();
	/*Set the first gain, i.e. the Hamamatsu one*/
	/*These are indexed by the H8500 id*/
	double PmtDA0359[MarocSetupHandler::nH8500Pixels]={76,79,86,96,100,95,88,83,76,71,80,89,95,89,87,82,75,68,82,87,92,91,81,77,71,64,79,83,88,88,75,74,69,63,74,79,78,83,73,70,68,61,71,75,76,73,68,65,63,60,65,69,66,62,59,60,61,64,66,70,65,60,56,52};
	double PmtDA0361[MarocSetupHandler::nH8500Pixels]={56,71,76,81,89,87,78,82,61,66,72,77,82,78,76,85,60,64,72,74,75,81,80,88,61,65,70,72,73,82,82,93,63,66,71,72,73,85,86,99,68,68,77,75,82,91,89,100,73,75,83,88,95,97,92,99,60,73,80,85,92,99,90,71};

	/*This is indexed by the MAROC id*/
	double MarocGain[Ntot];
	double Gain1[Ntot];
	double Gain2[Ntot];


	/*Set the gains*/
	for (int ii=0;ii<Ntot;ii++){
		iH8500=m_setup->getH8500IdFromMaroc(ii);
		if (ii<=31)			    MarocGain[ii]=.5;
		else if (ii<=47)		    MarocGain[ii]=.375;
		else if (ii<=63)		    MarocGain[ii]=.25;

		switch (iPMT1){
		case 359:
			Gain1[ii]=MarocGain[ii]*PmtDA0359[iH8500];
			break;
		case 361:
			Gain1[ii]=MarocGain[ii]*PmtDA0361[iH8500];
			break;
		default:
			Gain1[ii]=-1;
			break;
		}

		switch (iPMT2){
		case 359:
			Gain2[ii]=MarocGain[ii]*PmtDA0359[iH8500];
			break;
		case 361:
			Gain2[ii]=MarocGain[ii]*PmtDA0361[iH8500];
			break;
		default:
			Gain2[ii]=-1;
			break;
		}
	}

	/*set N0*/
	switch (iCard1){
	case 32:
		N0_1=2048;
		break;
	case 33:
		N0_1=2048+64;
		break;
	default:
		N0_1=0;
		break;
	}

	switch (iCard2){
	case 32:
		N0_2=2048;
		break;
	case 33:
		N0_2=2048+64;
		break;
	default:
		N0_2=0;
		break;
	}

	/*Define here the histograms*/
	/*These are indexed by the real pixel id*/
	TH1D *hCharge1[Ntot];
	TH1D *hCharge2[Ntot];
	TH1D *hChargeCorr1[Ntot];
	TH1D *hChargeCorr2[Ntot];

	TH1D *hPed1[Ntot];
	TH1D *hPed2[Ntot];

	TH2D *hGrid=new TH2D("hGrid","hGrid",16,-8.5,7.5,8,-0.5,7.5);

	/*
  TH2D *hGrid=new TH2D("hGrid","hGrid",16,-8.5,7.5,8,-0.5,7.5);
  TH2D *hGainMap=new TH2D("hGainMap","hGainMap",16,-8.5,7.5,8,-0.5,7.5);
  TH2D *hMean1=new TH2D("hMean1","hMean1",16,-8.5,7.5,8,-0.5,7.5);
  TH2D *hMean2=new TH2D("hMean2","hMean2",16,-8.5,7.5,8,-0.5,7.5);
  TH2D *hMeanDiff=new TH2D("hMeanDiff","hMeanDiff",16,-8.5,7.5,8,-0.5,7.5);
	 */

	TH2D *hMean1=new TH2D("hMean1","hMean1",8,-0.5,7.5,8,-0.5,7.5);
	TH2D *hMean2=new TH2D("hMean2","hMean2",8,-0.5,7.5,8,-0.5,7.5);
	TH2D *hGain1=new TH2D("hGain1","hGain1",8,-0.5,7.5,8,-0.5,7.5);
	TH2D *hGain2=new TH2D("hGain2","hGain2",8,-0.5,7.5,8,-0.5,7.5);
	TH2D *hMeanRatio;
	TH1D *hMeanRatio1D_H8500=new TH1D("hMeanRatio1D_H8500","hMeanRatio1D_H8500",64,-0.5,63.5);
	TH1D *hMeanRatio1D_Maroc=new TH1D("hMeanRatio1D_Maroc","hMeanRatio1D_Maroc",64,-0.5,63.5);

	TH1D *hMeanAll=new TH1D("hMeanAll","hMeanAll (PRE/POST)",100,0,2);

	for (int ii=0;ii<Ntot;ii++){
		iH8500=m_setup->getH8500IdFromGlobal(ii+N0);
		hPed1[ii]=new TH1D(Form("hPed1_%i",ii),Form("hPed1_%i:H8500_%i",ii,iH8500),4096,-0.5,4095.5);
		hPed2[ii]=new TH1D(Form("hPed2_%i",ii),Form("hPed2_%i:H8500_%i",ii,iH8500),4096,-0.5,4095.5);
		hCharge1[ii]=new TH1D(Form("hCharge1_%i",ii),Form("hCharge1_%i:H8500_%i",ii,iH8500),4096,-0.5,4095.5);
		hCharge2[ii]=new TH1D(Form("hCharge2_%i",ii),Form("hCharge2_%i:H8500_%i",ii,iH8500),4096,-0.5,4095.5);
		hChargeCorr1[ii]=new TH1D(Form("hChargeCorr1_%i",ii),Form("hChargeCorr1_%i:H8500_%i",ii,iH8500),5000,-1000.5,3999.5);
		hChargeCorr2[ii]=new TH1D(Form("hChargeCorr2_%i",ii),Form("hChargeCorr2_%i:H8500_%i",ii,iH8500),5000,-1000.5,3999.5);
	}

	/*Process*/

	/*Charge1*/
	f=new TFile(fFileName1.c_str());
	t=(TTree*)f->Get("fTdata");
	t->SetBranchAddress("ADC",ADC);
	N=t->GetEntries();
	for (int ii=0;ii<N;ii++){
		t->GetEntry(ii);
		for (int jj=0;jj<Ntot;jj++){
			id=jj+N0_1;
			Q=ADC[id];
			hCharge1[jj]->Fill(Q);
		}
	}
	/*Charge2*/
	f=new TFile(fFileName2.c_str());
	t=(TTree*)f->Get("fTdata");
	t->SetBranchAddress("ADC",ADC);
	N=t->GetEntries();
	for (int ii=0;ii<N;ii++){
		t->GetEntry(ii);
		for (int jj=0;jj<Ntot;jj++){
			id=jj+N0_2;
			Q=ADC[id];
			hCharge2[jj]->Fill(Q);
		}
	}



	/*Compute pedestal1*/
	for (int jj=0;jj<Ntot;jj++){

		imin=hCharge1[jj]->GetXaxis()->FindBin(0.);
		imax=hCharge1[jj]->GetXaxis()->FindBin(1380.);

		hCharge1[jj]->GetXaxis()->SetRangeUser(0.,1380.);
		min=hCharge1[jj]->GetBinCenter(hCharge1[jj]->GetMaximumBin());
		hCharge1[jj]->GetXaxis()->SetRangeUser(0.,4095.);
		max=min;
		min-=15;
		max+=15;
		hCharge1[jj]->Fit("gaus","RL","",min,max);
		ped1[jj]=hCharge1[jj]->GetFunction("gaus")->GetParameter(1);

		hCharge2[jj]->GetXaxis()->SetRangeUser(0.,1380.);
		min=hCharge2[jj]->GetBinCenter(hCharge2[jj]->GetMaximumBin());
		hCharge2[jj]->GetXaxis()->SetRangeUser(0.,4095.);
		max=min;
		min-=15;
		max+=15;
		hCharge2[jj]->Fit("gaus","RL","",min,max);
		ped2[jj]=hCharge2[jj]->GetFunction("gaus")->GetParameter(1);
	}

	/*Process again and do ped-subtr*/
	/*Charge1*/
	f=new TFile(fFileName1.c_str());
	t=(TTree*)f->Get("fTdata");
	t->SetBranchAddress("ADC",ADC);
	N=t->GetEntries();
	for (int ii=0;ii<N;ii++){
		t->GetEntry(ii);
		for (int jj=0;jj<Ntot;jj++){
			id=jj+N0_1;
			Q=ADC[id];
			hChargeCorr1[jj]->Fill(Q-ped1[jj]);
		}
	}
	/*Charge2*/
	f=new TFile(fFileName2.c_str());
	t=(TTree*)f->Get("fTdata");
	t->SetBranchAddress("ADC",ADC);
	N=t->GetEntries();
	for (int ii=0;ii<N;ii++){
		t->GetEntry(ii);
		for (int jj=0;jj<Ntot;jj++){
			id=jj+N0_2;
			Q=ADC[id];
			hChargeCorr2[jj]->Fill(Q-ped2[jj]);
		}
	}




	/*Get means*/

	for (int jj=0;jj<Ntot;jj++){
		iGlobal=jj+N0;

		iH8500=m_setup->getH8500IdFromGlobal(iGlobal);
		iMarocChannel=m_setup->getMarocChannelFromGlobal(iGlobal);

		ix=iH8500%8;
		iy=7-iH8500/8;

		gain=Gain1[jj];
		cout<<ix<<" "<<iy<<" "<<gain<<endl;
		hGain1->Fill(ix,iy,gain);
		mean1[jj]=hChargeCorr1[jj]->GetMean()/gain;

		iGlobal=jj+N0+Ntot;
		gain=Gain2[jj];
		mean2[jj]=hChargeCorr2[jj]->GetMean()/gain;
		hGain2->Fill(ix,iy,gain);


		hGrid->Fill(ix,iy,iH8500);
		hMean1->Fill(ix,iy,mean1[jj]);
		hMean2->Fill(ix,iy,mean2[jj]);

		hMeanRatio1D_H8500->Fill(iH8500,mean1[jj]/mean2[jj]);
		hMeanRatio1D_Maroc->Fill(iMarocChannel,mean1[jj]/mean2[jj]);

		hMeanAll->Fill(mean1[jj]/mean2[jj]);

	}
	hMeanRatio=(TH2D*)hMean1->Clone();hMeanRatio->SetName("hMeanRation");hMeanRatio->SetTitle("hMeanRatio");
	hMeanRatio->Divide(hMean2);



	/*Plots*/
	TCanvas **c=new TCanvas*[Ntot];


	for (int iGlobal=N0;iGlobal<(Ntot+N0);iGlobal++){

		iH8500=m_setup->getH8500IdFromGlobal(iGlobal);
		iMarocChannel=m_setup->getMarocChannelFromGlobal(iGlobal);





		c[iGlobal-N0]=new TCanvas(Form("c%i",(iGlobal-N0)),Form("c:H8500_%i",iH8500));
		c[iGlobal-N0]->Divide(2,2);
		c[iGlobal-N0]->cd(1)->SetLogy();
		hCharge1[iGlobal-N0]->Draw();
		//hPed1[iGlobal-N0]->Draw();
		//   hPed2[iGlobal-N0]->SetLineColor(2);hPed2[iGlobal-N0]->Draw("SAME");


		c[iGlobal-N0]->cd(2)->SetLogy();
		hCharge2[iGlobal-N0]->Draw();
		//  hCharge2[iGlobal-N0]->SetLineColor(2);hCharge2[iGlobal-N0]->Draw("SAME");

		c[iGlobal-N0]->cd(3)->SetLogy();
		hChargeCorr1[iGlobal-N0]->Draw();
		hChargeCorr2[iGlobal-N0]->SetLineColor(2);hChargeCorr2[iGlobal-N0]->Draw("SAMES");

		if ((iGlobal-N0)==0) c[iGlobal-N0]->Print((fOutNamePS+"(").c_str());
		else  c[iGlobal-N0]->Print(fOutNamePS.c_str());
		fOut->cd();
		c[iGlobal-N0]->Write();
	}

	TLine *l=new TLine(-0.5,-0.5,-0.5,7.5);l->SetLineWidth(2);l->SetLineColor(2);



	TCanvas *ca=new TCanvas("ca","ca");
	ca->Divide(3,3);
	ca->cd(1);hMean1->Draw("colz");
	ca->cd(2);hMean2->Draw("colz");
	ca->cd(3);hMeanRatio->Draw("colz");hGrid->SetMarkerColor(0);hGrid->SetMarkerSize(2);

	hGrid->Draw("TEXTSAME");



	ca->cd(4);hMeanRatio1D_H8500->Draw();


	ca->cd(5);hGain1->Draw("colz");
	ca->cd(6);hGain2->Draw("colz");
	ca->cd(7);hMeanRatio1D_Maroc->Draw();
	ca->cd(8);hMeanAll->Draw();

	ca->Print(fOutNamePS.c_str());
	fOut->cd();
	ca->Write();






	if (fDoBatch==0){
		gui.Run(1);
	}




	cout<<"Done"<<endl;
}



void ParseCommandLine(int argc,char **argv){
	for (int ii=0;ii<argc;ii++){

		if ((strcmp(argv[ii],"-f1")==0)||(strcmp(argv[ii],"-file1")==0)){
			fFileName1=string(argv[ii+1]);
			iCard1=atoi(argv[ii+2]);
			iPMT1=atoi(argv[ii+3]);
		}

		else  if ((strcmp(argv[ii],"-f2")==0)||(strcmp(argv[ii],"-file2")==0)){
			fFileName2=string(argv[ii+1]);
			iCard2=atoi(argv[ii+2]);
			iPMT2=atoi(argv[ii+3]);
		}
		else if ((strcmp(argv[ii],"-o")==0)||(strcmp(argv[ii],"-out")==0)){
			fOutName=string(argv[ii+1]);
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
	cout<<"-f1 or -file1: file name1 + card1 + PMT1"<<endl;
	cout<<"-f2 or -file2: file name2 + card2 + PMT2"<<endl;

	cout<<"-o or -out: output file name"<<endl;
	cout<<"-batch: batch mode"<<endl;
}









































