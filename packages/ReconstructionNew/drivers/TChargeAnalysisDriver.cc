#include <iostream>
#include <string>

#include "TClonesArray.h"
#include "TList.h"
#include "TApplication.h"
#include "TH1D.h"
#include "TH2D.h"
#include "TCanvas.h"

#include "TChargeAnalysisDriver.hh"
#include "OpNoviceDigi.hh"
#include "TDriver.hh"
#include "TEvent.hh"
#include "TJobManager.hh"
#include "TDetectorLight.hh"


using namespace std;

TChargeAnalysisDriver::TChargeAnalysisDriver() {
	// TODO Auto-generated constructor stub
	hPixels=0;
	m_nPixels=0;
	m_nDetectors=0;
	for (int ii=0;ii<6;ii++){
		for (int jj=0;jj<MAX_DETECTORS;jj++){
			hPixels2D[ii][jj]=0;
		}
	}
	m_writeOut=0;
}

TChargeAnalysisDriver::~TChargeAnalysisDriver() {
	// TODO Auto-generated destructor stub
}

int TChargeAnalysisDriver::process(TEvent *event){

	TClonesArray *digiCollection;
	TIter		 *digiCollectionIter;
	OpNoviceDigi *digi;

	int face,detector,pixel,nPhe,nX,nY,ID;

	m_Q.clear();
	m_Q.resize(m_manager->getDetector()->getTotPixels(),0);

	if (event->hasCollection(OpNoviceDigi::Class(),"DetDigiMC")){
		digiCollection=event->getCollection(OpNoviceDigi::Class(),"DetDigiMC");
		digiCollectionIter=new TIter(digiCollection);
		while (digi = (OpNoviceDigi*)digiCollectionIter->Next()){
			face=digi->GetFaceNumber();
			detector=digi->GetDetectorNumber();
			pixel=digi->GetPixelNumber();
			nPhe=digi->GetPheCount();
			nX=m_manager->getDetector()->getNPixelsX(face,detector);
			nY=m_manager->getDetector()->getNPixelsY(face,detector);
			ID=m_manager->getDetector()->getPixelGlobalID(face,detector,pixel);
			hPixels->Fill(m_manager->getDetector()->getPixelGlobalID(face,detector,pixel),nPhe);
			hPixels2D[face][detector]->Fill(pixel%nX,pixel/nX,nPhe);
			m_Q.at(ID)=nPhe;
		}
	}

	if (m_writeOut){	/*In this case, it is not running on proof by definition*/
		for (int ipixel=0;ipixel<m_Q.size();ipixel++){
			m_writeOutFile<<m_Q.at(ipixel)<<" ";
		}
		m_writeOutFile<<endl;
	}
	return 0;
}

int TChargeAnalysisDriver::start(){
	Info("start","start");
	if (m_manager->getVerboseLevel()>=TJobManager::normalVerbosity){
		m_manager->getDetector()->Print();
	}
	return 0;
}
int TChargeAnalysisDriver::startOfData(){
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
	hPixels=new TH1D("hPixels","hPixels",m_nPixels,-0.5,m_nPixels-0.5);
	m_manager->GetOutputList()->Add(hPixels);



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


int TChargeAnalysisDriver::end(){
	hPixels=(TH1D*)(m_manager->GetOutputList()->FindObject("hPixels"));
	hPixels->Scale(1./m_manager->getNumberOfEvents());
	for (int ii=0;ii<6;ii++){
		for (int jj=0;jj<m_manager->getDetector()->getNdet(ii);jj++){
			if (m_manager->getDetector()->isDetPresent(ii,jj)){
				hPixels2D[ii][jj]=(TH2D*)(m_manager->GetOutputList()->FindObject(Form("hPixel0_%i_%i",ii,jj)));
				hPixels2D[ii][jj]->Scale(1./m_manager->getNumberOfEvents());
			}
		}
	}
	/*Lets organize them in canvases*/

	return 0;
}








void TChargeAnalysisDriver::setWriteOutFileName(const char *fname){
	m_writeOut=1;
	m_writeOutFileName=string(fname);
	m_isProofCompatible=0;

	/*Also open it*/
	if	(m_writeOutFile) m_writeOutFile.close();
	m_writeOutFile.open(m_writeOutFileName.c_str());
}








