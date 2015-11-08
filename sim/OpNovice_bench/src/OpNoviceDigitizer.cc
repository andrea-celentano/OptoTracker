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
#include "OpNovicePMTHit.hh"

#include "G4SystemOfUnits.hh"
#include "G4EventManager.hh"
#include "G4Event.hh"
#include "G4SDManager.hh"
#include "G4DigiManager.hh"
#include "G4ios.hh"

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

OpNoviceDigitizer::OpNoviceDigitizer(G4String name)
:G4VDigitizerModule(name)
{
	G4String colName = "pmtDigiHitCollection";
	collectionName.push_back(colName);
	Energy_Threshold = 120.*keV;
	TotalEnergy = 0.;
	ACDThreshold = 15*keV;
	
//create a messenger for this class
	digiMessenger = new OpNoviceDigitizerMessenger(this);
	fDoDigi=true;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

OpNoviceDigitizer::~OpNoviceDigitizer()
{
	delete digiMessenger;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

void OpNoviceDigitizer::Digitize() // at each event
{
	if (fDoDigi){
		TotalEnergy = 0.;
		DigitsCollection = new OpNoviceDigitsCollection("OpNoviceDigitizer",collectionName[0]); //create the output Digi Collection
	
		//get the raw collection
		G4DigiManager* DigiMan = G4DigiManager::GetDMpointer();
		static G4int hitCID = -1;
		if(hitCID<0){
			hitCID = DigiMan->GetHitsCollectionID("pmtHitCollection"); 
		}	
		OpNovicePMTHitsCollection* THC = 0; 
		THC = (OpNovicePMTHitsCollection*)DigiMan->GetHitsCollection(hitCID); 
			
		if (THC)
		{
			G4int n_hit = THC->entries();  //1 "hit": 1 PMT
			for (G4int i=0;i<n_hit;i++)
			{
				OpNovicePMTHit* Hit =(*THC)[i];
				OpNoviceDigi* Digi = new OpNoviceDigi(Hit->GetName());
				
				
				
				
				Digi->SetPMTNumber(Hit->GetPMTNumber());
				Digi->SetPMTPhysVol(Hit->GetPMTPhysVol()); //photocathode
				Digi->SetPMTPhysVolMother(Hit->GetPMTPhysVolMother()); //box
				
				G4int nPhotons=Hit->GetPhotonCount();
				
				/*Here starts the real loop on the number of photons that hit the PMT*/
				for (int qq=0;qq<nPhotons;qq++){
					G4double e,t,x,y; //raw variables
					
					e=Hit->GetE(qq);
					t=Hit->GetT(qq);
					x=Hit->GetT(qq);
					y=Hit->GetT(qq);
					
					
				}
				
				//Digi->SetPixelNumber(Hit->GetPixelNumber());
				
				
				DigitsCollection->insert(Digi);	
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
	}
}
	

	
	//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....










