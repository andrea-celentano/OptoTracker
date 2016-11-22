// Mainframe macro generated from application: /project/Gruppo3/fiber6/apps/jlab_software_20160107/1.3/Linux_Scientific6-x86_64-gcc4.4.7/root/5.34.34/root/bin/root.exe
// By ROOT version 5.34/34 on 2016-11-21 11:45:34

#ifndef ROOT_TGDockableFrame
#include "TGDockableFrame.h"
#endif
#ifndef ROOT_TGMenu
#include "TGMenu.h"
#endif
#ifndef ROOT_TGMdiDecorFrame
#include "TGMdiDecorFrame.h"
#endif
#ifndef ROOT_TG3DLine
#include "TG3DLine.h"
#endif
#ifndef ROOT_TGMdiFrame
#include "TGMdiFrame.h"
#endif
#ifndef ROOT_TGMdiMainFrame
#include "TGMdiMainFrame.h"
#endif
#ifndef ROOT_TGMdiMenu
#include "TGMdiMenu.h"
#endif
#ifndef ROOT_TGColorDialog
#include "TGColorDialog.h"
#endif
#ifndef ROOT_TGColorSelect
#include "TGColorSelect.h"
#endif
#ifndef ROOT_TGListBox
#include "TGListBox.h"
#endif
#ifndef ROOT_TGNumberEntry
#include "TGNumberEntry.h"
#endif
#ifndef ROOT_TGScrollBar
#include "TGScrollBar.h"
#endif
#ifndef ROOT_TGComboBox
#include "TGComboBox.h"
#endif
#ifndef ROOT_TGuiBldHintsEditor
#include "TGuiBldHintsEditor.h"
#endif
#ifndef ROOT_TRootBrowser
#include "TRootBrowser.h"
#endif
#ifndef ROOT_TGuiBldNameFrame
#include "TGuiBldNameFrame.h"
#endif
#ifndef ROOT_TGFrame
#include "TGFrame.h"
#endif
#ifndef ROOT_TGFileDialog
#include "TGFileDialog.h"
#endif
#ifndef ROOT_TGShutter
#include "TGShutter.h"
#endif
#ifndef ROOT_TGButtonGroup
#include "TGButtonGroup.h"
#endif
#ifndef ROOT_TGCommandPlugin
#include "TGCommandPlugin.h"
#endif
#ifndef ROOT_TGCanvas
#include "TGCanvas.h"
#endif
#ifndef ROOT_TGFSContainer
#include "TGFSContainer.h"
#endif
#ifndef ROOT_TGFontDialog
#include "TGFontDialog.h"
#endif
#ifndef ROOT_TGuiBldEditor
#include "TGuiBldEditor.h"
#endif
#ifndef ROOT_TGTextEdit
#include "TGTextEdit.h"
#endif
#ifndef ROOT_TGButton
#include "TGButton.h"
#endif
#ifndef ROOT_TGFSComboBox
#include "TGFSComboBox.h"
#endif
#ifndef ROOT_TGLabel
#include "TGLabel.h"
#endif
#ifndef ROOT_TGView
#include "TGView.h"
#endif
#ifndef ROOT_TGMsgBox
#include "TGMsgBox.h"
#endif
#ifndef ROOT_TRootGuiBuilder
#include "TRootGuiBuilder.h"
#endif
#ifndef ROOT_TGFileBrowser
#include "TGFileBrowser.h"
#endif
#ifndef ROOT_TGTab
#include "TGTab.h"
#endif
#ifndef ROOT_TGListView
#include "TGListView.h"
#endif
#ifndef ROOT_TGSplitter
#include "TGSplitter.h"
#endif
#ifndef ROOT_TGTextEditor
#include "TGTextEditor.h"
#endif
#ifndef ROOT_TRootCanvas
#include "TRootCanvas.h"
#endif
#ifndef ROOT_TGStatusBar
#include "TGStatusBar.h"
#endif
#ifndef ROOT_TGListTree
#include "TGListTree.h"
#endif
#ifndef ROOT_TGuiBldGeometryFrame
#include "TGuiBldGeometryFrame.h"
#endif
#ifndef ROOT_TGToolTip
#include "TGToolTip.h"
#endif
#ifndef ROOT_TGToolBar
#include "TGToolBar.h"
#endif
#ifndef ROOT_TRootEmbeddedCanvas
#include "TRootEmbeddedCanvas.h"
#endif
#ifndef ROOT_TCanvas
#include "TCanvas.h"
#endif
#ifndef ROOT_TGuiBldDragManager
#include "TGuiBldDragManager.h"
#endif
#ifndef ROOT_TGHtmlBrowser
#include "TGHtmlBrowser.h"
#endif

#include "Riostream.h"

