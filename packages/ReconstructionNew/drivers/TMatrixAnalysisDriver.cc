#include "TMatrixAnalysisDriver.hh"

#include "OpNoviceDigi.hh"
#include "TDriver.hh"
#include "TEvent.hh"
#include "TJobManager.hh"
#include "TDetectorLight.hh"

TMatrixAnalysisDriver::TMatrixAnalysisDriver() {
	// TODO Auto-generated constructor stub
	hPixels=0;
	m_nPixelsTot=0;
	m_nDetectors=0;
}

TMatrixAnalysisDriver::~TMatrixAnalysisDriver() {
	// TODO Auto-generated destructor stub
}

int TMatrixAnalysisDriver::process(TEvent *event){

	TClonesArray *digiCollection;
	TIter		 *digiCollectionIter;
	OpNoviceDigi *digi;

	int face,detector,pixel,nPhe;

	if (event->hasCollection(OpNoviceDigi::Class(),"DetDigiMC")){
		digiCollection=event->getCollection(OpNoviceDigi::Class(),"DetDigiMC");
		digiCollectionIter=new TIter(digiCollection);
		while (digi = (OpNoviceDigi*)digiCollectionIter->Next()){
			face=digi->GetFaceNumber();
			detector=digi->GetDetectorNumber();
			pixel=digi->GetPixelNumber();
			nPhe=digi->GetPheCount();

		}
	}


}

int TMatrixAnalysisDriver::start(){
	Info("start","start");
	if (m_manager->getVerboseLevel()>=TJobManager::normalVerbosity){
		m_manager->getDetector()->Print();
	}
}
int TMatrixAnalysisDriver::startOfData(){
	Info("startOfData","start");
	m_nPixelsTot=0;
	m_nDetectors=0;
	/*Here I need to create the histogram with the pixels count
	I have faces,detectors,pixels
	 //	TODO: not parellelepied?
	 */
	for (int iface=0;iface<6;iface++){
		m_nDetectors+=m_manager->getDetector()->getNdet(iface);
		for (int idet=0;idet<m_manager->getDetector()->getNdet(iface);idet++){
			m_nPixelsTot+=m_manager->getDetector()->getNPixels(iface,idet);
		}
	}
	if (m_manager->getVerboseLevel()>=TJobManager::normalVerbosity){
		Info("startOfData","hPixels created with %i pixels",m_nPixelsTot);
	}
	hPixels=new TH1D("hPixels","hPixels",m_nPixelsTot,-0.5,m_nPixelsTot-0.5);


	m_manager->GetOutputList()->Add(hPixels);
}


int TMatrixAnalysisDriver::end(){
	Info("end","ended");
	cout<<m_manager->getNumberOfEvents()<<endl;
}
