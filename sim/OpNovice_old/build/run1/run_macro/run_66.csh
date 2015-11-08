#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
cd run1
root -l -q -b  ../doPixels.C\(66\) 
mv run66.ps matrix0/ps
mv run66.out matrix0/pixels
cd ..
