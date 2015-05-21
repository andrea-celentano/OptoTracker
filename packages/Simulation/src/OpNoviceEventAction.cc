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
#include "OpNovicePMTHit.hh"
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
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

OpNoviceEventAction::OpNoviceEventAction(OpNoviceRecorderBase* r)
: fRecorder(r),fSaveThreshold(0),fPMTCollID(-1),fPMTDigiCollID(-1),fVerbose(0),
fPMTThreshold(1),fForcedrawphotons(false),fForcenophotons(false)
{
	G4cout<<"OpNoviceEventAction::creator"<<G4endl;
	fVerbose=0;
	//by default, save!
	fSaveDigi=true;
	fSaveRaw=true;
	fDoDigi=true;
	
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
	//  if(fScintCollID<0)    fScintCollID=SDman->GetCollectionID("scintCollection");
	if(fPMTCollID<0)     fPMTCollID=SDman->GetCollectionID("pmtHitCollection");
	
	
	
	if(fRecorder)fRecorder->RecordBeginOfEvent(anEvent);
	
	((OpNoviceDigitizer*)(G4DigiManager::GetDMpointer()->FindDigitizerModule("OpNovicePMTDigitizer")))->SetDoDigi(fDoDigi);
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
	
	//get the RootIO pointer and the corresponding collections*/
	fRootIO=RootIO::GetInstance();
	fRootCollectionRaw=fRootIO->GetRootCollectionRaw();
	fRootCollectionDigi=fRootIO->GetRootCollectionDigi();
	
	//TClonesArray &mRootCollectionRaw=*fRootCollectionRaw;
	std::vector<OpNovicePMTHit*> &mRootCollectionRaw=*fRootCollectionRaw;	
	std::vector<OpNoviceDigi*> &mRootCollectionDigi=*fRootCollectionDigi;	
	mRootCollectionRaw.clear();
	mRootCollectionDigi.clear();
	
	pmtHC = 0;
	G4HCofThisEvent* hitsCE = anEvent->GetHCofThisEvent(); //hits
        //Get the hit collections
	if(hitsCE){
		if(fPMTCollID>=0) pmtHC=(OpNovicePMTHitsCollection*)(hitsCE->GetHC(fPMTCollID));
	 }	
	//hits in PMT
	if(pmtHC){
		G4int pmts=pmtHC->entries();
		//Gather info from all PMTs
		for(G4int i=0;i<pmts;i++){
			eventInformation->IncHitCount((*pmtHC)[i]->GetPheCount());
			if((*pmtHC)[i]->GetPheCount()>=fPMTThreshold){
				eventInformation->IncPMTSAboveThreshold();
			}
			else{//wasnt above the threshold, turn it back off
				(*pmtHC)[i]->SetDrawit(false);
			}
			if (fSaveRaw) mRootCollectionRaw.push_back((*pmtHC)[i]);
		}
		/*Scala di colore qui*/
		/*for(G4int i=0;i<pmts;i++){
			(*pmtHC)[i]->SetDrawScaleMax(eventInformation->GetHitCount());
		}*/
		if (G4VVisManager::GetConcreteInstance()!=0){
			pmtHC->DrawAllHits();
		}
	}
	/*Root Save*/
	if (fSaveRaw) fRootIO->FillRaw();
	
	//digi hits in PMT
	if (fDoDigi){
		pmtDigiHC = 0;
		G4DCofThisEvent* hitsDC = anEvent->GetDCofThisEvent(); //all digits
		if (fPMTDigiCollID<0){ //1: get the collection ID
			G4DigiManager* Digiman = G4DigiManager::GetDMpointer();
			fPMTDigiCollID=Digiman->GetDigiCollectionID("pmtDigiHitCollection");
		}
		if (hitsDC){ //2: Get the collection
			if(fPMTDigiCollID>=0) pmtDigiHC = (OpNoviceDigitsCollection*)(hitsDC->GetDC(fPMTCollID));
		}	
		if(pmtDigiHC){//3: Use it
			G4int pmtsdigi=pmtDigiHC->entries();
			//Gather info from all DigiPMTs
			for(G4int i=0;i<pmtsdigi;i++){
				//	G4cout<<"Digi hits "<<(*pmtDigiHC)[i]->GetEnergy()<<G4endl;
				if (fSaveDigi){
					mRootCollectionDigi.push_back((*pmtDigiHC)[i]);
				}
			}
			if (G4VVisManager::GetConcreteInstance()!=0){
				pmtDigiHC->DrawAllDigi();
			}
		}
	}
	if (fSaveDigi) fRootIO->FillDigi();
	
	
	if(fVerbose>0){
    //End of event output. later to be controlled by a verbose level
	G4cout << "\tNumber of photons that hit PMTs in this event : "
			<< eventInformation->GetHitCount() << G4endl;
	G4cout << "\tNumber of PMTs above threshold("<<fPMTThreshold<<") : "
			<< eventInformation->GetPMTSAboveThreshold() << G4endl;
	G4cout << "\tNumber of photons produced by scintillation in this event : "
			<< eventInformation->GetPhotonCount_Scint() << G4endl;
	G4cout << "\tNumber of photons produced by cerenkov in this event : "
			<< eventInformation->GetPhotonCount_Ceren() << G4endl;
	G4cout << "\tNumber of photons absorbed (OpAbsorption) in this event : "
			<< eventInformation->GetAbsorptionCount() << G4endl;
		G4cout << "\tNumber of photons absorbed at boundaries (OpBoundary) in "
			<< "this event : " << eventInformation->GetBoundaryAbsorptionCount()
			<< G4endl;
	G4cout << "Unacounted for photons in this event : "
			<< (eventInformation->GetPhotonCount_Scint() +
			    eventInformation->GetPhotonCount_Ceren() -
			    eventInformation->GetAbsorptionCount() -
			    eventInformation->GetHitCount() -
			    eventInformation->GetBoundaryAbsorptionCount())
			<< G4endl;
	}
  //If we have set the flag to save 'special' events, save here
	if(fSaveThreshold&&eventInformation->GetPhotonCount() <= fSaveThreshold)
		G4RunManager::GetRunManager()->rndmSaveThisEvent();
	
	if(fRecorder)fRecorder->RecordEndOfEvent(anEvent);
	
	
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void OpNoviceEventAction::SetSaveThreshold(G4int save){
/*Sets the save threshold for the random number seed. If the number of photons
generated in an event is lower than this, then save the seed for this event
in a file called run###evt###.rndm
*/
	fSaveThreshold=save;
	G4RunManager::GetRunManager()->SetRandomNumberStore(true);
	G4RunManager::GetRunManager()->SetRandomNumberStoreDir("random/");
  //  G4UImanager::GetUIpointer()->ApplyCommand("/random/setSavingFlag 1");
}
