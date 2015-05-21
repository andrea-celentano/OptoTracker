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
// $Id: OpNoviceEventMessenger.cc 70256 2013-05-28 07:29:30Z gcosmo $
//
/// \file optical/OpNovice/src/OpNoviceEventMessenger.cc
/// \brief Implementation of the OpNoviceEventMessenger class
//
//
#include "OpNoviceMessenger.hh"
#include "OpNoviceEventAction.hh"
#include "OpNoviceRunAction.hh"

#include "G4UIcmdWithABool.hh"
#include "G4UIcmdWithAnInteger.hh"
#include "G4UIcmdWithAString.hh"

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
static OpNoviceMessenger* messenger = 0;

OpNoviceMessenger::OpNoviceMessenger()
{
	
	fRunDir=new G4UIdirectory("/OpNovice/run/");
	fRunDir->SetGuidance("Run control");
	
	fSaveThresholdCmd = new G4UIcmdWithAnInteger("/OpNovice/saveThreshold",this);
	fSaveThresholdCmd->SetGuidance("Set the photon count threshold for saving the random number seed");
	fSaveThresholdCmd->SetParameterName("photons",true);
	fSaveThresholdCmd->SetDefaultValue(4500);
	fSaveThresholdCmd->AvailableForStates(G4State_PreInit,G4State_Idle);
	
	fVerboseCmd = new G4UIcmdWithAnInteger("/OpNovice/eventVerbose",this);
	fVerboseCmd->SetGuidance("Set the verbosity of event data.");
	fVerboseCmd->SetParameterName("verbose",true);
	fVerboseCmd->SetDefaultValue(1);
	
	fPmtThresholdCmd = new G4UIcmdWithAnInteger("/OpNovice/pmtThreshold",this);
	fPmtThresholdCmd->SetGuidance("Set the pmtThreshold (in # of photons)");
	
	fForceDrawPhotonsCmd=new G4UIcmdWithABool("/OpNovice/forceDrawPhotons",this);
	fForceDrawPhotonsCmd->SetGuidance("Force drawing of photons.");
	fForceDrawPhotonsCmd->SetGuidance("(Higher priority than /OpNovice/forceDrawNoPhotons)");
	
	fForceDrawNoPhotonsCmd=new G4UIcmdWithABool("/OpNovice/forceDrawNoPhotons",this);
	fForceDrawNoPhotonsCmd->SetGuidance("Force no drawing of photons.");
	fForceDrawNoPhotonsCmd->SetGuidance("(Lower priority than /OpNovice/forceDrawPhotons)");
	
	/*Run control commands*/
	
	fSaveNameCmd=new G4UIcmdWithAString("/OpNovice/run/setRunName",this);
	fSaveNameCmd->SetGuidance("Set this run name");
	fSaveNameCmd->SetParameterName("RunName",true);
	fSaveNameCmd->SetDefaultValue("data");
	
	fDoDigiCmd=new G4UIcmdWithABool("/OpNovice/run/doDigi",this);
	fDoDigiCmd->SetGuidance("Do digitization");
	
	fSaveRawCmd=new G4UIcmdWithABool("/OpNovice/run/saveRaw",this);
	fSaveRawCmd->SetGuidance("Save raw data");
	
	fSaveDigiCmd=new G4UIcmdWithABool("/OpNovice/run/saveDigi",this);
	fSaveDigiCmd->SetGuidance("Save digitized data");
	
	
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo.....

OpNoviceMessenger* OpNoviceMessenger::GetInstance(){
	if (messenger==0){
		G4cout<<"OpNoviceMessenger::GetInstance is creating a new Messenger"<<G4endl;
		messenger = new OpNoviceMessenger();
	}
	return messenger;
}



//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

OpNoviceMessenger::~OpNoviceMessenger(){
	
	delete fRunDir;
	
	delete fSaveThresholdCmd;
	delete fVerboseCmd;
	delete fPmtThresholdCmd;
	delete fForceDrawPhotonsCmd;
	delete fForceDrawNoPhotonsCmd;
	
	delete fDoDigiCmd;		
	/*Save command*/
	delete fSaveRawCmd;
	delete fSaveDigiCmd;
	delete fSaveNameCmd;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void OpNoviceMessenger::SetNewValue(G4UIcommand* command, G4String newValue){
	if( command == fSaveThresholdCmd ){
		fOpNoviceEvent->SetSaveThreshold(fSaveThresholdCmd->GetNewIntValue(newValue));
	}
	else if( command == fVerboseCmd ){
		fOpNoviceEvent->SetEventVerbose(fVerboseCmd->GetNewIntValue(newValue));
	}
	else if( command == fPmtThresholdCmd ){
		fOpNoviceEvent->SetPMTThreshold(fPmtThresholdCmd->GetNewIntValue(newValue));
	}
	else if(command == fForceDrawPhotonsCmd){
		fOpNoviceEvent->SetForceDrawPhotons(fForceDrawPhotonsCmd->GetNewBoolValue(newValue));
	}
	else if(command == fForceDrawNoPhotonsCmd){
		fOpNoviceEvent->SetForceDrawNoPhotons(fForceDrawNoPhotonsCmd->GetNewBoolValue(newValue));
	}
	else if(command == fDoDigiCmd){
		fOpNoviceEvent->SetDoDigi(fDoDigiCmd->GetNewBoolValue(newValue));
	}
	else if(command == fSaveRawCmd){
		fOpNoviceEvent->SetSaveRaw(fSaveRawCmd->GetNewBoolValue(newValue));
		fOpNoviceRun->SetSaveRaw(fSaveDigiCmd->GetNewBoolValue(newValue));
	}
	else if(command == fSaveDigiCmd){
		fOpNoviceEvent->SetSaveDigi(fSaveDigiCmd->GetNewBoolValue(newValue));
		fOpNoviceRun->SetSaveDigi(fSaveDigiCmd->GetNewBoolValue(newValue));
	}
	else if(command == fSaveNameCmd){
		fOpNoviceRun->SetName((std::string)newValue);
	}
}
