#include "TTofpetSetup.hh"
#include <algorithm>
#include <vector>
#include <utility>
#include <iostream>
using namespace std;

TTofpetSetup::TTofpetSetup(){


	m_Nsteps1=m_steps1.size();
	m_Nsteps2=m_steps2.size();

	Info("TTofpetSetup","number of steps1: %i -- number of steps2: %i",m_Nsteps1,m_Nsteps2);
}

void TTofpetSetup::addPair(int step1,int step2){
	m_pairs.push_back(std::make_pair(step1,step2));
	m_steps1.push_back(step1);
	m_steps2.push_back(step2);
}

int TTofpetSetup::getStepID(int step1,int step2) const{
	int ret=0;

	vector< pair<int,int> >::const_iterator it;
	it = find(m_pairs.begin(),m_pairs.end(),std::make_pair(step1,step2));

	if (it == m_pairs.end()){
		Error("getStepID","Step with step1=%i and step2=%i not found",step1,step2);
		ret=-1;
	}
	else  ret=std::distance((m_pairs.begin()), it);
	return ret;
}

