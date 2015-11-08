#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
cd run1
root -l -q -b  ../doPixels.C\(279\) 
mv run279.ps matrix0/ps
mv run279.out matrix0/pixels
cd ..
