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
#include "TCitirocSetupHandler.hh"
#include "TDetector.hh"
#include "TDetectorUtils.hh"
#include "TEvent.hh"
#include "TCitirocHitRaw.hh"
#include "TCitirocEventHeader.hh"


#define NBOARDS 2

using namespace std;

string inFileName;
string outFileName;
string geomFileName;
int nEvents=-1;
int nBoards=1;
bool doGeom=false;
double coincWindow=1000; //in ns

void printHelp(){
	cout<<"use options: "<<endl;
	cout<<"-infile inputFileName"<<endl;
	cout<<"-outfile outputFileName"<<endl;
	cout<<"-dT coincWindow width (ns)"<<endl;
	cout<<"-geom geometryFileName (optional)"<<endl;
	cout<<"-nEvt numberOfEventsToProcess (optional)"<<endl;
	cout<<"-nBoards minimum number of Citiroc boards to define an event (optional, 1 otherwise)"<<endl;
	cout<<"-h help"<<endl;
}

bool checkBlockEnds(const vector<int> &data);


void parseCommandLine(int argc,char **argv){
	for (int ii=1;ii<argc;ii++){
		if ((strcmp(argv[ii],"-infile")==0)||(strcmp(argv[ii],"-in")==0)) inFileName=argv[ii+1];
		if ((strcmp(argv[ii],"-outfile")==0)||(strcmp(argv[ii],"-out")==0)) outFileName=argv[ii+1];
		if (strcmp(argv[ii],"-dT")==0) coincWindow=atof(argv[ii+1]);
		if ((strcmp(argv[ii],"-geom")==0)||(strcmp(argv[ii],"-geometry")==0)) {geomFileName=argv[ii+1];doGeom=true;}
		if (strcmp(argv[ii],"-nEvt")==0) nEvents=atoi(argv[ii+1]);
		if (strcmp(argv[ii],"-nBoards")==0) nBoards=atoi(argv[ii+1]);
		if (strcmp(argv[ii],"-h")==0) printHelp();
	}
}

