#ifndef TLIKELIHOODRECONDRIVER_HH_
#define TLIKELIHOODRECONDRIVER_HH_

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
#include "TDetectorLight.hh"
#include "TJobManager.hh"

class TH1D;
class TH2D;
class TEvent;
class TReconInput;

#define clight 299.792  /*in mm/ns*/

class TLikelihoodReconDriver: public TDriver , public ROOT::Math::IBaseFunctionMultiDim{
public:
	TLikelihoodReconDriver();
	virtual ~TLikelihoodReconDriver();
	static const int m_nPars = 10;

	void initFit();
	void doFit();

	ROOT::Math::Minimizer* getMinimizer(){return m_minimizer;}


	void initParameters();
	void setFitObject(fitObject_t);
	void setFitLikelihoodMode(fitLikelihoodMode_t);
	fitObject_t getFitObject(){return m_fitObject;}
	fitLikelihoodMode_t getFitLikelihoodMode(){return m_fitLikelihoodMode;}

	/*These are inherited from the driver*/
	virtual int start();
	virtual int startOfData();
	virtual int process(TEvent *m_event);
	virtual int endOfData();



	/*These are inherited from IBaseFunctionMultiDim*/
	virtual double DoEval(const double*) const;
	virtual unsigned int NDim() const;
	virtual ROOT::Math::IBaseFunctionMultiDim* Clone() const;

	/*Point likelihood*/
	double PointLikelihood(const double *x) const;
	double PointLikelihoodCharge(int iface,int idetector,int id,const double *x) const;
	double PointLikelihoodTime(int iface,int idetector,int id,const double *x) const;

	/*Track likelihood*/
	double TrackLikelihood(const double *x) const;
	double TrackLikelihoodTime(int iface,int idetector,int id,const double *x) const;
	double TrackLikelihoodCharge(int iface,int idetector,int id,const double *x) const;


	void setReconInputMode(const char *mode);
	void setReconInputFileName(const char *name){m_reconInputFileName=string(name);}
private:
	ROOT::Math::Minimizer* m_minimizer;
	TReconInput* m_reconInput; /*This can be from file or from reconstruction itself*/

	fitObject_t m_fitObject;
	fitLikelihoodMode_t m_fitLikelihoodMode;


	int    **m_N[6];
	double **m_Q[6];
	double **m_t[6];

	int m_reconInputMode;
	string m_reconInputFileName;

	static const int reconInputFile=0;
	static const int reconInputDriver=1;

	void configReconInput();
	void configMinimizer();

	//histograms
	TH1D *hX,*hY,*hZ,*hX_1,*hY_1,*hZ_1,*hX_2,*hY_2,*hZ_2;
	TH2D *hXY,*hXZ,*hYZ,*hXY_1,*hXZ_1,*hYZ_1,*hXY_2,*hXZ_2,*hYZ_2;
	TH2D *hPixel0[6][MAX_DETECTORS];
	TH1D *hTheta,*hPhi;
	TH1D *hNPhotons,*hT0,*hTau;
	vector < TH1D* > *hCharge[6*MAX_DETECTORS];
	vector < TH1D* > *hTime[6*MAX_DETECTORS];
	vector < TH2D* > *hTimeVsCharge[6*MAX_DETECTORS];
	string *hPixel0Title;

	ClassDef(TLikelihoodReconDriver,1);
};

#endif
