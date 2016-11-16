#include "TTofpetRun.hh"
#include <algorithm>
#include <vector>
#include <utility>
#include <iostream>
using namespace std;

TTofpetRun::TTofpetRun(){
}

void TTofpetRun::addPair(int step1,int step2,int N){
	m_pairs.push_back(std::make_pair(step1,step2));
	m_pairsNevents.insert(std::make_pair(std::make_pair(step1,step2),N));
	if (find(m_steps1.begin(),m_steps1.end(),step1)==m_steps1.end()){
		m_steps1.push_back(step1);
	}
	if (find(m_steps2.begin(),m_steps2.end(),step2)==m_steps2.end()){
		m_steps2.push_back(step1);
	}


}

int TTofpetRun::getStepID(int step1,int step2) const{
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


int TTofpetRun::getStepNevents(int step1,int step2) const{
	int ret=0;

	map< pair<int,int> , int >::const_iterator it;
	it = m_pairsNevents.find(std::make_pair(step1,step2));

	if (it == m_pairsNevents.end()){
		Error("getStepNevents","Step with step1=%i and step2=%i not found",step1,step2);
		ret=-1;
	}
	else  ret=it->second;
	return ret;
}





int TTofpetRun::getStep1ID(int step1) const{
	int ret=0;

	vector< int >::const_iterator it;
	it = find(m_steps1.begin(),m_steps1.end(),step1);

	if (it == m_steps1.end()){
		Error("getStep1ID","Step with step1=%i not found",step1);
		ret=-1;
	}
	else  ret=std::distance((m_steps1.begin()), it);
	return ret;
}
