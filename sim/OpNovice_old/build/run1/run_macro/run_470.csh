#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
cd run1
root -l -q -b  ../doPixels.C\(470\) 
mv run470.ps matrix0/ps
mv run470.out matrix0/pixels
cd ..
