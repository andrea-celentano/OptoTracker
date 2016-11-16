#include "TRealSetupHandler.hh"
#include "TTofpetSetupHandler.hh"
using namespace std;

TTofpetSetupHandler::TTofpetSetupHandler():
TRealSetupHandler(){
	Info("TTofpetSetupHandler","default constructor");
}


TTofpetSetupHandler::TTofpetSetupHandler(string fname)
{
	Info("TTofpetSetupHandler","constructor with file: %s",fname.c_str());
	ifstream file;
	string line;
	file.open(fname.c_str());
	if (!file){
		cerr<<"TTofpetSetupHandler::file not found "<<fname<<endl;
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

void TTofpetSetupHandler::processLine(string line){
	return;
}
