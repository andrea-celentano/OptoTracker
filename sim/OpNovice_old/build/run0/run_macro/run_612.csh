#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
cd run0
root -l -q -b  ../doPixels.C\(612\) 
mv run612.ps matrix0/ps
mv run612.out matrix0/pixels
cd ..
