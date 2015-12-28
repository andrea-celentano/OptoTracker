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
#include "TApplication.h"
#include "TVector3.h"
#include "TRandom3.h"
#include "TGraph.h"
#include "TGraph2D.h"
#include "Cintex/Cintex.h"
#include "TList.h"


#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>





using namespace std;


TApplication gui("gui",0,NULL);

string fname;
string outname;
string outnameRoot;
int parseCommandLine(int argc,char **argv){
	for (int iarg=0;iarg<argc;iarg++){
		if (strcmp(argv[iarg],"-f")==0) fname=string(argv[iarg+1]);
		if (strcmp(argv[iarg],"-o")==0) {outname=string(argv[iarg+1])+".ps";outnameRoot=string(argv[iarg+1])+".root";}
	}
}


int main(int argc,char **argv){

	const int Nch=128;
	const int BIN_MIN=10;
	//	const double MAX_RATE=10E6; //for sure the thermal single phe are less than this

	TFile *f,*fOut;
	TTree *t;
	TH1D **hRate;
	TH1D **hRate2;
	TGraph **gRate2;
	TGraph **gRate2A;

	float step1,step2,channel,asic,rate;
	int ich,ihisto,istep1,id,imax,iphe;
	int N,Nstep1;


	double max,delta,diff;
	double data,prev_data,post_data;


	vector < float > m_step1;

	outname="out.ps";
	outnameRoot="out.root";
	parseCommandLine(argc,argv);

	f=new TFile(fname.c_str());
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
	gRate2=new TGraph*[Nch*Nstep1];
	gRate2A=new TGraph*[Nch*Nstep1];

	for (istep1=0;istep1<Nstep1;istep1++){
		for (ich=0;ich<Nch;ich++){
			id=ich+istep1*Nch;
			hRate[id]=new TH1D(Form("hRate_step%i_ch%i",istep1,ich),Form("hRate_step%i_ch%i:thr:rate",istep1,ich),64,-0.5,63.5);
			hRate[id]->SetStats(0);

			hRate2[id]=new TH1D(Form("hRate2_step%i_ch%i",istep1,ich),Form("hRate2_step%i_ch%i:thr:rate",istep1,ich),64,-0.5,63.5);
			hRate2[id]->SetStats(0);

			gRate2[id]=new TGraph();
			gRate2[id]->SetName(Form("gPhe_step%i_ch%i",istep1,ich));
			gRate2[id]->SetTitle(Form("gPhe_step%i_ch%i",istep1,ich));
			gRate2[id]->SetMarkerStyle(20);

			gRate2A[id]=new TGraph();
			gRate2A[id]->SetName(Form("gPheA_step%i_ch%i",istep1,ich));
			gRate2A[id]->SetTitle(Form("gPheA_step%i_ch%i",istep1,ich));
			gRate2A[id]->SetMarkerStyle(20);

			//	gRate2[id]->SetStats(0);
		}
	}

	for (int ii=0;ii<N;ii++){
		t->GetEntry(ii);
		if (asic>=2) continue; //TODO TEMPORARY
		ich=(int)(channel+asic*64);
		istep1=distance(m_step1.begin(),find(m_step1.begin(),m_step1.end(),step1));
		ihisto=ich+istep1*Nch;
		cout<<ihisto<<" "<<ich<<" "<<asic<<" "<<istep1<<" "<<step1<<endl;
		hRate[ihisto]->Fill(step2,rate);
	}

	/*Ok, now I have hRate*/
	for (istep1=0;istep1<Nstep1;istep1++){
		for (ich=0;ich<Nch;ich++){
			id=ich+istep1*Nch;
			imax=hRate[id]->GetMaximumBin();

			for (int ibin=imax;ibin>=BIN_MIN;ibin--){
				data=hRate[id]->GetBinContent(ibin);
				//	if (data>MAX_RATE) continue; //this avoids counting at the baseline

				diff=hRate[id]->GetBinContent(ibin)-hRate[id]->GetBinContent(ibin-1);
				delta=hRate[id]->GetBinContent(ibin)+hRate[id]->GetBinContent(ibin-1);
				if (delta!=0){
					diff=2*diff/delta;
					hRate2[id]->SetBinContent(ibin,diff);
				}
			}
			hRate2[id]->Smooth(1); //to avoid a local maximum
		}
	}
	for (istep1=0;istep1<Nstep1;istep1++){
		for (ich=0;ich<Nch;ich++){
			id=ich+istep1*Nch;
			imax=hRate[id]->GetMaximumBin();
			iphe=0;
			for (int ibin=imax;ibin>=BIN_MIN;ibin--){
				data=hRate2[id]->GetBinContent(ibin);
				prev_data=hRate2[id]->GetBinContent(ibin+1);
				post_data=hRate2[id]->GetBinContent(ibin-1);
				if ((data>prev_data)&&(data>post_data)){
					gRate2[id]->SetPoint(iphe,hRate2[id]->GetBinCenter(ibin),iphe);
					gRate2A[id]->SetPoint(iphe,63-hRate2[id]->GetBinCenter(ibin),iphe);
					iphe++;
				}
			}
		}
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
		for (istep1=0;istep1<Nstep1;istep1++){
			ihisto=ich+istep1*Nch;
			c->cd(1);
			hRate[ihisto]->SetLineColor(istep1+1);
			(istep1 == 0 ? hRate[ihisto]->Draw() : hRate[ihisto]->Draw("SAME"));

			c->cd(2);
			hRate2[ihisto]->SetLineColor(istep1+1);
			(istep1 == 0 ? hRate2[ihisto]->Draw() : hRate2[ihisto]->Draw("SAME"));
			c->cd(3);
			gRate2[ihisto]->SetLineColor(istep1+1);
			gRate2[ihisto]->SetMarkerColor(istep1+1);

			(istep1 == 0 ? gRate2[ihisto]->Draw("ALP") : gRate2[ihisto]->Draw("PLSAME"));

			c->cd(4);
			gRate2A[ihisto]->SetLineColor(istep1+1);
			gRate2A[ihisto]->SetMarkerColor(istep1+1);

			(istep1 == 0 ? gRate2A[ihisto]->Draw("ALP") : gRate2A[ihisto]->Draw("PLSAME"));

			if (istep1 == (Nstep1-1)) c->Print(outname.c_str());


		}
	}
	c->Print((outname+")").c_str());

	fOut->cd();

	for (ich=0;ich<Nch;ich++){
		for (istep1=0;istep1<Nstep1;istep1++){
			ihisto=ich+istep1*Nch;
			hRate[ihisto]->SetLineColor(1);
			hRate2[ihisto]->SetLineColor(1);
			gRate2[ihisto]->SetLineColor(1);
			gRate2[ihisto]->SetMarkerColor(1);
			hRate[ihisto]->Write();
			hRate2[ihisto]->Write();
			gRate2[ihisto]->Write();
			gRate2A[ihisto]->Write();
		}
	}

	cout<<"DONE"<<endl;
}



