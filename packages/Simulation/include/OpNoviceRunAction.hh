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

#ifndef OpNoviceRunAction_h
#define OpNoviceRunAction_h 1

#include <G4Types.hh>
#include <G4UserRunAction.hh>
#include <string>

#include "RootIO.hh"

class OpNoviceMessenger;

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

class G4Timer;
class G4Run;
class OpNoviceRecorderBase;
class RootIO;
class TDetector;

class OpNoviceRunAction : public G4UserRunAction
{
public:
	OpNoviceRunAction(OpNoviceRecorderBase*,TDetector*);
	virtual ~OpNoviceRunAction();
	
public:
	virtual void BeginOfRunAction(const G4Run* aRun);
	virtual void EndOfRunAction(const G4Run* aRun);
	
	inline void SetName(std::string name){fName=name;}
	inline std::string GetName(){return fName;}

	inline void SetSaveScintRaw(G4bool b){fSaveScintRaw=b;}
	inline void SetSaveDetRaw(G4bool b){fSaveDetRaw=b;}
	inline void SetSaveDetDigi(G4bool b){fSaveDetDigi=b;}
	
private:
	G4Timer* fTimer;
	OpNoviceRecorderBase* fRecorder;
	OpNoviceMessenger* fMessenger;
	TDetector* fDetector;

	G4bool fSaveScintRaw;
	G4bool fSaveDetRaw;
	G4bool fSaveDetDigi;
	
	std::string fName;
	RootIO fRootIO;
};

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#endif /*OpNoviceRunAction_h*/
