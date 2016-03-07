/*
 * TMatrixInterpreterDriver.cc
 *
 *  Created on: Sep 23, 2015
 *      Author: celentan
 */

#include "TMatrixInterpreterDriver.hh"

#include "OpNoviceDigi.hh"
#include "TDriver.hh"
#include "TEvent.hh"
#include "TJobManager.hh"
#include "TDetector.hh"

#include "TH3D.h"


TMatrixInterpreterDriver::TMatrixInterpreterDriver() {
	// TODO Auto-generated constructor stub
	hVoxelRecon=0;

}

TMatrixInterpreterDriver::~TMatrixInterpreterDriver() {
	// TODO Auto-generated destructor stub
}


int TMatrixInterpreterDriver::startOfData(){
	return 0;
}

int TMatrixInterpreterDriver::process(TEvent *event){

	if (!event->hasObject("hVoxels")){
		Error("process","There is no hVoxels object in the event. Have you added the TMatrixReconDriver in the steering?");
		return 0;
	}
	hVoxelRecon=(TH3D*)event->getObject("hVoxels");
/*	hVoxelRecon->SetName(Form("h%i",m_manager->getEventN()));
	m_manager->GetOutputList()->Add(hVoxelRecon);
*/
	/*Here we need to do the "interpetation" of the voxels reconstruction*/

	return 0;
}
