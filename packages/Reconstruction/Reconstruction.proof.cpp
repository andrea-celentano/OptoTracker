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

#include "OpNovicePMTHit.hh"
#include "G4SystemOfUnits.hh"
#include "G4PhysicalConstants.hh"
#include "G4UnitsTable.hh"

#include "TOpNoviceSelectorRaw.hh"
#include "TOpNoviceDetectorLight.hh"
#include "TRecon.hh"

using namespace std;



/*From the command line*/
string fName,detName;
int interactive=0;
int detNameCommandLine=0;
int doProof=0;
int doProofDiag=0;

double timeRes=-1;


//detector. Keep it global for "print" functions
TOpNoviceDetectorLight *detector;

void ParseCommandLine(int argc,char **argv);
void PrintDet();



TApplication gui("gui",0,NULL);

int main(int argc, char **argv){

  
     
	
	//Load Cintex and the shared library
	ROOT::Cintex::Cintex::Enable();
	gSystem->Load("libOpNoviceClassesDict.so");
	gSystem->Load("libGeometryClassesDict.so");
	gSystem->Load("libReconstructionClassesDict.so");
	
	int Nevents;
	TRandom3 rand(0);
	
	
	//Input file and output file
	TFile *fin,*fout;
	//Input chain 
	TChain *ch;
        //Selector
	TOpNoviceSelectorRaw *selectorRaw;
	
	TProof *pf;
		
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
	if (timeRes>=0){
	  for (int ii=0;ii<6;ii++){
	    if (detector->isDetPresent(ii)) detector->setTimeRes(ii,timeRes);
	  }
	}
	
	
	//Print detector information  
	
	detector->printPixels();
	detector->printDet();
	
	//Create the TChain, fill it
	ch=new TChain("raw"); //must have the TTree name I am going to read
	ch->Add(fName.c_str());	
	Nevents=ch->GetEntries(); //1 entry=1 event
	cout<<"There are: "<<Nevents<<" events"<<endl;
	
	
	
     

	
	if (doProof){
	  pf=TProof::Open("");
	  pf->Exec("gSystem->Load(\"libCintex\")");
	  pf->Exec("ROOT::Cintex::Cintex::Enable()");
	  pf->Exec("gSystem->Load(\"/project/Gruppo3/fiber5/celentano/OptoTracker/software/lib/libGeometryClassesDict.so\")");
          pf->Exec("gSystem->Load(\"/project/Gruppo3/fiber5/celentano/OptoTracker/software/lib/libOpNoviceClassesDict.so\")");
	  pf->Exec("gSystem->Load(\"/project/Gruppo3/fiber5/celentano/OptoTracker/software/lib/libReconstructionClassesDict.so\")");
	  //	pf->Load("/auto_data/fiber5/celentano/OptoTracker/sim/OpNovice/build/libOpNoviceClassesDict.so");
	  pf->SetLogLevel(1, TProofDebug::kPacketizer);
	  pf->SetParameter("PROOF_Packetizer", "TPacketizer");  
	  pf->AddInput(detector);
          ch->SetProof();    //Enable proof @TODO: Only if requested by the user via command line
	}
	else{
	//Create the Selector-derived class
	  selectorRaw=new TOpNoviceSelectorRaw();
	  selectorRaw->setDetector(detector);
	  //selectorRaw->setSeed(0);
	}

		
	if (doProof){
	  if (doProofDiag){
		pf->SetProgressDialog(kTRUE);
	  }	
	  else{
		pf->SetProgressDialog(kFALSE);
	  }
	  ch->Process("TOpNoviceSelectorRaw");
	}
	else{
	  ch->Process(selectorRaw);
	}
	cout<<"Process done"<<endl;
	
	if (doProof){
	  pf->Print();
	}
	if (interactive){
	  gui.Run(1);
	}
	
	cout<<"Save"<<endl;
	fout=new TFile((fName+".recon.root").c_str(),"recreate");
	fout->cd();
	if (doProof){
	    pf->GetOutputList()->Write();
	}
	else{
	    selectorRaw->GetOutputList()->Write();
	}
	
	/*Also save the detector used for the analysis*/
	fout->WriteTObject(detector);
	
	gSystem->Exit(0);
	
}






