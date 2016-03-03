/*
 * TLikelihoodCalculator.hh
 *
 *  Created on: Mar 3, 2016
 *      Author: celentan
 */

#ifndef TLIKELIHOODCALCULATOR_HH_
#define TLIKELIHOODCALCULATOR_HH_

#include "TDetectorLight.hh"
#include "TDetectorUtils.hh"

#include "TObject.h"

class TLikelihoodReconDriver;

class TLikelihoodCalculator : public TObject {
public:
	TLikelihoodCalculator();
	virtual ~TLikelihoodCalculator();
	/*This is the most critical method of this class! Since we MINIMIZE the function, this has to be negative (or -ln(L) if possible)
		x are the fit parameters.
		We define them in the TLikelihoodReconDriver as:
		x(0,1,2): xin
		x(3,4,5): xout
		x(6)       : beta
		x(7)       : t0
		x(8)       : Ntot
		x(9)       : tau
	*/
	virtual double CalculateLikelihood(const double *x)=0;

	TLikelihoodReconDriver* getDriver() const {
		return m_driver;
	}

	void setDriver(TLikelihoodReconDriver* driver) {
		m_driver = driver;
	}

	void Init(int **N[6],double **T[6],double **Q[6]);

protected:
	TLikelihoodReconDriver *m_driver;

	/*These 3 variables are the most important. Being indexed by pixel-detector-face.*/
	int    **m_N[6];   /*Is the pixel present in the event?*/
	double **m_Q[6]; 	/*Pixel charge*/
	double **m_T[6];	/*Pixel time*/

	ClassDef(TLikelihoodCalculator,1);
};

#endif /* TLIKELIHOODCALCULATOR_HH_ */
