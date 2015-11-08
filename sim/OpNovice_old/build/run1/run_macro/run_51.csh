#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
cd run1
root -l -q -b  ../doPixels.C\(51\) 
mv run51.ps matrix0/ps
mv run51.out matrix0/pixels
cd ..
