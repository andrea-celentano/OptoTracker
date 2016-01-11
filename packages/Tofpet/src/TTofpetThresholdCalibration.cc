/*
 * TTofpetChargeCalibration.cc
 *
 *  Created on: Dec 29, 2015
 *      Author: celentan
 */

#include "TTofpetThresholdCalibration.hh"
#include <iostream>

using namespace std;
TTofpetThresholdCalibration::TTofpetThresholdCalibration() {
	// TODO Auto-generated constructor stub
	Info("TTofpetThresholdCalibration","creator");
}


TTofpetThresholdCalibration::~TTofpetThresholdCalibration() {
	// TODO Auto-generated stub
	Info("TTofpetThresholdCalibration","desctructor");
}

int TTofpetThresholdCalibration::getTransition(int ch,int step1,int nphe) const{
	std::map<std::pair<int,int>,std::vector<int> >::const_iterator it;
	it=m_transitions.find(std::make_pair(ch,step1));
	if (it==m_transitions.end()){
		Error("getTransitions","no entry in map for ch: %i step1:%i",ch,step1);
		return -1;
	}
	return it->second.at(nphe);
}

int TTofpetThresholdCalibration::getThreshold(int ch,int step1,int nphe) const{

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
	mean+=1;

	return (int)mean;
}

void TTofpetThresholdCalibration::printTransitions(int step1,int nphe1,int nphe2) const{
	int thr1,thr2;
	for (int ich=0;ich<128;ich++){ ///TODO
		thr1=getTransition(ich,step1,nphe1);
		thr2=getTransition(ich,step1,nphe2);
		cout<<"Ch: "<<ich<<" transition (inverted!): "<<thr1<<" "<<thr2<<" --- transition(not inverted): "<<63-thr1<<" "<<63-thr2<<endl;
	}
}


void TTofpetThresholdCalibration::printThresholds(int step1,int nphe1,int nphe2) const{
	int thr1,thr2;
	for (int ich=0;ich<128;ich++){ ///TODO
		thr1=getThreshold(ich,step1,nphe1);
		thr2=getThreshold(ich,step1,nphe2);
		cout<<"Ch: "<<ich<<" thr (inverted!): "<<thr1<<" "<<thr2<<" --- thr(not inverted): "<<63-thr1<<" "<<63-thr2<<endl;
	}
}

void TTofpetThresholdCalibration::computeRateDerived(int ch,int step1){
	TH1D *hRateRaw=0;
	TH1D *hRateDerived=0;
	double data,diff,delta;
	int imax;
	hRateRaw=this->gethRateRaw(ch,step1);
	if (hRateRaw==0){
		Error("computeRateDerived","no raw-rate histogram found");
		return;
	}

	/*Compute here the derived rate*/
	hRateDerived=new TH1D(Form("hRateDerived_step%i_ch%i",step1,ch),Form("hRateDerived_step%i_ch%i:thr:rate",step1,ch),64,-0.5,63.5);

	for (int ibin=0;ibin<hRateRaw->GetNbinsX();ibin++){
		data=hRateRaw->GetBinContent(ibin);
		if (data>MAX_RATE){
			imax=ibin;
			break;
		}
	}

	for (int ibin=imax;ibin>=BIN_MIN;ibin--){
		data=hRateRaw->GetBinContent(ibin);
		diff=hRateRaw->GetBinContent(ibin+1)-hRateRaw->GetBinContent(ibin-1);
		delta=hRateRaw->GetBinContent(ibin);
		if (delta!=0){
			diff=2*diff/delta;
			hRateDerived->SetBinContent(ibin,diff);
		}
	}

	this->addhRateDerived(ch,step1,hRateDerived);
	return;
}

void TTofpetThresholdCalibration::computeThresholds(int ch,int step1){
	TH1D *hRateRaw=0;
	TH1D *hRateDerived=0;
	TGraph *gThreshold=0;
	double data,prev_data,post_data,rate;
	int iphe,imax;
	bool flag;

	vector <int> m_transition_tmp;
	vector <int> m_threshold_tmp;

	hRateRaw=this->gethRateRaw(ch,step1);
	if (hRateRaw==0){
		Error("computeTransitions","no raw-rate histogram found");
		return;
	}
	hRateDerived=this->gethRateDerived(ch,step1);
	if (hRateDerived==0){
		Error("ccomputeTransitions","no raw-rate histogram found");
		return;
	}

	/*Looking for maxima*/
	for (int ibin=0;ibin<hRateRaw->GetNbinsX();ibin++){
		data=hRateRaw->GetBinContent(ibin);
		if (data>MAX_RATE){
			imax=ibin;
			break;
		}
	}
	iphe=0;
	for (int ibin=imax;ibin>=BIN_MIN;ibin--){
		data=hRateDerived->GetBinContent(ibin);
		prev_data=hRateDerived->GetBinContent(ibin+1);
		post_data=hRateDerived->GetBinContent(ibin-1);
		if ((data>prev_data)&&(data>post_data)){
			m_transition_tmp.push_back(hRateDerived->GetBinCenter(ibin));
			iphe++;
		}
	}
	/*Now compute the rate corresponding to 1 phe and save it */
	if (m_transition_tmp.size()>1)			rate=hRateRaw->GetBinContent(hRateRaw->FindBin(m_transition_tmp.at(1)));
	else rate=0;
	//rateSinglePhe[id]=rate;

	/*Now it is important to do a check: the 1 phe rate should be, for sure, < 10MHz or so.
	 * If it is higher, it means there is 1 fake peak (or more)
	 */
	while(1){
		flag=true;
		if (rate>MAX_RATE){
			cout<<"Doing correction for channel: "<<ch<<" step: "<<step1<<endl;
			cout<<"Before: "<<rate<<endl;
			flag=false;
			//implement the correction->translate by -1 the phe, starting from 1
			m_transition_tmp.erase(m_transition_tmp.begin());
			//re-compute rateSinglePhe for this
			rate=hRateRaw->GetBinContent(hRateRaw->FindBin(m_transition_tmp.at(1)));
			cout<<"After: "<<rate<<endl<<endl;
		}
		if (flag) break;
	}

	/*Invert the scale*/
	for (int iphe=0;iphe<m_transition_tmp.size();iphe++){
		m_transition_tmp.at(iphe)=MAX_SCALE-m_transition_tmp.at(iphe);
	}
	/*Compute the thresholds values*/



	/*Now, save everything*/
	gThreshold=new TGraph();
	gThreshold->SetName(Form("gThreshold_step%i_ch%i",step1,ch));
	gThreshold->SetTitle(Form("gThreshold_step%i_ch%i",step1,ch));
	gThreshold->SetMarkerStyle(20);

	std::pair<int,int> m_key(ch,step1);
	m_transitions[m_key]=m_transition_tmp;
	m_rateSinglePhe[m_key]=rate;


	for (int iphe=0;iphe<m_transition_tmp.size();iphe++){
		gThreshold->SetPoint(iphe,iphe,m_transition_tmp.at(iphe));
	}
	this->addgThr(ch,step1,gThreshold);
}
