/*
 * TTofpetDummyAnalysis.hh
 *
 *  Created on: Dec 4, 2015
 *      Author: celentan
 */

#ifndef TTOFPETDUMMYANALYSIS_HH_
#define TTOFPETDUMMYANALYSIS_HH_

#include "TObject.h"

#include "TDriver.hh"

class TH1D;
class TH2D;
class TTofpetSetup;

class TTofpetDummyAnalysisDriver: public TDriver {
public:
	TTofpetDummyAnalysisDriver();
	virtual ~TTofpetDummyAnalysisDriver();


	/*These are the virtual methods implemented by the derived classes*/
	/*	virtual int start(){return 0;};
	virtual int startOfData(){return 0;};
	virtual int endOfData(){return 0;};
	virtual int end(){return 0;};
	virtual int process(TEvent *event);
	virtual int detectorChanged(){return 0;};*/

	virtual int startOfData();
	virtual int process(TEvent *event);
	virtual int end();

private:
	TH2D **hMultiplicity0;
	TH2D **hToT;
	TTofpetSetup *m_TofpetSetup;

	int m_Nsteps;

	ClassDef(TTofpetDummyAnalysisDriver,1);


};

#endif /* TTOFPETDUMMYANALYSIS_HH_ */
