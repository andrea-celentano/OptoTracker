/*
 * TTofpetChargeCalibrationDriver.cc
 *
 *  Created on: Dec 30, 2015
 *      Author: celentan
 */

#include "TTofpetCalibrationDriver.hh"

#include "TH1D.h"
#include "TH2D.h"

#include "TTofpetRun.hh"
#include "TEvent.hh"
#include "TTofpetEventHeader.hh"
#include "TTofpetHit.hh"
#include "TJobManager.hh"
#include "TTofpetSetupHandler.hh"

#include "TDetectorLight.hh"

TTofpetCalibrationDriver::TTofpetCalibrationDriver() {
	// TODO Auto-generated constructor stub
	m_TTofpetRun=0;
	m_TTofpetSetupHandler=0;
	hToT0=0;
	hToTCalib=0;
	m_detector=0;

	m_hToT0_nbins=400;
	m_hToT0_min=-100;
	m_hToT0_max=500;
}

TTofpetCalibrationDriver::~TTofpetCalibrationDriver() {
	// TODO Auto-generated destructor stub
}

int TTofpetCalibrationDriver::startOfData(){

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
	m_detector=m_manager->getDetector();


	m_Nsteps=m_TTofpetRun->getNsteps();
	m_Nchannels=m_detector->getTotPixels();

	if (m_manager->getVerboseLevel()>TJobManager::normalVerbosity) Info("startOfData","There are: %i steps and %i pixels",m_Nsteps,m_Nchannels);

	m_NhToT0=m_Nsteps*m_Nchannels;
	m_NhToTCalib=m_Nchannels*m_TTofpetRun->getNsteps1();

	hToT0=new TH1D*[m_NhToT0];
	id=0;
	for (int ich=0;ich<m_Nchannels;ich++){
		for (int istep=0;istep<m_Nsteps;istep++){
			step1=m_TTofpetRun->getStep1(istep);
			step2=m_TTofpetRun->getStep2(istep);
			hToT0[id]=new TH1D(Form("hToT0_step1:%i_step2:%i_ch:%i",step1,step2,ich),Form("hToT0_step1:%i_step2:%i_ch:%i",step1,step2,ich),m_hToT0_nbins,m_hToT0_min,m_hToT0_max);
			m_manager->GetOutputList()->Add(hToT0[id]);
			id++;
		}
	}

	hToTCalib=new TH2D*[m_NhToTCalib];
	id=0;
	for (int ich=0;ich<m_Nchannels;ich++){
		for (int istep1=0;istep1<m_TTofpetRun->getNsteps1();istep1++){
			step1=m_TTofpetRun->getStep1(istep1);
			hToTCalib[id]=new TH2D(Form("hToTCalib_step1:%i_ch:%i",step1,ich),Form("hToTCalib_step1:%i_ch:%i",step1,ich),m_hToT0_nbins,m_hToT0_min,m_hToT0_max,64,-0.5,63.5);
			m_manager->GetOutputList()->Add(hToTCalib[id]);
			id++;
		}
	}


}

int TTofpetCalibrationDriver::process(TEvent *event){
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
			id=ch+m_Nchannels*istep;
			id1=ch+m_Nchannels*istep1;
			hToT0[id]->Fill(hit->getToT());
			hToTCalib[id1]->Fill(hit->getToT(),step2);
		}
	}

}

int TTofpetCalibrationDriver::end(){

	int id;

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
	m_detector=m_manager->getDetector();


	m_Nsteps=m_TTofpetRun->getNsteps();
	m_Nchannels=m_detector->getTotPixels();


	m_NhToT0=m_Nsteps*m_Nchannels;
	m_NhToTCalib=m_Nchannels*m_TTofpetRun->getNsteps1();

	hToT0=new TH1D*[m_NhToT0];
	hToTCalib=new TH2D*[m_NhToTCalib];
	id=0;
	for (int ich=0;ich<m_Nchannels;ich++){
		for (int istep1=0;istep1<m_TTofpetRun->getNsteps1();istep1++){
			hToTCalib[id]=(TH2D*)(m_manager->GetOutputList()->FindObject(Form("hToTCalib_step1:%i_ch:%i",istep1,ich)));
			id++;
		}
	}

}
