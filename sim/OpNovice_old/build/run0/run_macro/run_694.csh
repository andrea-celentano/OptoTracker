#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
cd run0
root -l -q -b  ../doPixels.C\(694\) 
mv run694.ps matrix0/ps
mv run694.out matrix0/pixels
cd ..
