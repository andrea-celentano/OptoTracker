#ifndef TTOFPETEVENTHEADER_HG
#define TTOFPETEVENTHEADER_HG

#include "TObject.h"
#include "TEventHeader.hh"


class TTofpetEventHeader : public TEventHeader{


private:
	int m_step1;
	int m_step2;

public:




	int getStep1() const {
		return m_step1;
	}

	void setStep1(int step1) {
		m_step1 = step1;
	}

	int getStep2() const {
		return m_step2;
	}

	void setStep2(int step2) {
		m_step2 = step2;
	}

	ClassDef(TTofpetEventHeader,1);


};


#endif
