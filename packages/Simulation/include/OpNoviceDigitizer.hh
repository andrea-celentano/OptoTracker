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
// $Id: OpNoviceDigitizer.hh 66508 2012-12-19 10:16:45Z gcosmo $
// ------------------------------------------------------------
//      GEANT 4 class header file
//      CERN Geneva Switzerland
//
//
//      ------------ OpNoviceDigitizer ------
//
//           by F.Longo, R.Giannitrapani & G.Santin (24 oct 2001)
//
// ************************************************************

#ifndef OpNoviceDigitizer_h
#define OpNoviceDigitizer_h 1


#include "globals.hh"

#include "G4VDigitizerModule.hh"
#include "OpNoviceDigi.hh"
#include "OpNoviceDetectorConstruction.hh"
//#include "g4std/vector"

class OpNoviceDigitizerMessenger;

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

class OpNoviceDigitizer : public G4VDigitizerModule
{
public:

	OpNoviceDigitizer(G4String name);
	~OpNoviceDigitizer();
	
	void Digitize();
	
	
	inline void SetDoDigi(G4bool b){fDoDigi=b;}
private:

	OpNoviceDigitsCollection*  DigitsCollection;
	OpNoviceDigitizerMessenger* digiMessenger;
     
	
	int detNpixelsX[6];
	int detNpixelsY[6];
	double detSizeX[6];
	double detSizeY[6];
	double detPixelSizeX[6];
	double detPixelSizeY[6];
	double detTimeRes[6];
	G4bool fDoDigi;
	
	OpNoviceDetectorConstruction *fDetector;
	
	
public:	
	inline void setNPixelsX(int i,int N){detNpixelsX[i]=N;}
	inline void setNPixelsY(int i,int N){detNpixelsY[i]=N;}
	inline int getNPixelsX(int i){return detNpixelsX[i];}
	inline int getNPixelsY(int i){return detNpixelsY[i];}
	inline void setTimeRes(int iface,double t){detTimeRes[iface]=t;}
	inline double getTimeRes(int iface){return detTimeRes[iface];}
	
	
	
	
	
};

#endif








