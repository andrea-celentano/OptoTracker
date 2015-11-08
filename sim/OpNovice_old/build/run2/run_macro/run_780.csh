#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
cd run2
root -l -q -b  ../doPixels.C\(780\) 
mv run780.ps matrix0/ps
mv run780.out matrix0/pixels
cd ..
