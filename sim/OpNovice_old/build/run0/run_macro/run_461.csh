#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
cd run0
root -l -q -b  ../doPixels.C\(461\) 
mv run461.ps matrix0/ps
mv run461.out matrix0/pixels
cd ..
