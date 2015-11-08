#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
cd run0
root -l -q -b  ../doPixels.C\(37\) 
mv run37.ps matrix0/ps
mv run37.out matrix0/pixels
cd ..
