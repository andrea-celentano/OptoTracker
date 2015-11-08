#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
cd run0
root -l -q -b  ../doPixels.C\(678\) 
mv run678.ps matrix0/ps
mv run678.out matrix0/pixels
cd ..
