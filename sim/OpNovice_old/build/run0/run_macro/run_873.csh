#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
cd run0
root -l -q -b  ../doPixels.C\(873\) 
mv run873.ps matrix0/ps
mv run873.out matrix0/pixels
cd ..
