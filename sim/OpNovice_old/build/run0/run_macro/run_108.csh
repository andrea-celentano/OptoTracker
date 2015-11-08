#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
cd run0
root -l -q -b  ../doPixels.C\(108\) 
mv run108.ps matrix0/ps
mv run108.out matrix0/pixels
cd ..
