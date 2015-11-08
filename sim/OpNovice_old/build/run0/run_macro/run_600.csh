#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
cd run0
root -l -q -b  ../doPixels.C\(600\) 
mv run600.ps matrix0/ps
mv run600.out matrix0/pixels
cd ..
