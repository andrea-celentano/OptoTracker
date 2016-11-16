#ifndef TCITIROCEVENTHEADER_HG
#define TCITIROCEVENTHEADER_HG

#include "TObject.h"
#include "TEventHeader.hh"


class TCitirocEventHeader : public TEventHeader{


private:
	int m_multiplicity;
	int ts0,ts1,ts0_ref,ts1_ref;

public:

	TCitirocEventHeader(){};
	virtual ~TCitirocEventHeader(){};


	int getMultiplicity() const {
		return m_multiplicity;
	}

	void setMultiplicity(int multiplicity) {
		m_multiplicity = multiplicity;
	}


	int getTs0() const {
		return ts0;
	}

	void setTs0(int ts0) {
		this->ts0 = ts0;
	}

	int getTs0Ref() const {
		return ts0_ref;
	}

	void setTs0Ref(int ts0Ref) {
		ts0_ref = ts0Ref;
	}

	int getTs1() const {
		return ts1;
	}

	void setTs1(int ts1) {
		this->ts1 = ts1;
	}

	int getTs1Ref() const {
		return ts1_ref;
	}

	void setTs1Ref(int ts1Ref) {
		ts1_ref = ts1Ref;
	}

	ClassDef(TCitirocEventHeader,1);


};


#endif
