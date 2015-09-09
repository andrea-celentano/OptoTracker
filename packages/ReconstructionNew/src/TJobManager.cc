#include "TJobManager.hh"
#include "TDriver.hh"
#include "TEvent.hh"
#include "CommonStructures.hh"


#include "TClass.h"
#include "TMethod.h"
#include "TMethodArg.h"
#include "TMethodCall.h"



TJobManager::TJobManager(TTree* tree):
fTree(tree),b_event(0),m_event(0),m_xmlHandler(0),m_drivers(0)
{
	m_drivers=new vector<TDriver*>;
	m_eventN=0;
	m_doProof=0;
	m_doProofDiag=0;
	m_skipEvents=0;
	m_numberOfEvents=TChain::kBigNumber;
	m_verboseLevel=0;
	m_dryRun=0;
	m_numberOfWorkers=1;

	m_iterationN=0;
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
}


void TJobManager::SlaveBegin(TTree* /*tree*/)
{
	Info("SlaveBegin","start");
	m_eventN=0;
	/*We need to init each driver*/
	for (int ii=0;ii<m_drivers->size();ii++){
		m_drivers->at(ii)->startOfData();
	}

}



void TJobManager::SlaveTerminate()
{
	Info("SlaveTerminate","start");
}



void TJobManager::Terminate()
{
	Info("Terminate","start");
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


	Info("Config","Done");
}

void TJobManager::ConfigControl(const reconControl_struct &reconControl){
	this->setDryRun(reconControl.dryRun);
	this->setNumberOfEvents(reconControl.numberOfEvents);
	this->setSkipEvents(reconControl.skipEvents);
	this->setDoProof(reconControl.doProof);
	this->setDoProofDiag(reconControl.doProofDiag);
	this->setVerboseLevel(reconControl.verboseLevel);
	this->setNumberOfWorkers(reconControl.numberOfWorkers);
	Info("ConfigControl","Done");

}
void TJobManager::ConfigDrivers(const vector<driver_struct> &driver_list){

	TDriver *driver;
	TClass *driverClass;
	TMethod *classMethod;
	TMethodCall *classMethodCall;
	string name,className;
	string amethodName,amethodParam;
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
			/*Here we set some common driver parameters*/
			driver->setVerboseLevel(m_verboseLevel);
			driver->setIterationN(m_iterationN);
			/*Go with methods*/
			for (int imethod=0;imethod<driver_list.at(ii).methodName.size();imethod++){
				amethodName=driver_list.at(ii).methodName.at(imethod);
				amethodParam=driver_list.at(ii).methodParam.at(imethod);
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




