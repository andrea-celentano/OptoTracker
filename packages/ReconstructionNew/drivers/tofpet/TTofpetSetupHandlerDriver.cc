/*
 * TTofpetSetupHandlerDriver.cc
 *
 *  Created on: Dec 11, 2015
 *      Author: celentan
 */

#include "TFile.h"


#include "TTofpetSetupHandlerDriver.hh"
#include "TofpetSetupHandler.hh"
#include "TJobManager.hh"

TTofpetSetupHandlerDriver::TTofpetSetupHandlerDriver():
m_fname(""),m_setupHandler(0){
	// TODO Auto-generated constructor stub

}

TTofpetSetupHandlerDriver::~TTofpetSetupHandlerDriver() {
	// TODO Auto-generated destructor stub
}

/*This has to set the TTofpetSetupHandler in the inputList*/
/*There are 2 possibilities for the TTopfetSetupHandler:
 *
 * - Create a new one from a txt file
 * - Get one in a ROOT file
 *
 * Before, do a check to see if it is already in the input list.
 * Do this only at the first iteration, since the next ones will have it in the input list!
 */
int TTofpetSetupHandlerDriver::start(){
	TFile *m_file;
	if (m_manager->isFirstIteration()){
		if (m_manager->getVerboseLevel() >  TJobManager::normalVerbosity) Info("start","Iteration 0");


		if (m_manager->hasObject(TofpetSetupHandler::Class())){
			return 0;
		}
		else if (m_source==TTofpetSetupHandlerDriver::txtFile){
			if (m_manager->getVerboseLevel() >  TJobManager::normalVerbosity) Info("start","txt file: %s",m_fname.c_str());
			if (m_fname.length()==0){
				Error("start","Set file name first");
				return -1;
			}
			else{
				m_setupHandler=new TofpetSetupHandler(m_fname);
				m_manager->addObject(m_setupHandler);
			}
		}
		else if (m_source==TTofpetSetupHandlerDriver::rootFile){
			if (m_manager->getVerboseLevel() >  TJobManager::normalVerbosity) Info("start","root file: %s",m_fname.c_str());
			if (m_fname.length()==0){
				Error("start","Set file name first");
				return -1;
			}
			else{
				m_file=new TFile(m_fname.c_str());
				if (m_file->GetListOfKeys()->Contains("TofpetSetupHandler")){
					m_setupHandler=(TofpetSetupHandler*)m_file->Get("TofpetSetupHandler");
					m_manager->addObject(m_setupHandler);
				}
				else{
					Error("start","No TofpetSetupHandler found in ROOT file %s",m_fname.c_str());
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
