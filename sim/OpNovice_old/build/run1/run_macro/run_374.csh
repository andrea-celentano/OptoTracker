#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
cd run1
root -l -q -b  ../doPixels.C\(374\) 
mv run374.ps matrix0/ps
mv run374.out matrix0/pixels
cd ..
