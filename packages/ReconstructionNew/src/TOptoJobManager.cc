#define TOptoJobManager_cxx
#include "TOptoJobManager.hh"


TOptoJobManager::TOptoJobManager(TTree* /*tree*/)
{
//	Info("TOptoJobManager","TOptoJobManager constructor");
}



void TOptoJobManager::Init(TTree *tree)
{
	// The Init() function is called when the selector needs to initialize
	// a new tree or chain. Typically here the branch addresses and branch
	// pointers of the tree will be set.
	// It is normally not necessary to make changes to the generated
	// code, but the routine can be extended by the user if needed.
	// Init() will be called many times when running on PROOF
	// (once per file to be processed).

	Info("TOptoJobManager","TOptoJobManager Init");
	// Set object pointers
	b_MCraw = 0;
	b_MCdigi = 0;
	// Set branch addresses and branch pointers
	if (!tree) return;
	fTree = tree;
	fTree->SetMakeClass(1);

	if(fTree->GetListOfBranches()->FindObject("DetRaw")){
		fTree->SetBranchAddress("DetRaw", &m_MCraw, &b_MCraw);
	}

	if(fTree->GetListOfBranches()->FindObject("DetDigi")){
		fTree->SetBranchAddress("DetDigi", &m_MCdigi, &b_MCdigi);
	}


}




void TOptoJobManager::Begin(TTree* /*tree*/)
{
	Info("TOptoJobManager","TOptoJobManager Begin");
}


void TOptoJobManager::SlaveBegin(TTree* /*tree*/)
{
	Info("TOptoJobManager","TOptoJobManager SlaveBegin");
}



void TOptoJobManager::SlaveTerminate()
{
	Info("TOptoJobManager","TOptoJobManager SlaveTerminate");
}



void TOptoJobManager::Terminate()
{
	Info("TOptoJobManager","TOptoJobManager Terminate");
}






Bool_t  TOptoJobManager::Process(Long64_t entry){
	GetEntry(entry);

}


