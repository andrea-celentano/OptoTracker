#!/usr/local/bin/python

import string,math,os,sys,subprocess

#Initialization part for variables
#run on the farm?
doFarm=True

doGeant=True
doMatrix=True


queue_name="long"
resources="rusage[mem=500,swp=500] "
arch_name="sl6_64"
#work dir
#this is the folder where the data input files are located.
workDir=os.environ['OPTO']+"/MCrun/detector3/"
saveDir="run0"
matrixDir="matrix"
#Executables
geantExe=os.environ['OPTO']+"/bin/OpNoviceExe" 
matrixExe=os.environ['OPTO']+"/bin/ReconstructionNew"
steeringName=workDir+"matrixAnalysis.xml"
#dimensions, in cm -> This is used to "move" the particle!
Lx = 6.0
Ly = 6.0
Lz = 6.0
#divisions for voxels
Nx = 5
Ny = 5
Nz = 5

#which detector
detectorName=workDir+"/PrototypeGeometry.dat"
#which particle
particle="alpha"
#which energy
energy="1 MeV"

#How many events
Nevents=100

command = "rm log*"
os.system(command)
command = "rm run*.csh"
os.system(command)

if not os.path.exists(workDir+saveDir):
	os.makedirs(workDir+saveDir)
	
if not os.path.exists(workDir+saveDir+"/root"):
	os.makedirs(workDir+saveDir+"/root")
	
if not os.path.exists(workDir+saveDir+"/"+matrixDir):
	os.makedirs(workDir+saveDir+"/"+matrixDir)   
	os.makedirs(workDir+saveDir+"/"+matrixDir+"/ps")
	os.makedirs(workDir+saveDir+"/"+matrixDir+"/pixels")
	
if not os.path.exists(workDir+saveDir+"/run_macro"):
	os.makedirs(workDir+saveDir+"/run_macro")
	
#command = "cd "+workDir+saveDir+" ; ln -s ../libOpNoviceClassesDict.so ; cd .."
#os.system(command)
      


for iz in range(0,Nz):
	for iy in range(0,Ny):
		for ix in range(0,Nx):
			ibin=ix+Nx*iy+Nx*Ny*iz #as defined in my notebook
			centerX=-Lx/2+ix*(Lx/(Nx))+Lx/(2*Nx)
			centerY=-Ly/2+iy*(Ly/(Ny))+Ly/(2*Ny)
			centerZ=-Lz/2+iz*(Lz/(Nz))+Lz/(2*Nz)

			print "Bin "+str(ibin)+": "+str(ix)+" "+str(iy)+" "+str(iz)
			print "Center: "+str(centerX)+" "+str(centerY)+" "+str(centerZ)
			
			if (doGeant):
				#	Open the macro file and fill it
				macroFileName=workDir+saveDir+"/run_macro/macro"+str(ibin)+".run"
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
			runFileName=workDir+saveDir+"/run_macro/run_"+str(ibin)+".csh"
			runFile=open(runFileName,'w')
			runFile.write("#!/bin/tcsh -f\n")				
			runFile.write("cd "+workDir+"\n");
			if (doGeant):
				runFile.write("cd "+saveDir+"\n"); #go do the saveDir
				runFile.write(geantExe+" -m "+macroFileName+" -det "+detectorName+"\n");#launch MC
				runFile.write("mv run_"+str(ibin)+"_0.root "+"root/ \n"); #mv the root file to saveDir		
				runFile.write("cd "+workDir+"\n"); #cd to the workDir
            
			if (doMatrix):
				runFile.write("cd "+saveDir+"\n"); #go to the saveDir
				runFile.write(matrixExe+" -s "+steeringName+" -DvoxelID="+str(ibin)+" root/run_"+str(ibin)+"_0.root"+"\n"); #go with the analysis
				runFile.write("mv voxel_"+str(ibin)+".dat "+matrixDir+"/pixels"+ "\n"); #mv the out file
          
			runFile.write("cd "+workDir+"\n");
			os.chmod(runFileName,0755)

			if (doFarm):
				if (len(resources)>0):
					arg="-q "+queue_name+" -P "+arch_name+" -R \""+resources+"\" -e "+workDir+saveDir+"/log"+str(ibin)+".e"+" -o "+workDir+saveDir+"/log"+str(ibin)+".o "+runFileName
				else:
					arg="-q "+queue_name+" -P "+arch_name+" -e "+workDir+saveDir+"/log"+str(ibin)+".e"+" -o "+workDir+saveDir+"/log"+str(ibin)+".o "+runFileName
					subprocess.call("bsub "+arg,shell=True)
			else:
				subprocess.call([runFileName],shell=True)
                     
            
