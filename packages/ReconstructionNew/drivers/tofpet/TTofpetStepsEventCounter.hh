/*
 * TTofpetStepsEventCounter.hh
 *
 *  Created on: Dec 21, 2015
 *      Author: celentan
 */

#ifndef TTOFPETSTEPSEVENTCOUNTER_HH_
#define TTOFPETSTEPSEVENTCOUNTER_HH_

#include "TObject.h"
#include "TH2D.h"

#include "TDriver.hh"
class TTofpetRun;

class TTofpetStepsEventCounter: public TDriver {

private:
	TH2D *hStepsNevents;
	TTofpetRun *m_TofpetRun;

public:
	TTofpetStepsEventCounter();
	virtual ~TTofpetStepsEventCounter();


	/*virtual int start(){return 0;};*/
	virtual int startOfData();
	//	virtual int endOfData(){return 0;};
	//	virtual int end(){return 0;};
		virtual int process(TEvent *event);
	//	virtual int detectorChanged(){return 0;};

};

#endif /* TTOFPETSTEPSEVENTCOUNTER_HH_ */
