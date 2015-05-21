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
// $Id: OpNoviceDigitizerMessenger.cc 66508 2012-12-19 10:16:45Z gcosmo $
// ------------------------------------------------------------
//      GEANT 4 class implementation file
//      CERN Geneva Switzerland
//
//
//      ------------ OpNoviceDigitizerMessenger  ------
//           by F.Longo, G.Santin & R.Giannitrapani (27 nov 2001)
//
// ************************************************************

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

#include "OpNoviceDigitizerMessenger.hh"

#include "OpNoviceDigitizer.hh"
#include "G4SystemOfUnits.hh"
#include "G4UIcmdWithADoubleAndUnit.hh"
#include "G4UIcmdWithADouble.hh"

#include "TString.h"
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

OpNoviceDigitizerMessenger::OpNoviceDigitizerMessenger(OpNoviceDigitizer* OpNoviceDigit)
:fOpNoviceDigitizer(OpNoviceDigit)
{ 
	fDigitizerDir = new G4UIdirectory("/OpNovice/digitizer/");
	
	for (int ii=0;ii<6;ii++){
		fDetectorDir[ii]=new G4UIdirectory(Form("/OpNovice/digitizer/detector%i/",ii+1),this);
		
		
		
		fTimeResCmd[ii]=new G4UIcmdWithADoubleAndUnit(Form("/OpNovice/digitizer/detector%i/TimeResolution",ii+1),this);
		fTimeResCmd[ii]->SetGuidance("Set time resoultion");
		fTimeResCmd[ii]->SetDefaultUnit("ps");
		fTimeResCmd[ii]->AvailableForStates(G4State_PreInit,G4State_Idle);
		fTimeResCmd[ii]->SetToBeBroadcasted(false);
	}
	
	
	
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

OpNoviceDigitizerMessenger::~OpNoviceDigitizerMessenger()
{
	
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

void OpNoviceDigitizerMessenger::SetNewValue(G4UIcommand * command,G4String newValue)
{ 

	
	for (int ii=0;ii<6;ii++){
		
		if( command == fTimeResCmd[ii] ){
			fOpNoviceDigitizer->setTimeRes(ii,(fTimeResCmd[ii]->GetNewDoubleValue(newValue)));
		}
	}
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....












