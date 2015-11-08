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
//
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#ifndef OpNoviceDetectorConstruction_h
#define OpNoviceDetectorConstruction_h 1

#include "globals.hh"
#include "G4VUserDetectorConstruction.hh"

class G4LogicalVolume;
class G4VPhysicalVolume;
class G4UserLimits;
class G4Box;

#include "G4Material.hh"
#include "G4ThreeVector.hh"
#include "OpNoviceDetectorMessenger.hh"
#include "OpNovicePMTSD.hh"
#include "G4Cache.hh"
#include "G4RunManager.hh"
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

class OpNoviceDetectorConstruction : public G4VUserDetectorConstruction
{
public:
	OpNoviceDetectorConstruction();
	virtual ~OpNoviceDetectorConstruction();

public:
	virtual G4VPhysicalVolume* Construct();
	virtual void ConstructSDandField();

	//Functions to modify the geometry
	void SetDimensions(G4ThreeVector );
	void SetDefaults();
		
	inline void SetStepLimit(G4double step){fMaxStep=step;G4RunManager::GetRunManager()->ReinitializeGeometry(true);}


	//materials
	void DefineMaterials();
			
	inline void SetScintYield(G4double d){fEJ230_LY=d;G4RunManager::GetRunManager()->ReinitializeGeometry(true);}	
	inline void SetScintFastTimeConstant(G4double d){fEJ230_FastTimeConstant=d;G4RunManager::GetRunManager()->ReinitializeGeometry(true);}
	
	//Get values
	G4double GetScintX(){return fScint_x;}
	G4double GetScintY(){return fScint_y;}
	G4double GetScintZ(){return fScint_z;}
  
private:    
	//Elements
	G4Element* fH;
	G4Element* fB;
	G4Element* fC;
	G4Element* fN;
	G4Element* fO;
	G4Element* fNa;
	G4Element* fK;
	G4Element* fSi;
	G4Element* fAl;

	
	//Materials and their properties
	G4Material* fVacuum;
	G4Material* fAir;
	G4Material* fEJ230;
	
	
	G4double fEJ230_LY;
	G4double fEJ230_FastTimeConstant;
	
	G4Material* fH8500GlassWindow;
	
	
	//geometry	
	G4Box* fExperimentalHall_box;
	G4LogicalVolume* fExperimentalHall_log;
	G4VPhysicalVolume* fExperimentalHall_phys;
		
	G4LogicalVolume* H8500IntGlass_log;
	G4LogicalVolume* H8500Photo_log;
	G4VPhysicalVolume* H8500IntGlass_phys;
	G4VPhysicalVolume* H8500Photo_phys;
	
	G4double fExpHall_x;
	G4double fExpHall_y;
	G4double fExpHall_z;
	
	G4double fScint_x;
	G4double fScint_y;
	G4double fScint_z;
	
	
	G4Box* H8500_box;
	G4double fH8500box_x;
	G4double fH8500box_y;
	G4double fH8500box_z;
	
	
	G4bool fPmtPlaced;
	
	
	
	//member functions
	G4LogicalVolume* buildH8500();
	void H8500SurfaceProperties();
		
	void makeEJ230();
	
	OpNoviceDetectorMessenger*  fDetectorMessenger; 
	
	//Sensitive Detectors
	G4Cache<OpNovicePMTSD*> fPmt_SD;
	
	G4UserLimits* fStepLimit;
	G4double fMaxStep;
};

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#endif /*OpNoviceDetectorConstruction_h*/
