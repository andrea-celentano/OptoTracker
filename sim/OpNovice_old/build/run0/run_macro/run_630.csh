#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
cd run0
root -l -q -b  ../doPixels.C\(630\) 
mv run630.ps matrix0/ps
mv run630.out matrix0/pixels
cd ..
