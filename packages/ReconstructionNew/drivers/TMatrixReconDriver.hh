#ifndef TMATRIXRECONDRIVER_HH_
#define TMATRIXRECONDRIVER_HH_

#include "TObject.h"
#include "TMatrixT.h"
#include "TMatrixD.h"

#include "TDriver.hh"

#include <string>

class TEvent;

class TMatrixReconDriver : public TDriver {

private:
	TMatrixD *m_matrix;
	int m_matrixSource;

	TFile *m_matrixFile;
	string m_matrixFileName;

	static const int matrixSourceFile=0;
	static const int matrixSourceModel=1;

public:
	TMatrixReconDriver();
	virtual ~TMatrixReconDriver();

	virtual int startOfData();
	/*virtual int start();
	virtual int startOfData();
	virtual int process(TEvent *event);
	virtual int endOfData();
	virtual int end();
	 */
	void setMatrixSource(std::string source);
	void setMatrixFileName(std::string name){m_matrixFileName=name;};

	ClassDef(TMatrixReconDriver,1);

};

#endif /* TMATRIXRECONDRIVER_HH_ */
