#include <iostream>
#include <string>
#include "TFile.h"
#include "TMatrixT.h"
#include "TMatrixD.h"
#include "TMatrixTUtils.h"
#include "TDecompSVD.h"
#include "TH3D.h"
#include "TAxis.h"
#include "TApplication.h"

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
	m_matrixFileName="";
	hVoxels=0;

}

TMatrixReconDriver::~TMatrixReconDriver() {
	// TODO Auto-generated destructor stub
}


void TMatrixReconDriver::setMatrixSource(const char* ssource){
	string source=string(ssource);
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
	int Np,Nv;
	switch (m_matrixSource){
	case matrixSourceFile:
		m_matrixFile=new TFile(m_matrixFileName.c_str());
		if (!m_matrixFile){
			Error("startOfData","Error with the root file");
			return 0;
		}
		m_matrix=(TMatrixD*)m_matrixFile->Get("TMatrixT<double>");
		if (!m_matrix){
			Error("startOfData","Error with the matrix not in root file");
			return 0;
		}
		/*Get the voxels histo*/
		hVoxels=(TH3D*)m_matrixFile->Get("hVoxels");
		if (!hVoxels){
			Error("startOfData","Error with the hVoxels not in root file");
			return 0;
		}
		/*Do some dimensionals check*/
		Np=m_manager->getDetector()->getTotPixels();
		Nv=hVoxels->GetXaxis()->GetNbins();
		Nv*=hVoxels->GetYaxis()->GetNbins();
		Nv*=hVoxels->GetZaxis()->GetNbins();
		if (Np!=m_matrix->GetNrows()){
			Error("startOfData","Inconcisteny pixels number. Detector has %i, matrix has %i",Np,m_matrix->GetNrows());
		}
		if (Nv!=m_matrix->GetNcols()){
			Error("startOfData","Inconcisteny voxel number. Detector has %i, matrix has %i",Nv,m_matrix->GetNcols());
		}
		break;
	case matrixSourceModel:
		///TODO
		break;
	}

	/*Here we have m_matrix. Need to compute the inverse */
	/*If there are V voxels and P pixels, the direct matrix is P x V,
	 * and the generalized inverse should be V x P
	 */
	TDecompSVD svd(*m_matrix);
	Bool_t ok = svd.Decompose();
	if (ok){
		m_matrixInverse.ResizeTo(m_matrix->GetNcols(),m_matrix->GetNrows());
		m_matrixInverse = svd.Invert();
		if (m_manager->getVerboseLevel()>=TJobManager::normalVerbosity){
			Info("startOfData","inverse matrix computed");
			if (m_manager->getVerboseLevel()>=TJobManager::veryfullVerbosity){
				m_matrixInverse.Print();
			}
		}
	}
	else {
		Error("startOfData","SVT failed");
		m_matrix->Print();
	}
}

int TMatrixReconDriver::process(TEvent *event){


	TClonesArray *digiCollection;
	TIter		 *digiCollectionIter;
	OpNoviceDigi *digi;

	TMatrixD m_pixelData(m_matrix->GetNrows(),1); //this is the data vector, 1 column and P rows, one for each pixel
	TMatrixD m_voxelData(m_matrix->GetNcols(),1); //this is the voxels response, 1 column and V rows, one for each voxel
	int face,detector,pixel,nPhe,ID;
	int Vx,Vy,Vz,V;


	if (event->hasCollection(OpNoviceDigi::Class(),m_collectionName)){
		digiCollection=event->getCollection(OpNoviceDigi::Class(),m_collectionName);
		digiCollectionIter=new TIter(digiCollection);
		while (digi = (OpNoviceDigi*)digiCollectionIter->Next()){
			face=digi->GetFaceNumber();
			detector=digi->GetDetectorNumber();
			pixel=digi->GetPixelNumber();
			nPhe=digi->GetPheCount();
			ID=m_manager->getDetector()->getPixelGlobalID(face,detector,pixel);
			m_pixelData(ID,0)=nPhe;
		}
	}
	/*We have now the pixels vector*/
	/*Apply inversion*/
	m_voxelData=m_matrixInverse*m_pixelData;

	TH3D *m_voxelHisto=(TH3D*)(hVoxels->Clone());
	Vx=hVoxels->GetXaxis()->GetNbins();
	Vy=hVoxels->GetYaxis()->GetNbins();
	Vz=hVoxels->GetZaxis()->GetNbins();
	V=0;
	for (int iz=1;iz<=Vz;iz++){
		for (int iy=1;iy<=Vy;iy++){
			for (int ix=1;ix<=Vx;ix++){
				m_voxelHisto->Fill(ix,iy,iz,m_voxelData(V,0));
				V++;
			}
		}
	}

	TApplication gui("GUI",0,NULL);
	m_voxelHisto->Draw("BOX");
	gui.Run(1);

	event->addObject(m_voxelHisto);


}
