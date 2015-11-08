#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
cd run0
root -l -q -b  ../doPixels.C\(441\) 
mv run441.ps matrix0/ps
mv run441.out matrix0/pixels
cd ..
