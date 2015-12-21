/*
 * TTofpetDummyAnalysis.cc
 *
 *  Created on: Dec 4, 2015
 *      Author: celentan
 */

#include "TH1D.h"
#include "TH2D.h"


#include "TTofpetDummyAnalysisDriver.hh"
#include "TTofpetRun.hh"

#include "TEvent.hh"
#include "TTofpetEventHeader.hh"
#include "TTofpetHit.hh"
#include "TJobManager.hh"
#include "TofpetSetupHandler.hh"

TTofpetDummyAnalysisDriver::TTofpetDummyAnalysisDriver() {
	// TODO Auto-generated constructor stub
	m_TofpetRun=0;
	hMultiplicity0=0;
	hMultiplicityAverage=0;
	hToT0=0;
	hToT1=0;
}

TTofpetDummyAnalysisDriver::~TTofpetDummyAnalysisDriver() {
	// TODO Auto-generated destructor stub
}

int TTofpetDummyAnalysisDriver::process(TEvent *event){
	TClonesArray *TofpetHitCollection;
	TIter		 *TofpetHitCollectionIter;
	TTofpetHit   *hit;
	TTofpetEventHeader *header=0;

	int N,step1,step2,id,id1,ch,ix,iy;



	header=(TTofpetEventHeader*)event->getEventHeader();
	if (header==0){
		Error("process","no event header!");
	}
	step1=header->getStep1();
	step2=header->getStep2();
	id=m_TofpetRun->getStepID(step1,step2);
	id1=m_TofpetRun->getStep1ID(step1);
	if (event->hasCollection(TTofpetHit::Class(),m_collectionRawName)){
		TofpetHitCollection=event->getCollection(TTofpetHit::Class(),m_collectionRawName);
		N=TofpetHitCollection->GetEntries();
		TofpetHitCollectionIter=new TIter(TofpetHitCollection);

		hMultiplicity0[id]->Fill(N);
		while (hit = (TTofpetHit*)TofpetHitCollectionIter->Next()){

			ch=hit->getChannel();
			ix=hit->getXi();
			iy=hit->getYi();
			hToT0[id]->Fill(ix,iy,hit->getToT());
			hToT1[id1*128+ch]->Fill(hit->getToT(),step2);
			//cout<<hit->getChannel()<<" "<<hit->getToT()<<endl;
		}
	}
	else{
		Error("process","no collection with class TTofpetHit and name %s was found",m_collectionRawName.c_str());
	}

	return 0;
}

int TTofpetDummyAnalysisDriver::startOfData(){
	Info("startOfData","start");

	int step1,step2,N;

	hMultiplicityAverage=new TH2D("hMultiplicityAverage","hMultiplicityAverage",64,-0.5,63.5,64,-0.5,63.5);
	m_manager->GetOutputList()->Add(hMultiplicityAverage);

	if (m_manager->hasObject(TTofpetRun::Class())){
		m_TofpetRun=(TTofpetRun*)(m_manager->getObject(TTofpetRun::Class()));
		m_Nsteps=m_TofpetRun->getNsteps();
		if (m_manager->getVerboseLevel()>TJobManager::normalVerbosity)	Info("startOfData","Got TTofpetSetup. Number of steps: %i",m_Nsteps);

		hToT0=new TH2D*[m_Nsteps];
		hToT1=new TH2D*[128*m_TofpetRun->getNsteps1()];
		hMultiplicity0=new TH1D*[m_Nsteps];

		for (int ii=0;ii<m_Nsteps;ii++){
			step1=m_TofpetRun->getStep1(ii);
			step2=m_TofpetRun->getStep2(ii);
			N=m_TofpetRun->getStepNevents(step1,step2);

			if (m_manager->getVerboseLevel()>TJobManager::normalVerbosity)	printf("Step %i: step1: %i, step2: %i, events: %i \n",ii,step1,step2,N);

			hMultiplicity0[ii]=new TH1D(Form("hMultiplicity0_%i_%i",step1,step2),Form("hMultiplicity0_%i_%i",step1,step2),128,-0.5,128.5);
			m_manager->GetOutputList()->Add(hMultiplicity0[ii]);

		}
		for (int ii=0;ii<m_Nsteps;ii++){
			step1=m_TofpetRun->getStep1(ii);
			step2=m_TofpetRun->getStep2(ii);

			hToT0[ii]=new TH2D(Form("hTot0_%i_%i",step1,step2),Form("hTot0_%i_%i",step1,step2),TofpetSetupHandler::nTofpetPixelsX,-0.5,TofpetSetupHandler::nTofpetPixelsX-0.5,TofpetSetupHandler::nTofpetPixelsY,-.5,TofpetSetupHandler::nTofpetPixelsY-.5);
			m_manager->GetOutputList()->Add(hToT0[ii]);
		}

		for (int ii=0;ii<m_TofpetRun->getNsteps1();ii++){
			for (int jj=0;jj<128;jj++){
				hToT1[ii*128+jj]=new TH2D(Form("hToT1_%i_%i",ii,jj),Form("hToT1_%i_%i",ii,jj),1000,-50,200,64,-0.5,63.5);
				m_manager->GetOutputList()->Add(hToT1[ii*128+jj]);
			}
		}
	}
	else{
		Error("startOfData","No TTofpetRun object in the file, should be there!");
		return -1;
	}


	return 0;
}

int TTofpetDummyAnalysisDriver::end(){
	int step1,step2;
	double N;

	hMultiplicityAverage=(TH2D*)m_manager->GetOutputList()->FindObject("hMultiplicityAverage");
	m_TofpetRun=(TTofpetRun*)m_manager->GetOutputList()->FindObject("TTofpetRun");

	for (int ii=0;ii<m_Nsteps;ii++){
		step1=m_TofpetRun->getStep1(ii);
		step2=m_TofpetRun->getStep2(ii);
		hMultiplicity0[ii]=(TH1D*)m_manager->GetOutputList()->FindObject(Form("hMultiplicity0_%i_%i",step1,step2));
		hToT0[ii]=(TH2D*)m_manager->GetOutputList()->FindObject(Form("hTot0_%i_%i",step1,step2));
		hToT0[ii]->Scale(1./m_TofpetRun->getStepNevents(step1,step2));
		N=hMultiplicity0[ii]->GetMean();
		hMultiplicityAverage->Fill(step1,step2,N);
	}
	return 0;
}