/*


void ReadDetFile(string fname){

  ifstream file(fname.c_str());

  string line; vector < string > lines;
  string word; vector < string > words;
  string keyword;
  std::size_t found;

  double x,y,z;
  int N;
  while (!file.eof()){
    getline(file,line);
    lines.push_back(line);	
  }
  file.close();

  for (int ii=0;ii<lines.size();ii++){
	line=lines[ii];
	words.clear();
	word="";

	for (int jj=0;jj<line.size();jj++){
	  if (!isspace(line[jj])){
	    word += line[jj];
	    if ((jj == (line.size()-1))&&(!word.empty())){
	      words.push_back(word);
	      word = "";
	    }
	  }
	  else if (!word.empty()){
	    words.push_back(word);
	    word = "";
	  }
	}//end line-jj cicle
	//now we have words
	if (words.size() > 0) keyword = words[0];	
	if (keyword.empty()) continue;
	if (keyword[0]=='#') continue;


	keyword.find("/detector/dimensions");
	if (found!=std::string::npos){
	  x=atof(words[1].c_str());
	  y=atof(words[2].c_str());
	  z=atof(words[3].c_str());
	  if (words.size()==5){
	    if (words[4]=="cm"){
		x*=cm;
		y*=cm;
		z*=cm;
	      }
	    else if (words[4]=="mm"){
		x*=mm;
		y*=mm;
		z*=mm;
	    }

	    scintSizeX=x;
	    scintSizeY=y;
	    detector->getScintSizeZ()=z;
	  }	  
	}

	//the Dimensions
	for (int qq=0;qq<6;qq++){
	  x=y=0;
	  N=0;

	  found = keyword.find(Form("/detector/surface%i/PhotoDetectorDimensions",qq+1));
	  if (found!=std::string::npos){
	    x=atof(words[1].c_str());
	    y=atof(words[2].c_str());
	    if (words.size()==5){
	      if (words[4]=="cm"){
		x*=cm;
		y*=cm;
	      }
	      else if (words[4]=="mm"){
		x*=mm;
		y*=mm;
	      }
	      if ((x<=0)||(y<=0)){
		detPresent[qq]=0;
		x=0;
		y=0;
	      }
	      else detPresent[qq]=1;

	      detSizeX[qq]=x;
	      detSizeY[qq]=y;
	    }	    
	  }


	  found = keyword.find(Form("/digitizer/detector%i/NpixelsX",qq+1));
	  if (found!=std::string::npos){
	     N=atoi(words[1].c_str());
	     detNpixelsX[qq]=N;
	  }


	  found = keyword.find(Form("/digitizer/detector%i/NpixelsY",qq+1));
	  if (found!=std::string::npos){
	     N=atoi(words[1].c_str());
	     detNpixelsY[qq]=N;
	  }

	  found = keyword.find(Form("/digitizer/detector%i/TimeResolution",qq+1));
	  if (found!=std::string::npos){
	    x=atof(words[1].c_str());
	    if (words.size()==3){
	      if (words[2]=="ps"){
		x*=picosecond;
	      }
	      else if (words[2]=="ns"){
		x*=ns;
	      }
	      detTimeRes[qq]=x;
	    }
	  }
       	}	
  }

  for (int ii=0;ii<6;ii++){
    if (detPresent[ii]){
      detPixelSizeX[ii]=detSizeX[ii]/detNpixelsX[ii];
      detPixelSizeY[ii]=detSizeY[ii]/detNpixelsY[ii];
    }
  }
}
*/



void ParseCommandLine(int argc,char **argv){
	for (int ii=0;ii<argc;ii++){
		if ((strcmp(argv[ii],"-f")==0)||(strcmp(argv[ii],"-fname")==0)){
			fName=string(argv[ii+1]);
		}
		
		else if ((strcmp(argv[ii],"-det")==0)||(strcmp(argv[ii],"-detname")==0)){
			detName=string(argv[ii+1]);
		}
		
		else if ((strcmp(argv[ii],"-timeRes")==0)){ //owr the time resolution found in the detector object within the ROOT file
			  timeRes=atof(argv[ii+1]);
		}
		else if ((strcmp(argv[ii],"-int")==0)||(strcmp(argv[ii],"-interactive")==0)){
			interactive=1;
		}
		else if ((strcmp(argv[ii],"-proof")==0)||(strcmp(argv[ii],"-Proof")==0)){
			doProof=1;
		}
		else if ((strcmp(argv[ii],"-proofDiag")==0)){
			doProofDiag=1;
		}		
		
	}
	
}































