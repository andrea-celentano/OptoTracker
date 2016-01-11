/*
 * TTofpetChargeCalibration.hh
 *
 *  Created on: Dec 29, 2015
 *      Author: celentan
 */

#ifndef TTOFPETTHRCALIBRATION_HH_
#define TTOFPETTHRCALIBRATION_HH_

#include "TObject.h"
#include "TH1D.h"
#include "TGraph.h"
#include <algorithm>
#include <utility>
#include <map>
#include <string>
#include <iostream>


class TTofpetThresholdCalibration : public TObject {

private:
	std::map<std::pair<int,int>,TH1D*> m_hRateRaw;
	std::map<std::pair<int,int>,TH1D*> m_hRateDerived;
	std::map<std::pair<int,int>,TGraph*> m_gThr;

	std::map<std::pair<int,int>,std::vector<int> > m_transitions;  //each val in the vector, at the position i, corresponds to the transition i->i+1.
	std::map<std::pair<int,int>,double> m_rateSinglePhe;


	static const int BIN_MIN=10;
	static const int MAX_RATE=(int)5E6; //for sure the thermal single phe are less than this
	static const int MAX_SCALE=63;
public:


	TTofpetThresholdCalibration();
	virtual ~TTofpetThresholdCalibration();


	/*Methods to fill the maps*/
	template <typename T> int addObject(int ch,int step1,T* obj,std::map<std::pair<int,int>,T*> &map);

	int addhRateRaw(int ch,int step1,TH1D* h){return this->addObject(ch,step1,h,this->m_hRateRaw);}
	int addhRateDerived(int ch,int step1,TH1D* h){return this->addObject(ch,step1,h,this->m_hRateDerived);};
	int addgThr(int ch,int step1,TGraph* g){return this->addObject(ch,step1,g,this->m_gThr);};



	template <typename T> T* getObject(int ch,int step1,const std::map<std::pair<int,int>,T*> &map) const;

	TH1D* gethRateRaw(int ch,int step1) const{return this->getObject(ch,step1,this->m_hRateRaw);}
	TH1D* gethRateDerived(int ch,int step1) const{return this->getObject(ch,step1,this->m_hRateDerived);}
	TGraph* getgThr(int ch,int step1)const{return this->getObject(ch,step1,this->m_gThr);}

	template <typename T> void printObject(const std::map<std::pair<int,int>,T*> &map) const;
	void printhRateRaw() const{return this->printObject(this->m_hRateRaw);}
	void printhRateDerived() const{return this->printObject(this->m_hRateDerived);}
	void printgThr()const{return this->printObject(this->m_gThr);}

	/*Analysis methods*/
	void computeRateDerived(int ch,int step1);
	void computeThresholds(int ch,int step1);


	int getNtransitions(int ch,int step1) const;
	/*This method returns the threshold corresponding to the transition between nphe and nphe+1 */
	int getTransition(int ch,int step1,int nphe) const;
	void printTransitions(int step1,int nphe1,int nphe2) const;

	/*This method returns the threshold corresponding to nphe*/
	int getThreshold(int ch,int step1,int nphe) const;
	void printThresholds(int step1,int nphe1,int nphe2) const;

	ClassDef(TTofpetThresholdCalibration,1);

};

/*These have to be here since the compiler must always see the template-implementation in order to generate the proper code*/


template <typename T> int TTofpetThresholdCalibration::addObject(int ch,int step1,T* obj,std::map<std::pair<int,int>,T*> &map){
	std::pair<typename std::map<std::pair<int,int>,T*>::iterator,bool> ret=map.insert(std::make_pair(std::pair<int,int>(ch,step1),obj));
	if ((ret.second)==true) return 0;
	else{
		Error("addObject","something went wrong!");
		return -1;
	}
}

template <typename T> T* TTofpetThresholdCalibration::getObject(int ch,int step1,const std::map<std::pair<int,int>,T*> &map) const{
	typename std::map<std::pair<int,int>,T*>::const_iterator it;

	it = map.find(std::make_pair(ch,step1));
	if (it==map.end()){
		Error("gethRate","histogram with ch: %i and step1: %i not found",ch,step1);
		return 0;
	}
	else return (it->second);
}

template <typename T> void TTofpetThresholdCalibration::printObject(const std::map<std::pair<int,int>,T*> &map) const{
	typename std::map<std::pair<int,int>,T*>::const_iterator it;
	int ch,step1;
	std::string name,title;
	Info("printObject","There are %i objects",map.size());
	for (it=map.begin();it!=map.end();it++){
		ch=(*it).first.first;
		step1=(*it).first.second;
		name=(*it).second->GetName();
		title=(*it).second->GetTitle();
		Info("printObject","got Object: %i %i %s %s",ch,step1,name.c_str(),title.c_str());
	}
	return;
}


#endif /* TTOFPETCHARGECALIBRATION_HH_ */
