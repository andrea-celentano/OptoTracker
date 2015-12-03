#include <iostream>
#include <string>
#include <vector>
#include <sstream>

#include "TJobManager.hh"
#include "TDriver.hh"
#include "TEvent.hh"
#include "CommonStructures.hh"

#include "TList.h"
#include "TClass.h"
#include "TMethod.h"
#include "TMethodArg.h"
#include "TMethodCall.h"

using namespace std;

TJobManager::TJobManager(TTree* tree):
												fTree(tree),b_event(0),m_event(0),m_xmlHandler(0),m_drivers(0)
{
	m_drivers=new vector<TDriver*>;
	m_variables=new map < string, string>;
	m_eventN=0;
	m_doProof=0;
	m_doProofDiag=0;
	m_skipEvents=0;
	m_numberOfEvents=TChain::kBigNumber;
	m_verboseLevel=0;
	m_dryRun=0;
	m_numberOfWorkers=1;
	m_numberOfIterations=1;
	m_iterationN=0;
	m_detector=0;
	m_isProofCompatible=1;
	m_detectorUtils=0;

	m_randomGenerator=new TRandom3(0); ///TODO: use a proper seed
	Info("TOptoJobManager","Done");
}


TJobManager::~TJobManager()
{
	/*if (fTree) delete fTree;
	if (b_event) delete b_event;
	if (m_event) delete m_event;*/

	//if (m_xml) delete m_xml;
	Info("~TOptoJobManager","Done");

}
void TJobManager::Init(TTree *tree)
{
	// The Init() function is called when the selector needs to initialize
	// a new tree or chain. Typically here the branch addresses and branch
	// pointers of the tree will be set.
	// It is normally not necessary to make changes to the generated
	// code, but the routine can be extended by the user if needed.
	// Init() will be called many times when running on PROOF
	// (once per file to be processed).

	Info("Init","Start");
	// Set object pointers
	b_event = 0;
	m_event = 0;
	// Set branch addresses and branch pointers
	if (!tree) return;
	fTree = tree;
	//fTree->SetMakeClass(1);

	if(fTree->GetListOfBranches()->FindObject("Event")){
		fTree->SetBranchAddress("Event", &m_event, &b_event);
	}
	m_event->Clear("C");


	Info("Init","Done");
}

Bool_t TJobManager::Notify()
{
	// The Notify() function is called when a new file is opened. This
	// can be either for a new TTree in a TChain or when when a new TTree
	// is started when using PROOF. It is normally not necessary to make changes
	// to the generated code, but the routine can be extended by the
	// user if needed. The return value is currently not used.

	return kTRUE;
}



void TJobManager::Begin(TTree* /*tree*/)
{
	Info("Begin","start");
	/*We need to start each driver on the client*/
	for (int ii=0;ii<m_drivers->size();ii++){
		m_drivers->at(ii)->start();
	}
}


void TJobManager::SlaveBegin(TTree* /*tree*/)
{
	Info("SlaveBegin","start");
	m_detectorUtils=new TDetectorUtils(m_detector); //since each slave needs its own
	m_eventN=0;
	/*We need to init each driver on the workers*/
	for (int ii=0;ii<m_drivers->size();ii++){
		m_drivers->at(ii)->startOfData();
	}
}



void TJobManager::SlaveTerminate()
{

	Info("SlaveTerminate","start");
	/*We need to end each driver on the workers*/
	for (int ii=0;ii<m_drivers->size();ii++){
		m_drivers->at(ii)->endOfData();
	}



}



void TJobManager::Terminate()
{
	Info("Terminate","start");
	/*First, I copy all the objects from the input list to the output list*/
	TIter *inputIter=new TIter(fInput);
	while (TObject *obj=inputIter->Next()){
		fOutput->Add(obj);
	}
	/*Then I need to end each driver on the client*/
	/*Note that in this way the drivers will see everything in the input list+output list*/
	/*This is usefull for example for the TRootSave driver, that can save everything!*/
	for (int ii=0;ii<m_drivers->size();ii++){
		m_drivers->at(ii)->end();
	}
}






Bool_t  TJobManager::Process(Long64_t entry){
	m_event->Clear("C");
	fTree->GetEntry(entry);
	/*We need to process each driver*/
	for (int ii=0;ii<m_drivers->size();ii++){
		m_drivers->at(ii)->process(m_event);
	}
	m_eventN++;
}


/*This method is supposed to be called at the BEGINNING of the analysis, on the master, before the "process"*/
void	TJobManager::Config(string fname){

	m_xmlHandler=new TXMLHandler(fname);

	reconControl_struct reconControl=m_xmlHandler->GetReconControl();
	vector<driver_struct> driver_list=m_xmlHandler->GetDrivers();

	this->ConfigControl(reconControl);
	this->ConfigDrivers(driver_list);

	/*Check if drivers are Proof-compatible*/
	for (int ii=0;ii<m_drivers->size();ii++){
		if (!m_drivers->at(ii)->isProofCompatible()) {
			m_isProofCompatible=0;
			if (m_verboseLevel>=TJobManager::normalVerbosity){
				Info("Config","Driver %s not PROOF compatible",m_drivers->at(ii)->GetName());
			}
			break; //Do not neeed to check all, if one is not compatible we are not.
		}
	}
	Info("Config","Done");
}

