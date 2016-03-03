#ifndef _TLIKELIHOODCALCULATORPOINT_
#define _TLIKELIHOODCALCULATORPOINT_

#define clight 299.792  /*in mm/ns*/
#define SMALL_MU0 1E-24;

#include "TObject.h"
#include "TLikelihoodCalculator.hh"
class TLikelihoodCalculatorPoint : public TLikelihoodCalculator{
public:
	virtual double CalculateLikelihood(const double *x) const;

	double PointLikelihoodCharge(int iface,int idetector,int id,const double *para) const;
	double PointLikelihoodTime(int iface,int idetector,int id,const double *para) const;


	ClassDef(TLikelihoodCalculatorPoint,1);
};









#endif
