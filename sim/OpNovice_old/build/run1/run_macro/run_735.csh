#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
cd run1
root -l -q -b  ../doPixels.C\(735\) 
mv run735.ps matrix0/ps
mv run735.out matrix0/pixels
cd ..
