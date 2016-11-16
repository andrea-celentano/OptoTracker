#ifndef TXMLHANDLER_HG
#define TXMLHANDLER_HG

#include <iostream>
#include <string>
#include <vector>

#include "TObject.h"
/*for XML*/
#include "TXMLEngine.h"
#include "TXMLParser.h"
#include "TDOMParser.h"

#include "CommonStructures.hh"

using namespace std;



class TXMLHandler : public TObject{
private:


	TXMLEngine  *m_xml;
	string m_xmlFile;

	XMLDocPointer_t m_xmldoc;
	XMLNodePointer_t m_mainnode;

	XMLNodePointer_t GetUniqueNode(string nodename,XMLNodePointer_t father=0);

public:
	TXMLHandler(string fname="");
	virtual ~TXMLHandler();



	vector<driver_struct> GetDrivers();
	reconControl_struct GetReconControl();

	void DisplayNodes(XMLNodePointer_t node, Int_t level);


	ClassDef(TXMLHandler,1);
};



#endif
