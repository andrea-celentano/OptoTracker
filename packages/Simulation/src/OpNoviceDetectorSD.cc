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
// $Id: OpNoviceDetectorSD.cc 73915 2013-09-17 07:32:26Z gcosmo $
//
/// \file optical/OpNovice/src/OpNoviceDetectorSD.cc
/// \brief Implementation of the OpNoviceDetectorSD class
//
//
#include "OpNoviceDetectorSD.hh"
#include "OpNoviceDetectorHit.hh"
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

OpNoviceDetectorSD::OpNoviceDetectorSD(G4String name)
: G4VSensitiveDetector(name),fDetectorHitCollection(0),fPMTPositionsX(0),fPMTPositionsY(0),fPMTPositionsZ(0)
{
	G4cout<<"OpNoviceDetectorSD::creator"<<G4endl;
	collectionName.insert("DetectorHitCollection");
	fDigitizer = new OpNoviceDigitizer("OpNoviceDetectorDigitizer");
	G4DigiManager::GetDMpointer()->AddNewModule(fDigitizer);
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

OpNoviceDetectorSD::~OpNoviceDetectorSD() {}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......


/*
void OpNoviceDetectorSD::SetPmtPositions(const std::vector<G4ThreeVector>& positions)
{
	for (G4int i=0; i<G4int(positions.size()); ++i) {
		if(fPMTPositionsX)fPMTPositionsX->push_back(positions[i].x());
		if(fPMTPositionsY)fPMTPositionsY->push_back(positions[i].y());
		if(fPMTPositionsZ)fPMTPositionsZ->push_back(positions[i].z());
	}
}*/

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void OpNoviceDetectorSD::Initialize(G4HCofThisEvent* hitsCE){ //at the beginning of every EVENT!
	fDetectorHitCollection = new OpNoviceDetectorHitsCollection(SensitiveDetectorName,collectionName[0]);
	//Store collection with event and keep ID
	static G4int hitCID = -1;
	if(hitCID<0){
		hitCID = GetCollectionID(0);
	}
	hitsCE->AddHitsCollection(hitCID,fDetectorHitCollection );
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
G4bool OpNoviceDetectorSD::ProcessHits(G4Step* aStep ,G4TouchableHistory* aHist){


	//need to know if this is an optical photon
	if(aStep->GetTrack()->GetDefinition()!=G4OpticalPhoton::OpticalPhotonDefinition()) return false;

	//Pay attention here: any particle with pre-step point in the photo-cathode will ALSO trigger this!
	//This happens, for example, if a particle is reflected by the photo-cathode.
	//Trick: look at the energy deposited. OpBoundaryProcesss, for the detection, will assign the photon energy to the photo-cathode
	if (aStep->GetTotalEnergyDeposit()<=0) return false;

	G4StepPoint* preStepPoint = aStep->GetPreStepPoint();	       	
	G4StepPoint* postStepPoint = aStep->GetPostStepPoint();	       

	//we have replicas both for the pixel,for the Detector(mother volume), and for the Face (grand-mother)

	G4int pixelNumber=postStepPoint->GetTouchable()->GetReplicaNumber(0);
	G4int detectorNumber=postStepPoint->GetTouchable()->GetReplicaNumber(1);
	G4int faceNumber=postStepPoint->GetTouchable()->GetReplicaNumber(2);



	G4VPhysicalVolume* physVol=postStepPoint->GetTouchable()->GetVolume(0);           //this is the pixel
	G4VPhysicalVolume* physVolMother=postStepPoint->GetTouchable()->GetVolume(1);     //this is the detector
	G4VPhysicalVolume* physVolGranMother=postStepPoint->GetTouchable()->GetVolume(2); //this is the face


	G4double hitTime1=postStepPoint->GetGlobalTime();
	G4double hitTime2=preStepPoint->GetGlobalTime();
	G4double energy=aStep->GetTrack()->GetTotalEnergy();

	G4ThreeVector globalPosition=postStepPoint->GetPosition();
	G4ThreeVector localPosition=postStepPoint->GetTouchableHandle()->GetHistory()->GetTopTransform().TransformPoint(globalPosition);

	//wrt the local coordinates.
	//for reference, as seen from the photon side, the center is at (0,0) and the marker is at (-,-), pointing toward positive X
	G4double x=localPosition.x();
	G4double y=localPosition.y();

	/*G4cout<<"PRE: "<<preStepPoint->GetPhysicalVolume()->GetName()<<G4endl;
	G4cout<<"POST: "<<postStepPoint->GetPhysicalVolume()->GetName()<<G4endl;
	G4cout<<"PHYS: "<<physVol->GetName()<<G4endl;
	G4cout<<"Mother:"<<physVolMother->GetName()<<G4endl;
	G4cout<<"Gran Mother:"<<physVolGranMother->GetName()<<G4endl;
	G4cout<<"hit: "<<faceNumber<<" "<<detectorNumber<<" "<<pixelNumber<<endl;
	G4cout<<"coord: "<<x<<" "<<y<<G4endl;
*/

	if ((physVol->GetName()=="H8500Photocathode")&&(preStepPoint->GetPhysicalVolume()->GetName()!=Form("H8500GlassInt_%i_%i",faceNumber,detectorNumber))){
	/*	    G4cout<<"PRE: "<<preStepPoint->GetPhysicalVolume()->GetName()<<G4endl;
			G4cout<<"POST: "<<postStepPoint->GetPhysicalVolume()->GetName()<<G4endl;
			G4cout<<"PHYS: "<<physVol->GetName()<<G4endl;
			G4cout<<"Mother:"<<physVolMother->GetName()<<G4endl;
			G4cout<<"Gran Mother:"<<physVolGranMother->GetName()<<G4endl;
			G4cout<<"hit: "<<faceNumber<<" "<<detectorNumber<<" "<<pixelNumber<<endl;
			G4cout<<"coord: "<<x<<" "<<y<<G4endl;

			G4cout<<"Correct this work-around please"<<G4endl;*/
			return false;
	}

	//create a new hit, always.	                                      
	G4int n=fDetectorHitCollection->entries();
	OpNoviceDetectorHit* hit=NULL;
	for(G4int i=0;i<n;i++){
		if ( ((*fDetectorHitCollection)[i]->GetDetectorNumber()== detectorNumber) &&  ((*fDetectorHitCollection)[i]->GetFaceNumber()== faceNumber) ) {
			hit=(*fDetectorHitCollection)[i];
			break;
		}
	}
	

	if(hit==NULL){//this pmt wasnt previously hit in this event
		hit = new OpNoviceDetectorHit();   //so create new hit
		hit->SetFaceNumber(faceNumber);
		hit->SetDetectorNumber(detectorNumber);
		hit->SetDetectorPhysVol(physVol); //photocathode
		hit->SetDetectorPhysVolMother(physVolGranMother); //box around
		if (physVol->GetName()=="H8500Photocathode"){
			hit->SetName("H8500");		

		}
		else if (physVol->GetName()=="custom"){
			hit->SetName("custom");
		}
		fDetectorHitCollection->insert(hit);
	}
	hit->IncrementNPhe();
	hit->SetHitData(hitTime1,energy,x,y,pixelNumber);

	hit->SetDrawit(true);
	return true;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void OpNoviceDetectorSD::EndOfEvent(G4HCofThisEvent *hitsCE) {

	/*Here is a good place to digitize hits!*/
	//G4cout<<"OpNoviceDetectorSD::EndOfEvent"<<G4endl;

	/*Do the digitization. This creates the collection of digitized hits and stores it in the G4DCOfThisEvent*/
	fDigitizer->Digitize();
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void OpNoviceDetectorSD::clear() {}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void OpNoviceDetectorSD::DrawAll() {}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void OpNoviceDetectorSD::PrintAll() {}
