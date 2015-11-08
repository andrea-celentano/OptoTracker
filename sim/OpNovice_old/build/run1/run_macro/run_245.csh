#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
cd run1
root -l -q -b  ../doPixels.C\(245\) 
mv run245.ps matrix0/ps
mv run245.out matrix0/pixels
cd ..
