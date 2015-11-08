#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
cd run0
root -l -q -b  ../doPixels.C\(654\) 
mv run654.ps matrix0/ps
mv run654.out matrix0/pixels
cd ..
