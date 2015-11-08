#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
cd run1
root -l -q -b  ../doPixels.C\(93\) 
mv run93.ps matrix0/ps
mv run93.out matrix0/pixels
cd ..
