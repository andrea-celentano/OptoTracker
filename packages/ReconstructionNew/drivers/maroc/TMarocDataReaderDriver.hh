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

	ClassDef(TMarocDataReaderDriver,1);
};

#endif
