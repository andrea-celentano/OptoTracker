#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
cd run0
root -l -q -b  ../doPixels.C\(594\) 
mv run594.ps matrix0/ps
mv run594.out matrix0/pixels
cd ..
