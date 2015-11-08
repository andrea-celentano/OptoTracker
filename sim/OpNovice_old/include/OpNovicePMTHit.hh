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
// $Id: OpNovicePMTHit.hh 72250 2013-07-12 08:59:26Z gcosmo $
//
/// \file optical/OpNovice/include/OpNovicePMTHit.hh
/// \brief Definition of the OpNovicePMTHit class
//
//
#ifndef OpNovicePMTHit_h
#define OpNovicePMTHit_h 1

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

class OpNovicePMTHit :  public G4VHit //, public TObject
{
public:    
	OpNovicePMTHit();
	virtual ~OpNovicePMTHit();
	OpNovicePMTHit(const OpNovicePMTHit &right);
	
	const OpNovicePMTHit& operator=(const OpNovicePMTHit &right);
	G4int operator==(const OpNovicePMTHit &right) const;
	
	inline void *operator new(size_t);       //! transient value not to be saved in ROOT
	inline void operator delete(void *aHit); //! transient value not to be saved in ROOT
	
	/*
	inline void *operatornew(size_t){};
	inline void operatordelete(void*){};
	*/
	virtual void Draw();
	virtual void Print();
	
	
	inline void SetDrawit(G4bool b){fDrawit=b;}
	inline G4bool GetDrawit(){return fDrawit;}
	
	inline void IncrementPhotons(){fPhotons++;}
	inline G4int GetPhotonCount(){return fPhotons;}
	
	inline void SetPMTNumber(G4int n) { fPmtNumber = n; }
	inline G4int GetPMTNumber() { return fPmtNumber; }
	
	inline void SetNPixels(G4int n){fNPixels=n;}
	inline G4int GetNPixels(){return fNPixels;}
	
	inline void SetHitData(G4double t,G4double e,G4double x,G4double y) {fEnergy.push_back(e);fTime.push_back(t);fX.push_back(x);fY.push_back(y);}
	
	inline G4double GetX(int n){return fX.at(n);};
	inline G4double GetY(int n){return fY.at(n);};
	inline G4double GetT(int n){return fTime.at(n);};
	inline G4double GetE(int n){return fEnergy.at(n);};
	
	inline G4double GetFirstHitTime(){return fFirstTime;}
	inline void SetFirstHitTime(G4double t){fFirstTime=t;}
	
	inline void SetPMTPhysVol(G4VPhysicalVolume* physVol){this->fPhysVol=physVol;}
	inline G4VPhysicalVolume* GetPMTPhysVol(){return fPhysVol;}
	
	inline void SetPMTPhysVolMother(G4VPhysicalVolume* physVol){this->fPhysVolMother=physVol;}
	inline G4VPhysicalVolume* GetPMTPhysVolMother(){return fPhysVolMother;}
		
	
	inline void  SetDrawScaleMax(G4int n){fDrawScaleMax=n;}
	inline G4int GetDrawScaleMax(){return fDrawScaleMax;}
	
	inline void  SetDrawScaleMin(G4int n){fDrawScaleMin=n;}
	inline G4int GetDrawScaleMin(){return fDrawScaleMin;}

	inline void SetName(G4String n){fName=n;}
	inline G4String GetName(){return fName;}
private:
	G4int fPmtNumber;
	G4int fPhotons;	
	G4int fNPixels;
	G4double fFirstTime;
	G4String fName;
	
	std::vector < G4double > fTime; //hit time
	std::vector < G4double > fEnergy; //hit energy (i.e. opt.photon energy)
	std::vector < G4double > fX; //hit X coordinate (0,0 is in the center)
	std::vector < G4double > fY; //hit Y coordinate (0,0 is in the center)
	
	G4VPhysicalVolume* fPhysVolMother; //! transient value not to be saved in ROOT
	G4VPhysicalVolume* fPhysVol;       //! transient value not to be saved in ROOT
	G4bool fDrawit;
	G4int fDrawScaleMin,fDrawScaleMax;
	
	//	ClassDef(OpNovicePMTHit, 1);
	
};

typedef G4THitsCollection<OpNovicePMTHit> OpNovicePMTHitsCollection;

extern G4ThreadLocal G4Allocator<OpNovicePMTHit>* OpNovicePMTHitAllocator;

inline void* OpNovicePMTHit::operator new(size_t){
	if(!OpNovicePMTHitAllocator)
		OpNovicePMTHitAllocator = new G4Allocator<OpNovicePMTHit>;
	return (void *) OpNovicePMTHitAllocator->MallocSingle();
}

inline void OpNovicePMTHit::operator delete(void *aHit){
	OpNovicePMTHitAllocator->FreeSingle((OpNovicePMTHit*) aHit);
}

#endif
