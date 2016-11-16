/*
 * TCitirocHit.hh
 *
 *  Created on: Mar 3, 2016
 *      Author: celentan
 */

#ifndef TCITIROCHITRAW_HH_
#define TCITIROCHITRAW_HH_

#include "TObject.h"



class TCitirocHitRaw : public TObject{


private:
	char MAC;      /*MAC id, it is the identifier of the board*/
	char channel; /*Ch id (0..31)*/
	short charge;  /*Charge (12 bit)*/
	bool Hit;

public:
	TCitirocHitRaw(){};
	virtual ~TCitirocHitRaw(){};

	short getCharge() const {
		return charge;
	}

	void setCharge(short charge) {
		this->charge = charge;
	}

	bool isHit() const {
		return Hit;
	}

	void setHit(bool Hit) {
		this->Hit = Hit;
	}

	char getMAC() const {
		return MAC;
	}

	void setMAC(char MAC) {
		this->MAC = MAC;
	}

	char getChannel() const{
		return channel;
	}

	void setChannel(char channel){
		this->channel = channel;
	}
	ClassDef(TCitirocHitRaw,1);
};

#endif
