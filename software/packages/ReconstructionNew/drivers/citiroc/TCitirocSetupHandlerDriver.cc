/*
 * TCitirocSetupHandlerDriver.cc
 *
 *  Created on: Dec 11, 2015
 *      Author: celentan
 */

#include "TFile.h"


#include "TCitirocSetupHandlerDriver.hh"
#include "TCitirocSetupHandler.hh"
#include "TJobManager.hh"

TCitirocSetupHandlerDriver::TCitirocSetupHandlerDriver():
m_fname(""),m_setupHandler(0),m_source(0){
	// TODO Auto-generated constructor stub

}

TCitirocSetupHandlerDriver::~TCitirocSetupHandlerDriver() {
	// TODO Auto-generated destructor stub
}

/*This has to set the TCitirocSetupHandler in the inputList*/
/*There are 2 possibilities for the TCitirocSetupHandler:
 *
 * - Create a new one from a txt file
 * - Get one in a ROOT file
 *
 * Before, do a check to see if it is already in the input list.
 * Do this only at the first iteration, since the next ones will have it in the input list!
 */
int TCitirocSetupHandlerDriver::start(){
	TFile *m_file;
	if (m_manager->isFirstIteration()){
		if (m_manager->getVerboseLevel() >  TJobManager::normalVerbosity) Info("start","Iteration 0");


		if (m_manager->hasObject(TCitirocSetupHandler::Class())){
			Info("start()","TJobManager already has TCitirocSetupHandler object");
			return 0;
		}
		else if (m_source==TCitirocSetupHandlerDriver::txtFile){
			if (m_manager->getVerboseLevel() >  TJobManager::normalVerbosity) Info("start","txt file: %s",m_fname.c_str());
			if (m_fname.length()==0){
				Error("start","Set file name first");
				return -1;
			}
			else{
				m_setupHandler=new TCitirocSetupHandler(m_fname);
				m_manager->addObject(m_setupHandler);
			}
		}
		else if (m_source==TCitirocSetupHandlerDriver::rootFile){
			if (m_manager->getVerboseLevel() >  TJobManager::normalVerbosity) Info("start","root file: %s",m_fname.c_str());
			if (m_fname.length()==0){
				Error("start","Set file name first");
				return -1;
			}
			else{
				m_file=new TFile(m_fname.c_str());
				if (m_file->GetListOfKeys()->Contains("TCitirocSetupHandler")){
					m_setupHandler=(TCitirocSetupHandler*)m_file->Get("TCitirocSetupHandler");
					m_manager->addObject(m_setupHandler);
				}
				else{
					Error("start","No TCitirocSetupHandler found in ROOT file %s",m_fname.c_str());
				}
				m_file->Close();
			}
		}
	}
	else{
		if (m_manager->getVerboseLevel() >  TJobManager::normalVerbosity) Info("start","Iteration: %i doing nothing",m_manager->getIterationN());
	}

	return 0;
}
