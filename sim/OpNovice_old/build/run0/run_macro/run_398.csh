#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
cd run0
root -l -q -b  ../doPixels.C\(398\) 
mv run398.ps matrix0/ps
mv run398.out matrix0/pixels
cd ..
