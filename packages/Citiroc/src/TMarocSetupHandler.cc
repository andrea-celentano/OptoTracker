#include "TCitirocSetupHandler.hh"


TCitirocSetupHandler::TCitirocSetupHandler():
TRealSetupHandler()
{
	cout<<"CitirocSetupHandler default constructor"<<endl;
	fillMaps();
}


TCitirocSetupHandler::TCitirocSetupHandler(string fname):
TRealSetupHandler(fname)
{
	cout<<"CitirocSetupHandler file constructor"<<endl;
	ifstream file;
	string line;
	file.open(fname.c_str());
	if (!file){
		cerr<<"CitirocSetupHandler::file not found "<<fname<<endl;
	}
	else{
		while(!file.eof()){
			getline (file,line);
			if (line.size()==0) continue;
			this->processLine(line);
		}
	}
	file.close();
	fillMaps();
}

void TCitirocSetupHandler::fillMaps(){

	int CitirocChannel,H8500Id;
	for (CitirocChannel=0;CitirocChannel<nH8500Pixels;CitirocChannel++){
		switch (CitirocChannel){
		case 0:
			H8500Id=64;break;
		case 1:
			H8500Id=62;break;
		case 2:
			H8500Id=58;break;
		case 3:
			H8500Id=60;break;
		case 4:
			H8500Id=63;break;
		case 5:
			H8500Id=61;break;
		case 6:
			H8500Id=57;break;
		case 7:
			H8500Id=59;break;
		case 8:
			H8500Id=56;break;
		case 9:
			H8500Id=54;break;
		case 10:
			H8500Id=50;break;
		case 11:
			H8500Id=52;break;
		case 12:
			H8500Id=55;break;
		case 13:
			H8500Id=53;break;
		case 14:
			H8500Id=49;break;
		case 15:
			H8500Id=51;break;
		case 16:
			H8500Id=48;break;
		case 17:
			H8500Id=46;break;
		case 18:
			H8500Id=42;break;
		case 19:
			H8500Id=44;break;
		case 20:
			H8500Id=47;break;
		case 21:
			H8500Id=45;break;
		case 22:
			H8500Id=41;break;
		case 23:
			H8500Id=43;break;
		case 24:
			H8500Id=40;break;
		case 25:
			H8500Id=38;break;
		case 26:
			H8500Id=34;break;
		case 27:
			H8500Id=36;break;
		case 28:
			H8500Id=39;break;
		case 29:
			H8500Id=37;break;
		case 30:
			H8500Id=33;break;
		case 31:
			H8500Id=35;break;
		case 32:
			H8500Id=32;break;
		case 33:
			H8500Id=30;break;
		case 34:
			H8500Id=26;break;
		case 35:
			H8500Id=28;break;
		case 36:
			H8500Id=31;break;
		case 37:
			H8500Id=29;break;
		case 38:
			H8500Id=25;break;
		case 39:
			H8500Id=27;break;
		case 40:
			H8500Id=24;break;
		case 41:
			H8500Id=22;break;
		case 42:
			H8500Id=18;break;
		case 43:
			H8500Id=20;break;
		case 44:
			H8500Id=23;break;
		case 45:
			H8500Id=21;break;
		case 46:
			H8500Id=17;break;
		case 47:
			H8500Id=19;break;
		case 48:
			H8500Id=16;break;
		case 49:
			H8500Id=14;break;
		case 50:
			H8500Id=10;break;
		case 51:
			H8500Id=12;break;
		case 52:
			H8500Id=15;break;
		case 53:
			H8500Id=13;break;
		case 54:
			H8500Id=9;break;
		case 55:
			H8500Id=11;break;
		case 56:
			H8500Id=8;break;
		case 57:
			H8500Id=6;break;
		case 58:
			H8500Id=2;break;
		case 59:
			H8500Id=4;break;
		case 60:
			H8500Id=7;break;
		case 61:
			H8500Id=5;break;
		case 62:
			H8500Id=1;break;
		case 63:
			H8500Id=3;break;
		}
		H8500Id-=1; /*This instruction report the number from 0 to 63*/

		m_CitirocToH8500[CitirocChannel]=H8500Id;
		m_H8500ToCitiroc[H8500Id]=CitirocChannel;

	} //end for loop
}

