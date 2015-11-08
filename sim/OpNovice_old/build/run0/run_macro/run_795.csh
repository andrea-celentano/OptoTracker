#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
cd run0
root -l -q -b  ../doPixels.C\(795\) 
mv run795.ps matrix0/ps
mv run795.out matrix0/pixels
cd ..
