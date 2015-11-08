#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
cd run1
root -l -q -b  ../doPixels.C\(969\) 
mv run969.ps matrix0/ps
mv run969.out matrix0/pixels
cd ..
