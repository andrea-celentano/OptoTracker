#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
cd run1
root -l -q -b  ../doPixels.C\(667\) 
mv run667.ps matrix0/ps
mv run667.out matrix0/pixels
cd ..
