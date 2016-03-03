/*
 * TLikelihoodReconDriver.cc
 *
 *  Created on: Sep 25, 2015
 *      Author: celentan
 */
#include <stdio.h>


#include "TVector3.h"
#include "TH1D.h"
#include "TH2D.h"

#include "TLikelihoodCalculator.hh"
#include "TLikelihoodReconDriver.hh"

#include "TReconDefs.hh"
#include "TReconInput.hh"
#include "TEvent.hh"

#include "TClass.h"


TLikelihoodReconDriver::TLikelihoodReconDriver() :
m_fitObject(k_point),
m_fitLikelihoodMode(k_onlyCharge),
m_likelihoodCalculator(0)
{
	// TODO Auto-generated constructor stub
	m_minimizer=0;
	m_reconInputMode=reconInputFile;
	m_reconInput=0;
	for (int iface=0;iface<6;iface++){
		m_N[iface]=0;
		m_Q[iface]=0;
		m_T[iface]=0;
	}

	hX=hY=hZ=hX_1=hY_1=hZ_1=hX_2=hY_2=hZ_2=0;
	hXY=hXZ=hYZ=hXY_1=hXZ_1=hYZ_1=hXY_2=hXZ_2=hYZ_2=0;

	hTheta=hPhi=0;
	hNPhotons=hT0=hTau=0;

	/*for (int ii=0;ii<6;ii++){
		for (int jj=0;jj<MAX_DETECTORS;jj++){
			hPixel0[ii][jj]=0;
		}
	}
	hPixel0Title=0;
	 */
}

TLikelihoodReconDriver::~TLikelihoodReconDriver() {
	// TODO Auto-generated destructor stub
}

