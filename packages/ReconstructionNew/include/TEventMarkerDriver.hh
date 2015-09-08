#ifndef TEVENTMARKER_HG
#define TEVENTMARKER_HG

#include "TObject.h"
#include "TDriver.hh"

class TEvent;

class TEventMarkerDriver : public TDriver {

private:
	int Nevents;
	int m_eventN;
	int m_interval;

public:
	TEventMarkerDriver();
	virtual ~TEventMarkerDriver();

	/*These are the pure virtual methods implemented by here in derived classes*/
	virtual int startOfData(); //This method gets called once before the first event.
	virtual int endOfData();   //This method gets called once after the last event.
	virtual int process(TEvent *event);
	virtual int detectorChanged();


	int getInterval() const {
		return m_interval;
	}

	void setInterval(int interval) {
		if (interval>=1)	m_interval = interval;
	}

	ClassDef(TEventMarkerDriver,1);

};

#endif
