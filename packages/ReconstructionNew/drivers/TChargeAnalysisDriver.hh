#ifndef TCHARGEANALYSISDRIVER_H_
#define TCHARGENALYSISDRIVER_H_

#include "TObject.h"
#include "TDriver.hh"
#include "TDetectorLight.hh"
#include <vector>
#include <fstream>

class TEvent;
class TMCTruth;
class TH1D;
class TH2D;

class TChargeAnalysisDriver : public TDriver {
private:

	int m_nPixels;
	int m_nDetectors;

	int m_writeOut;
	std::string m_writeOutFileName;
	std::ofstream m_writeOutFile;

	vector < double > m_Q;

	TH2D *hPixels2D[6][MAX_DETECTORS];
	TH1D *hPixelsMC;
	TH1D *hPixelsModel;

	TMCTruth *m_MCTruth;

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

	void setWriteOutFileName(const char* fname);

	ClassDef(TChargeAnalysisDriver,1);

};

#endif /* TMATRIXANALYSISDRIVER_H_ */
