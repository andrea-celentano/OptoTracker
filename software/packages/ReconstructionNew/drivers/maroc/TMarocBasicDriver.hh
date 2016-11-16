/*
 * TMarocBasicDriver.hh
 *
 *  Created on: Mar 3, 2016
 *      Author: celentan
 */

#ifndef TMAROCBASICDRIVER_HH_
#define TMAROCBASICDRIVER_HH_
#include "TDriver.hh"

class TH1D;
class TH2D;

class TMarocBasicDriver: public TDriver {
public:
	TMarocBasicDriver();
	virtual ~TMarocBasicDriver();

	//virtual int start();
	virtual int startOfData();
	//virtual int endOfData();
	virtual int end();
	virtual int process(TEvent *event);
	//virtual int detectorChanged();
private:

	TH1D *hMultiplicity0;
	TH1D *hQTot0;
	TH2D *hQTotvsMultiplicity0;

	ClassDef(TMarocBasicDriver,1);
};

#endif /* TMAROCBASICDRIVER_HH_ */
