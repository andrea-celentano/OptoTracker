/*
 * TTofpetChargeCalibration.cc
 *
 *  Created on: Dec 29, 2015
 *      Author: celentan
 */

#include "TTofpetChargeCalibration.hh"
#include <iostream>

using namespace std;
TTofpetChargeCalibration::TTofpetChargeCalibration() {
	// TODO Auto-generated constructor stub
	Info("TTofpetChargeCalibration","creator");
}


TTofpetChargeCalibration::~TTofpetChargeCalibration() {
	// TODO Auto-generated stub
	Info("TTofpetChargeCalibration","desctructor");
}

int TTofpetChargeCalibration::getTransition(int ch,int step1,int nphe) const{

	TGraph *grThr=0;
	int thr=-1;
	grThr=this->getgThr(ch,step1);
	if (grThr==0){
		Error("getThreshold","no Threshold graph!");
		return -1;
	}
	else if(nphe<0){
		Error("getThreshold","transition val in phe must be >= 0");
		return -2;
	}
	else{
		return thr=grThr->Eval(nphe);
	}
}

int TTofpetChargeCalibration::getThreshold(int ch,int step1,int nphe) const{

	int nPreTransition,nPostTransition;

	double mean;
	if (nphe<1){
		Error("getThreshold","threshold val in phe must be > 0");
		return -1;
	}
	nPreTransition=this->getTransition(ch,step1,nphe-1); //this is the thr val corresponding to nphe-1 --> nphe
	nPostTransition=this->getTransition(ch,step1,nphe);  //this is the thr val corresponding to nphe   --> nphe+1

	mean=(nPreTransition+nPostTransition)/2.;
	mean=floor(mean);
	//mean+=1;

	return (int)mean;
}

void TTofpetChargeCalibration::printTransitions(int step1,int nphe1,int nphe2) const{
	int thr1,thr2;
	for (int ich=0;ich<128;ich++){ ///TODO
		thr1=getTransition(ich,step1,nphe1);
		thr2=getTransition(ich,step1,nphe2);
		cout<<"Ch: "<<ich<<" transition (inverted!): "<<thr1<<" "<<thr2<<" --- transition(not inverted): "<<63-thr1<<" "<<63-thr2<<endl;
	}
}


void TTofpetChargeCalibration::printThresholds(int step1,int nphe1,int nphe2) const{
	int thr1,thr2;
	for (int ich=0;ich<128;ich++){ ///TODO
		thr1=getThreshold(ich,step1,nphe1);
		thr2=getThreshold(ich,step1,nphe2);
		cout<<"Ch: "<<ich<<" thr (inverted!): "<<thr1<<" "<<thr2<<" --- thr(not inverted): "<<63-thr1<<" "<<63-thr2<<endl;
	}
}
