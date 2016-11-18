/*
 * TCitirocChargeCalibrationGui.cc
 *
 *  Created on: Jan 14, 2016
 *      Author: celentan
 */

#include "TCitirocChargeCalibration.hh"
#include "TCitirocSetupHandler.hh"
#include "TRootEmbeddedCanvas.h"
#include "TGFrame.h"
#include "TGButton.h"
#include "TGNumberEntry.h"
#include "TLine.h"
#include "TCanvas.h"
#include "TH1D.h"
TCitirocChargeCalibrationGui::TCitirocChargeCalibrationGui(TCitirocChargeCalibration *CitirocChargeCalibration,const TGWindow *p,UInt_t w,UInt_t h):
m_TCitirocChargeCalibration(CitirocChargeCalibration),m_curChannel(0)
{
	lThr1=0;
	lThr2=0;
	lThr3=0;
	lThr4=0;
	// Create a main frame
	fMain = new TGMainFrame(p,w,h);
	// Create canvas widget
	fEcanvas = new TRootEmbeddedCanvas("Ecanvas",fMain,w,h-20);
	fMain->AddFrame(fEcanvas, new TGLayoutHints(kLHintsExpandX| kLHintsExpandY,10,10,10,1));

	//Buttons

	TGHorizontalFrame *hframe = new TGHorizontalFrame(fMain,200,40);


	fThr = new TGNumberEntry(hframe, 0, 2, 0,
			TGNumberFormat::kNESInteger, //style
			TGNumberFormat::kNEANonNegative, //input value filter
			TGNumberFormat::kNELLimitMinMax, //specify limits
			0,63); //limit values
	fThr->Connect("ValueSet(Long_t)","TCitirocChargeCalibrationGui",this,"fThrChanged()");
	fThr->Connect("ValueChanged(Long_t)","TCitirocChargeCalibrationGui",this,"fThrChanged()");
	hframe->AddFrame(fThr, new TGLayoutHints(kLHintsCenterX,5,5,3,4));


	fNextAndSave=new TGTextButton(hframe,"NextAndSave");
	fNextAndSave->Connect("Clicked()","TCitirocChargeCalibrationGui",this,"NextAndSave()");
	hframe->AddFrame(fNextAndSave, new TGLayoutHints(kLHintsCenterX,5,5,3,4));

	fSave=new TGTextButton(hframe,"Save");
	fSave->Connect("Clicked()","TCitirocChargeCalibrationGui",this,"Save(=2)");
	hframe->AddFrame(fSave, new TGLayoutHints(kLHintsCenterX,5,5,3,4));

	fNext=new TGTextButton(hframe,"Next");
	fNext->Connect("Clicked()","TCitirocChargeCalibrationGui",this,"Next()");
	hframe->AddFrame(fNext, new TGLayoutHints(kLHintsCenterX,5,5,3,4));

	fCh = new TGNumberEntry(hframe, 0, 2, 0,
			TGNumberFormat::kNESInteger, //style
			TGNumberFormat::kNEANonNegative, //input value filter
			TGNumberFormat::kNELLimitMinMax, //specify limits
			0,m_TCitirocChargeCalibration->getChannels()); //limit values

	fCh->Connect("ValueSet(Long_t)","TCitirocChargeCalibrationGui",this,"GoToChannel(Long_t)");
	fCh->Connect("ValueChanged(Long_t)","TCitirocChargeCalibrationGui",this,"GoToChannel(Long_t)");
	hframe->AddFrame(fCh, new TGLayoutHints(kLHintsCenterX,5,5,3,4));

	fPrev=new TGTextButton(hframe,"&Prev");
	fPrev->Connect("Clicked()","TCitirocChargeCalibrationGui",this,"Prev()");
	hframe->AddFrame(fPrev, new TGLayoutHints(kLHintsCenterX,5,5,3,4));

	fMain->AddFrame(hframe, new TGLayoutHints(kLHintsCenterX,2,2,2,2));

	// Map all subwindows of main frame
	fMain->MapSubwindows();
	// Initialize the layout algorithm
	fMain->Resize(fMain->GetDefaultSize());
	// Map main frame
	fMain->MapWindow();



	m_canvas = fEcanvas->GetCanvas();
	m_canvas->Divide(2,2);
}


