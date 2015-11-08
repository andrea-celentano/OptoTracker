#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
cd run0
root -l -q -b  ../doPixels.C\(136\) 
mv run136.ps matrix0/ps
mv run136.out matrix0/pixels
cd ..
