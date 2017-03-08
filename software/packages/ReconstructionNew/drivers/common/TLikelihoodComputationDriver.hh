#ifndef TLIKELIHOODCOMPUTETIONDRIVER_HH_
#define TLIKELIHOODCOMPUTETIONDRIVER_HH_

#include <string>

#include "TObject.h"
#include "Fit/ParameterSettings.h"
#include "Math/Minimizer.h"
#include "Math/IFunction.h"
#include "Math/Factory.h"
#include "TMinuitMinimizer.h"
#include "OpNoviceDigi.hh"

#include "TDriver.hh"
#include "TReconDefs.hh"
#include "TDetector.hh"
#include "TJobManager.hh"


#include "TH1D.h"
#include "TH2D.h"

class TEvent;
class TReconInput;
class TLikelihoodCalculator;
class TRealSetupHandler;

class TLikelihoodComputationDriver: public TDriver{
public:
	TLikelihoodComputationDriver();
	virtual ~TLikelihoodComputationDriver();
	static const int m_nPars = 10;




	void initParameters();
	void setFitObject(fitObject_t);
	void setFitLikelihoodMode(fitLikelihoodMode_t);
	fitObject_t getFitObject(){return m_fitObject;}
	fitLikelihoodMode_t getFitLikelihoodMode(){return m_fitLikelihoodMode;}

	/*These are inherited from the driver*/
	virtual int start();
	virtual int startOfData();
	virtual int process(TEvent *m_event);
	virtual int end();


	/*This is the method to setup the Likelihood Calculator!*/
	void configLikelihoodCalculator(const char* name);

	TLikelihoodCalculator* getLikelihoodCalculator() const {
		return m_likelihoodCalculator;
	}

	void setLikelihoodCalculator(TLikelihoodCalculator* likelihoodCalculator) {
		m_likelihoodCalculator = likelihoodCalculator;
	}




	void setReconInputMode(const char *mode);
	void setReconInputFileName(const char *name){m_reconInputFileName=string(name);}
protected:

	TReconInput* m_reconInput; /*This can be from file or from reconstruction itself*/
	TRealSetupHandler *m_realSetupHandler;

	fitObject_t m_fitObject;
	fitLikelihoodMode_t m_fitLikelihoodMode;


	vector<vector<int>>    m_ON[6];  //consider hit or not
	vector<vector<int>>    m_disc[6];  //hit discriminator
	vector<vector<double>> m_Q[6];  //hit Charge
	vector<vector<double>> m_T[6];  //hit time

	int m_reconInputMode;
	string m_reconInputFileName;

	static const int reconInputFile=0;
	static const int reconInputDriver=1;

	void configReconInput();


	//Likelihood Calculator
	TLikelihoodCalculator *m_likelihoodCalculator;


	//histograms
	TH1D *hX,*hY,*hZ;
	TH2D *hXY,*hXZ,*hYZ;

	static const int nBinsX=100;
	static const int nBinsY=100;
	static const int nBinsZ=100;




	ClassDef(TLikelihoodComputationDriver,1);
};

#endif
