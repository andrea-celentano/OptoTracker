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

class TCitirocDataReaderDriver: public TDriver {
public:
	TCitirocDataReaderDriver();
	virtual ~TCitirocDataReaderDriver();

	virtual int process(TEvent *event);
	virtual int startOfData();


private:
	TClonesArray *m_reconHitCollection;
	TCitirocSetupHandler *m_citirocSetupHandler;
	TCitirocEventHeader  *m_citirocEventHeader;

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

	ClassDef(TCitirocDataReaderDriver,1);
};

#endif
