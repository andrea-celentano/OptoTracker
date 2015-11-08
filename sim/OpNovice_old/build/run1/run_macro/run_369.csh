#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
cd run1
root -l -q -b  ../doPixels.C\(369\) 
mv run369.ps matrix0/ps
mv run369.out matrix0/pixels
cd ..
