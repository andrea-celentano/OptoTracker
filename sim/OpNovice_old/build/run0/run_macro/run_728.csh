#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
cd run0
root -l -q -b  ../doPixels.C\(728\) 
mv run728.ps matrix0/ps
mv run728.out matrix0/pixels
cd ..
