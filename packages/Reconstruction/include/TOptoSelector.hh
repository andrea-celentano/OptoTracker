#ifndef TOptoSelector_h
#define TOptoSelector_h

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

using namespace std;

// Fixed size dimensions of array or collections stored in the TTree if any.

class TOptoSelector : public TSelector {
  public :
    TTree          *fChain;   //!pointer to the analyzed TTree or TChain
    
    // Declaration of leaf types ->in the derived classes
    
    // List of branches -> in the derived classes!

    
    TOptoSelector(TTree * t=0);
    

    virtual Int_t   Version() const { return 2; }
    virtual void    Begin(TTree *tree);      /*All the same*/
    virtual void    SlaveBegin(TTree *tree); /*All the same*/

    virtual Bool_t  Notify();
    virtual Int_t   GetEntry(Long64_t entry, Int_t getall = 0) { return fChain ? fChain->GetTree()->GetEntry(entry, getall) : 0; }
    virtual void    SetOption(const char *option) { fOption = option; } /*All the same*/
    virtual void    SetObject(TObject *obj) { fObject = obj; } /*All the same*/
    virtual void    SetInputList(TList *input) { fInput = input; } /*All the same*/
    virtual TList  *GetOutputList() const { return fOutput; } /*All the same*/
    virtual void    SlaveTerminate(); /*All the same*/
    virtual void    Terminate(); /*All the same*/
    




    TOpNoviceDetectorLight* getDetector(){return mm_detector;}
    void setDetector(TOpNoviceDetectorLight* detector){mm_detector=detector;}
    
    TReconInput* getReconInput(){return mm_reconInput;}
    void setReconInput(TReconInput* input){mm_reconInput=input;}
    
    void setSeed(int seed){mm_seed=seed;}   
    
    

    /*These are the pure virtual methods*/
      virtual ~TOptoSelector(){};
      virtual void    Init(TTree *tree)=0;       /*Specific to the selector*/
      virtual Bool_t  Process(Long64_t entry)=0; /*Specific to the selector*/

      virtual const char*	ClassName() const{return "TOptoSelector";} /*Stupid root.. as to be here otherwise crashes*/

  protected:
    TOpNoviceDetectorLight *mm_detector;
    TRecon                 *mm_recon;
    TReconInput 	       *mm_reconInput;
    TRandom3		       *mm_rand;
    int 		            mm_seed;
 
    double ***q;
    double ***tFirst;
    int ***N;
    
    //histograms
    TH1D *hX,*hY,*hZ,*hX_1,*hY_1,*hZ_1,*hX_2,*hY_2,*hZ_2;
    TH2D *hXY,*hXZ,*hYZ,*hXY_1,*hXZ_1,*hYZ_1,*hXY_2,*hXZ_2,*hYZ_2;
    TH2D *hPixel0[6][MAX_DETECTORS];
    TH1D *hTheta,*hPhi;
    TH1D *hNPhotons,*hT0,*hTau;
    
    /*indexed in this way: ID=6*idetector + iface
    So I just need to know there are 6 faces
    
    iface = ID % 6
    idetector = ID /6
    */
    
    vector < TH1D* > *hCharge[6*MAX_DETECTORS];
    vector < TH1D* > *hTime[6*MAX_DETECTORS];
    vector < TH2D* > *hTimeVsCharge[6*MAX_DETECTORS];
    string *hPixel0Title;
    
    ClassDef(TOptoSelector,1);
};


#endif
#ifdef TOptoSelector_cxx


Bool_t TOptoSelector::Notify()
{
  // The Notify() function is called when a new file is opened. This
  // can be either for a new TTree in a TChain or when when a new TTree
  // is started when using PROOF. It is normally not necessary to make changes
  // to the generated code, but the routine can be extended by the
  // user if needed. The return value is currently not used.
  
  return kTRUE;
}

#endif // #ifdef TOptoSelector_cxx
