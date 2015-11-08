#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
cd run0
root -l -q -b  ../doPixels.C\(494\) 
mv run494.ps matrix0/ps
mv run494.out matrix0/pixels
cd ..
