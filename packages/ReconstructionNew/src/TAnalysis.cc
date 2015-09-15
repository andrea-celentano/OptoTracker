#include "TAnalysis.hh"
#include "TJobManager.hh"

#include "TProof.h"
#include "Cintex/Cintex.h"
#include <string>

using namespace std;

TAnalysis::TAnalysis():
				m_manager(0),m_chain(0),m_proof(0)
{
	m_fileName=new vector<string>;
	m_manager=new TJobManager();
	m_chain=new TChain("Event");
	ROOT::Cintex::Cintex::Enable();
	isConfigured=0;
}


TAnalysis::~TAnalysis(){
	delete m_fileName;
	delete m_manager;
	delete m_chain;
}
void TAnalysis::addFileToChain(std::string fname){
	m_chain->Add(fname.c_str());
}


void TAnalysis::addToInputList(TObject *obj){
	TList *input =	m_manager->GetInputList();
	if (!input){
		Warning("addToInputList","Error, input list is null. Create a new one");
		input = new TList();
		m_manager->SetInputList(input);
	}
	else if (!obj){
		Warning("addToInputList","Error, obj is null");
		return;
	}
	input->Add(obj);
}

void TAnalysis::configure(string xmlname){
	int doProof;
	int doProofDiag;


	m_manager->Config(xmlname);


	doProof=m_manager->getDoProof();
	doProofDiag=m_manager->getDoProofDiag();

	if (doProof){
		m_proof=TProof::Open(Form("workers=%i",m_manager->getNumberOfWorkers()));
		m_proof->Exec("gSystem->Load(\"libCintex\")");
		m_proof->Exec("ROOT::Cintex::Cintex::Enable()");
		m_proof->Exec("gSystem->Load(\"${OPTO}/lib/libCommonClassesDict.so\")");
		m_proof->Exec("gSystem->Load(\"${OPTO}/lib/libOpNoviceClassesDict.so\")");
		m_proof->Exec("gSystem->Load(\"${OPTO}/lib/libReconstructionNewClassesDict.so\")");
		m_proof->SetLogLevel(1, TProofDebug::kPacketizer);
		m_proof->SetParameter("PROOF_Packetizer", "TPacketizer");
		m_chain->SetProof();
		if (doProofDiag){
			m_proof->SetProgressDialog(kTRUE);
		}
		else{
			m_proof->SetProgressDialog(kFALSE);
		}
	}
	isConfigured=1;
}

void TAnalysis::run(){

	int iterationN;

	if (isConfigured==0){
		Error("run","Use configure before with a proper xml file");
		return;
	}
	if (m_chain->GetEntries()==0){
		Error("run","No entries to process");
		return;
	}
	TList *input,*output;
	TIter *inputIter,*outputIter;

	for (iterationN=0;iterationN<m_manager->getNumberOfIterations();iterationN++){
		Info("run","\n \n Starting reconstruction iteration %i",m_manager->getIterationN());
		m_chain->Process(m_manager,"",m_manager->getNumberOfEventsTBP(),m_manager->getSkipEvents());

		output=m_manager->GetOutputList();
		if (output) m_manager->SetInputList(output);

		if ( (m_manager->getVerboseLevel()>=TJobManager::normalVerbosity) && output){
			outputIter = new TIter(output);
			while (TObject *obj = outputIter->Next()) Info("run","Object %s is in next input",obj->GetName());
			delete outputIter;
		}

		m_manager->incrementIterationN();

	}

}


void TAnalysis::ParseCommandLine(int argc,char **argv){

	string variableName,variableValue;
	int found1,found2;
	for (int ii=1;ii<argc;ii++){
		variableName=string(argv[ii]);
		if (variableName.find("-s")!=std::string::npos){	/*Steering file*/
			Info("ParseCommandLine","steering file: %s",argv[ii+1]);
			steeringName=string(argv[ii+1]);
			ii++;
		}
		else if (variableName.find("-D")!=std::string::npos){ /*Variable, -DvarName=value*/
			found1=variableName.find("-D");
			variableName=variableName.substr(found1+2); /*We skipped the "-D"*/
			found2=variableName.find("=");
			variableValue=variableName.substr(found2+1);
			variableName=variableName.substr(0,found2);
			m_manager->setVariable(variableName,variableValue);
		}
		else {
			Info("ParseCommandLine","add file to chain: %s",argv[ii]);
			m_fileName->push_back(string(argv[ii]));
		}
	}


	this->configure(steeringName);
	for (int ii=0;ii<m_fileName->size();ii++){
		this->addFileToChain(m_fileName->at(ii));
	}
}



