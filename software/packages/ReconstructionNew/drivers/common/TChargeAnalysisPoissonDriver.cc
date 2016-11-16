/*
 * TChargeAnalysisPoissonDriver.cc
 *
 *  Created on: Dec 3, 2015
 *      Author: celentan
 */



#include <iostream>
#include <string>

#include "TClonesArray.h"
#include "TList.h"
#include "TApplication.h"
#include "TH1D.h"
#include "TH2D.h"
#include "TCanvas.h"
#include "TVector3.h"
#include "TLorentzVector.h"

#include "TChargeAnalysisPoissonDriver.hh"
#include "OpNoviceDigi.hh"
#include "TDriver.hh"
#include "TEvent.hh"
#include "TJobManager.hh"
#include "TDetector.hh"
using namespace std;



TChargeAnalysisPoissonDriver::TChargeAnalysisPoissonDriver() {
	// TODO Auto-generated constructor stub
	// TODO Auto-generated constructor stub
	m_nPixels=0;
	m_nDetectors=0;
	for (int ii=0;ii<6;ii++){
		for (int jj=0;jj<MAX_DETECTORS;jj++){
			hPixels2D[ii][jj]=0;
		}
	}
	hPixelsMC=0;
	m_eventsProduced=0;

}

TChargeAnalysisPoissonDriver::~TChargeAnalysisPoissonDriver() {
	// TODO Auto-generated destructor stub
}


void TChargeAnalysisPoissonDriver::setWriteOutFileName(const char *fname){
	m_writeOutFileName=string(fname);

	/*Also open it*/
	if	(m_writeOutFile) m_writeOutFile.close();
	m_writeOutFile.open(m_writeOutFileName.c_str());
}



int TChargeAnalysisPoissonDriver::process(TEvent *event){

	TClonesArray *digiCollection;
	TIter		 *digiCollectionIter;
	OpNoviceDigi *digi;
	TVector3 xIn,xOut,x0;
	int face,detector,pixel,nPhe,nX,nY,ID;
	double meanModel;
	m_Q.clear();
	m_Q.resize(m_manager->getDetector()->getTotPixels(),0);




	if (event->hasCollection(OpNoviceDigi::Class(),m_collectionName)){
		digiCollection=event->getCollection(OpNoviceDigi::Class(),m_collectionName);
		digiCollectionIter=new TIter(digiCollection);
		while (digi = (OpNoviceDigi*)digiCollectionIter->Next()){
			face=digi->GetFaceNumber();
			detector=digi->GetDetectorNumber();
			pixel=digi->GetPixelNumber();
			nPhe=digi->GetPheCount();
			nX=m_manager->getDetector()->getNPixelsX(face,detector);
			nY=m_manager->getDetector()->getNPixelsY(face,detector);
			ID=m_manager->getDetector()->getPixelGlobalID(face,detector,pixel);
			hPixels2D[face][detector]->Fill(pixel%nX,pixel/nX,nPhe);
			m_Q.at(ID)=nPhe;
		}
	}




	return 0;
}

















int TChargeAnalysisPoissonDriver::start(){
	Info("start","start");
	if (m_manager->getVerboseLevel()>=TJobManager::normalVerbosity){
		m_manager->getDetector()->Print();
	}
	return 0;
}
int TChargeAnalysisPoissonDriver::startOfData(){
	Info("startOfData","start");
	int nX,nY;
	m_nPixels=m_manager->getDetector()->getTotPixels();
	m_nDetectors=m_manager->getDetector()->getTotDetectors();

	/*Here I need to create the histogram with the pixels count
	I have faces,detectors,pixels
	 //	TODO: not parellelepied?
	 */

	if (m_manager->getVerboseLevel()>=TJobManager::normalVerbosity){
		Info("startOfData","hPixels created with %i pixels",m_nPixels);
	}
	hPixelsMC=new TH1D("hPixelsMC","hPixelsMC",m_nPixels,-0.5,m_nPixels-0.5);


	m_manager->GetOutputList()->Add(hPixelsMC);




	//Histograms
	for (int ii=0;ii<6;ii++){
		for (int jj=0;jj<m_manager->getDetector()->getNdet(ii);jj++){
			if (m_manager->getDetector()->isDetPresent(ii,jj)){
				nX=m_manager->getDetector()->getNPixelsX(ii,jj);
				nY=m_manager->getDetector()->getNPixelsY(ii,jj);
				hPixels2D[ii][jj]=new TH2D(Form("hPixel0_%i_%i",ii,jj),Form("hPixel0_%i_%i",ii,jj),nX,-0.5,nX-0.5,nY,-0.5,nY-0.5);
				m_manager->GetOutputList()->Add(hPixels2D[ii][jj]); //VERY IMPORTANT: fill output list
			}
		}
	}

	return 0;
}


int TChargeAnalysisPoissonDriver::end(){
	int ID;
	double mean;
	double data;

	hPixelsMC=(TH1D*)(m_manager->GetOutputList()->FindObject("hPixelsMC"));
	hPixelsMC->Scale(1./m_manager->getNumberOfEvents());

	for (int ii=0;ii<6;ii++){
		for (int jj=0;jj<m_manager->getDetector()->getNdet(ii);jj++){
			if (m_manager->getDetector()->isDetPresent(ii,jj)){
				hPixels2D[ii][jj]=(TH2D*)(m_manager->GetOutputList()->FindObject(Form("hPixel0_%i_%i",ii,jj)));
				hPixels2D[ii][jj]->Scale(1./m_manager->getNumberOfEvents());
				for (int kk=0;kk<m_manager->getDetector()->getNPixels(ii,jj);kk++){
					ID=m_manager->getDetector()->getPixelGlobalID(ii,jj,kk);
					m_Q.at(ID)/=m_manager->getNumberOfEvents();
				}
			}
		}
	}

	for (int ii=0;ii<m_eventsProduced;ii++){
		for (int ipixel=0;ipixel<m_Q.size();ipixel++){
				mean=m_Q.at(ipixel);
				data=m_manager->getRandomGenerator()->Poisson(mean);
				m_writeOutFile<<data<<" ";
			}
			m_writeOutFile<<endl;
	}
	return 0;
}











