#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
cd run2
root -l -q -b  ../doPixels.C\(586\) 
mv run586.ps matrix0/ps
mv run586.out matrix0/pixels
cd ..
