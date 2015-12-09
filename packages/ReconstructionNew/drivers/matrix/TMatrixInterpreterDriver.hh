#ifndef TMATRIXINTERPRETERDRIVER_HH_
#define TMATRIXINTERPRETERDRIVER_HH_

#include "TObject.h"

#include "TDriver.hh"

class TEvent;
class TH3D;
class TMatrixInterpreterDriver: public TDriver {
private:
	TH3D* hVoxelRecon; /**This is the histogram containing the voxels solution*/

public:
	TMatrixInterpreterDriver();
	virtual ~TMatrixInterpreterDriver();

	virtual int startOfData();
	virtual int process(TEvent *event);


	ClassDef(TMatrixInterpreterDriver,1);

};

#endif /* TMATRIXINTERPRETERDRIVER_HH_ */
