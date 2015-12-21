#ifndef TTOFPETSETUP_HG
#define TTOFPETSETUP_HG

#include "TObject.h"
#include <vector>
#include <map>
#include <utility>


class TTofpetRun:public TObject{

private:

	std::vector < std::pair < int , int > > m_pairs;
	std::map < std::pair <int , int > , int > m_pairsNevents;
	std::vector < int > m_steps1;
	std::vector < int > m_steps2;

public:

	TTofpetRun();


	int getNsteps() const {
		return m_pairs.size();
	}

	int getNsteps1() const {
			return m_steps1.size();
		}

	int getNsteps2() const {
		return m_steps1.size();
	}


	void addPair(int step1,int step2,int N=0);

	std::pair < int , int > getPair(int id) const{
		return m_pairs.at(id);
	}

	int getStep1(int id) const{
		return m_pairs.at(id).first;
	}

	int getStep2(int id) const{
		return m_pairs.at(id).second;
	}

	int getStepID(int step1,int step2) const;
	int getStep1ID(int step1) const;

	int getStepNevents(int step1,int step2) const;

	ClassDef(TTofpetRun,1);
};


#endif
