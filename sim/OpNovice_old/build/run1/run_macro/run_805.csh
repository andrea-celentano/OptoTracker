#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
cd run1
root -l -q -b  ../doPixels.C\(805\) 
mv run805.ps matrix0/ps
mv run805.out matrix0/pixels
cd ..
