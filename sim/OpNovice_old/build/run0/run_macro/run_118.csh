#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
cd run0
root -l -q -b  ../doPixels.C\(118\) 
mv run118.ps matrix0/ps
mv run118.out matrix0/pixels
cd ..
