#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
cd run1
root -l -q -b  ../doPixels.C\(72\) 
mv run72.ps matrix0/ps
mv run72.out matrix0/pixels
cd ..
