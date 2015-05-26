#include "RealSetupHandler.hh"

using namespace std;

RealSetupHandler::RealSetupHandler():
nRealDet(0)
{
  cout<<"RealSetupHandler::default constructor"<<endl;
}

RealSetupHandler::RealSetupHandler(string fname):
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
	
		this->masterProcessLine(line);
	}
  }
  file.close();
}

void RealSetupHandler::masterProcessLine(string line){
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
			m_reconstructionRealDet.insert(pair < pair <int,int>, int > (facedet,m_thisRealDetID));
   }
   else if (key=="Pixel"){
			parser>>data;m_thisPixel=atoi(data.c_str());
			parser>>data;m_thisGainEntry=atoi(data.c_str());
			parser>>data;m_thisGainVal=atof(data.c_str());//gain
			switch (m_thisGainEntry){
			    case 1:
			      m_PixelGain1[m_thisReconFace][m_thisReconDetID].insert(pair<int,double>(m_thisPixel,m_thisGainVal));
			      break;
			    case 2:
			      m_PixelGain2[m_thisReconFace][m_thisReconDetID].insert(pair<int,double>(m_thisPixel,m_thisGainVal));
			      break;
			    case 3:
			      m_PixelGain3[m_thisReconFace][m_thisReconDetID].insert(pair<int,double>(m_thisPixel,m_thisGainVal));
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
			for (int ipixel=m_thisPixelFirst;ipixel<m_thisPixelLast;ipixel++){	  
			  switch (m_thisGainEntry){
			    case 1:
			      m_PixelGain1[m_thisReconFace][m_thisReconDetID].insert(pair<int,double>(ipixel,m_thisGainVal));
			      break;
			    case 2:
			      m_PixelGain2[m_thisReconFace][m_thisReconDetID].insert(pair<int,double>(ipixel,m_thisGainVal));
			      break;
			    case 3:
			      m_PixelGain3[m_thisReconFace][m_thisReconDetID].insert(pair<int,double>(ipixel,m_thisGainVal));
			      break;
			    default:
			      cerr<<"Error RealSetupHandler setup, gain id "<<m_thisGainEntry<<"is invalid"<<endl;
			      return;
			  } 
			}
		} 
}

int    RealSetupHandler::getReconstructionDetectorFace(int idet){
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

int     RealSetupHandler::getReconstructionDetectorID(int idet){  
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

int     RealSetupHandler::getRealDetectorID(int iface,int idet){
  pair <int,int> facedet(iface,idet);
  int ret=-1;
  std::map<pair<int,int>,int>::iterator it;
  it=m_reconstructionRealDet.find(facedet);
  if (it!=m_reconstructionRealDet.end()){
    ret=it->second;    
  }
  else{
    cerr<<"Error RealSetupHandler::getRealDetectorID for face / id: "<<iface<<" "<<idet<<endl;
  }
}


double RealSetupHandler::getPixelGain(int iface,int idetector, int ipixel,int igain){
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

void RealSetupHandler::setPixelGain(int iface,int idetector, int ipixel,int igain,double val){
  
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
      cout<<"Error in RealSetupHandler::setPixelGain. igain must be 1,2,3"<<endl;
      break;
  }
}



void RealSetupHandler::printRealSetup(){
  
  std::map<int,int>::iterator itDet,itFace;
  int iReconDetID,iReconDetFace,iDet,iDet2;
  
  itDet=m_reconstructionDetID.begin();
  itFace=m_reconstructionDetFace.begin();
  cout<<"RealDetectorID \t \t ReconstructionDetectorFace \t \t ReconstructionDetectorID \t \t RetrievedRealDetID"<<endl;
  for (itDet;itDet!=m_reconstructionDetID.end();itDet++){
    iDet=itDet->first;
    if (itDet->first != itFace->first){
     cerr<<"Error in RealSetupHandler::printRealSetup, something wrong with the mapping"<<endl;
     return;
    }
    iReconDetFace=itFace->second;
    iReconDetID=itDet->second;
    iDet2=this->getRealDetectorID(iReconDetFace,iReconDetID);
    cout<<iDet<<" \t \t"<<iReconDetFace<<"\t \t"<<iReconDetID<<" \t \t "<<iDet2<<endl;
  }
  
  
  
}

