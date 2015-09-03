//
// ********************************************************************
// * License and Disclaimer                                           *
// *                                                                  *
// * The  Geant4 software  is  copyright of the Copyright Holders  of *
// * the Geant4 Collaboration.  It is provided  under  the terms  and *
// * conditions of the Geant4 Software License,  included in the file *
// * LICENSE and available at  http://cern.ch/geant4/license .  These *
// * include a list of copyright holders.                             *
// *                                                                  *
// * Neither the authors of this software system, nor their employing *
// * institutes,nor the agencies providing financial support for this *
// * work  make  any representation or  warranty, express or implied, *
// * regarding  this  software system or assume any liability for its *
// * use.  Please see the license in the file  LICENSE  and URL above *
// * for the full disclaimer and the limitation of liability.         *
// *                                                                  *
// * This  code  implementation is the result of  the  scientific and *
// * technical work of the GEANT4 collaboration.                      *
// * By using,  copying,  modifying or  distributing the software (or *
// * any work based  on the software)  you  agree  to acknowledge its *
// * use  in  resulting  scientific  publications,  and indicate your *
// * acceptance of all terms of the Geant4 Software license.          *
// ********************************************************************
//
// $Id: OpNoviceDetectorHit.cc 72250 2013-07-12 08:59:26Z gcosmo $
//
/// \file optical/OpNovice/src/OpNoviceDetectorHit.cc
/// \brief Implementation of the OpNoviceDetectorHit class
//
//
#include "OpNoviceDetectorHit.hh"
#include "G4ios.hh"
#include "G4VVisManager.hh"
#include "G4Colour.hh"
#include "G4VisAttributes.hh"
#include "G4LogicalVolume.hh"
#include "G4VPhysicalVolume.hh"
#include "G4ThreeVector.hh"
#include "G4Box.hh"

#include "G4SystemOfUnits.hh"

using namespace std;

//ClassImp(OpNoviceDetectorHit)
G4ThreadLocal G4Allocator<OpNoviceDetectorHit>* OpNoviceDetectorHitAllocator=0;

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

