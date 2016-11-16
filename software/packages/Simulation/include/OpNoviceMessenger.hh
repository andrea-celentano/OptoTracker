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
// $Id: OpNoviceEventMessenger.hh 68752 2013-04-05 10:23:47Z gcosmo $
//
/// \file optical/OpNovice/include/OpNoviceEventMessenger.hh
/// \brief Definition of the OpNoviceEventMessenger class
//
//
#ifndef OpNoviceMessenger_h
#define OpNoviceMessenger_h 1

#include "G4UImessenger.hh"
#include "globals.hh"

class OpNoviceEventAction;
class OpNoviceRunAction;
class G4UIcmdWithAnInteger;
class G4UIcmdWithABool;
class G4UIcmdWithAString;
class G4UIdirectory;

class OpNoviceMessenger: public G4UImessenger
{
public:
	
	OpNoviceMessenger();
	virtual ~OpNoviceMessenger();
	virtual void SetNewValue(G4UIcommand*, G4String);
	
	void SetEventAction(OpNoviceEventAction *event){fOpNoviceEvent=event;}
	void SetRunAction(OpNoviceRunAction *run){fOpNoviceRun=run;};
	static OpNoviceMessenger* GetInstance();	
private:

	OpNoviceEventAction*   fOpNoviceEvent;
	OpNoviceRunAction*     fOpNoviceRun;
	
	G4UIcmdWithAnInteger*  fSaveThresholdCmd;
	G4UIcmdWithAnInteger*  fVerboseCmd;
	G4UIcmdWithAnInteger*  fPmtThresholdCmd;
	G4UIcmdWithABool*      fForceDrawPhotonsCmd;
	G4UIcmdWithABool*      fForceDrawNoPhotonsCmd;
	/*Directories*/
	G4UIdirectory*         fRunDir;
	
	/*Control commands*/
	G4UIcmdWithABool*      fDoDigiCmd;		
	/*Save command*/
	G4UIcmdWithABool*      fSaveScintRawCmd;
	G4UIcmdWithABool*      fSaveDetRawCmd;
	G4UIcmdWithABool*      fSaveDetDigiCmd;
	G4UIcmdWithAString*    fSaveNameCmd;
};

#endif
