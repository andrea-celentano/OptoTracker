/*
 * TDataReaderMC.cc
 *
 *  Created on: Mar 7, 2016
 *      Author: celentan
 */

#include "TMCDataReaderDriver.hh"

#include "TReconHit.hh"
#include "OpNoviceDigi.hh"


TMCDataReaderDriver::TMCDataReaderDriver() {
	// TODO Auto-generated constructor stub
	m_reconHitCollection=0;

}

TMCDataReaderDriver::~TMCDataReaderDriver() {
	// TODO Auto-generated destructor stub
}

int TMCDataReaderDriver::process(TEvent* event) {
	TClonesArray *digiCollection;
	TIter		 *digiCollectionIter;
	OpNoviceDigi *digi;
	TReconHit *hit;
	int face,detector,pixel,nPhe;
	bool isHit;
	double Q,T;
	int jj;





	if (event->hasCollection(OpNoviceDigi::Class(),m_collectionRawName)){
		m_reconHitCollection->Clear("C"); //fundamental instruction
		digiCollection=event->getCollection(OpNoviceDigi::Class(),m_collectionRawName);
		digiCollectionIter=new TIter(digiCollection);
		jj=0;
		while (digi = (OpNoviceDigi*)digiCollectionIter->Next()){
			face=digi->GetFaceNumber();
			detector=digi->GetDetectorNumber();
			pixel=digi->GetPixelNumber();
			nPhe=digi->GetPheCount();
			Q=digi->GetPheCount();
			T=digi->GetFirstHitTime();
			if (nPhe>0) isHit=true;

			/*Now put it!*/
			hit=(TReconHit*)m_reconHitCollection->ConstructedAt(jj++); //This creates a new TReconHit if necessary

			hit->setFace(face);
			hit->setDetector(detector);
			hit->setPixel(pixel);

			hit->setQ(Q);
			hit->setPhe(nPhe);
			hit->setT(T);
			hit->setHit(isHit);
		}

		event->addCollection(m_reconHitCollection);


	}

}

int TMCDataReaderDriver::startOfData() {
	m_reconHitCollection=new TClonesArray("TReconHit",100); /*If more than s objects are entered, the array will be automatically expanded*/
	Info("startOfData","Collections created");

	m_reconHitCollection->SetName(m_collectionOutName.c_str());
	Info("startOfData","Collections named");


}
