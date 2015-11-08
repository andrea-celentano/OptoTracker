#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
cd run1
root -l -q -b  ../doPixels.C\(142\) 
mv run142.ps matrix0/ps
mv run142.out matrix0/pixels
cd ..
