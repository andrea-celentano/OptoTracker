#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
cd run0
root -l -q -b  ../doPixels.C\(711\) 
mv run711.ps matrix0/ps
mv run711.out matrix0/pixels
cd ..
