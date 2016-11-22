/*
 * TCitirocChargeCalibrationDriver.cc
 *
 *  Created on: Dec 30, 2015
 *      Author: celentan
 */

#include "TCitirocChargeCalibrationDriver.hh"

#include "TH1D.h"
#include "TH2D.h"
#include "TFile.h"
#include "TCanvas.h"
#include "TLine.h"
#include "TROOT.h"


#include "TEvent.hh"
#include "TCitirocEventHeader.hh"
#include "TCitirocHitRaw.hh"
#include "TJobManager.hh"
#include "TCitirocSetupHandler.hh"
#include "TCitirocChargeCalibration.hh"
#include "TDetector.hh"


TCitirocChargeCalibrationDriver::TCitirocChargeCalibrationDriver() {
	// TODO Auto-generated constructor stub

	m_CitirocSetupHandler=0;
	m_detector=0;

	nBinsCharge=4096;
	chargeMin=-0.5;
	chargeMax=4095.5;

	chargeMinCut=10;
	chargeMaxCut=3500;

	m_isInteractive=0;
	m_CitirocChargeCalibration=0;
	m_nChannels=0;
}

TCitirocChargeCalibrationDriver::~TCitirocChargeCalibrationDriver() {
	// TODO Auto-generated destructor stub
}

/*This does the following:
 * 1) Add the TCitirocChargeCalibration object file to the input list
 */
int TCitirocChargeCalibrationDriver::start(){
	if (m_manager->isFirstIteration()){
		if (m_manager->getVerboseLevel() >  TJobManager::normalVerbosity) Info("start","Iteration 0");
		if (m_manager->hasObject(TCitirocChargeCalibration::Class())){
			return 0;
		}
		else{
			m_CitirocChargeCalibration=new TCitirocChargeCalibration();
			m_manager->addObject(m_CitirocChargeCalibration);
			Info("start","Created TCitirocChargeCalibration");
		}
	}
	else{
		if (m_manager->getVerboseLevel() >  TJobManager::normalVerbosity) Info("start","Iteration: %i doing nothing",m_manager->getIterationN());
	}
}

int TCitirocChargeCalibrationDriver::startOfData(){

	if (m_manager->getVerboseLevel()>TJobManager::normalVerbosity) Info("startOfData","called");

	if (m_manager->hasObject(TCitirocSetupHandler::Class())){
		m_CitirocSetupHandler=(TCitirocSetupHandler*)(m_manager->getObject(TCitirocSetupHandler::Class()));
	}
	else{
		Error("startOfData","No TCitirocSetup found. Have you activated (before this!) the TCitirocSetupHandlerDriver?");
		return -1;
	}

	if (m_manager->hasObject(TCitirocChargeCalibration::Class())){
		m_CitirocChargeCalibration=(TCitirocChargeCalibration*)(m_manager->getObject(TCitirocChargeCalibration::Class()));
	}
	else{
		Error("startOfData","No TCitirocChargeCalibration found");
		return -1;
	}

	m_detector=m_manager->getDetector();


	m_nChannels=TCitirocSetupHandler::nCitirocChannelsPerBoard*TCitirocSetupHandler::nCitirocMaxBoards; //for now




	if (m_manager->getVerboseLevel()>TJobManager::normalVerbosity) Info("startOfData","before creating histograms");


	for (int iboard=0;iboard<TCitirocSetupHandler::nCitirocMaxBoards;iboard++){
		for (int ich=0;ich<TCitirocSetupHandler::nCitirocChannelsPerBoard;ich++){
			m_CitirocKey=make_pair(iboard,ich);
			hCharge0[m_CitirocKey]=new TH1D(Form("hCharge0_%i_%i",iboard,ich),Form("hCharge0_%i_%i",iboard,ich),nBinsCharge,chargeMin,chargeMax);
			m_manager->GetOutputList()->Add(hCharge0[m_CitirocKey]);
		}
	}


	if (m_manager->getVerboseLevel()>TJobManager::normalVerbosity) Info("startOfData","after creating histogram");
}

