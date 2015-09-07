#define TOptoJobManager_cxx
#include "TOptoJobManager.hh"
#include "OpNoviceDigi.hh"
#include "OpNoviceDetectorHit.hh"

TOptoJobManager::TOptoJobManager(TTree* tree):
fTree(tree),b_event(0),m_event(0)
{
	Info("TOptoJobManager","TOptoJobManager constructor");
}


TOptoJobManager::~TOptoJobManager()
{
	/*if (fTree) delete fTree;
	if (b_event) delete b_event;
	if (m_event) delete m_event;*/
	Info("TOptoJobManager","TOptoJobManager destructor");

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
	b_event = 0;
	m_event = 0;
	// Set branch addresses and branch pointers
	if (!tree) return;
	fTree = tree;
	//fTree->SetMakeClass(1);

	if(fTree->GetListOfBranches()->FindObject("Event")){
		fTree->SetBranchAddress("Event", &m_event, &b_event);
	}

	m_event->Clear("C");
	Info("TOptoJobManager","TOptoJobManager Init Done");
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
	m_event->Clear("C");
	GetEntry(entry);
	cout<<this->getTmp2()<<endl;
	this->setTmp2(entry);
	cout<<this->getTmp2()<<endl;
	cout<<"AAA"<<endl;
	TClonesArray* tmp=m_event->getCollection(OpNoviceDigi::Class(),"DetDigiMC");
	TClonesArray* tmp2=m_event->getCollection(OpNoviceDetectorHit::Class(),"DetRawMC");
	cout<<"DIGI0: "<<((OpNoviceDigi*)tmp->At(0))->GetName()<<" "<<((OpNoviceDigi*)tmp->At(0))->GetPheCount()<<endl;
	cout<<"RAW0: "<<((OpNoviceDetectorHit*)tmp2->At(0))->GetName()<<" "<<((OpNoviceDetectorHit*)tmp2->At(0))->GetPheCount()<<endl;

	for (int qq=0;qq<tmp2->GetEntriesFast();qq++){
		int Nphe=((OpNoviceDetectorHit*)tmp2->At(qq))->GetPheCount();
		for (int nn=0;nn<Nphe;nn++){
			cout<<((OpNoviceDetectorHit*)tmp2->At(qq))->GetX(nn)<<endl;
		}
	}


}


