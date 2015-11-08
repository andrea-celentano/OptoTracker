#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
cd run0
root -l -q -b  ../doPixels.C\(651\) 
mv run651.ps matrix0/ps
mv run651.out matrix0/pixels
cd ..
