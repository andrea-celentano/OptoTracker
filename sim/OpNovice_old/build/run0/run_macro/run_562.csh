#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
cd run0
root -l -q -b  ../doPixels.C\(562\) 
mv run562.ps matrix0/ps
mv run562.out matrix0/pixels
cd ..
