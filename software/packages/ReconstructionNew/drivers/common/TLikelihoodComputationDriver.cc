/*
 * TLikelihoodComputationDriver.cc
 *
 *  Created on: Sep 25, 2015
 *      Author: celentan
 */
#include <stdio.h>


#include "TVector3.h"
#include "TH1D.h"
#include "TH2D.h"

#include "TLikelihoodCalculator.hh"
#include "TReconDefs.hh"
#include "TReconInput.hh"
#include "TReconHit.hh"
#include "TEvent.hh"

#include "TClass.h"
#include "TLikelihoodComputationDriver.hh"
#include "TRealSetupHandler.hh"

TLikelihoodComputationDriver::TLikelihoodComputationDriver() :
m_fitObject(k_point),
m_fitLikelihoodMode(k_onlyCharge),
m_likelihoodCalculator(0)
{
	// TODO Auto-generated constructor stub
	m_reconInputMode=reconInputFile;
	m_reconInput=0;
	m_realSetupHandler=0;
	for (int iface=0;iface<6;iface++){
		m_ON[iface]=0;
		m_disc[iface]=0;
		m_Q[iface]=0;
		m_T[iface]=0;
	}

	hX=hY=hZ=0;
	hXY=hXZ=hYZ=0;


}

TLikelihoodComputationDriver::~TLikelihoodComputationDriver() {
	// TODO Auto-generated destructor stub
}

void TLikelihoodComputationDriver::configLikelihoodCalculator(const char* name) {
	TClass *likelihoodClass=TClass::GetClass(name);
	if (likelihoodClass==0){
		Error("configLikelihoodCalculator","Error, driver class %s not in ROOT dictionary. Return");
		return;
	}
	m_likelihoodCalculator=(TLikelihoodCalculator*)likelihoodClass->New();
	if (m_likelihoodCalculator==0){
		Error("configLikelihoodCalculator","Error, driver class %s can't be created",name);
		return;
	}

}




void TLikelihoodComputationDriver::setFitObject(fitObject_t type){
	Info("setFitObject","Set fit Object called with %i",type);
	m_fitObject=type;
	if (m_fitObject==k_null){
		return;
	}
}


void  TLikelihoodComputationDriver::setFitLikelihoodMode(fitLikelihoodMode_t mode){
	m_fitLikelihoodMode=mode;
}







void TLikelihoodComputationDriver::initParameters(){
	if (m_fitObject==k_null){
		return;
	}
/*
	Info("initParameters","InitParameters start");
	m_minimizer->SetLimitedVariable(0,"X0",m_reconInput->getParVal(0),.1,-m_manager->getDetector()->getScintSizeX()*.5,m_manager->getDetector()->getScintSizeX()*.5);
	m_minimizer->SetLimitedVariable(1,"Y0",m_reconInput->getParVal(1),.1,-m_manager->getDetector()->getScintSizeY()*.5,m_manager->getDetector()->getScintSizeY()*.5);
	m_minimizer->SetLimitedVariable(2,"Z0",m_reconInput->getParVal(2),.1,-m_manager->getDetector()->getScintSizeZ()*.5,m_manager->getDetector()->getScintSizeZ()*.5);
	m_minimizer->SetLimitedVariable(3,"X1",m_reconInput->getParVal(3),.1,-m_manager->getDetector()->getScintSizeX()*.5,m_manager->getDetector()->getScintSizeX()*.5);
	m_minimizer->SetLimitedVariable(4,"Y1",m_reconInput->getParVal(4),.1,-m_manager->getDetector()->getScintSizeY()*.5,m_manager->getDetector()->getScintSizeY()*.5);
	m_minimizer->SetLimitedVariable(5,"Z1",m_reconInput->getParVal(5),.1,-m_manager->getDetector()->getScintSizeZ()*.5,m_manager->getDetector()->getScintSizeZ()*.5);
	m_minimizer->SetLimitedVariable(6,"b",m_reconInput->getParVal(6),.1,0.,1.);
	m_minimizer->SetVariable(7,"t",m_reconInput->getParVal(7),.1);
	m_minimizer->SetLowerLimitedVariable(8,"N",m_reconInput->getParVal(8),0.1,0.);
	m_minimizer->SetLowerLimitedVariable(9,"tau",m_reconInput->getParVal(9),0.1,0.);


	for (int ii=0;ii<m_nPars;ii++){
		if (m_reconInput->isParFixed(ii)) m_minimizer->FixVariable(ii);
	}
	Info("initParameters","InitParameters end");
*/
	/*@TODO: consider par limits in the file*/

}






