#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
cd run1
root -l -q -b  ../doPixels.C\(404\) 
mv run404.ps matrix0/ps
mv run404.out matrix0/pixels
cd ..
