#ifndef TMCTRUTH_HG
#define TMCTRUTH_HG

#include "TNamed.h"

class TVector3;
class TLorentzVector;


class TMCTruth : public TNamed{

private:
	int m_pid;
	TLorentzVector *m_P0; //generation 4-momentum
	TLorentzVector *m_x0; //generation xyzt

	TLorentzVector *m_xin;
	TLorentzVector *m_xout;

	double m_edep;
	double m_edepVis;

	double m_pathLength;

public:

	TMCTruth();
	virtual ~TMCTruth();



	double getEdep() const {
		return m_edep;
	}

	void setEdep(double edep) {
		m_edep = edep;
	}
	void addEdep(double edep){
		m_edep+=edep;
	}

	double getEdepVis() const {
		return m_edepVis;
	}

	void setEdepVis(double edepVis) {
		m_edepVis = edepVis;
	}
	void addEdepVis(double edep){
			m_edepVis+=edep;
		}

	TLorentzVector* getP0() const {
		return m_P0;
	}

	void setP0(TLorentzVector* p0) {
		m_P0 = p0;
	}

	int getPid() const {
		return m_pid;
	}

	void setPid(int pid) {
		m_pid = pid;
	}

	 TLorentzVector* getX0() const {
		return m_x0;
	}

	void setX0(TLorentzVector* x0) {
		m_x0 = x0;
	}

	TLorentzVector* getXin() const {
		return m_xin;
	}

	void setXin(TLorentzVector* xin) {
		m_xin = xin;
	}

	TLorentzVector* getXout() const {
		return m_xout;
	}

	void setXout(TLorentzVector* xout) {
		m_xout = xout;
	}


	double getPathLength() const {
		return m_pathLength;
	}

	void setPathLength(double pathLength) {
		m_pathLength = pathLength;
	}

	ClassDef(TMCTruth,1);
};


#endif
