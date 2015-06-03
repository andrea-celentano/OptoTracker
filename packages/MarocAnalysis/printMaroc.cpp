/*
 * printMaroc.cpp
 *
 *  Created on: May 27, 2015
 *      Author: celentan
 */




#include <iostream>
#include <string>



#include "MarocSetupHandler.hh"
#include "TOpNoviceDetectorLight.hh"

using namespace std;



/*From the command line*/
string fDetName,fSetupName;


void ParseCommandLine(int argc,char **argv);
void PrintHelp();


int main(int argc,char **argv){
	if (argc==0){
		PrintHelp();
		exit(1);
	}
	ParseCommandLine(argc,argv);


	if (fDetName.length()==0){
		cerr<<"Missing DET file name"<<endl;
		return -1;
	}
	if (fSetupName.length()==0){
		cerr<<"Missing Setup file name"<<endl;
		return -1;
	}


	TOpNoviceDetectorLight *m_detector=new TOpNoviceDetectorLight(fDetName);
	MarocSetupHandler *m_setup=new MarocSetupHandler(fSetupName);


	m_setup->Print(1);

	cout<<"Done!"<<endl;
}





void ParseCommandLine(int argc,char **argv){
	for (int ii=0;ii<argc;ii++){

		if ((strcmp(argv[ii],"-d")==0)||(strcmp(argv[ii],"-det")==0)){
			fDetName=string(argv[ii+1]);
		}
		else if ((strcmp(argv[ii],"-ss")==0)||(strcmp(argv[ii],"-setup")==0)){
			fSetupName=string(argv[ii+1]);
		}
		else if ((strcmp(argv[ii],"-h")==0)||(strcmp(argv[ii],"-help")==0)){
			PrintHelp();
		}
	}

}



void PrintHelp(){

	cout<<"-d or -det: detector file name"<<endl;
	cout<<"-ss or -setup: setup file name"<<endl;

}


