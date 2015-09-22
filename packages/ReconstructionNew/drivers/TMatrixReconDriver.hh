#ifndef TMATRIXRECONDRIVER_HH_
#define TMATRIXRECONDRIVER_HH_

#include "TObject.h"
#include "TMatrixT.h"
#include "TMatrixD.h"

#include "TDriver.hh"

#include <string>

class TEvent;
class TFile;
class TH3D;

class TMatrixReconDriver : public TDriver {

private:
	TMatrixD *m_matrix;
	TMatrixD m_matrixInverse;
	int m_matrixSource;

	TFile *m_matrixFile;
	string m_matrixFileName;
	string m_collectionName;

	TH3D *hVoxels;

	static const int matrixSourceFile=0;
	static const int matrixSourceModel=1;

public:
	TMatrixReconDriver();
	virtual ~TMatrixReconDriver();

	virtual int startOfData();
	virtual int process(TEvent *event);
	/*virtual int start();
	virtual int startOfData();
	virtual int process(TEvent *event);
	virtual int endOfData();
	virtual int end();
	 */
	void setMatrixSource(const char* source);
	void setMatrixFileName(const char* fname){m_matrixFileName=string(fname);}
	void setCollectionName(const char* name){m_collectionName=string(name);}

	ClassDef(TMatrixReconDriver,1);

};

#endif /* TMATRIXRECONDRIVER_HH_ */
