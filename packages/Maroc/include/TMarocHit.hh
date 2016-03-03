/*
 * TMarocHit.hh
 *
 *  Created on: Mar 3, 2016
 *      Author: celentan
 */

#ifndef TMAROCHIT_HH_
#define TMAROCHIT_HH_

#include "TObject.h"



class TMarocHit : public TObject{


private:
	int marocID;  /*The ID as reported by the MAROC measurement system!*/
	int charge;
	bool isHit;

public:
	TMarocHit(){};
	virtual ~TMarocHit(){};



	int getCharge() const {
		return charge;
	}

	void setCharge(int charge) {
		this->charge = charge;
	}

	bool isIsHit() const {
		return isHit;
	}

	void setIsHit(bool isHit) {
		this->isHit = isHit;
	}

	int getMarocId() const {
		return marocID;
	}

	void setMarocId(int marocId) {
		marocID = marocId;
	}

	ClassDef(TMarocHit,1);
};

#endif /* TMAROCHIT_HH_ */
