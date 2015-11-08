#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
cd run0
root -l -q -b  ../doPixels.C\(169\) 
mv run169.ps matrix0/ps
mv run169.out matrix0/pixels
cd ..