void CitirocChargeCalibrationGui()
{

   // main frame
   TGMainFrame *fMainFrame3461 = new TGMainFrame(gClient->GetRoot(),10,10,kMainFrame | kVerticalFrame);
   fMainFrame3461->SetName("fMainFrame3461");
   fMainFrame3461->SetLayoutBroken(kTRUE);

   // vertical frame
   TGVerticalFrame *fVerticalFrame = new TGVerticalFrame(fMainFrame3461,912,64,kVerticalFrame);
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
   TGNumberEntry *fBoard = new TGNumberEntry(fVerticalFrame, (Double_t) 0,6,-1,(TGNumberFormat::EStyle) 5);
   fBoard->SetName("fBoard");
   fVerticalFrame->AddFrame(fBoard, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   fBoard->MoveResize(8,32,59,22);
   TGNumberEntry *fCh = new TGNumberEntry(fVerticalFrame, (Double_t) 0,6,-1,(TGNumberFormat::EStyle) 5);
   fCh->SetName("fCh");
   fVerticalFrame->AddFrame(fCh, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   fCh->MoveResize(88,32,59,22);
   TGTextButton *fPrev = new TGTextButton(fVerticalFrame,"Prev",-1,TGTextButton::GetDefaultGC()(),TGTextButton::GetDefaultFontStruct(),kRaisedFrame);
   fPrev->SetTextJustify(36);
   fPrev->SetMargins(0,0,0,0);
   fPrev->SetWrapLength(-1);
   fPrev->Resize(56,24);
   fVerticalFrame->AddFrame(fPrev, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   fPrev->MoveResize(160,32,56,24);
   TGTextButton *fNext = new TGTextButton(fVerticalFrame,"Next",-1,TGTextButton::GetDefaultGC()(),TGTextButton::GetDefaultFontStruct(),kRaisedFrame);
   fNext->SetTextJustify(36);
   fNext->SetMargins(0,0,0,0);
   fNext->SetWrapLength(-1);
   fNext->Resize(56,24);
   fVerticalFrame->AddFrame(fNext, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   fNext->MoveResize(160,8,56,24);
   TGHScrollBar *fRange = new TGHScrollBar(fVerticalFrame,102,16,kHorizontalFrame | kOwnBackground);
   fRange->SetName("fRange");
   fRange->SetRange(100,20);
   fRange->SetPosition(50);
   fVerticalFrame->AddFrame(fRange, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   fRange->MoveResize(720,32,102,16);
   TGLabel *fRangeLabel = new TGLabel(fVerticalFrame,"Fit Range");
   fRangeLabel->SetTextJustify(36);
   fRangeLabel->SetMargins(0,0,0,0);
   fRangeLabel->SetWrapLength(-1);
   fVerticalFrame->AddFrame(fRangeLabel, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   fRangeLabel->MoveResize(744,8,64,18);
   TGTextButton *fNextAndFit = new TGTextButton(fVerticalFrame,"NextAndFit",-1,TGTextButton::GetDefaultGC()(),TGTextButton::GetDefaultFontStruct(),kRaisedFrame);
   fNextAndFit->SetTextJustify(36);
   fNextAndFit->SetMargins(0,0,0,0);
   fNextAndFit->SetWrapLength(-1);
   fNextAndFit->Resize(99,24);
   fVerticalFrame->AddFrame(fNextAndFit, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   fNextAndFit->MoveResize(224,8,99,24);
   TGTextButton *fFit = new TGTextButton(fVerticalFrame,"Fit current",-1,TGTextButton::GetDefaultGC()(),TGTextButton::GetDefaultFontStruct(),kRaisedFrame);
   fFit->SetTextJustify(36);
   fFit->SetMargins(0,0,0,0);
   fFit->SetWrapLength(-1);
   fFit->Resize(99,24);
   fVerticalFrame->AddFrame(fFit, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   fFit->MoveResize(488,8,99,24);
   TGTextButton *fTextButton1990 = new TGTextButton(fVerticalFrame,"fTextButton1990",-1,TGTextButton::GetDefaultGC()(),TGTextButton::GetDefaultFontStruct(),kRaisedFrame);
   fTextButton1990->SetTextJustify(36);
   fTextButton1990->SetMargins(0,0,0,0);
   fTextButton1990->SetWrapLength(-1);
   fTextButton1990->Resize(99,24);
   fVerticalFrame->AddFrame(fTextButton1990, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   fTextButton1990->MoveResize(600,8,99,24);
   TGTextButton *fTextButton2019 = new TGTextButton(fVerticalFrame,"fTextButton2019",-1,TGTextButton::GetDefaultGC()(),TGTextButton::GetDefaultFontStruct(),kRaisedFrame);
   fTextButton2019->SetTextJustify(36);
   fTextButton2019->SetMargins(0,0,0,0);
   fTextButton2019->SetWrapLength(-1);
   fTextButton2019->Resize(99,24);
   fVerticalFrame->AddFrame(fTextButton2019, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   fTextButton2019->MoveResize(600,32,99,24);

   fMainFrame3461->AddFrame(fVerticalFrame, new TGLayoutHints(kLHintsNormal));
   fVerticalFrame->MoveResize(0,632,912,64);

   // embedded canvas
   TRootEmbeddedCanvas *fEcanvas = new TRootEmbeddedCanvas(0,fMainFrame3461,920,632,kSunkenFrame);
   fEcanvas->SetName("fEcanvas");
   Int_t wfEcanvas = fEcanvas->GetCanvasWindowId();
   TCanvas *c125 = new TCanvas("c125", 10, 10, wfEcanvas);
   fEcanvas->AdoptCanvas(c125);
   fMainFrame3461->AddFrame(fEcanvas, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   fEcanvas->MoveResize(0,0,920,632);

   fMainFrame3461->SetMWMHints(kMWMDecorAll,
                        kMWMFuncAll,
                        kMWMInputModeless);
   fMainFrame3461->MapSubwindows();

   fMainFrame3461->Resize(fMainFrame3461->GetDefaultSize());
   fMainFrame3461->MapWindow();
   fMainFrame3461->Resize(926,702);
}  
