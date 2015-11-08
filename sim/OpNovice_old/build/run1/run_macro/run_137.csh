#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
cd run1
root -l -q -b  ../doPixels.C\(137\) 
mv run137.ps matrix0/ps
mv run137.out matrix0/pixels
cd ..
