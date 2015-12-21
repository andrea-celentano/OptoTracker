#include "TRealSetupHandler.hh"
#include "TofpetSetupHandler.hh"
using namespace std;

TofpetSetupHandler::TofpetSetupHandler():
TRealSetupHandler(){
	Info("TofpetSetupHandler","default constructor");
}


TofpetSetupHandler::TofpetSetupHandler(string fname)
{
	Info("TofpetSetupHandler","constructor with file: %s",fname.c_str());
	ifstream file;
	string line;
	file.open(fname.c_str());
	if (!file){
		cerr<<"TofpetSetupHandler::file not found "<<fname<<endl;
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

void TofpetSetupHandler::processLine(string line){
	return;
}
