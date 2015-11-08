#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
cd run1
root -l -q -b  ../doPixels.C\(0\) 
mv run0.ps matrix0/ps
mv run0.out matrix0/pixels
cd ..
