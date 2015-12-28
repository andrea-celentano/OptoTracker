/*
 * TTofpetStepsEventCounter.cc
 *
 *  Created on: Dec 21, 2015
 *      Author: celentan
 */

#include "TTofpetStepsEventCounter.hh"
#include "TEvent.hh"
#include "TofpetSetupHandler.hh"
#include "TTofpetRun.hh"

#include "TTofpetHit.hh"
#include "TTofpetEventHeader.hh"
#include "TJobManager.hh"

TTofpetStepsEventCounter::TTofpetStepsEventCounter() {
	// TODO Auto-generated constructor stub
	hStepsNevents=0;
	m_TofpetRun=0;
}

TTofpetStepsEventCounter::~TTofpetStepsEventCounter() {
	// TODO Auto-generated destructor stub
}


int TTofpetStepsEventCounter::startOfData(){
	Info("startOfData","start");

	if (m_manager->hasObject(TTofpetRun::Class())){
		m_TofpetRun=(TTofpetRun*)(m_manager->getObject(TTofpetRun::Class()));
	}




	hStepsNevents=new TH2D("hStepsNevents","hStepsNevents",64,-0.5,64-0.5,64,-0.5,64-0.5);
	return 0;
}


int TTofpetStepsEventCounter::process(TEvent *event){
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

	hStepsNevents->Fill(step1,step2);


	return 0;
}
