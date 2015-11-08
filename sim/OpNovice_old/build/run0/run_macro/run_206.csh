#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
cd run0
root -l -q -b  ../doPixels.C\(206\) 
mv run206.ps matrix0/ps
mv run206.out matrix0/pixels
cd ..
