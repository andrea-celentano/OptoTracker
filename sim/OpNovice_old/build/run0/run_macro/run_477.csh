#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
cd run0
root -l -q -b  ../doPixels.C\(477\) 
mv run477.ps matrix0/ps
mv run477.out matrix0/pixels
cd ..
