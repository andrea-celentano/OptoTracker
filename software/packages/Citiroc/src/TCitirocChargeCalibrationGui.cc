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
#include "TGLabel.h"
#include "TLine.h"
#include "TGScrollBar.h"
#include "TGDoubleSlider.h"
#include "TCanvas.h"
#include "TH1D.h"
#include "TGraphErrors.h"
#include "TAxis.h"

TCitirocChargeCalibrationGui::TCitirocChargeCalibrationGui(TCitirocChargeCalibration *CitirocChargeCalibration,const TGWindow *p,UInt_t w,UInt_t h):
m_TCitirocChargeCalibration(CitirocChargeCalibration),m_curChannel(0)
{
	lThr1=0;
	lThr2=0;
	lThr3=0;
	lThr4=0;
	m_curChannel=0;
	m_curBoard=0;
	// main frame
	fMain = new TGMainFrame(gClient->GetRoot(),10,10,kMainFrame | kVerticalFrame);
	fMain->SetName("fMain");
	fMain->SetLayoutBroken(kTRUE);

	// vertical frame
	fVerticalFrame = new TGVerticalFrame(fMain,912,64,kVerticalFrame);
	fVerticalFrame->SetName("fVerticalFrame");
	fVerticalFrame->SetLayoutBroken(kTRUE);

	TGFont *ufont;         // will reflect user font changes
	ufont = gClient->GetFont("-*-liberation serif-bold-r-*-*- 0-*-*-*-*-*-*-*");

	TGGC   *uGC;           // will reflect user GC changes
	// graphics context changes
	GCValues_t vallBoard;
	vallBoard.fMask = kGCForeground | kGCBackground | kGCFillStyle | kGCFont | kGCGraphicsExposures;
	gClient->GetColorByName("#000000",vallBoard.fForeground);
	gClient->GetColorByName("#e8e8e8",vallBoard.fBackground);
	vallBoard.fFillStyle = kFillSolid;
	vallBoard.fFont = ufont->GetFontHandle();
	vallBoard.fGraphicsExposures = kFALSE;
	uGC = gClient->GetGC(&vallBoard, kTRUE);
	TGLabel *fLabelBoard = new TGLabel(fVerticalFrame,"Board",uGC->GetGC(),ufont->GetFontStruct());
	fLabelBoard->SetTextJustify(36);
	fLabelBoard->SetMargins(0,0,0,0);
	fLabelBoard->SetWrapLength(-1);
	fVerticalFrame->AddFrame(fLabelBoard, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
	fLabelBoard->MoveResize(8,8,64,18);

	ufont = gClient->GetFont("-*-liberation sans-bold-r-*-*- 0-*-*-*-*-*-*-*");

	// graphics context changes
	GCValues_t vallCh;
	vallCh.fMask = kGCForeground | kGCBackground | kGCFillStyle | kGCFont | kGCGraphicsExposures;
	gClient->GetColorByName("#000000",vallCh.fForeground);
	gClient->GetColorByName("#e8e8e8",vallCh.fBackground);
	vallCh.fFillStyle = kFillSolid;
	vallCh.fFont = ufont->GetFontHandle();
	vallCh.fGraphicsExposures = kFALSE;
	uGC = gClient->GetGC(&vallCh, kTRUE);
	TGLabel *fLabelCh = new TGLabel(fVerticalFrame,"Channel",uGC->GetGC(),ufont->GetFontStruct());
	fLabelCh->SetTextJustify(36);
	fLabelCh->SetMargins(0,0,0,0);
	fLabelCh->SetWrapLength(-1);
	fVerticalFrame->AddFrame(fLabelCh, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
	fLabelCh->MoveResize(80,8,64,18);

	/*Board number entry*/
	fBoard = new TGNumberEntry(fVerticalFrame, (Double_t) 0,6,-1,
			TGNumberFormat::kNESInteger, //style
			TGNumberFormat::kNEANonNegative, //input value filter
			TGNumberFormat::kNELLimitMinMax, //specify limits
			0,TCitirocSetupHandler::nCitirocMaxBoards);
	fBoard->SetName("fBoard");
	fVerticalFrame->AddFrame(fBoard, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
	fBoard->MoveResize(8,32,59,22);
	fBoard->Connect("ValueSet(Long_t)","TCitirocChargeCalibrationGui",this,"GoToChannel()");
	fBoard->Connect("ValueChanged(Long_t)","TCitirocChargeCalibrationGui",this,"GoToChannel()");


	/*Channel number entry*/
	fCh = new TGNumberEntry(fVerticalFrame, (Double_t) 0,6,-1,
			TGNumberFormat::kNESInteger, //style
			TGNumberFormat::kNEANonNegative, //input value filter
			TGNumberFormat::kNELLimitMinMax, //specify limits
			0,TCitirocSetupHandler::nCitirocChannelsPerBoard);
	fCh->SetName("fCh");
	fVerticalFrame->AddFrame(fCh, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
	fCh->MoveResize(88,32,59,22);
	fCh->Connect("ValueSet(Long_t)","TCitirocChargeCalibrationGui",this,"GoToChannel()");
	fCh->Connect("ValueChanged(Long_t)","TCitirocChargeCalibrationGui",this,"GoToChannel()");

	/*Prev button*/
	fPrev = new TGTextButton(fVerticalFrame,"Prev",-1,TGTextButton::GetDefaultGC()(),TGTextButton::GetDefaultFontStruct(),kRaisedFrame);
	fPrev->SetTextJustify(36);
	fPrev->SetMargins(0,0,0,0);
	fPrev->SetWrapLength(-1);
	fPrev->Resize(56,24);
	fVerticalFrame->AddFrame(fPrev, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
	fPrev->MoveResize(160,32,56,24);
	fPrev->Connect("Clicked()","TCitirocChargeCalibrationGui",this,"Prev()");

	/*Next button*/
	fNext = new TGTextButton(fVerticalFrame,"Next",-1,TGTextButton::GetDefaultGC()(),TGTextButton::GetDefaultFontStruct(),kRaisedFrame);
	fNext->SetTextJustify(36);
	fNext->SetMargins(0,0,0,0);
	fNext->SetWrapLength(-1);
	fNext->Resize(56,24);
	fVerticalFrame->AddFrame(fNext, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
	fNext->MoveResize(160,8,56,24);
	fNext->Connect("Clicked()","TCitirocChargeCalibrationGui",this,"Next()");

	//	fRange = new TGHScrollBar(fVerticalFrame,102,16,kHorizontalFrame | kOwnBackground);
	fRange = new TGDoubleHSlider(fVerticalFrame,1,kDoubleScaleBoth);

	fRange->SetName("fRange");
	//fRange->SetRange(100,20);
	//fRange->SetPosition(50);
	fRange->Connect("PositionChanged()","TCitirocChargeCalibrationGui",this,"DoSliderMoved()");
	fVerticalFrame->AddFrame(fRange, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
	fRange->MoveResize(720,32,102,16);
	TGLabel *fRangeLabel = new TGLabel(fVerticalFrame,"Fit Range");
	fRangeLabel->SetTextJustify(36);
	fRangeLabel->SetMargins(0,0,0,0);
	fRangeLabel->SetWrapLength(-1);
	fVerticalFrame->AddFrame(fRangeLabel, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
	fRangeLabel->MoveResize(744,8,64,18);

	/*NextAndSave button*/
	fSave = new TGTextButton(fVerticalFrame,"Save",-1,TGTextButton::GetDefaultGC()(),TGTextButton::GetDefaultFontStruct(),kRaisedFrame);
	fSave->SetTextJustify(36);
	fSave->SetMargins(0,0,0,0);
	fSave->SetWrapLength(-1);
	fSave->Resize(99,24);
	fVerticalFrame->AddFrame(fSave, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
	fSave->MoveResize(224,32,99,24);
	fSave->Connect("Clicked()","TCitirocChargeCalibrationGui",this,"Save()");




	/*NextAndSave button*/
	fNextAndSave = new TGTextButton(fVerticalFrame,"NextAndSave",-1,TGTextButton::GetDefaultGC()(),TGTextButton::GetDefaultFontStruct(),kRaisedFrame);
	fNextAndSave->SetTextJustify(36);
	fNextAndSave->SetMargins(0,0,0,0);
	fNextAndSave->SetWrapLength(-1);
	fNextAndSave->Resize(99,24);
	fVerticalFrame->AddFrame(fNextAndSave, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
	fNextAndSave->MoveResize(224,8,99,24);
	fNextAndSave->Connect("Clicked()","TCitirocChargeCalibrationGui",this,"NextAndSave()");


	/*Fit button*/
	fFit = new TGTextButton(fVerticalFrame,"Fit current",-1,TGTextButton::GetDefaultGC()(),TGTextButton::GetDefaultFontStruct(),kRaisedFrame);
	fFit->SetTextJustify(36);
	fFit->SetMargins(0,0,0,0);
	fFit->SetWrapLength(-1);
	fFit->Resize(99,24);
	fVerticalFrame->AddFrame(fFit, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
	fFit->MoveResize(288,8,99,24);
	fFit->Connect("Clicked()","TCitirocChargeCalibrationGui",this,"Fit()");

	/*SaveNextFit*/
	fSaveNextFit = new TGTextButton(fVerticalFrame,"fSaveNextFit",-1,TGTextButton::GetDefaultGC()(),TGTextButton::GetDefaultFontStruct(),kRaisedFrame);
	fSaveNextFit->SetTextJustify(36);
	fSaveNextFit->SetMargins(0,0,0,0);
	fSaveNextFit->SetWrapLength(-1);
	fSaveNextFit->Resize(99,24);
	fVerticalFrame->AddFrame(fSaveNextFit, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
	fSaveNextFit->MoveResize(288,32,99,24);
	fSaveNextFit->Connect("Clicked()","TCitirocChargeCalibrationGui",this,"NextSaveFit()");

	TGTextButton *fTextButton1990 = new TGTextButton(fVerticalFrame,"fTextButton1990",-1,TGTextButton::GetDefaultGC()(),TGTextButton::GetDefaultFontStruct(),kRaisedFrame);
	fTextButton1990->SetTextJustify(36);
	fTextButton1990->SetMargins(0,0,0,0);
	fTextButton1990->SetWrapLength(-1);
	fTextButton1990->Resize(99,24);
	fVerticalFrame->AddFrame(fTextButton1990, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
	fTextButton1990->MoveResize(600,8,99,24);


	fMain->AddFrame(fVerticalFrame, new TGLayoutHints(kLHintsNormal));
	fVerticalFrame->MoveResize(0,632,912,64);

	// embedded canvas
	fEcanvas = new TRootEmbeddedCanvas(0,fMain,920,632,kSunkenFrame);
	fEcanvas->SetName("fEcanvas");
	Int_t wfEcanvas = fEcanvas->GetCanvasWindowId();
	TCanvas *c125 = new TCanvas("c125", 10, 10, wfEcanvas);
	fEcanvas->AdoptCanvas(c125);
	fMain->AddFrame(fEcanvas, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
	fEcanvas->MoveResize(0,0,920,632);

	fMain->SetMWMHints(kMWMDecorAll,
			kMWMFuncAll,
			kMWMInputModeless);
	fMain->MapSubwindows();

	fMain->Resize(fMain->GetDefaultSize());
	fMain->MapWindow();
	fMain->Resize(926,702);


	m_canvas = fEcanvas->GetCanvas();
	m_canvas->Divide(2,2);

}


void TCitirocChargeCalibrationGui::Start(){
	m_curChannel=0;
	m_curBoard=0;
	while (m_TCitirocChargeCalibration->gethChargeRaw(m_curBoard,m_curChannel)==0){
		m_curChannel++;
		if (m_curChannel==TCitirocSetupHandler::nCitirocChannelsPerBoard){
			m_curBoard++;
			m_curChannel=0;
		}
	}

	this->Refresh();
}

void TCitirocChargeCalibrationGui::Refresh(){
	m_canvas = fEcanvas->GetCanvas();
	m_canvas->cd();
	if(m_TCitirocChargeCalibration->gethChargeRaw(m_curBoard,m_curChannel)!=0){
		/*Modify the slider*/
		Int_t ixrange = m_TCitirocChargeCalibration->gethChargeRaw(m_curBoard,m_curChannel)->GetXaxis()->GetNbins();
		Int_t ixmin =  m_TCitirocChargeCalibration->gethChargeRaw(m_curBoard,m_curChannel)->GetXaxis()->GetFirst();
		Int_t ixmax =  m_TCitirocChargeCalibration->gethChargeRaw(m_curBoard,m_curChannel)->GetXaxis()->GetLast();

		if (ixmin > 1 || ixmax < ixrange) {
			fRange->SetRange(ixmin,ixmax);
			fRange->SetPosition(ixmin, ixmax);
		} else {
			fRange->SetRange(1,ixrange);
			fRange->SetPosition(ixmin,ixmax);
		}
		fRange->SetScale(5);
		/*Here draw the canvas*/

		int firstBin,lastBin;

		m_canvas->cd(1);
		m_TCitirocChargeCalibration->gethChargeRaw(m_curBoard,m_curChannel)->Draw();
		m_canvas->cd(2);
		if (m_TCitirocChargeCalibration->getgCalib(m_curBoard,m_curChannel)!=0){
			m_TCitirocChargeCalibration->getgCalib(m_curBoard,m_curChannel)->Draw("AP");
		}
		else{
			m_canvas->cd(2)->Clear();
		}
		m_canvas->cd(3)->SetLogy();


		m_canvas->cd(4);


		m_canvas->Modified();
		m_canvas->Update();
	}
	else{
		Error("Refresh","no data for board:%i ch: %i",m_curBoard,m_curChannel);
	}
}
void TCitirocChargeCalibrationGui::Save(){
	Info("Save","saving for board: %i ch: %i",m_curBoard,m_curChannel);
	m_TCitirocChargeCalibration->dumpCalibration();
}



void TCitirocChargeCalibrationGui::GoToChannel(){
	int ch=fCh->GetIntNumber();
	int ID=fBoard->GetIntNumber();

	m_curBoard=ID;
	m_curChannel=ch;
	Info("GoToChannel","cur board - channel now is: %i %i",m_curBoard,m_curChannel);
	Refresh();

}


void TCitirocChargeCalibrationGui::Next(){
	int m_tmp;
	m_tmp=m_curChannel+m_curBoard*TCitirocSetupHandler::nCitirocChannelsPerBoard;
	if (m_tmp==(m_TCitirocChargeCalibration->getChannels()-1)) return; //do nothing

	m_curChannel++;
	if (m_curChannel==TCitirocSetupHandler::nCitirocChannelsPerBoard){
		m_curChannel=0;
		m_curBoard++;
	}

	Info("Next","ID/Channel now is: %i %i",m_curBoard,m_curChannel);
	RefreshIDChWidgetValue();
	Refresh();

}


void TCitirocChargeCalibrationGui::Prev(){
	if ((m_curChannel==0)&&(m_curBoard==0)) return;
	else if (m_curChannel==0){
		m_curChannel=TCitirocSetupHandler::nCitirocChannelsPerBoard-1;
		m_curBoard--;
	}
	else{
		m_curChannel--;
	}
	Info("Prev","cur ID-channel  now is: %i %i",m_curBoard,m_curChannel);
	RefreshIDChWidgetValue();

	Refresh();

}


void TCitirocChargeCalibrationGui::RefreshIDChWidgetValue(){
	fCh->SetIntNumber(m_curChannel);
	fBoard->SetIntNumber(m_curBoard);
}



void TCitirocChargeCalibrationGui::Fit(){
	/*Fit the current histogram*/
	double min,max;
	min=m_TCitirocChargeCalibration->gethChargeRaw(m_curBoard,m_curChannel)->GetXaxis()->GetBinCenter(fRange->GetMinPosition());
	max=m_TCitirocChargeCalibration->gethChargeRaw(m_curBoard,m_curChannel)->GetXaxis()->GetBinCenter(fRange->GetMaxPosition());


	m_TCitirocChargeCalibration->setFitRange(min,max);

	m_TCitirocChargeCalibration->Fit(m_curBoard,m_curChannel);
	Refresh();

}

void TCitirocChargeCalibrationGui::NextAndSave(){
	Save();
	Next();
}


void TCitirocChargeCalibrationGui::DoSliderMoved(){
	DrawFitBox();
}

void TCitirocChargeCalibrationGui::DrawFitBox(){
	static Int_t px1old, py1old, px2old, py2old; // to remember the square drawn.

	Int_t px1,py1,px2,py2;

	TAxis *fXaxis=m_TCitirocChargeCalibration->gethChargeRaw(m_curBoard,m_curChannel)->GetXaxis();

	Double_t xleft = 0;
	Double_t xright = 0;
	xleft  = fXaxis->GetBinLowEdge((Int_t)((fRange->GetMinPosition())+0.5));
	xright = fXaxis->GetBinUpEdge((Int_t)((fRange->GetMaxPosition())+0.5));

	Float_t ymin, ymax;
	ymin=m_canvas->cd(1)->GetUymin();
	ymax=m_canvas->cd(1)->GetUymax();

	px1 =  m_canvas->cd(1)->XtoAbsPixel(xleft);
	py1 =  m_canvas->cd(1)->YtoAbsPixel(ymin);
	px2 =  m_canvas->cd(1)->XtoAbsPixel(xright);
	py2 =  m_canvas->cd(1)->YtoAbsPixel(ymax);
	gPad=m_canvas->cd(1);


	if (gPad->GetCanvas()) gPad->GetCanvas()->FeedbackMode(kTRUE);
	gPad->SetLineWidth(1);
	gPad->SetLineColor(2);

	gVirtualX->DrawBox(px1old, py1old, px2old, py2old, TVirtualX::kHollow);
	gVirtualX->DrawBox(px1, py1, px2, py2, TVirtualX::kHollow);

	px1old = px1;
	py1old = py1;
	px2old = px2 ;
	py2old = py2;

}


