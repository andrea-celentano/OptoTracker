#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
cd run0
root -l -q -b  ../doPixels.C\(759\) 
mv run759.ps matrix0/ps
mv run759.out matrix0/pixels
cd ..
