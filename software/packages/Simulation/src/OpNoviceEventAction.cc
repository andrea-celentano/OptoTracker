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
// $Id: OpNoviceEventAction.cc 68752 2013-04-05 10:23:47Z gcosmo $
//
/// \file optical/OpNovice/src/OpNoviceEventAction.cc
/// \brief Implementation of the OpNoviceEventAction class
//
//
#include "OpNoviceEventAction.hh"
#include "OpNoviceDetectorHit.hh"
#include "OpNoviceDigi.hh"
#include "OpNoviceDigitizer.hh"
#include "OpNoviceUserEventInformation.hh"
#include "OpNoviceTrajectory.hh"
#include "OpNoviceRecorderBase.hh"

#include "G4EventManager.hh"
#include "G4SDManager.hh"
#include "G4DigiManager.hh"
#include "G4RunManager.hh"
#include "G4Event.hh"
#include "G4EventManager.hh"
#include "G4TrajectoryContainer.hh"
#include "G4Trajectory.hh"
#include "G4VVisManager.hh"
#include "G4ios.hh"
#include "G4UImanager.hh"
#include "G4SystemOfUnits.hh"


#include "RootIO.hh"
#include "TMCTruth.hh"
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

OpNoviceEventAction::OpNoviceEventAction(OpNoviceRecorderBase* r)
: fRecorder(r),fScintCollID(-1),fDetectorCollID(-1),fDetectorDigiCollID(-1),fVerbose(0),
  fForcedrawphotons(false),fForcenophotons(false),fMCTruth(NULL)
{
	G4cout<<"OpNoviceEventAction::creator"<<G4endl;
	fVerbose=0;
	//by default, save!
	fDoDigi=true;

	fSaveScintRaw=true;
	fSaveDetRaw=true;
	fSaveDetDigi=true;

	fMessenger = OpNoviceMessenger::GetInstance();
	fMessenger->SetEventAction(this);


}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

