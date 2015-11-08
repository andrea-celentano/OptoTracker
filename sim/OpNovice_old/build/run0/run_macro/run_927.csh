#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
cd run0
root -l -q -b  ../doPixels.C\(927\) 
mv run927.ps matrix0/ps
mv run927.out matrix0/pixels
cd ..
