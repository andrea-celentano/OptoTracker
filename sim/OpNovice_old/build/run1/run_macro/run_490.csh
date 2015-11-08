#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
cd run1
root -l -q -b  ../doPixels.C\(490\) 
mv run490.ps matrix0/ps
mv run490.out matrix0/pixels
cd ..
