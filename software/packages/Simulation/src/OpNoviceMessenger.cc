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
	
		
	fVerboseCmd = new G4UIcmdWithAnInteger("/OpNovice/eventVerbose",this);
	fVerboseCmd->SetGuidance("Set the verbosity of event data.");
	fVerboseCmd->SetParameterName("verbose",true);
	fVerboseCmd->SetDefaultValue(1);
	

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
	
	fSaveScintRawCmd=new G4UIcmdWithABool("/OpNovice/run/saveScintRaw",this);
	fSaveScintRawCmd->SetGuidance("Save scint raw data");

	fSaveDetRawCmd=new G4UIcmdWithABool("/OpNovice/run/saveDetRaw",this);
	fSaveDetRawCmd->SetGuidance("Save det raw data");
	
	fSaveDetDigiCmd=new G4UIcmdWithABool("/OpNovice/run/saveDetDigi",this);
	fSaveDetDigiCmd->SetGuidance("Save det digitized data");
	
	
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
	delete fSaveDetRawCmd;
	delete fSaveDetDigiCmd;
	delete fSaveNameCmd;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void OpNoviceMessenger::SetNewValue(G4UIcommand* command, G4String newValue){
	if( command == fVerboseCmd ){
		fOpNoviceEvent->SetEventVerbose(fVerboseCmd->GetNewIntValue(newValue));
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
	else if(command == fSaveScintRawCmd){
			fOpNoviceEvent->SetSaveScintRaw(fSaveScintRawCmd->GetNewBoolValue(newValue));
			fOpNoviceRun->SetSaveScintRaw(fSaveScintRawCmd->GetNewBoolValue(newValue));
		}
	else if(command == fSaveDetRawCmd){
		fOpNoviceEvent->SetSaveDetRaw(fSaveDetRawCmd->GetNewBoolValue(newValue));
		fOpNoviceRun->SetSaveDetRaw(fSaveDetRawCmd->GetNewBoolValue(newValue));
	}
	else if(command == fSaveDetDigiCmd){
		fOpNoviceEvent->SetSaveDetDigi(fSaveDetDigiCmd->GetNewBoolValue(newValue));
		fOpNoviceRun->SetSaveDetDigi(fSaveDetDigiCmd->GetNewBoolValue(newValue));
	}
	else if(command == fSaveNameCmd){
		fOpNoviceRun->SetName((std::string)newValue);
	}
}
