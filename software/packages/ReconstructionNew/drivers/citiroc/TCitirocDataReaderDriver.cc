/*
 * TDataReaderCitiroc.cc
 *
 *  Created on: Mar 7, 2016
 *      Author: celentan
 */

#include "TCitirocDataReaderDriver.hh"

#include "TCitirocHitRaw.hh"
#include "TCitirocSetupHandler.hh"
#include "TCitirocEventHeader.hh"
#include "TReconHit.hh"


TCitirocDataReaderDriver::TCitirocDataReaderDriver() {
	// TODO Auto-generated constructor stub
	m_reconHitCollection=0;
	m_citirocSetupHandler=0;
	m_citirocEventHeader=0;

	m_MultCutMin=-1;
	m_MultCutMax=999;
}

TCitirocDataReaderDriver::~TCitirocDataReaderDriver() {
	// TODO Auto-generated destructor stub
}

int TCitirocDataReaderDriver::process(TEvent* event) {
	TClonesArray *hitCollection;
	TIter		 *hitCollectionIter;
	TCitirocHitRaw	 *hit;
	TReconHit 	 *rhit;

	int ID,channel;
	int face,detector,pixel;

	int nPhe,realDet;
	bool isHit;
	double Q,T;
	int jj;

	int multiplicity;


	m_citirocEventHeader=(TCitirocEventHeader*)event->getEventHeader();
	if (m_citirocEventHeader==0){
		Error("process","no event header!");
		return 0;
	}
	multiplicity=m_citirocEventHeader->getMultiplicity();


	if (event->hasCollection(TCitirocHitRaw::Class(),m_collectionRawName)){
		m_reconHitCollection->Clear("C"); //fundamental instruction
		hitCollection=event->getCollection(TCitirocHitRaw::Class(),m_collectionRawName);
		hitCollectionIter=new TIter(hitCollection);
		jj=0;

		while (hit = (TCitirocHitRaw*)hitCollectionIter->Next()){

			ID = hit->getMAC();
			channel = hit->getChannel();

			face=m_citirocSetupHandler->getReconstructionDetectorID(ID);
			detector=m_citirocSetupHandler->getReconstructionDetectorID(ID);
			pixel=m_citirocSetupHandler->getReconstructionDetectorPixel(ID,channel);



			Q=hit->getCharge();
			T=0;
			nPhe=0;
			isHit=hit->isHit();



			/*Now put it!*/
			rhit=(TReconHit*)m_reconHitCollection->ConstructedAt(jj++); //This creates a new TReconHit if necessary

			rhit->setFace(face);
			rhit->setDetector(detector);
			rhit->setPixel(pixel);

			rhit->setQ(Q);
			rhit->setPhe(nPhe);
			rhit->setT(T);
			rhit->setHit(isHit);

		}
		if ((multiplicity>=m_MultCutMin)&&(multiplicity<=m_MultCutMax)){
			event->addCollection(m_reconHitCollection);
		}
		return 0;

	}

}

int TCitirocDataReaderDriver::startOfData() {


	m_reconHitCollection=new TClonesArray("TReconHit",100); /*If more than s objects are entered, the array will be automatically expanded*/
	Info("startOfData","Collections created");

	m_reconHitCollection->SetName(m_collectionOutName.c_str());
	Info("startOfData","Collections named");


	if (m_manager->hasObject(TCitirocSetupHandler::Class())){
		m_citirocSetupHandler=(TCitirocSetupHandler*)(m_manager->getObject(TCitirocSetupHandler::Class()));
	}
	else{
		Error("startOfData","No TCitirocSetup found. Have you activated (before this!) the TCitirocSetupHandlerDriver?");
		return -1;
	}
}
