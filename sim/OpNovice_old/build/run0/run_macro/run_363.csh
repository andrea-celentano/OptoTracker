#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
cd run0
root -l -q -b  ../doPixels.C\(363\) 
mv run363.ps matrix0/ps
mv run363.out matrix0/pixels
cd ..