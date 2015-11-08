#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
cd run2
root -l -q -b  ../doPixels.C\(934\) 
mv run934.ps matrix0/ps
mv run934.out matrix0/pixels
cd ..
