#include "TRealSetupHandler.hh"

using namespace std;

TRealSetupHandler::TRealSetupHandler() :
		nRealDet(0)
{
	cout<<"RealSetupHandler::default constructor"<<endl;
}

TRealSetupHandler::TRealSetupHandler(string fname) :
		nRealDet(0)
{
	cout<<"RealSetupHandler::file constructor"<<endl;
	ifstream file;
	string line;
	file.open(fname.c_str());
	if (!file){
		cerr<<"RealSetupHandler::file not found "<<fname<<endl;
	}
	else{
		while(!file.eof()){
			getline (file,line);
			if (line.size()==0) continue;
			this->processLine(line);
		}
	}
	file.close();
}

void TRealSetupHandler::processLine(string line){
	Info("processLine","called with line: %s",line.c_str());
	istringstream parser;
	string key,data;
	pair < int , int > facedet;
	parser.str(line);
	parser>>key;
	if (key[0]=='#') return; //comment
	if (key=="Detector"){
		nRealDet++;
		parser>>data;m_thisRealDetID=atoi(data.c_str());
		parser>>data;m_thisReconFace=atoi(data.c_str());
		parser>>data;m_thisReconDetID=atoi(data.c_str());
		m_reconstructionDetFace.insert(pair<int,int>(m_thisRealDetID,m_thisReconFace));
		m_reconstructionDetID.insert(pair<int,int>(m_thisRealDetID,m_thisReconDetID));
		facedet=make_pair(m_thisReconFace,m_thisReconDetID);
		m_reconstructionRealDet[facedet].push_back(m_thisRealDetID); //the [] creates a new empty vector if key does not exists
	}
	else if (key=="Pixel"){
		parser>>data;m_thisPixel=atoi(data.c_str());
		parser>>data;m_thisGainEntry=atoi(data.c_str());
		parser>>data;m_thisGainVal=atof(data.c_str());//gain
		switch (m_thisGainEntry){
		case 1:
			m_PixelGain1[m_thisReconFace][m_thisReconDetID][m_thisPixel]=m_thisGainVal;
			break;
		case 2:
			m_PixelGain2[m_thisReconFace][m_thisReconDetID][m_thisPixel]=m_thisGainVal;
			break;
		case 3:
			m_PixelGain3[m_thisReconFace][m_thisReconDetID][m_thisPixel]=m_thisGainVal;
			break;
		default:
			cerr<<"Error RealSetupHandler setup, gain id "<<m_thisGainEntry<<"is invalid"<<endl;
			return;
		}
	}
	else if (key=="Pixels"){
		parser>>data;m_thisPixelFirst=atoi(data.c_str());
		parser>>data;m_thisPixelLast=atoi(data.c_str());
		parser>>data;m_thisGainEntry=atoi(data.c_str());
		parser>>data;m_thisGainVal=atof(data.c_str());
		for (int ipixel=m_thisPixelFirst;ipixel<=m_thisPixelLast;ipixel++){
			switch (m_thisGainEntry){
			case 1:
				m_PixelGain1[m_thisReconFace][m_thisReconDetID][ipixel]=m_thisGainVal;
				break;
			case 2:
				m_PixelGain2[m_thisReconFace][m_thisReconDetID][ipixel]=m_thisGainVal;
				break;
			case 3:
				m_PixelGain3[m_thisReconFace][m_thisReconDetID][ipixel]=m_thisGainVal;
				break;
			default:
				cerr<<"Error RealSetupHandler setup, gain id "<<m_thisGainEntry<<"is invalid"<<endl;
				return;
			}
		}
	}
}

int    TRealSetupHandler::getReconstructionDetectorFace(int idet){
	int ret=-1;
	std::map<int,int>::iterator it;
	it = m_reconstructionDetFace.find(idet);
	if (it!=m_reconstructionDetFace.end()){
		ret = it->second;
	}
	else{
		cerr<<"Error RealSetupHandler::getReconstructionDetectorFace for det id: "<<idet<<endl;
	}
	return ret;
}

int     TRealSetupHandler::getReconstructionDetectorID(int idet){  
	int ret=-1;
	std::map<int,int>::iterator it;
	it = m_reconstructionDetID.find(idet);
	if (it!=m_reconstructionDetID.end()){
		ret = it->second;
	}
	else{
		cerr<<"Error RealSetupHandler::getReconstructionDetectorID for det id: "<<idet<<endl;
	}
	return ret;

}

vector <int> & TRealSetupHandler::getRealDetectorID(int iface,int idet){
	pair <int,int> facedet(iface,idet);
	vector<int> retTmp;
	std::map<pair<int,int>,vector <int>>::iterator it;
	it=m_reconstructionRealDet.find(facedet);
	if (it!=m_reconstructionRealDet.end()){
		return it->second;
	}
	else{
		cerr<<"Error RealSetupHandler::getRealDetectorID for face / id: "<<iface<<" "<<idet<<endl;
		return retTmp;
	}
}


double TRealSetupHandler::getPixelGain(int iface,int idetector, int ipixel,int igain){
	double ret=-1;
	std::map<int,double>::iterator it;
	switch (igain){
	case 1:
		it = m_PixelGain1[iface][idetector].find(ipixel);
		if (it!=m_PixelGain1[iface][idetector].end()){
			ret = it->second;
		}
		else ret=1;
		break;
	case 2:
		it = m_PixelGain2[iface][idetector].find(ipixel);
		if (it!=m_PixelGain2[iface][idetector].end()){
			ret = it->second;
		}
		else ret=1;
		break;
	case 3:
		it = m_PixelGain3[iface][idetector].find(ipixel);
		if (it!=m_PixelGain3[iface][idetector].end()){
			ret = it->second;
		}
		else ret=1;
		break;
	case 0:
		ret=(this->getPixelGain(iface,idetector,ipixel,1))*(this->getPixelGain(iface,idetector,ipixel,2))*(this->getPixelGain(iface,idetector,ipixel,3));
		break;
	}
	return ret;
}

