#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
cd run2
root -l -q -b  ../doPixels.C\(224\) 
mv run224.ps matrix0/ps
mv run224.out matrix0/pixels
cd ..
