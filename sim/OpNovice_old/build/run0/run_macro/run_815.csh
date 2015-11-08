#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
cd run0
root -l -q -b  ../doPixels.C\(815\) 
mv run815.ps matrix0/ps
mv run815.out matrix0/pixels
cd ..