void TRealSetupHandler::setPixelGain(int iface,int idetector, int ipixel,int igain,double val){

	std::pair <int,double> par(ipixel,val);
	switch (igain){
	case 1:
		m_PixelGain1[iface][idetector].insert(par);
		break;
	case 2:
		m_PixelGain2[iface][idetector].insert(par);
		break;
	case 3:
		m_PixelGain3[iface][idetector].insert(par);
		break;

	default:
		Error("setPixelGain","Error in RealSetupHandler::setPixelGain. igain must be 1,2,3");
		break;
	}
}



void TRealSetupHandler::Print(int printPixels){

	std::map<int,int>::iterator itDet,itFace;
	int iReconDetID,iReconDetFace,iDet,tmp;
	vector<int> iDet2;





	const char separator    = ' ';
	const int Width     = 20;

	itDet=m_reconstructionDetID.begin();
	itFace=m_reconstructionDetFace.begin();

	if (!printPixels){
		cout<<endl;
		cout<<left<<setw(Width)<<setfill(separator)<<"RealDetID";
		cout<<left<<setw(Width)<<setfill(separator)<<"ReconDetFace";
		cout<<left<<setw(Width)<<setfill(separator)<<"ReconDetID";
		cout<<left<<setw(Width)<<setfill(separator)<<"RetrievRealDetId";
		cout<<endl;
	}
	for (;itDet!=m_reconstructionDetID.end();itDet++){
		iDet=itDet->first;
		if (itDet->first != itFace->first){
			cerr<<"Error in RealSetupHandler::printRealSetup, something wrong with the mapping"<<endl;
			return;
		}
		iReconDetFace=itFace->second;
		iReconDetID=itDet->second;
		iDet2=this->getRealDetectorID(iReconDetFace,iReconDetID);
		if (printPixels){
			cout<<endl;
			cout<<left<<setw(Width)<<setfill(separator)<<"RealDetID";
			cout<<left<<setw(Width)<<setfill(separator)<<"ReconDetFace";
			cout<<left<<setw(Width)<<setfill(separator)<<"ReconDetID";
			cout<<left<<setw(Width)<<setfill(separator)<<"RetrievRealDetId1";
			cout<<left<<setw(Width)<<setfill(separator)<<"RetrievRealDetId2";
			cout<<left<<setw(Width)<<setfill(separator)<<"RetrievRealDetId3";
			cout<<left<<setw(Width)<<setfill(separator)<<"RetrievRealDetId4";
			cout<<endl;
		}

		cout<<left<<setw(Width)<<setfill(separator)<<iDet;
		cout<<left<<setw(Width)<<setfill(separator)<<iReconDetFace;
		cout<<left<<setw(Width)<<setfill(separator)<<iReconDetID;
		tmp=iDet2[0];
		cout<<left<<setw(Width)<<setfill(separator)<<tmp;
		if (iDet2.size()>=2) tmp=iDet2[1]; else tmp=-1;
		cout<<left<<setw(Width)<<setfill(separator)<<tmp;
		if (iDet2.size()>=3) tmp=iDet2[2]; else tmp=-1;
		cout<<left<<setw(Width)<<setfill(separator)<<tmp;
		if (iDet2.size()>=4) tmp=iDet2[3]; else tmp=-1;
		cout<<left<<setw(Width)<<setfill(separator)<<tmp;


		cout<<endl;
		cout<<endl;
		if (printPixels){
			this->PrintPixels(iReconDetFace,iReconDetID);
		}

		itFace++;
	}
}


void TRealSetupHandler::PrintPixels(int iface,int idetector){

	std::map<int,double>::iterator itGain1,itGain2,itGain3;

	const char separator    = ' ';
	const int Width     = 15;


	double gain1,gain2,gain3,gain;
	itGain1=m_PixelGain1[iface][idetector].begin();
	itGain2=m_PixelGain2[iface][idetector].begin();
	itGain3=m_PixelGain3[iface][idetector].begin();

	cout<<endl<<"Pixels for face/detector: "<<iface<<" "<<idetector<<endl;

	cout<<left<<setw(Width)<<setfill(separator)<<"Pixel";
	cout<<left<<setw(Width)<<setfill(separator)<<"Gain1";
	cout<<left<<setw(Width)<<setfill(separator)<<"Gain2";
	cout<<left<<setw(Width)<<setfill(separator)<<"Gain3";
	cout<<left<<setw(Width)<<setfill(separator)<<"GainTOT";
	cout<<endl;
	for (;itGain1!=m_PixelGain1[iface][idetector].end();itGain1++){
		gain1=itGain1->second;

		itGain2=m_PixelGain2[iface][idetector].find(itGain1->first);
		if (itGain2!=m_PixelGain2[iface][idetector].end()){
			gain2=itGain2->second;
		}
		else{
			gain2=1;
		}

		itGain3=m_PixelGain3[iface][idetector].find(itGain1->first);
		if (itGain3!=m_PixelGain3[iface][idetector].end()){
			gain3=itGain3->second;
		}
		else{
			gain3=1;
		}

		gain=this->getPixelGain(iface,idetector,itGain1->first);

		cout<<left<<setw(Width)<<setfill(separator)<<itGain1->first;
		cout<<left<<setw(Width)<<setfill(separator)<<gain1;
		cout<<left<<setw(Width)<<setfill(separator)<<gain2;
		cout<<left<<setw(Width)<<setfill(separator)<<gain3;
		cout<<left<<setw(Width)<<setfill(separator)<<gain;
		cout<<endl;
	}
	cout<<endl;
}
