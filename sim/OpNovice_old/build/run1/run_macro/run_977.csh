#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
cd run1
root -l -q -b  ../doPixels.C\(977\) 
mv run977.ps matrix0/ps
mv run977.out matrix0/pixels
cd ..
