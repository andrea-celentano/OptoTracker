#include <iostream>
#include <string>
#include "TMatrixReconDriver.hh"
#include "OpNoviceDigi.hh"
#include "TDriver.hh"
#include "TEvent.hh"
#include "TJobManager.hh"
#include "TDetectorLight.hh"

using namespace std;
TMatrixReconDriver::TMatrixReconDriver() {
	// TODO Auto-generated constructor stub
	m_matrix=0;
	m_matrixFile=0;
}

TMatrixReconDriver::~TMatrixReconDriver() {
	// TODO Auto-generated destructor stub
}


void TMatrixReconDriver::setMatrixSource(string source){
	if (source=="file"){
		m_matrixSource=matrixSourceFile;
	}
	else if (source=="model"){
		m_matrixSource=matrixSourceModel;
	}
	else{
		Error("setMatrixSource","source %s not recognized. Use \"file\" or \"model\" ",source.c_str());
	}

	if (m_manager->getVerboseLevel()>=TJobManager::normalVerbosity){
		Info("setMatrixSource","Matrix source set to %s",source.c_str());
	}
}

int TMatrixReconDriver::startOfData(){
	/*First, load the matrix from the proper source*/
	switch (m_matrixSource){
	case matrixSourceFile:
		m_matrixFile=new TFile(m_matrixFileName.c_str());
		if (!m_matrixFile){
			Error("startOfData","Error with the root file");
			return;
		}
		break;
	case matrixSourceModel:

		break;
	}


}
