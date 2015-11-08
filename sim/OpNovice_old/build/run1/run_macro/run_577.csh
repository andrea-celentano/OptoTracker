#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
cd run1
root -l -q -b  ../doPixels.C\(577\) 
mv run577.ps matrix0/ps
mv run577.out matrix0/pixels
cd ..
