#ifndef TTOFPETSETUP_HG
#define TTOFPETSETUP_HG

#include "TObject.h"
#include <vector>
#include <utility>


class TTofpetSetup:public TObject{

private:

	std::vector < std::pair < int , int > > m_pairs;
	std::vector < int > m_steps1;
	std::vector < int > m_steps2;

public:

	TTofpetSetup();


	int getNsteps() const {
		return m_pairs.size();
	}

	int getNsteps1() const {
			return m_steps1.size();
		}

	int getNsteps2() const {
		return m_steps1.size();
	}


	void addPair(int step1,int step2);

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

	ClassDef(TTofpetSetup,1);
};


#endif
