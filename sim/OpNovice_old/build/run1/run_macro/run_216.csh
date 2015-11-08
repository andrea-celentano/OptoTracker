#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
cd run1
root -l -q -b  ../doPixels.C\(216\) 
mv run216.ps matrix0/ps
mv run216.out matrix0/pixels
cd ..
