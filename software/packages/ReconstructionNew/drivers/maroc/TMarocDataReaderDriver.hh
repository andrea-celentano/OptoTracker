/*
 * TDataReaderMaroc.hh
 *
 *  Created on: Mar 7, 2016
 *      Author: celentan
 */

#ifndef TMAROCDATAREADERDRIVER_HH_
#define TMAROCDATAREADERDRIVEr_HH_

#include "TDriver.hh"

class TEvent;
class TClonesArray;
class TMarocSetupHandler;
class TMarocEventHeader;

class TMarocDataReaderDriver: public TDriver {
public:
	TMarocDataReaderDriver();
	virtual ~TMarocDataReaderDriver();

	virtual int process(TEvent *event);
	virtual int startOfData();


private:
	TClonesArray *m_reconHitCollection;
	TMarocSetupHandler *m_marocSetupHandler;
	TMarocEventHeader  *m_marocEventHeader;

	double m_ChargeCutMin,m_ChargeCutMax;
	double m_MultCutMin,m_MultCutMax;

public:
	double getChargeCutMax() const {
		return m_ChargeCutMax;
	}

	void setChargeCutMax(double chargeCutMax) {
		m_ChargeCutMax = chargeCutMax;
	}

	double getChargeCutMin() const {
		return m_ChargeCutMin;
	}

	void setChargeCutMin(double chargeCutMin) {
		m_ChargeCutMin = chargeCutMin;
	}

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

	ClassDef(TMarocDataReaderDriver,1);
};

#endif