void TLikelihoodComputationDriver::setReconInputMode(const char *mode){
	if (string(mode)=="file"){
		m_reconInputMode=reconInputFile;
	}
	else if (string(mode)=="driver"){
		m_reconInputMode=reconInputDriver;
	}
	else{
		Error("setReconInputMode","mode %s not recognized");
	}
}

void TLikelihoodComputationDriver::configReconInput(){
	if (m_reconInputMode==reconInputFile){
		ifstream f(m_reconInputFileName.c_str());
		if (f.good()){
			f.close();
			m_reconInput=new TReconInput(m_reconInputFileName);
			if (m_manager->getVerboseLevel()>=TJobManager::normalVerbosity) Info("configReconInput","Used file %s to create the reconInput",m_reconInputFileName.c_str());
		}
		else{
			Error("configReconInput","recon input file %s does not exists",m_reconInputFileName.c_str());
		}
	}
	else if (m_reconInputMode==reconInputDriver){
		m_reconInput=NULL;
	}
	else{
		Error("configReconInput","recon input mode %i not recognized",m_reconInputMode);
	}
}

/*These are inherited from the driver*/
int TLikelihoodComputationDriver::start(){


	this->configReconInput();
	return 0;
}


int TLikelihoodComputationDriver::startOfData(){

	double Lx,Ly,Lz;
	double dx,dy,dz;

	/*Set the variables*/
	for (int iface=0;iface<6;iface++){
		m_ON[iface]=new int*[m_manager->getDetector()->getNdet(iface)];
		m_disc[iface]=new int*[m_manager->getDetector()->getNdet(iface)];
		m_Q[iface]=new double*[m_manager->getDetector()->getNdet(iface)];
		m_T[iface]=new double*[m_manager->getDetector()->getNdet(iface)];
		for (int idet=0;idet<m_manager->getDetector()->getNdet(iface);idet++){
			m_ON[iface][idet]=new int[m_manager->getDetector()->getNPixels(iface,idet)];
			m_disc[iface][idet]=new int[m_manager->getDetector()->getNPixels(iface,idet)];
			m_Q[iface][idet]=new double[m_manager->getDetector()->getNPixels(iface,idet)];
			m_T[iface][idet]=new double[m_manager->getDetector()->getNPixels(iface,idet)];
		}
	}

	Lx=m_manager->getDetector()->getScintSizeX();
	Ly=m_manager->getDetector()->getScintSizeY();
	Lz=m_manager->getDetector()->getScintSizeZ();

	dx=Lx/nBinsX;
	dy=Ly/nBinsY;
	dz=Lz/nBinsZ;

	hX=new TH1D("hX","hX;x (cm)",nBinsX,-Lx/2,Lx/2);m_manager->GetOutputList()->Add(hX);
	hY=new TH1D("hY","hY;y (cm)",nBinsY,-Ly/2,Ly/2);m_manager->GetOutputList()->Add(hY);
	hZ=new TH1D("hZ","hZ;z (cm)",nBinsZ,-Lz/2,Lz/2);m_manager->GetOutputList()->Add(hZ);
	hXY=new TH2D("hXY","hXY;x (cm);y (cm)",nBinsX,-Lx/2,Lx/2,nBinsY,-Ly/2,Ly/2);m_manager->GetOutputList()->Add(hXY);
	hXZ=new TH2D("hXZ","hXZ;x (cm);z (cm)",nBinsX,-Lx/2,Lx/2,nBinsZ,-Lz/2,Lz/2);m_manager->GetOutputList()->Add(hXZ);
	hYZ=new TH2D("hYZ","hYZ;y (cm);z (cm)",nBinsY,-Ly/2,Ly/2,nBinsZ,-Lz/2,Lz/2);m_manager->GetOutputList()->Add(hYZ);


	/*Config computation mode*/
	setFitObject(m_reconInput->getFitObject()); /*Set the fit object: point or track. Correspondingly, fix the parameters we are not sensitive to*/
	setFitLikelihoodMode(m_reconInput->getFitLikelihoodMode());/*Set the fit data: charge, time, both. Correspondingly, fix the parameters we are not sensitive to*/


	/*Config the likelihood calculator*/
	m_likelihoodCalculator->setDriver(this);
	m_likelihoodCalculator->SetData(m_ON,m_disc,m_Q,m_T);
	m_likelihoodCalculator->setFitLikelihoodMode(m_reconInput->getFitLikelihoodMode());
	m_likelihoodCalculator->setFitObject(m_reconInput->getFitObject());

	/*Check if there is a realSetupHandler with some gains*/
	if (m_manager->hasObject(TRealSetupHandler::Class())){
			m_realSetupHandler=(TRealSetupHandler*)(m_manager->getObject(TRealSetupHandler::Class()));
			m_likelihoodCalculator->setRealSetupHandler(m_realSetupHandler);
	}










	return 0;
}

