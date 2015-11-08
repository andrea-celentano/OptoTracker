#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
cd run0
root -l -q -b  ../doPixels.C\(349\) 
mv run349.ps matrix0/ps
mv run349.out matrix0/pixels
cd ..