void TLikelihoodReconDriver::configLikelihoodCalculator(const char* name) {
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

void TLikelihoodReconDriver::configMinimizer(){
	if (!m_minimizer) m_minimizer=ROOT::Math::Factory::CreateMinimizer("Minuit2","Migrad"); //minimizer name: Minuit, Minuit2 //algo: Migrad, Simplex, Combined, Scan.

	m_minimizer->SetFunction(*this); /*This is very important*/
	m_minimizer->SetPrintLevel(1);
	m_minimizer->SetMaxFunctionCalls(1000000);
	m_minimizer->SetMaxIterations(100000);
	//m_minimizer->SetTolerance(0.01);//The minimization will stop when the estimated distance to the minimum is less than 0.001*tolerance (from ROOT FORUM)
	m_minimizer->SetPrecision(0); //find it automatically
}


void TLikelihoodReconDriver::setFitObject(fitObject_t type){
	Info("setFitObject","Set fit Object called with %i",type);
	m_fitObject=type;
	if (m_fitObject==k_null){
		return;
	}
	else if (m_fitObject==k_point){
		Info("setFitObject","Fixing parameters for point mode");
		m_minimizer->FixVariable(3);
		m_minimizer->FixVariable(4);
		m_minimizer->FixVariable(5);
		/*Fix beta*/
		m_minimizer->FixVariable(6);
		Info("setFitObject","Fixed parameters for point mode");
	}
}


void  TLikelihoodReconDriver::setFitLikelihoodMode(fitLikelihoodMode_t mode){
	m_fitLikelihoodMode=mode;

	/*If we fit only the time info, we can't get N*/
	if (m_fitLikelihoodMode==k_onlyTime){
		Info("setFitLikelihoodMode","Fixing parameters for onlyTime mode");
		m_minimizer->FixVariable(8);
	}
	/*If we fit only the charge info, we can't get t0 and beta and tau*/
	else if (m_fitLikelihoodMode==k_onlyCharge){
		Info("setFitLikelihoodMode","Fixing parameters for onlyCharge mode");
		m_minimizer->FixVariable(6);
		m_minimizer->FixVariable(7);
		m_minimizer->FixVariable(9);
	}
}





/*This is the method that computes the function, x are the variables*/

//double TRecon::operator()(const std::vector< double >& x) const{
double TLikelihoodReconDriver::DoEval(const double *x) const{
	double ret;
	ret=m_likelihoodCalculator->CalculateLikelihood(x);
	return ret;
}


unsigned int TLikelihoodReconDriver::NDim() const{
	return m_nPars;
}

ROOT::Math::IBaseFunctionMultiDim* TLikelihoodReconDriver::Clone() const{
	return 0;
}


void TLikelihoodReconDriver::doFit(){
	if (m_fitObject==k_null){
		return;
	}
	ROOT::Fit::ParameterSettings parSettings;
	Info("TLikelihoodReconDriver","Start the maximum likelihood fit");
	if (m_manager->getVerboseLevel()>=TJobManager::normalVerbosity){
		printf("Parameter \t \t Value \t \t IsFixed? \t IsBounded? \n");
		for (int ii=0;ii<m_minimizer->NDim();ii++){
			m_minimizer->GetVariableSettings(ii,parSettings);
			if (parSettings.IsBound()){
				printf("%s \t \t %f \t \t %i \t \t 1 \t \t%f \t\t %f\n",m_minimizer->VariableName(ii).c_str(),parSettings.Value(),m_minimizer->IsFixedVariable(ii),parSettings.LowerLimit(),parSettings.UpperLimit());

			}
			else{
				printf("%s \t \t %f \t \t %i \t \t 1 \n",m_minimizer->VariableName(ii).c_str(),parSettings.Value(),m_minimizer->IsFixedVariable(ii));
			}
		}
	}


	m_minimizer->SetStrategy(2);
	m_minimizer->SetPrintLevel(2);
	m_minimizer->Minimize();
}


void TLikelihoodReconDriver::initParameters(){
	if (m_fitObject==k_null){
		return;
	}

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

	/*Then, verify if we need to fix anything*/
	for (int ii=0;ii<m_nPars;ii++){
		if (m_reconInput->isParFixed(ii)) m_minimizer->FixVariable(ii);
	}
	Info("initParameters","InitParameters end");

	/*@TODO: consider par limits in the file*/

}


void TLikelihoodReconDriver::initFit(){
	initParameters(); /*Create all the parameters and set them*/
	setFitObject(m_reconInput->getFitObject()); /*Set the fit object: point or track. Correspondingly, fix the parameters we are not sensitive to*/
	setFitLikelihoodMode(m_reconInput->getFitLikelihoodMode());/*Set the fit data: charge, time, both. Correspondingly, fix the parameters we are not sensitive to*/
}




void TLikelihoodReconDriver::setReconInputMode(const char *mode){
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

void TLikelihoodReconDriver::configReconInput(){
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
int TLikelihoodReconDriver::start(){


	this->configReconInput();
	return 0;
}


int TLikelihoodReconDriver::startOfData(){

	/*Set the variables*/
	for (int iface=0;iface<6;iface++){
		m_N[iface]=new int*[m_manager->getDetector()->getNdet(iface)];
		m_Q[iface]=new double*[m_manager->getDetector()->getNdet(iface)];
		m_T[iface]=new double*[m_manager->getDetector()->getNdet(iface)];
		for (int idet=0;idet<m_manager->getDetector()->getNdet(iface);idet++){
			m_N[iface][idet]=new int[m_manager->getDetector()->getNPixels(iface,idet)];
			m_Q[iface][idet]=new double[m_manager->getDetector()->getNPixels(iface,idet)];
			m_T[iface][idet]=new double[m_manager->getDetector()->getNPixels(iface,idet)];
		}
	}



	hX=new TH1D("hX","hX;x (cm)",200,-m_manager->getDetector()->getScintSizeX()/2-1,m_manager->getDetector()->getScintSizeX()/2+1);m_manager->GetOutputList()->Add(hX);
	hY=new TH1D("hY","hY;y (cm)",200,-m_manager->getDetector()->getScintSizeY()/2-1,m_manager->getDetector()->getScintSizeY()/2+1);m_manager->GetOutputList()->Add(hY);
	hZ=new TH1D("hZ","hZ;z (cm)",200,-m_manager->getDetector()->getScintSizeZ()/2-1,m_manager->getDetector()->getScintSizeZ()/2+1);m_manager->GetOutputList()->Add(hZ);
	hXY=new TH2D("hXY","hXY;x (cm);y (cm)",100,-m_manager->getDetector()->getScintSizeX()/2-1,m_manager->getDetector()->getScintSizeX()/2+1,100,-m_manager->getDetector()->getScintSizeY()/2-1,m_manager->getDetector()->getScintSizeY()/2+1);m_manager->GetOutputList()->Add(hXY);
	hXZ=new TH2D("hXZ","hXZ;x (cm);z (cm)",100,-m_manager->getDetector()->getScintSizeX()/2-1,m_manager->getDetector()->getScintSizeX()/2+1,100,-m_manager->getDetector()->getScintSizeZ()/2-1,m_manager->getDetector()->getScintSizeZ()/2+1);m_manager->GetOutputList()->Add(hXZ);
	hYZ=new TH2D("hYZ","hYZ;y (cm);z (cm)",100,-m_manager->getDetector()->getScintSizeY()/2-1,m_manager->getDetector()->getScintSizeY()/2+1,100,-m_manager->getDetector()->getScintSizeZ()/2-1,m_manager->getDetector()->getScintSizeZ()/2+1);m_manager->GetOutputList()->Add(hYZ);


	hX_1=new TH1D("hX_1","hX;x (cm)",200,-m_manager->getDetector()->getScintSizeX()/2-1,m_manager->getDetector()->getScintSizeX()/2+1);m_manager->GetOutputList()->Add(hX_1);
	hY_1=new TH1D("hY_1","hY;y (cm)",200,-m_manager->getDetector()->getScintSizeY()/2-1,m_manager->getDetector()->getScintSizeY()/2+1);m_manager->GetOutputList()->Add(hY_1);
	hZ_1=new TH1D("hZ_1","hZ;z (cm)",200,-m_manager->getDetector()->getScintSizeZ()/2-1,m_manager->getDetector()->getScintSizeZ()/2+1);m_manager->GetOutputList()->Add(hZ_1);
	hXY_1=new TH2D("hXY_1","hXY;x (cm);y (cm)",100,-m_manager->getDetector()->getScintSizeX()/2-1,m_manager->getDetector()->getScintSizeX()/2+1,100,-m_manager->getDetector()->getScintSizeY()/2-1,m_manager->getDetector()->getScintSizeY()/2+1);m_manager->GetOutputList()->Add(hXY_1);
	hXZ_1=new TH2D("hXZ_1","hXZ;x (cm);z (cm)",100,-m_manager->getDetector()->getScintSizeX()/2-1,m_manager->getDetector()->getScintSizeX()/2+1,100,-m_manager->getDetector()->getScintSizeZ()/2-1,m_manager->getDetector()->getScintSizeZ()/2+1);m_manager->GetOutputList()->Add(hXZ_1);
	hYZ_1=new TH2D("hYZ_1","hYZ;y (cm);z (cm)",100,-m_manager->getDetector()->getScintSizeY()/2-1,m_manager->getDetector()->getScintSizeY()/2+1,100,-m_manager->getDetector()->getScintSizeZ()/2-1,m_manager->getDetector()->getScintSizeZ()/2+1);m_manager->GetOutputList()->Add(hYZ_1);

	hX_2=new TH1D("hX_2","hX;x (cm)",200,-m_manager->getDetector()->getScintSizeX()/2-1,m_manager->getDetector()->getScintSizeX()/2+1);m_manager->GetOutputList()->Add(hX_2);
	hY_2=new TH1D("hY_2","hY;y (cm)",200,-m_manager->getDetector()->getScintSizeY()/2-1,m_manager->getDetector()->getScintSizeY()/2+1);m_manager->GetOutputList()->Add(hY_2);
	hZ_2=new TH1D("hZ_2","hZ;z (cm)",200,-m_manager->getDetector()->getScintSizeZ()/2-1,m_manager->getDetector()->getScintSizeZ()/2+1);m_manager->GetOutputList()->Add(hZ_2);
	hXY_2=new TH2D("hXY_2","hXY;x (cm);y (cm)",100,-m_manager->getDetector()->getScintSizeX()/2-1,m_manager->getDetector()->getScintSizeX()/2+1,100,-m_manager->getDetector()->getScintSizeY()/2-1,m_manager->getDetector()->getScintSizeY()/2+1);m_manager->GetOutputList()->Add(hXY_2);
	hXZ_2=new TH2D("hXZ_2","hXZ;x (cm);z (cm)",100,-m_manager->getDetector()->getScintSizeX()/2-1,m_manager->getDetector()->getScintSizeX()/2+1,100,-m_manager->getDetector()->getScintSizeZ()/2-1,m_manager->getDetector()->getScintSizeZ()/2+1);m_manager->GetOutputList()->Add(hXZ_2);
	hYZ_2=new TH2D("hYZ_2","hYZ;y (cm);z (cm)",100,-m_manager->getDetector()->getScintSizeY()/2-1,m_manager->getDetector()->getScintSizeY()/2+1,100,-m_manager->getDetector()->getScintSizeZ()/2-1,m_manager->getDetector()->getScintSizeZ()/2+1);m_manager->GetOutputList()->Add(hYZ_2);



	hTheta=new TH1D("hTheta","hTheta",150,-120,120);m_manager->GetOutputList()->Add(hTheta);
	hPhi=new TH1D("hPhi","hPhi",150,-250,250);m_manager->GetOutputList()->Add(hPhi);

	hNPhotons=new TH1D("hNPhotons","hNPhotons",1000,0,4E5);m_manager->GetOutputList()->Add(hNPhotons);
	hT0=new TH1D("hT0","hT0",100,-.1,.1);m_manager->GetOutputList()->Add(hT0);
	hTau=new TH1D("hTau","hTau",100,-.1,5);m_manager->GetOutputList()->Add(hTau);



	/*Config the likelihood calculator*/
	m_likelihoodCalculator->setDriver(this);
	m_likelihoodCalculator->Init(m_N,m_Q,m_T);
	/*Config the minimizer*/
	this->configMinimizer();








	return 0;
}

int TLikelihoodReconDriver::process(TEvent *event){
	TClonesArray *digiCollection;
	TIter		 *digiCollectionIter;
	OpNoviceDigi *digi;

	TVector3 rReconIN,rReconOUT,rRecon;
	TVector3 ux,uy,uz;
	double Ntot,theta,phi;
	int face,detector,pixel,nPhe,nX,nY,ID;

	/*First, check if the recon input was given from file or we expect it event by event from previous drivers*/
	if (m_reconInputMode==reconInputDriver){
		if (event->hasObject("reconInput")){
			m_reconInput=(TReconInput*)event->getObject("reconInput");
		}
		else{
			Error("process","Asked for recon input from driver, but no reconInput object present. Are you using the TMatrixReconDriver and the TMatrixInterpreterDriver?");
			return 1;
		}
	}
	else if (m_reconInput==0){
		Error("process","something went wrong, no reconInput");
		return 2;
	}

	/*Prepare the data*/
	for (face=0;face<6;face++){
		for (detector=0;detector<m_manager->getDetector()->getNdet(face);detector++){
			for (pixel=0;pixel<m_manager->getDetector()->getNPixels(face,detector);pixel++){
				m_N[face][detector][pixel]=-1;  /*I use a negative value, since it is possible that we do not have this data in this event. Therefore, the likelihood will ignore this pixel*/
				m_T[face][detector][pixel]=-1;
				m_Q[face][detector][pixel]=-1;
			}
		}
	}

	if (event->hasCollection(OpNoviceDigi::Class(),m_collectionName)){
		cout<<"!!!!!!OK!!!!!!!"<<endl;
		digiCollection=event->getCollection(OpNoviceDigi::Class(),m_collectionName);
		digiCollectionIter=new TIter(digiCollection);
		while (digi = (OpNoviceDigi*)digiCollectionIter->Next()){
			face=digi->GetFaceNumber();
			detector=digi->GetDetectorNumber();
			pixel=digi->GetPixelNumber();
			nPhe=digi->GetPheCount();
			m_N[face][detector][pixel]=nPhe;
			nX=m_manager->getDetector()->getNPixelsX(face,detector);
			nY=m_manager->getDetector()->getNPixelsY(face,detector);
			ID=m_manager->getDetector()->getPixelGlobalID(face,detector,pixel);
		}
	}


	m_minimizer->Clear();
	this->initParameters(); /*This defines the parameters*/
	this->initFit();

	this->doFit();

	if (m_manager->getVerboseLevel()>=TJobManager::normalVerbosity){
		this->getMinimizer()->PrintResults();
		Info("Process","Fit was done");
		cout<<m_minimizer->X()[0]<<" "<<m_minimizer->X()[1]<<" "<<m_minimizer->X()[2]<<endl;
		cout<<m_minimizer->X()[3]<<" "<<m_minimizer->X()[4]<<" "<<m_minimizer->X()[5]<<endl;
		cout<<m_minimizer->X()[6]<<" "<<m_minimizer->X()[7]<<" "<<m_minimizer->X()[8]<<" "<<m_minimizer->X()[9]<<endl;
	}



	rReconIN.SetXYZ(m_minimizer->X()[0],m_minimizer->X()[1],m_minimizer->X()[2]);
	rReconOUT.SetXYZ(m_minimizer->X()[3],m_minimizer->X()[4],m_minimizer->X()[5]);



	rRecon=rReconOUT-rReconIN; //full trajectory

	Ntot=m_minimizer->X()[4];

	hX_1->Fill( rReconIN.X());
	hY_1->Fill( rReconIN.Y());
	hZ_1->Fill( rReconIN.Z());
	hXY_1->Fill( rReconIN.X(), rReconIN.Y());
	hXZ_1->Fill( rReconIN.X(), rReconIN.Z());
	hYZ_1->Fill( rReconIN.Y(), rReconIN.Z());

	hX_2->Fill( rReconOUT.X());
	hY_2->Fill( rReconOUT.Y());
	hZ_2->Fill( rReconOUT.Z());
	hXY_2->Fill( rReconOUT.X(), rReconOUT.Y());
	hXZ_2->Fill( rReconOUT.X(), rReconOUT.Z());
	hYZ_2->Fill( rReconOUT.Y(), rReconOUT.Z());



	/*Define the angles wrt the VERTICAL direction, that is -y. Phi is in the xz plane, wrt to X*/
	ux.SetXYZ(1.,0.,0.);uy.SetXYZ(0.,1.,0.),uz.SetXYZ(0.,0.,1.); //since we have down-going muons..
	theta=rRecon.Angle(-1.*uy); //since we have down-going muons..

	double yTMP=rRecon.Y();

	rRecon.SetY(0.); //project on XZ
	phi=rRecon.Angle(ux);
	rRecon.SetY(yTMP);

	hTheta->Fill(theta*TMath::RadToDeg());
	hPhi->Fill(phi*TMath::RadToDeg());



	hT0->Fill(m_minimizer->X()[7]);
	hNPhotons->Fill(m_minimizer->X()[8]);
	hTau->Fill( m_minimizer->X()[9]);




	return 0;
}
int TLikelihoodReconDriver::endOfData(){
	return 0;
}



