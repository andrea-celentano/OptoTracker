#ifndef _TLIKELIHOODCALCULATORIDEAL_
#define _TLIKELIHOODCALCULATORIDEAL_

#define clight 299.792  /*in mm/ns*/
#define SMALL_MU0 1E-24

#include "TObject.h"
#include "TLikelihoodCalculator.hh"
#include "TReconDefs.hh"
class TLikelihoodCalculatorIdeal : public TLikelihoodCalculator{
public:
	TLikelihoodCalculatorIdeal(){};
	virtual ~TLikelihoodCalculatorIdeal(){};

	virtual double CalculateLikelihood(const double *x) const;

	double PointLikelihoodCharge(int iface,int idetector,int id,const double *para) const;
	double PointLikelihoodTime(int iface,int idetector,int id,const double *para) const;
	double TrackLikelihoodCharge(int iface,int idetector,int id,const double *para) const;
	double TrackLikelihoodTime(int iface,int idetector,int id,const double *para) const;





	ClassDef(TLikelihoodCalculatorIdeal,1);
};









#endif
