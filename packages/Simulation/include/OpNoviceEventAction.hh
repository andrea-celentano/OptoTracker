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
// $Id: OpNoviceEventAction.hh 68752 2013-04-05 10:23:47Z gcosmo $
//
/// \file optical/OpNovice/include/OpNoviceEventAction.hh
/// \brief Definition of the OpNoviceEventAction class
//

#ifndef OpNoviceEventAction_h
#define OpNoviceEventAction_h 1

#include "OpNoviceDetectorHit.hh"
#include "OpNoviceDigi.hh"
#include "OpNoviceMessenger.hh"
#include "G4UserEventAction.hh"
#include "globals.hh"
#include "G4ThreeVector.hh"

#include "RootIO.hh"

#include "TClonesArray.h"
#include "RootIO.hh"

class G4Event;
class OpNoviceRecorderBase;

class OpNoviceEventAction : public G4UserEventAction
{
public:
	
	OpNoviceEventAction(OpNoviceRecorderBase*);
	virtual ~OpNoviceEventAction();
	
public:
	
	virtual void BeginOfEventAction(const G4Event*);
	virtual void EndOfEventAction(const G4Event*);
	
	
	
	void SetEventVerbose(G4int v){fVerbose=v;}
	
	
	void SetForceDrawPhotons(G4bool b){fForcedrawphotons=b;}
	void SetForceDrawNoPhotons(G4bool b){fForcenophotons=b;}
	
	inline void SetDoDigi(G4bool b){fDoDigi=b;}
	
	inline void SetSaveScintRaw(G4bool b){fSaveScintRaw=b;}
	inline void SetSaveDetRaw(G4bool b){fSaveDetRaw=b;}
	inline void SetSaveDetDigi(G4bool b){fSaveDetDigi=b;}

private:
	
	OpNoviceRecorderBase* fRecorder;
	OpNoviceMessenger* fMessenger;
	
	
	

	

	G4int              fVerbose;
	
	
	
	G4bool fForcedrawphotons;
	G4bool fForcenophotons;

	G4bool fSaveScintRaw;
	G4bool fSaveDetRaw;
	G4bool fSaveDetDigi;
	G4bool fDoDigi;
	
	G4int              fScintCollID;
	G4int              fDetectorCollID;
	G4int              fDetectorDigiCollID;

	OpNoviceScintHitsCollection* scintHC;
	OpNoviceDetectorHitsCollection* detectorHC;
	OpNoviceDigitsCollection* detectorDigiHC;
	
	/*To save data*/
	RootIO *fRootIO;
	
	MCEvent* fMCEvent;
	std::vector<OpNoviceScintHit*>    *fRootCollectionScintRaw;
	std::vector<OpNoviceDetectorHit*> *fRootCollectionDetRaw;
	std::vector<OpNoviceDigi*>        *fRootCollectionDetDigi;

};

#endif
