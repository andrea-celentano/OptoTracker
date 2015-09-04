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

//#include "TEvent.hh"
//#include "TOptoJobManager.hh"

//#include "OpNoviceDigi.hh"
//#include "OpNoviceDetectorHit.hh"
/*#include "OpNoviceDetectorHit.hh"
#include "OpNoviceDigi.hh"
#include "G4SystemOfUnits.hh"
#include "G4PhysicalConstants.hh"
#include "G4UnitsTable.hh"*/



//#include "TOpNoviceDetectorLight.hh"

using namespace std;


TApplication gui("gui",0,NULL);

int main(int argc,char **argv){
	TH1::AddDirectory(kFALSE);

	//Load Cintex
	ROOT::Cintex::Cintex::Enable();

	//Selector
	//TOptoJobManager *manager=new TOptoJobManager();
	//manager->setTmp2(22);
	//PROOF
	//TProof *pf;

	TChain *ch=new TChain("Event");
	ch->Add("test.root");
	int doProof=0;
	int doProofDiag=1;


	//TEvent *ev=0;
	//ch->SetBranchAddress("Event",&ev);
	//TClonesArray *tmp=0;
	cout<<"Entries: "<<ch->GetEntries()<<endl;
	//for (int ii=0;ii<ch->GetEntries();ch++){
		//if (ev) ev->Clear("C");
		//if (tmp) tmp->Clear();
		//ch->GetEntry(ii);
		//ev->printCollections();
	//	tmp=ev->getCollection(OpNoviceDetectorHit::Class(),"DetRawMC");





	//	cout<<tmp->GetEntriesFast()<<endl;
		//for (int jj=0;jj<tmp->GetEntriesFast();jj++){
		//	cout<<((OpNoviceDetectorHit*)tmp->At(jj))->GetPheCount()<<endl;
		//}
	//}
	cout<<"DONE"<<endl;
	/*cin.get();


	if (doProof){
			pf=TProof::Open("workers=2");
			pf->Exec("gSystem->Load(\"libCintex\")");
			pf->Exec("ROOT::Cintex::Cintex::Enable()");
			pf->Exec("gSystem->Load(\"${OPTO}/lib/libCommonClassesDict.so\")");
			pf->Exec("gSystem->Load(\"${OPTO}/lib/libReconstructionNewClassesDict.so\")");
			pf->Exec("gSystem->Load(\"${OPTO}/lib/libOpNoviceClassesDict.so\")");
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
*/
}
