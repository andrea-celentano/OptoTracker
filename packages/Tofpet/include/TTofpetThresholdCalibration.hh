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
	std::map<int,TH1D*> m_hRateRaw;
	std::map<int,TH1D*> m_hRateDerived;
	std::map<int,TGraph*> m_gThr;
	std::map<int,TGraph*> m_gRateVsThr;

	//this is the histogram for the ToT vs THR
	std::map<int,TH2D*> m_hToTvsThr;
	std::map<int,TH1D*> m_hToT;

	std::map<int,std::vector<int> > m_transitions;  //each val in the vector, at the position i, corresponds to the transition i->i+1.
	std::map<int,double> m_rateSinglePhe;

	std::map<int,int> m_RawThresholds;
	std::map<int,int> m_Thresholds;

	std::map<int,std::string> m_ThresholdsDate;

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
	template <typename T> int addObject(int ch,T* obj,std::map<int,T*> &map);

	int addhRateRaw(int ch,TH1D* h){return this->addObject(ch,h,this->m_hRateRaw);}
	int addhRateDerived(int ch,TH1D* h){return this->addObject(ch,h,this->m_hRateDerived);};
	int addgThr(int ch,TGraph* g){return this->addObject(ch,g,this->m_gThr);};
	int addgRateVsThr(int ch,TGraph* g){return this->addObject(ch,g,this->m_gRateVsThr);};
	int addhToT(int ch,TH1D* h){return this->addObject(ch,h,this->m_hToT);};
	int addhToTvsThr(int ch,TH2D* h){return this->addObject(ch,h,this->m_hToTvsThr);};

	template <typename T> T* getObject(int ch,const std::map<int,T*> &map) const;

	TH1D* gethRateRaw(int ch) const{return this->getObject(ch,this->m_hRateRaw);}
	TH1D* gethRateDerived(int ch) const{return this->getObject(ch,this->m_hRateDerived);}
	TGraph* getgThr(int ch)const{return this->getObject(ch,this->m_gThr);}
	TGraph* getgRateVsThr(int ch)const{return this->getObject(ch,this->m_gRateVsThr);}

	TH2D* gethToTvsThr(int ch)const{return this->getObject(ch,this->m_hToTvsThr);}
	TH1D* gethToT(int ch)const{return this->getObject(ch,this->m_hToT);}

	template <typename T> void printObject(const std::map<int,T*> &map) const;
	void printhRateRaw() const{return this->printObject(this->m_hRateRaw);}
	void printhRateDerived() const{return this->printObject(this->m_hRateDerived);}
	void printgThr()const{return this->printObject(this->m_gThr);}

	/*Analysis methods*/
	void computeRateDerived(int ch);
	void computeThresholds(int ch);


	int getNtransitions(int ch) const;
	/*This method returns the threshold corresponding to the transition between nphe and nphe+1 */
	int getTransition(int ch,int nphe) const;
	void printTransitions(int nphe1,int nphe2) const;
	/*This method returns the threshold corresponding to  PHE_THR phe*/
	bool hasFinalThreshold(int ch) const;
	int getThreshold(int ch,bool forceRaw=false) const;
	void setThreshold(int ch,int thr);
	void dumpThresholds(std::string fname="thr.dat") const;


	int computeThresholdFromRateTransitions(int ch,int nphe) const;
	void printThresholds(int nphe1,int nphe2) const;

	/*In the do_dump_sipm.thrDetermination.py script (DAQ repository) this is also used (txs to pyRoot from this class!)*/
	int getDAQRunThreshold(int ch, int step2) const;

	/*The interactive analysis methods for a channel*/
	TCanvas* getInteractiveCanvas(int ch);
	int decideThresholdDummy(int ch);
	int decideThresholds();


	ClassDef(TTofpetThresholdCalibration,2);

};

/*These have to be here since the compiler must always see the template-implementation in order to generate the proper code*/
template <typename T> int TTofpetThresholdCalibration::addObject(int ch,T* obj,std::map<int,T*> &map){
	std::pair<typename std::map<int,T*>::iterator,bool> ret=map.insert(std::make_pair(ch,obj));
	if ((ret.second)==true) return 0;
	else{
		Error("addObject","something went wrong!");
		return -1;
	}
}

template <typename T> T* TTofpetThresholdCalibration::getObject(int ch,const std::map<int,T*> &map) const{
	typename std::map<int,T*>::const_iterator it;
	it = map.find(ch);
	if (it==map.end()){
		Error("gethRate","histogram with ch: %i not found",ch);
		return 0;
	}
	else return (it->second);
}

template <typename T> void TTofpetThresholdCalibration::printObject(const std::map<int,T*> &map) const{
	typename std::map<int,T*>::const_iterator it;
	int ch;
	std::string name,title;
	Info("printObject","There are %i objects",map.size());
	for (it=map.begin();it!=map.end();it++){
		ch=(*it).first;
		name=(*it).second->GetName();
		title=(*it).second->GetTitle();
		Info("printObject","got Object: %i %s %s",ch,name.c_str(),title.c_str());
	}
	return;
}






class TTofpetThresholdCalibrationGui:public TGCanvas{
public:
	TTofpetThresholdCalibrationGui(TTofpetThresholdCalibration *TofpetThresholdCalibration,const TGWindow *p,UInt_t w,UInt_t h);
	TTofpetThresholdCalibrationGui(){Info("TTofpetThresholdCalibrationGui","Dummy creator");}
	void Start();

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
