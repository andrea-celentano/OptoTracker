#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
cd run0
root -l -q -b  ../doPixels.C\(202\) 
mv run202.ps matrix0/ps
mv run202.out matrix0/pixels
cd ..
