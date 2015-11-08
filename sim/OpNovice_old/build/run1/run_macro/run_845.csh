#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
cd run1
root -l -q -b  ../doPixels.C\(845\) 
mv run845.ps matrix0/ps
mv run845.out matrix0/pixels
cd ..
