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

	int doProof;
	int doProofDiag;
	//Selector

	TJobManager *manager=new TJobManager();
	manager->Config("recon.xml");
	//PROOF
	TProof *pf;

	TChain *ch=new TChain("Event");
	ch->Add("test.root");

	doProof=manager->getDoProof();
	doProofDiag=manager->getDoProofDiag();
	if (doProof){
		pf=TProof::Open(Form("workers=%i",manager->getNumberOfWorkers()));
		pf->Exec("gSystem->Load(\"libCintex\")");
		pf->Exec("ROOT::Cintex::Cintex::Enable()");
		pf->Exec("gSystem->Load(\"${OPTO}/lib/libCommonClassesDict.so\")");
		pf->Exec("gSystem->Load(\"${OPTO}/lib/libOpNoviceClassesDict.so\")");
		pf->Exec("gSystem->Load(\"${OPTO}/lib/libReconstructionNewClassesDict.so\")");
		pf->SetLogLevel(1, TProofDebug::kPacketizer);
		pf->SetParameter("PROOF_Packetizer", "TPacketizer");
		ch->SetProof();
		if (doProofDiag){
			pf->SetProgressDialog(kTRUE);
		}
		else{
			pf->SetProgressDialog(kFALSE);
		}
	}


	ch->Process(manager,"",manager->getNumberOfEvents(),manager->getSkipEvents());

}

