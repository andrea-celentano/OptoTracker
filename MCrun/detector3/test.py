#!/usr/local/bin/python

import string,math,os,sys,subprocess
import ROOT
from ROOT import * 

writeMacroName=os.environ['OPTO']+"/macros/writeMatrix.C"

gSystem.Load("$OPTO/lib/libCommonClassesDict.so")
detector = TDetectorLight("PrototypeGeometry.dat");

detector.Print();
#
Lx = detector.getScintSizeX();
Ly = detector.getScintSizeY();
Lz = detector.getScintSizeZ();


gROOT.LoadMacro(writeMacroName)
base="run0/matrix0/pixels/"
writeMatrix(base);
