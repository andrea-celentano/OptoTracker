#include "TCitirocChargeCalibration.hh"

#include <iostream>
#include "time.h"
#include "TH1D.h"
#include "TSpectrum.h"
#include "TGraphErrors.h"
#include "TF1.h"
#include "TStyle.h"
using namespace std;



TCitirocChargeCalibration::TCitirocChargeCalibration() {
	// TODO Auto-generated constructor stub
	Info("TCitirocChargeCalibration","creator");
	m_TCitirocChargeCalibrationGui=0;

	m_grpeaks=0;
	m_fit=0;
	m_hfit=0;

	m_xmin=0;
	m_xmax=4096;
}


TCitirocChargeCalibration::~TCitirocChargeCalibration() {
	// TODO Auto-generated stub
	Info("TCitirocChargeCalibration","destructor");

}

Float_t TCitirocChargeCalibration::FitGains(){
	Info("FitGains","Doing fit in the range: %f - %f",m_xmin,m_xmax);
	Float_t gain=0;
	TSpectrum *s = new TSpectrum();
	Int_t nfound = s->Search(m_hfit,2,"",0.02);
	Int_t npeaks = s->GetNPeaks();
	Int_t npeaks_good=0;
	Info("FitGains","Found %d peaks to fit\n",nfound);


	Float_t *peaks;
	Double_t *altpeaks;
	peaks = s->GetPositionX();
	//  altpeaks = s->GetPositionY();

	//Sort peaks
	double temp;
	int nchanges=0;
	do{
		nchanges=0;
		for(int p=0;p<nfound-1;p++){
			if(peaks[p]>peaks[p+1]){
				temp=peaks[p];
				peaks[p]=peaks[p+1];
				peaks[p+1]=temp;
				nchanges++;
			}
			//cout<<"iteraciones "<<nchanges<<endl;
		}

	}while(nchanges!=0);


	for (int j=0 ; j<npeaks ; j++) {
		//cout << "Peak "<<j<<" at = " << peaks[j] <<", with "<<altpeaks[j] <<" counts"<< endl;
		if ((peaks[j]>m_xmin)&&(peaks[j]<m_xmax)){
			x[npeaks_good]=npeaks_good;
			y[npeaks_good]=peaks[j];
			npeaks_good++;
		}
	}
	Info("FitGains","Good peaks: %d \n",npeaks_good);

	int gg = 0;
	for (int g=0 ; g<npeaks_good ; g++){

		TF1 *gfit = new TF1("gfit","gaus",y[g]-20,y[g]+20);

		m_hfit->Fit(gfit,"QR+");

		// cout<<"Peak "<<g<<" in "<< y[g]<< " centroid: "<< gfit->GetParameter(1)<<endl;
		//cout<<"Difference: "<<abs( y[g] - gfit->GetParameter(1) )<<endl;
		//getchar();

		if( (fabs(y[g] - gfit->GetParameter(1)) ) < 25 ){
			gx[gg] = gg;
			gy[gg] = gfit->GetParameter(1);
			gey[gg] = gfit->GetParError(1);
			gg++;
			// cout<<"good"<<endl;
			//getchar();
		}

		if (gfit) delete gfit;

	}

	if(!m_grpeaks) m_grpeaks = new TGraphErrors(gg,gx,gy,0,gey);
	else { m_grpeaks->Clear();}
	/*for (int p=0; p<20 ; p++){
		m_grpeaks->SetPoint(p,p,0);
		m_grpeaks->SetPointError(p,p,0);
	}*/

	for(int p=0;p<gg;p++){
		m_grpeaks->SetPoint(p,gx[p],gy[p]);
		m_grpeaks->SetPointError(p,0,gey[p]);
	}


	m_grpeaks->SetTitle("SiPM Gain");
	m_grpeaks->GetXaxis()->SetTitle("Peak N+i");
	m_grpeaks->GetYaxis()->SetTitle("ADC Channel");
	m_grpeaks->SetMarkerColor(4);
	m_grpeaks->SetMarkerStyle(20);
	m_grpeaks->SetFillColor(0);


	//Fit
	//TF1 *fit = new TF1("fit","[0] + [1]*x",0.5,gg-0.5);
	m_fit = new TF1("fit","[0] + [1]*x",-0.5,gg+0.5);

	m_fit->SetParName(1,"Gain");
	m_fit->SetParName(0, "Pedestal");
	m_fit->SetParameter(1,50);
	m_fit->SetParameter(0,190);
	m_grpeaks->Fit(m_fit, "QR");





	Double_t p1 = m_fit->GetParameter(1);
	Double_t p1error = m_fit->GetParError(1);
	Double_t p0 = m_fit->GetParameter(0);
	Double_t p0error = m_fit->GetParError(0);
	/*
	cout<<"Gain "<<p1<<" error "<<p1error<<" ADC Counts/photoelectron"<<endl;
	cout<<"Pedestal "<<p0<<" error "<<p0error<<endl;
	 */
	if (s) delete s;
	return p1;
}

void TCitirocChargeCalibration::Fit(int ID,int ch){
	m_hfit=this->gethChargeRaw(ID,ch);
	this->FitGains();
	this->addgCalib(ID,ch,m_grpeaks);
}


int TCitirocChargeCalibration::doCalibrationGui(){
	m_TCitirocChargeCalibrationGui=new TCitirocChargeCalibrationGui(this,gClient->GetRoot(),1000,1000);
	m_TCitirocChargeCalibrationGui->Start();
}


