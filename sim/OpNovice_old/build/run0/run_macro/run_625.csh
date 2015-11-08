#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
cd run0
root -l -q -b  ../doPixels.C\(625\) 
mv run625.ps matrix0/ps
mv run625.out matrix0/pixels
cd ..
