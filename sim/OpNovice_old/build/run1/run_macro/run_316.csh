#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
cd run1
root -l -q -b  ../doPixels.C\(316\) 
mv run316.ps matrix0/ps
mv run316.out matrix0/pixels
cd ..
