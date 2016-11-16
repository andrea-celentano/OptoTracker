/*
 * TReconHit.hh
 *
 *  Created on: Mar 7, 2016
 *      Author: celentan
 */

#ifndef TRECONHIT_HH_
#define TRECONHIT_HH_

#include "TObject.h"

class TReconHit : public TObject{
public:
	TReconHit();
	virtual ~TReconHit();

	int face,detector,pixel;
	int nPhe;
	double Q,T;
	bool hit;


	int getDetector() const {
		return detector;
	}

	void setDetector(int detector) {
		this->detector = detector;
	}

	int getFace() const {
		return face;
	}

	void setFace(int face) {
		this->face = face;
	}

	bool isHit() const {
		return hit;
	}

	void setHit(bool hit) {
		this->hit = hit;
	}

	int getPhe() const {
		return nPhe;
	}

	void setPhe(int phe) {
		nPhe = phe;
	}

	int getPixel() const {
		return pixel;
	}

	void setPixel(int pixel) {
		this->pixel = pixel;
	}

	double getQ() const {
		return Q;
	}

	void setQ(double q) {
		Q = q;
	}

	double getT() const {
		return T;
	}

	void setT(double t) {
		T = t;
	}

	ClassDef(TReconHit,1);
};

#endif /* TRECONHIT_HH_ */
