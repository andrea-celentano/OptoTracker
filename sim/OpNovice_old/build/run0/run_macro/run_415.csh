#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
cd run0
root -l -q -b  ../doPixels.C\(415\) 
mv run415.ps matrix0/ps
mv run415.out matrix0/pixels
cd ..
