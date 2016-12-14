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

#include <iostream>
#include <fstream>
#include <vector>
#include <string>




#include "TDetector.hh"


using namespace std;

void ParseCommandLine(int argc,char **argv);

/*From the command line*/
string fName,detName;


double timeRes=-1;




int main(int argc,char **argv){
  
  
  
  //Input file
  TFile *fin;
  //detector	
  TDetector *detector;
  
  //Parse the command line, open the input file
  ParseCommandLine(argc,argv);
  
  std::size_t found = fName.find(".root");
  if (found!=std::string::npos){
    
    cout<<"ROOT mode"<<endl;
    fin=new TFile(fName.c_str()); 		
    //Check if we have detector info in the ROOT file. 
    if (fin->GetListOfKeys()->Contains("TDetectorLight")){
      detector=(TDetector*)fin->Get("TDetectorLight");
      cout<<"Detector found:"<<detector->getName()<<endl;
    }
    else{
      cout<<"Detector not found"<<endl;
      exit(1);
    }
  }
  else{
    cout<<"TXT mode"<<endl;
    detector=new TDetector(fName); 
  }
  
  //OWR time resolution
  if (timeRes>0){
    for (int ii=0;ii<6;ii++){
      for (int jj=0;jj<detector->getNdet(ii);jj++){
      if (detector->isDetPresent(ii,jj)) detector->setDetTimeRes(ii,jj,timeRes);
      }
    }
  }
  
  
  //Print detector information  
  
  detector->PrintPixels();
  detector->Print();
  
}








void ParseCommandLine(int argc,char **argv){
  for (int ii=0;ii<argc;ii++){
    if ((strcmp(argv[ii],"-f")==0)||(strcmp(argv[ii],"-fname")==0)){
      fName=string(argv[ii+1]);
    }
    
    
    
    
  }
  
}














