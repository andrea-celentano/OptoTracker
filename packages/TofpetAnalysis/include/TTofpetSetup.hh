#ifndef TTOFPETSETUP_HG
#define TTOFPETSETUP_HG

#include "TObject.h"
#include <vector>
#include <utility>


class TTofpetSetup:public TObject{

private:
	int m_Nsteps1,m_Nsteps2,m_Nsteps;
	std::vector < std::pair < int , int > > m_pairs;

public:



	int getNsteps() const {
		return m_Nsteps;
	}

	void setNsteps(int nsteps) {
		m_Nsteps = nsteps;
	}

	int getNsteps1() const {
		return m_Nsteps1;
	}

	void setNsteps1(int nsteps1) {
		m_Nsteps1 = nsteps1;
	}

	int getNsteps2() const {
		return m_Nsteps2;
	}

	void setNsteps2(int nsteps2) {
		m_Nsteps2 = nsteps2;
	}

	void addPair(int step1,int step2){
		m_pairs.push_back(std::make_pair(step1,step2));
	}

	std::pair < int , int > getPair(int id) const{
		return m_pairs.at(id);
	}

	int getStep1(int id) const{
		return m_pairs.at(id).first;
	}

	int getStep2(int id) const{
		return m_pairs.at(id).second;
	}

	ClassDef(TTofpetSetup,1);
};


#endif
