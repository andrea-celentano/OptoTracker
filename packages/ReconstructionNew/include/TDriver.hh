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



	ClassDef(TDriver,1);
};



#endif
