#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
cd run0
root -l -q -b  ../doPixels.C\(99\) 
mv run99.ps matrix0/ps
mv run99.out matrix0/pixels
cd ..
