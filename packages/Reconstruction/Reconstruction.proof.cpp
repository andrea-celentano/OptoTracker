#include "TFile.h"
#include "TTree.h"
#include "TChain.h"
#include "TSystem.h"
#include "TProof.h"
#include "TProofLog.h"

#include "TH1D.h"
#include "TH2D.h"
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
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#include "OpNoviceDetectorHit.hh"
#include "OpNoviceDigi.hh"
#include "G4SystemOfUnits.hh"
#include "G4PhysicalConstants.hh"
#include "G4UnitsTable.hh"



#include "TOptoSelector.hh"
#include "TOptoSelectorRaw.hh"
#include "TOpNoviceDetectorLight.hh"
#include "TRecon.hh"
#include "TReconInput.hh"

using namespace std;



/*From the command line*/
string fName,detName,reconName;
int interactive=0;
int detNameCommandLine=0;
int doProof=0;
int doProofDiag=0;

double timeRes=-1;


//detector. Keep it global for "print" functions


void ParseCommandLine(int argc,char **argv);
void PrintHelp();

TApplication gui("gui",0,NULL);

//Recon input
TReconInput *m_reconInput=0;
//Detector
TOpNoviceDetectorLight *m_detector=0;

int main(int argc, char **argv){
     
	//Parse the command line
	ParseCommandLine(argc,argv);



	TH1::AddDirectory(kFALSE); 

	//Load Cintex and the shared library
	ROOT::Cintex::Cintex::Enable();
	gSystem->Load("libGeometryClassesDict.so");
	gSystem->Load("libOpNoviceClassesDict.so");
	gSystem->Load("libReconstructionClassesDict.so");

	int Nevents;
	TRandom3 rand(0);


	//Input file and output file
	TFile *fin,*fout;
	//Input chain 
	TChain *ch;
	//Selector
	TOptoSelector *selector;
	
	//PROOF
	TProof *pf;

	//open the input file

	fin=new TFile(fName.c_str()); 
	//Check if we have detector info in the ROOT file. 
	if (fin->GetListOfKeys()->Contains("TOpNoviceDetectorLight")){
		m_detector=(TOpNoviceDetectorLight*)fin->Get("TOpNoviceDetectorLight");
		cout<<"Detector found:"<<m_detector->getName()<<endl;
	}
	else {
		cout<<"Detector not found"<<endl;
		exit(1);
	}

	//OWR time resolution
	if (timeRes>=0){
		for (int ii=0;ii<6;ii++){
			for (int jj=0;jj<m_detector->getNdet(ii);jj++){
				if (m_detector->isDetPresent(ii,jj)) m_detector->setDetTimeRes(ii,jj,timeRes);
			}
		}
	}


	//Print detector information  

	m_detector->PrintPixels();
	m_detector->Print();

	//Create the TChain, fill it
	ch=new TChain("raw"); //must have the TTree name I am going to read
	ch->Add(fName.c_str());	
	Nevents=ch->GetEntries(); //1 entry=1 event
	cout<<"There are: "<<Nevents<<" events"<<endl;

	//Create the TReconInput
	m_reconInput=new TReconInput(reconName);
       // TReconInput m_reconInput(reconName);
	m_reconInput->Print();
	
	  m_reconInput->setName("minchia rec");
	  m_detector->setName("minchia det");
	  

	if (doProof){
		pf=TProof::Open("");
		pf->Exec("gSystem->Load(\"libCintex\")");
		pf->Exec("ROOT::Cintex::Cintex::Enable()");
		pf->Exec("gSystem->Load(\"${OPTO}/lib/libGeometryClassesDict.so\")");		
		pf->Exec("gSystem->Load(\"${OPTO}/lib/libReconstructionClassesDict.so\")");
		pf->Exec("gSystem->Load(\"${OPTO}/lib/libOpNoviceClassesDict.so\")");
		pf->SetLogLevel(1, TProofDebug::kPacketizer);
		pf->SetParameter("PROOF_Packetizer", "TPacketizer");
		//This is the way to do when using PROOF,
		//since we can't use a concrete instance of a selector, only the "class"
		
		
		pf->AddInput(m_detector);
		pf->AddInput(m_reconInput);
		ch->SetProof();   
	}
	else{
		//Create the Selector-derived class
		selector=new TOptoSelectorRaw();
		selector->setDetector(m_detector);
		selector->setReconInput(m_reconInput);
		//selectorRaw->setSeed(0);
	}


	if (doProof){
		if (doProofDiag){
			pf->SetProgressDialog(kTRUE);
		}
		else{
			pf->SetProgressDialog(kFALSE);
		}
		ch->Process("TOptoSelectorRaw");
	}
	else{
		ch->Process(selector);
	}
	cout<<"Process done"<<endl;

	if (doProof){
		pf->Print();
	}
	if (interactive){
		gui.Run(1);
	}

	cout<<"Save"<<endl;
	fout=new TFile((fName+".recon.root").c_str(),"recreate");
	fout->cd();
	if (doProof){
		pf->GetOutputList()->Write();
	}
	else{
		selector->GetOutputList()->Write();
	}

	//Also save the detector used for the analysis
	fout->WriteTObject(m_detector);
	fout->WriteTObject(m_reconInput);

	gSystem->Exit(0);

}



void ParseCommandLine(int argc,char **argv){
	for (int ii=0;ii<argc;ii++){
		if ((strcmp(argv[ii],"-f")==0)||(strcmp(argv[ii],"-fname")==0)){
			fName=string(argv[ii+1]);
		}

		else if ((strcmp(argv[ii],"-det")==0)||(strcmp(argv[ii],"-detname")==0)){
			detName=string(argv[ii+1]);
		}
		else if ((strcmp(argv[ii],"-recon")==0)||(strcmp(argv[ii],"-reconInput")==0)){
			reconName=string(argv[ii+1]);
		}

		else if ((strcmp(argv[ii],"-timeRes")==0)){ //owr the time resolution found in the detector object within the ROOT file
			timeRes=atof(argv[ii+1]);
		}
		else if ((strcmp(argv[ii],"-int")==0)||(strcmp(argv[ii],"-interactive")==0)){
			interactive=1;
		}
		else if ((strcmp(argv[ii],"-proof")==0)||(strcmp(argv[ii],"-Proof")==0)){
			doProof=1;
		}
		else if ((strcmp(argv[ii],"-proofDiag")==0)){
			doProofDiag=1;
		}		
		else if ((strcmp(argv[ii],"-h")==0)){
			PrintHelp();
			exit(1);
		}		

	}

}

void PrintHelp(){
    cout<<"-f or -fname: file name"<<endl;
    cout<<"-det or -detname: detector file name, if not already in fname"<<endl;
    cout<<"-recon or -reconInput: recon input file name"<<endl;
    cout<<"-timeRes : owr the detector time resoluiton"<<endl;
    cout<<"-int: interactive, i.e. draw plots at end"<<endl;
    cout<<"-proof: use PROOF"<<endl;
    cout<<"-proofDiag: show proof dialog"<<endl;
  
  
}




























