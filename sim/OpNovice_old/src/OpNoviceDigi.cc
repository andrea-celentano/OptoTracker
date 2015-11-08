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
// $Id: OpNoviceDigi.cc 82268 2014-06-13 13:47:30Z gcosmo $
// ------------------------------------------------------------
//      GEANT 4 class implementation file
//      CERN Geneva Switzerland
//
//
//      ------------ OpNoviceDigi  ------
//           by F.Longo, R.Giannitrapani & G.Santin (21 oct 2001)
//
// ************************************************************

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo.....
#include "OpNoviceDigi.hh"
#include "G4SystemOfUnits.hh"

G4ThreadLocal G4Allocator<OpNoviceDigi> *OpNoviceDigiAllocator = 0;

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

OpNoviceDigi::OpNoviceDigi()
{
	fPmtNumber=0;	
	fPhotons=0;
	fNPixels=1;	
	fName="";
}

OpNoviceDigi::OpNoviceDigi(G4String name):
fName(name)
{
	fPmtNumber=0;	
	fPhotons=0;
	fNPixels=1;	
	
	
	if (fName=="H8500"){
		fNPixels=64;
		fXmax=49.*mm;
		fYmax=49.*mm;
		
		
		
		
	}
	
}


//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

OpNoviceDigi::~OpNoviceDigi()
{;}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

OpNoviceDigi::OpNoviceDigi(const OpNoviceDigi& right)
  :G4VDigi()
{
	fPmtNumber=right.fPmtNumber;
	fPhotons=right.fPhotons;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

const OpNoviceDigi& OpNoviceDigi::operator=(const OpNoviceDigi& right)
{
	fPmtNumber=right.fPmtNumber;
	fPhotons=right.fPhotons;
	return *this;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

int OpNoviceDigi::operator==(const OpNoviceDigi& right) const
{ 
	return 0;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

void OpNoviceDigi::Draw()
{
	
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

void OpNoviceDigi::Print()
{;}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....











