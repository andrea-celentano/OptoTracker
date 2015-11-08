#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
cd run0
root -l -q -b  ../doPixels.C\(292\) 
mv run292.ps matrix0/ps
mv run292.out matrix0/pixels
cd ..
