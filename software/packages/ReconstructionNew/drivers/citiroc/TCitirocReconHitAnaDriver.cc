/*
 * TCitirocReconHitAnaDriver.cc
 *
 *  Created on: Mar 3, 2016
 *      Author: celentan
 */

#include "TCitirocReconHitAnaDriver.hh"
#include "TCitirocEventHeader.hh"
#include "TCitirocHitRaw.hh"
#include "TCitirocSetupHandler.hh"
#include "TReconHit.hh"

#include "TH1D.h"
#include "TH2D.h"

TCitirocReconHitAnaDriver::TCitirocReconHitAnaDriver() {
	// TODO Auto-generated constructor stub
	hTmp=0;
	hTmp2=0;
}

TCitirocReconHitAnaDriver::~TCitirocReconHitAnaDriver() {
	// TODO Auto-generated destructor stub
}

int TCitirocReconHitAnaDriver::startOfData(){
	Info("startOfData","start");

	hTmp=new TH2D("h","h",20,-0.5,19.5,1024,-0.5,4095.5);m_manager->GetOutputList()->Add(hTmp);
	hTmp2=new TH2D("h2","h2",20,-0.5,19.5,20,-0.5,19.5);m_manager->GetOutputList()->Add(hTmp2);
	return 0;
}


int TCitirocReconHitAnaDriver::end(){
	Info("end","end starts now");
	//hMultiplicity0=(TH1D*)m_manager->GetOutputList()->FindObject("hMultiplicity0");

	return 0;
}

int TCitirocReconHitAnaDriver::process(TEvent *event){
	TClonesArray *TReconHitCollection;
	TIter		 *TReconHitCollectionIter;
	TReconHit   *hit;
	TCitirocEventHeader *header=0;

	int face,detector,pixel;
	double Q;
	int nPhe;
	int N;

	int N1,N2;

	header=(TCitirocEventHeader*)event->getEventHeader();
	if (header==0){
		Error("process","no event header!");
	}
	N=header->getMultiplicity();

	N1=-10;
	N2=-10;
	if (event->hasCollection(TReconHit::Class(),m_collectionName)){
		TReconHitCollection=event->getCollection(TReconHit::Class(),m_collectionName);
		TReconHitCollectionIter=new TIter(TReconHitCollection);
		while (hit = (TReconHit*)TReconHitCollectionIter->Next()){
			Q=hit->getQ();
			face=hit->getFace();
			detector=hit->getDetector();
			pixel=hit->getPixel();
			nPhe=hit->getPhe();

			if ((detector==0)&&(face==0)&&(pixel==0)){
				hTmp->Fill(nPhe,Q);
				N1=nPhe;
			}
			if ((detector==0)&&(face==0)&&(pixel==32)){
				N2=nPhe;
			}
		}
		if ((N1>=0)&&(N2>=0)) hTmp2->Fill(N1,N2);
		delete TReconHitCollectionIter;
	}
	return 0;
}
