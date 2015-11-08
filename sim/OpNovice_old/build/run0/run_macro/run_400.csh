#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
cd run0
root -l -q -b  ../doPixels.C\(400\) 
mv run400.ps matrix0/ps
mv run400.out matrix0/pixels
cd ..
