/*
 * TCitirocBasicDriver.cc
 *
 *  Created on: Mar 3, 2016
 *      Author: celentan
 */

#include "TCitirocBasicDriver.hh"
#include "TCitirocEventHeader.hh"
#include "TCitirocHitRaw.hh"
#include "TCitirocSetupHandler.hh"
#include "TH1D.h"
#include "TH2D.h"

TCitirocBasicDriver::TCitirocBasicDriver() {
	// TODO Auto-generated constructor stub

	hQvsCh0=0;
	hQvsCh1=0;
	hQvsCh2=0;
	hQvsCh3=0;
}

TCitirocBasicDriver::~TCitirocBasicDriver() {
	// TODO Auto-generated destructor stub
}

int TCitirocBasicDriver::startOfData(){
	Info("startOfData","start");

	hQvsCh0=new TH2D("hQvsCh0","hQvsCh0",1024,-0.5,1023.5,4096,-0.5,4095.5);	m_manager->GetOutputList()->Add(hQvsCh0);
	hQvsCh1=new TH2D("hQvsCh1","hQvsCh1",1024,-0.5,1023.5,4096,-0.5,4095.5);	m_manager->GetOutputList()->Add(hQvsCh1);
	hQvsCh2=new TH2D("hQvsCh2","hQvsCh2",1024,-0.5,1023.5,4096,-0.5,4095.5);	m_manager->GetOutputList()->Add(hQvsCh2);
	hQvsCh3=new TH2D("hQvsCh3","hQvsCh3",1024,-0.5,1023.5,4096,-0.5,4095.5);	m_manager->GetOutputList()->Add(hQvsCh3);

	return 0;
}


int TCitirocBasicDriver::end(){
	Info("end","end starts now");
	//hMultiplicity0=(TH1D*)m_manager->GetOutputList()->FindObject("hMultiplicity0");

	return 0;
}

int TCitirocBasicDriver::process(TEvent *event){
	TClonesArray *TCitirocHitCollection;
	TIter		 *TCitirocHitCollectionIter;
	TCitirocHitRaw   *hit;
	TCitirocEventHeader *header=0;

	int N;
	double Q;
	int channel,ID;
	int Ts0;
	header=(TCitirocEventHeader*)event->getEventHeader();
	if (header==0){
		Error("process","no event header!");
	}
	N=header->getMultiplicity();
	Ts0=header->getTs0();

	if (event->hasCollection(TCitirocHitRaw::Class(),m_collectionRawName)){
		TCitirocHitCollection=event->getCollection(TCitirocHitRaw::Class(),m_collectionRawName);
		TCitirocHitCollectionIter=new TIter(TCitirocHitCollection);
		while (hit = (TCitirocHitRaw*)TCitirocHitCollectionIter->Next()){
			Q=hit->getCharge();
			channel=hit->getChannel();
			ID=hit->getMAC();
			hQvsCh0->Fill(channel+ID*TCitirocSetupHandler::nCitirocChannelsPerBoard,Q);
			if (N>=2) hQvsCh1->Fill(channel+ID*TCitirocSetupHandler::nCitirocChannelsPerBoard,Q);
			else hQvsCh2->Fill(channel+ID*TCitirocSetupHandler::nCitirocChannelsPerBoard,Q);
			if (Ts0==0) hQvsCh3->Fill(channel+ID*TCitirocSetupHandler::nCitirocChannelsPerBoard,Q);
		}
		delete TCitirocHitCollectionIter;
	}
	return 0;
}
