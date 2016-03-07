/*
 * TTofpetChargeCalibrationDriver.cc
 *
 *  Created on: Dec 30, 2015
 *      Author: celentan
 */

#include "TTofpetThresholdCalibrationDriver.hh"

#include "TH1D.h"
#include "TH2D.h"
#include "TFile.h"
#include "TCanvas.h"
#include "TLine.h"
#include "TROOT.h"

#include "TTofpetRun.hh"
#include "TEvent.hh"
#include "TTofpetEventHeader.hh"
#include "TTofpetHit.hh"
#include "TJobManager.hh"
#include "TTofpetSetupHandler.hh"
#include "TTofpetThresholdCalibration.hh"
#include "TDetector.hh"


TTofpetThresholdCalibrationDriver::TTofpetThresholdCalibrationDriver() {
	// TODO Auto-generated constructor stub
	m_TTofpetRun=0;
	m_TTofpetSetupHandler=0;
	hToT0=0;
	hToTvsThr=0;
	m_detector=0;

	m_hToT0_nbins=400;
	m_hToT0_min=-100;
	m_hToT0_max=500;
	m_isInteractive=0;
	m_TTofpetThresholdCalibration=0;
}

TTofpetThresholdCalibrationDriver::~TTofpetThresholdCalibrationDriver() {
	// TODO Auto-generated destructor stub
}

/*This does the following:
 * 1) Add the TTofpetThresholdCalibration object file to the input list
 */
int TTofpetThresholdCalibrationDriver::start(){
	TFile *m_file;
	if (m_manager->isFirstIteration()){
		if (m_manager->getVerboseLevel() >  TJobManager::normalVerbosity) Info("start","Iteration 0");
		if (m_manager->hasObject(TTofpetThresholdCalibration::Class())){
			return 0;
		}
		if (m_Thrfname.length()==0){
			Error("start","Set file name first");
			return -1;
		}
		else{
			m_file=new TFile(m_Thrfname.c_str());
			if (m_file->GetListOfKeys()->Contains("TTofpetThresholdCalibration")){
				m_TTofpetThresholdCalibration=(TTofpetThresholdCalibration*)m_file->Get("TTofpetThresholdCalibration");
				m_manager->addObject(m_TTofpetThresholdCalibration);
				Info("start","Got TTofpetThresholdCalibration");
			}
			else{
				Error("start","No TTofpetThresholdCalibration found in ROOT file %s",m_Thrfname.c_str());
			}
			m_file->Close();
		}
	}

	else{
		if (m_manager->getVerboseLevel() >  TJobManager::normalVerbosity) Info("start","Iteration: %i doing nothing",m_manager->getIterationN());
	}
}

int TTofpetThresholdCalibrationDriver::startOfData(){

	int step1,step2,id;

	if (m_manager->getVerboseLevel()>TJobManager::normalVerbosity) Info("startOfData","called");

	if (m_manager->hasObject(TTofpetRun::Class())){
		m_TTofpetRun=(TTofpetRun*)(m_manager->getObject(TTofpetRun::Class()));
	}
	else{
		Error("startOfData","No TTofpetRun object in the file, should be there!");
		return -1;
	}
	if (m_manager->hasObject(TTofpetSetupHandler::Class())){
		m_TTofpetSetupHandler=(TTofpetSetupHandler*)(m_manager->getObject(TTofpetSetupHandler::Class()));
	}
	else{
		Error("startOfData","No TTofpetSetup found. Have you activated (before this!) the TTofpetSetupHandlerDriver?");
		return -1;
	}

	if (m_manager->hasObject(TTofpetThresholdCalibration::Class())){
		m_TTofpetThresholdCalibration=(TTofpetThresholdCalibration*)(m_manager->getObject(TTofpetThresholdCalibration::Class()));
	}
	else{
		Error("startOfData","No TTofpetThresholdCalibration found");
		return -1;
	}

	m_detector=m_manager->getDetector();


	m_Nsteps=m_TTofpetRun->getNsteps();
	m_Nchannels=m_detector->getTotPixels();

	if (m_manager->getVerboseLevel()>TJobManager::normalVerbosity) Info("startOfData","There are: %i steps and %i pixels",m_Nsteps,m_Nchannels);

	m_NhToT0=m_Nchannels;
	m_NhToTCalib=m_Nchannels;

	hToT0=new TH1D*[m_NhToTCalib];
	hToTvsThr=new TH2D*[m_NhToTCalib];

	for (int ich=0;ich<m_Nchannels;ich++){
			hToTvsThr[id]=new TH2D(Form("hToTCalib_ch:%i",ich),Form("hToTCalib_ch:%i",ich),m_hToT0_nbins,m_hToT0_min,m_hToT0_max,64,-0.5,63.5);
			m_manager->GetOutputList()->Add(hToTvsThr[id]);
			id++;
	}
}

