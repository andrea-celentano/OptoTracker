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
#ifndef OpNoviceDetectorMessenger_h
#define OpNoviceDetectorMessenger_h 1

#include "G4UImessenger.hh"
#include "globals.hh"


class OpNoviceDetectorConstruction;
class G4UIdirectory;
class G4UIcmdWithADoubleAndUnit;
class G4UIcmdWith3VectorAndUnit;
class G4UIcmdWithAnInteger;
class G4UIcommand;
class G4UIcmdWithABool;
class G4UIcmdWithADouble;

class OpNoviceDetectorMessenger: public G4UImessenger
{
public:

OpNoviceDetectorMessenger(OpNoviceDetectorConstruction*);
virtual ~OpNoviceDetectorMessenger();

virtual void SetNewValue(G4UIcommand*, G4String);

private:

OpNoviceDetectorConstruction*     fOpNoviceDetector;
G4UIdirectory*                    fDetectorDir;
G4UIdirectory*                    fVolumesDir;
G4UIcmdWith3VectorAndUnit*        fDimensionsCmd;
G4UIcmdWithADouble*               fScintYield;
G4UIcmdWithADouble*  	          fScintFastDecayTime;


/*SURFACES*/
//photo-detectors
G4UIdirectory*                    fSurfDir[6];
G4UIcmdWithAnInteger*             fNdetCmd[6];
G4UIcmdWith3VectorAndUnit*        fPhotoDetDimension[6];	
G4UIcmdWith3Vector*               fNpixelsCmd[6];

G4UIcmdWith3Vector*               fRCmd[6];	
G4UIcmdWith3Vector*               fQECmd[6];


//coupling
G4UIcmdWithADoubleAndUnit*        fCouplingThicknessCmd[6];		
G4UIcmdWithADouble*               fCouplingNCmd[6];		
G4UIcmdWithADouble*               fReflectivityCmd[6];




G4UIcmdWithADoubleAndUnit*        fStepLimitCmd;



};

#endif
