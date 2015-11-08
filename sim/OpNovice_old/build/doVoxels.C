#include "TFile.h"
#include "TTree.h"
#include "TSystem.h"

const int Nvx=5,Nvy=5,Nvz=5;
const int Npx=8,Npy=8,Npz=8,Npmt=4;
double Lx=52,Ly=52,Lz=52;

	


doVoxels(string fname){

	
	ifstream file(fname.c_str());
	
	int ix,iy,iz;
	
	double q,qmax;
	qmax=0;
	double xv,yv,zv;
	
	TH2D *hSlice[Nvy];
	
	for (int ii=0;ii<Nvy;ii++)	hSlice[ii]=new TH2D(Form("hSlice_%i",ii),Form("hSlice_%i;X(cm);Z(cm)",ii),Nvx,-Lx/2,Lx/2,Nvz,-Lz/2,Lz/2);
	
	
	
	
	
	for (int ii=0;ii<(Nvx*Nvy*Nvz);ii++){
		
		iz=ii/(Nvx*Nvy);
		iy=ii/(Nvx)-iz*Nvy;
		ix=ii-iy*Nvx-iz*Nvx*Nvy;
		file>>q;
		if (q>qmax) qmax=q;
		
		xv=-Lx/2+ix*(Lx/(Nvx))+Lx/(2*Nvx);
		yv=-Ly/2+iy*(Ly/(Nvy))+Ly/(2*Nvy);
		zv=-Lz/2+iz*(Lz/(Nvz))+Lz/(2*Nvz);
	
		hSlice[iy]->Fill(xv,zv,q);
		
	}	
	file.close();

	TCanvas *c=new TCanvas("c","c");
	c->Divide(4,4);
	for (int ii=0;ii<Nvy;ii++){
		c->cd(ii+1);
		c->cd(ii+1)->SetLogz();
		hSlice[ii]->GetZaxis()->SetRangeUser(0,qmax);
		hSlice[ii]->Draw("colz");
	}
	
}

