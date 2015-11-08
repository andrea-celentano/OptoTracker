#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
cd run0
root -l -q -b  ../doPixels.C\(388\) 
mv run388.ps matrix0/ps
mv run388.out matrix0/pixels
cd ..
