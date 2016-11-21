#include "TTofpetThresholdCalibration.hh"
#include <iostream>
#include "time.h"
#include "TLine.h"
using namespace std;
TTofpetThresholdCalibration::TTofpetThresholdCalibration() {
	// TODO Auto-generated constructor stub
	Info("TTofpetThresholdCalibration","creator");
	m_c_interactive=new TList();
	m_TTofpetThresholdCalibrationGui=0;
}


TTofpetThresholdCalibration::~TTofpetThresholdCalibration() {
	// TODO Auto-generated stub
	Info("TTofpetThresholdCalibration","destructor");
	TIter *iter=new TIter(m_c_interactive);
	TObject *obj;
	while (obj = iter->Next()){
		if (obj!=0) delete obj;
	}
	delete iter;
}

int TTofpetThresholdCalibration::getNtransitions(int ch) const{
	std::map<int,std::vector<int> >::const_iterator it;
	it=m_transitions.find(ch);
	return it->second.size();
}

int TTofpetThresholdCalibration::getTransition(int ch,int nphe) const{
	std::map<int,std::vector<int> >::const_iterator it;
	it=m_transitions.find(ch);
	if (it==m_transitions.end()){
		Error("getTransition","no entry in map for ch: %i",ch);
		return -1;
	}
	if (it->second.size()<=nphe){
		Error("getTransition","vector size is less than nphe");
		return -2;
	}
	return it->second.at(nphe);
}

bool TTofpetThresholdCalibration::hasFinalThreshold(int ch) const{
	int thr;
	std::map<int,std::pair<int,int> >::const_iterator it;
	it = m_Thresholds.find(ch);
	if (it==m_Thresholds.end()) return false;
	else return true;
}

int TTofpetThresholdCalibration::getThreshold(int ch,bool forceRaw) const{
	int thr;
	std::map<int,int>::const_iterator it_raw;
	std::map<int,std::pair<int,int> >::const_iterator it;
	if (forceRaw){
		it_raw = m_RawThresholds.find(ch);
		if (it_raw==m_RawThresholds.end()){
			Error("getThreshold","Raw threshold not found for ch: %i",ch);
			return 0;
		}
		else{
			return (it_raw)->second;
		}
	}
	else{
		it = m_Thresholds.find(ch);
		if (it==m_Thresholds.end()){
			Info("getThreshold","Threshold not found for ch: %i Trying raw",ch);
			return this->getThreshold(ch,true);
		}
		else{
			return (it)->second.first;
		}
	}
	return 0;
}
void TTofpetThresholdCalibration::setThreshold(int ch,int thr,int nphe){
	//here, I am not checking if the element exists or not!
	m_Thresholds[ch]=std::make_pair(thr,nphe);

	//save the time this was done
	char thrTime[40];
	time_t _tm =time(NULL );
	struct tm * curtime = localtime ( &_tm );
	strftime(thrTime,sizeof(thrTime),"%Y%m%d%H%M%S",curtime);
	m_ThresholdsDate[ch]=string(thrTime);

}



int TTofpetThresholdCalibration::computeThresholdFromRateTransitions(int ch,int nphe) const{

	int nPreTransition,nPostTransition;

	double mean;
	if (nphe<1){
		Error("getThreshold","threshold val in phe must be > 0");
		return -1;
	}
	nPreTransition=this->getTransition(ch,nphe-1); //this is the thr val corresponding to nphe-1 --> nphe
	nPostTransition=this->getTransition(ch,nphe);  //this is the thr val corresponding to nphe   --> nphe+1
	if ((nPreTransition<0)||(nPostTransition<0)){
		return 0;
	}
	mean=(nPreTransition+nPostTransition)/2.;
	mean=floor(mean);
	mean+=1;

	return (int)mean;
}

void TTofpetThresholdCalibration::printTransitions(int nphe1,int nphe2) const{
	int thr1,thr2;
	for (int ich=0;ich<128;ich++){ ///TODO
		thr1=getTransition(ich,nphe1);
		thr2=getTransition(ich,nphe2);
		cout<<"Ch: "<<ich<<" transition (inverted!): "<<thr1<<" "<<thr2<<" --- transition(not inverted): "<<63-thr1<<" "<<63-thr2<<endl;
	}
}


void TTofpetThresholdCalibration::printThresholds(int nphe1,int nphe2) const{
	int thr1,thr2;
	for (int ich=0;ich<128;ich++){ ///TODO
		thr1=getThreshold(ich,nphe1);
		thr2=getThreshold(ich,nphe2);
		cout<<"Ch: "<<ich<<" thr (inverted!): "<<thr1<<" "<<thr2<<" --- thr(not inverted): "<<63-thr1<<" "<<63-thr2<<endl;
	}
}

