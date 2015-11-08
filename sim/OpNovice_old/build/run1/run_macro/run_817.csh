#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
cd run1
root -l -q -b  ../doPixels.C\(817\) 
mv run817.ps matrix0/ps
mv run817.out matrix0/pixels
cd ..
