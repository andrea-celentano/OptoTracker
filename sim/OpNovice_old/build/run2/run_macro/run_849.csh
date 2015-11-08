#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
cd run2
root -l -q -b  ../doPixels.C\(849\) 
mv run849.ps matrix0/ps
mv run849.out matrix0/pixels
cd ..