void TCitirocChargeCalibrationGui::Start(){
	m_curChannel=0;
	m_curID=0;
	while (m_TCitirocChargeCalibration->gethChargeRaw(m_curID,m_curChannel)==0){
		m_curChannel++;
		if (m_curChannel==TCitirocSetupHandler::nCitirocChannelsPerBoard){
			m_curID++;
			m_curChannel=0;
		}
	}
	this->Refresh();
}

void TCitirocChargeCalibrationGui::Refresh(){
	m_canvas = fEcanvas->GetCanvas();
	m_canvas->cd();
	if(m_TCitirocChargeCalibration->gethChargeRaw(m_curID,m_curChannel)!=0){
		/*Here draw the canvas*/
		int thr_tmp;


		int firstBin,lastBin;

		m_canvas->cd(1);

		m_TCitirocChargeCalibration->gethChargeRaw(m_curID,m_curChannel)->Draw();





		m_canvas->cd(2);


		m_canvas->cd(3)->SetLogy();


		m_canvas->cd(4);


		m_canvas->Modified();
		m_canvas->Update();
	}
	else{
		Error("Refresh","no data for board:%i ch: %i",m_curID,m_curChannel);
	}
}
void TCitirocChargeCalibrationGui::Save(int nphe){
	//	Info("Save","saving thr for ch: %i at %i with %i phe",m_curChannel,m_curThr,nphe);
	//	m_TCitirocChargeCalibration->setCharge(m_curChannel,m_curThr,nphe);
	//m_TCitirocChargeCalibration->dumpCharges();
}

void TCitirocChargeCalibrationGui::NextAndSave(){
	Save();
	Next();
}

void TCitirocChargeCalibrationGui::GoToChannel(Long_t ch){
	ch=fCh->GetIntNumber();
	if (ch<0) return;
	else if (ch>(m_TCitirocChargeCalibration->getChannels()-1)) return;
	else{
		m_curChannel=ch;
		//m_curThr=m_TCitirocChargeCalibration->getCharge(m_curChannel);
		Info("GoToChannel","cur channel now is: %i",m_curChannel);
		RefreshThrWidgetValue();
		Refresh();
	}
}


void TCitirocChargeCalibrationGui::Next(){
	int m_tmp;
	m_tmp=m_curChannel+m_curID*TCitirocSetupHandler::nCitirocChannelsPerBoard;
	if (m_tmp==(m_TCitirocChargeCalibration->getChannels()-1)) return; //do nothing

	m_curChannel++;
	if (m_curChannel==TCitirocSetupHandler::nCitirocChannelsPerBoard){
		m_curChannel=0;
		m_curID++;
	}

	Info("Next","ID/Channel now is: %i %i",m_curID,m_curChannel);
	RefreshChWidgetValue();
	RefreshThrWidgetValue();
	Refresh();

}


void TCitirocChargeCalibrationGui::Prev(){
	if ((m_curChannel==0)&&(m_curID==0)) return;
	else if (m_curChannel==0){
		m_curChannel=TCitirocSetupHandler::nCitirocChannelsPerBoard-1;
		m_curID--;
	}
	else{
		m_curChannel--;
	}
	Info("Prev","cur ID-channel  now is: %i %i",m_curID,m_curChannel);
	RefreshChWidgetValue();
	RefreshThrWidgetValue();
	Refresh();

}

void TCitirocChargeCalibrationGui::RefreshThrWidgetValue(){
	//fThr->SetIntNumber(m_TCitirocChargeCalibration->getCharge(m_curChannel));
}
void TCitirocChargeCalibrationGui::RefreshChWidgetValue(){
	fCh->SetIntNumber(m_curChannel);
}


void  TCitirocChargeCalibrationGui::fThrChanged(){
//	Info("fThrChanged","thr now: %i",m_curThr);
//	m_curThr=fThr->GetIntNumber();
	Refresh();
}
