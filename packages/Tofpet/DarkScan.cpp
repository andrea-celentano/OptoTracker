#include "TFile.h"
#include "TTree.h"
#include "TChain.h"
#include "TSystem.h"
#include "TProof.h"
#include "TProofLog.h"

#include "TH1D.h"
#include "TH2D.h"
#include "TMath.h"
#include "TCanvas.h"
#include "TF1.h"
#include "TApplication.h"
#include "TVector3.h"
#include "TRandom3.h"
#include "TGraph.h"
#include "TGraphErrors.h"
#include "TGraph2D.h"
#include "TLine.h"
#include "Cintex/Cintex.h"
#include "TList.h"
#include "TROOT.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "TTofpetThresholdCalibration.hh"
#include "TTofpetRun.hh"


using namespace std;


TApplication gui("gui",0,NULL);

string fname;
string outname;
string outnameRoot;
int parseCommandLine(int argc,char **argv){

	if (argc==1){
		cout<<"-f infilename"<<endl;
		cout<<"-o outfilename, no suffixe"<<endl;
		cout<<"-b batch"<<endl;
	}
	for (int iarg=0;iarg<argc;iarg++){
		if (strcmp(argv[iarg],"-f")==0) fname=string(argv[iarg+1]);
		if (strcmp(argv[iarg],"-o")==0) {outname=string(argv[iarg+1])+".ps";outnameRoot=string(argv[iarg+1])+".root";}
		if (strcmp(argv[iarg],"-b")==0) {gROOT->SetBatch(1);}
	}
}


