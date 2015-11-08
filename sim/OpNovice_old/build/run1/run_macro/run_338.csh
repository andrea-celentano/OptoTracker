#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
cd run1
root -l -q -b  ../doPixels.C\(338\) 
mv run338.ps matrix0/ps
mv run338.out matrix0/pixels
cd ..
