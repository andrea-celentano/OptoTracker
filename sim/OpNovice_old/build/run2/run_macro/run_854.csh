#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
cd run2
root -l -q -b  ../doPixels.C\(854\) 
mv run854.ps matrix0/ps
mv run854.out matrix0/pixels
cd ..
