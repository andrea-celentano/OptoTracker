#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
cd run1
root -l -q -b  ../doPixels.C\(972\) 
mv run972.ps matrix0/ps
mv run972.out matrix0/pixels
cd ..
