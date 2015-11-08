#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
cd run0
root -l -q -b  ../doPixels.C\(312\) 
mv run312.ps matrix0/ps
mv run312.out matrix0/pixels
cd ..
