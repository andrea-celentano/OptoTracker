#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
cd run1
root -l -q -b  ../doPixels.C\(835\) 
mv run835.ps matrix0/ps
mv run835.out matrix0/pixels
cd ..
