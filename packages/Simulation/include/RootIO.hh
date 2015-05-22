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
/// \file persistency/P01/include/RootIO.hh
/// \brief Definition of the RootIO class
//
// $Id: RootIO.hh 71791 2013-06-24 14:08:28Z gcosmo $
#ifndef INCLUDE_ROOTIO_HH 
#define INCLUDE_ROOTIO_HH 1

// Include files
#include "TROOT.h"
#include "TTree.h"
#include "TFile.h"
#include "TH1D.h"
#include "TH2D.h"
#include "TSystem.h"
#include "TClonesArray.h"

#include "OpNoviceDetectorHit.hh"
#include "OpNoviceDigi.hh"

#include "TOpNoviceDetectorLight.hh"

#include <string>
/** @class RootIO
 *   
 *
 *  @author Witold POKORSKI
 *  @date   2005-10-27
 */

/// Root IO implementation for the persistency example

class RootIO 
{
public: 
	virtual ~RootIO();
	
	static RootIO* GetInstance();
	void FillRaw();
	void FillDigi();
	void FillAll();
	void WriteAll();
	void Init(int n);
	
	
	inline void SetName(std::string s){this->fName=s;}
	inline TString GetName(){return fName;}
	
	//inline TClonesArray* GetRootCollectionRaw(){return fRootCollectionRaw;}
	inline std::vector<OpNoviceDetectorHit*>* GetRootCollectionRaw(){return fRootCollectionRaw;}
	inline std::vector<OpNoviceDigi*>* GetRootCollectionDigi(){return fRootCollectionDigi;}
	
	inline TFile* getFile(){return fFile;}
	inline void SetSaveRaw(G4bool b){fSaveRaw=b;}
	inline void SetSaveDigi(G4bool b){fSaveDigi=b;}
	
	void fillHistogram1D(int idx,double x,double w);
	void fillHistogram2D(int idx,double x,double y,double w);
	void saveDetectorLight(TOpNoviceDetectorLight *detector);
	RootIO(); 
private:
	
	std::string fName;
	TFile* fFile;
	TTree* fTreeRaw;
	TTree* fTreeDigi;
	int fNevents;
	
	G4bool fSaveRaw;
	G4bool fSaveDigi;
	
	//TClonesArray *fRootCollectionRaw;
	
	std::vector< TH1* > *fHistograms1D;
	std::vector< TH2* > *fHistograms2D;
	std::vector<OpNoviceDetectorHit*> *fRootCollectionRaw;
	std::vector<OpNoviceDigi*> *fRootCollectionDigi;
};
#endif // INCLUDE_ROOTIO_HH