void TJobManager::ConfigControl(const reconControl_struct &reconControl){
	this->setDryRun(reconControl.dryRun);
	this->setNumberOfEvents(reconControl.numberOfEventsTBP);
	this->setSkipEvents(reconControl.skipEvents);
	this->setDoProof(reconControl.doProof);
	this->setDoProofDiag(reconControl.doProofDiag);
	this->setVerboseLevel(reconControl.verboseLevel);
	this->setNumberOfWorkers(reconControl.numberOfWorkers);
	this->setNumberOfIterations(reconControl.numberOfIterations);
	Info("ConfigControl","Done");

}
void TJobManager::ConfigDrivers(const vector<driver_struct> &driver_list){

	TDriver *driver;
	TClass *driverClass;
	TMethod *classMethod;
	TMethodCall *classMethodCall;
	string name,className;
	string amethodName,amethodParam;
	string variableName,variableValue;
	for (int ii=0;ii<driver_list.size();ii++){
		driverClass=0;

		name=driver_list.at(ii).name;
		className=driver_list.at(ii).className;

		driverClass=TClass::GetClass(className.c_str());
		if (driverClass==0){
			Error("ConfigDrivers","Error, driver class %s not in ROOT dictionary. Skip",className.c_str());
			continue;
		}
		driver=(TDriver*)driverClass->New();
		if (driver==0){
			Error("ConfigDrivers","Error, driver class %s can't be created",className.c_str());
			continue;
		}
		else{
			/*We created the class. */
			driver->setName(name);
			driver->setManager(this);
			Info("ConfigDrivers","Configure driver %s class %s",name.c_str(),className.c_str());
			/*Here we set some common driver parameters*/
			driver->setVerboseLevel(m_verboseLevel);
			driver->setIterationN(m_iterationN);
			/*Go with methods*/
			for (int imethod=0;imethod<driver_list.at(ii).methodName.size();imethod++){
				amethodName=driver_list.at(ii).methodName.at(imethod);
				amethodParam=driver_list.at(ii).methodParam.at(imethod);
				/*Here I need to check if the methodParam is a variable from command line*/
				if(amethodParam[0]=='$'){ /*This is a variable*/
					variableName=amethodParam.substr(1);
					if (this->hasVariable(variableName)){
						variableValue=this->getVariable(variableName);
						amethodParam=variableValue;
					}
					else{
						Error("ConfigDrivers","Variable %s in steering file not exists",variableName.c_str());
						exit(1);
					}

				}

				Info("ConfigDrivers","Try to call method name %s with param %s on class %s",amethodName.c_str(),amethodParam.c_str(),className.c_str());
				classMethod=0;
				classMethod=driverClass->GetMethod(amethodName.c_str(),amethodParam.c_str());                         //Use "GetMethod" to also search in base class (TDriver, TObject)
				if (classMethod==0){
					Error("ConfigDrivers","Error, driver class %s does not have any matching methods name: %s param: %s",className.c_str(),amethodName.c_str(),amethodParam.c_str());
					continue;
				}
				else{
					classMethodCall=0;
					classMethodCall=new TMethodCall(driverClass,amethodName.c_str(),amethodParam.c_str());
					classMethodCall->Execute((void *)driver);
					Info("ConfigDrivers","Method %s called",amethodName.c_str());
				}

			}
			m_drivers->push_back(driver);
		}
	}
	Info("ConfigDrivers","Done");
}



TDriver* TJobManager::getDriver(int id){
	if (m_drivers==0){
		Error("getDriver","m_drivers is null");
		return 0;
	}
	if (id<m_drivers->size()){
		Error("getDriver","driver id is larger than drivers size");
		return 0;
	}
	return m_drivers->at(id);
}


void TJobManager::setVariable(string name, string value) {
	map<string,string>::iterator it;
	it = m_variables->find(name);
	if (it!=m_variables->end()){ //This wariable is already here
		Warning("setVariable","Variable %s already exists with value %d. Setting it at %s",name.c_str(),it->second,value.c_str());
		m_variables->at(name)=value;
	}
	else{
		Info("setVariable","Setting variable %s at value %s",name.c_str(),value.c_str());
		m_variables->insert(std::make_pair(name,value));
	}

}

int TJobManager::hasVariable(string name) const{
	map<string,string>::const_iterator it;
	it = m_variables->find(name);
	if (it==m_variables->end()){
		return 0;
	}
	else{
		return 1;
	}
}

string TJobManager::getVariable(string name) const{
	map<string,string>::const_iterator it;
	it = m_variables->find(name);
	if (it==m_variables->end()){
		Warning("getVariable","Variable %s does not exists",name);
		return "";
	}
	else{
		return it->second;
	}
}

void TJobManager::printVariables() const{
	map<string,string>::const_iterator it;
	Info("printVariables","Registered variables");
	for (it=m_variables->begin();it!=m_variables->end();it++){
		cout<<it->first<<" "<<it->second<<endl;
	}
}


