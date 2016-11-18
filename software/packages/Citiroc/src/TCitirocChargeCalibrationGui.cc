/*
 * TCitirocChargeCalibrationGui.cc
 *
 *  Created on: Jan 14, 2016
 *      Author: celentan
 */

#include "TCitirocChargeCalibration.hh"

#include "TRootEmbeddedCanvas.h"
#include "TGFrame.h"
#include "TGButton.h"
#include "TGNumberEntry.h"
#include "TLine.h"

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
	m_curThr=m_TCitirocChargeCalibration->getCharge(m_curChannel);
	RefreshThrWidgetValue();
	this->Refresh();
}

void TCitirocChargeCalibrationGui::Refresh(){
	m_canvas = fEcanvas->GetCanvas();
	m_canvas->cd();
	if(m_TCitirocChargeCalibration->gethToTvsThr(m_curChannel)!=0){
		/*Here draw the canvas*/
		int thr_tmp;
		double maxDrawY,minDrawY;
		double maxDrawX,minDrawX;
		int firstBin,lastBin;
		maxDrawY=m_TCitirocChargeCalibration->getDAQRunCharge(m_curChannel,0);
		minDrawY=m_TCitirocChargeCalibration->getDAQRunCharge(m_curChannel,20);

		m_canvas->cd(1);

		m_TCitirocChargeCalibration->gethToTvsThr(m_curChannel)->GetYaxis()->SetRangeUser(minDrawY,maxDrawY);
		m_TCitirocChargeCalibration->gethToTvsThr(m_curChannel)->Draw("colz");

		minDrawX=m_TCitirocChargeCalibration->gethToTvsThr(m_curChannel)->GetXaxis()->GetXmin();
		maxDrawX=m_TCitirocChargeCalibration->gethToTvsThr(m_curChannel)->GetXaxis()->GetXmax();

		if (lThr1) delete lThr1;



		thr_tmp=m_TCitirocChargeCalibration->getTransition(m_curChannel,1);
		if (lThr2) delete lThr2;

		lThr2=new TLine(minDrawX,thr_tmp,maxDrawX,thr_tmp);
		lThr2->SetLineColor(3);
		lThr2->SetLineWidth(2);
		lThr2->Draw("SAME");

		thr_tmp=m_TCitirocChargeCalibration->getTransition(m_curChannel,2);
		if (lThr3) delete lThr3;
		lThr3=new TLine(minDrawX,thr_tmp,maxDrawX,thr_tmp);
		lThr3->SetLineColor(3);
		lThr3->SetLineWidth(2);
		lThr3->Draw("SAME");

		lThr1=new TLine(minDrawX,m_curThr,maxDrawX,m_curThr);
		if (m_TCitirocChargeCalibration->hasFinalCharge(m_curChannel)){
			lThr1->SetLineColor(2);
			lThr1->SetLineWidth(3);
		}
		else{
			lThr1->SetLineColor(4);
			lThr1->SetLineWidth(2);
		}

		lThr1->Draw("SAME");



		m_canvas->cd(2);
		firstBin=m_curThr+1;
		lastBin=m_curThr+1;
		m_TCitirocChargeCalibration->gethToTvsThr(m_curChannel)->ProjectionX(Form("hToT0_ch:%i_proj",m_curChannel),firstBin,lastBin)->Draw();

		m_canvas->cd(3)->SetLogy();
		maxDrawY=m_TCitirocChargeCalibration->gethRateRaw(m_curChannel)->GetMaximum()*1.1;
		minDrawY=1;
		m_TCitirocChargeCalibration->gethRateRaw(m_curChannel)->Draw();

		if (lThr4) delete lThr4;
		lThr4=new TLine(m_curThr,minDrawY,m_curThr,maxDrawY);
		lThr4->SetLineColor(2);
		lThr4->SetLineWidth(2);
		lThr4->Draw("SAME");

		m_canvas->cd(4);
		m_TCitirocChargeCalibration->getgThr(m_curChannel)->Draw("AP");

		m_canvas->Modified();
		m_canvas->Update();
	}
	else{
		Error("Refresh","no data for ch: %i",m_curChannel);
	}
}
void TCitirocChargeCalibrationGui::Save(int nphe){
	Info("Save","saving thr for ch: %i at %i with %i phe",m_curChannel,m_curThr,nphe);
	m_TCitirocChargeCalibration->setCharge(m_curChannel,m_curThr,nphe);
	m_TCitirocChargeCalibration->dumpCharges();
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
		m_curThr=m_TCitirocChargeCalibration->getCharge(m_curChannel);
		Info("GoToChannel","cur channel now is: %i",m_curChannel);
		RefreshThrWidgetValue();
		Refresh();
	}
}


void TCitirocChargeCalibrationGui::Next(){

	if (m_curChannel==(m_TCitirocChargeCalibration->getChannels()-1)) return;
	m_curChannel++;
	m_curThr=m_TCitirocChargeCalibration->getCharge(m_curChannel);
	Info("Next","cur channel now is: %i",m_curChannel);
	RefreshChWidgetValue();
	RefreshThrWidgetValue();
	Refresh();

}


void TCitirocChargeCalibrationGui::Prev(){
	if (m_curChannel==0) return;
	m_curChannel--;
	m_curThr=m_TCitirocChargeCalibration->getCharge(m_curChannel);
	Info("Prev","cur channel now is: %i",m_curChannel);
	RefreshChWidgetValue();
	RefreshThrWidgetValue();
	Refresh();

}

void TCitirocChargeCalibrationGui::RefreshThrWidgetValue(){
	fThr->SetIntNumber(m_TCitirocChargeCalibration->getCharge(m_curChannel));
}
void TCitirocChargeCalibrationGui::RefreshChWidgetValue(){
	fCh->SetIntNumber(m_curChannel);
}


void  TCitirocChargeCalibrationGui::fThrChanged(){
	Info("fThrChanged","thr now: %i",m_curThr);
	m_curThr=fThr->GetIntNumber();
	Refresh();
}
