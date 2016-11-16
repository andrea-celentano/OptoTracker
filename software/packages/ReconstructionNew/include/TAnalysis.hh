#ifndef TANALYSIS_HG
#define TANALYSIS_HG

#include "TObject.h"
#include <string>
class TJobManager;
class TChain;
class TList;
class TProof;

using namespace std;

class TAnalysis : public TObject{
private:

	TJobManager *m_manager;
	TChain		*m_chain;
	TProof		*m_proof;

	string m_steeringName;
	string m_detName;
	vector<string> *m_fileName;


	int isConfigured;
public:
	TAnalysis();
	virtual ~TAnalysis();

	TChain* getChain() const {
		return m_chain;
	}

	void setChain(TChain* fChain) {
		m_chain = fChain;
	}

	TJobManager* getManager() const {
		return m_manager;
	}

	void setManager(TJobManager* manager) {
		m_manager = manager;
	}

	void addToInputList(TObject *obj);

	void configure(std::string fname);

	void addFileToChain(std::string fname);

	void run();

	void ParseCommandLine(int argc,char **argv);

	ClassDef(TAnalysis,1);
};


#endif
