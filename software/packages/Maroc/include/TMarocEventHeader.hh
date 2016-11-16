#ifndef TMAROCEVENTHEADER_HG
#define TMAROCEVENTHEADER_HG

#include "TObject.h"
#include "TEventHeader.hh"


class TMarocEventHeader : public TEventHeader{


private:
	int m_multiplicity;

public:

	TMarocEventHeader(){};
	virtual ~TMarocEventHeader(){};




	int getMultiplicity() const {
		return m_multiplicity;
	}

	void setMultiplicity(int multiplicity) {
		m_multiplicity = multiplicity;
	}

	ClassDef(TMarocEventHeader,1);


};


#endif
