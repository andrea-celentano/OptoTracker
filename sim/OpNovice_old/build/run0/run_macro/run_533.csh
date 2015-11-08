#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
cd run0
root -l -q -b  ../doPixels.C\(533\) 
mv run533.ps matrix0/ps
mv run533.out matrix0/pixels
cd ..
