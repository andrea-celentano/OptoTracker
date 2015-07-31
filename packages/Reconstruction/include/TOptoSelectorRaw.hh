#ifndef TOptoSelectorRaw_h
#define TOptoSelectorRaw_h

#include <vector>
#include <string>
#include <iostream>
#include <fstream>

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TSelector.h>
#include <TProofServ.h>
#include <TRandom3.h>
#include <TH1D.h>
#include <TH2D.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <TString.h>

#include "Cintex/Cintex.h"
#include <TSystem.h>
#include <TMath.h>
// Header file for the classes stored in the TTree if any.

#include "OpNoviceDetectorHit.hh"
#include "TOpNoviceDetectorLight.hh"
#include "TRecon.hh"
#include "TReconInput.hh"

#include "TOptoSelector.hh"

using namespace std;


class TOptoSelectorRaw : public TOptoSelector{

private:
	//List of leafs
	vector<OpNoviceDetectorHit*> *raw;
	 // List of branches
    TBranch        *b_raw;

public:
    TOptoSelectorRaw(TTree * t=0);
    virtual ~TOptoSelectorRaw() { }

    virtual void    Init(TTree *tree);       /*Specific to the selector*/
    virtual Bool_t  Process(Long64_t entry); /*Specific to the selector*/


    ClassDef(TOptoSelectorRaw,1);
};

#endif

#ifdef TOptoSelectorRaw_cxx
void TOptoSelectorRaw::Init(TTree *tree)
{
  // The Init() function is called when the selector needs to initialize
  // a new tree or chain. Typically here the branch addresses and branch
  // pointers of the tree will be set.
  // It is normally not necessary to make changes to the generated
  // code, but the routine can be extended by the user if needed.
  // Init() will be called many times when running on PROOF
  // (once per file to be processed).

  // Set object pointer
  raw = 0;
  // Set branch addresses and branch pointers
  if (!tree) return;
  fChain = tree;
  fChain->SetMakeClass(1);

  fChain->SetBranchAddress("DetRaw", &raw, &b_raw);
}

#endif
