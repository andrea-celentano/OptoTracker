/*
 * TCitirocHit.hh
 *
 *  Created on: Mar 3, 2016
 *      Author: celentan
 */

#ifndef TCITIROCHIT_HH_
#define TCITIROCHIT_HH_

#include "TObject.h"



class TCitirocHit : public TObject{


private:
	UChar_t MAC;      /*MAC id, it is the identifier of the board*/
	UChar_t channel; /*Ch id (0..31)*/
	Short_t charge;  /*Charge (12 bit)*/
	bool Hit;

public:
	TCitirocHit(){};
	virtual ~TCitirocHit(){};



	Short_t getCharge() const {
		return charge;
	}

	void setCharge(Short_t charge) {
		this->charge = charge;
	}

	bool isHit() const {
		return Hit;
	}

	void setHit(bool Hit) {
		this->Hit = Hit;
	}

	UChar_t getMAC() const {
		return MAC;
	}

	void setMAC(UChar_t MAC) {
		this->MAC = MAC;
	}

	UChar_t getChannel() const{
		return channel;
	}

	void setChannel(UChar_t channel){
		this->channel = channel;
	}


	ClassDef(TCitirocHit,1);
};

#endif /* TCitirocHIT_HH_ */
