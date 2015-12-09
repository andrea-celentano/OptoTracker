/*
 * TTofpetDummyAnalysis.cc
 *
 *  Created on: Dec 4, 2015
 *      Author: celentan
 */

#include "TTofpetDummyAnalysisDriver.hh"
#include "TTofpetSetup.hh"

#include "TEvent.hh"
#include "TTofpetEventHeader.hh"
#include "TTofpetHit.hh"
#include "TJobManager.hh"

#include "TH1D.h"
#include "TH2D.h"

TTofpetDummyAnalysisDriver::TTofpetDummyAnalysisDriver() {
	// TODO Auto-generated constructor stub
	m_TofpetSetup=0;
	hMultiplicity0=0;
	hToT=0;
}

TTofpetDummyAnalysisDriver::~TTofpetDummyAnalysisDriver() {
	// TODO Auto-generated destructor stub
}

int TTofpetDummyAnalysisDriver::process(TEvent *event){
	TClonesArray *TofpetHitCollection;
	TIter		 *TofpetHitCollectionIter;
	TTofpetHit   *hit;
	TTofpetEventHeader *header=0;

	int N,step1,step2,id;


	header=(TTofpetEventHeader*)event->getEventHeader();
	if (header==0){
		Error("process","no event header!");
	}
	step1=header->getStep1();
	step2=header->getStep2();
	id=m_TofpetSetup->getStepID(step1,step2);
	if (event->hasCollection(TTofpetHit::Class(),m_collectionRawName)){
		TofpetHitCollection=event->getCollection(TTofpetHit::Class(),m_collectionRawName);
		N=TofpetHitCollection->GetEntries();
		TofpetHitCollectionIter=new TIter(TofpetHitCollection);


		while (hit = (TTofpetHit*)TofpetHitCollectionIter->Next()){
			hToT[id]->Fill(hit->getChannel(),hit->getToT());
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

	int step1,step2;

	hMultiplicity0=new TH2D*[128];
	for (int ii=0;ii<128;ii++){  ///TODO: Do this better
		hMultiplicity0[ii]=new TH2D(Form("hMultiplicity0_%i",ii),Form("hMultiplicity0_%i;step1;step2",ii),64,-0.5,64-0.5,64,-0.5,64-0.5);
		m_manager->GetOutputList()->Add(hMultiplicity0[ii]);
	}


	if (m_manager->hasObject(TTofpetSetup::Class())){
		m_TofpetSetup=(TTofpetSetup*)(m_manager->getObject(TTofpetSetup::Class()));
		m_Nsteps=m_TofpetSetup->getNsteps();
		hToT=new TH2D*[m_Nsteps];

		if (m_manager->getVerboseLevel()>TJobManager::normalVerbosity)	Info("startOfData","Got TTofpetSetup. Number of steps: %i",m_Nsteps);

		for (int ii=0;ii<m_Nsteps;ii++){
			step1=m_TofpetSetup->getStep1(ii);
			step2=m_TofpetSetup->getStep2(ii);

			if (m_manager->getVerboseLevel()>TJobManager::normalVerbosity)	printf("Step %i: step1: %i, step2: %i \n",ii,step1,step2);

			hToT[ii]=new TH2D(Form("hTot_%i_%i",step1,step2),Form("hTot_%i_%i",step1,step2),128,-0.5,127.5,1000,-500,500);
			m_manager->GetOutputList()->Add(hToT[ii]);
		}
	}


	return 0;
}

int TTofpetDummyAnalysisDriver::end(){
	int step1,step2,N;

	for (int istep=0;istep<m_Nsteps;istep++){
		step1=m_TofpetSetup->getStep1(istep);
		step2=m_TofpetSetup->getStep2(istep);
		hToT[istep]=(TH2D*)m_manager->GetOutputList()->FindObject(Form("hTot_%i_%i",step1,step2));
		for (int ii=0;ii<128;ii++){  ///TODO: Do this better
			N=hToT[istep]->ProjectionY("",ii+1,ii+1,"")->GetEntries();
			hMultiplicity0[ii]=(TH2D*)m_manager->GetOutputList()->FindObject(Form("hMultiplicity0_%i",ii));
			hMultiplicity0[ii]->Fill(step1,step2,N);
		}//end loop on channels
	}//end loop on steps
}
