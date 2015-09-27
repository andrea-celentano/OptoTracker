#ifndef TMCPARTICLE_HG
#define TMCPARTICLE_HG

#include "TObject.h"

class TLorentzVector;

class TMCParticle : public TObject{

private:
	int m_pid;
	int m_id;
	int m_parentId;
	double m_edep;
	double m_edepVis;

	TLorentzVector *m_x0;
	TLorentzVector *m_P0;

public:
	TMCParticle();
	virtual ~TMCParticle();
	virtual void Clear(Option_t* option);

	double getEdep() const {
		return m_edep;
	}

	void setEdep(double edep) {
		m_edep = edep;
	}

	double getEdepVis() const {
		return m_edepVis;
	}

	void setEdepVis(double edepVis) {
		m_edepVis = edepVis;
	}

	int getId() const {
		return m_id;
	}

	void setId(int id) {
		m_id = id;
	}

	int getParentId() const {
		return m_parentId;
	}

	void setParentId(int parentId) {
		m_parentId = parentId;
	}

	int getPid() const {
		return m_pid;
	}

	void setPid(int pid) {
		m_pid = pid;
	}

	ClassDef(TMCParticle,1);

};

#endif
