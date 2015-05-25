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
/// \file persistency/P01/include/OpNoviceClasses.hh
/// \brief Declaration of the classes for generating dictionaries
//
// $Id: ExP01Classes.hh 68025 2013-03-13 13:43:46Z gcosmo $
//
#include "OpNoviceDetectorHit.hh"
#include "G4VHit.hh"

#include "G4VDigi.hh"
#include "OpNoviceDigi.hh"

OpNoviceDetectorHit object1;
G4VHit object2;
std::vector<OpNoviceDetectorHit*> object3;

OpNoviceDigi object4;
G4VDigi object5;
std::vector<OpNoviceDigi*> object6;

std::vector< double > object7;



//TOpNoviceDetectorLight detector;

#undef __G4String
