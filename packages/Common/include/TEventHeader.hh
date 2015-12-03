#ifndef TEVENTHEADER_HG
#define TEVENTHEADER_HG

#include "TObject.h"

class TEventHeader : public TObject{

private:
	int m_eventNumber;
	int m_runNumber;

public:

	int getEventNumber() const {
		return m_eventNumber;
	}

	void setEventNumber(int eventNumber) {
		m_eventNumber = eventNumber;
	}

	int getRunNumber() const {
		return m_runNumber;
	}

	void setRunNumber(int runNumber) {
		m_runNumber = runNumber;
	}

	ClassDef(TEventHeader,1);
};

#endif
