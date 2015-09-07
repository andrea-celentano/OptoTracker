#include "TXMLHandler.hh"



TXMLHandler::TXMLHandler(string fname){
	m_xmlFile=fname;
	m_xml = new TXMLEngine;
	m_xmldoc = m_xml->ParseFile(m_xmlFile.c_str());
	// take access to main node
	m_mainnode = m_xml->DocGetRootElement(m_xmldoc);
	DisplayNodes(m_mainnode,1);

	//Check the main node name
	string mainname=string(m_xml->GetNodeName(m_mainnode));

	if (mainname!="OptoTracker"){
		Error("TXMlHandler","TXMLHandler:: main node should be OptoTracker");
	}


}


TXMLHandler::~TXMLHandler(){

}


XMLNodePointer_t TXMLHandler::GetUniqueNode(string nodename,XMLNodePointer_t father){
	XMLNodePointer_t ret=0;
	XMLNodePointer_t child;


	child=m_xml->GetChild(m_mainnode);
	if (father==0) father=m_mainnode;


	if (string(m_xml->GetNodeName(father))==nodename){

		ret=father;
	}
	else{
		child=m_xml->GetChild(father);
		while (child!=0){

			ret=this->GetUniqueNode(nodename,child);
			if (ret) break;
			child=m_xml->GetNext(child);
		}
	}
	return ret;
}
vector<driver> TXMLHandler::GetDrivers(){

	vector<driver> ret;
	driver m_driver;
	string name;
	int isAttrGood=0;
	int isDriverGood=0;

	XMLNodePointer_t executeNode = this->GetUniqueNode("execute");
	XMLNodePointer_t driversNode = this->GetUniqueNode("drivers");
	XMLNodePointer_t execute=0;
	XMLNodePointer_t driver=0;
	XMLAttrPointer_t attr;
	if (executeNode == 0){
		Error("TXMLHandler","TXMLHandler::GetDrivers, no execute node");
		return ret;
	}
	if (driversNode == 0){
		Error("TXMLHandler","TXMLHandler::GetDrivers, no drivers node");
		return ret;
	}

	/*Now loop on execute*/
	execute = m_xml->GetChild(executeNode);
	if (execute==0){
		Error("TXMLHandler","TXMLHandler::GetDrivers, no entry in execute");
		return ret;
	}
	else{
		while (execute!=0){
			isAttrGood=0;
			attr = m_xml->GetFirstAttr(execute);
			while (attr!=0) {
				name=string(m_xml->GetAttrName(attr));
				if (name=="name"){
					m_driver.name=string(m_xml->GetAttrValue(attr));
					isAttrGood=1;
					break;
				}
				else{
					attr = m_xml->GetNextAttr(attr);
				}
			}
			if (isAttrGood==0){
				Error("TXMLHandler","TXMLHandler::GetDrivers Error, driver entry in execute is not well formed");
			}
			execute = m_xml->GetNext(execute);
		}

	}

	return ret;
}

void TXMLHandler::DisplayNodes(XMLNodePointer_t node, Int_t level)
{
	// this function display all accessible information about xml node and its children

	printf("%*c node: %s\n",level,' ', m_xml->GetNodeName(node));

	// display namespace
	XMLNsPointer_t ns =m_xml->GetNS(node);
	if (ns!=0)
		printf("%*c namespace: %s refer: %s\n",level+2,' ', m_xml->GetNSName(ns), m_xml->GetNSReference(ns));

	// display attributes
	XMLAttrPointer_t attr = m_xml->GetFirstAttr(node);
	while (attr!=0) {
		printf("%*c attr: %s value: %s\n",level+2,' ', m_xml->GetAttrName(attr), m_xml->GetAttrValue(attr));
		attr = m_xml->GetNextAttr(attr);
	}

	// display content (if exists)
	const char* content =m_xml->GetNodeContent(node);
	if (content!=0)
		printf("%*c cont: %s\n",level+2,' ', content);

	// display all child nodes
	XMLNodePointer_t child = m_xml->GetChild(node);
	while (child!=0) {
		DisplayNodes(child, level+2);
		child = m_xml->GetNext(child);
	}
}


