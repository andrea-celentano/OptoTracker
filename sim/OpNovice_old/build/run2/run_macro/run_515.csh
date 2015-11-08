#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
cd run2
root -l -q -b  ../doPixels.C\(515\) 
mv run515.ps matrix0/ps
mv run515.out matrix0/pixels
cd ..
