#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
cd run0
root -l -q -b  ../doPixels.C\(483\) 
mv run483.ps matrix0/ps
mv run483.out matrix0/pixels
cd ..
