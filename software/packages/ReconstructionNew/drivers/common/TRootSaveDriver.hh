#ifndef TROOTSAVEDRIVER_HG
#define TROOTSAVEDRIVER_HG

#include "TDriver.hh"
#include <string>

class TFile;

class TRootSaveDriver : public TDriver{

	string m_fname;
	TFile *m_fout;

public:
	TRootSaveDriver();
	virtual ~TRootSaveDriver();

	void setOutFileName(const char* m_fname);


	/*These are the pure virtual methods implemented here*/
	virtual int end();   //This method gets called once after the last event.


	ClassDef(TRootSaveDriver,1);

};


#endif