/*This is a very important method, that, for each detector pixel, associates it to the ABSOLUTE position in the detector.*/
/*Note that, within a detector face, x and y axis are oriented in a given way, not equal to the absolute xyz coordinate system*/
/*Ipixel=Ix+Iy*Nx;*/
/*
void ConfigPixels(){



  double x,y,z,xs,ys,zs;
  int ipixel;
  for (int ii=0;ii<6;ii++){
    if (detPresent[ii]==0) continue;
    for (int iy=0;iy<detNpixelsY[ii];iy++){
        for (int ix=0;ix<detNpixelsX[ii];ix++){
	  ipixel=ix+detNpixelsY[ii]*iy;	  

	  switch (ii){
	  case 0: //faccia 1:yx, +z
	    z=+scintSizeZ/2;
	    x=-(-detSizeX[ii]/2+ix*detPixelSizeX[ii]+detPixelSizeX[ii]/2);
	    y=(-detSizeY[ii]/2+iy*detPixelSizeY[ii]+detPixelSizeY[ii]/2); 
	    xs=x*scintSizeX/detSizeX[ii];
	    ys=y*scintSizeY/detSizeY[ii];
	    zs=z;
	    break;
	  case 2: //faccia 3: yx, -z
	    z=-scintSizeZ/2;
	    x=(-detSizeX[ii]/2+ix*detPixelSizeX[ii]+detPixelSizeX[ii]/2);
	    y=(-detSizeY[ii]/2+iy*detPixelSizeY[ii]+detPixelSizeY[ii]/2);
	    xs=x*scintSizeX/detSizeX[ii];
	    ys=y*scintSizeY/detSizeY[ii];
	    zs=z;
	    break;
	  case 1: //faccia 2: yz, +x
	    x=+scintSizeX/2;
	    y=(-detSizeY[ii]/2+iy*detPixelSizeY[ii]+detPixelSizeY[ii]/2);
	    z=(-detSizeX[ii]/2+ix*detPixelSizeX[ii]+detPixelSizeX[ii]/2);
	    xs=x;
	    ys=y*scintSizeY/detSizeY[ii];
	    zs=z*scintSizeZ/detSizeX[ii];
	    break;
	  case 3: //faccia 4: yz, -x
	    x=-scintSizeX/2;
	    y=(-detSizeY[ii]/2+iy*detPixelSizeY[ii]+detPixelSizeY[ii]/2);
	    z=-(-detSizeX[ii]/2+ix*detPixelSizeY[ii]+detPixelSizeX[ii]/2);
	    xs=x;
	    ys=y*scintSizeY/detSizeY[ii];
	    zs=z*scintSizeZ/detSizeX[ii];
	    break;
	  case 4: //faccia 5, xz, +y
	    y=scintSizeY/2;
	    x=(-detSizeX[ii]/2+ix*detPixelSizeX[ii]+detPixelSizeX[ii]/2);
	    z=(-detSizeY[ii]/2+iy*detPixelSizeY[ii]+detPixelSizeY[ii]/2);
	    ys=y;
	    xs=x*scintSizeX/detSizeX[ii];
	    zs=z*scintSizeZ/detSizeY[ii];
	    break;
	  case 5: //faccia 6, xz, -y
	    y=-scintSizeY/2;
	    x=(-detSizeX[ii]/2+ix*detPixelSizeX[ii]+detPixelSizeX[ii]/2);
	    z=-(-detSizeY[ii]/2+iy*detPixelSizeY[ii]+detPixelSizeY[ii]/2);
	    ys=y;
	    xs=x*scintSizeX/detSizeX[ii];
	    zs=z*scintSizeZ/detSizeY[ii];
	    break;
	  } 	  
	  posPixel[ii].push_back(new TVector3(x,y,z));
	  posPixelScaled[ii].push_back(new TVector3(xs,ys,zs));
	}    
    }
  }
}


*/
