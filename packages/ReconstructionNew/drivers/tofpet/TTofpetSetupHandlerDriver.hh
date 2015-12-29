/*
 * TTofpetSetupHandlerDriver.hh
 *
 *  Created on: Dec 11, 2015
 *      Author: celentan
 */

#ifndef TTOFPETSETUPHANDLERDRIVER_HH_
#define TTOFPETSETUPHANDLERDRIVER_HH_

#include "TDriver.hh"
#include <string>

class TTofpetSetupHandler;

class TTofpetSetupHandlerDriver: public TDriver {

private:
	int m_source;
	std::string m_fname;
	TTofpetSetupHandler *m_setupHandler;
public:
	TTofpetSetupHandlerDriver();
	virtual ~TTofpetSetupHandlerDriver();


	/*These are the virtual methods implemented by the derived classes*/
	/*	virtual int start(){return 0;};
	virtual int startOfData(){return 0;};
	virtual int endOfData(){return 0;};
	virtual int end(){return 0;};
	virtual int process(TEvent *event);
	virtual int detectorChanged(){return 0;};*/


	virtual int start();

	void setSource(int source){m_source=source;}
	void setFileName(const char* fname){this->m_fname=string(fname);}

	static const int	txtFile=0;
	static const int	rootFile=1;






	ClassDef(TTofpetSetupHandlerDriver,1);

};

#endif /* TTOFPETSETUPHANDLERDRIVER_HH_ */
