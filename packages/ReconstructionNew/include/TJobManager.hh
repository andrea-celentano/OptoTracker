#ifndef TOPTOJOBMANAGER_HG
#define TOPTOJOBMANAGER_HG

#include <vector>
#include <string>
#include <map>

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

	map < string , string > *m_variables;


	int m_eventN;

	int m_doProof,m_doProofDiag,m_skipEvents,m_numberOfEventsTBP,m_verboseLevel,m_dryRun,m_numberOfWorkers,m_numberOfIterations;

	/*For some analysis, we may want to do more than one iteration.
	 * This happens, for example, if we need to first compute a "global" quantity,
	 * and then re-process the events using this quantity
	 */
	int m_iterationN;

	void ConfigDrivers(const vector < driver_struct > &driver_list);
	void ConfigControl(const reconControl_struct  &reconControl);


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

	void setVariable(string name,string value);
	int hasVariable(string name) const;
	string getVariable(string name) const;
	void printVariables() const;

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


	int getDoProof() const {
		return m_doProof;
	}

	void setDoProof(int doProof) {
		m_doProof = doProof;
	}

	int getDoProofDiag() const {
		return m_doProofDiag;
	}

	void setDoProofDiag(int doProofDiag) {
		m_doProofDiag = doProofDiag;
	}

	/*These methods refer to the number of events to be processed, and to the number of events skipped*/
	int getNumberOfEventsTBP() const {
		return m_numberOfEventsTBP;
	}
	void setNumberOfEventsTBP(int numberOfEvents) {
		m_numberOfEventsTBP = numberOfEvents;
	}
	int getSkipEvents() const {
		return m_skipEvents;
	}
	void setSkipEvents(int skipEvents) {
		m_skipEvents = skipEvents;
	}

	int getNumberOfEventsProcessed() const{
		int treeEntries;
		if (!fTree){
			Warning("getNumberOfEventsProcessed","no tree");
			return 0;
		}
		treeEntries=fTree->GetEntries();

		if (m_numberOfEventsTBP <= treeEntries ) return m_numberOfEventsTBP;
		else return treeEntries;
	}

	int getVerboseLevel() const {
		return m_verboseLevel;
	}

	void setVerboseLevel(int verboseLevel) {
		m_verboseLevel = verboseLevel;
	}


	int getDryRun() const {
		return m_dryRun;
	}

	void setDryRun(int dryRun) {
		m_dryRun = dryRun;
	}


	int getNumberOfWorkers() const {
		return m_numberOfWorkers;
	}

	void setNumberOfWorkers(int numberOfWorkers) {
		m_numberOfWorkers = numberOfWorkers;
	}


	int getIterationN() const {
		return m_iterationN;
	}

	void setIterationN(int iterationN) {
		m_iterationN = iterationN;
	}
	void incrementIterationN(){m_iterationN++;}
	int isLastIteration(){
		if (m_iterationN==(m_numberOfIterations-1)) return 1;
		else return 0;
	}

	int getNumberOfIterations() const {
		return m_numberOfIterations;
	}

	void setNumberOfIterations(int numberOfIterations) {
		m_numberOfIterations = numberOfIterations;
	}



public:

	static const int	noVerbosity=0;
	static const int	minimalVerbosity=1;
	static const int	normalVerbosity=2;
	static const int	fullVerbosity=3;
	static const int	veryfullVerbosity=4;



	ClassDef(TJobManager,1);


};
#endif

