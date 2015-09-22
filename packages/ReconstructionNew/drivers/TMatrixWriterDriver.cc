#include "TMatrixWriterDriver.hh"

#include <iostream>
#include <string>
#include "OpNoviceDigi.hh"
#include "TDriver.hh"
#include "TEvent.hh"
#include "TJobManager.hh"
#include "TDetectorLight.hh"

using namespace std;

TMatrixWriterDriver::TMatrixWriterDriver() {
	// TODO Auto-generated constructor stub
	hPixels=0;
	m_nPixels=0;
	m_nDetectors=0;
	m_voxelID=0;
}

TMatrixWriterDriver::~TMatrixWriterDriver() {
	// TODO Auto-generated destructor stub
}

int TMatrixWriterDriver::process(TEvent *event){

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
			hPixels->Fill(m_manager->getDetector()->getPixelGlobalID(face,detector,pixel),nPhe);
		}
	}


}

int TMatrixWriterDriver::start(){
	Info("start","start");
	if (m_manager->getVerboseLevel()>=TJobManager::normalVerbosity){
		m_manager->getDetector()->Print();
	}
}
int TMatrixWriterDriver::startOfData(){
	Info("startOfData","start");
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
}


int TMatrixWriterDriver::end(){
	ofstream out;
	string outName;
	outName=Form("voxel_%i.dat",m_voxelID);
	out.open(outName.c_str());
	Info("end","ended");
	cout<<m_manager->getNumberOfEvents()<<endl;
	hPixels->Scale(1./m_manager->getNumberOfEvents());



	Info("end","Writing datafile");
	out<<m_nPixels<<endl;
	for (int ipixel=0;ipixel<m_nPixels;ipixel++){
		out<<hPixels->GetBinContent(ipixel+1)<<" "; //out will be a 2-line file
		if (m_manager->getVerboseLevel()>=TJobManager::fullVerbosity){ cout<<ipixel<<" "<<hPixels->GetBinContent(ipixel+1)<<endl; //+1 is "a-la-Root"
		}
	}




}
