#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
cd run0
root -l -q -b  ../doPixels.C\(462\) 
mv run462.ps matrix0/ps
mv run462.out matrix0/pixels
cd ..
