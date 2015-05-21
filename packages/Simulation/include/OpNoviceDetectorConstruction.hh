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
class G4SubtractionSolid;

#include "G4Material.hh"
#include "G4ThreeVector.hh"
//#include "OpNoviceDetectorMessenger.hh"
#include "OpNovicePMTSD.hh"
#include "TOpNoviceDetectorLight.hh"

#include "G4Cache.hh"
#include "G4RunManager.hh"

class OpNovicePMTSD;
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

class OpNoviceDetectorConstruction : public G4VUserDetectorConstruction
{
public:
	OpNoviceDetectorConstruction(TOpNoviceDetectorLight *mDetectorLight);
	virtual ~OpNoviceDetectorConstruction();

public:
	virtual G4VPhysicalVolume* Construct();
	virtual void ConstructSDandField();

	static OpNoviceDetectorConstruction* GetInstance();
		
	void SetStepLimit(G4double step){fMaxStep=step;G4RunManager::GetRunManager()->ReinitializeGeometry(true);}


	//materials
	void DefineMaterials();
			
	void SetScintYield(G4double d){fEJ230_LY=d;G4RunManager::GetRunManager()->ReinitializeGeometry(true);}	
	void SetScintFastTimeConstant(G4double d){fEJ230_FastTimeConstant=d;G4RunManager::GetRunManager()->ReinitializeGeometry(true);}
	
	
	//Get values
	inline G4double GetScintX(){return fScint_x;}
	inline G4double GetScintY(){return fScint_y;}
	inline G4double GetScintZ(){return fScint_z;}
	
	inline G4double getDetSizeX(int ii){return fPhotoDetectorSizeX[ii];}
	inline G4double getDetSizeY(int ii){return fPhotoDetectorSizeY[ii];}
	
	inline G4int getNPixelsX(int ii){return fNPixelsX[ii];}
	inline G4int getNPixelsY(int ii){return fNPixelsY[ii];}
	inline G4int getNPixels(int ii){return fNPixelsX[ii]*fNPixelsY[ii];}
	
	G4bool isDetPresent(int ii);
	
	G4double GetLY(){return fEJ230_LY;}
	G4double GetScintFastTimeConstant(){return fEJ230_FastTimeConstant;}
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
	G4Material* fCoupling[6][MAX_DETECTORS];
	
	G4double fEJ230_LY;
	G4double fEJ230_FastTimeConstant;
	
	
	
	
	//geometry	
	G4Box* fExperimentalHall_box;
	G4LogicalVolume* fExperimentalHall_log;
	G4VPhysicalVolume* fExperimentalHall_phys;
	
	G4Box* fDummy_box;
	G4LogicalVolume* fDummy_log;
	G4VPhysicalVolume* fDummy_phys;
	
	
	G4Box* fFace_box[6];	
	G4Box* fMarker_box[6];	
	
	G4Box* fDetector_box[6][MAX_DETECTORS];
	G4Box* fCoupling_box[6][MAX_DETECTORS];
	
	G4Box* fPixel_box[6][MAX_DETECTORS];
	
	G4Box* fAround_box_a[6];	
	G4Box* fAround_box_b[6];	
	G4SubtractionSolid* fAround[6];	
	 
	
	G4LogicalVolume* fFace_log[6];
	G4LogicalVolume* fCoupling_log[6];
	G4LogicalVolume* fDetector_log[6];
	G4LogicalVolume* fPixel_log[6];
	G4LogicalVolume* fMarker_log[6];
	G4LogicalVolume* fAround_log[6];
	
	G4VPhysicalVolume* fAround_phys[6];
	
	G4double fExpHall_x;
	G4double fExpHall_y;
	G4double fExpHall_z;
	
	G4double fScint_x,fScint_y,fScint_z;
	G4double fPhotoDetectorSizeX[6][MAX_DETECTORS];
	G4double fPhotoDetectorSizeY[6][MAX_DETECTORS];
	G4double fPixelSizeX[6][MAX_DETECTORS];
	G4double fPixelSizeY[6][MAX_DETECTORS];
	G4double fCouplingThickness[6][MAX_DETECTORS];
	/*The reflectivity of the wrapping surface (where no photo-detectors are)*/
	G4double fWrappingR;
	
	
	
	//member functions
		
	void makeEJ230();
	
	TOpNoviceDetectorLight*  fDetectorLight; 
	
	//Sensitive Detectors
	G4Cache<OpNovicePMTSD*> fPmt_SD;
	
	G4UserLimits* fStepLimit;
	G4double fMaxStep;
	
public:	

	
	void SetDefaults();
};








//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#endif /*OpNoviceDetectorConstruction_h*/
