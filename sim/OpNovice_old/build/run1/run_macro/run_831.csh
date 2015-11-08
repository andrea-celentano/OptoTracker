#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
cd run1
root -l -q -b  ../doPixels.C\(831\) 
mv run831.ps matrix0/ps
mv run831.out matrix0/pixels
cd ..
