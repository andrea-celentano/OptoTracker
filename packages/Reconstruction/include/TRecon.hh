#ifndef TRECON_H_GUARD
#define TRECON_H_GUARD

#include "TOpNoviceDetectorLight.hh"


//#include "Minuit2/FCNBase.h"
//#include "TFitterMinuit.h"
#include "Fit/ParameterSettings.h"
#include "Math/Minimizer.h"
#include "Math/IFunction.h"
#include "Math/Factory.h"
#include "TMinuitMinimizer.h"
#include "TF1.h"
#include "TVector3.h"

#include <vector>
#include <iostream>

#define clight 299.792  /*in mm/ns*/


enum fitObject_t{
	k_point,
	k_track
};

enum fitLikelihoodMode_t{
	k_onlyCharge,
	k_onlyTime,
	k_both	
};



class TRecon : public ROOT::Math::IBaseFunctionMultiDim{
//class TRecon: public ROOT::Minuit2::FCNBase{	
	
public:
	TRecon(TOpNoviceDetectorLight* detector);
	~TRecon();
	
//	TMinuitMinimizer* getMinimizer(){return m_minimizer;}
	ROOT::Math::Minimizer* getMinimizer(){return m_minimizer;}
	TOpNoviceDetectorLight* getDetector(){return m_detector;}
	void setDetector(TOpNoviceDetectorLight* detector){m_detector=detector;}
	
	void initParameters();
	void setFitObject(fitObject_t);
	void setFitLikelihoodMode(fitLikelihoodMode_t);
	fitObject_t getFitObject(){return m_fitObject;}
	fitLikelihoodMode_t getFitLikelihoodMode(){return m_fitLikelihoodMode;}
	
	
	
	void setNaddress(int i,int *N){m_N[i]=N;}
	void setTaddress(int i,double *t){m_t[i]=t;}
	
	
	void setPrintLevel(int level){m_minimizer->SetPrintLevel(level);}
	int  getPrintLevel(){return m_minimizer->PrintLevel();}
	void doFit();

	TVector3 computeCOG();
	
	//virtual double Up() const {return 1;} 
	//virtual double operator()(const std::vector < double > & x) const;
	virtual double DoEval(const double*) const;
	virtual unsigned int NDim() const;
	virtual ROOT::Math::IBaseFunctionMultiDim* Clone() const;
	
	
	
	
private:
	ROOT::Math::Minimizer* m_minimizer;
	TOpNoviceDetectorLight* m_detector;
	
	fitObject_t m_fitObject;
	fitLikelihoodMode_t m_fitLikelihoodMode;
	
	/*These are the arrays used to store the data.Note that the arrays are not filled here, but the user has to point them to a proper mem location*/
	int *m_N[6];
	double *m_t[6];
	
	int m_freeFitObject;
	
	
public:	
	
	double PointLikelihood(const double *x) const;
	double PointLikelihoodCharge(int iPMT,int id,const double *x) const;	
	double PointLikelihoodTime(int iPMT,int id,const double *x) const;
	

	double TrackLikelihood(const double *x) const;	
	double TrackLikelihoodTime(int iPMT,int id,const double *x) const;	
	double TrackLikelihoodCharge(int iPMT,int id,const double *x) const;
	double TrackAverageCharge(const TVector3 &x0,const TVector3 &x1,int iPMT,int id) const;
	TF1 *m_TrackLikelihoodChargeKernel;
	double TrackLikelihoodChargeKernel(double *x,double *p);
	
	
	/*These methods are used by both!*/
	double SinglePhotonTimeProb(double t,double tau,double sigma) const;
	double SinglePhotonIntegratedTimeProb(double t,double tau,double sigma) const;
	double SinglePhotonTimeProbKernel(double *x,double *p);
	TF1 *m_SinglePhotonTimeProbKernel;
	double SinglePixelAverageCharge(const TVector3 &x0,int iPMT,int id) const;
	double GetSolidAngle(const TVector3 &x0,int iPMT,int id) const;
	
	double GaussianCDF(const double &x,const double &mean,const double &sigma) const;
};





#endif