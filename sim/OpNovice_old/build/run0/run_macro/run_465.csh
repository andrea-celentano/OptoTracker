#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
cd run0
root -l -q -b  ../doPixels.C\(465\) 
mv run465.ps matrix0/ps
mv run465.out matrix0/pixels
cd ..