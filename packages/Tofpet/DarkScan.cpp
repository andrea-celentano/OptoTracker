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
	const int Nch=256;
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
		ich=(int)(channel+asic*64);
		istep1=distance(m_step1.begin(),find(m_step1.begin(),m_step1.end(),step1));
		ihisto=ich+istep1*Nch;
		//cout<<ihisto<<" "<<ich<<" "<<asic<<" "<<istep1<<" "<<step1<<endl;
		hRate[ihisto]->Fill(step2,rate);
	}



	//Ok, now I have hRate
	//Use the TTofpetThresholdCalibration!

	//1: Load histograms

	for (ich=0;ich<Nch;ich++){
		ihisto=ich+istep1*Nch;
		m_calib->addhRateRaw(ich,hRate[ihisto]);
	}
	//2: Compute derived histograms

	for (ich=0;ich<Nch;ich++){
		m_calib->computeRateDerived(ich);
	}

	//3: analysis

	for (ich=0;ich<Nch;ich++){
		m_calib->computeThresholds(ich);
	}

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
		ihisto=ich;
		c->cd(1);
		hRate[ihisto]->SetLineColor(istep1+1);
		(istep1 == 0 ? hRate[ihisto]->Draw() : hRate[ihisto]->Draw("SAME"));
		ymin=0.01;
		ymax=hRate[ihisto]->GetMaximum();
		cout<<ymin<<" "<<ymax<<endl;
		for (int iphe=0;iphe<m_calib->getNtransitions(ich);iphe++){
			int val=m_calib->getTransition(ich,iphe);
			//	cout<<iphe<<" "<<val<<endl;
			TLine *l=new TLine(val,ymin,val,ymax);
			l->SetLineColor(2);
			l->SetLineWidth(2);
			l->Draw("SAME");
		}
		c->cd(2);
		hRate2[ihisto]=m_calib->gethRateDerived(ich);
		hRate2[ihisto]->SetLineColor(istep1+1);
		hRate2[ihisto]->Draw();
		c->cd(3);
		gRate[ihisto]=m_calib->getgThr(ich);
		gRate[ihisto]->SetLineColor(istep1+1);
		gRate[ihisto]->SetMarkerColor(istep1+1);
		gRate[ihisto]->Draw("ALP");
		c->cd(4)->SetLogy();
		gRateVsThr[ihisto]=m_calib->getgRateVsThr(ich);
		gRateVsThr[ihisto]->SetLineColor(istep1+1);
		gRateVsThr[ihisto]->SetMarkerColor(istep1+1);
		gRateVsThr[ihisto]->Draw("ALP");


		c->Print(outname.c_str());
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
			ihisto=ich;
			hRate[ihisto]->SetLineColor(1);
			hRate2[ihisto]->SetLineColor(1);
			gRate[ihisto]->SetLineColor(1);
			gRate[ihisto]->SetMarkerColor(1);
			hRate[ihisto]->Write();
			hRate2[ihisto]->Write();
			gRate[ihisto]->Write();
			cout<<"step1: "<<m_step1.at(istep1)<<" ch: "<<ich<<" Thr 2 phe: "<<m_calib->getThreshold(ich,2)<<endl;
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