void TTofpetThresholdCalibration::dumpThresholds(string fname) const{
	ofstream file(fname.c_str(),std::ios::trunc);
	std::map<int,std::pair<int,int> >::const_iterator it;
	file<<"#Ch thr nphe"<<endl;
	for (it=m_Thresholds.begin();it!=m_Thresholds.end();it++){
		file<<it->first<<" "<<it->second.first<<" "<<it->second.second<<endl;
	}
	file.close();
}

void TTofpetThresholdCalibration::computeRateDerived(int ch){
	TH1D *hRateRaw=0;
	TH1D *hRateDerived=0;
	double data,max_data,diff,delta;
	int imax,imax2;
	hRateRaw=this->gethRateRaw(ch);
	if (hRateRaw==0){
		Error("computeRateDerived","no raw-rate histogram found");
		return;
	}

	/*Compute here the derived rate*/
	hRateDerived=new TH1D(Form("hRateDerived_ch%i",ch),Form("hRateDerived_ch%i:thr:rate",ch),64,-0.5,63.5);

	imax=-1;
	max_data=0;
	for (int ibin=0;ibin<hRateRaw->GetNbinsX();ibin++){
		data=hRateRaw->GetBinContent(ibin);
		if (data>MAX_RATE){
			imax=ibin;
			break;
		}
		if (data>max_data){
			max_data=data;
			imax2=ibin;
		}
	}
	if (imax==-1){
		Warning("computeRateDerived","using local maxima since MAX_RATE not exceeded");
		imax=imax2;
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
	//hRateDerived->Smooth(1);

	this->addhRateDerived(ch,hRateDerived);
	return;
}

void TTofpetThresholdCalibration::computeThresholds(int ch){
	TH1D *hRateRaw=0;
	TH1D *hRateDerived=0;
	TGraph *gThreshold=0;
	TGraph *gRateVsThreshold=0;
	double data,prev_data,prev_prev_data,post_data,post_post_data,rate,max_data;
	int iphe,imax,imax2,thr;
	bool flag;

	vector <int> m_transition_tmp;
	vector <int> m_threshold_tmp;

	hRateRaw=this->gethRateRaw(ch);
	if (hRateRaw==0){
		Error("computeTransitions","no raw-rate histogram found");
		return;
	}
	hRateDerived=this->gethRateDerived(ch);
	if (hRateDerived==0){
		Error("ccomputeTransitions","no raw-rate histogram found");
		return;
	}

	/*Looking for maxima*/
	imax=-1;
	for (int ibin=0;ibin<hRateRaw->GetNbinsX();ibin++){
		data=hRateRaw->GetBinContent(ibin);
		if (data>MAX_RATE){
			imax=ibin;
			break;
		}
		if (data>max_data){
			max_data=data;
			imax2=ibin;
		}
	}
	if (imax==-1){
		Warning("computeThresholds","using local maxima since MAX_RATE not exceeded");
		imax=imax2;
	}


	iphe=0;
	for (int ibin=imax;ibin>=BIN_MIN;ibin--){
		data=hRateDerived->GetBinContent(ibin);
		prev_prev_data=hRateDerived->GetBinContent(ibin+2);
		prev_data=hRateDerived->GetBinContent(ibin+1);
		post_data=hRateDerived->GetBinContent(ibin-1);
		post_post_data=hRateDerived->GetBinContent(ibin-2);

		if ((data>prev_data)&&(data>post_data)&&(data>post_post_data)&&(data>prev_prev_data)){
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
			cout<<"Doing correction for channel: "<<ch<<endl;
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
		//	m_transition_tmp.at(iphe)=MAX_SCALE-m_transition_tmp.at(iphe);
		m_transition_tmp.at(iphe)=1*m_transition_tmp.at(iphe);
	}
	/*Write transitions*/

	m_transitions[ch]=m_transition_tmp;
	m_rateSinglePhe[ch]=rate;

	/*Compute the threshold values*/
	thr=this->computeThresholdFromRateTransitions(ch,PHE_THR);
	m_RawThresholds[ch]=thr;

	/*save graph*/
	gThreshold=new TGraph();
	gThreshold->SetName(Form("gThreshold_ch%i",ch));
	gThreshold->SetTitle(Form("gThreshold_ch%i",ch));
	gThreshold->SetMarkerStyle(20);

	gRateVsThreshold=new TGraph();
	gRateVsThreshold->SetName(Form("gRateVsThreshold_ch%i",ch));
	gRateVsThreshold->SetTitle(Form("gRateVsThreshold_ch%i",ch));
	gRateVsThreshold->SetMarkerStyle(20);



	for (int iphe=0;iphe<m_transition_tmp.size();iphe++){
		gThreshold->SetPoint(iphe,iphe,m_transition_tmp.at(iphe));
		gRateVsThreshold->SetPoint(iphe,iphe+1,hRateRaw->GetBinContent(m_transition_tmp.at(iphe)+1));
	}
	this->addgThr(ch,gThreshold);
	this->addgRateVsThr(ch,gRateVsThreshold);
}

int TTofpetThresholdCalibration::getDAQRunThreshold(int ch, int step2) const{

	int thr;
	int other_ch;
	thr=this->computeThresholdFromRateTransitions(ch,1);
	if (thr==0){ //if not threshold transition found - for example because dark scan was inefficient on this channel
		if ((ch%64)==0){ //first channel in asic
			other_ch=ch+1;
		}
		else if ((ch%64)==63){ //last channel in asic
			other_ch=ch-1;
		}
		else{
			other_ch=ch-1;
		}
		thr=this->computeThresholdFromRateTransitions(other_ch,1);
		Warning("getDAQRunThreshold","ch %i DAQ thr was determined with rate transition from ch %i",ch,other_ch);
	}

	thr=thr+2-step2;
	return thr;


}

TCanvas* TTofpetThresholdCalibration::getInteractiveCanvas(int ch){
	string name=string(Form("c_ch:%i",ch));
	TIter *iter=new TIter(m_c_interactive);
	TCanvas *c;
	Info("getInteractiveCanvas","creating canvas");
	c=new TCanvas(name.c_str(),name.c_str(),1000,1000);
	//m_c_interactive->Add(c);
	Info("getInteractiveCanvas","done");

	/*Here draw the canvas*/
	TLine *l;
	int thr,thr_tmp;
	double maxDrawY,minDrawY;
	double maxDrawX,minDrawX;
	int firstBin,lastBin;
	thr=this->getThreshold(ch); //whatever the threshold is - raw or not
	maxDrawY=this->getDAQRunThreshold(ch,0);
	minDrawY=this->getDAQRunThreshold(ch,20);


	c->Divide(2,2);
	c->cd(1);
	Info("getInteractiveCanvas","1");
	this->gethToTvsThr(ch)->GetYaxis()->SetRangeUser(minDrawY,maxDrawY);
	this->gethToTvsThr(ch)->Draw("colz");
	Info("getInteractiveCanvas","2");
	minDrawX=this->gethToTvsThr(ch)->GetXaxis()->GetXmin();
	maxDrawX=this->gethToTvsThr(ch)->GetXaxis()->GetXmax();
	Info("getInteractiveCanvas","3");
	l=new TLine(minDrawX,thr,maxDrawX,thr);
	l->SetLineColor(2);
	l->SetLineWidth(2);
	l->Draw("SAME");
	thr_tmp=this->getTransition(ch,1);
	l=new TLine(minDrawX,thr_tmp,maxDrawX,thr_tmp);
	l->SetLineColor(3);
	l->SetLineWidth(2);
	l->Draw("SAME");
	thr_tmp=this->getTransition(ch,2);
	l=new TLine(minDrawX,thr_tmp,maxDrawX,thr_tmp);
	l->SetLineColor(3);
	l->SetLineWidth(2);
	l->Draw("SAME");


	c->cd(2);
	firstBin=thr+1;
	lastBin=thr+1;
	Info("getInteractiveCanvas","4");
	if (m_hToT.find(ch) !=	m_hToT.end() ){
		Info("getInteractiveCanvas","hToT %i already exists. delete it and replace",ch);
		delete m_hToT[ch]; //note that this calls delete on the pointer, that is still there in the map pointing at 0!
		m_hToT.erase(m_hToT.find(ch));
		Info("getInteractiveCanvas","done");
	}
	m_hToT[ch]=this->gethToTvsThr(ch)->ProjectionX(Form("hToT0_ch:%i_proj",ch),firstBin,lastBin);
	m_hToT[ch]->Draw();
	c->cd(3)->SetLogy();
	maxDrawY=this->gethRateRaw(ch)->GetMaximum()*1.1;
	minDrawY=1;
	this->gethRateRaw(ch)->Draw();
	l=new TLine(thr,minDrawY,thr,maxDrawY);
	l->SetLineColor(2);
	l->SetLineWidth(2);
	l->Draw("SAME");
	c->cd(4);
	this->getgThr(ch)->Draw("AP");


	return c;


}

int TTofpetThresholdCalibration::decideThresholdDummy(int ch){
	TCanvas *c;
	int thr;
	while(1){
		c=this->getInteractiveCanvas(ch);
		c->Draw();
		c->Modified();
		c->Update();
		cout<<"Thr is: "<<this->getThreshold(ch)<<" it is ok? Or set new value"<<endl;
		cin>>thr;
		if (thr){
			this->setThreshold(ch,thr);
		}
		else break;
	}


}

int TTofpetThresholdCalibration::decideThresholds(){
	m_TTofpetThresholdCalibrationGui=new TTofpetThresholdCalibrationGui(this,gClient->GetRoot(),1000,1000);
	m_TTofpetThresholdCalibrationGui->Start();
}
