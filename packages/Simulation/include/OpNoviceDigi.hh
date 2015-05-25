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
// $Id: OpNoviceDigi.hh 82268 2014-06-13 13:47:30Z gcosmo $
// ------------------------------------------------------------
//      GEANT 4 class header file
//      CERN Geneva Switzerland
//
//
//      ------------ OpNoviceDigi  ------
//           by F.Longo, R.Giannitrapani & G.Santin (24 oct 2001)
//
// ************************************************************
// This Class describe the digits 

#ifndef OpNoviceDigi_h
#define OpNoviceDigi_h 1

#include "G4VDigi.hh"
#include "G4TDigiCollection.hh"
#include "G4Allocator.hh"
#include "G4ThreeVector.hh"
#include "G4RotationMatrix.hh"
#include "G4LogicalVolume.hh"
#include "G4Transform3D.hh"
#include "G4VPhysicalVolume.hh"

#include <vector>
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

class OpNoviceDigi : public G4VDigi
{

public:
  
  OpNoviceDigi();
  OpNoviceDigi(G4String name);
  ~OpNoviceDigi();
  OpNoviceDigi(const OpNoviceDigi&);
  const OpNoviceDigi& operator=(const OpNoviceDigi&);
  int operator==(const OpNoviceDigi&) const;
  
  inline void* operator new(size_t);
  inline void  operator delete(void*);
  
  void Draw();
  void Print();

private:
	

	/*identifiers*/
	G4int fDetectorNumber,fPixelNumber,fFaceNumber,fUniqueNumber;
	G4String fName;
	
	/*Semi-raw variables*/
	G4int fNPhe;	 //total phe
	G4double fFirstHitTime;

	
	
	
	G4VPhysicalVolume* fPhysVolMother; //! transient value not to be saved in ROOT
	G4VPhysicalVolume* fPhysVol;       //! transient value not to be saved in ROOT


public:
	
	inline void SetDetectorNumber(G4int n) { fDetectorNumber = n; }
	inline G4int GetDetectorNumber() { return fDetectorNumber; }

	inline void SetFaceNumber(G4int n) { fFaceNumber = n; }
	inline G4int GetFaceNumber() { return fFaceNumber; }

	inline void SetUniqueNumber(G4int n) { fUniqueNumber = n; }
	inline G4int GetUniqueNumber() { return fUniqueNumber; }




	inline void SetPixelNumber(G4int n) { fPixelNumber = n; }
	inline G4int GetPixelNumber() { return fPixelNumber; }
	
	inline void SetFirstHitTime(G4double t) { fFirstHitTime = t; }
	inline G4int GetFirstHitTime() { return fFirstHitTime; }
	
	inline void SetPheCount(G4int n){fNPhe=n;}
	inline void IncrementPheCount(){fNPhe++;}
	inline G4int GetPheCount(){return fNPhe;}
  
	
	inline void SetPMTPhysVol(G4VPhysicalVolume* physVol){this->fPhysVol=physVol;}
	inline G4VPhysicalVolume* GetPMTPhysVol(){return fPhysVol;}
	
	inline void SetPMTPhysVolMother(G4VPhysicalVolume* physVol){this->fPhysVolMother=physVol;}
	inline G4VPhysicalVolume* GetPMTPhysVolMother(){return fPhysVolMother;}

	
	
};

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

typedef G4TDigiCollection<OpNoviceDigi> OpNoviceDigitsCollection;

extern G4ThreadLocal G4Allocator<OpNoviceDigi> *OpNoviceDigiAllocator;

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

inline void* OpNoviceDigi::operator new(size_t)
{
  if (!OpNoviceDigiAllocator)
    OpNoviceDigiAllocator = new G4Allocator<OpNoviceDigi>;
  return (void*) OpNoviceDigiAllocator->MallocSingle();
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

inline void OpNoviceDigi::operator delete(void* aDigi)
{
  OpNoviceDigiAllocator->FreeSingle((OpNoviceDigi*) aDigi);
}

#endif









