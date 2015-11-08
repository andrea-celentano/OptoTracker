#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
cd run0
root -l -q -b  ../doPixels.C\(453\) 
mv run453.ps matrix0/ps
mv run453.out matrix0/pixels
cd ..
