/*
 * TTofpetTimeAnalysisDriver.cc
 *
 *  Created on: Apr 14, 2016
 *      Author: celentan
 */

#include "TTofpetTimeAnalysisDriver.hh"

#include "TH1D.h"
#include "TH2D.h"


#include "TTofpetRun.hh"

#include "TEvent.hh"
#include "TTofpetEventHeader.hh"
#include "TTofpetHit.hh"
#include "TJobManager.hh"
#include "TTofpetSetupHandler.hh"
#include "TTree.h"




TTofpetTimeAnalysisDriver::TTofpetTimeAnalysisDriver() {
	// TODO Auto-generated constructor stub
	m_TofpetRun=0;
	hMultiplicity0=0;
	hMultiplicity1=0;
	hMultiplicity2=0;
	hToT0=0;
	hToT1=0;
	hToTch1VSch2=0;
	hDeltaT=0;
	tout=0;
	hEntries0=0;
	hEntries1=0;

	m_ch1=0;
	m_ch2=0;

}

TTofpetTimeAnalysisDriver::~TTofpetTimeAnalysisDriver() {
	// TODO Auto-generated destructor stub
}


int TTofpetTimeAnalysisDriver::startOfData(){

	Info("startOfData","start");

	if (m_manager->hasObject(TTofpetRun::Class())){
		m_TofpetRun=(TTofpetRun*)(m_manager->getObject(TTofpetRun::Class()));



		hMultiplicity0=new TH1D(Form("hMultiplicity0"),Form("hMultiplicity0"),m_Nch,-0.5,m_Nch-0.5);
		m_manager->GetOutputList()->Add(hMultiplicity0);

		hMultiplicity1=new TH1D(Form("hMultiplicity1"),Form("hMultiplicity1"),m_Nch,-0.5,m_Nch-0.5);
		m_manager->GetOutputList()->Add(hMultiplicity1);

		hMultiplicity2=new TH1D(Form("hMultiplicity2"),Form("hMultiplicity2"),m_Nch,-0.5,m_Nch-0.5);
		m_manager->GetOutputList()->Add(hMultiplicity2);

		hEntries0=new TH1D(Form("hEntries0"),Form("hEntries0"),m_Nch,-0.5,m_Nch-0.5);
		m_manager->GetOutputList()->Add(hEntries0);

		hEntries1=new TH1D(Form("hEntries1"),Form("hEntries1"),m_Nch,-0.5,m_Nch-0.5);
		m_manager->GetOutputList()->Add(hEntries1);

		hDeltaT=new TH1D(Form("hDeltaT"),Form("hDeltaT"),100,-10.,10.);	m_manager->GetOutputList()->Add(hDeltaT);

		hToT0=new TH1D*[m_Nch];
		hToT1=new TH1D*[m_Nch];

		hToTch1VSch2=new TH2D("hToTch1VSch2","hToTch1VSch2",100,-10,250,100,-10,250);m_manager->GetOutputList()->Add(hToTch1VSch2);

		for (int ich=0;ich<m_Nch;ich++){
			hToT0[ich]=new TH1D(Form("hTOT0_%i",ich),Form("hTOT0_%i",ich),100,-10,250);m_manager->GetOutputList()->Add(hToT0[ich]);
			hToT1[ich]=new TH1D(Form("hTOT1_%i",ich),Form("hTOT1_%i",ich),100,-10,250);m_manager->GetOutputList()->Add(hToT1[ich]);
		}

	tout=new TTree("tout","tout");
		tout->Branch("Q1",&m_Q1);
		tout->Branch("Q2",&m_Q2);
		tout->Branch("T2",&m_T1);
		tout->Branch("T1",&m_T2);
		m_manager->GetOutputList()->Add(tout);

	}
	else{
		Error("startOfData","No TTofpetRun object in the file, should be there!");
		return -1;
	}

}


int TTofpetTimeAnalysisDriver::process(TEvent* event){
	TClonesArray *TTofpetHitCollection;
	TIter		 *TTofpetHitCollectionIter;
	TTofpetHit   *hit;
	TTofpetEventHeader *header=0;

	int N,step1,step2,id,id1,ch,ix,iy;
	double Q1,Q2;
	bool flag1,flag2;
	long long T1,T2;


	header=(TTofpetEventHeader*)event->getEventHeader();
	if (header==0){
		Error("process","no event header!");
	}

	step1=header->getStep1();
	step2=header->getStep2();

	id=m_TofpetRun->getStepID(step1,step2);
	id1=m_TofpetRun->getStep1ID(step1);
	flag1=false;
	flag2=false;
	if (event->hasCollection(TTofpetHit::Class(),m_collectionRawName)){
		TTofpetHitCollection=event->getCollection(TTofpetHit::Class(),m_collectionRawName);
		N=TTofpetHitCollection->GetEntries();
		TTofpetHitCollectionIter=new TIter(TTofpetHitCollection);
		hMultiplicity0->Fill(N);

		while (hit = (TTofpetHit*)TTofpetHitCollectionIter->Next()){
			ch=hit->getChannel();
			hToT0[ch]->Fill(hit->getToT());
			hEntries0->Fill(ch);
			if (N<100){
				hToT1[ch]->Fill(hit->getToT());
				hEntries1->Fill(hit->getChannel());
			}
			if (ch==m_ch1){
				flag1=true;
				m_T1=hit->getTime();
				m_Q1=hit->getToT();
			}
			else if (ch==m_ch2){
				flag2=true;
				m_T2=hit->getTime();
				m_Q2=hit->getToT();
			}
			if ((flag1)&&(flag2)){
				hDeltaT->Fill((T1-T2)*0.001);
				hToTch1VSch2->Fill(Q1,Q2);
				tout->Fill();
			}
		}
	}
}

int TTofpetTimeAnalysisDriver::end(){


}

