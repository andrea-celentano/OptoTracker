#include "TFile.h"
#include "TTree.h"
#include "TChain.h"
#include "TSystem.h"
#include "TProof.h"
#include "TProofLog.h"

#include "TH1D.h"
#include "TH2D.h"
#include "TF1.h"
#include "TMath.h"
#include "TCanvas.h"
#include "TApplication.h"
#include "TVector3.h"
#include "TRandom3.h"
#include "TGraph.h"
#include "TGraph2D.h"
#include "Cintex/Cintex.h"


#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#include "OpNoviceDetectorHit.hh"
#include "OpNoviceDigi.hh"
#include "G4SystemOfUnits.hh"
#include "G4PhysicalConstants.hh"
#include "G4UnitsTable.hh"

#include "TOpNoviceDetectorLight.hh"
#include "TRecon.hh"
#include "TReconInput.hh"
#include "TReconDefs.hh"

using namespace std;

void ParseCommandLine(int argc,char **argv);
void PrintHelp();

/*From the command line*/
string fName,fRecon;

TApplication gui("gui",0,NULL);




Double_t
poissonf(Double_t*x,Double_t*par){                                                                              
	return par[0]*TMath::Poisson(x[0],par[1]);
}      

int main(int argc,char **argv){
	//Load Cintex and the shared library
	ROOT::Cintex::Cintex::Enable();
	gSystem->Load("libGeometryClassesDict.so");
	gSystem->Load("libOpNoviceClassesDict.so");	
	gSystem->Load("libReconstructionClassesDict.so");


	int Nevents,Nhits;
	int detNumber,faceNumber,pixelNumber;
	int Nx,Ny;
	double qMean,solidAngle,eff;

	TRandom3 rand(0);
	TVector3 vin,vout;

	//Input file and output file
	TFile *fin,*fout;
	//Input chain
	TChain *fChain;
	//detector
	TOpNoviceDetectorLight *m_detector;
	//Reconstruction
	TRecon *m_recon;
	//Input for the recon
	TReconInput *m_reconInput;

	double N0=1;

	vector < TH1D* > hTime[6][MAX_DETECTORS];

	//Parse the command line, open the input file
	ParseCommandLine(argc,argv);
	fin=new TFile(fName.c_str());
	//Check if we have detector info in the ROOT file.
	if (fin->GetListOfKeys()->Contains("TOpNoviceDetectorLight")){
		m_detector=(TOpNoviceDetectorLight*)fin->Get("TOpNoviceDetectorLight");
		cout<<"Detector found:"<<m_detector->getName()<<endl;
	}
	else{
		cout<<"Detector not found"<<endl;
		exit(1);
	}




	//Print detector information

	m_detector->PrintPixels();
	m_detector->Print();

	//Create the recon input
	m_reconInput=new TReconInput(fRecon);
	m_reconInput->Print();

	for (int ii=0;ii<6;ii++){
		for (int jj=0;jj<m_detector->getNdet(ii);jj++){
			if (m_detector->isDetPresent(ii,jj)){
				Nx=m_detector->getNPixelsX(ii,jj);
				Ny=m_detector->getNPixelsY(ii,jj);
				/*	hChargeAll[ii][jj]=new TH1D(Form("hChargeDet%i_%i",ii,jj),Form("hChargeDet%i_%i",ii,jj),Nx*Ny,-0.5,Nx*Ny-0.5);
				hChargeF[ii][jj]=new TH1D(Form("hChargeF%i_%i",ii,jj),Form("hChargeF%i_%i",ii,jj),Nx*Ny,-0.5,Nx*Ny-0.5);

				hChargeAll2D[ii][jj]=new TH2D(Form("hChargeAll2D%i_%i",ii,jj),Form("hChargeDet%i_%i",ii,jj),Nx,-0.5,Nx-0.5,Ny,-0.5,Ny-0.5);
				hChargeF2D[ii][jj]=new TH2D(Form("hChargeF2D%i_%i",ii,jj),Form("hChargeF%i_%i",ii,jj),Nx,-0.5,Nx-0.5,Ny,-0.5,Ny-0.5);*/

				for (int id=0;id<Nx*Ny;id++){
					hTime[ii][jj].push_back(new TH1D(Form("hTime_%i_%i_%i",ii,jj,id),Form("hTime_%i_%i_%i",ii,jj,id),1000,-0.5,99.5)); /*100 ps bin*/
				}
			}
		}
	}

	fChain=new TChain("DetDigi"); //must have the TTree name I am going to read
	fChain->Add(fName.c_str());
	Nevents=fChain->GetEntries(); //1 entry=1 event
	cout<<"There are: "<<Nevents<<" events"<<endl;





	//Connect to the TTree
	vector<OpNoviceDigi*> *digi=NULL;
	fChain->SetBranchAddress("digi", &digi);

	cout<<"There are "<<Nevents<<endl;

	for (int ii=0;ii<Nevents;ii++){
		fChain->GetEntry(ii);
		Nhits=digi->size();
		for (int jj=0;jj<Nhits;jj++){
			faceNumber=digi->at(jj)-> GetFaceNumber();
			detNumber=digi->at(jj)-> GetDetectorNumber();
			pixelNumber=digi->at(jj)-> GetPixelNumber();
			cout<<digi->at(jj)->GetFirstHitTime()<<endl;
			hTime[faceNumber][detNumber].at(pixelNumber)->Fill(digi->at(jj)->GetFirstHitTime());
		}
	}


	//Create the reconstruction object
	m_recon=new TRecon(m_detector,m_reconInput);





	int id=0;
	for (int ii=0;ii<6;ii++){
		for (int jj=0;jj<m_detector->getNdet(ii);jj++){
			id=0;
			if (m_detector->isDetPresent(ii,jj)){
				Nx=m_detector->getNPixelsX(ii,jj);
				Ny=m_detector->getNPixelsY(ii,jj);
				for (int idy=0;idy<Ny;idy++){
					for (int idx=0;idx<Nx;idx++){




						id++;
					}
				}
			}
		}
	}
	cout<<"All charge fits done"<<endl;

	vin.SetXYZ(m_reconInput->getParVal(k_x0),m_reconInput->getParVal(k_y0),m_reconInput->getParVal(k_z0));
	vout.SetXYZ(m_reconInput->getParVal(k_x1),m_reconInput->getParVal(k_y1),m_reconInput->getParVal(k_z1));
	N0=m_reconInput->getParVal(k_N0);



	/*
	TCanvas *c=new TCanvas("c","c");
	c->Divide(6,3);
	for (int ii=0;ii<6;ii++){
		for (int jj=0;jj<m_detector->getNdet(ii);jj++){
			if (m_detector->isDetPresent(ii,jj)){
				c->cd(jj*6+ii+1);
				hTime[ii][jj]->Draw();
			}
		}
	}



	gui.Run(1);*/



	fout=new TFile((fName+".time.root").c_str(),"recreate");
	fout->cd();
	for (int ii=0;ii<6;ii++){
		for (int jj=0;jj<m_detector->getNdet(ii);jj++){
			if (m_detector->isDetPresent(ii,jj)){
				Nx=m_detector->getNPixelsX(ii,jj);
				Ny=m_detector->getNPixelsY(ii,jj);
				for (int id=0;id<Nx*Ny;id++){
					hTime[ii][jj].at(id)->Write();
				}
			}
		}
	}
	fout->Write();
	fout->Close();

}

void ParseCommandLine(int argc,char **argv){



	for (int ii=0;ii<argc;ii++){
		if ((strcmp(argv[ii],"-f")==0)||(strcmp(argv[ii],"-fname")==0)){
			fName=string(argv[ii+1]);
		}
		else if ((strcmp(argv[ii],"-r")==0)){
			fRecon=string(argv[ii+1]);
		}
		else if ((strcmp(argv[ii],"-h")==0)){
			PrintHelp();
			exit(0);
		}
	}




}


void PrintHelp(){
	cout<<"-f or -fname <file> : ROOT file with MC results"<<endl;
	cout<<"-r <file>: recon input file"<<endl;
	cout<<"-h: this help"<<endl;
}










