#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
cd run1
root -l -q -b  ../doPixels.C\(881\) 
mv run881.ps matrix0/ps
mv run881.out matrix0/pixels
cd ..