void TCitirocSetupHandler::processLine(string line){


}


int TCitirocSetupHandler::getCitirocCard(int globalId){
	int CitirocCard;
	CitirocCard=globalId/nH8500Pixels;
	return CitirocCard;
}


 /*This methods returns the Citiroc CHANNEL, from 0 to 63, given the globalID*/
int TCitirocSetupHandler::getCitirocChannelFromGlobal(int globalId){
	int CitirocChannel;
	CitirocChannel=globalId%nH8500Pixels;
	return CitirocChannel;
}


 /*This methods returns the Citiroc CHANNEL, from 0 to 63, given the H8500ID*/
int TCitirocSetupHandler::getCitirocChannelFromH8500(int H8500Id){
	int CitirocChannel=-1;
	map<int,int>::iterator it;

	it=m_H8500ToCitiroc.find(H8500Id);
	if (it==m_H8500ToCitiroc.end()){
		cerr<<"Error in CitirocSetupHandler::getCitirocChannelFromH8500. The CitirocChannel corresponding to H8500ID: "<<H8500Id<<"was not found"<<endl;
	}
	else CitirocChannel=it->second;
	return CitirocChannel;
}
 /*This methods returns the pixel id, in H8500 arrangement, from 0 to 63, given the CitirocId (from 0 to 63)*/
int TCitirocSetupHandler::getH8500IdFromCitiroc(int CitirocChannel){
	int H8500Id=-1;
	map<int,int>::iterator it;

	it=m_CitirocToH8500.find(CitirocChannel);
	if (it==m_CitirocToH8500.end()){
		cerr<<"Error in CitirocSetupHandler::getH8500IdFromCitiroc. The H8500 corresponding to Citiroc: "<<CitirocChannel<<"was not found"<<endl;
	}
	else H8500Id=it->second;
	return H8500Id;
}

 /*This methods returns the pixel id, in H8500 arrangement, from 0 to 63, given the global DAQ ID (from 0 to 4095)*/
int TCitirocSetupHandler::getH8500IdFromGlobal(int globalId){
	int H8500Id;
	int CitirocChannel;
	CitirocChannel=getCitirocChannelFromGlobal(globalId);

	H8500Id=getH8500IdFromCitiroc(CitirocChannel);
	return H8500Id;
}


int  TCitirocSetupHandler::getPixelReconId(int globalID){
	int CitirocCard=this->getCitirocCard(globalID);           /*The CARD id: 0 ... 63. */ /*This is the number to identify the "REAL" detector*/
	int H8500Id=this->getH8500IdFromGlobal(globalID);     /*The H8500 pixel id*/
	

	int ret=-1;
	ret=this->getPixelReconId(CitirocCard,H8500Id);
	return ret;
}

int TCitirocSetupHandler::getPixelReconId(int iRealDet,int iRealPixel){
	int reconFace=this->getReconstructionDetectorFace(iRealDet);
	int H8500Id=iRealPixel;
	int ret=-1;
	int iX,iY;
	switch(reconFace){

	case 0:
	case 1:   //check me
	case 2:
	case 3:  //check me
		iX=H8500Id%nH8500PixelsX;
		iY=H8500Id/nH8500PixelsX;
		iY=nH8500PixelsY-iY-1;
		ret=iX+nH8500PixelsX*iY;
		break;
	}
     ///Todo: complete with other faces
	return ret;

}

/*Given the globalID (0..4095) it retuns the pixel gain*/
double TCitirocSetupHandler::getPixelGainFromGlobal(int globalID,int igain){
    int CitirocCard=this->getCitirocCard(globalID);           /*The CARD id: 0 ... 63. */ /*This is the number to identify the "REAL" detector*/
    int H8500Id=this->getH8500IdFromGlobal(globalID);     /*The H8500 pixel id*/

    int reconFace=this->getReconstructionDetectorFace(CitirocCard);
    int reconDetector=this->getReconstructionDetectorID(CitirocCard);
    int reconPixel=this->getPixelReconId(CitirocCard,H8500Id);
		
     double gain=this->getPixelGain(reconFace,reconDetector,reconPixel,igain);
  
 
     return gain;
  
}