OpNoviceDetectorHit::OpNoviceDetectorHit()
:TObject(), fDetectorNumber(-1),fInFaceNumber(-1),fFaceNumber(-1),fNPhe(0),fPhysVol(0),fPhysVolMother(0),fDrawit(false),fName("")
//,TObject()
{
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

OpNoviceDetectorHit::~OpNoviceDetectorHit() {}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

OpNoviceDetectorHit::OpNoviceDetectorHit(const OpNoviceDetectorHit &right) : TObject(),G4VHit()
{
	fDetectorNumber=right.fDetectorNumber;
	fFaceNumber=right.fFaceNumber;
	fInFaceNumber=right.fInFaceNumber;


	fNPhe=right.fNPhe;
	fPhysVol=right.fPhysVol;
	fPhysVolMother=right.fPhysVolMother;
	fDrawit=right.fDrawit;
	
	fEnergy.clear();
	fTime.clear();
	fX.clear();
	fY.clear();
	fPixel.clear();
	for (int ii=0;ii<right.fNPhe;ii++){
		fEnergy.push_back(right.fEnergy.at(ii));
		fTime.push_back(right.fTime.at(ii));
		fX.push_back(right.fX.at(ii));
		fY.push_back(right.fX.at(ii));
		fPixel.push_back(right.fPixel.at(ii));
	}
}
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

const OpNoviceDetectorHit& OpNoviceDetectorHit::operator=(const OpNoviceDetectorHit &right){

	fDetectorNumber=right.fDetectorNumber;
	fFaceNumber=right.fFaceNumber;
	fInFaceNumber=right.fInFaceNumber;


	fNPhe=right.fNPhe;
	fPhysVol=right.fPhysVol;
	fPhysVolMother=right.fPhysVolMother;
	fDrawit=right.fDrawit;
	
	fEnergy=right.fEnergy;
	fTime=right.fTime;
	fX=right.fX;
	fY=right.fY;
	fPixel=right.fPixel;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......


G4int OpNoviceDetectorHit::operator==(const OpNoviceDetectorHit &right) const{
	return false;
	    //return (fPmtNumber==right.fPmtNumber);
}






//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void OpNoviceDetectorHit::Draw(){
	if(fDrawit&&fPhysVol&&fPhysVolMother){ //ReDraw only the PMTs that have hit counts > 0
			//Also need a physical volume to be able to draw anything
			G4VVisManager* pVVisManager = G4VVisManager::GetConcreteInstance();
			if(pVVisManager){//Make sure that the VisManager exists
				
				if (fName=="H8500"){
					
					G4double delta=49.*mm/8; //6.125mm
					G4double x,y;
					G4int iPixel,iPixelX,iPixelY;
					G4int fPhotonsPixels[64]={0.};
					for (int ii=0;ii<fNPhe;ii++){
						x=GetX(ii);
						y=GetY(ii);
						
						if (fabs(x)>49.*mm/2) continue;
						if (fabs(y)>49.*mm/2) continue;
						
						x+=4*delta; //0..49mm
						y+=4*delta; //0..49mm
						
						iPixelX=(x/delta);// 0..7;
						iPixelY=(y/delta);// 0..7;
						
						iPixel=iPixelX+8*iPixelY;
						
						fPhotonsPixels[iPixel]++;													
					}
					
					SetDrawScaleMin(fNPhe);
					SetDrawScaleMax(0);
					for (int ii=0;ii<64;ii++){
						if (fPhotonsPixels[ii]<GetDrawScaleMin()) SetDrawScaleMin(fPhotonsPixels[ii]);
						if (fPhotonsPixels[ii]>GetDrawScaleMax()) SetDrawScaleMax(fPhotonsPixels[ii]);
					}
					
					for (int ii=0;ii<64;ii++){
						G4double fGreen,fRed;
						fRed=(1.*fPhotonsPixels[ii]-1.*GetDrawScaleMin())/(1.*GetDrawScaleMax()-1.*GetDrawScaleMin()); 
						fGreen=(1.*GetDrawScaleMax()-1.*fPhotonsPixels[ii])/(1.*GetDrawScaleMax()-1.*GetDrawScaleMin()); 						
						G4VisAttributes attribs(G4Colour(fRed,fGreen,0.,0.6));
						attribs.SetForceSolid(true);
						
						iPixelX=ii%8;
						iPixelY=ii/8;
						
						x=iPixelX*delta-4*delta;
						y=iPixelY*delta-4*delta;
					
						//	G4cout<<x<<" "<<y<<" "<<fPhotonsPixels[ii]<<" "<<fRed<<" "<<fGreen<<" "<<GetDrawScaleMax()<<" "<<GetDrawScaleMin()<<G4endl;
						
						G4RotationMatrix rot1,rot2,rot3;
						if(fPhysVolMother->GetRotation()) rot1=*(fPhysVolMother->GetRotation()); //If a rotation is defined use it
						if(fPhysVol->GetRotation()) rot2=*(fPhysVol->GetRotation()); //If a rotation is defined use it
						G4ThreeVector v1=fPhysVolMother->GetTranslation();
						G4ThreeVector v2=fPhysVol->GetTranslation();
						G4ThreeVector v3(x+delta/2,y+delta/2,-3*mm);
						rot1=rot1.inverse();
						G4Transform3D transMother(rot1,v1);       //Create transform
						G4Transform3D transSon(rot2,v2);       //Create transform
						G4Transform3D transFinal(rot3,v3);
						G4Transform3D trans=transMother*transSon*transFinal;
						
						G4Box *box=new G4Box("HitDrawBox",delta/2,delta/2,0.5*mm);
						if (fPhotonsPixels[ii]>0) pVVisManager->Draw(*box,attribs,trans); //draw only if >0
					}
							
					
					
					
					
				}								
		}
	}
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......



void OpNoviceDetectorHit::Print() {}



/*From root TOBject*/
void OpNoviceDetectorHit::Clear(Option_t* option){
	fEnergy.clear();
	fTime.clear();
	fX.clear();
	fY.clear();
	fPixel.clear();
}
