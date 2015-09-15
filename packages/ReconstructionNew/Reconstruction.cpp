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


#include "TAnalysis.hh"
#include "CommonMacros.hh"



using namespace std;


TApplication gui("gui",0,NULL);


int main(int argc,char **argv){
	TH1::AddDirectory(kFALSE);



	//Load Cintex
	LOADLIBS

	TAnalysis ana;
	ana.ParseCommandLine(argc,argv);
	ana.run();
}



