#include "TJobManager.hh"
#include "TRootSaveDriver.hh"
#include "TFile.h"
#include "TList.h"
TRootSaveDriver::TRootSaveDriver():
m_fname("out.root"),m_fout(0){
	m_fname="out.root";
}

TRootSaveDriver::~TRootSaveDriver() {
}


void TRootSaveDriver::setOutFileName(const char* fname){
	this->m_fname=string(fname);
}

int TRootSaveDriver::end(){
	if (m_verboseLevel>=TJobManager::normalVerbosity) Info("end","end was called. File name is:%s",m_fname.c_str());

	/*Now save everything in the output list of the TJobManager.
	 * This method is called only on the client!
	 */

	TListIter *outputIter;
	if ((m_manager->isLastIteration()) && (m_manager->GetOutputList()!=0)){
		m_fout=new TFile(m_fname.c_str(),"RECREATE");
		m_fout->cd();
		outputIter=new TListIter(m_manager->GetOutputList());
		if (m_verboseLevel>=TJobManager::normalVerbosity) Info("end","There are %i object in output list",m_manager->GetOutputList()->GetEntries());
		while (TObject *obj=outputIter->Next()){
			obj->Write();
			if (m_verboseLevel>=TJobManager::normalVerbosity){
				Info("end","Writing to file object: %s",obj->GetName());
			}
		}
	}
	else if (m_manager->isLastIteration()==0){
		if (m_verboseLevel>=TJobManager::normalVerbosity){
			Info("end","This is not the last iteration, doing nothing");
		}
	}
}
