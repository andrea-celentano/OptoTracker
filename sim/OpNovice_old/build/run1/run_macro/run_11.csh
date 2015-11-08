#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
cd run1
root -l -q -b  ../doPixels.C\(11\) 
mv run11.ps matrix0/ps
mv run11.out matrix0/pixels
cd ..
