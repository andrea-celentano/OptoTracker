#ifndef TOPTOJOBMANAGER_HG
#define TOPTOJOBMANAGER_HG

#include <vector>



#include "TSelector.h"
#include "TChain.h"
#include "TTree.h"

class OpNoviceDetectorHit;
class OpNoviceDigi;

using namespace std;

class TOptoJobManager : public TSelector{
private:
	TTree *fTree;   //!pointer to the analyzed TTree or TChain

	// List of branches and corresponding pointers
	TBranch        *b_MCraw;
	vector < OpNoviceDetectorHit* > *m_MCraw;

	TBranch        *b_MCdigi;
	vector < OpNoviceDigi* > *m_MCdigi;

public:
	TOptoJobManager(TTree * t=0);
	virtual ~TOptoJobManager(){};

	virtual Int_t   Version() const { return 2; }
	virtual void    Begin(TTree *tree);      /*All the same*/
	virtual void    SlaveBegin(TTree *tree); /*All the same*/

	virtual Int_t   GetEntry(Long64_t entry, Int_t getall = 0) { return fTree ? fTree->GetTree()->GetEntry(entry, getall) : 0; }
	virtual void    SetOption(const char *option) { fOption = option; } /*All the same*/
	virtual void    SetObject(TObject *obj) { fObject = obj; } /*All the same*/
	virtual void    SetInputList(TList *input) { fInput = input; } /*All the same*/
	virtual TList  *GetOutputList() const { return fOutput; } /*All the same*/
	virtual void    SlaveTerminate(); /*All the same*/
	virtual void    Terminate(); /*All the same*/


	virtual Bool_t  Notify();
	virtual void    Init(TTree *tree);
	virtual Bool_t  Process(Long64_t entry);

	virtual const char*	ClassName() const{return "TOptoJobManager";} /*Stupid root.. as to be here otherwise crashes*/


	ClassDef(TOptoJobManager,1);
};
#endif

#ifdef TOptoJobManager_cxx


Bool_t TOptoJobManager::Notify()
{
	// The Notify() function is called when a new file is opened. This
	// can be either for a new TTree in a TChain or when when a new TTree
	// is started when using PROOF. It is normally not necessary to make changes
	// to the generated code, but the routine can be extended by the
	// user if needed. The return value is currently not used.

	return kTRUE;
}







#endif
