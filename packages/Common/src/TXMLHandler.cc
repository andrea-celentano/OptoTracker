#include "TXMLHandler.hh"
#include "TChain.h" //kBigNumber

#include <stdlib.h>     /* atoi */

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

reconControl_struct TXMLHandler::GetReconControl(){
	reconControl_struct	m_ret={};
	m_ret.numberOfEvents=TChain::kBigNumber;
	m_ret.numberOfWorkers=1;
	m_ret.numberOfIterations=1;

	XMLNodePointer_t controlNode = this->GetUniqueNode("control");
	XMLNodePointer_t control=0;

	string nodeName;
	string nodeContent;
	if (controlNode == 0){
		Error("GetReconControl","No control node");
		return m_ret;
	}
	/*Now loop on control*/
	control = m_xml->GetChild(controlNode);
	if (control==0){
		Error("GetReconControl","No entry control");
		return m_ret;
	}
	else{
		while (control!=0){
			nodeName = m_xml->GetNodeName(control);
			nodeContent = m_xml->GetNodeContent(control);
			if (nodeName=="skipEvents"){
				m_ret.skipEvents=atoi(nodeContent.c_str());
				if (m_ret.skipEvents<0){
					Warning("GetReconControl","skipEvents must be >=0");
					m_ret.skipEvents=0;
				}
			}
			else if (nodeName=="numberOfEvents"){
				m_ret.numberOfEvents=atoi(nodeContent.c_str());
				if (m_ret.numberOfEvents<=0){
					Warning("GetReconControl","skipEvents must be >0");
					m_ret.numberOfEvents=TChain::kBigNumber;
				}
			}
			else if (nodeName=="verboseLevel"){
				m_ret.verboseLevel=atoi(nodeContent.c_str());
				if (m_ret.verboseLevel<0){
					Warning("GetReconControl","verboseLevel must be >=0");
					m_ret.verboseLevel=0;
				}
			}
			else if (nodeName=="doProof"){
				m_ret.doProof=atoi(nodeContent.c_str());
				if ((m_ret.doProof!=0)&&(m_ret.doProof!=1)){
					Warning("GetReconControl","doProof can be 0 or 1");
					m_ret.doProof=0;
				}
			}
			else if (nodeName=="doProofDiag"){
				m_ret.doProofDiag=atoi(nodeContent.c_str());
				if ((m_ret.doProofDiag!=0)&&(m_ret.doProofDiag!=1)){
					Warning("GetReconControl","doProofDiag can be 0 or 1");
					m_ret.doProofDiag=0;
				}
			}
			else if (nodeName=="dryRun"){
				m_ret.dryRun=atoi(nodeContent.c_str());
				if ((m_ret.dryRun!=0)&&(m_ret.dryRun!=1)){
					Warning("GetReconControl","dryRun can be 0 or 1");
					m_ret.dryRun=0;
				}
			}
			else if (nodeName=="numberOfWorkers"){
				m_ret.numberOfWorkers=atoi(nodeContent.c_str());
				if (m_ret.numberOfWorkers<=0){
					Warning("GetReconControl","numberOfWorkers must be >0");
					m_ret.numberOfWorkers=1;
				}
			}

			else if (nodeName=="numberOfIterations"){
							m_ret.numberOfIterations=atoi(nodeContent.c_str());
							if (m_ret.numberOfIterations<=0){
								Warning("GetReconControl","numberOfIterations must be >0");
								m_ret.numberOfIterations=1;
							}
						}

			control = m_xml->GetNext(control);
		}
	}

	return m_ret;
}

vector<driver_struct> TXMLHandler::GetDrivers(){

	vector<driver_struct> m_ret;

	string name,content;
	int isGood=0;
	int isDriverGood=0;

	XMLNodePointer_t executeNode = this->GetUniqueNode("execute");
	XMLNodePointer_t driversNode = this->GetUniqueNode("drivers");
	XMLNodePointer_t execute=0;
	XMLNodePointer_t driver=0;
	XMLNodePointer_t child=0;
	XMLAttrPointer_t attr;
	if (executeNode == 0){
		Error("GetDrivers","No execute node");
		return m_ret;
	}
	if (driversNode == 0){
		Error("GetDrivers","No drivers node");
		return m_ret;
	}

	/*Now loop on execute*/
	execute = m_xml->GetChild(executeNode);
	if (execute==0){
		Error("GetDrivers","No entry in execute");
		return m_ret;
	}
	else{
		while (execute!=0){
			isGood=0;
			attr = m_xml->GetFirstAttr(execute);
			while (attr!=0) {
				name=string(m_xml->GetAttrName(attr));
				if (name=="name"){
					driver_struct m_driver={};
					m_driver.name=string(m_xml->GetAttrValue(attr));
					m_driver.className="";
					m_ret.push_back(m_driver);
					isGood=1;
					break;
				}
				else{
					attr = m_xml->GetNextAttr(attr);
				}
			}
			if (isGood==0){
				Error("TXMLHandler","TXMLHandler::GetDrivers Error, driver entry in execute is not well formed");
			}
			execute = m_xml->GetNext(execute);
		}
	}


	/*Now loop on drivers*/
	driver = m_xml->GetChild(driversNode);
	if (driver==0){
		Error("TXMLHandler","TXMLHandler::GetDrivers, no entry in drivers");
		m_ret.clear();
		return m_ret;
	}
	else{
		while (driver!=0){
			driver_struct m_driver={};
			isGood=0;
			attr = m_xml->GetFirstAttr(driver);
			while (attr!=0) {
				name=string(m_xml->GetAttrName(attr));
				if (name=="name"){
					m_driver.name=string(m_xml->GetAttrValue(attr));
					isGood++;

				}
				else if (name=="type"){
					m_driver.className=string(m_xml->GetAttrValue(attr));
					isGood++;

				}
				attr = m_xml->GetNextAttr(attr);	
			}
			if (isGood!=2){
				Error("TXMLHandler","TXMLHandler::GetDrivers Error, driver entry in drivers is not well formed");
				m_ret.clear();
				return m_ret;
			}

			child  = m_xml->GetChild(driver);
			while (child!=0){
				name = string(m_xml->GetNodeName(child));
				content = string(m_xml->GetNodeContent(child));
				m_driver.methodName.push_back(name);
				m_driver.methodParam.push_back(content);
				child = m_xml->GetNext(child);
			}
			isGood=0;
			//Now we need to check this driver has a matching execute entry 
			for (int qq=0;qq<m_ret.size();qq++){
				if (m_ret.at(qq).name==m_driver.name){
					m_ret.at(qq).className=m_driver.className;
					m_ret.at(qq).methodName=m_driver.methodName;
					m_ret.at(qq).methodParam=m_driver.methodParam;


					isGood=1;
					break;
				}
			}
			if (isGood!=1){
				Error("TXMLHandler","TXMLHandler::GetDrivers Error, driver entry %s does not match any execute entry",m_driver.name.c_str());
				m_ret.clear();
				return m_ret;
			}
			driver = m_xml->GetNext(driver);
		}
	}
	//Final check on entries
	for (int qq=0;qq<m_ret.size();qq++){
		if (m_ret.at(qq).className==""){
			Error("TXMLHandler","TXMLHandler::GetDrivers Error, execute entry %s does not match any driver entry",m_ret.at(qq).name.c_str());
			m_ret.clear();
			return m_ret;
		}
	}
	return m_ret;
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


