#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
cd run1
root -l -q -b  ../doPixels.C\(145\) 
mv run145.ps matrix0/ps
mv run145.out matrix0/pixels
cd ..
