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

}


TCitirocChargeCalibration::~TCitirocChargeCalibration() {
	// TODO Auto-generated stub
	Info("TCitirocChargeCalibration","destructor");

}

Float_t TCitirocChargeCalibration::FitGains(TH1D *hs){
	Float_t gain=0;
	TSpectrum *s = new TSpectrum();
	Int_t nfound = s->Search(hs,2,"",0.009);
	Int_t npeaks = s->GetNPeaks();
	printf("Found %d peaks to fit\n",nfound);
	printf("Found %d peaks to fit\n",npeaks);

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

		x[j] =j+1;
		y[j]=peaks[j];

	}

	int gg = 1;
	for (int g=0 ; g<npeaks ; g++){

		TF1 *gfit = new TF1("gfit","gaus",y[g]-20,y[g]+20);

		hs->Fit(gfit,"QR+");

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

	if(!grpeaks) grpeaks = new TGraphErrors(gg,gx,gy,0,gey);
	else { grpeaks->Clear();}
	for (int p=0; p<20 ; p++){grpeaks->SetPoint(p,p,0); grpeaks->SetPointError(p,p,0);}

	for(int p=0;p<gg;p++){ grpeaks->SetPoint(p,gx[p],gy[p]); grpeaks->SetPointError(p,0,gey[p]);}


	grpeaks->SetTitle("SiPM Gain");
	grpeaks->GetXaxis()->SetTitle("Peak N+i");
	grpeaks->GetYaxis()->SetTitle("ADC Channel");
	grpeaks->SetMarkerColor(4);
	grpeaks->SetMarkerStyle(20);
	grpeaks->SetFillColor(0);


	//Fit
	//TF1 *fit = new TF1("fit","[0] + [1]*x",0.5,gg-0.5);
	fit = new TF1("fit","[0] + [1]*x",0.5,8.5);

	fit->SetParName(1,"Gain");
	fit->SetParName(0, "Pedestal");
	fit->SetParameter(1,50);
	fit->SetParameter(0,190);
	grpeaks->Fit(fit, "QR");


	Double_t p1 = fit->GetParameter(1);
	Double_t p1error = fit->GetParError(1);
	Double_t p0 = fit->GetParameter(0);
	Double_t p0error = fit->GetParError(0);
/*
	cout<<"Gain "<<p1<<" error "<<p1error<<" ADC Counts/photoelectron"<<endl;
	cout<<"Pedestal "<<p0<<" error "<<p0error<<endl;
*/

	return p1;
}

int TCitirocChargeCalibration::doCalibrationGui(){
	m_TCitirocChargeCalibrationGui=new TCitirocChargeCalibrationGui(this,gClient->GetRoot(),1000,1000);
	m_TCitirocChargeCalibrationGui->Start();
}


