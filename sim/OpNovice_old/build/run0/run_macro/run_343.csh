#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
cd run0
root -l -q -b  ../doPixels.C\(343\) 
mv run343.ps matrix0/ps
mv run343.out matrix0/pixels
cd ..
