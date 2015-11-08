#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
cd run1
root -l -q -b  ../doPixels.C\(452\) 
mv run452.ps matrix0/ps
mv run452.out matrix0/pixels
cd ..
