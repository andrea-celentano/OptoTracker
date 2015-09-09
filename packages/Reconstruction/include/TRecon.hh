#ifndef TRECON_H_GUARD
#define TRECON_H_GUARD

#include "TDetectorLight.hh"


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

#include "TReconInput.hh"
#include "TReconDefs.hh"



class TRecon : public ROOT::Math::IBaseFunctionMultiDim{
	//class TRecon: public ROOT::Minuit2::FCNBase{

public:
	TRecon(TDetectorLight* detector, TReconInput* input);
	~TRecon();

	static const int m_nPars = 10;

	
	ROOT::Math::Minimizer* getMinimizer(){return m_minimizer;}
	TDetectorLight* getDetector(){return m_detector;}
	void setDetector(TDetectorLight* detector){m_detector=detector;}

	  
	void initParameters();
	void setFitObject(fitObject_t);
	void setFitLikelihoodMode(fitLikelihoodMode_t);	
	fitObject_t getFitObject(){return m_fitObject;}
	fitLikelihoodMode_t getFitLikelihoodMode(){return m_fitLikelihoodMode;}



	void setNaddress(int iface,int idetector,int *N){m_N[iface][idetector]=N;}
	void setTaddress(int iface,int idetector,double *t){m_t[iface][idetector]=t;}


	void setPrintLevel(int level){m_minimizer->SetPrintLevel(level);}
	int  getPrintLevel(){return m_minimizer->PrintLevel();}
	
	
	void initFit();
	void doFit();

	TVector3 computeCOG();

	//virtual double Up() const {return 1;} 
	//virtual double operator()(const std::vector < double > & x) const;
	virtual double DoEval(const double*) const;
	virtual unsigned int NDim() const;
	virtual ROOT::Math::IBaseFunctionMultiDim* Clone() const;


    
private:
	ROOT::Math::Minimizer* m_minimizer;
	TDetectorLight* m_detector;
	TReconInput* m_reconInput;

	fitObject_t m_fitObject;
	fitLikelihoodMode_t m_fitLikelihoodMode;

	/*These are the arrays used to store the data.Note that the arrays are not filled here, but the user has to point them to a proper mem location*/
	int *m_N[6][MAX_DETECTORS];
	double *m_t[6][MAX_DETECTORS];
	
	string m_parNames[m_nPars];
	int m_freeFitObject;


public:	
	/*These methods are used by both!*/
	double SinglePhotonTimeProb(double t,double tau,double sigma) const;
	double SinglePhotonIntegratedTimeProb(double t,double tau,double sigma) const;
	double SinglePhotonTimeProbKernel(double *x,double *p);
	TF1 *m_SinglePhotonTimeProbKernel;
	double SinglePixelAverageCharge(const TVector3 &x0,int iface,int idetector,int id) const;
	double GetSolidAngle(const TVector3 &x0,int iface,int idetector,int id) const;

	double GetMinimalDelay(const TVector3 &x0,const TVector3 &x1,double beta,int iface,int idetector,int id) const;

	double GaussianCDF(const double &x,const double &mean,const double &sigma) const;
	/*Point likelihood*/
	double PointLikelihood(const double *x) const;
	double PointLikelihoodCharge(int iface,int idetector,int id,const double *x) const;
	double PointLikelihoodTime(int iface,int idetector,int id,const double *x) const;

	/*Track likelihood*/
	double TrackLikelihood(const double *x) const;	
	double TrackLikelihoodTime(int iface,int idetector,int id,const double *x) const;
	double TrackLikelihoodCharge(int iface,int idetector,int id,const double *x) const;
	double TrackAverageCharge(const TVector3 &x0,const TVector3 &x1,int iface,int idetector,int id) const;
	TF1 *m_TrackLikelihoodChargeKernel;
	double TrackLikelihoodChargeKernel(double *x,double *p);



};





#endif
