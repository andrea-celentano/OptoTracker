#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
cd run2
root -l -q -b  ../doPixels.C\(251\) 
mv run251.ps matrix0/ps
mv run251.out matrix0/pixels
cd ..
