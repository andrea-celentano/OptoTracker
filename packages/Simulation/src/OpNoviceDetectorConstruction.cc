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
//
//
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#include "OpNoviceDetectorConstruction.hh"

#include "G4Material.hh"
#include "G4Element.hh"
#include "G4LogicalBorderSurface.hh"
#include "G4LogicalSkinSurface.hh"
#include "G4OpticalSurface.hh"
#include "G4Box.hh"
#include "G4Tubs.hh"
#include "G4SubtractionSolid.hh"
#include "G4LogicalVolume.hh"
#include "G4ThreeVector.hh"
#include "G4PVPlacement.hh"
#include "G4SystemOfUnits.hh"
#include "G4PhysicalConstants.hh"
#include "G4VisAttributes.hh"
#include "G4GeometryManager.hh"
#include "G4SolidStore.hh"
#include "G4LogicalVolumeStore.hh"
#include "G4PhysicalVolumeStore.hh"
#include "G4SDManager.hh"
#include "G4RunManager.hh"
#include "G4UserLimits.hh"




#include "TString.h"


static OpNoviceDetectorConstruction* instance = 0;


//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

OpNoviceDetectorConstruction::OpNoviceDetectorConstruction(TDetectorLight *mDetectorLight)
: G4VUserDetectorConstruction(),fDetectorLight(mDetectorLight)
{

	//for (int ii=0;ii<6;ii++) fDetector_log[ii]=NULL;	
	SetDefaults();
	OverloadWithDetectorLight();
	previousSubtraction=NULL;
	currentSubtraction=NULL;
	if (instance){
		G4cout<<"An instance of the detector already exists? Error!"<<G4endl;
		exit(1);
	}
	else{
		instance=this;
	}
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

OpNoviceDetectorConstruction::~OpNoviceDetectorConstruction(){;}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......



OpNoviceDetectorConstruction* OpNoviceDetectorConstruction::GetInstance()
{
	if (instance == 0 )
	{
		G4cout<<"OpNoviceDetectorConstruction::GetInstance can't return any instance"<<G4endl;
		return 0;
	}
	return instance;
}



//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......



G4VPhysicalVolume* OpNoviceDetectorConstruction::Construct()
{

	previousSubtraction=NULL;
	currentSubtraction=NULL;


	G4cout<<"OpNoviceDetectorConstruction::Construct was called"<<G4endl;
	if (fExperimentalHall_phys) {
		G4GeometryManager::GetInstance()->OpenGeometry();
		G4PhysicalVolumeStore::GetInstance()->Clean();
		G4LogicalVolumeStore::GetInstance()->Clean();
		G4SolidStore::GetInstance()->Clean();
		G4LogicalSkinSurface::CleanSurfaceTable();
		G4LogicalBorderSurface::CleanSurfaceTable();
	}


	double x,y;
	double xp,yp;
	faceThickness=2*cm;
	detectorThickness=1*cm;
	pixelThickness=.1*mm;
	aroundThickness=.2*mm;

	G4ThreeVector fTrans[6];
	G4VisAttributes* VisAtt;
	G4RotationMatrix* fRot[6];	

	int ix,iy,id;

	// ------------- Materials -------------
	DefineMaterials();
	// The experimental Hall
	//
	//The experimental hall walls are all 100cm away from housing walls
	fExpHall_x = 50.*cm;
	fExpHall_y = 50.*cm;
	fExpHall_z = 50.*cm;

	fExperimentalHall_box = new G4Box("World",fExpHall_x,fExpHall_y,fExpHall_z);
	fExperimentalHall_log = new G4LogicalVolume(fExperimentalHall_box,fAir,"World",0,0,0);
	fExperimentalHall_phys = new G4PVPlacement(0,G4ThreeVector(),fExperimentalHall_log,"World",0,false,0);

	//fDummy_box = new G4Box("Dummy",1*mm,1*mm,1*mm);
	//fDummy_log = new G4LogicalVolume(fDummy_box,fAir,"Dummy",0,0,0);
	//fDummy_phys = new G4PVPlacement(0,G4ThreeVector(fExpHall_x/2-1*cm,fExpHall_y/2-1*cm,fExpHall_z/2-1*cm),fDummy_log,"Dummy",fExperimentalHall_log ,false,0);


	// The Scintillator
	fScint_x=fDetectorLight->getScintSizeX()*cm;
	fScint_y=fDetectorLight->getScintSizeX()*cm;
	fScint_z=fDetectorLight->getScintSizeX()*cm;

	fScintillator_box = new G4Box("Scintillator",fScint_x/2,fScint_y/2,fScint_z/2);
	fScintillator_log = new G4LogicalVolume(fScintillator_box,fEJ230,"Scintillator",0,0,0);
	G4VPhysicalVolume* Scintillator_phys = new G4PVPlacement(0,G4ThreeVector(),fScintillator_log,"Scintillator",fExperimentalHall_log,false,0);


	//The 6 faces

	for (int ii=0;ii<6;ii++){

		previousSubtraction=NULL;
		currentSubtraction=NULL;

		fFaceReflectivity[ii]=fDetectorLight->getFaceReflectivity(ii);

		if (ii==0){ //xy, +z
			x=fScint_x;
			y=fScint_y;
			fTrans[0]=G4ThreeVector(0,0,(fScint_z+faceThickness)/2);
			fRot[0]=new G4RotationMatrix;
			fRot[0]->rotateY(M_PI*rad);
		}
		if (ii==2){ //xy, -z
			x=fScint_x;
			y=fScint_y;
			fTrans[2]=G4ThreeVector(0,0,-(fScint_z+faceThickness)/2);
			fRot[2]=new G4RotationMatrix;
			fRot[2]->rotateY(0);
		}
		if (ii==1){ //yz,+x
			x=fScint_z;
			y=fScint_y;
			fTrans[1]=G4ThreeVector((fScint_x+faceThickness)/2,0,0);
			fRot[1]=new G4RotationMatrix;
			fRot[1]->rotateY(M_PI/2.*rad);
		}
		if (ii==3){ //yz,-x
			x=fScint_z;
			y=fScint_y;
			fTrans[3]=G4ThreeVector(-(fScint_x+faceThickness)/2,0,0);
			fRot[3]=new G4RotationMatrix;
			fRot[3]->rotateY(-M_PI/2.*rad);
		}
		if (ii==4){ //xz,+y
			x=fScint_x;
			y=fScint_z;
			fTrans[4]=G4ThreeVector(0,(fScint_y+faceThickness)/2,0);
			fRot[4]=new G4RotationMatrix;
			fRot[4]->rotateX(-M_PI/2*rad);
		}	
		if (ii==5){ //xz,-y
			x=fScint_x;
			y=fScint_z;
			fTrans[5]=G4ThreeVector(0,-(fScint_y+faceThickness)/2,0);
			fRot[5]=new G4RotationMatrix;
			fRot[5]->rotateX(M_PI/2*rad);
		}
		fFace_box[ii]=new G4Box("Face",x/2,y/2,faceThickness/2);
		fFace_log[ii]=new G4LogicalVolume(fFace_box[ii],fAir,"Face",0,0,0);



		fFaceMarker_box[ii]=new G4Box("FaceMarker",3*mm,.2*mm,.2*mm);
		fFaceMarker_log[ii]=new G4LogicalVolume(fFaceMarker_box[ii],fAir,Form("FaceMarker_%i",ii),0,0,0);
		VisAtt = new G4VisAttributes(G4Colour(1.0,0.7,0.0));
		VisAtt->SetForceSolid(true);
		fFaceMarker_log[ii]->SetVisAttributes(VisAtt);
		fAround_box_a[ii]=new G4Box("Around",x/2,y/2,aroundThickness/2);

		for (int jj=0;jj<fDetectorLight->getNdet(ii);jj++){

			if (fDetectorLight->isDetPresent(ii,jj)){
				fPhotoDetectorSizeX[ii][jj]=fDetectorLight->getDetSizeX(ii,jj)*cm;
				fPhotoDetectorSizeY[ii][jj]=fDetectorLight->getDetSizeY(ii,jj)*cm;

				fPhotoDetectorCenterX[ii][jj]=fDetectorLight->getDetCenterX(ii,jj)*cm;
				fPhotoDetectorCenterY[ii][jj]=fDetectorLight->getDetCenterY(ii,jj)*cm;
				fPhotoDetectorRotation[ii][jj]=fDetectorLight->getDetRotation(ii,jj)*deg;

				fPixelSizeX[ii][jj]=fDetectorLight->getPixelSizeX(ii,jj)*cm;
				fPixelSizeY[ii][jj]=fDetectorLight->getPixelSizeY(ii,jj)*cm;


				fNPixelsX[ii][jj]=fDetectorLight->getNPixelsX(ii,jj);
				fNPixelsY[ii][jj]=fDetectorLight->getNPixelsY(ii,jj);

				fCouplingThickness[ii][jj]=fDetectorLight->getCouplingThickness(ii,jj)*cm;
				fPhotoReflectivity[ii][jj]=fDetectorLight->getDetReflectivity(ii,jj);
				fPhotoQE[ii][jj]=fDetectorLight->getDetQE(ii,jj);



				rotDet[ii][jj].rotateZ(fPhotoDetectorRotation[ii][jj]);
				translDet[ii][jj]=G4ThreeVector(fPhotoDetectorCenterX[ii][jj],fPhotoDetectorCenterY[ii][jj],faceThickness/2-fCouplingThickness[ii][jj]-detectorThickness/2);
				transformDet[ii][jj]=G4Transform3D(rotDet[ii][jj],translDet[ii][jj]);

				if (fDetectorLight->getDetName(ii,jj)=="H8500"){
					fDetector_log[ii][jj]=buildH8500(ii,jj); //this defines fH8500_box , fH8500Photo_box, fH8500Photo_log
					fDetector_box[ii][jj]=fH8500_box;
					fPixel_box[ii][jj]=fH8500Photo_box;
					fPixel_log[ii][jj]=fH8500Photo_log;

					fPhotoDetectorSizeX[ii][jj]=H8500FULLSIZE*cm;
					fPhotoDetectorSizeY[ii][jj]=H8500FULLSIZE*cm;
				}
				else if (fDetectorLight->getDetName(ii,jj)=="custom"){ /*For the generic case: construct the detector_log (the box) and the pixel_log*/
					fDetector_box[ii][jj]=new G4Box("Detector",fPhotoDetectorSizeX[ii][jj]/2,fPhotoDetectorSizeY[ii][jj]/2,detectorThickness/2);
					fDetector_log[ii][jj]=new G4LogicalVolume(fDetector_box[ii][jj],fVacuum,"Detector",0,0,0);
					fPixel_box[ii][jj]=new G4Box("Pixel",fPixelSizeX[ii][jj]/2,fPixelSizeY[ii][jj]/2,pixelThickness/2);
					fPixel_log[ii][jj]=new G4LogicalVolume(fPixel_box[ii][jj],fAir,"Pixel",0,0,0);
					/*Now place the pixels in the detector*/
					id=0;
					for (iy=0;iy<fNPixelsY[ii][jj];iy++){
						for (ix=0;ix<fNPixelsX[ii][jj];ix++){

							xp=(fPixelSizeX[ii][jj]-fPhotoDetectorSizeX[ii][jj])/2+ix*fPixelSizeX[ii][jj];
							yp=(fPixelSizeY[ii][jj]-fPhotoDetectorSizeY[ii][jj])/2+iy*fPixelSizeY[ii][jj];


							new G4PVPlacement(0,G4ThreeVector(xp,yp,detectorThickness/2-pixelThickness/2),fPixel_log[ii][jj],Form("Pixel_%i_%i_%i",ii,jj,id),fDetector_log[ii][jj],false,id); //copy number
							id++;
						}
					}
				}

				VisAtt = new G4VisAttributes(G4Colour(0.1,1.,0.1,0.8));
				VisAtt->SetForceSolid(true);
				fDetector_log[ii][jj]->SetVisAttributes(VisAtt);



				/*Place the detector in the face. This is OK for all the cases*/
				new G4PVPlacement(transformDet[ii][jj],fDetector_log[ii][jj],Form("Detector_%i_%i",ii,jj),fFace_log[ii],false,jj);//I use a copy-number to keep the detector number within the face





				/*Place the optical coupling in the face*/
				if (fCouplingThickness[ii][jj]>0){
					fCoupling_box[ii][jj]=new G4Box("Coupling",fPhotoDetectorSizeX[ii][jj]/2,fPhotoDetectorSizeY[ii][jj]/2,fCouplingThickness[ii][jj]/2);
					fCoupling_log[ii][jj]=new G4LogicalVolume(fCoupling_box[ii][jj],fCoupling[ii][jj],"Coupling",0,0,0);
					VisAtt = new G4VisAttributes(G4Colour(0.1,1.,1.,0.3));
					VisAtt->SetForceSolid(true);
					fCoupling_log[ii][jj]->SetVisAttributes(VisAtt);

					translCoupling[ii][jj]=G4ThreeVector(fPhotoDetectorCenterX[ii][jj],fPhotoDetectorCenterY[ii][jj],faceThickness/2-fCouplingThickness[ii][jj]/2);
					transformCoupling[ii][jj]=G4Transform3D(rotDet[ii][jj],translCoupling[ii][jj]);

					new G4PVPlacement(transformCoupling[ii][jj],fCoupling_log[ii][jj],"Coupling",fFace_log[ii],false,0);
				}
				else{
					fCouplingThickness[ii][jj]=0;
				}

				fAround_box_b[ii][jj]=new G4Box(Form("AroundBoxB_%i_%i",ii,jj),fPhotoDetectorSizeX[ii][jj]/2,fPhotoDetectorSizeY[ii][jj]/2,aroundThickness);
				translAround[ii][jj]=G4ThreeVector(fPhotoDetectorCenterX[ii][jj],fPhotoDetectorCenterY[ii][jj],0);
				transformAround[ii][jj]=G4Transform3D(rotDet[ii][jj],translAround[ii][jj]);

				if (previousSubtraction==NULL){ //this is the first time we subtract
					G4cout<<"OpNoviceDetectorConstruction:: previous subtraction is NULL "<<ii<<" "<<jj<<G4endl;
					previousSubtraction=new G4SubtractionSolid(Form("previousSubtraction_%i_%i",ii,jj),fAround_box_a[ii],fAround_box_b[ii][jj],transformAround[ii][jj]);
				}
				else{ //this is not the first subtraction
					G4cout<<"OpNoviceDetectorConstruction:: previous subtraction is NOT NULL "<<ii<<" "<<jj<<G4endl;
					currentSubtraction=new G4SubtractionSolid(Form("currentSubtraction_%i_%i",ii,jj),previousSubtraction,fAround_box_b[ii][jj],transformAround[ii][jj]);
					previousSubtraction=currentSubtraction;
				}

				/*The 0-0 pixel marker
				 */
				fDetectorMarker_box[ii][jj]=new G4Box("DetectorMarker",1*mm,.2*mm,.2*mm);
				fDetectorMarker_log[ii][jj]=new G4LogicalVolume(fDetectorMarker_box[ii][jj],fAir,Form("DetectorMarker_%i_%i",ii,jj),0,0,0);
				VisAtt = new G4VisAttributes(G4Colour(1.0,0.1,1.0));
				VisAtt->SetForceSolid(true);
				fDetectorMarker_log[ii][jj]->SetVisAttributes(VisAtt);

				new G4PVPlacement(0,G4ThreeVector(-fPhotoDetectorSizeX[ii][jj]/2+1*mm/2,-fPhotoDetectorSizeY[ii][jj]/2+.5*mm/2,-detectorThickness/2+.2*mm/2),fDetectorMarker_log[ii][jj],Form("DetectorMarker_%i",ii),fDetector_log[ii][jj],false,0);

			}//end if isDetPresent(ii,jj)


		}//loop on detectors(jj) on face ii

		if (previousSubtraction==NULL){ //we never subtracted
			G4cout<<"OpNoviceDetectorConstruction:: constructing around WITHOUT subtraction "<<ii<<G4endl;
			fAround_log[ii]=new G4LogicalVolume(fAround_box_a[ii],fAir,"AroundNotSubtracted",0,0,0);
		}
		else{
			G4cout<<"OpNoviceDetectorConstruction:: constructing around WITH subtraction "<<ii<<G4endl;
			fAround[ii]=previousSubtraction;
			fAround_log[ii]=new G4LogicalVolume(fAround[ii],fAir,"AroundSubtracted",0,0,0);
		}

		VisAtt = new G4VisAttributes(G4Colour(1.,0.,0.,0.8));
		VisAtt->SetForceSolid(true);
		fAround_log[ii]->SetVisAttributes(VisAtt);

		fAround_phys[ii]=new G4PVPlacement(0,G4ThreeVector(0,0,faceThickness/2-aroundThickness/2),fAround_log[ii],Form("Around_%i",ii),fFace_log[ii],false,0);

		new G4PVPlacement(0,G4ThreeVector(-x/2+2*3*mm,-y/2+2*.5*mm,-faceThickness/2+.2*mm/2),fFaceMarker_log[ii],Form("FaceMarker_%i",ii),fFace_log[ii],false,0);
		new G4PVPlacement(fRot[ii],fTrans[ii],fFace_log[ii],Form("Face%i",ii),fExperimentalHall_log,false,ii); //I use a copy-number to keep the face number
	}//loop on faces (ii)




	fPmtPlaced=true;




	/*Optical surfaces*/

	/*The wrappings*/
	const G4int numScintSurf=2;
	G4double ePhotonScintSurf[numScintSurf]={1.,10.};

	G4double ScintSurfSpecularLobe[numScintSurf]={0.,0.};
	G4double ScintSurfSpecularSpike[numScintSurf]={0.,0.};
	G4double ScintSurfBackScatter[numScintSurf]={0.,0.};

	const G4int numDetSurf=2;
	G4double ePhotonDetSurf[numDetSurf]={1.,10.};


	for (int ii=0;ii<6;ii++){

		G4double ScintSurfReflectivity[numScintSurf]={fFaceReflectivity[ii],fFaceReflectivity[ii]};

		/*This is the part of the face NOT in contact to the detector*/
		fFaceOpsurf[ii]=new G4OpticalSurface("scint_opsurf",unified,polishedfrontpainted,dielectric_dielectric);
		fFaceOpsurf[ii]->SetSigmaAlpha(.1);
		fFaceOpsurfMT[ii] = new G4MaterialPropertiesTable();
		fFaceOpsurfMT[ii]->AddProperty("REFLECTIVITY",ePhotonScintSurf, ScintSurfReflectivity,numScintSurf);
		fFaceOpsurfMT[ii]->AddProperty("SPECULARLOBECONSTANT",ePhotonScintSurf,ScintSurfSpecularLobe,numScintSurf);
		fFaceOpsurfMT[ii]->AddProperty("SPECULARSPIKECONSTANT",ePhotonScintSurf,ScintSurfSpecularSpike,numScintSurf);
		fFaceOpsurfMT[ii]->AddProperty("BACKSCATTERCONSTANT",ePhotonScintSurf,ScintSurfBackScatter,numScintSurf);
		fFaceOpsurf[ii]->SetMaterialPropertiesTable(fFaceOpsurfMT[ii]);

		if (fFaceReflectivity[ii]>=0){ /*with this, if I enter a negative reflectivity, the logical border surface is NOT created, and around we have air*/
			G4cout<<"Reflectivity specified ( "<<fFaceReflectivity[ii]<<" ) for face "<<ii<<" create opt surface "<<G4endl;
			fFaceBorder[ii]=new G4LogicalBorderSurface(Form("scint_surf_%i",ii),Scintillator_phys,fAround_phys[ii],fFaceOpsurf[ii]);
		}
		else{
			G4cout<<"Reflectivity NOT specified for face "<<ii<<" use AIR around"<<G4endl;
		}

		for (int jj=0;jj<fDetectorLight->getNdet(ii);jj++){
			///TODO: the case of H8500?
			G4double DetectorSurfReflectivity[numDetSurf]={fPhotoReflectivity[ii][jj],fPhotoReflectivity[ii][jj]};
		//	G4double DetectorSurfEfficiency[numDetSurf]={fPhotoQE[ii][jj]/(1-fPhotoReflectivity[ii][jj]),fPhotoQE[ii][jj]/(1-fPhotoReflectivity[ii][jj])};    //QE=(1-R)*efficiency
			G4double DetectorSurfEfficiency[numDetSurf]={fPhotoQE[ii][jj],fPhotoQE[ii][jj]};  //NO. This is again in fPhotoQE, embedded!!!
			fDetectorOpsurf[ii][jj]=new G4OpticalSurface(Form("detector_opsurf_%i_%i",ii,jj),unified,polished,dielectric_metal);
			fDetectorOpsurfMT[ii][jj] = new G4MaterialPropertiesTable();
			fDetectorOpsurfMT[ii][jj]->AddProperty("REFLECTIVITY",ePhotonDetSurf,DetectorSurfReflectivity,numDetSurf);
			fDetectorOpsurfMT[ii][jj]->AddProperty("EFFICIENCY",ePhotonDetSurf,DetectorSurfEfficiency,numDetSurf);
			fDetectorOpsurf[ii][jj]->SetMaterialPropertiesTable(fDetectorOpsurfMT[ii][jj]);
			fDetectorSkin[ii][jj]=new G4LogicalSkinSurface(Form("detector_surf_%i_%i",ii,jj),fPixel_log[ii][jj],fDetectorOpsurf[ii][jj]);  /*Pixel - coupling material*/
		}
	}


	/*Set the step limit in the scintillator*/
	/*fStepLimit = new G4UserLimits(fMaxStep);
      Scintillator_log->SetUserLimits(fStepLimit);
	 */

	return fExperimentalHall_phys;
}


void OpNoviceDetectorConstruction::DefineMaterials(){
	G4cout<<"OpNoviceDetectorConstruction::DefineMaterials() was called"<<G4endl;
	G4double a;  // atomic mass
	G4double z;  // atomic number
	G4double density;



	//***Elements
	fH = new G4Element("H","H", z=1., a=1.01*g/mole);
	fB = new G4Element("B","B",z=5., a=10.811*g/mole); 
	fC = new G4Element("C","C", z=6., a=12.01*g/mole);
	fN = new G4Element("N","N", z=7., a= 14.01*g/mole);
	fO = new G4Element("O","O", z=8., a= 16.00*g/mole);
	fNa= new G4Element("Na","Na",z=11.,a=22.989*g/mole);
	fAl = new G4Element("Al","Al",z=13.,a=26.981*g/mole);
	fSi = new G4Element("Si","Si",z=14.,a=28.0855*g/mole);
	fK = new G4Element("K","K",z=19.,a=39.0983*g/mole);



	//Vacuum
	fVacuum = new G4Material("Vacuum",z=1.,a=1.01*g/mole,
			density=universe_mean_density,kStateGas,0.1*kelvin,
			1.e-19*pascal);
	//Air
	fAir = new G4Material("Air", density= 1.29*mg/cm3, 2);
	fAir->AddElement(fN, 70*perCent);
	fAir->AddElement(fO, 30*perCent);



	//The coupling material.
	//Note that the critical properties of this material are mainly "collapsed" in the refraction index...
	//so I put it as "water", with density=1.
	const int numCouplingRindex=2;
	G4double eCouplingRindex[numCouplingRindex]={1*eV,10*eV};
	for (int ii=0;ii<6;ii++){
		for (int jj=0;jj<fDetectorLight->getNdet(ii);jj++){
			fCouplingN[ii][jj]=fDetectorLight->getCouplingRIndex(ii,jj);

			fCoupling[ii][jj] = new G4Material(Form("CouplingMaterial_%i",ii),density=1.*g/cm3,2);
			fCoupling[ii][jj]->AddElement(fH, 2);
			fCoupling[ii][jj]->AddElement(fO, 1);

			//coupling material

			G4double CouplingRindex[numCouplingRindex]={fCouplingN[ii][jj],fCouplingN[ii][jj]};

			fCouplingMT[ii][jj] = new G4MaterialPropertiesTable();
			fCouplingMT[ii][jj]->AddProperty("RINDEX",eCouplingRindex,CouplingRindex,numCouplingRindex);
			fCoupling[ii][jj]->SetMaterialPropertiesTable(fCouplingMT[ii][jj]);
		}
	}
	//Properties tables

	//vacuum
	G4double vacuum_Energy[]={1.0*eV,10.0*eV};
	const G4int vacnum = sizeof(vacuum_Energy)/sizeof(G4double);
	G4double vacuum_RIND[]={1.,1.};
	assert(sizeof(vacuum_RIND) == sizeof(vacuum_Energy));
	vacuumMT = new G4MaterialPropertiesTable();
	vacuumMT->AddProperty("RINDEX", vacuum_Energy, vacuum_RIND,vacnum);
	//fVacuum->SetMaterialPropertiesTable(vacuumMT);

	//air
	fAir->SetMaterialPropertiesTable(vacuumMT);//Give air the same rindex as vacuum

	//make the H8500 materials
	makeH8500materials();

	//build the EJ230 scintillator material
	makeEJ230();

}



void OpNoviceDetectorConstruction::ConstructSDandField() {

	if (!fExperimentalHall_phys) return;
	if (!fPmtPlaced) return;
	//Scint SD
	if (!fScintSD.Get()){
		G4cout << "Construction /OpNoviceDet/ScintSD" << G4endl;
		OpNoviceScintSD* ScintSD = new OpNoviceScintSD("/OpNoviceDet/ScintSD");
		fScintSD.Put(ScintSD);
		SetSensitiveDetector(fScintillator_log, fScintSD.Get());
	}

	//Detector SD
	if (!fDetectorSD.Get()) {
		//Created here so it exists as pmts are being placed
		G4cout << "Construction /OpNoviceDet/DetectorSD" << G4endl;
		OpNoviceDetectorSD* detectorSD = new OpNoviceDetectorSD("/OpNoviceDet/DetectorSD");
		fDetectorSD.Put(detectorSD);
		for (int ii=0;ii<6;ii++){
			for (int jj=0;jj<fDetectorLight->getNdet(ii);jj++){
				if (fDetector_log[ii][jj])	SetSensitiveDetector(fPixel_log[ii][jj],fDetectorSD.Get());
			}
		}
	}




	//sensitive detector is not actually on the photocathode.
	//processHits gets done manually by the stepping action.
	//It is used to detect when photons hit and get absorbed&detected at the
	//boundary to the photocathode (which doesnt get done by attaching it to a
	//logical volume.
	//It does however need to be attached to something or else it doesnt get
	//reset at the begining of events

	/*If I attach it to the photocathode, the G4OpBoundary process will see it, and call 
	the ProcessHits method, that is actually doing nothing.
	The OpNoviceStepping action is calling instead ProcessHits_conststep, that is doing the real record*/

	/*for (int ii=0;ii<6;ii++){
	if (fDetector_log[ii])	SetSensitiveDetector(fDetector_log[ii], fPmt_SD.Get());
    }*/

	//SetSensitiveDetector(fDummy_log, fDetectorSD.Get());


}



void OpNoviceDetectorConstruction::OverloadWithDetectorLight(){

	if (fDetectorLight->getLY()>=0) fEJ230_LY=fDetectorLight->getLY();
	if (fDetectorLight->getFastScintTime()>=0) fEJ230_FastTimeConstant=fDetectorLight->getFastScintTime();

}








void OpNoviceDetectorConstruction::SetDefaults() {

	//Resets to default values
	fExpHall_x = fExpHall_y = fExpHall_z = 50.0*cm;


	fScint_x = 6.*cm;
	fScint_y = 6.*cm;
	fScint_z = 6.*cm;

	for (int ii=0;ii<6;ii++){
		for (int jj=0;jj<MAX_DETECTORS;jj++){

			fPhotoDetectorSizeX[ii][jj]=5.*cm;
			fPhotoDetectorSizeY[ii][jj]=5.*cm;
			fPhotoDetectorCenterX[ii][jj]=0.*cm;
			fPhotoDetectorCenterY[ii][jj]=0.*cm;
			fNPixelsX[ii][jj]=1;
			fNPixelsY[ii][jj]=1;
			fPixelSizeX[ii][jj]=fPhotoDetectorSizeX[ii][jj];
			fPixelSizeY[ii][jj]=fPhotoDetectorSizeY[ii][jj];

			fCouplingThickness[ii][jj]=1.*mm;
			fCouplingN[ii][jj]=1.5;

			fPhotoQE[ii][jj]=0.2;
			fPhotoReflectivity[ii][jj]=0.1;
		}
		fFaceReflectivity[ii]=.1;
	}

	/*EJ230*/
	fEJ230_LY=9700./MeV;            //from the datasheet
	fEJ230_FastTimeConstant=1.5*ns; //from the datasheet


	fPmtPlaced=false;


	fMaxStep=0.5*mm;

	G4RunManager::GetRunManager()->ReinitializeGeometry();
}






//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void OpNoviceDetectorConstruction::makeEJ230(){

	/*Physical properties*/
	G4double density=1.023*g/cm3;
	G4double Hnum=5.15E22/cm3;
	G4double Cnum=4.69E22/cm3;
	G4double Hw=(Hnum*fH->GetA())/(Avogadro*density);
	G4double Cw=(Cnum*fC->GetA())/(Avogadro*density);

	const G4int numRI = 2;
	G4double ePhotonRI[numRI] = {1.*eV,10.*eV};
	G4double RI[numRI] = {fDetectorLight->getRindex(),fDetectorLight->getRindex()};

	G4double absLength[numRI] = {100.*cm,100.*cm}; //temporary

	const G4int numFastLY = 101;
	//as Reported in the datasheet
	G4double LambdaPhotLY[numFastLY] = {351.527*nm, 354.962*nm, 359.160*nm, 361.196*nm, 362.595*nm, 364.122*nm, 365.649*nm, 367.176*nm, 368.575*nm, 369.720*nm, 370.738*nm, 371.883*nm, 372.519*nm, 373.282*nm, 374.300*nm, 374.809*nm, 375.827*nm, 376.463*nm, 377.226*nm, 377.863*nm, 378.626*nm, 379.517*nm, 380.153*nm, 380.534*nm, 381.679*nm, 382.188*nm, 383.333*nm, 384.606*nm, 385.623*nm, 386.768*nm, 388.041*nm, 389.313*nm, 391.221*nm, 393.130*nm, 395.038*nm, 396.056*nm, 397.455*nm, 398.473*nm, 399.746*nm, 400.636*nm, 401.272*nm, 402.290*nm, 403.053*nm, 404.198*nm, 404.962*nm, 405.725*nm, 406.616*nm, 407.761*nm, 408.906*nm, 409.542*nm, 410.560*nm, 411.705*nm, 413.232*nm, 413.868*nm, 414.504*nm, 415.649*nm, 416.667*nm, 418.066*nm, 419.338*nm, 420.356*nm, 421.247*nm, 422.265*nm, 423.155*nm, 424.173*nm, 425.191*nm, 426.590*nm, 428.626*nm, 430.025*nm, 430.789*nm, 431.807*nm, 432.316*nm, 433.588*nm, 435.115*nm, 436.896*nm, 438.295*nm, 440.331*nm, 443.257*nm, 444.911*nm, 445.802*nm, 448.346*nm, 449.618*nm, 451.527*nm, 453.562*nm, 455.598*nm, 457.125*nm, 459.542*nm, 461.705*nm, 464.758*nm, 467.430*nm, 470.865*nm, 473.155*nm, 475.954*nm, 478.371*nm, 481.552*nm, 484.606*nm, 487.659*nm, 489.567*nm, 491.858*nm, 494.020*nm, 495.802*nm, 498.219*nm};
	G4double PhotLYFast[numFastLY] = {0.00881057, 0.0176211, 0.0396476, 0.0558003, 0.0734214, 0.0939794, 0.120411, 0.154185, 0.185022, 0.221733, 0.249633, 0.298091, 0.348018, 0.395007, 0.447871, 0.493392, 0.550661, 0.603524, 0.635830, 0.678414, 0.728341, 0.762115, 0.795888, 0.822320, 0.857562, 0.894273, 0.922173, 0.947137, 0.963289, 0.976505, 0.989721, 0.995595, 0.997063, 0.986784, 0.975037, 0.963289, 0.948605, 0.928047, 0.908957, 0.885463, 0.872247, 0.848752, 0.825257, 0.797357, 0.773862, 0.751836, 0.728341, 0.698972, 0.675477, 0.656388, 0.627019, 0.603524, 0.568282, 0.553598, 0.537445, 0.511013, 0.488987, 0.471366, 0.440529, 0.421439, 0.405286, 0.396476, 0.378855, 0.368576, 0.348018, 0.330396, 0.302496, 0.287812, 0.273128, 0.267254, 0.252570, 0.246696, 0.232012, 0.218796, 0.205580, 0.183554, 0.160059, 0.145374, 0.140969, 0.127753, 0.114537, 0.107195, 0.0969163, 0.0851689, 0.0792952, 0.0734214, 0.0646109, 0.0587372, 0.0543319, 0.0455213, 0.0440529, 0.0367107, 0.0352423, 0.0264317, 0.0220264, 0.0205580, 0.0176211, 0.0161527, 0.0146843, 0.0161527, 0.0146843};
	G4double ePhotonLY[numFastLY]; 
	for (int ii=0;ii<numFastLY;ii++) ePhotonLY[ii]=h_Planck*c_light/LambdaPhotLY[ii];




	/*Set Physical properties*/
	fEJ230=new G4Material("EJ230",density,2,kStateSolid);
	fEJ230->AddElement(fH,Hw);
	fEJ230->AddElement(fC,1.-Hw);	

	/*Create the propertie table and set it*/
	G4MaterialPropertiesTable* EJ230_mt = new G4MaterialPropertiesTable();

	EJ230_mt->AddProperty("RINDEX",ePhotonRI,RI,numRI);
	EJ230_mt->AddConstProperty("SCINTILLATIONYIELD",fEJ230_LY);
	EJ230_mt->AddConstProperty("FASTTIMECONSTANT",fEJ230_FastTimeConstant);
	EJ230_mt->AddConstProperty("RESOLUTIONSCALE",1.); //this is to broaden the number of optical photons : scale*sqrt(mean_photons)
	EJ230_mt->AddProperty("FASTCOMPONENT",ePhotonLY,PhotLYFast,numFastLY);

	EJ230_mt->AddProperty("ABSLENGTH",ePhotonRI,absLength,numRI);

	fEJ230->SetMaterialPropertiesTable(EJ230_mt);
}


