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
#include "TVector3.h"

#include "MarocSetupHandler.hh"
#include "TOpNoviceDetectorLight.hh"
#include "TRecon.hh"

using namespace std;

#define N0 2048
#define Ntot 64
#define Nfiles 10
#define Nfiles1


/*From the command line*/
string fSetupName;
string fOutNameRoot,fOutNamePS,fOutName;
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
  
  
  if (fSetupName.length()==0){
    cerr<<"Missing Setup file name"<<endl;
    return -1;
  }
  if (fOutName.length()==0){
    cerr<<"Missing OUT file name, auto-selecting"<<endl;
    fOutName="MarocComparison.out";
  }
  fOutNameRoot=fOutName+".root";
  fOutNamePS=fOutName+".ps";
  
  TTree *t;
  TFile *f;	
  TFile *fOut=new TFile(fOutNameRoot.c_str(),"recreate");
  
  Float_t ADC[4096];
  Bool_t hit[4096];
 
  double ped1[Ntot],ped2[Ntot];
  double mean1[Ntot],mean2[Ntot];
  
  string dataFolder="/work/apcx4/celentano/OptoTracker/hardware/Maroc/data/parsed/";
  
  int id;
  int ix,iy,iH8500,iMarocChannel,iMarocCard,iRealDet,iReconDet,iReconFace,iReconPixel;
  int iPad;
  double Q,gain;
  int N;
  
  
  MarocSetupHandler *m_setup=new MarocSetupHandler(fSetupName);
  /*Set the first gain, i.e. the Hamamatsu one*/
  double PmtDA0359[MarocSetupHandler::nH8500Pixels]={76,79,86,96,100,95,88,83,76,71,80,89,95,89,87,82,75,68,82,87,92,91,81,77,71,64,79,83,88,88,75,74,69,63,74,79,78,83,73,70,68,61,71,75,76,73,68,65,63,60,65,69,66,62,59,60,61,64,66,70,65,60,56,52};
  double PmtDA0361[MarocSetupHandler::nH8500Pixels]={56,71,76,81,89,87,78,82,61,66,72,77,82,78,76,85,60,64,72,74,75,81,80,88,61,65,70,72,73,82,82,93,63,66,71,72,73,85,86,99,68,68,77,75,82,91,89,100,73,75,83,88,95,97,92,99,60,73,80,85,92,99,90,71};
  
  for (int ii=0;ii<MarocSetupHandler::nH8500Pixels;ii++){
    iReconPixel=m_setup->getPixelReconId(32,ii);
    iMarocChannel=m_setup->getMarocChannelFromH8500(ii);
    iReconFace=m_setup->getReconstructionDetectorFace(32);
    iReconDet=m_setup->getReconstructionDetectorID(32);
    m_setup->setPixelGain(iReconFace,iReconDet,iReconPixel,1,PmtDA0359[ii]/100.);
    
    if (iMarocChannel<=31)			m_setup->setPixelGain(iReconFace,iReconDet,iReconPixel,2,.5);
    else if (iMarocChannel<=47)			m_setup->setPixelGain(iReconFace,iReconDet,iReconPixel,2,.375);
    else if (iMarocChannel<=63)			m_setup->setPixelGain(iReconFace,iReconDet,iReconPixel,2,.25);
    
    
    
    iReconPixel=m_setup->getPixelReconId(33,ii);
    iMarocChannel=m_setup->getMarocChannelFromH8500(ii);
    iReconFace=m_setup->getReconstructionDetectorFace(33);
    iReconDet=m_setup->getReconstructionDetectorID(33);
    m_setup->setPixelGain(iReconFace,iReconDet,iReconPixel,1,PmtDA0361[ii]/100.);
    
    if (iMarocChannel<=31)			m_setup->setPixelGain(iReconFace,iReconDet,iReconPixel,2,.5);
    else if (iMarocChannel<=47)		m_setup->setPixelGain(iReconFace,iReconDet,iReconPixel,2,.375);
    else if (iMarocChannel<=63)		m_setup->setPixelGain(iReconFace,iReconDet,iReconPixel,2,.25);
  }
  
  
  m_setup->Print(1);
  
  
  
  /*Define here the histograms*/
  /*These are indexed by the real pixel id*/
  TH1D *hCharge1[Ntot];
  TH1D *hCharge2[Ntot];
  TH1D *hChargeCorr1[Ntot];
  TH1D *hChargeCorr2[Ntot];
  
  TH1D *hPed1[Ntot];
  TH1D *hPed2[Ntot];
  
  
  /*
  TH2D *hGrid=new TH2D("hGrid","hGrid",16,-8.5,7.5,8,-0.5,7.5);
  TH2D *hGainMap=new TH2D("hGainMap","hGainMap",16,-8.5,7.5,8,-0.5,7.5);
  TH2D *hMean1=new TH2D("hMean1","hMean1",16,-8.5,7.5,8,-0.5,7.5);
  TH2D *hMean2=new TH2D("hMean2","hMean2",16,-8.5,7.5,8,-0.5,7.5);
  TH2D *hMeanDiff=new TH2D("hMeanDiff","hMeanDiff",16,-8.5,7.5,8,-0.5,7.5);
  */
  
  TH2D *hMean1=new TH2D("hMean1","hMean1",8,-0.5,7.5,8,-0.5,7.5);
  TH2D *hMean2=new TH2D("hMean2","hMean2",8,-0.5,7.5,8,-0.5,7.5);
  TH2D *hMeanRatio;
  TH1D *hMeanRatio1D=new TH1D("hMeanRatio1D","hMeanRatio1D",64,-0.5,63.5);
  
   for (int ii=0;ii<Ntot;ii++){
	iH8500=m_setup->getH8500IdFromGlobal(ii+N0);
	hPed1[ii]=new TH1D(Form("hPed1_%i",ii),Form("hPed1%i:H8500_%i",ii,iH8500),4096,-0.5,4095.5);	 
	hPed2[ii]=new TH1D(Form("hPed2_%i",ii),Form("hPed2%i:H8500_%i",ii,iH8500),4096,-0.5,4095.5);	 
	
	hCharge1[ii]=new TH1D(Form("hCharge1_%i",ii),Form("hCharge1%i:H8500_%i",ii,iH8500),4096,-0.5,4095.5);	 
	hCharge2[ii]=new TH1D(Form("hCharge2_%i",ii),Form("hCharge2%i:H8500_%i",ii,iH8500),4096,-0.5,4095.5);	 
	hChargeCorr1[ii]=new TH1D(Form("hChargeCorr1_%i",ii),Form("hChargeCorr1%i:H8500_%i",ii,iH8500),5000,-1000.5,3999.5);	 
	hChargeCorr2[ii]=new TH1D(Form("hChargeCorr2_%i",ii),Form("hChargeCorr2%i:H8500_%i",ii,iH8500),5000,-1000.5,3999.5);	 
  }
  
  /*Process*/
  
  /*Pedestal1*/
  f=new TFile((dataFolder+"comparison2_00001.root").c_str());
  t=(TTree*)f->Get("fTdata");
  t->SetBranchAddress("ADC",ADC);
  N=t->GetEntries(); 
  for (int ii=0;ii<N;ii++){
      t->GetEntry(ii);
      for (int jj=0;jj<Ntot;jj++){
	id=jj+N0;
	Q=ADC[id];
	
	hPed1[jj]->Fill(Q);     
    }
  }
  /*Compute pedestal*/
  for (int jj=0;jj<Ntot;jj++){
	ped1[jj]=hPed1[jj]->GetMean();     
  }
  
  /*Data1*/
  f=new TFile((dataFolder+"comparison2_00002.root").c_str());
  t=(TTree*)f->Get("fTdata");
  t->SetBranchAddress("ADC",ADC);
  N=t->GetEntries(); 
  for (int ii=0;ii<N;ii++){
      t->GetEntry(ii);
      for (int jj=0;jj<Ntot;jj++){
	id=jj+N0;
	Q=ADC[id];	
	hCharge1[jj]->Fill(Q);     
	hChargeCorr1[jj]->Fill(Q-ped1[jj]);
      }
  }
  
  
  /*Pedestal2*/
  f=new TFile((dataFolder+"comparison2_00003.root").c_str());
  t=(TTree*)f->Get("fTdata");
  t->SetBranchAddress("ADC",ADC);
  N=t->GetEntries(); 
  for (int ii=0;ii<N;ii++){
      t->GetEntry(ii);
      for (int jj=0;jj<Ntot;jj++){
	id=jj+N0+Ntot; //critical +Ntot here
	Q=ADC[id];
	
	hPed2[jj]->Fill(Q);     
    }
  }
  
   /*Compute pedestal*/
  for (int jj=0;jj<Ntot;jj++){
	ped2[jj]=hPed2[jj]->GetMean();     
  }
  
  
  /*Data1*/
  f=new TFile((dataFolder+"comparison2_00004.root").c_str());
  t=(TTree*)f->Get("fTdata");
  t->SetBranchAddress("ADC",ADC);
  N=t->GetEntries(); 
  for (int ii=0;ii<N;ii++){
      t->GetEntry(ii);
      for (int jj=0;jj<Ntot;jj++){
	id=jj+N0+Ntot;//critical +Ntot here
	Q=ADC[id];	
	hCharge2[jj]->Fill(Q);     
	hChargeCorr2[jj]->Fill(Q-ped2[jj]);
      }
  }
  
  
  
  /*Get means*/  
  int iGlobal;
  for (int jj=0;jj<Ntot;jj++){
   iGlobal=jj+N0;
   iRealDet=m_setup->getMarocCard(iGlobal);
   iH8500=m_setup->getH8500IdFromGlobal(iGlobal);
   iMarocChannel=m_setup->getMarocChannelFromGlobal(iGlobal);

   iReconDet=m_setup->getReconstructionDetectorID(iRealDet);
    iReconFace=m_setup->getReconstructionDetectorFace(iRealDet);
    iReconPixel=m_setup->getPixelReconId(iGlobal);
    mean1[jj]=hChargeCorr1[jj]->GetMean();
    mean2[jj]=hChargeCorr2[jj]->GetMean();
    
    ix=iH8500%8;
    iy=7-iH8500/8;
   
    hMean1->Fill(ix,iy,mean1[jj]);
    hMean2->Fill(ix,iy,mean2[jj]);
    
    hMeanRatio1D->Fill(iH8500,mean1[jj]/mean2[jj]);
  }  
  hMeanRatio=(TH2D*)hMean1->Clone();hMeanRatio->SetName("hMeanRation");hMeanRatio->SetTitle("hMeanRatio");
  hMeanRatio->Divide(hMean2);
  
  
  
  /*Plots*/
  TCanvas **c=new TCanvas*[Ntot];
  
  
  for (int iGlobal=N0;iGlobal<(Ntot+N0);iGlobal++){
    iRealDet=m_setup->getMarocCard(iGlobal);
    iH8500=m_setup->getH8500IdFromGlobal(iGlobal);
    iMarocChannel=m_setup->getMarocChannelFromGlobal(iGlobal);
    
    iReconDet=m_setup->getReconstructionDetectorID(iRealDet);
    iReconFace=m_setup->getReconstructionDetectorFace(iRealDet);
    iReconPixel=m_setup->getPixelReconId(iGlobal);
    
    
    
    c[iGlobal-N0]=new TCanvas(Form("c%i",(iGlobal-N0)),Form("c:H8500_%i",iH8500));
    c[iGlobal-N0]->Divide(2,2);
    c[iGlobal-N0]->cd(1)->SetLogy();
    hPed1[iGlobal-N0]->Draw();
    hPed2[iGlobal-N0]->SetLineColor(2);hPed2[iGlobal-N0]->Draw("SAME");
 
    
    c[iGlobal-N0]->cd(2)->SetLogy();
    hCharge1[iGlobal-N0]->Draw();
    hCharge2[iGlobal-N0]->SetLineColor(2);hCharge2[iGlobal-N0]->Draw("SAME");
    
    c[iGlobal-N0]->cd(3)->SetLogy();
    hChargeCorr1[iGlobal-N0]->Draw();
    hChargeCorr2[iGlobal-N0]->SetLineColor(2);hChargeCorr2[iGlobal-N0]->Draw("SAME");
    
    if ((iGlobal-N0)==0) c[iGlobal-N0]->Print((fOutNamePS+"(").c_str());
    else  c[iGlobal-N0]->Print(fOutNamePS.c_str());
    fOut->cd();
    c[iGlobal-N0]->Write();
  }
  
  TLine *l=new TLine(-0.5,-0.5,-0.5,7.5);l->SetLineWidth(2);l->SetLineColor(2);
  
  
  
  TCanvas *ca=new TCanvas("ca","ca");
  ca->Divide(2,2);
  ca->cd(1);hMean1->Draw("colz");
  ca->cd(2);hMean2->Draw("colz");
  ca->cd(3);hMeanRatio->Draw("colz");
  ca->cd(4);hMeanRatio1D->Draw();
  
  ca->Print(fOutNamePS.c_str());
  fOut->cd();
  ca->Write();
  
  
  
  
  
  
  if (fDoBatch==0){
    gui.Run(1);
  }
  
  
  
  
  cout<<"Done"<<endl;
}



void ParseCommandLine(int argc,char **argv){
  for (int ii=0;ii<argc;ii++){
    if ((strcmp(argv[ii],"-o")==0)||(strcmp(argv[ii],"-out")==0)){
      fOutName=string(argv[ii+1]);
    }
    else if ((strcmp(argv[ii],"-ss")==0)||(strcmp(argv[ii],"-setup")==0)){
      fSetupName=string(argv[ii+1]);
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
  cout<<"-ss or -setup: setup file name"<<endl;
  cout<<"-o or -out: output file name"<<endl;
  cout<<"-batch: batch mode"<<endl;
}




