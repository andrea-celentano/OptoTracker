#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
cd run1
root -l -q -b  ../doPixels.C\(272\) 
mv run272.ps matrix0/ps
mv run272.out matrix0/pixels
cd ..
