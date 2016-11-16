/*
 * TDataReaderMaroc.cc
 *
 *  Created on: Mar 7, 2016
 *      Author: celentan
 */

#include "TMarocDataReaderDriver.hh"

#include "TMarocHit.hh"
#include "TMarocSetupHandler.hh"
#include "TMarocEventHeader.hh"
#include "TReconHit.hh"


TMarocDataReaderDriver::TMarocDataReaderDriver() {
	// TODO Auto-generated constructor stub
	m_reconHitCollection=0;
	m_marocSetupHandler=0;
	m_marocEventHeader=0;

	m_ChargeCutMin=-1;
	m_ChargeCutMax=9999999;
	m_MultCutMin=-1;
	m_MultCutMax=999;
}

TMarocDataReaderDriver::~TMarocDataReaderDriver() {
	// TODO Auto-generated destructor stub
}

int TMarocDataReaderDriver::process(TEvent* event) {
	TClonesArray *hitCollection;
	TIter		 *hitCollectionIter;
	TMarocHit	 *hit;
	TReconHit 	 *rhit;
	int face,detector,pixel,nPhe,ID,realDet;
	bool isHit;
	double Q,T;
	int jj;

	int multiplicity;
	double Qtot;

	m_marocEventHeader=(TMarocEventHeader*)event->getEventHeader();
	if (m_marocEventHeader==0){
		Error("process","no event header!");
		return 0;
	}
	multiplicity=m_marocEventHeader->getMultiplicity();


	if (event->hasCollection(TMarocHit::Class(),m_collectionRawName)){
		m_reconHitCollection->Clear("C"); //fundamental instruction
		hitCollection=event->getCollection(TMarocHit::Class(),m_collectionRawName);
		hitCollectionIter=new TIter(hitCollection);
		jj=0;
		Qtot=0;
		while (hit = (TMarocHit*)hitCollectionIter->Next()){

			ID = hit->getMarocId();
			pixel=m_marocSetupHandler->getPixelReconId(ID);
			realDet=m_marocSetupHandler->getMarocCard(ID);
			detector=m_marocSetupHandler->getReconstructionDetectorID(realDet);
			face=m_marocSetupHandler->getReconstructionDetectorFace(realDet);

			Q=hit->getCharge();
			T=0;
			nPhe=0;
			isHit=hit->isHit();

			Qtot+=Q;

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

		//	if ((Qtot<0.18E6)||(Qtot>0.184E6)||(multiplicity<35)||(multiplicity>50)){  //alphaCenter ///TODO: temporary!!!
		//	if ((Qtot<0.181E6)||(Qtot>0.185E6)||(multiplicity<30)||(multiplicity>45)){   //xp10y0///TODO: temporary!!!
		//	if ((Qtot<0.1805E6)||(Qtot>0.184E6)||(multiplicity<30)||(multiplicity>50)){  //x0ym10///TODO: temporary!!!
		//			if ((Qtot<0.179E6)||(Qtot>0.183E6)||(multiplicity<30)||(multiplicity>45)){  //xm15ym15 ///TODO: temporary!!!

		if ((Qtot>m_ChargeCutMin)&&(Qtot<m_ChargeCutMax)&&(multiplicity>=m_MultCutMin)&&(multiplicity<=m_MultCutMax)){
			event->addCollection(m_reconHitCollection);
		}
		return 0;

	}

}

int TMarocDataReaderDriver::startOfData() {


	m_reconHitCollection=new TClonesArray("TReconHit",100); /*If more than s objects are entered, the array will be automatically expanded*/
	Info("startOfData","Collections created");

	m_reconHitCollection->SetName(m_collectionOutName.c_str());
	Info("startOfData","Collections named");


	if (m_manager->hasObject(TMarocSetupHandler::Class())){
		m_marocSetupHandler=(TMarocSetupHandler*)(m_manager->getObject(TMarocSetupHandler::Class()));
	}
	else{
		Error("startOfData","No TMarocSetup found. Have you activated (before this!) the TMarocSetupHandlerDriver?");
		return -1;
	}

	/*A.C. terrible!*/
	double PmtDA0359[TMarocSetupHandler::nH8500Pixels]={76,79,86,96,100,95,88,83,76,71,80,89,95,89,87,82,75,68,82,87,92,91,81,77,71,64,79,83,88,88,75,74,69,63,74,79,78,83,73,70,68,61,71,75,76,73,68,65,63,60,65,69,66,62,59,60,61,64,66,70,65,60,56,52};
	double PmtDA0361[TMarocSetupHandler::nH8500Pixels]={56,71,76,81,89,87,78,82,61,66,72,77,82,78,76,85,60,64,72,74,75,81,80,88,61,65,70,72,73,82,82,93,63,66,71,72,73,85,86,99,68,68,77,75,82,91,89,100,73,75,83,88,95,97,92,99,60,73,80,85,92,99,90,71};
	double PmtDA0349[TMarocSetupHandler::nH8500Pixels]={74,66,65,68,73,74,75,83,74,63,62,69,71,76,74,78,73,66,65,68,76,80,77,78,75,68,68,89,76,82,76,77,80,74,75,72,74,81,77,78,89,81,82,80,81,82,79,82,98,90,88,86,89,88,84,90,100,94,91,89,93,91,91,96};

	int iReconPixel,iMarocChannel,iReconFace,iReconDet;

	for (int ii=0;ii<TMarocSetupHandler::nH8500Pixels;ii++){
		iReconPixel=m_marocSetupHandler->getPixelReconId(32,ii);
		iMarocChannel=m_marocSetupHandler->getMarocChannelFromH8500(ii);
		iReconFace=m_marocSetupHandler->getReconstructionDetectorFace(32);
		iReconDet=m_marocSetupHandler->getReconstructionDetectorID(32);
		m_marocSetupHandler->setPixelGain(iReconFace,iReconDet,iReconPixel,1,PmtDA0359[ii]/100.);
		//m_marocSetupHandler->setPixelGain(iReconFace,iReconDet,iReconPixel,3,0.62); /*This is the gain configuration PMT359 vs PMT361*/
		m_marocSetupHandler->setPixelGain(iReconFace,iReconDet,iReconPixel,2,.5);


		iReconPixel=m_marocSetupHandler->getPixelReconId(33,ii);
		iMarocChannel=m_marocSetupHandler->getMarocChannelFromH8500(ii);
		iReconFace=m_marocSetupHandler->getReconstructionDetectorFace(33);
		iReconDet=m_marocSetupHandler->getReconstructionDetectorID(33);
		m_marocSetupHandler->setPixelGain(iReconFace,iReconDet,iReconPixel,1,PmtDA0361[ii]/100.);
		//m_marocSetupHandler->setPixelGain(iReconFace,iReconDet,iReconPixel,3,1.); /*This is the gain configuration PMT359 vs PMT361*/
		m_marocSetupHandler->setPixelGain(iReconFace,iReconDet,iReconPixel,2,.5);

		iReconPixel=m_marocSetupHandler->getPixelReconId(34,ii);
		iMarocChannel=m_marocSetupHandler->getMarocChannelFromH8500(ii);
		iReconFace=m_marocSetupHandler->getReconstructionDetectorFace(34);
		iReconDet=m_marocSetupHandler->getReconstructionDetectorID(34);
		m_marocSetupHandler->setPixelGain(iReconFace,iReconDet,iReconPixel,1,PmtDA0349[ii]/100.);
		//m_marocSetupHandler->setPixelGain(iReconFace,iReconDet,iReconPixel,3,.82); /*This is the gain configuration PMT349 vs PMT361*/
		m_marocSetupHandler->setPixelGain(iReconFace,iReconDet,iReconPixel,2,.5);

	}



}
