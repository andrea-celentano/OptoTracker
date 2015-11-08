#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
cd run2
root -l -q -b  ../doPixels.C\(754\) 
mv run754.ps matrix0/ps
mv run754.out matrix0/pixels
cd ..
