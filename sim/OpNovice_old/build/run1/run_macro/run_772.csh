#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
cd run1
root -l -q -b  ../doPixels.C\(772\) 
mv run772.ps matrix0/ps
mv run772.out matrix0/pixels
cd ..
