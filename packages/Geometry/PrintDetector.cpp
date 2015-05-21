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


#include <iostream>
#include <fstream>
#include <vector>
#include <string>




#include "TOpNoviceDetectorLight.hh"


using namespace std;

void ParseCommandLine(int argc,char **argv);

/*From the command line*/
string fName,detName;


double timeRes=-1;


//detector. Keep it global for "print" functions
TOpNoviceDetectorLight *detector;

int main(int argc,char **argv){
	//Load Cintex and the shared library
	ROOT::Cintex::Cintex::Enable();
	gSystem->Load("libGeometryClassesDict.so");
	
	

	
	//Input file
	TFile *fin;

        
        //Parse the command line, open the input file
	ParseCommandLine(argc,argv);
	fin=new TFile(fName.c_str()); 
	//Check if we have detector info in the ROOT file. 
	if (fin->GetListOfKeys()->Contains("TOpNoviceDetectorLight")){
		detector=(TOpNoviceDetectorLight*)fin->Get("TOpNoviceDetectorLight");
		cout<<"Detector found:"<<detector->getName()<<endl;
	}
	else{
		cout<<"Detector not found"<<endl;
		exit(1);
	}
	
	//OWR time resolution
	if (timeRes>0){
	  for (int ii=0;ii<6;ii++){
	    if (detector->isDetPresent(ii)) detector->setTimeRes(ii,timeRes);
	  }
	}
	
	
	//Print detector information  
	
	detector->printPixels();
	detector->printDet();
	
	}
	
	
	
	
	
	
	

void ParseCommandLine(int argc,char **argv){
	for (int ii=0;ii<argc;ii++){
		if ((strcmp(argv[ii],"-f")==0)||(strcmp(argv[ii],"-fname")==0)){
			fName=string(argv[ii+1]);
		}
		
	
		
		
	}
	
}










	
	
	
	