void  OpNoviceDetectorConstruction::makeH8500materials(){
	//H8500 Glass
	fH8500C03GlassWindow=new G4Material("H8500GlassWindow",2.23*g/cm3, 6);
	fH8500C03GlassWindow->AddElement(fB,0.040064);
	fH8500C03GlassWindow->AddElement(fO,0.539562);
	fH8500C03GlassWindow->AddElement(fNa,0.028191);
	fH8500C03GlassWindow->AddElement(fAl,0.011644);
	fH8500C03GlassWindow->AddElement(fSi,0.377220);
	fH8500C03GlassWindow->AddElement(fK,0.003321);



	//H8500C-03 PMT glass
	/*Hamamatsu private communication*/
	const int numGlassRindexH8500C03=21;
	G4double lambdaGlassRindexH8500C03[numGlassRindexH8500C03]={300*nm,310*nm,320*nm,330*nm,340*nm,350*nm,360*nm,370*nm,380*nm,390*nm,400*nm,410*nm,420*nm,430*nm,440*nm,450*nm,460*nm,470*nm,480*nm,490*nm,500*nm};
	G4double eGlassRindexH8500C03[numGlassRindexH8500C03];
	for (int ii=0;ii<numGlassRindexH8500C03;ii++) eGlassRindexH8500C03[ii]=h_Planck*c_light/lambdaGlassRindexH8500C03[ii];
	G4double GlassRindexH8500C03[numGlassRindexH8500C03]={1.504,1.503,1.504,1.504,1.503,1.502,1.495,1.494,1.489,1.481,1.477,1.473,1.472,1.47,1.468,1.467,1.468,1.465,1.47,1.469,1.473};
	G4MaterialPropertiesTable* fH8500C03GlassWindow_mt = new G4MaterialPropertiesTable();
	fH8500C03GlassWindow_mt->AddProperty("RINDEX",eGlassRindexH8500C03,GlassRindexH8500C03,numGlassRindexH8500C03);
	fH8500C03GlassWindow->SetMaterialPropertiesTable(fH8500C03GlassWindow_mt);


}




