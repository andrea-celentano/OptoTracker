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

int parseCommandLine(int argc,char **argv){
	for (int iarg=0;iarg<argc;iarg++){
		if (strcmp(argv[iarg],"-f")==0) fname=string(argv[iarg+1]);
		if (strcmp(argv[iarg],"-o")==0) outname=string(argv[iarg+1]);
	}
}


int main(int argc,char **argv){

	const int Nch=128;

	TFile *f;
	TTree *t;
	TH1D **hRate;


	float step1,step2,channel,asic,rate;
	int ich,ihisto,istep1;
	int N,Nstep1;

	vector < float > m_step1;

	outname="out.ps";
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
	hRate=new TH1D*[Nch*Nstep1];
	for (istep1=0;istep1<Nstep1;istep1++){
		for (ich=0;ich<Nch;ich++){

			hRate[ich+istep1*Nch]=new TH1D(Form("hRate_step%i_ch%i",istep1,ich),Form("hRate_step%i_ch%i:thr:rate",istep1,ich),64,-0.5,63.5);
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

	TCanvas *c=new TCanvas();
	c->SetLogy();
	c->SetGridx();
	c->SetGridy();
	c->Print((outname+"(").c_str());
	for (ich=0;ich<Nch;ich++){
		for (istep1=0;istep1<Nstep1;istep1++){
			ihisto=ich+istep1*Nch;

			hRate[ihisto]->SetLineColor(istep1+1);
			(istep1 == 0 ? hRate[ihisto]->Draw() : hRate[ihisto]->Draw("SAME"));
			if (istep1 == (Nstep1-1)) c->Print(outname.c_str());
		}
	}
	c->Print((outname+")").c_str());




	cout<<"DONE"<<endl;
}



