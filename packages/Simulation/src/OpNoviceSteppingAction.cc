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
// $Id: OpNoviceSteppingAction.cc 71007 2013-06-09 16:14:59Z maire $
//
/// \file OpNoviceSteppingAction.cc
/// \brief Implementation of the OpNoviceSteppingAction class

#include "OpNoviceSteppingAction.hh"

#include "G4Step.hh"
#include "G4Track.hh"
#include "G4OpticalPhoton.hh"

#include "G4RunManager.hh"
#include "G4SteppingManager.hh"
#include "G4SDManager.hh"
#include "G4EventManager.hh"
#include "G4ProcessManager.hh"
#include "G4Track.hh"
#include "G4Step.hh"
#include "G4Event.hh"
#include "G4StepPoint.hh"
#include "G4TrackStatus.hh"
#include "G4VPhysicalVolume.hh"
#include "G4ParticleDefinition.hh"
#include "G4ParticleTypes.hh"
#include "G4SystemOfUnits.hh"
#include "G4PhysicalConstants.hh"


#include "RootIO.hh"
#include "TMCTruth.hh"
#include "OpNoviceDetectorSD.hh"
#include "OpNoviceUserTrackInformation.hh"
#include "OpNoviceUserEventInformation.hh"
#include "OpNoviceRecorderBase.hh"

#include "TLorentzVector.h"
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......