OpNoviceEventAction::~OpNoviceEventAction(){

	G4cout<<"OpNoviceEventAction::deconstructor"<<G4endl;

}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void OpNoviceEventAction::BeginOfEventAction(const G4Event* anEvent){

	//New event, add the user information object
	G4EventManager::GetEventManager()->SetUserInformation(new OpNoviceUserEventInformation);

	G4SDManager* SDman = G4SDManager::GetSDMpointer();
	if(fScintCollID<0)    fScintCollID=SDman->GetCollectionID("ScintHitCollection");
	if(fDetectorCollID<0)     fDetectorCollID=SDman->GetCollectionID("DetectorHitCollection");



	if(fRecorder)fRecorder->RecordBeginOfEvent(anEvent);


	((OpNoviceDigitizer*)(G4DigiManager::GetDMpointer()->FindDigitizerModule("OpNoviceDetectorDigitizer")))->SetDoDigi(fDoDigi);

	fRootIO=RootIO::GetInstance();
	fEvent=fRootIO->GetEvent();
	fEvent->Clear("C"); /*This is a fundamental instruction*/
	fMCTruth=new TMCTruth();
	fMCTruth->SetName("MCTruth");
	fEvent->addObject(fMCTruth); //add the MCTruth
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void OpNoviceEventAction::EndOfEventAction(const G4Event* anEvent){


	OpNoviceUserEventInformation* eventInformation=(OpNoviceUserEventInformation*)anEvent->GetUserInformation();
	G4TrajectoryContainer* trajectoryContainer=anEvent->GetTrajectoryContainer();

	G4int n_trajectories = 0;
	if (trajectoryContainer) n_trajectories = trajectoryContainer->entries();

	//extract the trajectories and draw them
	if (G4VVisManager::GetConcreteInstance()){
		for (G4int i=0; i<n_trajectories; i++){
			OpNoviceTrajectory* trj = (OpNoviceTrajectory*)((*(anEvent->GetTrajectoryContainer()))[i]);
			if(trj->GetParticleName()=="opticalphoton"){
				trj->SetForceDrawTrajectory(fForcedrawphotons);
				trj->SetForceNoDrawTrajectory(fForcenophotons);
			}
			trj->DrawTrajectory();
		}
	}


	/*
	fRootIO=RootIO::GetInstance();
	fEvent=fRootIO->GetEvent();
	fEvent->Clear("C"); //this is a fundamental instruction
	 */

	fRootCollectionScintRaw=fEvent->getCollection(OpNoviceScintHit::Class(),"ScintRawMC");
	fRootCollectionDetRaw=fEvent->getCollection(OpNoviceDetectorHit::Class(),"DetRawMC");
	fRootCollectionDetDigi=fEvent->getCollection(OpNoviceDigi::Class(),"DetDigiMC");




	detectorHC = 0;
	G4HCofThisEvent* hitsCE = anEvent->GetHCofThisEvent(); //hits
	//Get the hit collections
	if(hitsCE){
		if(fDetectorCollID>=0)  detectorHC=(OpNoviceDetectorHitsCollection*)(hitsCE->GetHC(fDetectorCollID));
		if(fScintCollID>=0)     scintHC = (OpNoviceScintHitsCollection*)(hitsCE->GetHC(fScintCollID));
	}

	//raw hits in scintillator
	fMCTruth->setEdep(0);
	fMCTruth->setEdepVis(0);
	if (scintHC){
		G4int scintN=scintHC->entries(); /*Here 1 hit is 1 hit in the scintillator*/
		//	G4cout<<" There are: "<<scintN<<" hits in scintillator"<<G4endl;
		for (G4int i=0;i<scintN;i++){
			//G4cout<<"Hit "<<i<<" energy: "<<(*scintHC)[i]->GetEdep()<<G4endl;
			fMCTruth->addEdep((*scintHC)[i]->GetEdep());
			fMCTruth->addEdepVis((*scintHC)[i]->GetEdepVis());
			if (fSaveScintRaw){ 
				((OpNoviceScintHit*)fRootCollectionScintRaw->ConstructedAt(i))->operator=(*((*scintHC)[i]));
			}
		}
	}


	//raw hits in detector
	if(detectorHC){
		G4int detectorN=detectorHC->entries(); /*Here 1 hit is "1 detector".*/
		//Gather info from all detectors
		for(G4int i=0;i<detectorN;i++){

			eventInformation->IncHitCount((*detectorHC)[i]->GetPheCount());
			/*
			if((*detectorHC)[i]->GetPheCount()>=fPMTThreshold){
				eventInformation->IncPMTSAboveThreshold();
			}
			else{//wasnt above the threshold, turn it back off
				(*detectorHC)[i]->SetDrawit(false);
			}*/

			if (fSaveDetRaw){
				((OpNoviceDetectorHit*)fRootCollectionDetRaw->ConstructedAt(i))->operator=(*((*detectorHC)[i]));
			}
		}
		/*Scala di colore qui*/
		/*for(G4int i=0;i<pmts;i++){
			(*pmtHC)[i]->SetDrawScaleMax(eventInformation->GetHitCount());
		}*/
		if (G4VVisManager::GetConcreteInstance()!=0){
			//	detectorHC->DrawAllHits();
		}
	}

	//digi hits in detector
	if (fDoDigi){
		detectorDigiHC = 0;
		G4DCofThisEvent* hitsDC = anEvent->GetDCofThisEvent(); //all digits

		if (fDetectorDigiCollID<0){ //1: get the collection ID
			G4DigiManager* Digiman = G4DigiManager::GetDMpointer();
			fDetectorDigiCollID=Digiman->GetDigiCollectionID("DetectorDigiHitCollection");
		}
		if (hitsDC){ //2: Get the collection
			if(fDetectorDigiCollID>=0) detectorDigiHC = (OpNoviceDigitsCollection*)(hitsDC->GetDC(fDetectorDigiCollID));
		}	
		if(detectorDigiHC){//3: Use it
			G4int DetectorDigiN=detectorDigiHC->entries();
			//Gather info from all DigiPMTs
			for(G4int i=0;i<DetectorDigiN;i++){
				if (fSaveDetDigi){
					((OpNoviceDigi*)fRootCollectionDetDigi->ConstructedAt(i))->operator=(*((*detectorDigiHC)[i]));
				}
			}
			if (G4VVisManager::GetConcreteInstance()!=0){
				//detectorDigiHC->DrawAllDigi();
			}
		}
	}



	fRootIO->FillEvent();

	delete fMCTruth;

	if(fVerbose>0){
		//End of event output. later to be controlled by a verbose level
		G4cout << "\tNumber of total phe in all detectors in this event : "
				<< eventInformation->GetHitCount() << G4endl;
		G4cout << "\tNumber of photons produced by scintillation in this event : "
				<< eventInformation->GetPhotonCount_Scint() << G4endl;
		G4cout << "\tNumber of photons detected in this event : "
				<< eventInformation->GetDetectionCount() << G4endl;
		G4cout << "\tNumber of photons absorbed (OpAbsorption) in this event : "
				<< eventInformation->GetAbsorptionCount() << G4endl;
		G4cout << "\tNumber of photons absorbed at boundaries (OpBoundary) in "
				<< "this event : " << eventInformation->GetBoundaryAbsorptionCount()
				<< G4endl;
		G4cout << "Unacounted for photons in this event : "
				<< (eventInformation->GetPhotonCount_Scint() -
						eventInformation->GetAbsorptionCount() -
						eventInformation->GetDetectionCount() -
						eventInformation->GetBoundaryAbsorptionCount())
						<< G4endl;
	}

	if(fRecorder)fRecorder->RecordEndOfEvent(anEvent);


}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......


