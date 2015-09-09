#include "TAnalysis.hh"
#include "TJobManager.hh"

#include "TProof.h"
#include "Cintex/Cintex.h"
#include <string>

using namespace std;

TAnalysis::TAnalysis():
		m_manager(0),m_chain(0),m_proof(0)
{
	m_manager=new TJobManager();
	m_chain=new TChain("Event");
	ROOT::Cintex::Cintex::Enable();
	isConfigured=0;
}


TAnalysis::~TAnalysis(){
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
	TList *input,*output;
	TIter *inputIter,*outputIter;

	for (iterationN=0;iterationN<m_manager->getNumberOfIterations();iterationN++){
		Info("run","\n \n Starting reconstruction iteration %i",m_manager->getIterationN());
		m_chain->Process(m_manager,"",m_manager->getNumberOfEvents(),m_manager->getSkipEvents());

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


