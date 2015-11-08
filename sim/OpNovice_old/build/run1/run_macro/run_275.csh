#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
cd run1
root -l -q -b  ../doPixels.C\(275\) 
mv run275.ps matrix0/ps
mv run275.out matrix0/pixels
cd ..
