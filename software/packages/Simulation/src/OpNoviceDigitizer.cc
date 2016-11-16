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
//
// $Id: OpNoviceDigitizer.cc 66508 2012-12-19 10:16:45Z gcosmo $
// ------------------------------------------------------------
//      GEANT 4 class implementation file
//      CERN Geneva Switzerland
//
//
//      ------------ OpNoviceDigitizer  ------
//           by   F.Longo, R.Giannitrapani & G.Santin (13 nov 2000)
//
// ************************************************************

#include <vector>

#include "OpNoviceDigitizer.hh"
#include "OpNoviceDigi.hh"
#include "OpNoviceDigitizerMessenger.hh"

/*Here goes the input collections*/
#include "OpNoviceDetectorHit.hh"

#include "G4SystemOfUnits.hh"
#include "G4EventManager.hh"
#include "G4Event.hh"
#include "G4SDManager.hh"
#include "G4DigiManager.hh"
#include "G4ios.hh"

#include "OpNoviceDetectorConstruction.hh"

#include "CLHEP/Random/RandGauss.h"
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

OpNoviceDigitizer::OpNoviceDigitizer(G4String name)
:G4VDigitizerModule(name)
{
	G4String colName = "DetectorDigiHitCollection";
	collectionName.push_back(colName);


	//create a messenger for this class
	digiMessenger = new OpNoviceDigitizerMessenger(this);
	fDoDigi=true;

	fDetector=OpNoviceDetectorConstruction::GetInstance();

}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

OpNoviceDigitizer::~OpNoviceDigitizer()
{
	delete digiMessenger;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

void OpNoviceDigitizer::Digitize() // at each event
{

	G4String name;
	G4int nPhe;
	G4int ix,iy;
	G4double e,t,x,y,n; 
	G4double dx,dy;
	G4int pixelNumber,detectorNumber,kk;
	G4int faceNumber,uniqueNumber;
	OpNoviceDetectorHit* Hit;
	OpNoviceDigi* Digi ;

	if (fDoDigi){
		//create the output Digi Collection
		DigitsCollection = new OpNoviceDigitsCollection("OpNoviceDigitizer",collectionName[0]);
		//init all the digits at 0
		for (int ii=0;ii<6;ii++){
			for (int jj=0;jj<fDetector->getNdet(ii);jj++){
				if (fDetector->isDetPresent(ii,jj)==false) continue;
				for (int id=0;id<fDetector->getNPixels(ii,jj);id++){
					Digi = new OpNoviceDigi("");
					Digi->SetFaceNumber(ii);
					Digi->SetDetectorNumber(jj);
					Digi->SetPixelNumber(id);
					DigitsCollection->insert(Digi);
				}
			}
		}

		//get the raw collection
		G4DigiManager* DigiMan = G4DigiManager::GetDMpointer();
		static G4int hitCID = -1;
		if(hitCID<0){
			hitCID = DigiMan->GetHitsCollectionID("DetectorHitCollection");
		}	
		OpNoviceDetectorHitsCollection* THC = 0;
		THC = (OpNoviceDetectorHitsCollection*)DigiMan->GetHitsCollection(hitCID);

		if (THC){
			for (G4int ii=0;ii<THC->entries();ii++){ //1 "hit": 1 detector
				Hit =(*THC)[ii];				
				nPhe=Hit->GetPheCount();
				detectorNumber=Hit->GetDetectorNumber();
				faceNumber=Hit->GetFaceNumber();
				uniqueNumber=Hit->GetInFaceNumber();
				name=Hit->GetName();



				for (int qq=0;qq<nPhe;qq++){				

					e=Hit->GetE(qq);
					t=Hit->GetT(qq);
					x=Hit->GetX(qq);
					y=Hit->GetY(qq);	

					/*Here is the "proper" part for the digitization.
					 * In the custom case, the detector is already divided in pixels. The pixelNumber is already set
					 */
					if (name=="custom"){
						pixelNumber=Hit->GetPixel(qq);
					}
					/*
					 * In the H8500 case, there is only one "pixel", i.e. the SINGLE photocathode
					 * In this case, x and y are the hit position on the photocathode itself.
					 */
					else if (name=="H8500"){
						 dx=H8500ACTIVESIZE*cm/H8500NPIXELSX;
						 dy=H8500ACTIVESIZE*cm/H8500NPIXELSY;
						 ix=(x+H8500ACTIVESIZE*cm/2.)/dx;
						 iy=(y+H8500ACTIVESIZE*cm/2.)/dy;
						 pixelNumber=ix+iy*H8500NPIXELSX;
					}

					/*The time resolution*/
					t=t+CLHEP::RandGauss::shoot(0,detTimeRes[detectorNumber]);
					Digi=NULL;
					/*Check if this digi hit already exists. It should, we created all of them!*/
					n=DigitsCollection->entries();
					for(G4int jj=0;jj<n;jj++){
						if ( ((*DigitsCollection)[jj]->GetFaceNumber()==faceNumber) && ((*DigitsCollection)[jj]->GetDetectorNumber()==detectorNumber) && ((*DigitsCollection)[jj]->GetPixelNumber()==pixelNumber)  ) {
							Digi=(*DigitsCollection)[jj];
							Digi->IncrementPheCount();
							if ( t < Digi->GetFirstHitTime() ) Digi->SetFirstHitTime(t);
							break;
						}
					}
					if(Digi==NULL){
						G4cout<<"Probable_error in OpNoviceDigitizer: digi not found "<<detectorNumber<<" "<<pixelNumber<<endl;
						G4cout<<"Hit face,det,pixel X-Y (cm) is: "<<faceNumber<<" "<<detectorNumber<<" "<<pixelNumber<<" "<<x/cm<<" "<<y/cm<<endl;
					}


				}
			}
		}

		if (THC){
			G4cout << "Number of digits in this event =  " 
					<< DigitsCollection->entries()
					// << " " << DigitsCollection->GetName()
					// << " " << DigitsCollection->GetDMname()
					<< G4endl;
		}
		StoreDigiCollection(DigitsCollection); //This is also storing the collection in the DCoFThisEvent
	/*G4cout<<"*********************************************************************************"<<G4endl;
		G4cout<<G4endl<<G4endl<<G4endl;*/
	}
}



//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....










