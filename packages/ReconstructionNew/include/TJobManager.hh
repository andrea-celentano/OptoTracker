#ifndef TOPTOJOBMANAGER_HG
#define TOPTOJOBMANAGER_HG

#include <vector>
#include <string>


#include "TSelector.h"
#include "TChain.h"
#include "TTree.h"


#include "TXMLHandler.hh"

class TDriver;
class TEvent;
using namespace std;

class TJobManager : public TSelector{

private:
	TTree *fTree;   //!pointer to the analyzed TTree or TChain

	// List of branches and corresponding pointers
	TBranch        *b_event;
	TEvent         *m_event;

	TXMLHandler 	  *m_xmlHandler;
	vector <TDriver*> *m_drivers;


	int m_eventN;

public:
	TJobManager(TTree * t=0);
	virtual ~TJobManager();

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

	virtual const char*	ClassName() const{return "TJobManager";} /*Stupid root.. as to be here otherwise crashes*/


	void Config(string fname="reconstruction.xml");


	vector<TDriver*>* getDrivers(){
		return m_drivers;
	}
	TDriver* getDriver(int id);

	int getEventN() const {
		return m_eventN;
	}

	void setEventN(int eventN) {
		m_eventN = eventN;
	}

	ClassDef(TJobManager,1);


};
#endif

