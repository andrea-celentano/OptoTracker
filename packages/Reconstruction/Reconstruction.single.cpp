#include "TFile.h"
#include "TTree.h"
#include "TSystem.h"

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

#include "OpNoviceDetectorHit.hh"
#include "G4SystemOfUnits.hh"
#include "G4PhysicalConstants.hh"
#include "G4UnitsTable.hh"

#include "TOpNoviceDetectorLight.hh"
#include "TRecon.hh"

using namespace std;



/*From the command line*/
string fName,detName;
int interactive=0;
int detNameCommandLine=0;


TOpNoviceDetectorLight *detector;

void ParseCommandLine(int argc,char **argv);
//void ConfigureDetector(TOpNoviceDetectorLight *detector);
//void ReadDetFile(string fname);
void PrintDet();
//void ConfigPixels();
TVector3 COG(int **q);


TApplication gui("gui",0,NULL);

int main(int argc, char **argv){
	ROOT::Cintex::Cintex::Enable();


	gSystem->Load("libOpNoviceClassesDict.so");


	TRandom3 rand(0);

	int Nevents,Nhit,Nphe,iPMT,pxid,pyid,pid,Ntot;
	int Nx,Ny;
	TVector3 r,rScaled,cogNew,rReconIN,rReconOUT,rRecon;
	double xp,yp,t,x,y,z;
	int **q; //pixels charge.
	double **tFirst;
	double qtot;

	TFile *fin,*fout;
	TTree *tree;

	vector <OpNoviceDetectorHit*> *PMTHit=NULL;
	OpNoviceDetectorHit* PMT = NULL;
	detector = NULL;

	TRecon *recon = NULL;

	//Histograms
	TH2D *hPixel0[6];
	TH1D *hX,*hY,*hZ,*hX_1,*hY_1,*hZ_1,*hX_2,*hY_2,*hZ_2;
	TH2D *hXY,*hXZ,*hYZ,*hXY_1,*hXZ_1,*hYZ_1,*hXY_2,*hXZ_2,*hYZ_2;

	TH1D *hTheta,*hPhi;
	vector < TH1D* > hCharge[6];
	vector < TH1D* > hTime[6];
	vector < TH2D* > hTimeVsCharge[6];

	//Start
	ParseCommandLine(argc,argv);
	fin=new TFile(fName.c_str());
	//Check if we have detector info in the ROOT file.
	if (fin->GetListOfKeys()->Contains("TOpNoviceDetectorLight")){
		detector=(TOpNoviceDetectorLight*)fin->Get("TOpNoviceDetectorLight");
		cout<<"Detector found:"<<detector->getName()<<endl;
		//  ConfigureDetector(detector);
	}
	else{
		cout<<"Detector not found"<<endl;
		exit(1);
	}


	//ReadDetFile(detName.c_str());
	detector->printDet();
	detector->printPixels();



	// ConfigPixels();

	hX=new TH1D("hX","hX;x",200,-detector->getScintSizeX()/2-1,detector->getScintSizeX()/2+1);
	hY=new TH1D("hY","hY;y",200,-detector->getScintSizeY()/2-1,detector->getScintSizeY()/2+1);
	hZ=new TH1D("hZ","hZ;z",200,-detector->getScintSizeZ()/2-1,detector->getScintSizeZ()/2+1);
	hXY=new TH2D("hXY","hXY;x;y",100,-detector->getScintSizeX()/2-1,detector->getScintSizeX()/2+1,100,-detector->getScintSizeY()/2-1,detector->getScintSizeY()/2+1);
	hXZ=new TH2D("hXZ","hXZ;x;z",100,-detector->getScintSizeX()/2-1,detector->getScintSizeX()/2+1,100,-detector->getScintSizeZ()/2-1,detector->getScintSizeZ()/2+1);
	hYZ=new TH2D("hYZ","hYZ;y;z",100,-detector->getScintSizeY()/2-1,detector->getScintSizeY()/2+1,100,-detector->getScintSizeZ()/2-1,detector->getScintSizeZ()/2+1);


	hX_1=new TH1D("hX_1","hX;x",200,-detector->getScintSizeX()/2-1,detector->getScintSizeX()/2+1);
	hY_1=new TH1D("hY_1","hY;y",200,-detector->getScintSizeY()/2-1,detector->getScintSizeY()/2+1);
	hZ_1=new TH1D("hZ_1","hZ;z",200,-detector->getScintSizeZ()/2-1,detector->getScintSizeZ()/2+1);
	hXY_1=new TH2D("hXY_1","hXY;x;y",100,-detector->getScintSizeX()/2-1,detector->getScintSizeX()/2+1,100,-detector->getScintSizeY()/2-1,detector->getScintSizeY()/2+1);
	hXZ_1=new TH2D("hXZ_1","hXZ;x;z",100,-detector->getScintSizeX()/2-1,detector->getScintSizeX()/2+1,100,-detector->getScintSizeZ()/2-1,detector->getScintSizeZ()/2+1);
	hYZ_1=new TH2D("hYZ_1","hYZ;y;z",100,-detector->getScintSizeY()/2-1,detector->getScintSizeY()/2+1,100,-detector->getScintSizeZ()/2-1,detector->getScintSizeZ()/2+1);

	hX_2=new TH1D("hX_2","hX;x",200,-detector->getScintSizeX()/2-1,detector->getScintSizeX()/2+1);
	hY_2=new TH1D("hY_2","hY;y",200,-detector->getScintSizeY()/2-1,detector->getScintSizeY()/2+1);
	hZ_2=new TH1D("hZ_2","hZ;z",200,-detector->getScintSizeZ()/2-1,detector->getScintSizeZ()/2+1);
	hXY_2=new TH2D("hXY_2","hXY;x;y",100,-detector->getScintSizeX()/2-1,detector->getScintSizeX()/2+1,100,-detector->getScintSizeY()/2-1,detector->getScintSizeY()/2+1);
	hXZ_2=new TH2D("hXZ_2","hXZ;x;z",100,-detector->getScintSizeX()/2-1,detector->getScintSizeX()/2+1,100,-detector->getScintSizeZ()/2-1,detector->getScintSizeZ()/2+1);
	hYZ_2=new TH2D("hYZ_2","hYZ;y;z",100,-detector->getScintSizeY()/2-1,detector->getScintSizeY()/2+1,100,-detector->getScintSizeZ()/2-1,detector->getScintSizeZ()/2+1);

	hTheta=new TH1D("hTheta","hTheta",100,-90,90);
	hPhi=new TH1D("hPhi","hPhi",100,-180,180);

	string hPixel0Title[6];
	hPixel0Title[0]="hPixel0_0;-x;y";
	hPixel0Title[1]="hPixel0_0;+z;+y";
	hPixel0Title[2]="hPixel0_0;+x;+y";
	hPixel0Title[3]="hPixel0_0;-z;+y";
	hPixel0Title[4]="hPixel0_0;+x;+z";
	hPixel0Title[5]="hPixel0_0;+x;-z";


	for (int ii=0;ii<6;ii++){
		if (detector->isDetPresent(ii)){
			hPixel0[ii]=new TH2D(Form("hPixel0_%i",ii+1),Form("hPixel0_%i",ii+1),detector->getNPixelsX(ii),-detector->getDetSizeX(ii)/2,detector->getDetSizeX(ii)/2,detector->getNPixelsY(ii),-detector->getDetSizeY(ii)/2,detector->getDetSizeY(ii)/2);
			hPixel0[ii]->SetTitle(hPixel0Title[ii].c_str());
			Nx=detector->getNPixelsX(ii);
			Ny=detector->getNPixelsY(ii);
			for (int id=0;id<Ny*Ny;id++){
				hCharge[ii].push_back(new TH1D(Form("hCharge_%i_%i",ii,id),Form("hCharge_%i_%i",ii,id),100,-0.5,99.5));
				hTime[ii].push_back(new TH1D(Form("hTime_%i_%i",ii,id),Form("hTime_%i_%i",ii,id),400,-0.5,19.5));
				hTimeVsCharge[ii].push_back(new TH2D(Form("hTimeVsCharge_%i_%i",ii,id),Form("hTimeVsCharge_%i_%i",ii,id),100,-0.5,99.5,400,-0.5,19.5));
			}
		}
	}




	fin=new TFile(fName.c_str());
	tree=(TTree*)fin->Get("raw");

	tree->SetBranchAddress("raw",&PMTHit);


	recon=new TRecon(detector);



	Nevents=tree->GetEntries(); //1 entry=1 event

	q=new int*[6];
	tFirst=new double*[6];
	for (int ii=0;ii<6;ii++){
		q[ii]=new int[detector->getNPixels(ii)]();
		tFirst[ii]=new double[detector->getNPixels(ii)]();

	}





	cout<<"There are: "<<Nevents<<" events"<<endl;

	fout=new TFile((fName+".recon.root").c_str(),"recreate");
	for (int ievent=0;ievent<Nevents;ievent++){


		/*A new event. Init to 0*/
		x=y=z=0;
		qtot=0;

		for (int ii=0;ii<6;ii++){
			for (int ipid=0;ipid<detector->getNPixels(ii);ipid++){
				q[ii][ipid]=0;
				tFirst[ii][ipid]=9999;
			}
		}
		r.SetXYZ(0.,0.,0.);
		rScaled.SetXYZ(0.,0.,0.);

		tree->GetEntry(ievent);
		Nhit=PMTHit->size();

		for (int ihit=0;ihit<Nhit;ihit++){



			iPMT=PMTHit->at(ihit)->GetPMTNumber();
			if (detector->isDetPresent(iPMT)==0){
				cout<<"Error! The detector on face "<<iPMT+1<<"is not supposed to be here but we have a hit"<<endl;
				exit(1);
			}

			Nphe=PMTHit->at(ihit)->GetPheCount();


			for (int iphe=0;iphe<Nphe;iphe++){


				xp=PMTHit->at(ihit)->GetX(iphe);
				yp=PMTHit->at(ihit)->GetY(iphe);
				t=PMTHit->at(ihit)->GetT(iphe);
				pid=detector->getPixelID(iPMT,xp,yp);

				/**Time resolution effects*/
				if (detector->getTimeRes(iPMT)>0) t=t+rand.Gaus(0,detector->getTimeRes(iPMT));
				if (t<tFirst[iPMT][pid]) tFirst[iPMT][pid]=t;


				r+=detector->getPosPixel(iPMT,pid);
				rScaled+=detector->getPosPixelScaled(iPMT,pid);

				qtot++;
				q[iPMT][pid]++;


				hPixel0[iPMT]->Fill(xp,yp);

			}///end loop on phe
		}//end loop on hits (1 hit == 1 face)


		/*
     hX->Fill(r.X());
     hY->Fill(r.Y());
     hZ->Fill(r.Z());
     hXY->Fill(r.X(),r.Y());
     hXZ->Fill(r.X(),r.Z());
     hYZ->Fill(r.Y(),r.Z());
		 */


		cogNew=COG(q);



		hX->Fill(cogNew.X());
		hY->Fill(cogNew.Y());
		hZ->Fill(cogNew.Z());
		hXY->Fill(cogNew.X(),cogNew.Y());
		hXZ->Fill(cogNew.X(),cogNew.Z());
		hYZ->Fill(cogNew.Y(),cogNew.Z());
		/*Fill other histograms*/
		for (int ii=0;ii<6;ii++){
			if (detector->isDetPresent(ii)==0) continue;
			for (int id=0;id<detector->getNPixels(ii);id++){
				hCharge[ii].at(id)->Fill(q[ii][id]);
				hTime[ii].at(id)->Fill(tFirst[ii][id]);
				hTimeVsCharge[ii].at(id)->Fill(q[ii][id],tFirst[ii][id]);
			}
		}
		/*Try the likelihood*/
		cout<<endl<<endl<<"EVENT: "<<ievent<<endl<<endl<<endl;
		for (int ii=0;ii<6;ii++){
			if (detector->isDetPresent(ii)==0) continue;
			recon->setNaddress(ii,q[ii]);
			recon->setTaddress(ii,tFirst[ii]);
		}

		Ntot=qtot/0.2; //since par[8]=sqrt(Ntot)
		fitObject_t fitObject=k_track;
		fitLikelihoodMode_t fitMode=k_both;
		recon->getMinimizer()->Clear();
		recon->initParameters();
		recon->setFitObject(fitObject);
		recon->setFitLikelihoodMode(fitMode);







		recon->getMinimizer()->SetPrecision(1E-13);
		//recon->getMinimizer()->SetVariable(0,"X0",COG.X(),.1,-detector->getScintSizeX()*.5,detector->getScintSizeX()*.5);//recon->getMinimizer()->FixVariable(0);
		recon->getMinimizer()->SetLimitedVariable(1,"Y0",detector->getScintSizeY()*.5,.1,-detector->getScintSizeY()*.5,detector->getScintSizeY()*.5);   recon->getMinimizer()->FixVariable(1);
		//recon->getMinimizer()->SetVariable(2,"Z0",COG.Z(),.1,-detector->getScintSizeZ()*.5,detector->getScintSizeZ()*.5);//recon->getMinimizer()->FixVariable(2);

		//recon->getMinimizer()->SetVariable(3,"X1",0.,.1,-detector->getScintSizeX()*.5,detector->getScintSizeX()*.5);//recon->getMinimizer()->FixVariable(0);
		recon->getMinimizer()->SetLimitedVariable(4,"Y1",-detector->getScintSizeY()*.5,.1,-detector->getScintSizeY()*.5,detector->getScintSizeY()*.5); recon->getMinimizer()->FixVariable(4);
		//recon->getMinimizer()->SetVariable(5,"Z1",0.,.1,-detector->getScintSizeZ()*.5,detector->getScintSizeZ()*.5);//recon->getMinimizer()->FixVariable(2);

		//recon->getMinimizer()->SetLimitedVariable(6,"b",0.99999,0.1,0.,1.);
		recon->getMinimizer()->FixVariable(6);
		//recon->getMinimizer()->SetVariable(7,"t",0.,0.1,0.,1.);
		recon->getMinimizer()->FixVariable(7);
		recon->getMinimizer()->SetVariable(8,"N",sqrt(Ntot),1);//recon->getMinimizer()->FixVariable(8);
		//recon->getMinimizer()->SetVariable(9,"tau",1.5,0.1,0,0);
		recon->getMinimizer()->FixVariable(9);

		recon->getMinimizer()->SetStrategy(2);
		recon->setPrintLevel(1);


		recon->doFit();
		recon->getMinimizer()->PrintResults();


		if ((recon->getFitObject()==k_track)&&(recon->getMinimizer()->X()[6]*detector->getRindex()<1)){
			cout<<"In this fit, nb<1: do again point-like"<<endl;
			recon->getMinimizer()->Clear();
			recon->initParameters();
			fitObject=k_point;
			recon->setFitObject(fitObject);
			recon->setFitLikelihoodMode(fitMode);

			recon->getMinimizer()->SetLimitedVariable(0,"X0",cogNew.X(),.1,-detector->getScintSizeX()*.5,detector->getScintSizeX()*.5);
			recon->getMinimizer()->SetLimitedVariable(1,"Y0",cogNew.Y(),.1,-detector->getScintSizeY()*.5,detector->getScintSizeY()*.5);
			recon->getMinimizer()->SetLimitedVariable(2,"Z0",cogNew.Z(),.1,-detector->getScintSizeZ()*.5,detector->getScintSizeZ()*.5);
			recon->getMinimizer()->SetVariable(9,"tau",1.5,0.1);recon->getMinimizer()->FixVariable(9);


			recon->doFit();
			recon->getMinimizer()->PrintResults();
		}

		rReconIN.SetXYZ(recon->getMinimizer()->X()[0],recon->getMinimizer()->X()[1],recon->getMinimizer()->X()[2]);
		rReconOUT.SetXYZ(recon->getMinimizer()->X()[3],recon->getMinimizer()->X()[4],recon->getMinimizer()->X()[5]);



		rRecon=rReconOUT-rReconIN; //full trajectory

		Ntot=recon->getMinimizer()->X()[4];

		hX_1->Fill( rReconIN.X());
		hY_1->Fill( rReconIN.Y());
		hZ_1->Fill( rReconIN.Z());
		hXY_1->Fill( rReconIN.X(), rReconIN.Y());
		hXZ_1->Fill( rReconIN.X(), rReconIN.Z());
		hYZ_1->Fill( rReconIN.Y(), rReconIN.Z());

		hX_2->Fill( rReconOUT.X());
		hY_2->Fill( rReconOUT.Y());
		hZ_2->Fill( rReconOUT.Z());
		hXY_2->Fill( rReconOUT.X(), rReconOUT.Y());
		hXZ_2->Fill( rReconOUT.X(), rReconOUT.Z());
		hYZ_2->Fill( rReconOUT.Y(), rReconOUT.Z());







































		hTheta->Fill(rRecon.Theta()*TMath::RadToDeg());
		hPhi->Fill(rRecon.Phi()*TMath::RadToDeg());

	}//end loop on events






	TCanvas *c1=new TCanvas("c1","c1");
	c1->Divide(4,3);
	for (int ii=0;ii<4;ii++){if (detector->isDetPresent(ii)){c1->cd(ii+5);hPixel0[ii]->Draw("colz");}}
	if (detector->isDetPresent(4)){c1->cd(2);hPixel0[4]->Draw("colz");}
	if (detector->isDetPresent(5)){c1->cd(10);hPixel0[5]->Draw("colz");}


	TCanvas *c2=new TCanvas("c2","c2");
	c2->Divide(3,3);
	c2->cd(4);hXY->Draw("colz");c2->cd(1);hX->Draw();c2->cd(7);hY->Draw();
	c2->cd(5);hYZ->Draw("colz");c2->cd(2);hY->Draw();c2->cd(8);hZ->Draw();
	c2->cd(6);hXZ->Draw("colz");c2->cd(3);hZ->Draw();c2->cd(9);hX->Draw();


	TCanvas *c2s=new TCanvas("c2a","c2_likelihoodReconstructionIN");
	c2s->Divide(3,3);
	c2s->cd(4);hXY_1->Draw("colz");c2s->cd(1);hX_1->Draw();c2s->cd(7);hY_1->Draw();
	c2s->cd(5);hYZ_1->Draw("colz");c2s->cd(2);hY_1->Draw();c2s->cd(8);hZ_1->Draw();
	c2s->cd(6);hXZ_1->Draw("colz");c2s->cd(3);hZ_1->Draw();c2s->cd(9);hX_1->Draw();

	TCanvas *c2i=new TCanvas("c2b","c2_likelihoodReconstructionOUT");
	c2i->Divide(3,3);
	c2i->cd(4);hXY_2->Draw("colz");c2i->cd(1);hX_2->Draw();c2i->cd(7);hY_2->Draw();
	c2i->cd(5);hYZ_2->Draw("colz");c2i->cd(2);hY_2->Draw();c2i->cd(8);hZ_2->Draw();
	c2i->cd(6);hXZ_2->Draw("colz");c2i->cd(3);hZ_2->Draw();c2i->cd(9);hX_2->Draw();


	TCanvas *c2a=new TCanvas("c2a","c2_likelihoodReconstructionAngles");
	c2a->Divide(2,2);
	c2a->cd(1);hTheta->Draw();
	c2a->cd(2);hTheta->Draw();



	if (interactive){
		gui.Run(1);
	}




	/*Save in output*/
	fout->cd();


	/*Fill other histograms*/
	for (int ii=0;ii<6;ii++){
		if (detector->isDetPresent(ii)==0) continue;
		for (int id=0;id<detector->getNPixels(ii);id++){
			hCharge[ii].at(id)->Write();
			hTime[ii].at(id)->Write();
			hTimeVsCharge[ii].at(id)->Write();
		}
	}
	hXY->Write();hXY_1->Write();hXY_2->Write();
	hXZ->Write();hXZ_1->Write();hXZ_2->Write();
	hYZ->Write();hYZ_1->Write();hYZ_2->Write();
	hX->Write(); hX_1->Write(); hX_2->Write();
	hY->Write(); hY_1->Write(); hY_2->Write();
	hZ->Write(); hZ_1->Write(); hZ_2->Write();


	//delete detector;
	fin->Close();
	fout->Close();
	cout<<"end"<<endl;


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

		else if ((strcmp(argv[ii],"-int")==0)||(strcmp(argv[ii],"-interactive")==0)){
			interactive=1;
		}
	}

}

TVector3 COG(int **q){

	int ipixel;
	double qNew=0;
	double qTotNew=0;
	double cosine=0;
	TVector3 cog(0.,0.,0.);
	TVector3 cogNew(0.,0.,0.);

	for (int ii=0;ii<6;ii++){
		if (detector->isDetPresent(ii)==0) continue;
		for (int iy=0;iy<detector->getNPixelsY(ii);iy++){
			for (int ix=0;ix<detector->getNPixelsX(ii);ix++){
				ipixel=ix+iy*detector->getNPixelsX(ii);
				qNew=1.*q[ii][ipixel];
				qNew=pow(qNew,1.5);

				cog=cog+qNew*(detector->getPosPixel(ii,ipixel));
				qTotNew+=qNew;
			}
		}
	}
	cog=cog*(1./qTotNew);
	cogNew=cog;

	return cogNew;

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
