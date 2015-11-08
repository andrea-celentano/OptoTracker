#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
cd run2
root -l -q -b  ../doPixels.C\(133\) 
mv run133.ps matrix0/ps
mv run133.out matrix0/pixels
cd ..
