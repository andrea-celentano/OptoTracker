#include "TFile.h"
#include "TTree.h"
#include "TSystem.h"

macro(string fname){

  gSystem->Load("libOpNoviceClassesDict.so");

  TFile *f=new TFile(fname.c_str());
  TTree *t=f->Get("raw");

  vector <OpNovicePMTHit*> *PMTHit=NULL;
  t->SetBranchAddress("raw",&PMTHit);

  int Nentries=t->GetEntries();

  TH2D *h1=new TH2D("h1","h1",8,-49./2,49/2.,8,-49/2.,49/2.);
  TH2D *h2=new TH2D("h2","h2",8,-49./2,49/2.,8,-49/2.,49/2.);
  TH2D *h3=new TH2D("h3","h3",8,-49./2,49/2.,8,-49/2.,49/2.);


  TH2D *h1t=new TH2D("h1t","h1t",8,-49./2,49/2.,8,-49/2.,49/2.);
  TH2D *h2t=new TH2D("h2t","h2t",8,-49./2,49/2.,8,-49/2.,49/2.);
  TH2D *h3t=new TH2D("h3t","h3t",8,-49./2,49/2.,8,-49/2.,49/2.);

  int n,PMT,pixel,photons,bin;
  double xp,yp,T;

  for (int ii=0;ii<Nentries;ii++){
    t->GetEntry(ii);  
    n=PMTHit->size();
    

    for (int jj=0;jj<n;jj++){
      PMT=PMTHit->at(jj)->GetPMTNumber();
      photons=PMTHit->at(jj)->GetPhotonCount();
      
      //cout<<PMT<<" "<<photons<<endl;
      
      for (int qq=0;qq<photons;qq++){

	xp=PMTHit->at(jj)->GetX(qq);
	yp=PMTHit->at(jj)->GetY(qq);
	T=PMTHit->at(jj)->GetT(qq);
	//	cout<<xp<<" "<<yp<<endl;
	
	switch (PMT){
	case 0:
	  h1->Fill(xp,yp);
	  if (ii==0){
	    if (h1t->GetBinContent(h1t->FindBin(xp,yp))==0) h1t->SetBinContent(h1t->FindBin(xp,yp),T);
	    else if (T<h1t->GetBinContent(h1t->FindBin(xp,yp)))  h1t->SetBinContent(h1t->FindBin(xp,yp),T);
	  }
	  break;
	case 1:
	  h2->Fill(xp,yp);
	  if (ii==0){
	    if (h2t->GetBinContent(h2t->FindBin(xp,yp))==0)  h2t->SetBinContent(h2t->FindBin(xp,yp),T);
	    else if (T<h2t->GetBinContent(h2t->FindBin(xp,yp))) h2t->SetBinContent(h2t->FindBin(xp,yp),T);
	  }
	  break;   
	case 2:
	  h3->Fill(xp,yp);
	  if (ii==0){
	    if (h3t->GetBinContent(h3t->FindBin(xp,yp))==0)  h3t->SetBinContent(h3t->FindBin(xp,yp),T);
	    else if (T<h3t->GetBinContent(h3t->FindBin(xp,yp)))  h3t->SetBinContent(h3t->FindBin(xp,yp),T);
	  }
	  break;
	}
      }      
    }
  }
 

  TCanvas *c=new TCanvas("c","c");
  c->Divide(3,3);
  c->cd(4);h1->Draw("colz");
  c->cd(5);h2->Draw("colz");
  c->cd(6);h3->Draw("colz");


  TCanvas *c1=new TCanvas("c1","c1");
  c1->Divide(3,3);
  c1->cd(4);h1t->Draw("colz");
  c1->cd(5);h2t->Draw("colz");
  c1->cd(6);h3t->Draw("colz");

  

}
