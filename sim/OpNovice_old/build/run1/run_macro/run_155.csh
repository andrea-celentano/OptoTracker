#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
cd run1
root -l -q -b  ../doPixels.C\(155\) 
mv run155.ps matrix0/ps
mv run155.out matrix0/pixels
cd ..
