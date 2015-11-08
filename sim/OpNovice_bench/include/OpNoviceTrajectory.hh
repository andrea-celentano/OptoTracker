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
// $Id: OpNoviceTrajectory.hh 72349 2013-07-16 12:13:16Z gcosmo $
//
/// \file optical/OpNovice/include/OpNoviceTrajectory.hh
/// \brief Definition of the OpNoviceTrajectory class
//
#ifndef OpNoviceTrajectory_h
#define OpNoviceTrajectory_h 1

#include "G4Trajectory.hh"
#include "G4Allocator.hh"
#include "G4ios.hh"
#include "globals.hh"
#include "G4ParticleDefinition.hh"
#include "G4TrajectoryPoint.hh"
#include "G4Track.hh"
#include "G4Step.hh"

class G4Polyline;                   // Forward declaration.

class OpNoviceTrajectory : public G4Trajectory
{
  public:

    OpNoviceTrajectory();
    OpNoviceTrajectory(const G4Track* aTrack);
    OpNoviceTrajectory(OpNoviceTrajectory &);
    virtual ~OpNoviceTrajectory();
 
    virtual void DrawTrajectory() const;
 
    inline void* operator new(size_t);
    inline void  operator delete(void*);

    void SetDrawTrajectory(G4bool b){fDrawit=b;}
    void WLS(){fWls=true;}
    void SetForceDrawTrajectory(G4bool b){fForceDraw=b;}
    void SetForceNoDrawTrajectory(G4bool b){fForceNoDraw=b;}

  private:

    G4bool fWls;
    G4bool fDrawit;
    G4bool fForceNoDraw;
    G4bool fForceDraw;
    G4ParticleDefinition* fParticleDefinition;
};

extern G4ThreadLocal G4Allocator<OpNoviceTrajectory>* OpNoviceTrajectoryAllocator;

inline void* OpNoviceTrajectory::operator new(size_t)
{
  if(!OpNoviceTrajectoryAllocator)
      OpNoviceTrajectoryAllocator = new G4Allocator<OpNoviceTrajectory>;
  return (void*)OpNoviceTrajectoryAllocator->MallocSingle();
}

inline void OpNoviceTrajectory::operator delete(void* aTrajectory)
{
  OpNoviceTrajectoryAllocator->FreeSingle((OpNoviceTrajectory*)aTrajectory);
}

#endif
