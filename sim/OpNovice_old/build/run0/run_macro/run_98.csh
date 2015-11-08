#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
cd run0
root -l -q -b  ../doPixels.C\(98\) 
mv run98.ps matrix0/ps
mv run98.out matrix0/pixels
cd ..
