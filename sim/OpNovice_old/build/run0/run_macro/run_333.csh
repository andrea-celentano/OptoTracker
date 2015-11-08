#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
cd run0
root -l -q -b  ../doPixels.C\(333\) 
mv run333.ps matrix0/ps
mv run333.out matrix0/pixels
cd ..
