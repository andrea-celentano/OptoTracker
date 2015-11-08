#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
cd run0
root -l -q -b  ../doPixels.C\(454\) 
mv run454.ps matrix0/ps
mv run454.out matrix0/pixels
cd ..
