#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
cd run0
root -l -q -b  ../doPixels.C\(681\) 
mv run681.ps matrix0/ps
mv run681.out matrix0/pixels
cd ..
