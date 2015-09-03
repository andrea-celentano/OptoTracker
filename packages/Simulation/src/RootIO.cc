//
// ********************************************************************
// * License and Disclaimer                                           *
// *                                                                  *
// * The  Geant4 software  is  copyright of the Copyright Holders  of *
// * the Geant4 Collaboration.  It is provided  under  the terms  and *
// * conditions of the Geant4 Software License,  included in the file *
// * LICENSE and available at  http://cern.ch/geant4/license .  These *
// * include a list of copyright holders.                             *
// *                                                                  *
// * Neither the authors of this software system, nor their employing *
// * institutes,nor the agencies providing financial support for this *
// * work  make  any representation or  warranty, express or implied, *
// * regarding  this  software system or assume any liability for its *
// * use.  Please see the license in the file  LICENSE  and URL above *
// * for the full disclaimer and the limitation of liability.         *
// *                                                                  *
// * This  code  implementation is the result of  the  scientific and *
// * technical work of the GEANT4 collaboration.                      *
// * By using,  copying,  modifying or  distributing the software (or *
// * any work based  on the software)  you  agree  to acknowledge its *
// * use  in  resulting  scientific  publications,  and indicate your *
// * acceptance of all terms of the Geant4 Software license.          *
// ********************************************************************
//
/// \file persistency/P01/src/RootIO.cc
/// \brief Implementation of the RootIO class
//
// $Id: RootIO.cc 82130 2014-06-11 09:26:44Z gcosmo $
//
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#include <sstream>

#include "RootIO.hh"
//
#include "Cintex/Cintex.h"
#include "G4SDManager.hh"
#include "G4HCofThisEvent.hh"
#include "G4EventManager.hh"
#include "G4Event.hh"
//

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

static RootIO* instance = 0;

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

RootIO::RootIO():fNevents(0),fFile(NULL),fName("")
{
	G4cout<<"RootIO::creator"<<G4endl;
	// initialize ROOT

	//gSystem->Load("libOpNoviceClassesDict");

	ROOT::Cintex::Cintex::SetDebug(0);
	ROOT::Cintex::Cintex::Enable();
	//gDebug = 1;

	fFile=NULL;
	fTree=NULL;
	fEvent=NULL;

	fRootCollectionScintRaw=NULL;
	fRootCollectionDetRaw=NULL;
	fRootCollectionDetDigi=NULL;


	fSaveScintRaw=true;
	fSaveDetRaw=true;
	fSaveDetDigi=true;


	fMCEvent = new MCEvent;


	fHistograms1D=NULL;
	fHistograms2D=NULL;
	instance=this;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
RootIO::~RootIO()
{
	fFile->Close();
	delete fMCEvent;
	if(fRootCollectionScintRaw) delete fRootCollectionScintRaw;
	if(fRootCollectionDetRaw) delete fRootCollectionDetRaw;
	if(fRootCollectionDetDigi) delete fRootCollectionDetDigi;

}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

RootIO* RootIO::GetInstance()
{
	if (instance == 0 )
	{
		G4cout<<"RootIO::GetInstance is creating a new RootIO"<<G4endl;
		instance = new RootIO();
	}
	return instance;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......



void RootIO::Init(int n){

	if (fFile) delete fFile;

	std::string fFileName=Form("%s_%i.root",fName.c_str(),n);
	fFile = new TFile(fFileName.c_str(),"RECREATE");
	fTree = new TTree("Event","Event");
	fTree->Branch("Event",&fEvent);

	/*Here we need to set the collections of our event*/
	fRootCollectionScintRaw=new TClonesArray("OpNoviceScintHit",1000); /*If more than s objects are entered, the array will be automatically expanded*/
	fRootCollectionDetRaw=new TClonesArray("OpNoviceDetectorHit",1000);
	fRootCollectionDetDigi=new TClonesArray("OpNoviceDigi",1000);

	fRootCollectionScintRaw->SetName("ScintRawMC");
	fRootCollectionDetRaw->SetName("DetRawMC");
	fRootCollectionDetDigi->SetName("DetDigiMC");
	fEvent->addCollection(fRootCollectionScintRaw); /*Do not need to check if exists already*/
	fEvent->addCollection(fRootCollectionDetRaw);
	fEvent->addCollection(fRootCollectionDetDigi);



	fHistograms1D=new std::vector<TH1*>;
	fHistograms2D=new std::vector<TH2*>;
	/*Define here histograms*/
	fHistograms1D->push_back(new TH1D("hy","hy",200,-3.1,3.1));   //0
	fHistograms1D->push_back(new TH1D("hY1","hY1",200,-3.1,3.1)); //1


	fHistograms2D->push_back(new TH2D("hGenYX","hGenYX",600,-3.1,3.1,600,-3.1,3.1)); //0
	fHistograms2D->push_back(new TH2D("hGenYZ","hGenYZ",600,-3.1,3.1,600,-3.1,3.1)); //1
	fHistograms2D->push_back(new TH2D("hGenXZ","hGenXZ",600,-3.1,3.1,600,-3.1,3.1)); //2
	for (int ii=0;ii<6;ii++) fHistograms2D->push_back(new TH2D(Form("hRecXY_%i",ii),Form("hRecXY_%i",ii),600,-3.1,3.1,600,-3.1,3.1)); //3..8


}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......


//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void RootIO::FillEvent()
{
	fTree->Fill();
}


void RootIO::WriteAll(){
	/// Write the Root tree in the file and close it (it is called at the end of run, 1 run == 1 file).
	fFile->cd();
	for (int ii=0;ii<fHistograms1D->size();ii++){
		fHistograms1D->at(ii)->Write();
	}
	for (int ii=0;ii<fHistograms2D->size();ii++){
		fHistograms2D->at(ii)->Write();
	}
	fFile->Write();
	G4cout<<"RootIO::WriteAll done"<<G4endl;
}




void RootIO::fillHistogram1D(int idx,double x,double w=1){
	fHistograms1D->at(idx)->Fill(x,w);	
}
void RootIO::fillHistogram2D(int idx,double x,double y,double w=1){
	((TH2*)(fHistograms2D->at(idx)))->Fill(x,y,w);	
}


void RootIO::saveDetectorLight(TOpNoviceDetectorLight *detector){
	fFile->WriteTObject(detector);
	//	detector->Write();
}


//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
