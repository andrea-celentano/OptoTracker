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
// $Id: OpNovicePMTSD.cc 73915 2013-09-17 07:32:26Z gcosmo $
//
/// \file optical/OpNovice/src/OpNovicePMTSD.cc
/// \brief Implementation of the OpNovicePMTSD class
//
//
#include "OpNovicePMTSD.hh"
#include "OpNovicePMTHit.hh"
#include "OpNoviceDigitizer.hh"
#include "OpNoviceDigi.hh"
#include "OpNoviceDetectorConstruction.hh"
#include "OpNoviceUserTrackInformation.hh"

#include "G4VPhysicalVolume.hh"
#include "G4LogicalVolume.hh"
#include "G4Track.hh"
#include "G4Step.hh"
#include "G4VTouchable.hh"
#include "G4TouchableHistory.hh"
#include "G4ios.hh"
#include "G4ParticleTypes.hh"
#include "G4ParticleDefinition.hh"
#include "G4DigiManager.hh"

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

OpNovicePMTSD::OpNovicePMTSD(G4String name)
: G4VSensitiveDetector(name),fPMTHitCollection(0),fPMTPositionsX(0),fPMTPositionsY(0),fPMTPositionsZ(0)
{
	G4cout<<"OpNovicePMTSD::creator"<<G4endl;
	collectionName.insert("pmtHitCollection");
	fDigitizer = new OpNoviceDigitizer("OpNovicePMTDigitizer");
	G4DigiManager::GetDMpointer()->AddNewModule(fDigitizer);
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

OpNovicePMTSD::~OpNovicePMTSD() {}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void OpNovicePMTSD::SetPmtPositions(const std::vector<G4ThreeVector>& positions)
{
	for (G4int i=0; i<G4int(positions.size()); ++i) {
		if(fPMTPositionsX)fPMTPositionsX->push_back(positions[i].x());
		if(fPMTPositionsY)fPMTPositionsY->push_back(positions[i].y());
		if(fPMTPositionsZ)fPMTPositionsZ->push_back(positions[i].z());
	}
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void OpNovicePMTSD::Initialize(G4HCofThisEvent* hitsCE){ //at the beginning of every EVENT!
	fPMTHitCollection = new OpNovicePMTHitsCollection(SensitiveDetectorName,collectionName[0]);
        //Store collection with event and keep ID
	static G4int hitCID = -1;
	if(hitCID<0){
		hitCID = GetCollectionID(0);
	}
	hitsCE->AddHitsCollection(hitCID,fPMTHitCollection );
	/*	
	trackerCollection = new ExN02TrackerHitsCollection
		(SensitiveDetectorName,collectionName[0]); 
	static G4int HCID = -1;
	if(HCID<0)
	{ HCID = G4SDManager::GetSDMpointer()->GetCollectionID(collectionName[0]); }
	HCE->AddHitsCollection( HCID, trackerCollection ); 
	
	static G4bool registered = false;
	if ( ! registered ) {
		G4cout << "... registering TClonesArray" << G4endl;
		Ex02RootManager::Instance()
			->Register("hits", "TClonesArray",&fRootCollection);
		registered = true;
	}   */
	
	
	
	
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

/*This function is actually called by the G4OpBoundaryProcess, that recognizes the photon is being detected.*/
/*If I attach the SD to the photocathode (post step point)*/
G4bool OpNovicePMTSD::ProcessHits(G4Step* ,G4TouchableHistory* ){
	return false;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

//Generates a hit and uses the postStepPoint's mother volume replica number
//PostStepPoint because the hit is generated manually when the photon is
//absorbed by the photocathode

G4bool OpNovicePMTSD::ProcessHits_constStep(const G4Step* aStep,G4TouchableHistory* ){

	//need to know if this is an optical photon
	if(aStep->GetTrack()->GetDefinition()!=G4OpticalPhoton::OpticalPhotonDefinition()) return false;
	G4StepPoint* postStepPoint = aStep->GetPostStepPoint();	       
	
	//we have replicas both for the pixel and for the PMT(mother volume)                                      
	G4int pmtNumber=postStepPoint->GetTouchable()->GetReplicaNumber(1);
	G4int pixelNumber=postStepPoint->GetTouchable()->GetReplicaNumber(0);
	G4VPhysicalVolume* physVol=postStepPoint->GetTouchable()->GetVolume(0);       //this is the photocathode
	G4VPhysicalVolume* physVolMother=postStepPoint->GetTouchable()->GetVolume(1); //this is the PMT box
	
	G4double hitTime=postStepPoint->GetGlobalTime();
	G4double hitTime1= aStep->GetTrack()->GetGlobalTime();
	G4double energy=aStep->GetTrack()->GetTotalEnergy();
	
	G4ThreeVector globalPosition=postStepPoint->GetPosition();
	G4ThreeVector localPosition=postStepPoint->GetTouchableHandle()->GetHistory()->GetTopTransform().TransformPoint(globalPosition);
	
	//wrt the local coordinates.
	//for reference, as seen from the photon side, the center is at (0,0) and the marker is at (-49,-49)mm, pointing toward positive X
	G4double x=localPosition.x();
	G4double y=localPosition.y();
	                        
	//G4cout<<pmtNumber<<" "<<x<<" "<<y<<" "<<physVol->GetName()<<G4endl;
	//create a new hit, always.	                                      
	G4int n=fPMTHitCollection->entries(); 
	OpNovicePMTHit* hit=NULL;
	for(G4int i=0;i<n;i++){
		if ((*fPMTHitCollection)[i]->GetPMTNumber()==pmtNumber) {
			hit=(*fPMTHitCollection)[i];
			break;
		}
	}
	
	if(hit==NULL){//this pmt wasnt previously hit in this event
		hit = new OpNovicePMTHit();   //so create new hit
		hit->SetPMTNumber(pmtNumber);		
		hit->SetPMTPhysVol(physVol); //photocathode
		hit->SetPMTPhysVolMother(physVolMother); //box around
		if (physVol->GetName()=="H8500Photocathode"){
			hit->SetName("H8500");		
		}
		fPMTHitCollection->insert(hit);
	}
	hit->IncrementPhotons();
	hit->SetHitData(hitTime,energy,x,y);
	if (hitTime < hit->GetFirstHitTime()) hit->SetFirstHitTime(hitTime);
	hit->SetDrawit(true);
	return true;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void OpNovicePMTSD::EndOfEvent(G4HCofThisEvent *hitsCE) {

	/*Here is a good place to digitize hits!*/
	//G4cout<<"OpNovicePMTSD::EndOfEvent"<<G4endl;
	
	/*Do the digitization. This creates the collection of digitized hits and stores it in the G4DCOfThisEvent*/
	fDigitizer->Digitize();
	
	
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void OpNovicePMTSD::clear() {}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void OpNovicePMTSD::DrawAll() {}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void OpNovicePMTSD::PrintAll() {}
