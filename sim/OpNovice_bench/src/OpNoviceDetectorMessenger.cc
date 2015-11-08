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
//
#include "OpNoviceDetectorMessenger.hh"
#include "OpNoviceDetectorConstruction.hh"

#include "G4UIcmdWithADoubleAndUnit.hh"
#include "G4UIcmdWith3VectorAndUnit.hh"
#include "G4UIcmdWithAnInteger.hh"
#include "G4UIcommand.hh"
#include "G4UIdirectory.hh"
#include "G4UIcmdWithABool.hh"
#include "G4UIcmdWithADouble.hh"
#include "G4Scintillation.hh"
#include "G4SystemOfUnits.hh"

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

OpNoviceDetectorMessenger::OpNoviceDetectorMessenger(OpNoviceDetectorConstruction* detector)
: fOpNoviceDetector(detector)
{
  //Setup a command directory for detector controls with guidance
	fDetectorDir = new G4UIdirectory("/OpNovice/detector/");
	fDetectorDir->SetGuidance("Detector geometry control");
	
	fVolumesDir = new G4UIdirectory("/OpNovice/detector/volumes/");
	fVolumesDir->SetGuidance("Enable/disable volumes");
	
  //Various commands for modifying detector geometry
	fDimensionsCmd =
		new G4UIcmdWith3VectorAndUnit("/OpNovice/detector/dimensions",this);
	fDimensionsCmd->SetGuidance("Set the dimensions of the detector volume.");
	fDimensionsCmd->SetParameterName("scint_x","scint_y","scint_z",false);
	fDimensionsCmd->SetDefaultUnit("cm");
	fDimensionsCmd->AvailableForStates(G4State_PreInit,G4State_Idle);
	fDimensionsCmd->SetToBeBroadcasted(false);
	
	
	fScintYield=new G4UIcmdWithADouble("/OpNovice/detector/ScintYield",this);
	fScintYield->SetGuidance("Set scinitillation yield of scintillator");
	fScintYield->SetGuidance("Specified in photons/MeV");
	fScintYield->AvailableForStates(G4State_PreInit,G4State_Idle);
	fScintYield->SetToBeBroadcasted(false);
	
	fScintFastDecayTime=new G4UIcmdWithADouble("/OpNovice/detector/ScintFastDecayTime",this);
	fScintFastDecayTime->SetGuidance("Set fast decay time of scintillator");
	fScintFastDecayTime->SetGuidance("Specified in ns");
	fScintFastDecayTime->AvailableForStates(G4State_PreInit,G4State_Idle);
	fScintFastDecayTime->SetToBeBroadcasted(false);
		
	
	fReflectivityCmd = new G4UIcmdWithADouble("/OpNovice/detector/reflectivity",this);
	fReflectivityCmd->SetGuidance("Set the reflectivity of the housing.");
	fReflectivityCmd->AvailableForStates(G4State_PreInit,G4State_Idle);
	fReflectivityCmd->SetToBeBroadcasted(false);

	
	fStepLimitCmd = new G4UIcmdWithADoubleAndUnit("/OpNovice/detector/stepLimit",this);
	fStepLimitCmd->SetGuidance("Set the step limit in the scintillator.");
	fStepLimitCmd->SetDefaultUnit("cm");
	fStepLimitCmd->AvailableForStates(G4State_PreInit,G4State_Idle);
	fStepLimitCmd->SetToBeBroadcasted(false);
	
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

OpNoviceDetectorMessenger::~OpNoviceDetectorMessenger()
{
	delete fDimensionsCmd;
	delete fScintYield;
	delete fScintFastDecayTime;
	delete fReflectivityCmd;
	delete fStepLimitCmd;
	
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void OpNoviceDetectorMessenger::SetNewValue(G4UIcommand* command, G4String newValue)
{
	if( command == fDimensionsCmd ){
		fOpNoviceDetector->SetDimensions(fDimensionsCmd->GetNew3VectorValue(newValue));
	}
	else if (command == fScintYield){
		fOpNoviceDetector->SetScintYield((fScintYield->GetNewDoubleValue(newValue))/MeV);
	}
	else if (command == fScintFastDecayTime){
		fOpNoviceDetector->SetScintFastTimeConstant(fScintFastDecayTime->GetNewDoubleValue(newValue));
	}
	else if (command == fStepLimitCmd){
		fOpNoviceDetector->SetStepLimit(fStepLimitCmd->GetNewDoubleValue(newValue));
	}
	/*else if (command == fHousingThicknessCmd){
		fOpNoviceDetector->SetHousingThickness(fHousingThicknessCmd
		                                  ->GetNewDoubleValue(newValue));
	}
	else if (command == fPmtRadiusCmd){
		fOpNoviceDetector->SetPMTRadius(fPmtRadiusCmd->GetNewDoubleValue(newValue));
	}
	else if (command == fNxCmd){
		fOpNoviceDetector->SetNX(fNxCmd->GetNewIntValue(newValue));
	}
	else if (command == fNyCmd){
		fOpNoviceDetector->SetNY(fNyCmd->GetNewIntValue(newValue));
	}
	else if (command == fNzCmd){
		fOpNoviceDetector->SetNZ(fNzCmd->GetNewIntValue(newValue));
	}
	else if (command == fDefaultsCmd){
		fOpNoviceDetector->SetDefaults();
	}
	else if (command == fSphereCmd){
		fOpNoviceDetector->SetSphereOn(fSphereCmd->GetNewBoolValue(newValue));
	}
	else if (command == fReflectivityCmd){
		fOpNoviceDetector
			->SetHousingReflectivity(fReflectivityCmd->GetNewDoubleValue(newValue));
	}
	else if (command == fWlsCmd){
		fOpNoviceDetector->SetWLSSlabOn(fWlsCmd->GetNewBoolValue(newValue));
	}
	else if (command == fOpNoviceCmd){
		fOpNoviceDetector->SetMainVolumeOn(fOpNoviceCmd->GetNewBoolValue(newValue));
	}
	else if (command == fNFibersCmd){
		fOpNoviceDetector->SetNFibers(fNFibersCmd->GetNewIntValue(newValue));
	}
	else if (command == fMainScintYield){
		fOpNoviceDetector->SetMainScintYield(fMainScintYield->GetNewDoubleValue(newValue));
	}
	else if (command == fWLSScintYield){
		fOpNoviceDetector->SetWLSScintYield(fWLSScintYield->GetNewDoubleValue(newValue));
	}*/
}
