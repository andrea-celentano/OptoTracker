#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
cd run1
root -l -q -b  ../doPixels.C\(604\) 
mv run604.ps matrix0/ps
mv run604.out matrix0/pixels
cd ..
