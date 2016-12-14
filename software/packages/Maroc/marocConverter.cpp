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
#include "TRandom3.h"
#include "TLatex.h"
#include "TClass.h"
#include "TObject.h"


#include "CommonMacros.hh"
#include "TMarocSetupHandler.hh"
#include "TDetector.hh"
#include "TDetectorUtils.hh"
#include "TEvent.hh"
#include "TMarocHit.hh"
#include "TMarocEventHeader.hh"

using namespace std;

#define N0 2048
#define Ntot 128

/*From the command line*/
string fInName,fOutName;
void ParseCommandLine(int argc,char **argv);
void PrintHelp();


int main(int argc,char **argv){
	if (argc==1){
		PrintHelp();
		exit(1);
	}
	ParseCommandLine(argc,argv);
	//Load Cintex and the shared library
	LOADLIBS




	if (fInName.length()==0){
		cerr<<"Missing input file name!"<<endl;
		return -1;
	}
	if (fOutName.length()==0){
		cout<<"Missing OUT file name, auto-selecting"<<endl;
		fOutName=fInName+".out.root";
	}

	TFile *fIn=new TFile(fInName.c_str());



	TTree *tIn=(TTree*)fIn->Get("fTdata");
	int N,id;

	Float_t ADC[TMarocSetupHandler::nMarocChannels];
	Bool_t hit[TMarocSetupHandler::nMarocChannels];


	Int_t EvtMultiplicity;
	TEvent *fEvent = 0;
	TClonesArray *fRootCollectionMarocHit=0;
	TMarocEventHeader *fEventHeader;
	TMarocHit *fHit;

	/*Create here what we need to write*/
	fEvent=0;
	TFile *fOut=new TFile(fOutName.c_str(),"recreate");
	TTree *fTree=new TTree("Event","Event");
	fTree->Branch("Event",&fEvent);
	cout<<"File and tree created"<<endl;

	fRootCollectionMarocHit=new TClonesArray("TMarocHit",Ntot); /*If more than s objects are entered, the array will be automatically expanded*/
	cout<<"Collections created"<<endl;

	fRootCollectionMarocHit->SetName("MarocHitRaw");
	cout<<"Collections named "<<endl;

	fEvent->addCollection(fRootCollectionMarocHit); /*Do not need to check if exists already*/
	cout<<"Collections added "<<endl;




	/*Process the signal*/
	tIn->SetBranchAddress("ADC",ADC);
	tIn->SetBranchAddress("EvtMultiplicity",&EvtMultiplicity);
	tIn->SetBranchAddress("hit",hit);


	N=tIn->GetEntries();
	cout<<"There are "<<N<<" signals "<<endl;
	for (int ii=0;ii<N;ii++){
		if ((ii%10000)==0) cerr<<"Processing: "<<ii<<endl;
		tIn->GetEntry(ii);
		fEvent->Clear("C"); /*This is a fundamental instruction*/

		fEventHeader = new TMarocEventHeader();
		fEventHeader->setMultiplicity(EvtMultiplicity);
		fEventHeader->setEventNumber(ii);
		fEvent->setEventHeader(fEventHeader);

		for (int jj=0;jj<Ntot;jj++){
			fHit=(TMarocHit*)fRootCollectionMarocHit->ConstructedAt(jj); //This creates a new TTofpetHit if necessary
			id=jj+N0;
			fHit->setMarocId(id);
			fHit->setCharge(ADC[id]);
			fHit->setHit(hit[id]);
		}
		fTree->Fill();
	}



	fOut->Write();
	fOut->Close();
	cout<<"Done"<<endl;
}



void ParseCommandLine(int argc,char **argv){
	for (int ii=0;ii<argc;ii++){
		if (strcmp(argv[ii],"-i")==0){
			fInName=string(argv[ii+1]);
		}
		else if ((strcmp(argv[ii],"-o")==0)||(strcmp(argv[ii],"-out")==0)){
			fOutName=string(argv[ii+1]);
		}
	}
}



void PrintHelp(){
	cout<<"-i: input file name"<<endl;
	cout<<"-o or -out: output file name"<<endl;
}
