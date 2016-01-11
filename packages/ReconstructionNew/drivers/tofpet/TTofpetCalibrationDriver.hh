/*
 * TTofpetCalibrationDriver.hh
 *
 *  Created on: Dec 30, 2015
 *      Author: celentan
 */

#ifndef TTOFPETCALIBRATIONDRIVER_HH_
#define TTOFPETCALIBRATIONDRIVER_HH_

#include "TObject.h"

#include "TDriver.hh"

class TH1D;
class TH2D;
class TEvent;
class TTofpetRun;
class TTofpetSetupHandler;
class TDetectorLight;
class TTofpetThresholdCalibration;

class TTofpetCalibrationDriver: public TDriver {
public:
	TTofpetCalibrationDriver();
	virtual ~TTofpetCalibrationDriver();
	/*
	virtual int start(){return 0;};
	virtual int startOfData(){return 0;};
	virtual int endOfData(){return 0;};
	virtual int end(){return 0;};
	virtual int process(TEvent *event){return 0;};
	virtual int detectorChanged(){return 0;};
	 */
	virtual int start();
	virtual int startOfData();
	virtual int end();
	virtual int process(TEvent *event);


private:

	TH1D **hToT0;
	TH2D **hToTCalib;

	TTofpetRun *m_TTofpetRun;
	TTofpetSetupHandler *m_TTofpetSetupHandler;
	TTofpetThresholdCalibration *m_TTofpetThresholdCalibration;

	TDetectorLight 	    *m_detector;

	int m_Nsteps;
	int m_Nchannels;
	int m_NhToT0,m_NhToTCalib;

	int m_hToT0_nbins;
	double m_hToT0_min,m_hToT0_max;

	string m_Thrfname;
public:

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

	void setThrFileName(const char* fname){this->m_Thrfname=string(fname);}

	ClassDef(TTofpetCalibrationDriver,1);
};

#endif /* TTOFPETCHARGECALIBRATIONDRIVER_HH_ */
