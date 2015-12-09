#ifndef TEVENTMARKER_HG
#define TEVENTMARKER_HG

#include "TObject.h"
#include "TDriver.hh"

class TEvent;

class TEventMarkerDriver : public TDriver {

private:
	int m_interval;

public:
	TEventMarkerDriver();
	virtual ~TEventMarkerDriver();

	/*These are the pure methods implemented here*/
	virtual int process(TEvent *event);


	int getInterval() const {
		return m_interval;
	}

	void setInterval(int interval) {
		if (interval>=1)	m_interval = interval;
	}

	ClassDef(TEventMarkerDriver,1);

};

#endif
