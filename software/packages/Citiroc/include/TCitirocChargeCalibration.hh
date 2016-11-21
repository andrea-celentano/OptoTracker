#ifndef TCITIROC_CHARGE_CALIBRATION_HG
#define TCITIROC_CHARGE_CALIBRATION_HG

#include "TObject.h"
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
class TGNumberEntry;
class TLine;



class TH1D;
class TGraphErrors;
class TF1;
class TCanvas;

class TCitirocChargeCalibrationGui;

class TCitirocChargeCalibration : public TObject{



private:


	std::map<std::pair<int,int>,TH1D*> m_hQ; //key is boardID - chID.

	TCitirocChargeCalibrationGui *m_TCitirocChargeCalibrationGui;


	/*To fit*/
	Float_t FitGains(TH1D *h);
	Double_t x[50], ex[50];
	Double_t y[50], ey[50];

	Double_t gx[50], gex[50];
	Double_t gy[50], gey[50];
	TGraphErrors* grpeaks;
	TF1* fit;



public:

	TCitirocChargeCalibration();
	virtual ~TCitirocChargeCalibration();

	template <typename T> int addObject(int ID,int ch,T* obj,std::map<std::pair<int,int>,T*> &map);
	template <typename T> T* getObject(int ID,int ch,const std::map<std::pair<int,int>,T*> &map) const;
	template <typename T> void printObject(const std::map<std::pair<int,int>,T*> &map) const;

	int addhChargeRaw(int ID,int ch,TH1D* h){return this->addObject(ID,ch,h,this->m_hQ);}
	TH1D* gethChargeRaw(int ID,int ch){return this->getObject(ID,ch,this->m_hQ);}




	int getChannels(){return m_hQ.size();}


	int doCalibrationGui();

	ClassDef(TCitirocChargeCalibration,1);

};





/*These have to be here since the compiler must always see the template-implementation in order to generate the proper code*/
template <typename T> int TCitirocChargeCalibration::addObject(int ID,int ch,T* obj,std::map<std::pair<int,int>,T*> &map){

	std::pair<int,int> key=std::make_pair(ID,ch);


	std::pair<typename std::map<std::pair<int,int>,T*>::iterator,bool> ret=map.insert(std::make_pair(key,obj));
	if ((ret.second)==true) return 0;
	else{
		Error("addObject","something went wrong!");
		return -1;
	}
}

template <typename T> T* TCitirocChargeCalibration::getObject(int ID,int ch,const std::map<std::pair<int,int>,T*> &map) const{
	typename std::map<std::pair<int,int>,T*>::const_iterator it;
	std::pair<int,int>  key=std::make_pair(ID,ch);

	it = map.find(key);
	if (it==map.end()){
		Error("getObject","object with ID: %i , ch: %i not found",ID,ch);
		return 0;
	}
	else return (it->second);
}

template <typename T> void TCitirocChargeCalibration::printObject(const std::map<std::pair<int,int>,T*> &map) const{
	typename std::map<std::pair<int,int>,T*>::const_iterator it;
	int ch;
	std::pair<int,int>  key;
	std::string name,title;
	Info("printObject","There are %i objects",map.size());
	for (it=map.begin();it!=map.end();it++){
		key=(*it).first;
		name=(*it).second->GetName();
		title=(*it).second->GetTitle();
		Info("printObject","got Object: %i %i - %s %s",key.first,key.second,name.c_str(),title.c_str());
	}
	return;
}









class TCitirocChargeCalibrationGui:public TGCanvas{

public:
	TCitirocChargeCalibrationGui(TCitirocChargeCalibration *CitirocChargeCalibration,const TGWindow *p,UInt_t w,UInt_t h);
	TCitirocChargeCalibrationGui(){Info("TCitirocChargeCalibrationGui","Dummy creator");}
	void Start();

private:
	TCitirocChargeCalibration *m_TCitirocChargeCalibration;

	/*Graphics*/
	TGMainFrame *fMain;
	TRootEmbeddedCanvas *fEcanvas;
	TGTextButton *fNext,*fPrev,*fSave,*fNextAndSave;
	TGHorizontalFrame *fFrame;
	TGNumberEntry *fThr;
	TGNumberEntry *fCh;

	TLine *lThr1,*lThr2,*lThr3,*lThr4;

	TCanvas *m_canvas;

	int m_curChannel;
	int m_curID;


public:
	void Prev();
	void Next();
	void Refresh();
	void Save(int nphe=2);
	void NextAndSave();
	void RefreshThrWidgetValue();
	void RefreshChWidgetValue();
	void fThrChanged();

	void GoToChannel(Long_t ch);

	ClassDef(TCitirocChargeCalibrationGui,1);


};






#endif
