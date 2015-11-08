#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
cd run1
root -l -q -b  ../doPixels.C\(573\) 
mv run573.ps matrix0/ps
mv run573.out matrix0/pixels
cd ..
