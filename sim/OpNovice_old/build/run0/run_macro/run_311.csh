#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
cd run0
root -l -q -b  ../doPixels.C\(311\) 
mv run311.ps matrix0/ps
mv run311.out matrix0/pixels
cd ..
