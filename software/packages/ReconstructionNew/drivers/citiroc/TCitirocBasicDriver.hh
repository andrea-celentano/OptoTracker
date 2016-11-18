/*
 * TCitirocBasicDriver.hh
 *
 *  Created on: Mar 3, 2016
 *      Author: celentan
 */

#ifndef TCITIROCBASICDRIVER_HH_
#define TCITIROCBASICDRIVER_HH_
#include "TDriver.hh"

class TH1D;
class TH2D;

class TCitirocBasicDriver: public TDriver {
public:
	TCitirocBasicDriver();
	virtual ~TCitirocBasicDriver();

	//virtual int start();
	virtual int startOfData();
	//virtual int endOfData();
	virtual int end();
	virtual int process(TEvent *event);
	//virtual int detectorChanged();
private:

	TH2D *hQvsCh0;
	TH2D *hQvsCh1;
	TH2D *hQvsCh2;
	TH2D *hQvsCh3;
	ClassDef(TCitirocBasicDriver,1);
};

#endif /* TMAROCBASICDRIVER_HH_ */
