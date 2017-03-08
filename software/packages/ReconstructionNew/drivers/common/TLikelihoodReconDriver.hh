#ifndef TLIKELIHOODRECONDRIVERBASE_HH_
#define TLIKELIHOODRECONDRIVERBASE_HH_

#include <string>
#include <vector>

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

class TEvent;
class TReconInput;
class TLikelihoodCalculator;
class TRealSetupHandler;
class TTree;
class TH1D;
class TH2D;

class TLikelihoodReconDriver: public TDriver, public ROOT::Math::IBaseFunctionMultiDim {
public:
	TLikelihoodReconDriver();
	virtual ~TLikelihoodReconDriver();
	static const int m_nPars = 10;

	void initFit();
	void doFit();

	ROOT::Math::Minimizer* getMinimizer() {
		return m_minimizer;
	}

	void initParameters();
	void setFitObject(fitObject_t);
	void setFitLikelihoodMode(fitLikelihoodMode_t);
	fitObject_t getFitObject() {
		return m_fitObject;
	}
	fitLikelihoodMode_t getFitLikelihoodMode() {
		return m_fitLikelihoodMode;
	}

	/*These are inherited from the driver*/
	virtual int start();
	virtual int startOfData();
	virtual int process(TEvent *m_event);
	virtual int endOfData();

	/*These are inherited from IBaseFunctionMultiDim*/
	virtual double DoEval(const double*) const;
	virtual unsigned int NDim() const;
	virtual ROOT::Math::IBaseFunctionMultiDim* Clone() const;

	/*This is the method to setup the Likelihood Calculator!*/
	void configLikelihoodCalculator(const char* name);

	TLikelihoodCalculator* getLikelihoodCalculator() const {
		return m_likelihoodCalculator;
	}

	void setLikelihoodCalculator(TLikelihoodCalculator* likelihoodCalculator) {
		m_likelihoodCalculator = likelihoodCalculator;
	}

	void setReconInputMode(const char *mode);
	void setReconInputFileName(const char *name) {
		m_reconInputFileName = string(name);
	}
protected:
	ROOT::Math::Minimizer* m_minimizer;
	TReconInput* m_reconInput; /*This can be from file or from reconstruction itself*/

	TRealSetupHandler *m_realSetupHandler;

	fitObject_t m_fitObject;
	fitLikelihoodMode_t m_fitLikelihoodMode;

	vector<vector<int> > m_ON[6];  //consider hit or not
	vector<vector<int> > m_disc[6];  //hit discriminator
	vector<vector<double> > m_Q[6];  //hit Charge
	vector<vector<double> > m_T[6];  //hit time

	int m_reconInputMode;
	string m_reconInputFileName;

	static const int reconInputFile = 0;
	static const int reconInputDriver = 1;

	void configReconInput();
	void configMinimizer();

	//Likelihood Calculator
	TLikelihoodCalculator *m_likelihoodCalculator;

	//histograms
	TH1D *hX, *hY, *hZ, *hX_1, *hY_1, *hZ_1, *hX_2, *hY_2, *hZ_2;
	TH2D *hXY, *hXZ, *hYZ, *hXY_1, *hXZ_1, *hYZ_1, *hXY_2, *hXZ_2, *hYZ_2;
	TH1D *hTheta, *hPhi;
	TH1D *hNPhotons, *hT0, *hTau;

	//tree - and associated variables
	TTree *tout;

	/*Fit results*/
	double m_x0, m_y0, m_z0;
	double m_x1, m_y1, m_z1;
	double m_N, m_tau, m_beta, m_T0;
	double m_L;

	/*Some data*/
	int m_nON;
	double m_QTOT;

	int m_eventN;

ClassDef(TLikelihoodReconDriver,1);
};

#endif
