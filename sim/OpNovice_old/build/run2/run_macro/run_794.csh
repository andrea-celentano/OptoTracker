#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
cd run2
root -l -q -b  ../doPixels.C\(794\) 
mv run794.ps matrix0/ps
mv run794.out matrix0/pixels
cd ..
