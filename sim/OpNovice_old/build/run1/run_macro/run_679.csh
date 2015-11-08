#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
cd run1
root -l -q -b  ../doPixels.C\(679\) 
mv run679.ps matrix0/ps
mv run679.out matrix0/pixels
cd ..
