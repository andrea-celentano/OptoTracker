#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
cd run1
root -l -q -b  ../doPixels.C\(587\) 
mv run587.ps matrix0/ps
mv run587.out matrix0/pixels
cd ..
