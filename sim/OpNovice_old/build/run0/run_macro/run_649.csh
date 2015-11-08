#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
cd run0
root -l -q -b  ../doPixels.C\(649\) 
mv run649.ps matrix0/ps
mv run649.out matrix0/pixels
cd ..
