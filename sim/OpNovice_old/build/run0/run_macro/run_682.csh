#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
cd run0
root -l -q -b  ../doPixels.C\(682\) 
mv run682.ps matrix0/ps
mv run682.out matrix0/pixels
cd ..