int TTofpetThresholdCalibrationDriver::process(TEvent *event){
	TClonesArray *TofpetHitCollection;
	TIter		 *TofpetHitCollectionIter;
	TTofpetHit   *hit;
	TTofpetEventHeader *header=0;

	int N,step1,step2,istep,istep1,id,id1,ch,ix,iy;



	header=(TTofpetEventHeader*)event->getEventHeader();
	if (header==0){
		Error("process","no event header!");
	}

	step1=header->getStep1();
	step2=header->getStep2();

	istep=m_TTofpetRun->getStepID(step1,step2);
	istep1=m_TTofpetRun->getStep1ID(step1);
	if (event->hasCollection(TTofpetHit::Class(),m_collectionRawName)){
		TofpetHitCollection=event->getCollection(TTofpetHit::Class(),m_collectionRawName);
		N=TofpetHitCollection->GetEntries();
		TofpetHitCollectionIter=new TIter(TofpetHitCollection);

		while (hit = (TTofpetHit*)TofpetHitCollectionIter->Next()){
			ch=hit->getChannel();
			ix=hit->getXi();
			iy=hit->getYi();
			id=ch%TTofpetSetupHandler::nMPPCPixels;  //from 0 to 64
			if ((id>=16*step1)&&(id<16*(step1+1))){
			//	hToT0[id]->Fill(hit->getToT());
				hToTvsThr[ch]->Fill(hit->getToT(),m_TTofpetThresholdCalibration->getDAQRunThreshold(ch,step2));
			}
			else{
				hToTvsThr[ch]->Fill(hit->getToT(),10);
			}
		}
	}

}

int TTofpetThresholdCalibrationDriver::end(){

	int id,step1;
	int firstBin,lastBin;
	int thr,thr_tmp;
	double minDrawY=30;
	double maxDrawY=60;
	TLine *l;

	if (!m_isInteractive){
		gROOT->SetBatch(true);
	}
	else{
		gROOT->SetBatch(false);
	}

	if (m_manager->hasObject(TTofpetRun::Class())){
		m_TTofpetRun=(TTofpetRun*)(m_manager->getObject(TTofpetRun::Class()));
	}
	else{
		Error("end","No TTofpetRun object in the file, should be there!");
		return -1;
	}

	if (m_manager->hasObject(TTofpetSetupHandler::Class())){
		m_TTofpetSetupHandler=(TTofpetSetupHandler*)(m_manager->getObject(TTofpetSetupHandler::Class()));
	}
	else{
		Error("end","No TTofpetSetup found. Have you activated (before this!) the TTofpetSetupHandlerDriver?");
		return -1;
	}
	if (m_manager->hasObject(TTofpetThresholdCalibration::Class())){
		m_TTofpetThresholdCalibration=(TTofpetThresholdCalibration*)(m_manager->getObject(TTofpetThresholdCalibration::Class()));
	}
	else{
		Error("end","No TTofpetThresholdCalibration found");
		return -1;
	}
	m_detector=m_manager->getDetector();


	m_Nsteps=m_TTofpetRun->getNsteps();
	m_Nchannels=m_detector->getTotPixels();


	m_NhToT0=m_Nsteps*m_Nchannels;
	m_NhToTCalib=m_Nchannels*m_TTofpetRun->getNsteps1();


	hToTvsThr=new TH2D*[m_NhToTCalib];


	//Get the hToTvsThr and save it to the TTofpetThresholdCalibration class responsible of threshold calibration
	id=0;
	for (int ich=0;ich<m_Nchannels;ich++){
			hToTvsThr[id]=(TH2D*)(m_manager->GetOutputList()->FindObject(Form("hToTCalib_ch:%i",ich)));
			if (hToTvsThr[id]==0){
				Error("end","no hToTCalib for ch: %i",ich);
			}
			m_TTofpetThresholdCalibration->addhToTvsThr(ich,hToTvsThr[id]);
			id++;
	}



	/*Put here the "interactive part!*/
	if (m_isInteractive){
		id=0;
		for (int ich=0;ich<m_Nchannels;ich++){



				/*	thr=m_TTofpetThresholdCalibration->getThreshold(ich,step1,2);
			maxDrawY=m_TTofpetThresholdCalibration->getActualThreshold(ich,step1,0);
			minDrawY=m_TTofpetThresholdCalibration->getActualThreshold(ich,step1,20); ///TODO: not hardcoded

			c[id]=new TCanvas(Form("c_%i",id),Form("c_%i",id),1000,1000);
			c[id]->Divide(2,2);

			c[id]->cd(1);

			hToTvsThr[id]->GetYaxis()->SetRangeUser(minDrawY,maxDrawY);
			hToTvsThr[id]->Draw("colz");

			l=new TLine(m_hToT0_min,thr,m_hToT0_max,thr);
			l->SetLineColor(2);
			l->SetLineWidth(2);
			l->Draw("SAME");
			thr_tmp=m_TTofpetThresholdCalibration->getTransition(ich,step1,1);
			l=new TLine(m_hToT0_min,thr_tmp,m_hToT0_max,thr_tmp);
			l->SetLineColor(3);
			l->SetLineWidth(2);
			l->Draw("SAME");
			thr_tmp=m_TTofpetThresholdCalibration->getTransition(ich,step1,2);
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
			m_TTofpetThresholdCalibration->gethRateRaw(ich,step1)->Draw();
			c[id]->cd(4);
			m_TTofpetThresholdCalibration->getgThr(ich,step1)->Draw("AP");
			hToT0[id];

			if (m_isInteractive){
				c[id]->Update();
				cin.get();
			}
			m_manager->GetOutputList()->Add(c[id]);
			id++;*/
		}
	}

}




