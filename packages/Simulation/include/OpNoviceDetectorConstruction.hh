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
#include "G4Material.hh"
#include "G4ThreeVector.hh"

#include "G4Cache.hh"
#include "G4RunManager.hh"
#include "OpNoviceDetectorSD.hh"
#include "OpNoviceScintSD.hh"
#include "TOpNoviceDetectorLight.hh"
#include "H8500.h"


class G4LogicalVolume;
class G4VPhysicalVolume;
class G4UserLimits;
class G4Box;
class G4SubtractionSolid;
class G4OpticalSurface;
class G4LogicalSkinSurface;
class G4LogicalBorderSurface;


//#include "OpNoviceDetectorMessenger.hh"



class OpNoviceDetectorSD;
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

	void SetDefaults();
	void OverloadWithDetectorLight();

	void SetScintYield(G4double d){fEJ230_LY=d;G4RunManager::GetRunManager()->ReinitializeGeometry(true);}	
	void SetScintFastTimeConstant(G4double d){fEJ230_FastTimeConstant=d;G4RunManager::GetRunManager()->ReinitializeGeometry(true);}


	//Get values
	inline G4double GetScintX(){return fDetectorLight->getScintSizeX();}
	inline G4double GetScintY(){return fDetectorLight->getScintSizeY();}
	inline G4double GetScintZ(){return fDetectorLight->getScintSizeZ();}

	inline G4double getDetSizeX(int ii,int jj){return fDetectorLight->getDetSizeX(ii,jj);}
	inline G4double getDetSizeY(int ii,int jj){return fDetectorLight->getDetSizeY(ii,jj);}

	inline G4int getNPixelsX(int ii,int jj){return fDetectorLight->getNPixelsX(ii,jj);}
	inline G4int getNPixelsY(int ii,int jj){return fDetectorLight->getNPixelsY(ii,jj);}
	inline G4int getNPixels(int ii,int jj){return fDetectorLight->getNPixels(ii,jj);}

	inline G4int getNdet(int ii){return fDetectorLight->getNdet(ii);}

	G4bool isDetPresent(int ii,int jj){return fDetectorLight->isDetPresent(ii,jj);}


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
	G4MaterialPropertiesTable* fCouplingMT[6][MAX_DETECTORS];
	G4MaterialPropertiesTable *vacuumMT;

	G4double fEJ230_LY;
	G4double fEJ230_FastTimeConstant;




	//geometry	
	G4Box* fExperimentalHall_box;
	G4Box* fDummy_box;
	G4Box* fFace_box[6];	
	G4Box* fFaceMarker_box[6];
	G4Box* fDetectorMarker_box[6][MAX_DETECTORS];
	G4Box* fDetector_box[6][MAX_DETECTORS];
	G4Box* fCoupling_box[6][MAX_DETECTORS];
	G4Box* fPixel_box[6][MAX_DETECTORS];
	G4Box* fAround_box_a[6];	
	G4Box* fAround_box_b[6][MAX_DETECTORS];	
	G4Box* fScintillator_box;
	G4SubtractionSolid* fAround[6];	
	G4SubtractionSolid *previousSubtraction,*currentSubtraction;


	G4LogicalVolume* fFace_log[6];
	G4LogicalVolume* fFaceMarker_log[6];
	G4LogicalVolume* fAround_log[6];
	G4LogicalVolume* fCoupling_log[6][MAX_DETECTORS];
	G4LogicalVolume* fDetector_log[6][MAX_DETECTORS];
	G4LogicalVolume* fDetectorMarker_log[6][MAX_DETECTORS];
	G4LogicalVolume* fPixel_log[6][MAX_DETECTORS];
	G4LogicalVolume* fScintillator_log;
	G4LogicalVolume* fDummy_log;
	G4LogicalVolume* fExperimentalHall_log;

	G4VPhysicalVolume* fAround_phys[6];
	G4VPhysicalVolume* fDummy_phys;
	G4VPhysicalVolume* fExperimentalHall_phys;

	G4double fExpHall_x;
	G4double fExpHall_y;
	G4double fExpHall_z;

	G4double fScint_x,fScint_y,fScint_z;


	G4double fPhotoDetectorSizeX[6][MAX_DETECTORS];
	G4double fPhotoDetectorSizeY[6][MAX_DETECTORS];
	G4double fPhotoDetectorCenterX[6][MAX_DETECTORS];
	G4double fPhotoDetectorCenterY[6][MAX_DETECTORS];
	G4double fPhotoDetectorRotation[6][MAX_DETECTORS];

	G4double fPixelSizeX[6][MAX_DETECTORS];
	G4double fPixelSizeY[6][MAX_DETECTORS];

	G4int fNPixelsX[6][MAX_DETECTORS];
	G4int fNPixelsY[6][MAX_DETECTORS];


	G4double fPhotoReflectivity[6][MAX_DETECTORS];
	G4double fPhotoQE[6][MAX_DETECTORS];

	G4Transform3D transformDet[6][MAX_DETECTORS];
	G4Transform3D transformCoupling[6][MAX_DETECTORS];
	G4Transform3D transformAround[6][MAX_DETECTORS];
	G4RotationMatrix rotDet[6][MAX_DETECTORS];
	G4ThreeVector translDet[6][MAX_DETECTORS];
	G4ThreeVector translCoupling[6][MAX_DETECTORS];
	G4ThreeVector translAround[6][MAX_DETECTORS];

	G4double faceThickness,detectorThickness,pixelThickness,aroundThickness;

	/*The reflectivity of the wrapping surfaces*/
	G4double fFaceReflectivity[6];

	/*The coupling*/
	G4double fCouplingThickness[6][MAX_DETECTORS];
	G4double fCouplingN[6][MAX_DETECTORS];

	/*Optical surfaces*/
	G4OpticalSurface* fDetectorOpsurf[6][MAX_DETECTORS];
	G4MaterialPropertiesTable* fDetectorOpsurfMT[6][MAX_DETECTORS];
	G4LogicalSkinSurface* fDetectorSkin[6][MAX_DETECTORS];

	G4OpticalSurface* fFaceOpsurf[6];
	G4MaterialPropertiesTable* fFaceOpsurfMT[6];
	G4LogicalBorderSurface* fFaceBorder[6];

	//member functions

	void makeEJ230();
	G4LogicalVolume* buildH8500(int iface,int idetector);
	void makeH8500materials();
	//for the H8500
	G4double fH8500box_x,fH8500box_y,fH8500box_z;
	G4Box* fH8500_box;
	G4Box* fH8500IntGlass_box;
	G4Box* fH8500Photo_box;
	G4Material* fH8500GlassWindow;
	G4LogicalVolume* fH8500IntGlass_log;
	G4LogicalVolume* fH8500Photo_log;
	G4VPhysicalVolume* fH8500IntGlass_phys;
	G4VPhysicalVolume* fH8500Photo_phys;

	TOpNoviceDetectorLight*  fDetectorLight; 

	//Sensitive Detectors
	G4Cache<OpNoviceDetectorSD*> fDetectorSD;
	G4Cache<OpNoviceScintSD*> fScintSD;

	G4UserLimits* fStepLimit;
	G4double fMaxStep;

	G4bool fPmtPlaced;


};








//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#endif /*OpNoviceDetectorConstruction_h*/
