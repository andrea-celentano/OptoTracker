#include "TCitirocSetupHandler.hh"


TCitirocSetupHandler::TCitirocSetupHandler():
TRealSetupHandler()
{
	cout<<"MarocSetupHandler default constructor"<<endl;
	//fillMaps();
}

/*
TMarocSetupHandler::TMarocSetupHandler(string fname):
TRealSetupHandler(fname)
{
	cout<<"MarocSetupHandler file constructor"<<endl;
	ifstream file;
	string line;
	file.open(fname.c_str());
	if (!file){
		cerr<<"MarocSetupHandler::file not found "<<fname<<endl;
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
*/
