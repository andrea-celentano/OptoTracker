/*
 * TTofpetTimeAnalysisDriver.hh
 *
 *  Created on: Apr 14, 2016
 *      Author: celentan
 */

#ifndef TTOFPETTIMEANALYSISDRIVER_HH_
#define TTOFPETTIMEANALYSISDRIVER_HH_

#include "TObject.h"

#include "TDriver.hh"

class TH1D;
class TH2D;
class TTofpetRun;
class TTree;


class TTofpetTimeAnalysisDriver: public TDriver {
public:
	TTofpetTimeAnalysisDriver();

	virtual int startOfData();
	virtual int process(TEvent *event);
	virtual int end();

	virtual ~TTofpetTimeAnalysisDriver();

	void setCh1(int ch1){m_ch1=ch1;}
	void setCh2(int ch2){m_ch2=ch2;}


private:
	TH1D *hMultiplicity0;
	TH1D *hMultiplicity1;
	TH1D *hMultiplicity2;

	TH1D *hEntries0;
	TH1D *hEntries1;

	TH1D **hToT0;
	TH1D **hToT1;

	TH2D *hToTch1VSch2;

	TH1D *hDeltaT;

	TTofpetRun *m_TofpetRun;

	TTree *tout;
	double m_Q1,m_Q2;
	long long m_T1,m_T2;

	int m_Nsteps;
	static const int m_Nch=256;

	int m_ch1,m_ch2;

	ClassDef(TTofpetTimeAnalysisDriver,1);
};

#endif /* TTOFPETTIMEANALYSISDRIVER_HH_ */
