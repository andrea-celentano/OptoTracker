#include "TMatrixAnalysisDriver.hh"

#include "OpNoviceDigi.hh"
#include "TDriver.hh"
#include "TEvent.hh"
#include "TJobManager.hh"

TMatrixAnalysisDriver::TMatrixAnalysisDriver() {
	// TODO Auto-generated constructor stub

}

TMatrixAnalysisDriver::~TMatrixAnalysisDriver() {
	// TODO Auto-generated destructor stub
}

int TMatrixAnalysisDriver::process(TEvent *event){

	TClonesArray *digiCollection;
	TIter		 *digiCollectionIter;
	OpNoviceDigi *digi;

	int face,detector,nPhe;

	if (event->hasCollection(OpNoviceDigi::Class(),"DetDigiMC")){
		digiCollection=event->getCollection(OpNoviceDigi::Class(),"DetDigiMC");
		digiCollectionIter=new TIter(digiCollection);
		while (digi = (OpNoviceDigi*)digiCollectionIter->Next()){
			face=digi->GetFaceNumber();
			detector=digi->GetDetectorNumber();
			nPhe=digi->GetPheCount();
			//cout<<face<<" "<<detector<<" "<<nPhe<<endl;
		}
	}


}

int TMatrixAnalysisDriver::start(){

}
int TMatrixAnalysisDriver::end(){
	Info("end","ended");
	cout<<m_manager->getNumberOfEventsProcessed()<<endl;
}
