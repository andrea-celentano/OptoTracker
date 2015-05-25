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

// Make this appear first!
#include "G4Timer.hh"

#include "OpNoviceRunAction.hh"
#include "OpNoviceRecorderBase.hh"
#include "G4Run.hh"
#include "RootIO.hh"
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

OpNoviceRunAction::OpNoviceRunAction(OpNoviceRecorderBase* r)
: G4UserRunAction(),
fTimer(0),
fRecorder(r),
fRootIO()
{
	fTimer = new G4Timer;
	fMessenger = OpNoviceMessenger::GetInstance();
	fMessenger->SetRunAction(this);
	fName="OpNovice";
	fSaveRaw=true;
	fSaveDigi=true;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

OpNoviceRunAction::~OpNoviceRunAction()
{
	delete fTimer;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void OpNoviceRunAction::BeginOfRunAction(const G4Run* aRun)
{
	G4cout << "### Run " << aRun->GetRunID() << " start." << G4endl;
	fTimer->Start();
	if(fRecorder)fRecorder->RecordBeginOfRun(aRun);
	
	/*Init the RootIO*/
	fRootIO.SetName(fName);
	fRootIO.SetSaveRaw(fSaveRaw);
	fRootIO.SetSaveDigi(fSaveDigi);
	fRootIO.Init(aRun->GetRunID());
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void OpNoviceRunAction::EndOfRunAction(const G4Run* aRun)
{
	if(fRecorder)fRecorder->RecordEndOfRun(aRun);
	fTimer->Stop();
	G4cout << "number of events = " << aRun->GetNumberOfEvent()
		<< " " << *fTimer << G4endl;	
	fRootIO.WriteAll();
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......