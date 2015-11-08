#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
cd run2
root -l -q -b  ../doPixels.C\(184\) 
mv run184.ps matrix0/ps
mv run184.out matrix0/pixels
cd ..
