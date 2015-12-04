/*
 * TTofpetDummyAnalysis.cc
 *
 *  Created on: Dec 4, 2015
 *      Author: celentan
 */

#include "TTofpetDummyAnalysisDriver.hh"


#include "TEvent.hh"
#include "TTofpetEventHeader.hh"
#include "TTofpetHit.hh"
#include "TJobManager.hh"

#include "TH1D.h"
#include "TH2D.h"

TTofpetDummyAnalysisDriver::TTofpetDummyAnalysisDriver() {
	// TODO Auto-generated constructor stub
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



	return 0;
}
