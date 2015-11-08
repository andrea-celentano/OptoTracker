#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
cd run1
root -l -q -b  ../doPixels.C\(561\) 
mv run561.ps matrix0/ps
mv run561.out matrix0/pixels
cd ..
