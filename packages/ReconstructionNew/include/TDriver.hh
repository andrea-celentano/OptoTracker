#ifndef TDRIVER_HG
#define TDRIVER_HG

#include "TObject.h"
#include "TEvent.hh"
#include <string>

using namespace std;



class TJobManager;

class TDriver : public TObject{

protected:
	TJobManager *m_manager;
	string m_name;

	int m_verboseLevel;
	int m_iterationN;

public:
	TDriver(TJobManager *manager=0);
	virtual ~TDriver();

	/*These are the pure virtual methods implemented by the derived classes*/
	virtual int startOfData()=0;
	virtual int endOfData()=0;
	virtual int process(TEvent *event)=0;
	virtual int detectorChanged()=0;

	TJobManager* getManager() const {
		return m_manager;
	}

	void setManager(TJobManager* manager) {
		this->m_manager = manager;
	}
	const string& getName() const {
		return m_name;
	}

	void setName(const string& name) {
		m_name = name;
	}

	int getVerboseLevel() const {
		return m_verboseLevel;
	}

	void setVerboseLevel(int verboseLevel) {
		m_verboseLevel = verboseLevel;
	}


	int getIterationN() const {
		return m_iterationN;
	}

	void setIterationN(int iterationN) {
		m_iterationN = iterationN;
	}

	ClassDef(TDriver,1);
};



#endif
