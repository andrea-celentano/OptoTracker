#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
cd run0
root -l -q -b  ../doPixels.C\(821\) 
mv run821.ps matrix0/ps
mv run821.out matrix0/pixels
cd ..
