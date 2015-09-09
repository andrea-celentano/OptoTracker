#include "TEventMarkerDriver.hh"

#include "TDriver.hh"
#include "TEvent.hh"
#include "TJobManager.hh"
TEventMarkerDriver::TEventMarkerDriver():
m_interval(1)
{

}

TEventMarkerDriver::~TEventMarkerDriver() {
	// TODO Auto-generated destructor stub
}




int TEventMarkerDriver::process(TEvent* event) {
	int eventN=m_manager->getEventN();
	if (eventN%m_interval==0){
		cout<<"Processing event "<<eventN<<endl;
	}
}





