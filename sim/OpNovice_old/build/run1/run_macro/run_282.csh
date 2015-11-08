#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
cd run1
root -l -q -b  ../doPixels.C\(282\) 
mv run282.ps matrix0/ps
mv run282.out matrix0/pixels
cd ..
