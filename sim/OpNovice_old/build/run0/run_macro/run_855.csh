#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
cd run0
root -l -q -b  ../doPixels.C\(855\) 
mv run855.ps matrix0/ps
mv run855.out matrix0/pixels
cd ..