int TLikelihoodComputationDriver::end(){
	hXZ=(TH2D*)(m_manager->GetOutputList()->FindObject("hXZ"));
	hXZ->Scale(1./m_manager->getNumberOfEvents());
	return 0;
}




int TLikelihoodComputationDriver::process(TEvent *event){
	TClonesArray *hitCollection;
	TIter		 *hitCollectionIter;
	TReconHit *hit;
	TEventHeader *header=0;

	double likelihood;
	double x,y,z,lx,ly,lz,N0;
	int face,detector,pixel,nPhe,nX,nY,ID,iRealDet,iH8500,iMarocChannel,iReconDet,iReconFace,iReconPixel,ix,iy;

/*
	//First, check if the recon input was given from file or we expect it event by event from previous drivers
	if (m_reconInputMode==reconInputDriver){
		if (event->hasObject("reconInput")){
			m_reconInput=(TReconInput*)event->getObject("reconInput");
		}
		else{
			Error("process","Asked for recon input from driver, but no reconInput object present. Are you using the TMatrixReconDriver and the TMatrixInterpreterDriver?");
			return 1;
		}
	}
	else*/ if (m_reconInput==0){
		Error("process","something went wrong, no reconInput");
		return 2;
	}

	//Prepare the data
	for (face=0;face<6;face++){
		for (detector=0;detector<m_manager->getDetector()->getNdet(face);detector++){
			for (pixel=0;pixel<m_manager->getDetector()->getNPixels(face,detector);pixel++){
				m_disc[face][detector][pixel]=0;
				m_T[face][detector][pixel]=-1;
				m_Q[face][detector][pixel]=-1;
				m_ON[face][detector][pixel]=(m_manager->getDetector()->isDetPresent(face,detector));
			}
		}
	}


	header=(TEventHeader*)event->getEventHeader();
	if (header==0){
		Error("process","no event header!");
	}


	if (event->hasCollection(TReconHit::Class(),m_collectionName)){
		hitCollection=event->getCollection(TReconHit::Class(),m_collectionName);
		hitCollectionIter=new TIter(hitCollection);
		while (hit = (TReconHit*)hitCollectionIter->Next()){

			iReconFace=hit->getFace();
			iReconDet=hit->getDetector();
			iReconPixel=hit->getPixel();

			m_Q[iReconFace][iReconDet][iReconPixel]=hit->getQ();
			m_T[iReconFace][iReconDet][iReconPixel]=hit->getT();
			m_disc[iReconFace][iReconDet][iReconPixel]=hit->isHit();
		}
		delete hitCollectionIter;


		m_likelihoodCalculator->SetData(m_ON,m_disc,m_Q,m_T);

		/*Now compute it*/
		y=m_manager->getDetector()->getScintSizeY()*.5;
		N0=m_reconInput->getParVal(8);

		for (int ix=nBinsX/2-30;ix<=nBinsX/2+30;ix++){
			for (int iz=nBinsZ/2-30;iz<=nBinsZ/2+30;iz++){
				x=hXZ->GetXaxis()->GetBinCenter( ix+1 );
				z=hXZ->GetYaxis()->GetBinCenter( iz+1 );
				double pars[10]={x,y,z,0,0,0,1,0,N0,0};
				likelihood=m_likelihoodCalculator->CalculateLikelihood(pars);
				hXZ->Fill(x,z,likelihood);
			}
		}



	}

	return 0;
}





