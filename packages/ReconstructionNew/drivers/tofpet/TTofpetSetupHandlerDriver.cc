/*
 * TTofpetSetupHandlerDriver.cc
 *
 *  Created on: Dec 11, 2015
 *      Author: celentan
 */

#include "TTofpetSetupHandlerDriver.hh"
#include "TofpetSetupHandler.hh"

TTofpetSetupHandlerDriver::TTofpetSetupHandlerDriver() {
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

	if (m_manager->isFirstIteration()){
		if (m_manager->getVerboseLevel() >  TJobManager::normalVerbosity()) Info("start","Iteration 0");
		if (m_source==TTofpetSetupHandlerDriver::txtFile){
			if (m_manager->getVerboseLevel() >  TJobManager::normalVerbosity()) Info("start","txt file: %s",m_fname.c_str());
				m_setupHandler
		}
	}
	else{
		if (m_manager->getVerboseLevel() >  TJobManager::normalVerbosity()) Info("start","Iteration: %i doing nothing",m_manager->getIterationN());
	}

	return 0;
}
