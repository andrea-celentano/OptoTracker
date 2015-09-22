#ifndef TCHARGEANALYSISDRIVER_H_
#define TCHARGENALYSISDRIVER_H_

#include "TObject.h"
#include "TDriver.hh"
#include "TDetectorLight.hh"
#include <vector>

class TEvent;
class TH1D;
class TH2D;

class TChargeAnalysisDriver : public TDriver {
private:
	TH1D *hPixels;
	int m_nPixels;
	int m_nDetectors;

	TH2D *hPixels2D[6][MAX_DETECTORS];

public:
	TChargeAnalysisDriver();
	virtual ~TChargeAnalysisDriver();

	/*These are the virtual methods implemented by the derived classes*/
/*	virtual int start(){return 0;};
	virtual int startOfData(){return 0;};
	virtual int endOfData(){return 0;};
	virtual int end(){return 0;};
	virtual int process(TEvent *event);
	virtual int detectorChanged(){return 0;};*/

	virtual int start();
	virtual int startOfData();
	virtual int process(TEvent *event);
	virtual int end();



	ClassDef(TChargeAnalysisDriver,1);

};

#endif /* TMATRIXANALYSISDRIVER_H_ */
