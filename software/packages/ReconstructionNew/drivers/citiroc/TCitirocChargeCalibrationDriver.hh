/*
 * TCitirocCalibrationDriver.hh
 *
 *  Created on: Dec 30, 2015
 *      Author: celentan
 */

#ifndef TCITIROCCHARGECALIBDRIVER_HH_
#define TCITIROCCHARGECALIBDRIVER_HH_

#include "TObject.h"

#include "TDriver.hh"
#include <string>

class TH1D;
class TH2D;
class TEvent;
class TCitirocRun;
class TCitirocSetupHandler;
class TDetector;
class TCitirocChargeCalibration;

class TCitirocChargeCalibrationDriver: public TDriver {

public:
	TCitirocChargeCalibrationDriver();
	virtual ~TCitirocChargeCalibrationDriver();
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

	map<pair<int,int>,TH1D*> hCharge0;
	std::pair<int,int> m_CitirocKey;


	TCitirocSetupHandler *m_CitirocSetupHandler;
	TCitirocChargeCalibration *m_CitirocChargeCalibration;

	TDetector 	    *m_detector;

	int m_nChannels;
	int nBinsCharge;
	double chargeMin,chargeMax;

	double chargeMinCut,chargeMaxCut;

	int m_isInteractive;
	std::string m_Thrfname;



public:



	void setThrFileName(const char* fname){this->m_Thrfname=string(fname);}




	int getIsInteractive() const {
		return m_isInteractive;
	}

	void setIsInteractive(int isInteractive) {
		m_isInteractive = isInteractive;
	}


	double getChargeMax() const {
		return chargeMax;
	}

	void setChargeMax(double chargeMax) {
		this->chargeMax = chargeMax;
	}

	double getChargeMin() const {
		return chargeMin;
	}

	void setChargeMin(double chargeMin) {
		this->chargeMin = chargeMin;
	}

	int getBinsCharge() const {
		return nBinsCharge;
	}

	void setBinsCharge(int binsCharge) {
		nBinsCharge = binsCharge;
	}


	double getChargeMaxCut() const {
		return chargeMaxCut;
	}

	void setChargeMaxCut(double chargeMaxCut) {
		this->chargeMaxCut = chargeMaxCut;
	}

	double getChargeMinCut() const {
		return chargeMinCut;
	}

	void setChargeMinCut(double chargeMinCut) {
		this->chargeMinCut = chargeMinCut;
	}

	ClassDef(TCitirocChargeCalibrationDriver,1);
};

#endif
