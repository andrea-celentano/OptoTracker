#ifndef TMATRIXANALYSISDRIVER_H_
#define TMATRIXANALYSISDRIVER_H_

#include "TObject.h"
#include "TDriver.hh"

class TEvent;

class TMatrixAnalysisDriver : public TDriver {
public:
	TMatrixAnalysisDriver();
	virtual ~TMatrixAnalysisDriver();

	/*These are the virtual methods implemented by the derived classes*/
/*	virtual int start(){return 0;};
	virtual int startOfData(){return 0;};
	virtual int endOfData(){return 0;};
	virtual int end(){return 0;};
	virtual int process(TEvent *event);
	virtual int detectorChanged(){return 0;};*/

	virtual int start();
	virtual int process(TEvent *event);
	virtual int end();

	ClassDef(TMatrixAnalysisDriver,1);

};

#endif /* TMATRIXANALYSISDRIVER_H_ */
