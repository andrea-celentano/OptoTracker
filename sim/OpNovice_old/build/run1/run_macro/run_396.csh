#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
cd run1
root -l -q -b  ../doPixels.C\(396\) 
mv run396.ps matrix0/ps
mv run396.out matrix0/pixels
cd ..
