#ifndef TMATRIXANALYSISDRIVER_H_
#define TMATRIXANALYSISDRIVER_H_

#include "TObject.h"
#include "TDriver.hh"

#include "TH1D.h"
class TEvent;

class TMatrixWriterDriver : public TDriver {
private:
	TH1D *hPixels;
	int m_nPixels;
	int m_nDetectors;
	int m_voxelID;
public:
	TMatrixWriterDriver();
	virtual ~TMatrixWriterDriver();

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

	void setVoxelID(int id){m_voxelID=id;}

	ClassDef(TMatrixWriterDriver,1);

};

#endif /* TMATRIXANALYSISDRIVER_H_ */
