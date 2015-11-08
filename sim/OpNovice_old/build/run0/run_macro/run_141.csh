#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
cd run0
root -l -q -b  ../doPixels.C\(141\) 
mv run141.ps matrix0/ps
mv run141.out matrix0/pixels
cd ..
