#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
cd run0
root -l -q -b  ../doPixels.C\(161\) 
mv run161.ps matrix0/ps
mv run161.out matrix0/pixels
cd ..
