#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
cd run2
root -l -q -b  ../doPixels.C\(187\) 
mv run187.ps matrix0/ps
mv run187.out matrix0/pixels
cd ..
