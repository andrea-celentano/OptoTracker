#include <iostream>
#include <string>

#include "TFile.h"
#include "TTree.h"
#include "TH1D.h"
#include "TH2D.h"
#include "TF1.h"
#include "TCanvas.h"
#include "TLine.h"
#include "TApplication.h"
#include "TROOT.h"

#include "MarocSetupHandler.hh"
#include "TOpNoviceDetectorLight.hh"

using namespace std;


/*From the command line*/
string fSigName,fBckName,fDetName,fOutNameRoot,fOutNamePS,fOutName;
int fDoBatch=0;
void ParseCommandLine(int argc,char **argv);
void PrintHelp();
TApplication gui("GUI",0,NULL);


int main(int argc,char **argv){
  if (argc==0){
    PrintHelp();
    exit(1);
  }
  ParseCommandLine(argc,argv);	
  
  
  if (fDoBatch)  gROOT->SetBatch();
  

  
  if (fSigName.length()==0){
   cerr<<"Missing SIGNAL file name!"<<endl;
   return -1;
  }
  if (fBckName.length()==0){
   cerr<<"Missing BCK file name!"<<endl;
   return -1;
  }
  if (fDetName.length()==0){
   cerr<<"Missing DET file name"<<endl;
   return -1;
  }
  
  if (fOutName.length()==0){
   cout<<"Missing OUT file name, auto-selecting"<<endl;
   fOutName=fSigName+".out";
  }
  fOutNameRoot=fOutName+".root";
  fOutNamePS=fOutName+".ps";
  TFile *f1=new TFile(fSigName.c_str());
  TFile *f2=new TFile(fBckName.c_str());
  
  TFile *fOut=new TFile(fOutName.c_str(),"recreate");


  TTree *tSig=(TTree*)f1->Get("fTdata");
  TTree *tBck=(TTree*)f2->Get("fTdata");
  
  Float_t ADC[4096];
  Bool_t hit[4096];
  double PedSig[4096],PedBck[4096];
 
  Int_t EvtMultiplicity;
  int Nb,Ns,Nped;
  int id;
  int ix,iy,iboard,iH8500,iMaroc;
  double Q;

  double MeanSig,MeanBck,MeanDiff;
  double Saturation;

  int Nx,Ny;
  TOpNoviceDetectorLight *m_detector=new TOpNoviceDetectorLight(fDetName);
  /*Define here the histograms*/

  TH1D **hChargeSig=new TH1D*[Ntot];  TH1D **hChargeSig2=new TH1D*[Ntot];
  TH1D **hChargeBck=new TH1D*[Ntot];  TH1D **hChargeBck2=new TH1D*[Ntot];
  TH1D **hChargeDiff=new TH1D*[Ntot];

  TH2D *hGrid=new TH2D("hGrid","hGrid",16,-8.5,7.5,8,-0.5,7.5);
  TH2D *hGainMap=new TH2D("hGainMap","hGainMap",16,-8.5,7.5,8,-0.5,7.5);
  TH2D *hMeanSig=new TH2D("hMeanSig","hMeanSig",16,-8.5,7.5,8,-0.5,7.5);
  TH2D *hMeanBck=new TH2D("hMeanBck","hMeanBck",16,-8.5,7.5,8,-0.5,7.5);
  TH2D *hMeanDiff=new TH2D("hMeanDiff","hMeanDiff",16,-8.5,7.5,8,-0.5,7.5);
  
  
  TH1D* hChargeExp[6][MAX_DETECTORS];
  TH1D* hChargeTeo[6][MAX_DETECTORS];
  
  for (int ii=0;ii<Ntot;ii++){
    iH8500=GetH8500Id(ii+N0);
    
    hChargeSig[ii]=new TH1D(Form("hChargeSig%i",ii),Form("hChargeSig%i:H8500_%i",ii,iH8500),4096,-0.5,4095.5);
    hChargeBck[ii]=new TH1D(Form("hChargeBck%i",ii),Form("hChargeBck%i:H8500_%i",ii,iH8500),4096,-0.5,4095.5);
    hChargeDiff[ii]=new TH1D(Form("hChargeDiff%i",ii),Form("hChargeDiff%i:H8500_%i",ii,iH8500),5000,-1000.5,3999.5);
  }
  
  
  for (int ii=0;ii<6;ii++){
		for (int jj=0;jj<m_detector->getNdet(ii);jj++){
			if (m_detector->isDetPresent(ii,jj)){
				Nx=m_detector->getNPixelsX(ii,jj);
				Ny=m_detector->getNPixelsY(ii,jj);
				hChargeExp[ii][jj]=new TH1D(Form("hChargeTeo%i_%i",ii,jj),Form("hChargeExo%i_%i",ii,jj),Nx*Ny,-0.5,Nx*Ny-0.5);
				hChargeTeo[ii][jj]=new TH1D(Form("hChargeExp%i_%i",ii,jj),Form("hChargeTeo%i_%i",ii,jj),Nx*Ny,-0.5,Nx*Ny-0.5);
			}
		}
  }
  
  
  /*Process the signal*/
  tSig->SetBranchAddress("ADC",ADC);
  tSig->SetBranchAddress("EvtMultiplicity",&EvtMultiplicity);
  tSig->SetBranchAddress("hit",hit);

  
  Ns=tSig->GetEntries();
  cout<<"There are "<<Ns<<" signals "<<endl;
  for (int ii=0;ii<Ns;ii++){    
    tSig->GetEntry(ii);
    for (int jj=0;jj<Ntot;jj++){
      id=jj+N0;
      Q=ADC[id];  
      hChargeSig[jj]->Fill(Q);
      //  hChargeDiff[jj]->Fill(Q,+1);
    }
  }
 
  /*Process the background*/
  tBck->SetBranchAddress("ADC",ADC);
  tBck->SetBranchAddress("EvtMultiplicity",&EvtMultiplicity);
  tBck->SetBranchAddress("hit",hit);

  Nb=tBck->GetEntries();
  cout<<"There are "<<Nb<<" backgrounds"<<endl;
  for (int ii=0;ii<Nb;ii++){
    tBck->GetEntry(ii);
    for (int jj=0;jj<Ntot;jj++){
      id=jj+N0;
      Q=ADC[id];
      //if (Q<100) Q=0;
      hChargeBck[jj]->Fill(Q);
      //  hChargeDiff[jj]->Fill(Q,-1);
    }
  }
  /*Compute the pedestals*/
  for (int jj=0;jj<Ntot;jj++){
    double min,max;
    
    min=hChargeSig[jj]->GetBinCenter(hChargeSig[jj]->GetMaximumBin());
    max=min;
    min-=15;
    max+=15;
    hChargeSig[jj]->Fit("gaus","RL","",min,max);
   
    min=hChargeBck[jj]->GetBinCenter(hChargeBck[jj]->GetMaximumBin());
    max=min;
    min-=15;
    max+=15;
    hChargeBck[jj]->Fit("gaus","RL","",min,max);

    PedSig[jj]=hChargeSig[jj]->GetFunction("gaus")->GetParameter(1);
    PedBck[jj]=hChargeBck[jj]->GetFunction("gaus")->GetParameter(1);
  }
  
  /*Process the signal, again*/
  tSig->SetBranchAddress("ADC",ADC);
  tSig->SetBranchAddress("EvtMultiplicity",&EvtMultiplicity);
  tSig->SetBranchAddress("hit",hit);
  Ns=tSig->GetEntries();
  for (int ii=0;ii<Ns;ii++){    
    tSig->GetEntry(ii);
    for (int jj=0;jj<Ntot;jj++){
      id=jj+N0;
      Q=ADC[id]-PedSig[jj];  
      //      hChargeSig[jj]->Fill(Q);
      hChargeDiff[jj]->Fill(Q,+1);
    }
  }


  /*Process the bck, again*/
  tBck->SetBranchAddress("ADC",ADC);
  tBck->SetBranchAddress("EvtMultiplicity",&EvtMultiplicity);
  tBck->SetBranchAddress("hit",hit);
 
  for (int ii=0;ii<Nb;ii++){    
    tBck->GetEntry(ii);
    for (int jj=0;jj<Ntot;jj++){
      id=jj+N0;
      Q=ADC[id]-PedBck[jj];  
      hChargeDiff[jj]->Fill(Q,-1);
    }
  }



  for (int jj=0;jj<Ntot;jj++){
    iboard=jj/64;
    iH8500=GetH8500Id(jj+N0)-1;
    iMaroc=GetMarocId(jj+N0);
    if (iboard==0){
      ix=iH8500%8;
    }
    else {
      ix=-iH8500%8-1;
    }
    iy=7-iH8500/8;
    MeanSig=hChargeSig[jj]->GetMean();
    MeanBck=hChargeBck[jj]->GetMean();
    MeanDiff=hChargeDiff[jj]->GetMean();

    //   MeanSig/=H8500Gain(iH8500,iboard);
    //  MeanBck/=H8500Gain(iH8500,iboard);
    MeanDiff/=H8500Gain(iH8500,iboard);
    
    
    // MeanSig/=MarocGain(GetMarocId(jj+N0));
    // MeanBck/=MarocGain(GetMarocId(jj+N0));
    MeanDiff/=MarocGain(GetMarocId(jj+N0));

    hGrid->Fill(ix,iy,jj);
    hGainMap->Fill(ix,iy,H8500Gain(iH8500,iboard)*MarocGain(GetMarocId(jj+N0)));
    hMeanSig->Fill(ix,iy,MeanSig);
    hMeanBck->Fill(ix,iy,MeanBck);
    hMeanDiff->Fill(ix,iy,MeanDiff);



    hChargeDiff[jj]->Fit("pol1","LQ","R",0.5E3,.9E3);
    hChargeDiff[jj]->GetFunction("pol1")->SetLineColor(2); 
 
    hChargeExp[][0]->Fill(GetMarocId(jj+N0),MeanDiff);
    
  }
  

  
  /*Plots*/
  TCanvas **c=new TCanvas*[Ntot];
 
 
  for (int jj=0;jj<Ntot;jj++){
    iboard=jj/64;
    iH8500=GetH8500Id(jj+N0);




    c[jj]=new TCanvas(Form("c%i",jj),Form("c:H8500_%i",iH8500));
    c[jj]->Divide(2,2);
    c[jj]->cd(1)->SetLogy();
    //  hChargePed[jj]->GetXaxis()->SetRangeUser(1250,1500);
    // hChargePed[jj]->Draw();

    c[jj]->cd(2)->SetLogy();
    hChargeSig[jj]->GetXaxis()->SetRangeUser(1250,3000);
    hChargeSig[jj]->SetFillColor(kYellow-9);
    hChargeSig[jj]->Draw();
    hChargeBck[jj]->SetLineColor(2);
    hChargeBck[jj]->SetFillColor(kRed-9);
    hChargeBck[jj]->Draw("SAME");

    c[jj]->cd(3)->SetLogy();
    hChargeDiff[jj]->GetXaxis()->SetRangeUser(-500,1600);
    hChargeDiff[jj]->Draw();
  

    

    if (jj==0) c[jj]->Print((fOutNamePS+"(").c_str());
    else  c[jj]->Print(fOutNamePS.c_str());
    fOut->cd();
    c[jj]->Write();
   }

  TLine *l=new TLine(-0.5,-0.5,-0.5,7.5);l->SetLineWidth(2);l->SetLineColor(2);

  

  TCanvas *ca=new TCanvas("ca","ca");
  ca->Divide(2,2);
  ca->cd(1);
  hGainMap->GetXaxis()->SetRangeUser(1000,2000);
  hGainMap->Draw("colz");
  hGrid->SetMarkerSize(1.8);hGrid->SetMarkerColor(0);
  hGrid->Draw("TEXTSAME");
  l->Draw("SAME");
 

  ca->cd(2);
  hMeanSig->SetStats(0);
  hMeanSig->Draw("colz");
  hGrid->Draw("TEXTSAME");
  l->Draw("SAME");

  ca->cd(3);
  hMeanBck->SetStats(0);
  hMeanBck->Draw("colz");
  hGrid->Draw("TEXTSAME");

  ca->cd(4);
  hMeanDiff->SetStats(0);
  hMeanDiff->Draw("colz");
  hGrid->Draw("TEXTSAME");
  l->Draw("SAME");
  ca->Print((fOutNamePS+")").c_str());
  fOut->cd();
  ca->Write();

  if (fDoBatch==0){
    gui.Run(1);
  }
  cout<<"Done"<<endl;
}



