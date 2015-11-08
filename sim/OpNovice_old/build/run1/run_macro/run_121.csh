#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
cd run1
root -l -q -b  ../doPixels.C\(121\) 
mv run121.ps matrix0/ps
mv run121.out matrix0/pixels
cd ..
