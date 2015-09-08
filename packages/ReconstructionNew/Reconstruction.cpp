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

#include "TEvent.hh"
#include "TJobManager.hh"

#include "OpNoviceDigi.hh"
#include "OpNoviceDetectorHit.hh"
#include "OpNoviceScintHit.hh"
#include "OpNoviceDigi.hh"
#include "G4SystemOfUnits.hh"
#include "G4PhysicalConstants.hh"
#include "G4UnitsTable.hh"



//#include "TOpNoviceDetectorLight.hh"

using namespace std;


TApplication gui("gui",0,NULL);

int main(int argc,char **argv){
	TH1::AddDirectory(kFALSE);

	//Load Cintex
	ROOT::Cintex::Cintex::Enable();


	/*
	TFile *fout=new TFile("fout.root","recreate");
	TTree *tout=new TTree("out","out");
	TEvent *evOut=new TEvent();
	tout->Branch("event",&evOut);

	TClonesArray *coll;
	coll=new TClonesArray("OpNoviceDigi",1000);
	coll->SetName("COLLEZIONE");
	evOut->addCollection(coll);
	for (int ii=0;ii<10;ii++){
		evOut->Clear("C");
		for (int jj=0;jj<ii+10;jj++){
			((OpNoviceDigi*)evOut->getCollection(OpNoviceDigi::Class(),"COLLEZIONE")->ConstructedAt(jj))->SetPixelNumber(ii*100+jj);
		}

		tout->Fill();
	}
	tout->Write();
	fout->Close();
	cout<<"Write done"<<endl;


	TChain *chin=new TChain("out");
	chin->Add("fout.root");
	TEvent *evIn=0;
	chin->SetBranchAddress("event",&evIn);
	TClonesArray *collout;
	for (int ii=0;ii<chin->GetEntries();ii++){
		if (evIn) evIn->Clear("C");
		chin->GetEntry(ii);
		evIn->printCollections();
		collout=evIn->getCollection(OpNoviceDigi::Class(),"COLLEZIONE");
		cout<<collout->GetEntriesFast()<<endl;
		for (int qq=0;qq<collout->GetEntriesFast();qq++){
			cout<<((OpNoviceDigi*)evIn->getCollection(OpNoviceDigi::Class(),"COLLEZIONE")->At(qq))->GetPixelNumber()<<endl;
		}
	}*/
/*

	TChain *ch=new TChain("Event");
	ch->Add("test.root");
	int doProof=0;
	int doProofDiag=1;


	TEvent *ev=0;
	ch->SetBranchAddress("Event",&ev);
	TClonesArray *tmp=0;
	TClonesArray *tmp2=0;
	int N=ch->GetEntries();
	cout<<"Entries: "<<N<<endl;
	for (int ii=0;ii<N;ii++){
		if (ev) ev->Clear("C");
		//if (tmp) tmp->Clear();
		ch->GetEntry(ii);
		ev->printCollections();
		tmp=ev->getCollection(OpNoviceDigi::Class(),"DetDigiMC");
		tmp2=ev->getCollection(OpNoviceDetectorHit::Class(),"DetRawMC");
		cout<<tmp->GetEntriesFast()<<endl;
		for (int jj=0;jj<tmp->GetEntriesFast();jj++){
			cout<<"DIGI :"<<((OpNoviceDigi*)tmp->At(jj))->GetName()<<" ";
			cout<<((OpNoviceDigi*)tmp->At(jj))->GetPheCount()<<endl;
		}
		for (int jj=0;jj<tmp2->GetEntriesFast();jj++){
			cout<<"RAW: "<<((OpNoviceDetectorHit*)tmp2->At(jj))->GetName()<<" ";
			cout<<((OpNoviceDetectorHit*)tmp2->At(jj))->GetPheCount()<<endl;
		}
	}
	cout<<"DONE"<<endl;
	cin.get();*/

//Selector
	TJobManager *manager=new TJobManager();
	//PROOF
	TProof *pf;

	TChain *ch=new TChain("Event");
	ch->Add("test.root");
	int doProof=1;
	int doProofDiag=0;

	if (doProof){
			pf=TProof::Open("workers=2");
			pf->Exec("gSystem->Load(\"libCintex\")");
			pf->Exec("ROOT::Cintex::Cintex::Enable()");
			pf->Exec("gSystem->Load(\"${OPTO}/lib/libCommonClassesDict.so\")");
			pf->Exec("gSystem->Load(\"${OPTO}/lib/libOpNoviceClassesDict.so\")");
			pf->Exec("gSystem->Load(\"${OPTO}/lib/libReconstructionNewClassesDict.so\")");
			pf->SetLogLevel(1, TProofDebug::kPacketizer);
			pf->SetParameter("PROOF_Packetizer", "TPacketizer");
			//This is the way to do when using PROOF,
			//since we can't use a concrete instance of a selector, only the "class"
			ch->SetProof();
		}
		else{
			//Create the Selector-derived class
			//selectorRaw->setSeed(0);
		}

		manager->Config("recon.xml");

		if (doProof){
			if (doProofDiag){
				pf->SetProgressDialog(kTRUE);
			}
			else{
				pf->SetProgressDialog(kFALSE);
			}
		//	ch->Process("TOptoJobManager");
			ch->Process(manager);
		}
		else{
			ch->Process(manager);
		}
}

