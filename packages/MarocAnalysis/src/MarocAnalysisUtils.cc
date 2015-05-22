#include "MarocAnalysisUtils.hh"



  
int GetMarocId(int globalId){
  int MarocId;
  MarocId=globalId%64;
  return MarocId;
}


int GetH8500Id(int globalId){
  int MarocId,H8500Id;
  MarocId=GetMarocId(globalId);
  
  switch (MarocId){
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
  return H8500Id;
}


double H8500Gain(int H8500Id,int PmtID){
  double PmtDA0359[64]={76,79,86,96,100,95,88,83,76,71,80,89,95,89,87,82,75,68,82,87,92,91,81,77,71,64,79,83,88,88,75,74,69,63,74,79,78,83,73,70,68,61,71,75,76,73,68,65,63,60,65,69,66,62,59,60,61,64,66,70,65,60,56,52};
  double PmtDA0361[64]={56,71,76,81,89,87,78,82,61,66,72,77,82,78,76,85,60,64,72,74,75,81,80,88,61,65,70,72,73,82,82,93,63,66,71,72,73,85,86,99,68,68,77,75,82,91,89,100,73,75,83,88,95,97,92,99,60,73,80,85,92,99,90,71};

  if (PmtID==0) return PmtDA0361[H8500Id]*0.01;
  if (PmtID==1) return PmtDA0359[H8500Id]*0.01;
}

double MarocGain(int MarocId){
  if (MarocId<=31) return .5;
  else if (MarocId<=47) return .375;
  else if (MarocId<=63) return .25;
}