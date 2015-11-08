#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
cd run1
root -l -q -b  ../doPixels.C\(129\) 
mv run129.ps matrix0/ps
mv run129.out matrix0/pixels
cd ..