OpNoviceSteppingAction::OpNoviceSteppingAction(OpNoviceRecorderBase* r)
: G4UserSteppingAction(),fRecorder(r)
{ 
	fScintillationCounter = 0;
	fCerenkovCounter      = 0;
	fEventNumber = -1;

	fAbsorbed=fReflected=fRefracted=0;

	G4cout<<"OpNoviceSteppingAction::creator "<<G4endl;

	fRootIO=RootIO::GetInstance();
	fMCTruth=0;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

OpNoviceSteppingAction::~OpNoviceSteppingAction()
{ 
	G4cout<<fAbsorbed<<" "<<fReflected<<" "<<fRefracted<<G4endl;


}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......


void  OpNoviceSteppingAction::UserSteppingAction(const G4Step * theStep){

	G4Track* theTrack = theStep->GetTrack();

	OpNoviceUserTrackInformation* trackInformation=(OpNoviceUserTrackInformation*)theTrack->GetUserInformation();
	OpNoviceUserEventInformation* eventInformation=(OpNoviceUserEventInformation*)G4EventManager::GetEventManager()->GetConstCurrentEvent()->GetUserInformation();

	G4StepPoint* thePrePoint = theStep->GetPreStepPoint();
	G4VPhysicalVolume* thePrePV = thePrePoint->GetPhysicalVolume();

	G4StepPoint* thePostPoint = theStep->GetPostStepPoint();
	G4VPhysicalVolume* thePostPV = thePostPoint->GetPhysicalVolume();

	G4OpBoundaryProcessStatus boundaryStatus=Undefined;
	static G4ThreadLocal G4OpBoundaryProcess* boundary=NULL;

	if ( theTrack->GetCurrentStepNumber() == 1 ){
		fExpectedNextStatus = Undefined;
	}

	if (theTrack->GetParentID() == 0){ //first step of primary track
		if ( theTrack->GetCurrentStepNumber() == 1 ){
			fMCTruth=(TMCTruth *)(fRootIO->GetEvent()->getObject("MCTruth"));
			if (!fMCTruth){
				G4ExceptionDescription ed;
				ed << "OpNoviceSteppingAction::UserSteppingAction(): "
						<< "No MCTruth object in the event"	<< G4endl;
				G4Exception("OpNoviceSteppingAction::UserSteppingAction()", "OpNovice",
						FatalException,ed,
						"Something is wrong with the fMCTruth");
			}
			fMCTruth->setPid(theTrack->GetParticleDefinition()->GetPDGEncoding());
			fMCTruth->setX0(new TLorentzVector(thePrePoint->GetPosition().x(),thePrePoint->GetPosition().y(),thePrePoint->GetPosition().z(),thePrePoint->GetGlobalTime()));
			fMCTruth->setP0(new TLorentzVector(theTrack->GetMomentum().x(),theTrack->GetMomentum().y(),theTrack->GetMomentum().z(),theTrack->GetTotalEnergy()));
		}
		else if (!thePostPV){
			fExpectedNextStatus=Undefined;
			return;
		}
		else if((thePostPoint->GetPhysicalVolume()->GetName()=="Scintillator")&&(thePrePoint->GetStepStatus()==fGeomBoundary)&&(thePrePoint->GetPhysicalVolume()->GetName()!="Scintillator")){ //entering
      			fMCTruth->setXin(new TLorentzVector(thePrePoint->GetPosition().x(),thePrePoint->GetPosition().y(),thePrePoint->GetPosition().z(),thePrePoint->GetGlobalTime()));
		}
		else if((thePrePoint->GetPhysicalVolume()->GetName()=="Scintillator")&&(thePostPoint->GetStepStatus()==fGeomBoundary)&&((thePostPoint->GetPhysicalVolume()->GetName()!="Scintillator"))){ //exiting
			fMCTruth->setXout(new TLorentzVector(thePostPoint->GetPosition().x(),thePostPoint->GetPosition().y(),thePostPoint->GetPosition().z(),thePostPoint->GetGlobalTime()));
		}
	}




	//find the boundary process only once
	if(!boundary){
		G4ProcessManager* pm = theStep->GetTrack()->GetDefinition()->GetProcessManager();
		G4int nprocesses = pm->GetProcessListLength();
		G4ProcessVector* pv = pm->GetProcessList();
		G4int i;
		for( i=0;i<nprocesses;i++){
			if((*pv)[i]->GetProcessName()=="OpBoundary"){
				boundary = (G4OpBoundaryProcess*)(*pv)[i];
				break;
			}
		}
	}


	if(!thePostPV){//out of world
		fExpectedNextStatus=Undefined;
		return;
	}

	G4ParticleDefinition* particleType = theTrack->GetDefinition();
	if(particleType==G4OpticalPhoton::OpticalPhotonDefinition() ) {

		//if (theStep->IsFirstStepInVolume()){
		//	G4cout<<theStep->GetPreStepPoint()->GetPosition()<<G4endl;

		if ( theTrack->GetCurrentStepNumber() == 1 ){ //first step

			fRootIO->fillHistogram1D(0,thePrePoint->GetPosition().y()/cm,1.);
			fRootIO->fillHistogram2D(0,thePrePoint->GetPosition().x()/cm,thePrePoint->GetPosition().y()/cm,1.);
			fRootIO->fillHistogram2D(1,thePrePoint->GetPosition().z()/cm,thePrePoint->GetPosition().y()/cm,1.);
			fRootIO->fillHistogram2D(2,thePrePoint->GetPosition().x()/cm,thePrePoint->GetPosition().z()/cm,1.);
		}
		//Optical photon only
		//Was the photon absorbed by the absorption process
		if(thePostPoint->GetProcessDefinedStep()->GetProcessName()=="OpAbsorption"){
			eventInformation->IncAbsorption();
			trackInformation->AddTrackStatusFlag(absorbed);
		}
		boundaryStatus=boundary->GetStatus();
		//Check to see if the partcile was actually at a boundary
		//Otherwise the boundary status may not be valid
		//Prior to Geant4.6.0-p1 this would not have been enough to check
		if(thePostPoint->GetStepStatus()==fGeomBoundary){
			if(fExpectedNextStatus==StepTooSmall){
				if(boundaryStatus!=StepTooSmall){
					G4cout<<theStep->GetPreStepPoint()->GetPhysicalVolume()->GetName()<<G4endl;
					G4cout<<theStep->GetPostStepPoint()->GetPhysicalVolume()->GetName()<<G4endl;

					G4ExceptionDescription ed;
					ed << "OpNoviceSteppingAction::UserSteppingAction(): "
							<< "No reallocation step after reflection!"
							<< G4endl;
					G4Exception("OpNoviceSteppingAction::UserSteppingAction()", "OpNovice",
							FatalException,ed,
							"Something is wrong with the surface normal or geometry");
				}
			}
			fExpectedNextStatus=Undefined;
			switch(boundaryStatus){
			case Absorption:
				//G4cout<<"Absorption"<<G4endl;
				trackInformation->AddTrackStatusFlag(boundaryAbsorbed);
				eventInformation->IncBoundaryAbsorption();
				fAbsorbed++;
				break;
			case Detection: 
			{

				/*The PostPoint is in the PIXEL
					thePostPoint->GetTouchable->GetVolume(1) is the "detector", i.e. the pixels assembly
					thePostPoint->GetTouchable->GetVolume(2) is the "face"
				 */

				/*  thePrePoint is in the coupling
					thePostPoint->GetTouchable->GetVolume(1) is the "face"
				 */
				eventInformation->IncDetection();

				G4int pmtNumber=thePostPoint->GetTouchable()->GetReplicaNumber(1);

				G4ThreeVector globalPosition=thePrePoint->GetPosition();
				G4ThreeVector localPosition=thePrePoint->GetTouchableHandle()->GetHistory()->GetTopTransform().TransformPoint(globalPosition);




				fRootIO->fillHistogram2D(pmtNumber+3,localPosition.x()/cm,localPosition.y()/cm,1.);

				/*
				G4SDManager* SDman = G4SDManager::GetSDMpointer();
				G4String sdName="/OpNoviceDet/DetectorSD";
				OpNoviceDetectorSD* DetectorSD = (OpNoviceDetectorSD*)SDman->FindSensitiveDetector(sdName);
				if(DetectorSD)DetectorSD->ProcessHits_constStep(theStep,NULL);
				 */
				trackInformation->AddTrackStatusFlag(hitPMT);
				fAbsorbed++;


				break;
			}
			case FresnelReflection:
			case TotalInternalReflection:
			case LambertianReflection:
			case LobeReflection:
			case SpikeReflection:
			case BackScattering:

				trackInformation->IncReflections();
				fExpectedNextStatus=StepTooSmall;
				fReflected++;
				//theStep->GetTrack()->SetTrackStatus(fStopAndKill);
				break;
			case FresnelRefraction:
				trackInformation->IncRefractions();
				fRefracted++;

				break;
			default:
				break;
			}
		}
	}

	if(fRecorder)fRecorder->RecordStep(theStep);
}

