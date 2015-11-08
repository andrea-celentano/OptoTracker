#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
cd run0
root -l -q -b  ../doPixels.C\(748\) 
mv run748.ps matrix0/ps
mv run748.out matrix0/pixels
cd ..
