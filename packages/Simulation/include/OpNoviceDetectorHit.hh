//
// ********************************************************************
// * License and Disclaimer
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
// $Id: OpNoviceDetectorHit.hh 72250 2013-07-12 08:59:26Z gcosmo $
//
/// \file optical/OpNovice/include/OpNoviceDetectorHit.hh
/// \brief Definition of the OpNoviceDetectorHit class
//
//
#ifndef OpNoviceDetectorHit_h
#define OpNoviceDetectorHit_h

#include "G4VHit.hh"
#include "G4THitsCollection.hh"
#include "G4Allocator.hh"
#include "G4ThreeVector.hh"
#include "G4LogicalVolume.hh"
#include "G4Transform3D.hh"
#include "G4RotationMatrix.hh"
#include "G4VPhysicalVolume.hh"

#include "TObject.h"

#include <vector>

#include "tls.hh"

class G4VTouchable;

class OpNoviceDetectorHit :  public TObject , public G4VHit
{
public:    
	OpNoviceDetectorHit();
	virtual ~OpNoviceDetectorHit();
	OpNoviceDetectorHit(const OpNoviceDetectorHit &right);
	
	const OpNoviceDetectorHit& operator=(const OpNoviceDetectorHit &right);
	G4int operator==(const OpNoviceDetectorHit &right) const;
	
	inline void *operator new(size_t);       //! transient value not to be saved in ROOT
	inline void operator delete(void *aHit); //! transient value not to be saved in ROOT
	

	virtual void Draw();
	virtual void Print();
	
	
	inline void SetDrawit(G4bool b){fDrawit=b;}
	inline G4bool GetDrawit(){return fDrawit;}
	
	inline void IncrementNPhe(){fNPhe++;}
	inline G4int GetPheCount(){return fNPhe;}
	
	inline void SetDetectorNumber(G4int n) { fDetectorNumber = n; }
	inline G4int GetDetectorNumber() { return fDetectorNumber; }

	inline void SetFaceNumber(G4int n) { fFaceNumber = n; }
	inline G4int GetFaceNumber() { return fFaceNumber; }

	inline void SetInFaceNumber(G4int n) { fInFaceNumber = n; }
	inline G4int GetInFaceNumber() { return fInFaceNumber; }

	
	inline void SetNPixels(G4int n){fNPixels=n;}
	inline G4int GetNPixels(){return fNPixels;}
	
	inline void SetHitData(G4double t,G4double e,G4double x,G4double y,G4int pixel) {fEnergy.push_back(e);fTime.push_back(t);fX.push_back(x);fY.push_back(y);fPixel.push_back(pixel);}
	
	inline G4double GetX(int n){return fX.at(n);};
	inline G4double GetY(int n){return fY.at(n);};
	inline G4double GetT(int n){return fTime.at(n);};
	inline G4double GetE(int n){return fEnergy.at(n);};
	inline G4int    GetPixel(int n){return fPixel.at(n);};
	
	
	inline void SetDetectorPhysVol(G4VPhysicalVolume* physVol){this->fPhysVol=physVol;}
	inline G4VPhysicalVolume* GetDetectorPhysVol(){return fPhysVol;}
	
	inline void SetDetectorPhysVolMother(G4VPhysicalVolume* physVol){this->fPhysVolMother=physVol;}
	inline G4VPhysicalVolume* GetDetectorPhysVolMother(){return fPhysVolMother;}
		
	
	inline void  SetDrawScaleMax(G4int n){fDrawScaleMax=n;}
	inline G4int GetDrawScaleMax(){return fDrawScaleMax;}
	
	inline void  SetDrawScaleMin(G4int n){fDrawScaleMin=n;}
	inline G4int GetDrawScaleMin(){return fDrawScaleMin;}

	inline void SetName(G4String n){fName=n;}
	inline G4String GetName(){return fName;}

	
	/*From root TObject*/
public:
	virtual void Clear(Option_t* option="");
 	virtual const char* GetName() const{return fName;}

private:
	G4int fDetectorNumber;
	G4int fFaceNumber;
	G4int fInFaceNumber;

	G4int fNPhe;	
	G4int fNPixels;
	
	G4String fName;
	
	std::vector < G4double > fTime; //hit time
	std::vector < G4double > fEnergy; //hit energy (i.e. opt.photon energy)
	std::vector < G4double > fX; //hit X coordinate (0,0 is in the center)
	std::vector < G4double > fY; //hit Y coordinate (0,0 is in the center)
	std::vector < G4double > fPixel; //hit pixel number. Cna be calculated from X,Y, but here is for simplicity!
	
	G4VPhysicalVolume* fPhysVolMother; //! transient value not to be saved in ROOT
	G4VPhysicalVolume* fPhysVol;       //! transient value not to be saved in ROOT
	G4bool fDrawit; 		   //! transient value not to be saved in ROOT
	G4int fDrawScaleMin,fDrawScaleMax; //! transient value not to be saved in ROOT
	
	ClassDef(OpNoviceDetectorHit, 1);
	
};

typedef G4THitsCollection<OpNoviceDetectorHit> OpNoviceDetectorHitsCollection;

extern G4ThreadLocal G4Allocator<OpNoviceDetectorHit>* OpNoviceDetectorHitAllocator;

inline void* OpNoviceDetectorHit::operator new(size_t){
	if(!OpNoviceDetectorHitAllocator)
		OpNoviceDetectorHitAllocator = new G4Allocator<OpNoviceDetectorHit>;
	return (void *) OpNoviceDetectorHitAllocator->MallocSingle();
}

inline void OpNoviceDetectorHit::operator delete(void *aHit){
	OpNoviceDetectorHitAllocator->FreeSingle((OpNoviceDetectorHit*) aHit);
}

#endif