int TCitirocChargeCalibrationDriver::process(TEvent *event){
	TClonesArray *CitirocHitCollection;
	TIter		 *CitirocHitCollectionIter;
	TCitirocHitRaw   *hit;
	TCitirocEventHeader *header=0;

	int N,ch,id,board;
	double charge;


	header=(TCitirocEventHeader*)event->getEventHeader();
	if (header==0){
		Error("process","no event header!");
	}




	if (event->hasCollection(TCitirocHitRaw::Class(),m_collectionRawName)){
		CitirocHitCollection=event->getCollection(TCitirocHitRaw::Class(),m_collectionRawName);
		N=CitirocHitCollection->GetEntries();
		CitirocHitCollectionIter=new TIter(CitirocHitCollection);

		while (hit = (TCitirocHitRaw*)CitirocHitCollectionIter->Next()){
			ch=hit->getChannel();
			board=hit->getMAC();
			m_CitirocKey=make_pair(board,ch);
			charge=hit->getCharge();
			if ((charge>chargeMinCut)&&(charge<chargeMaxCut)){
				hCharge0[m_CitirocKey]->Fill(charge);
			}
		}
	}

}

int TCitirocChargeCalibrationDriver::end(){

	TH1D *hTmp;
	if (!m_isInteractive){
		gROOT->SetBatch(true);
	}
	else{
		gROOT->SetBatch(false);
	}



	if (m_manager->hasObject(TCitirocSetupHandler::Class())){
		m_CitirocSetupHandler=(TCitirocSetupHandler*)(m_manager->getObject(TCitirocSetupHandler::Class()));
	}
	else{
		Error("end","No TCitirocSetup found. Have you activated (before this!) the TCitirocSetupHandlerDriver?");
		return -1;
	}
	if (m_manager->hasObject(TCitirocChargeCalibration::Class())){
		m_CitirocChargeCalibration=(TCitirocChargeCalibration*)(m_manager->getObject(TCitirocChargeCalibration::Class()));
	}
	else{
		Error("end","No TCitirocChargeCalibration found");
		return -1;
	}
	m_detector=m_manager->getDetector();










	for (int iboard=0;iboard<TCitirocSetupHandler::nCitirocMaxBoards;iboard++){
		for (int ich=0;ich<TCitirocSetupHandler::nCitirocChannelsPerBoard;ich++){
			m_CitirocKey=make_pair(iboard,ich);
			hTmp=0;
			hTmp=(TH1D*)(m_manager->GetOutputList()->FindObject(Form("hCharge0_%i_%i",iboard,ich)));
			if (hTmp==0){
				Error("end","no hCharge find for id: %i ch: %i",iboard,ich);
			}
			else{
				m_CitirocChargeCalibration->addhChargeRaw(iboard,ich,hTmp);
			}
		}
	}



	/*Put here the "interactive part!*/
	if (m_isInteractive){

		//for (int ich=0;ich<m_Nchannels;ich++){



		/*	thr=m_TCitirocChargeCalibration->getCharge(ich,step1,2);
			maxDrawY=m_TCitirocChargeCalibration->getActualCharge(ich,step1,0);
			minDrawY=m_TCitirocChargeCalibration->getActualCharge(ich,step1,20); ///TODO: not hardcoded

			c[id]=new TCanvas(Form("c_%i",id),Form("c_%i",id),1000,1000);
			c[id]->Divide(2,2);

			c[id]->cd(1);

			hToTvsThr[id]->GetYaxis()->SetRangeUser(minDrawY,maxDrawY);
			hToTvsThr[id]->Draw("colz");

			l=new TLine(m_hToT0_min,thr,m_hToT0_max,thr);
			l->SetLineColor(2);
			l->SetLineWidth(2);
			l->Draw("SAME");
			thr_tmp=m_TCitirocChargeCalibration->getTransition(ich,step1,1);
			l=new TLine(m_hToT0_min,thr_tmp,m_hToT0_max,thr_tmp);
			l->SetLineColor(3);
			l->SetLineWidth(2);
			l->Draw("SAME");
			thr_tmp=m_TCitirocChargeCalibration->getTransition(ich,step1,2);
			l=new TLine(m_hToT0_min,thr_tmp,m_hToT0_max,thr_tmp);
			l->SetLineColor(3);
			l->SetLineWidth(2);
			l->Draw("SAME");


			c[id]->cd(2);
			firstBin=thr+1;
			lastBin=thr+1;
			hToT0[id]=hToTvsThr[id]->ProjectionX(Form("hToT0_%i",id),firstBin,lastBin);
			hToT0[id]->Draw();
			c[id]->cd(3)->SetLogy();
			m_TCitirocChargeCalibration->gethRateRaw(ich,step1)->Draw();
			c[id]->cd(4);
			m_TCitirocChargeCalibration->getgThr(ich,step1)->Draw("AP");
			hToT0[id];

			if (m_isInteractive){
				c[id]->Update();
				cin.get();
			}
			m_manager->GetOutputList()->Add(c[id]);
			id++;*/
		//	}
	}

}