G4LogicalVolume* OpNoviceDetectorConstruction::buildH8500(int iface, int idetector){
	//This is the function to create the H8500 logical, including all the sub-components
	//Construct it so that the glass is at z=const, in the xy plane, and the glass starts at z=+14*mm
	//First, build the box
	fH8500box_x=H8500FULLSIZE*cm;
	fH8500box_y=H8500FULLSIZE*cm;
	fH8500box_z=detectorThickness;
	fH8500_box = new G4Box("H8500Box",fH8500box_x/2,fH8500box_y/2,fH8500box_z/2);
	G4LogicalVolume* H8500_log = new G4LogicalVolume(fH8500_box,fVacuum,"H8500Log",0,0,0);

	//Then, build the internal glass, that is active (photocathode is deposited on it)
	G4double int_glass_x=H8500ACTIVESIZE*cm;
	G4double int_glass_y=H8500ACTIVESIZE*cm;
	G4double int_glass_z=H8500GLASSTHICKNESS*cm;
	fH8500IntGlass_box = new G4Box("H8500GlassInt",int_glass_x/2,int_glass_y/2,int_glass_z/2);
	G4LogicalVolume* H8500IntGlass_log = new G4LogicalVolume(fH8500IntGlass_box,fH8500C03GlassWindow,"H8500GlassInt",0,0,0);
	//place it wrt the mother
	fH8500IntGlass_phys = new G4PVPlacement(0,G4ThreeVector(0.,0.,fH8500box_z/2-int_glass_z/2),H8500IntGlass_log,Form("H8500GlassInt_%i_%i",iface,idetector),H8500_log,false,0);
	//visual attributes
	G4VisAttributes* VisAtt1 = new G4VisAttributes(G4Colour(0.,1.,1.,.6));
	VisAtt1->SetForceSolid(true);
	H8500IntGlass_log->SetVisAttributes(VisAtt1);

	//Then, build the external glass, not active
	G4double ext_glass_x=H8500FULLSIZE*cm;
	G4double ext_glass_y=H8500FULLSIZE*cm;
	G4double ext_glass_z=H8500GLASSTHICKNESS*cm;

	G4Box *H8500SubtractionGlass_box1 = new G4Box("H8500SubtractionGlass1",ext_glass_x/2,ext_glass_y/2,ext_glass_z/2);
	G4Box *H8500SubtractionGlass_box2 = new G4Box("H8500SubtractionGlass2",int_glass_x/2,int_glass_y/2,int_glass_z); //should be int_glass_z/2, but this helps the subtraction
	G4SubtractionSolid* H8500ExtGlass_box=new G4SubtractionSolid("H8500GlassExt",H8500SubtractionGlass_box1,H8500SubtractionGlass_box2);

	//smooth it



	G4LogicalVolume* H8500ExtGlass_log = new G4LogicalVolume(H8500ExtGlass_box,fH8500C03GlassWindow,"H8500GlassExt",0,0,0);
	//place it wrt the mother
	G4VPhysicalVolume* H8500ExtGlass_phys = new G4PVPlacement(0,G4ThreeVector(0.,0.,fH8500box_z/2-ext_glass_z/2),H8500ExtGlass_log,"H8500GlassExt",H8500_log,false,0);
	//visual attributes
	G4VisAttributes* VisAtt2 = new G4VisAttributes(G4Colour(0.,.4,.6,.6));
	VisAtt2->SetForceSolid(true);
	H8500ExtGlass_log->SetVisAttributes(VisAtt2);

	//Then build the photo-cathode, that it is used only for the surface.
	G4double photo_x= int_glass_x;
	G4double photo_y= int_glass_y;
	G4double photo_z=.1*mm;

	fH8500Photo_box=new G4Box("H8500Photocathode",photo_x/2,photo_y/2,photo_z/2);
	fH8500Photo_log = new G4LogicalVolume(fH8500Photo_box,fAir,"H8500Photocathode",0,0,0); //material is irrelevant, since I define surface properties!
	fH8500Photo_phys= new G4PVPlacement(0,G4ThreeVector(0.,0.,fH8500box_z/2-int_glass_z-photo_z/2),fH8500Photo_log,"H8500Photocathode",H8500_log,false,0);
	G4VisAttributes* VisAtt3 = new G4VisAttributes(G4Colour(0.5,0.5,0.5));
	VisAtt3->SetForceSolid(true);
	fH8500Photo_log->SetVisAttributes(VisAtt3);

	return H8500_log;
}
















