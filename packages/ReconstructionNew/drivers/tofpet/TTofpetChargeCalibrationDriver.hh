/*
 * TTofpetChargeCalibrationDriver.hh
 *
 *  Created on: Dec 30, 2015
 *      Author: celentan
 */

#ifndef TTOFPETCHARGECALIBRATIONDRIVER_HH_
#define TTOFPETCHARGECALIBRATIONDRIVER_HH_

#include "TObject.h"

#include "TDriver.hh"

class TH1D;
class TH2D;
class TEvent;
class TTofpetRun;
class TTofpetSetupHandler;
class TDetectorLight;

class TTofpetChargeCalibrationDriver: public TDriver {
public:
	TTofpetChargeCalibrationDriver();
	virtual ~TTofpetChargeCalibrationDriver();
	/*
	virtual int start(){return 0;};
	virtual int startOfData(){return 0;};
	virtual int endOfData(){return 0;};
	virtual int end(){return 0;};
	virtual int process(TEvent *event){return 0;};
	virtual int detectorChanged(){return 0;};
	 */
	virtual int startOfData();
	virtual int end();
	virtual int process(TEvent *event);


private:

	TH1D **hToT0;

	TTofpetRun *m_TTofpetRun;
	TTofpetSetupHandler *m_TTofpetSetupHandler;
	TDetectorLight 	    *m_detector;

	int m_Nsteps;
	int m_Nchannels;
	int m_NhToT0;

	int m_hToT0_nbins;
	double m_hToT0_min,m_hToT0_max;


	double getHToT0Max() const {
		return m_hToT0_max;
	}

	void setHToT0Max(double hToT0Max) {
		m_hToT0_max = hToT0Max;
	}

	double getHToT0Min() const {
		return m_hToT0_min;
	}

	void setHToT0Min(double hToT0Min) {
		m_hToT0_min = hToT0Min;
	}

	int getHToT0Nbins() const {
		return m_hToT0_nbins;
	}

	void setHToT0Nbins(int hToT0Nbins) {
		m_hToT0_nbins = hToT0Nbins;
	}

	ClassDef(TTofpetChargeCalibrationDriver,1);
};

#endif /* TTOFPETCHARGECALIBRATIONDRIVER_HH_ */
