#!/usr/local/bin/python

import string,math,os,sys,subprocess,time
import ROOT
from ROOT import * 

#Initialization part for variables
#run on the farm?
doFarm=True

doGeant=True
doMatrix=True
doVoxelVolume=True

queue_name="long"
resources="rusage[mem=500,swp=500] "
arch_name="sl6_64"
#work dir
#this is the folder where the data input files are located.
workDir=os.environ['OPTO']+"/MCrun/detector5e"
saveDir=workDir+"/matrix2"
#Executables
geantExe=os.environ['OPTO']+"/bin/OpNoviceExe" 
matrixExe=os.environ['OPTO']+"/bin/ReconstructionNew"
steeringName=workDir+"/matrixMCcalculation.xml"
writeMacroName=os.environ['OPTO']+"/macros/writeMatrix.C"

#dimensions, in cm -> These are re-loaded from the detector now!!
Lx = 6.0
Ly = 6.0
Lz = 6.0
#divisions for voxels
Nx = 6
Ny = 6
Nz = 6

#which detector
detectorName=workDir+"/PrototypeGeometry.dat"
#which particle
particle="alpha"
#which energy
energy="1 MeV"

#How many events
Nevents=10000


if not os.path.exists(saveDir):
	os.makedirs(saveDir)
	os.makedirs(saveDir+"/root")
	os.makedirs(saveDir+"/ps")
	os.makedirs(saveDir+"/pixels")
	os.makedirs(saveDir+"/run_macro")

if not os.path.exists(saveDir+"/root"):
	os.makedirs(saveDir+"/root")
      	
if not os.path.exists(saveDir+"/ps"):
        os.makedirs(saveDir+"/ps")
	
if not os.path.exists(saveDir+"/pixels"):
        os.makedirs(saveDir+"/pixels")

if not os.path.exists(saveDir+"/run_macro"):
        os.makedirs(saveDir+"/run_macro")



command = "cd "+saveDir+" ; rm -rf *log* ; cd .."
os.system(command)


#Let's start
#Go to the saveDir and work there
os.chdir(saveDir)      

#Remove the matrix file if it exists
command = "rm -f matrix.root"
os.system(command)



gSystem.Load("$OPTO/lib/libCommonClassesDict.so")
detector = TDetectorLight(workDir+"/PrototypeGeometry.dat");

detector.Print();

Lx = detector.getScintSizeX();
Ly = detector.getScintSizeY();
Lz = detector.getScintSizeZ();

fVoxels = TFile("matrix.root","recreate");
hVoxels = TH3D("hVoxels","hVoxels",Nx,-Lx/2,Lx/2,Ny,-Ly/2,Ly/2,Nz,-Lz/2,Lz/2);
hVoxels.Write()
procs=[]
for iz in range(0,Nz):
	for iy in range(0,Ny):
		for ix in range(0,Nx):
			ibin=ix+Nx*iy+Nx*Ny*iz #as defined in my notebook
		
			
			centerX=hVoxels.GetXaxis().GetBinCenter(ix+1);
			centerY=hVoxels.GetYaxis().GetBinCenter(iy+1);
			centerZ=hVoxels.GetZaxis().GetBinCenter(iz+1);



			print "Bin "+str(ibin)+": "+str(ix)+" "+str(iy)+" "+str(iz)
			print "Center: "+str(centerX)+" "+str(centerY)+" "+str(centerZ)
			
			if (doGeant):
				#	Open the macro file and fill it
				macroFileName=saveDir+"/run_macro/macro"+str(ibin)+".run"
				macroFile=open(macroFileName,'w')	
				 # define the file-name!!
				line="/OpNovice/run/setRunName run_"+str(ibin)+"\n"
				macroFile.write(line)
				# define the particle
				line="/gps/particle "+particle+"\n"
				macroFile.write(line)
				# define the energy
				line="/gps/energy "+energy+"\n"
				macroFile.write(line)
				# set up the generator
				if (doVoxelVolume):
					line="/gps/pos/type Volume \n"
					macroFile.write(line)
					line="/gps/pos/shape Para \n"
					macroFile.write(line)
					# the volume is the voxel volume
					line="/gps/pos/halfx "+str(Lx/(2*Nx))+"\n"
					macroFile.write(line)
					line="/gps/pos/halfy "+str(Ly/(2*Ny))+"\n"
		        		macroFile.write(line)
					line="/gps/pos/halfz "+str(Lz/(2*Nz))+"\n"
					macroFile.write(line)
					# angles
					line="/gps/ang/type iso"+"\n"
					macroFile.write(line)
				# the center
				line="/gps/pos/centre "+str(centerX)+" "+str(centerY)+" "+str(centerZ)+" cm"+"\n"				
				macroFile.write(line)
				# event number
				line="/run/beamOn "+str(Nevents)+"\n"
				macroFile.write(line)
				macroFile.close()
				

			# now prepare the run file
			runFileName=saveDir+"/run_macro/run_"+str(ibin)+".csh"
			runFile=open(runFileName,'w')
			runFile.write("#!/bin/tcsh -f\n")				
			runFile.write("cd "+workDir+"\n");
			if (doGeant):
				runFile.write("cd "+saveDir+"\n"); #go do the saveDir
				runFile.write(geantExe+" -m "+macroFileName+" -det "+detectorName+"\n");#launch MC
				runFile.write("mv run_"+str(ibin)+"_0.root "+"root/ \n"); #mv the root file to saveDir/root		
				runFile.write("cd "+saveDir+"\n"); #cd to the saveDir
            
			if (doMatrix):
				runFile.write("cd "+saveDir+"\n"); #go to the saveDir
				runFile.write(matrixExe+" -s "+steeringName+" -DvoxelID="+str(ibin)+" root/run_"+str(ibin)+"_0.root"+"\n"); #go with the analysis
				runFile.write("mv voxel_"+str(ibin)+".dat "+saveDir+"/pixels"+ "\n"); #mv the out file to saveDir/pixels
          
			runFile.write("cd "+saveDir+"\n");
			runFile.close()
			os.chmod(runFileName,0755)
time.sleep(1);
#redo the loop and run!
for iz in range(0,Nz):
	for iy in range(0,Ny):
		for ix in range(0,Nx):
			ibin=ix+Nx*iy+Nx*Ny*iz #as defined in my notebook
			print "Execute bin "+str(ibin)+": "+str(ix)+" "+str(iy)+" "+str(iz)
			runFileName=saveDir+"/run_macro/run_"+str(ibin)+".csh"

			if (doFarm):
				if (len(resources)>0):
					arg="-q "+queue_name+" -P "+arch_name+" -R \""+resources+"\" -e "+saveDir+"/log"+str(ibin)+".e"+" -o "+saveDir+"/log"+str(ibin)+".o "+runFileName
				else:
					arg="-q "+queue_name+" -P "+arch_name+" -e "+saveDir+"/log"+str(ibin)+".e"+" -o "+saveDir+"/log"+str(ibin)+".o "+runFileName
				procs.append(subprocess.Popen("bsub -K "+arg,shell=True));	
				time.sleep(0.2);
			else:
				subprocess.call([runFileName],shell=True)
			
if (doFarm):
	for p in procs:
		p.wait()

print "DONE"
fVoxels.Close()
gROOT.LoadMacro(writeMacroName)
writeMatrix(detectorName,saveDir+"/pixels");

 
