/*
 * TMarocBasicDriver.cc
 *
 *  Created on: Mar 3, 2016
 *      Author: celentan
 */

#include "TMarocBasicDriver.hh"
#include "TMarocEventHeader.hh"
#include "TMarocHit.hh"

#include "TH1D.h"
#include "TH2D.h"

TMarocBasicDriver::TMarocBasicDriver() {
	// TODO Auto-generated constructor stub
	hMultiplicity0=0;
	hQTot0=0;
	hQTotvsMultiplicity0=0;
}

TMarocBasicDriver::~TMarocBasicDriver() {
	// TODO Auto-generated destructor stub
}

int TMarocBasicDriver::startOfData(){
	Info("startOfData","start");
	hMultiplicity0=new TH1D("hMultiplicity0","hMultiplicity0",129,-0.5,128.5);
	m_manager->GetOutputList()->Add(hMultiplicity0);


	hQTot0=new TH1D("hQTot0","hQTot0",1000,0,.5E6);
	m_manager->GetOutputList()->Add(hQTot0);

	hQTotvsMultiplicity0=new TH2D("hQTotvsMultiplicity0","hQTotvsMultiplicity0",400,0,.2E6,129,-0.5,128.5);
	m_manager->GetOutputList()->Add(hQTotvsMultiplicity0);

	return 0;
}


int TMarocBasicDriver::end(){
	Info("end","end starts now");
	//hMultiplicity0=(TH1D*)m_manager->GetOutputList()->FindObject("hMultiplicity0");

	return 0;
}

int TMarocBasicDriver::process(TEvent *event){
	TClonesArray *TMarocHitCollection;
	TIter		 *TMarocHitCollectionIter;
	TMarocHit   *hit;
	TMarocEventHeader *header=0;

	int N;
	double QTot0;

	header=(TMarocEventHeader*)event->getEventHeader();
	if (header==0){
		Error("process","no event header!");
	}
	N=header->getMultiplicity();
	hMultiplicity0->Fill(header->getMultiplicity());

	if (event->hasCollection(TMarocHit::Class(),m_collectionRawName)){
		TMarocHitCollection=event->getCollection(TMarocHit::Class(),m_collectionRawName);
		TMarocHitCollectionIter=new TIter(TMarocHitCollection);

		QTot0=0;
		while (hit = (TMarocHit*)TMarocHitCollectionIter->Next()){

			QTot0+=hit->getCharge();

		}

		hQTot0->Fill(QTot0);
		hQTotvsMultiplicity0->Fill(QTot0,N);
		delete TMarocHitCollectionIter;
	}
	return 0;
}
