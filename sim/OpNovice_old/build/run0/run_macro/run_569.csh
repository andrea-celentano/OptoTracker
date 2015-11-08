#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
cd run0
root -l -q -b  ../doPixels.C\(569\) 
mv run569.ps matrix0/ps
mv run569.out matrix0/pixels
cd ..
