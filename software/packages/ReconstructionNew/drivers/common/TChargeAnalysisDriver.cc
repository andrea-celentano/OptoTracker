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

#include "TChargeAnalysisDriver.hh"
#include "TDriver.hh"
#include "TEvent.hh"
#include "TJobManager.hh"
#include "TDetector.hh"
#include "TMCTruth.hh"
#include "TReconHit.hh"

using namespace std;

TChargeAnalysisDriver::TChargeAnalysisDriver() {
	// TODO Auto-generated constructor stub
	hPixelsMC=0;
	hPixelsModel=0;
	hEdep=0;
	hLength=0;
	m_nPixels=0;
	m_nDetectors=0;
	for (int ii=0;ii<6;ii++){
		for (int jj=0;jj<MAX_DETECTORS;jj++){
			hPixels2D[ii][jj]=0;
		}
	}
	m_writeOut=0;
	m_MCTruth=0;
}

TChargeAnalysisDriver::~TChargeAnalysisDriver() {
	// TODO Auto-generated destructor stub
}

int TChargeAnalysisDriver::process(TEvent *event){
	TClonesArray *hitCollection;
	TIter		 *hitCollectionIter;
	TReconHit *hit;

	TVector3 xIn,xOut,x0;
	double L;
	int face,detector,pixel,nPhe,nX,nY,ID;
	double meanModel;
	m_Q.clear();
	m_Q.resize(m_manager->getDetector()->getTotPixels(),0);



	if (event->hasCollection(TReconHit::Class(),m_collectionName)){
		hitCollection=event->getCollection(TReconHit::Class(),m_collectionName);
		hitCollectionIter=new TIter(hitCollection);
		while (hit = (TReconHit*)hitCollectionIter->Next()){
			face=hit->getFace();
			detector=hit->getDetector();
			pixel=hit->getPixel();
			nPhe=hit->getQ();
			nX=m_manager->getDetector()->getNPixelsX(face,detector);
			nY=m_manager->getDetector()->getNPixelsY(face,detector);
			ID=m_manager->getDetector()->getPixelGlobalID(face,detector,pixel);

			hPixelsMC->Fill(ID,nPhe);
			hPixels2D[face][detector]->Fill(pixel%nX,pixel/nX,nPhe);
			m_Q.at(ID)=nPhe;
		}
	}

	if (event->hasObject("MCTruth")){
		m_MCTruth=(TMCTruth*)event->getObject("MCTruth");
		hEdep->Fill(m_MCTruth->getEdep());
		if ((m_MCTruth->getXin()!=0)&&(m_MCTruth->getXout()!=0)){
			xIn=m_MCTruth->getXin()->Vect();
			xOut=m_MCTruth->getXout()->Vect();
			L=(xIn-xOut).Mag();
			hLength->Fill(L);
		}
		for (int ii=0;ii<6;ii++){
			for (int jj=0;jj<m_manager->getDetector()->getNdet(ii);jj++){
				if (m_manager->getDetector()->isDetPresent(ii,jj)){
					for (int kk=0;kk<m_manager->getDetector()->getNPixels(ii,jj);kk++){
						ID=m_manager->getDetector()->getPixelGlobalID(ii,jj,kk);
						//mean=m_manager->getDetectorUtils()->SinglePixelAverageCharge( ,ii,jj,kk);
						meanModel=0;
						if ((m_MCTruth->getXin()!=0)&&(m_MCTruth->getXout()!=0)){
							if (m_manager->getVerboseLevel()>TJobManager::normalVerbosity){
								Info("process","model with track");
							}
							xIn=m_MCTruth->getXin()->Vect();
							xOut=m_MCTruth->getXout()->Vect();
							meanModel=m_manager->getDetectorUtils()->TrackAverageCharge(xIn,xOut,ii,jj,kk);
						}
						else{
							x0=m_MCTruth->getX0()->Vect();
							meanModel=m_manager->getDetectorUtils()->SinglePixelAverageCharge(x0,ii,jj,kk);
							if (m_manager->getVerboseLevel()>TJobManager::normalVerbosity){
								Info("process","model with point: %f %f %f. Average: %f",x0.X(),x0.Y(),x0.Z(),meanModel);

							}
						}
						meanModel*=m_MCTruth->getEdepVis();
						meanModel*=m_manager->getDetector()->getLY();
						hPixelsModel->Fill(ID,meanModel);
					}
				}
			}
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
	hPixelsMC=new TH1D("hPixelsMC","hPixelsMC",m_nPixels,-0.5,m_nPixels-0.5);
	hPixelsModel=new TH1D("hPixelsModel","hPixelsModel",m_nPixels,-0.5,m_nPixels-0.5);

	hEdep=new TH1D("hEdep","hEdep",100,0,20);
	hLength=new TH1D("hLength","hLength",100,0,10);

	m_manager->GetOutputList()->Add(hPixelsMC);
	m_manager->GetOutputList()->Add(hPixelsModel);
	m_manager->GetOutputList()->Add(hEdep);
	m_manager->GetOutputList()->Add(hLength);

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
	int ID;
	double mean;


	hPixelsMC=(TH1D*)(m_manager->GetOutputList()->FindObject("hPixelsMC"));
	hPixelsModel=(TH1D*)(m_manager->GetOutputList()->FindObject("hPixelsModel"));
	hPixelsMC->Scale(1./m_manager->getNumberOfEvents());
	hPixelsModel->Scale(1./m_manager->getNumberOfEvents());

	for (int ii=0;ii<6;ii++){
		for (int jj=0;jj<m_manager->getDetector()->getNdet(ii);jj++){
			if (m_manager->getDetector()->isDetPresent(ii,jj)){
				hPixels2D[ii][jj]=(TH2D*)(m_manager->GetOutputList()->FindObject(Form("hPixel0_%i_%i",ii,jj)));
				hPixels2D[ii][jj]->Scale(1./m_manager->getNumberOfEvents());
			}
		}
	}

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








