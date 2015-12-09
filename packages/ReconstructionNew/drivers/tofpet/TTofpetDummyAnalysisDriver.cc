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

}

TTofpetDummyAnalysisDriver::~TTofpetDummyAnalysisDriver() {
	// TODO Auto-generated destructor stub
}

int TTofpetDummyAnalysisDriver::process(TEvent *event){
	TClonesArray *TofpetHitCollection;
	TIter		 *TofpetHitCollectionIter;
	TTofpetHit   *hit;
	TTofpetEventHeader *header=0;

	int N,step1,step2;


	header=(TTofpetEventHeader*)event->getEventHeader();
	if (header==0){
		Error("process","no event header!");
	}
	step1=header->getStep1();
	step2=header->getStep2();

	if (event->hasCollection(TTofpetHit::Class(),m_collectionRawName)){
		TofpetHitCollection=event->getCollection(TTofpetHit::Class(),m_collectionRawName);
		N=TofpetHitCollection->GetEntries();
		TofpetHitCollectionIter=new TIter(TofpetHitCollection);

		hMultiplicity0->Fill(step1,N);
		while (hit = (TTofpetHit*)TofpetHitCollectionIter->Next()){
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

	hMultiplicity0=new TH2D("hMultiplicity0","hMultiplicity;step1;step2",64,-0.5,64-0.5,64,-0.5,64-0.5);

	m_manager->GetOutputList()->Add(hMultiplicity0);
	if (m_manager->hasObject(TTofpetSetup::Class())){
		m_TofpetSetup=(TTofpetSetup*)(m_manager->getObject(TTofpetSetup::Class()));
		m_Nsteps=m_TofpetSetup->getNsteps();
		if (m_manager->getVerboseLevel()>TJobManager::normalVerbosity){
			Info("startOfData","Got TTofpetSetup. Number of steps: %i",m_Nsteps);
			for (int ii=0;ii<m_Nsteps;ii++){
				printf("Step %i: step1: %i, step2: %i \n",ii,m_TofpetSetup->getStep1(ii),m_TofpetSetup->getStep2(ii));
			}

		}
	}


	return 0;
}
