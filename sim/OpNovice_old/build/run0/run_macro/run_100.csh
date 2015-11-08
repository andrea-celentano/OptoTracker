#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
cd run0
root -l -q -b  ../doPixels.C\(100\) 
mv run100.ps matrix0/ps
mv run100.out matrix0/pixels
cd ..
