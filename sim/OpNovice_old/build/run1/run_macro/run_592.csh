#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
cd run1
root -l -q -b  ../doPixels.C\(592\) 
mv run592.ps matrix0/ps
mv run592.out matrix0/pixels
cd ..