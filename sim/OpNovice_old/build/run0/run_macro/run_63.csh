#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
cd run0
root -l -q -b  ../doPixels.C\(63\) 
mv run63.ps matrix0/ps
mv run63.out matrix0/pixels
cd ..