int main(int argc,char **argv){
	//Load Cintex and the shared library
	LOADLIBS


	if (argc==1){
		printHelp();
		exit(0);
	}
	parseCommandLine(argc,argv);


	/*Open the input root file and get the TTree*/
	TFile *fin=new TFile(inFileName.c_str());
	TTree *tin=(TTree*)fin->Get("mppc");
	int N=tin->GetEntries();
	if (nEvents<=0) nEvents=N;
	cout<<"There are: "<<N<<" hits"<<endl;
	cout<<"Processing: "<<nEvents<<" hits"<<endl;



	/*Variables for the input TTree*/
	UInt_t ts0,ts1,ts0_ref,ts1_ref;
	UShort_t charge[TCitirocSetupHandler::nCitirocChannelsPerBoard];
	UChar_t mac5;


	/*Open the output root file, create the TEvent*/
	if (strlen(outFileName.c_str())==0){
		outFileName="out.root"; //some kind of default
	}



	TEvent *fEvent=0;
	TClonesArray *fRootCollectionCitirocHitRaw=0;
	TCitirocEventHeader *fEventHeader;
	TCitirocHitRaw *fHit;


	fEvent=0;
	TFile *fout=new TFile(outFileName.c_str(),"recreate");
	TTree *tout=new TTree("Event","Event");
	tout->Branch("Event",&fEvent);
	cout<<"File and tree created "<<&fEvent<<endl;

	fRootCollectionCitirocHitRaw=new TClonesArray("TCitirocHitRaw",NBOARDS*TCitirocSetupHandler::nCitirocChannelsPerBoard);
	cout<<"Collections created"<<endl;

	fRootCollectionCitirocHitRaw->SetName("CitirocHitRaw");
	cout<<"Collections named "<<endl;

	fEvent->addCollection(fRootCollectionCitirocHitRaw); /*Do not need to check if exists already*/
	cout<<"Collections added "<<endl;

	/*Process the signal*/
	tin->SetBranchAddress("mac5",&mac5);
	tin->SetBranchAddress("ts0",&ts0);
	tin->SetBranchAddress("ts1",&ts1);
	tin->SetBranchAddress("ts0_ref",&ts0_ref);
	tin->SetBranchAddress("ts1_ref",&ts1_ref);
	tin->SetBranchAddress("chg",charge);

	/*Variables for the loop*/
	int this_ts0,this_mac5;
	int prev_ts0,prev_mac5;
	int next_ts0,next_mac5;
	int delta_ts0;
	int ii,jj,ihit;
	int multiplicity;

	bool alreadyAssociated[nEvents];
	vector<int> countBlocksPerBoard;
	for (int jj=0;jj<nEvents;jj++) alreadyAssociated[jj]=false;

	for(ii = 0 ; ii < nEvents ; ii++ ) {

		if (ii%1000==0) cerr<<"Hit "<<ii<<endl;

		if (alreadyAssociated[ii]) continue; //to guarantee no hits are associated twice!
		tin->GetEntry(ii);
		this_ts0=ts0;
		this_mac5=mac5;

		/*Prepare the event*/
		fEvent->Clear("C"); /*This is a fundamental instruction*/
		fEventHeader = new TCitirocEventHeader();
		fEventHeader->setTs0(this_ts0);
		fEventHeader->setTs1(ts1);
		fEventHeader->setTs0Ref(ts0_ref);
		fEventHeader->setTs1Ref(ts1_ref);


		/*Fill it with this hit information*/
		alreadyAssociated[ii]=true;
		multiplicity=1;
		for (ihit=0;ihit<TCitirocSetupHandler::nCitirocChannelsPerBoard;ihit++){
			fHit=(TCitirocHitRaw*)fRootCollectionCitirocHitRaw->ConstructedAt(ihit); //This creates a new TCitirocRawHit if necessary
			fHit->setCharge(charge[ihit]);
			fHit->setMAC(mac5);
			fHit->setChannel(ihit);
		}

		jj=ii;
		next_ts0=this_ts0;
		next_mac5=this_mac5;
		countBlocksPerBoard.clear();
		for (int iboard=0;iboard<NBOARDS;iboard++){
			countBlocksPerBoard.push_back(0);
		}
		countBlocksPerBoard[this_mac5]=999;
		while(1){
			jj++;
			if (jj>=(nEvents-1)) break; //end of events
			if (alreadyAssociated[jj]==true) continue; //already associated event

			prev_ts0=next_ts0;
			prev_mac5=next_mac5;
			tin->GetEntry(jj);
			next_ts0=ts0;
			next_mac5=mac5;

			if (next_mac5!=prev_mac5){ //end of a block. Check if we break here
				countBlocksPerBoard[prev_mac5]++;
				if (checkBlockEnds(countBlocksPerBoard)) break;
			}
			if ((fabs(next_ts0-this_ts0)<coincWindow)&&(next_mac5!=this_mac5)){ //coincidence hit
				alreadyAssociated[jj]=true;
				for (ihit=0;ihit<TCitirocSetupHandler::nCitirocChannelsPerBoard;ihit++){
					fHit=(TCitirocHitRaw*)fRootCollectionCitirocHitRaw->ConstructedAt(ihit+multiplicity*TCitirocSetupHandler::nCitirocChannelsPerBoard); //This creates a new TCitirocRawHit if necessary
					fHit->setCharge(charge[ihit]);
					fHit->setMAC(next_mac5);
					fHit->setChannel(ihit);
				}
				multiplicity++;
			}
		}
		fEventHeader->setMultiplicity(multiplicity);
		fEvent->setEventHeader(fEventHeader);

		if (multiplicity>=nBoards){
			tout->Fill();
		}
	}
	tout->Write();
	fout->Close();
}

bool checkBlockEnds(const vector<int> &data){
	int N=data.size();
	bool flag=true;
	for (int ii=0;ii<N;ii++){
		if (data[ii]<2) flag=false;
	}
	return flag;
}
