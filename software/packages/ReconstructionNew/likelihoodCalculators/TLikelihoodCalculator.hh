/*
 * TLikelihoodCalculator.hh
 *
 *  Created on: Mar 3, 2016
 *      Author: celentan
 */

#ifndef TLIKELIHOODCALCULATOR_HH_
#define TLIKELIHOODCALCULATOR_HH_

#include "TReconDefs.hh"
#include <vector>

#include "TObject.h"
class TDriver;
class TDetector;
class TDetectorUtils;
class TRealSetupHandler;
using namespace std;

class TLikelihoodCalculator: public TObject {
public:
	TLikelihoodCalculator();
	virtual ~TLikelihoodCalculator();
	/*This is the most critical method of this class! Since we MINIMIZE the function, this has to be negative (or -ln(L) if possible)
	 x are the fit parameters.
	 We define them in the TDriver as:
	 x(0,1,2): xin
	 x(3,4,5): xout
	 x(6)       : beta
	 x(7)       : t0
	 x(8)       : Ntot
	 x(9)       : tau
	 */
	virtual double CalculateLikelihood(const double *x) const {
		return 0;
	}

	TDriver* getDriver() const {
		return m_driver;
	}
	void setDriver(TDriver* driver);

	TDetector* getDetector() const {
		return m_detector;
	}

	void setDetector(TDetector* detector) {
		m_detector = detector;
	}

	TDetectorUtils* getDetectorUtils() const {
		return m_detectorUtils;
	}

	void setDetectorUtils(TDetectorUtils* detectorUtils) {
		m_detectorUtils = detectorUtils;
	}

	TRealSetupHandler* getRealSetupHandler() const {
		return m_realSetupHandler;
	}

	void setRealSetupHandler(TRealSetupHandler* realSetupHandler) {
		m_realSetupHandler = realSetupHandler;
	}

	void SetData(vector<vector<int>> *ON,vector<vector<int>> *disc,vector<vector<double>> *T,vector<vector<double>> *Q);

	fitLikelihoodMode_t getFitLikelihoodMode() const {
		return m_fitLikelihoodMode;
	}

	void setFitLikelihoodMode(fitLikelihoodMode_t fitLikelihoodMode) {
		m_fitLikelihoodMode = fitLikelihoodMode;
	}

	fitObject_t getFitObject() const {
		return m_fitObject;
	}

	void setFitObject(fitObject_t fitObject) {
		m_fitObject = fitObject;
	}

protected:
	TDriver *m_driver;
	TDetector *m_detector;
	TDetectorUtils *m_detectorUtils;
	TRealSetupHandler *m_realSetupHandler;
	/*These 4 variables are the most important. Being indexed by pixel-detector-face.*/
	vector<vector<int>> *m_ON; /*Is the pixel present in the event?*/
	vector<vector<int>> *m_disc;
	vector<vector<double>> *m_Q; /*Pixel charge*/
	vector<vector<double>> *m_T; /*Pixel time*/

	fitObject_t m_fitObject;
	fitLikelihoodMode_t m_fitLikelihoodMode;

ClassDef(TLikelihoodCalculator,1)
	;
};

#endif /* TLIKELIHOODCALCULATOR_HH_ */
