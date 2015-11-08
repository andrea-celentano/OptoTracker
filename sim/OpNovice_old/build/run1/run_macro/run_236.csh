#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
cd run1
root -l -q -b  ../doPixels.C\(236\) 
mv run236.ps matrix0/ps
mv run236.out matrix0/pixels
cd ..
