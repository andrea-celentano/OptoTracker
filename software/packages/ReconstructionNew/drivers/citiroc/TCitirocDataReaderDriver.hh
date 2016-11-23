/*
 * TDataReaderCitiroc.hh
 *
 *  Created on: Mar 7, 2016
 *      Author: celentan
 */

#ifndef TCITIROCDATAREADERDRIVER_HH_
#define TCITIROCDATAREADERDRIVER_HH_

#include "TDriver.hh"

class TEvent;
class TClonesArray;
class TCitirocSetupHandler;
class TCitirocEventHeader;
class TCitirocChargeCalibration;

class TCitirocDataReaderDriver: public TDriver {
public:
	TCitirocDataReaderDriver();
	virtual ~TCitirocDataReaderDriver();

	virtual int process(TEvent *event);
	virtual int startOfData();
	virtual int start();



private:
	TClonesArray *m_reconHitCollection;
	TCitirocSetupHandler *m_citirocSetupHandler;
	TCitirocEventHeader  *m_citirocEventHeader;
	TCitirocChargeCalibration *m_citirocChargeCalibration;

	std::pair<int,int> m_CitirocKey;
	std::string m_fname;

	double m_MultCutMin,m_MultCutMax;

public:

	double getMultCutMax() const {
		return m_MultCutMax;
	}

	void setMultCutMax(double multCutMax) {
		m_MultCutMax = multCutMax;
	}

	double getMultCutMin() const {
		return m_MultCutMin;
	}

	void setMultCutMin(double multCutMin) {
		m_MultCutMin = multCutMin;
	}

	void setChargeCalibFileName(const char* fname){this->m_fname=string(fname);}

	ClassDef(TCitirocDataReaderDriver,1);
};

#endif
