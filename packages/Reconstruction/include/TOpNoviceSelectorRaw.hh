//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Thu Mar 19 10:24:19 2015 by ROOT version 5.34/21
// from TTree raw/raw
// found on file: muon.root
//////////////////////////////////////////////////////////

#ifndef TOpNoviceSelectorRaw_h
#define TOpNoviceSelectorRaw_h

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

#include "Cintex/Cintex.h"
#include <TSystem.h>
#include <TMath.h>
// Header file for the classes stored in the TTree if any.

#include "OpNoviceDetectorHit.hh"
#include "TOpNoviceDetectorLight.hh"
#include "TRecon.hh"


using namespace std;

// Fixed size dimensions of array or collections stored in the TTree if any.

class TOpNoviceSelectorRaw : public TSelector {
  public :
    TTree          *fChain;   //!pointer to the analyzed TTree or TChain
    
    // Declaration of leaf types
    vector<OpNoviceDetectorHit*> *raw;
    
    // List of branches
    TBranch        *b_raw;   //!
    
    TOpNoviceSelectorRaw(TTree * t=0);
    
    virtual ~TOpNoviceSelectorRaw() { }
    virtual Int_t   Version() const { return 2; }
    virtual void    Begin(TTree *tree);
    virtual void    SlaveBegin(TTree *tree);
    virtual void    Init(TTree *tree);
    virtual Bool_t  Notify();
    virtual Bool_t  Process(Long64_t entry);
    virtual Int_t   GetEntry(Long64_t entry, Int_t getall = 0) { return fChain ? fChain->GetTree()->GetEntry(entry, getall) : 0; }
    virtual void    SetOption(const char *option) { fOption = option; }
    virtual void    SetObject(TObject *obj) { fObject = obj; }
    virtual void    SetInputList(TList *input) { fInput = input; }
    virtual TList  *GetOutputList() const { return fOutput; }
    virtual void    SlaveTerminate();
    virtual void    Terminate();
    
    TOpNoviceDetectorLight* getDetector(){return m_detector;}
    void setDetector(TOpNoviceDetectorLight* detector){m_detector=detector;cout<<"SET DETECTOR"<<endl;}
    void setSeed(int seed){m_seed=seed;}   
    
    
  private:
    TOpNoviceDetectorLight *m_detector;
    TRecon                 *m_recon;
    TRandom3		   *m_rand;
    int 		    m_seed;
 
    double ***q;
    double ***tFirst;
    int ***N;
    
    //histograms
    TH1D *hX,*hY,*hZ,*hX_1,*hY_1,*hZ_1,*hX_2,*hY_2,*hZ_2;
    TH2D *hXY,*hXZ,*hYZ,*hXY_1,*hXZ_1,*hYZ_1,*hXY_2,*hXZ_2,*hYZ_2;
    TH2D *hPixel0[6][MAX_DETECTORS];
    TH1D *hTheta,*hPhi;
    TH1D *hNPhotons,*hT0,*hTau;
    
    vector < TH1D* > hCharge[6][MAX_DETECTORS];
    vector < TH1D* > hTime[6][MAX_DETECTORS];
    vector < TH2D* > hTimeVsCharge[6][MAX_DETECTORS];
    string hPixel0Title[6];
    
 //   ClassDef(TOpNoviceSelectorRaw,0);
};


#endif
#ifdef TOpNoviceSelectorRaw_cxx
void TOpNoviceSelectorRaw::Init(TTree *tree)
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
  
  fChain->SetBranchAddress("raw", &raw, &b_raw);
}

Bool_t TOpNoviceSelectorRaw::Notify()
{
  // The Notify() function is called when a new file is opened. This
  // can be either for a new TTree in a TChain or when when a new TTree
  // is started when using PROOF. It is normally not necessary to make changes
  // to the generated code, but the routine can be extended by the
  // user if needed. The return value is currently not used.
  
  return kTRUE;
}

#endif // #ifdef TOpNoviceSelectorRaw_cxx