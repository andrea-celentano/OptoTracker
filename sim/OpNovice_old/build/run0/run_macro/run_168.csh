#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
cd run0
root -l -q -b  ../doPixels.C\(168\) 
mv run168.ps matrix0/ps
mv run168.out matrix0/pixels
cd ..
