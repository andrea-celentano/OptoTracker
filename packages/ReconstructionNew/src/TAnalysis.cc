#include "TAnalysis.hh"
#include "TJobManager.hh"
#include "TDetectorLight.hh"

#include "TProof.h"
#include "TFile.h"
#include "TKey.h"
#include "Cintex/Cintex.h"
#include <string>



using namespace std;

TAnalysis::TAnalysis():
				m_manager(0),m_chain(0),m_proof(0)
{
	m_fileName=new vector<string>;
	m_manager=new TJobManager();
	m_chain=new TChain("Event");

	m_detName="";
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
	int detFound=0;
	TFile *fTMP;


	/*Configure the manager*/
	m_manager->Config(xmlname);
	doProof=m_manager->getDoProof();
	doProofDiag=m_manager->getDoProofDiag();
	if (m_manager->getVerboseLevel()>=TJobManager::normalVerbosity){
		Info("configure","TJobManager has been configured");
	}
	if ((!m_manager->isProofCompatible())&&(doProof)){
		doProof=0;
		if (m_manager->getVerboseLevel()>=TJobManager::minimalVerbosity){
			Info("configure","Not proof compatible, switching PROOF off");
		}
	}

	if (doProof){
		m_proof=TProof::Open(Form("workers=%i",m_manager->getNumberOfWorkers()));
		m_proof->Exec("gSystem->Load(\"libCintex\")");
		m_proof->Exec("ROOT::Cintex::Cintex::Enable()");
		m_proof->Exec("gSystem->Load(\"${OPTO}/lib/libCommonClassesDict.so\")");
		m_proof->Exec("gSystem->Load(\"${OPTO}/lib/libTofpetClassesDict.so\")");
		m_proof->Exec("gSystem->Load(\"${OPTO}/lib/libOpNoviceClassesDict.so\")");
		m_proof->Exec("gSystem->Load(\"${OPTO}/lib/libMarocClassesDict.so\")");
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


	/*If the detector was specified via filename, set it*/
	if (m_detName.length()!=0){
		m_manager->setDetector(new TDetectorLight(m_detName));
	}
	/*Otherwise, check the detector existance*/
	else{
		for (int ii=0;ii<m_fileName->size();ii++){
			fTMP=new TFile((m_fileName->at(ii)).c_str());
			if (fTMP->GetListOfKeys()->Contains("TDetectorLight")){
				Info("configure","Detector found in file %s",(m_fileName->at(ii)).c_str());
				m_manager->setDetector((TDetectorLight*)fTMP->Get("TDetectorLight"));
				if (m_manager->getVerboseLevel()>=TJobManager::normalVerbosity){
					((TDetectorLight*)fTMP->Get("TDetectorLight"))->Print();
				}
				fTMP->Close();
				detFound=1;
				delete fTMP;
				break;
			}
			fTMP->Close();
			delete fTMP;
		}
		if (!detFound){
			Error("configure","No detector found in any file, and no txt file passed with -det option");
			exit(1);
		}
	}

	/*Add all the objects found in the files, but the TTree and the TDetectorLight, to the inputList*/
	for (int ii=0;ii<m_fileName->size();ii++){
		fTMP=new TFile((m_fileName->at(ii)).c_str());
		TIter next (fTMP->GetListOfKeys());
		TKey *key;
		while ((key = (TKey*)next())) {
			if (string(key->GetClassName())=="TTree") continue;
			else if (string(key->GetClassName())=="TChain") continue;
			else if (string(key->GetClassName())=="TDetectorLight") continue;
			else {
				this->addToInputList(fTMP->Get(key->GetName()));
				if (m_manager->getVerboseLevel()>TJobManager::normalVerbosity){
					Info("configure","Object found in TFile and added to input list. Class: %s Name: %s",key->GetClassName(),key->GetName());
				}
			}

			/*if (strstr(key->GetClassName(),"TH1")) {
					         printf (" key : %s is a %s in %s\n",
					                 key->GetName(),key->GetClassName(),dir->GetPath());
					      }
					      if (!strcmp(key->GetClassName(),"TDirectory")) {
					         dir->cd(key->GetName());
					         TDirectory *subdir = gDirectory;
					         loopdir(subdir);
					         dir->cd();
					      }*/
		}

		fTMP->Close();
		delete fTMP;
	}


	/*Add the files to the chain,*/
	for (int ii=0;ii<m_fileName->size();ii++){
		this->addFileToChain(m_fileName->at(ii));
	}



	isConfigured=1;
}

void TAnalysis::run(){

	int iterationN;
	TList *input,*output;
	TIter *inputIter,*outputIter;
	if (isConfigured==0){
		Error("run","Use configure before with a proper xml file");
		return;
	}
	if (m_chain->GetEntries()==0){
		Error("run","No entries to process");
		return;
	}

	/*I guarantee that the number of events we ask to process is <= that the number of events in the chain.
	 * Proof can do this automatically, but I can't get any longer the number of actually processed events
	 */
	if (iterationN==0){
		if (m_chain->GetEntries() <= m_manager->getNumberOfEvents()) m_manager->setNumberOfEvents(m_chain->GetEntries());
	}
	for (iterationN=0;iterationN<m_manager->getNumberOfIterations();iterationN++){
		Info("run","\n \n Starting reconstruction iteration %i",m_manager->getIterationN());
		m_chain->Process(m_manager,"",m_manager->getNumberOfEvents(),m_manager->getSkipEvents());

		output=m_manager->GetOutputList();
		if (output) m_manager->SetInputList(output);

		if ( (m_manager->getVerboseLevel()>=TJobManager::normalVerbosity) && output){
			outputIter = new TIter(output);
			Info("run","List of next inputs");
			while (TObject *obj = outputIter->Next()) Info("run","Object %s is in next input",obj->GetName());
			delete outputIter;
		}
		Info("run","\n \n Ended reconstruction iteration %i",m_manager->getIterationN());
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
			m_steeringName=string(argv[ii+1]);
			ii++;
		}
		else if (variableName.find("-det")!=std::string::npos){ /*Detector file name (txt format)*/
			Info("ParseCommandLine","detector name: %s",argv[ii+1]);
			m_detName=string(argv[ii+1]);
			ii++; //need to force skipping
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


	this->configure(m_steeringName);

}



