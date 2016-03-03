#ifndef _TLIKELIHOODCALCULATORTRACK_
#define _TLIKELIHOODCALCULATORTRACK_

#define clight 299.792  /*in mm/ns*/
#define SMALL_MU0 1E-24;

#include "TLikelihoodCalculator.hh"
#include "TObject.h"

class TLikelihoodCalculatorTrack : public TLikelihoodCalculator{
public:
	virtual double CalculateLikelihood(const double *x) const;

	double TrackLikelihoodCharge(int iface,int idetector,int id,const double *para) const;
	double TrackLikelihoodTime(int iface,int idetector,int id,const double *para) const;

	ClassDef(TLikelihoodCalculatorTrack,1);
};









#endif
