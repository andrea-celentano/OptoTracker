#ifndef _TLIKELIHOODCALCULATORMAROC1_
#define _TLIKELIHOODCALCULATORMAROC1L_

#define clight 299.792  /*in mm/ns*/
#define SMALL_MU0 1E-24

#include "TObject.h"
#include "TLikelihoodCalculator.hh"
class TLikelihoodCalculatorMaroc1 : public TLikelihoodCalculator{
public:
	TLikelihoodCalculatorMaroc1(){};
	virtual ~TLikelihoodCalculatorMaroc1(){};

	virtual double CalculateLikelihood(const double *x) const;

	double PointLikelihoodCharge(int iface,int idetector,int id,const double *para) const;
	double PointLikelihoodTime(int iface,int idetector,int id,const double *para) const;
	double TrackLikelihoodCharge(int iface,int idetector,int id,const double *para) const;
	double TrackLikelihoodTime(int iface,int idetector,int id,const double *para) const;



	ClassDef(TLikelihoodCalculatorMaroc1,1);
};









#endif
