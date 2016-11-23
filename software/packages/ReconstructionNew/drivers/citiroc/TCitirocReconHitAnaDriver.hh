/*
 * TCitirocReconHitAnaDriver.hh
 *
 *  Created on: Mar 3, 2016
 *      Author: celentan
 */

#ifndef TCITIROCRECONHITANADRIVER_HH_
#define TCITIROCRECONHITANADRIVER_HH_
#include "TDriver.hh"

class TH1D;
class TH2D;

class TCitirocReconHitAnaDriver: public TDriver {
public:
	TCitirocReconHitAnaDriver();
	virtual ~TCitirocReconHitAnaDriver();

	//virtual int start();
	virtual int startOfData();
	//virtual int endOfData();
	virtual int end();
	virtual int process(TEvent *event);
	//virtual int detectorChanged();
private:

	TH2D *hTmp;
	TH2D *hTmp2;

	ClassDef(TCitirocReconHitAnaDriver,1);
};

#endif /* TMAROCBASICDRIVER_HH_ */