void ParseCommandLine(int argc,char **argv){
	for (int ii=0;ii<argc;ii++){
		if ((strcmp(argv[ii],"-s")==0)||(strcmp(argv[ii],"-signal")==0)){
			fSigName=string(argv[ii+1]);
		}
		
		else if ((strcmp(argv[ii],"-b")==0)||(strcmp(argv[ii],"-background")==0)){
			fBckName=string(argv[ii+1]);
		}
		
		else if ((strcmp(argv[ii],"-o")==0)||(strcmp(argv[ii],"-out")==0)){
			fOutName=string(argv[ii+1]);
		}
		else if ((strcmp(argv[ii],"-d")==0)||(strcmp(argv[ii],"-det")==0)){
			fDetName=string(argv[ii+1]);
		}
		else if ((strcmp(argv[ii],"-h")==0)||(strcmp(argv[ii],"-help")==0)){
			PrintHelp();
		}
		else if (strcmp(argv[ii],"-batch")==0){
			fDoBatch=true;
		}
		
	}
	
}



void PrintHelp(){
    cout<<"-s or -signal: signal file name"<<endl;
    cout<<"-b or -background: bck file name"<<endl;
    cout<<"-d or -det: detector file name"<<endl;
    cout<<"-o or -out: output file name"<<endl;
    cout<<"-batch: batch mode"<<endl;
}




