#include "TCitirocSetupHandler.hh"
#include <fstream>


TCitirocSetupHandler::TCitirocSetupHandler():
TRealSetupHandler()
{
	cout<<"CitirocSetupHandler default constructor"<<endl;
}


TCitirocSetupHandler::TCitirocSetupHandler(std::string fname)
{
	cout<<"CitirocSetupHandler file constructor"<<endl;
	std::ifstream file;
	std::string line;
	file.open(fname.c_str());
	if (!file){
		cerr<<"MarocSetupHandler::file not found "<<fname<<endl;
	}
	else{
		while(!file.eof()){
			getline (file,line);
			if (line.size()==0) continue;
			TRealSetupHandler::processLine(line);
			this->processLine(line);
		}
	}
	file.close();

}

void TCitirocSetupHandler::processLine(std::string line){

	istringstream parser;
	std::string key,data;
	int CitirocCh0,CitirocCh1,Pixel0,Pixel1;
	std::pair < int , int > CitirocIDChannel;
	parser.str(line);
	parser>>key;
	if (key[0]=='#') return; //comment
	else if (key=="ChannelToPixel"){

		parser>>data;CitirocCh0=atoi(data.c_str());
		parser>>data;Pixel0=atoi(data.c_str());
		CitirocIDChannel=make_pair(m_thisRealDetID,CitirocCh0);

		m_reconstructionDetFacefromCitirocIDChannel[CitirocIDChannel]=m_thisReconFace;
		m_reconstructionDetIDfromCitirocIDChannel[CitirocIDChannel]=m_thisReconDetID;
		m_reconstructionDetPixelfromCitirocIDChannel[CitirocIDChannel]=Pixel0;

	}
	else if (key=="MultiChannelToPixel"){
		parser>>data;CitirocCh0=atoi(data.c_str());
		parser>>data;CitirocCh1=atoi(data.c_str());
		parser>>data;Pixel0=atoi(data.c_str());
		parser>>data;Pixel1=atoi(data.c_str());

		int N=Pixel1-Pixel0+1;
		for (int ii=0;ii<N;ii++){
			CitirocIDChannel=make_pair(m_thisRealDetID,CitirocCh0+ii);
			m_reconstructionDetFacefromCitirocIDChannel[CitirocIDChannel]=m_thisReconFace;
			m_reconstructionDetIDfromCitirocIDChannel[CitirocIDChannel]=m_thisReconDetID;
			m_reconstructionDetPixelfromCitirocIDChannel[CitirocIDChannel]=Pixel0+ii;
		}
	}
}


int TCitirocSetupHandler::getReconstructionDetectorPixel(int ID,int ch){
	int ret=-1;
	std::map<pair <int,int>,int>::iterator it;
	std::pair < int , int > CitirocIDChannel;
	CitirocIDChannel=make_pair(ID,ch);

	it = m_reconstructionDetPixelfromCitirocIDChannel.find(CitirocIDChannel);
	if (it!=m_reconstructionDetPixelfromCitirocIDChannel.end()){
		ret = it->second;
	}
	else{
		Error("getReconstructionDetectorPixel","Reconstruction pixel not found for board %i channel %i",ID,ch);
	}
	return ret;
}
