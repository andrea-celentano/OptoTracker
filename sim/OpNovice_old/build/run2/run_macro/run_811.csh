#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
cd run2
root -l -q -b  ../doPixels.C\(811\) 
mv run811.ps matrix0/ps
mv run811.out matrix0/pixels
cd ..
