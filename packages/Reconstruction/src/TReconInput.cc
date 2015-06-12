#include "TReconInput.hh"
#include <stdlib.h>     /* atof */
TReconInput::TReconInput(){
  
    cout<<"TReconInput:: default constructor"<<endl;
  
      for (int ii=0;ii<m_nPars;ii++) m_isParConfigured[ii]=0;
}

TReconInput::TReconInput(string fname){
    ifstream file(fname.c_str());
    string line,key,data;
    istringstream parser;
    int parId;
    
 
     for (int ii=0;ii<m_nPars;ii++) m_isParConfigured[ii]=0;
    cout<<"TReconInput: init with file "<<fname<<endl;
	if (!file){
		cout<<"Error in TReconInput, file not found: "<<fname<<endl;
		exit(1);
	}
	while(!file.eof()){
	  
	        getline (file,line);
		if (line.size()==0) continue;

		parser.clear();
		parser.str(line);
		parser>>key;

		if (key[0]=='#') continue; //comment

		if ((key=="FitObject")||(key=="fitObject")){
		    parser>>key;
		    if ((key == "null") || (key=="Null")) m_fitObject=k_null;
		    else if ((key == "point") || (key=="Point")) m_fitObject=k_point;
		    else if ((key == "track") || (key=="Track")) m_fitObject=k_track;
		    else {
		     cerr<<"Error, FitObject "<<key<<" not recognized. Use point or track"<<endl;
		     exit(1);
		    }
		}
		else if ((key=="FitMode")||(key=="fitMode")){
		    parser>>key;
		    if ((key == "charge") || (key=="Charge")) m_fitLikelihoodMode=k_onlyCharge;
		    else if ((key == "time") || (key=="Time")) m_fitLikelihoodMode=k_onlyTime;
		    else if ((key == "both") || (key=="Both")) m_fitLikelihoodMode=k_both;
		    else {
		     cerr<<"Error, FitMode "<<key<<" not recognized. Use point or track"<<endl;
		     exit(1);
		    }
		}
		else if ((key=="Parameter")||(key=="parameter")){
		  	parser>>data;parId=atoi(data.c_str());
			m_isParConfigured[parId]=1;
			parser>>data;m_parVal[parId]=atof(data.c_str());
			parser>>data;m_isParFixed[parId]=atoi(data.c_str());
		}
		else if ((key=="LowLimit")||(key=="lowLimit")){
			parser>>data;m_parLowLimit[parId]=atof(data.c_str());
			m_isParLowLimited[parId]=1;
		}
		else if ((key=="HighLimit")||(key=="highLimit")){
			parser>>data;m_parHighLimit[parId]=atof(data.c_str());
			m_isParHighLimited[parId]=1;
		}
	}
}



void TReconInput::print(){
   printf("TRecon input %s : \n",m_name.c_str());
  for (int ii=0;ii<m_nPars;ii++){
    if(m_isParConfigured[ii]==1){
     printf("Parameter %i : value is %f . Fixed : %i \n",ii,m_parVal[ii],m_isParFixed[ii]); 
    }   
  }
}