int main(int argc,char **argv){
	ROOT::Cintex::Cintex::Enable();
	const int Nch=128;
	const int BIN_MIN=10;
	const double MAX_RATE=5E6; //for sure the thermal single phe are less than this

	TFile *f,*fOut;
	TTree *t;
	TH1D **hRate;
	TH1D **hRate2;
	TGraph **gRateVsThr;
	TGraph **gRate;


	TH1D** hSlope;
	TH1D** hRateSinglePhe;
	TTofpetThresholdCalibration *m_calib;

	float step1,step2,channel,asic,rate;
	int ich,ihisto,istep1,id,imax,iphe;
	int N,Nstep1;
	double ymin,ymax;
	float *rateSinglePhe,*rateSinglePheTMP;

	double max,delta,diff;
	double data,prev_data,post_data;

	vector < float > *m_thr;
	vector < float > m_step1;

	outname="out.ps";
	outnameRoot="out.root";
	parseCommandLine(argc,argv);



	f=new TFile(fname.c_str());

	m_calib=new TTofpetThresholdCalibration();

	t=(TTree*)f->Get("data");



	t->SetBranchAddress("step1",&step1);
	t->SetBranchAddress("step2",&step2);
	t->SetBranchAddress("asic",&asic);
	t->SetBranchAddress("channel",&channel);
	t->SetBranchAddress("rate",&rate);

	/*First, determine the values of step1*/
	N=t->GetEntries();
	for (int ii=0;ii<N;ii++){
		t->GetEntry(ii);
		if (find(m_step1.begin(),m_step1.end(),step1) == m_step1.end()){
			m_step1.push_back(step1);
		}
	}



	Nstep1=m_step1.size();
	Info("main","There are %i values of step1",Nstep1);
	for (istep1=0;istep1<Nstep1;istep1++){
		Info("main","value %i : %f",istep1,m_step1.at(istep1));
	}

	fOut=new TFile(outnameRoot.c_str(),"recreate");

	hRate=new TH1D*[Nch*Nstep1];
	hRate2=new TH1D*[Nch*Nstep1];
	gRate=new TGraph*[Nch*Nstep1];
	gRateVsThr=new TGraph*[Nch*Nstep1];

	/*
	gRate2A=new TGraphErrors*[Nch*Nstep1];

	hSlope=new TH1D*[Nstep1];
	hRateSinglePhe=new TH1D*[Nstep1];

	rateSinglePhe=new float[Nch*Nstep1];
	rateSinglePheTMP=new float[Nch*Nstep1];

	m_thr = new vector<float>[Nch*Nstep1];*/

	for (istep1=0;istep1<Nstep1;istep1++){


		for (ich=0;ich<Nch;ich++){
			id=ich+istep1*Nch;
			cout<<"Creating histo for ch: "<<ich<<" step1 val: "<<m_step1.at(istep1)<<endl;
			hRate[id]=new TH1D(Form("hRateRaw_step%i_ch%i",int(m_step1.at(istep1)),ich),Form("hRateRaw_step%i_ch%i:thr:rate",int(m_step1.at(istep1)),ich),64,-0.5,63.5);
			hRate[id]->SetStats(0);

			/*	hRate2[id]=new TH1D(Form("hRate2_step%i_ch%i",int(m_step1.at(istep1)),ich),Form("hRate2_step%i_ch%i:thr:rate",int(m_step1.at(istep1)),ich),64,-0.5,63.5);
			hRate2[id]->SetStats(0);

			gRate2[id]=new TGraph();
			gRate2[id]->SetName(Form("gPhe_step%i_ch%i",int(m_step1.at(istep1)),ich));
			gRate2[id]->SetTitle(Form("gPhe_step%i_ch%i",int(m_step1.at(istep1)),ich));
			gRate2[id]->SetMarkerStyle(20);

			gRate2A[id]=new TGraphErrors();
			gRate2A[id]->SetName(Form("gPheA_step%i_ch%i",int(m_step1.at(istep1)),ich));
			gRate2A[id]->SetTitle(Form("gPheA_step%i_ch%i",int(m_step1.at(istep1)),ich));
			gRate2A[id]->SetMarkerStyle(20);*/

			//	gRate2[id]->SetStats(0);
		}

		//	hSlope[istep1]=new TH1D(Form("hSlope_step1:%i",istep1),Form("hSlope_step1:%i",istep1),100,0,6);
		//	hRateSinglePhe[istep1]=new TH1D(Form("hRateSinglePhe_step1:%i",istep1),Form("hRateSinglePhe_step1:%i",istep1),Nch,-0.5,Nch-0.5);

	}

	/*Now read the data!*/
	for (int ii=0;ii<N;ii++){
		t->GetEntry(ii);
		if (asic>=2) continue; //TODO TEMPORARY
		ich=(int)(channel+asic*64);
		istep1=distance(m_step1.begin(),find(m_step1.begin(),m_step1.end(),step1));
		ihisto=ich+istep1*Nch;
		//cout<<ihisto<<" "<<ich<<" "<<asic<<" "<<istep1<<" "<<step1<<endl;
		hRate[ihisto]->Fill(step2,rate);
	}



	//Ok, now I have hRate
	//Use the TTofpetThresholdCalibration!

	//1: Load histograms
	for (istep1=0;istep1<Nstep1;istep1++){
		for (ich=0;ich<Nch;ich++){
			ihisto=ich+istep1*Nch;
			m_calib->addhRateRaw(ich,m_step1.at(istep1),hRate[ihisto]);
		}
	}
	//2: Compute derived histograms
	for (istep1=0;istep1<Nstep1;istep1++){
		for (ich=0;ich<Nch;ich++){
			m_calib->computeRateDerived(ich,m_step1.at(istep1));
		}
	}
	//3: analysis
	for (istep1=0;istep1<Nstep1;istep1++){
		for (ich=0;ich<Nch;ich++){
			m_calib->computeThresholds(ich,m_step1.at(istep1));
		}
	}



	//Now I compute the numerical derivative of the spectrum
	//	cout<<"Computing numerical derivative"<<endl;
	/*
	for (istep1=0;istep1<Nstep1;istep1++){
		for (ich=0;ich<Nch;ich++){
			id=ich+istep1*Nch;

			//Compute the derivative of the spectrum starting from the FIRST bin above max_rate
			for (int ibin=0;ibin<hRate[id]->GetNbinsX();ibin++){
				data=hRate[id]->GetBinContent(ibin);
				if (data>MAX_RATE){
					imax=ibin;
					break;
				}
			}

			for (int ibin=imax;ibin>=BIN_MIN;ibin--){
				data=hRate[id]->GetBinContent(ibin);
				//	if (data>MAX_RATE) continue; //this avoids counting at the baseline

				//diff=hRate[id]->GetBinContent(ibin)-hRate[id]->GetBinContent(ibin-1);
				diff=hRate[id]->GetBinContent(ibin+1)-hRate[id]->GetBinContent(ibin-1);
				delta=hRate[id]->GetBinContent(ibin);
				if (delta!=0){
					diff=2*diff/delta;
					hRate2[id]->SetBinContent(ibin,diff);
				}
			}
			//hRate2[id]->Smooth(1); //to avoid a local maximum
		}
	}

	cout<<"Searching maxima"<<endl;
	//Looking for maxima
	for (istep1=0;istep1<Nstep1;istep1++){
		for (ich=0;ich<Nch;ich++){
			id=ich+istep1*Nch;
			//Compute the derivative of the spectrum starting from the FIRST bin above max_rate
			for (int ibin=0;ibin<hRate[id]->GetNbinsX();ibin++){
				data=hRate[id]->GetBinContent(ibin);
				if (data>MAX_RATE){
					imax=ibin;
					break;
				}
			}
			iphe=0;
			for (int ibin=imax;ibin>=BIN_MIN;ibin--){
				data=hRate2[id]->GetBinContent(ibin);
				prev_data=hRate2[id]->GetBinContent(ibin+1);
				post_data=hRate2[id]->GetBinContent(ibin-1);
				if ((data>prev_data)&&(data>post_data)){
					m_thr[id].push_back(hRate2[id]->GetBinCenter(ibin));
					//					gRate2[id]->SetPoint(iphe,hRate2[id]->GetBinCenter(ibin),iphe);
					iphe++;
				}
			}
		}
	}
	//Now compute the rate corresponding to 1 phe and save it
	cout<<"Computing single phe rate"<<endl;
	for (istep1=0;istep1<Nstep1;istep1++){
		for (ich=0;ich<Nch;ich++){
			id=ich+istep1*Nch;
			if (m_thr[id].size()>1)			rate=hRate[id]->GetBinContent(hRate[id]->FindBin(m_thr[id].at(1)));
			else rate=0;
			rateSinglePhe[id]=rate;
		}
	}


	//Now it is important to do a check: the 1 phe rate should be, for sure, < 10MHz or so.
	// If it is higher, it means there is 1 fake peak (or more)
	//
	cout<<"Rate correction"<<endl;
	bool common_flag;
	while(1){
		common_flag=true;
		//First, loop on all channels and check the single-phe rate
		for (istep1=0;istep1<Nstep1;istep1++){
			for (int ich=0;ich<Nch;ich++){
				id=ich+istep1*Nch;
				rate=rateSinglePhe[id];
				if (rate>MAX_RATE){
					cout<<"Doing correction for channel: "<<ich<<" step: "<<istep1<<endl;
					cout<<"Before: "<<rate<<endl;
					common_flag=false;
					//implement the correction->translate by -1 the phe, starting from 1
					m_thr[id].erase(m_thr[id].begin());
					//re-compute rateSinglePhe for this
					rate=hRate[id]->GetBinContent(hRate[id]->FindBin(m_thr[id].at(1)));
					rateSinglePhe[id]=rate;
					cout<<"After: "<<rate<<endl<<endl;

				}
			}
		}
		if (common_flag) break;
	}
	//
	for (istep1=0;istep1<Nstep1;istep1++){
		for (ich=0;ich<Nch;ich++){
			id=ich+istep1*Nch;
			for (int iphe=0;iphe<m_thr[id].size();iphe++){
				gRate2[id]->SetPoint(iphe,m_thr[id].at(iphe),iphe);
				gRate2A[id]->SetPoint(iphe,iphe,63-m_thr[id].at(iphe));
				gRate2A[id]->SetPointError(iphe,0.,1./sqrt(12.));
			}
			if (gRate2A[id]->GetN()>2){
				gRate2A[id]->Fit("pol1","FQ");
				hSlope[istep1]->Fill(gRate2A[id]->GetFunction("pol1")->GetParameter(1));
			}
			rate=rateSinglePhe[id];
			hRateSinglePhe[istep1]->Fill(ich,rate);
		}

	}

	 */

	/*		if (gRate2A[id]->GetN()>2){
				gRate2A[id]->Fit("pol1","F");
				hSlope->Fill(gRate2A[id]->GetFunction("pol1")->GetParameter(1));
			}
		}
	}*/

	TCanvas *c=new TCanvas();

	c->Divide(2,2);

	c->cd(1)->SetLogy();
	c->cd(1)->SetGridx();
	c->cd(1)->SetGridy();

	c->cd(2)->SetLogy();
	c->cd(2)->SetGridx();
	c->cd(2)->SetGridy();


	c->Print((outname+"(").c_str());


	for (ich=0;ich<Nch;ich++){
		for (istep1=0;istep1<Nstep1;istep1++){
			ihisto=ich+istep1*Nch;
			c->cd(1);
			hRate[ihisto]->SetLineColor(istep1+1);
			(istep1 == 0 ? hRate[ihisto]->Draw() : hRate[ihisto]->Draw("SAME"));
			ymin=0.01;
			ymax=hRate[ihisto]->GetMaximum();
			cout<<ymin<<" "<<ymax<<endl;
			for (int iphe=0;iphe<m_calib->getNtransitions(ich,m_step1.at(istep1));iphe++){
				int val=m_calib->getTransition(ich,m_step1.at(istep1),iphe);
				//	cout<<iphe<<" "<<val<<endl;
				TLine *l=new TLine(val,ymin,val,ymax);
				l->SetLineColor(2);
				l->SetLineWidth(2);
				l->Draw("SAME");
			}
			c->cd(2);
			hRate2[ihisto]=m_calib->gethRateDerived(ich,m_step1.at(istep1));
			hRate2[ihisto]->SetLineColor(istep1+1);
			(istep1 == 0 ? hRate2[ihisto]->Draw() : hRate2[ihisto]->Draw("SAME"));
			c->cd(3);
			gRate[ihisto]=m_calib->getgThr(ich,m_step1.at(istep1));
			gRate[ihisto]->SetLineColor(istep1+1);
			gRate[ihisto]->SetMarkerColor(istep1+1);
			(istep1 == 0 ? gRate[ihisto]->Draw("ALP") : gRate[ihisto]->Draw("PLSAME"));
			c->cd(4)->SetLogy();
			gRateVsThr[ihisto]=m_calib->getgRateVsThr(ich,m_step1.at(istep1));
			gRateVsThr[ihisto]->SetLineColor(istep1+1);
			gRateVsThr[ihisto]->SetMarkerColor(istep1+1);
			(istep1 == 0 ? gRateVsThr[ihisto]->Draw("ALP") : gRateVsThr[ihisto]->Draw("PLSAME"));



			if (istep1 == (Nstep1-1)) c->Print(outname.c_str());




		}
	}
	TCanvas *cReport0=new TCanvas();/*
	cReport0->Divide(2,2);
	cReport0->cd(1);
	for (istep1=0;istep1<Nstep1;istep1++){
		(istep1==0 ? hSlope[istep1]->Draw() : hSlope[istep1]->Draw("SAME"));
	}
	cReport0->cd(2);

	for (istep1=0;istep1<Nstep1;istep1++){
		(istep1==0 ? hRateSinglePhe[istep1]->Draw() : hRateSinglePhe[istep1]->Draw("SAME"));
	}
	 */
	cReport0->Print((outname+")").c_str());


	for (ich=0;ich<Nch;ich++){
		for (istep1=0;istep1<Nstep1;istep1++){
			ihisto=ich+istep1*Nch;
			hRate[ihisto]->SetLineColor(1);
			hRate2[ihisto]->SetLineColor(1);
			gRate[ihisto]->SetLineColor(1);
			gRate[ihisto]->SetMarkerColor(1);
			hRate[ihisto]->Write();
			hRate2[ihisto]->Write();
			gRate[ihisto]->Write();
			cout<<"step1: "<<m_step1.at(istep1)<<" ch: "<<ich<<" Thr 2 phe: "<<m_calib->getThreshold(ich,step1,2)<<endl;
		}
	}
	fOut->cd();
	//m_calib->printhRateDerived();
	m_calib->Write();
	/*for (istep1=0;istep1<Nstep1;istep1++){

		hRateSinglePhe[istep1]->Write();
		hSlope[istep1]->Write();
	}
	 */
	fOut->Close();
	cout<<"DONE"<<endl;
}



