/*
 * TDataReaderMC.hh
 *
 *  Created on: Mar 7, 2016
 *      Author: celentan
 */

#ifndef TMCDATAREADERDRIVER_HH_
#define TMCDATAREADERDRIVEr_HH_

#include "TDriver.hh"

class TEvent;
class TClonesArray;

class TMCDataReaderDriver: public TDriver {
public:
	TMCDataReaderDriver();
	virtual ~TMCDataReaderDriver();

	virtual int process(TEvent *event);
	virtual int startOfData();
private:
	TClonesArray *m_reconHitCollection;

	ClassDef(TMCDataReaderDriver,1);

};

#endif
