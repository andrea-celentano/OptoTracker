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
#include "TH2D.h"
#include "TGraph.h"
#include "TCanvas.h"
#include "TList.h"
#include "TCollection.h"
#include <algorithm>
#include <utility>
#include <map>
#include <string>
#include <iostream>
#include <fstream>

#include "TGCanvas.h"
class TRootEmbeddedCanvas;
class TGTextButton;
class TGHorizontalFrame;
class TTofpetThresholdCalibrationGui;
class TGNumberEntry;
class TLine;

class TTofpetThresholdCalibration : public TObject {

private:

	//These are the plots for the dark rate measurement
	std::map<std::pair<int,int>,TH1D*> m_hRateRaw;
	std::map<std::pair<int,int>,TH1D*> m_hRateDerived;
	std::map<std::pair<int,int>,TGraph*> m_gThr;
	std::map<std::pair<int,int>,TGraph*> m_gRateVsThr;

	//this is the histogram for the ToT vs THR
	std::map<std::pair<int,int>,TH2D*> m_hToTvsThr;
	std::map<std::pair<int,int>,TH1D*> m_hToT;

	std::map<std::pair<int,int>,std::vector<int> > m_transitions;  //each val in the vector, at the position i, corresponds to the transition i->i+1.
	std::map<std::pair<int,int>,double> m_rateSinglePhe;

	std::map<std::pair<int,int>,int> m_RawThresholds;
	std::map<std::pair<int,int>,int> m_Thresholds;

	std::map<std::pair<int,int>,std::string> m_ThresholdsDate;

	TList *m_c_interactive;

	static const int BIN_MIN=10;
	static const int MAX_RATE=(int)5E6; //for sure the thermal single phe are less than this
	static const int MAX_SCALE=63;

	static const int PHE_THR=2;


public:



	TTofpetThresholdCalibrationGui *m_TTofpetThresholdCalibrationGui;


	TTofpetThresholdCalibration();
	virtual ~TTofpetThresholdCalibration();


	/*Methods to fill the maps*/
	template <typename T> int addObject(int ch,int step1,T* obj,std::map<std::pair<int,int>,T*> &map);

	int addhRateRaw(int ch,int step1,TH1D* h){return this->addObject(ch,step1,h,this->m_hRateRaw);}
	int addhRateDerived(int ch,int step1,TH1D* h){return this->addObject(ch,step1,h,this->m_hRateDerived);};
	int addgThr(int ch,int step1,TGraph* g){return this->addObject(ch,step1,g,this->m_gThr);};
	int addgRateVsThr(int ch,int step1,TGraph* g){return this->addObject(ch,step1,g,this->m_gRateVsThr);};
	int addhToT(int ch,int step1,TH1D* h){return this->addObject(ch,step1,h,this->m_hToT);};
	int addhToTvsThr(int ch,int step1,TH2D* h){return this->addObject(ch,step1,h,this->m_hToTvsThr);};

	template <typename T> T* getObject(int ch,int step1,const std::map<std::pair<int,int>,T*> &map) const;

	TH1D* gethRateRaw(int ch,int step1) const{return this->getObject(ch,step1,this->m_hRateRaw);}
	TH1D* gethRateDerived(int ch,int step1) const{return this->getObject(ch,step1,this->m_hRateDerived);}
	TGraph* getgThr(int ch,int step1)const{return this->getObject(ch,step1,this->m_gThr);}
	TGraph* getgRateVsThr(int ch,int step1)const{return this->getObject(ch,step1,this->m_gRateVsThr);}

	TH2D* gethToTvsThr(int ch,int step1)const{return this->getObject(ch,step1,this->m_hToTvsThr);}
	TH1D* gethToT(int ch,int step1)const{return this->getObject(ch,step1,this->m_hToT);}

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
	/*This method returns the threshold corresponding to  PHE_THR phe*/
	bool hasFinalThreshold(int ch,int step1) const;
	int getThreshold(int ch,int step1,bool forceRaw=false) const;
	void setThreshold(int ch,int step1,int thr);
	void dumpThresholds(int step1,std::string fname="thr.dat") const;


	int computeThresholdFromRateTransitions(int ch,int step1,int nphe) const;
	void printThresholds(int step1,int nphe1,int nphe2) const;

	/*In the do_dump_sipm.thrDetermination.py script (DAQ repository) this is also used (txs to pyRoot from this class!)*/
	int getDAQRunThreshold(int ch,int step1, int step2) const;

	/*The interactive analysis methods for a channel*/
	TCanvas* getInteractiveCanvas(int ch,int step1);
	int decideThresholdDummy(int ch,int step1);
	int decideThresholds(int step1);


	ClassDef(TTofpetThresholdCalibration,2);

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






class TTofpetThresholdCalibrationGui:public TGCanvas{
public:
	TTofpetThresholdCalibrationGui(TTofpetThresholdCalibration *TofpetThresholdCalibration,const TGWindow *p,UInt_t w,UInt_t h);
	TTofpetThresholdCalibrationGui(){Info("TTofpetThresholdCalibrationGui","Dummy creator");}
	void Start(int step1);

private:
	TTofpetThresholdCalibration *m_TTofpetThresholdCalibration;

	/*Graphics*/
	TGMainFrame *fMain;
	TRootEmbeddedCanvas *fEcanvas;
	TGTextButton *fNext,*fPrev,*fSave,*fNextAndSave;
	TGHorizontalFrame *fFrame;
	TGNumberEntry *fThr;

	TLine *lThr1,*lThr2,*lThr3,*lThr4;

	TCanvas *m_canvas;

	int m_curChannel;
	int m_curThr;
	int m_step1;

public:
	void Prev();
	void Next();
	void Refresh();
	void Save();
	void NextAndSave();
	void RefreshThrWidgetValue();
	void fThrChanged();

	ClassDef(TTofpetThresholdCalibrationGui,1);


};








#endif /* TTOFPETCHARGECALIBRATION_HH_ */
