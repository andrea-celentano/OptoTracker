#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
cd run0
root -l -q -b  ../doPixels.C\(102\) 
mv run102.ps matrix0/ps
mv run102.out matrix0/pixels
cd ..
