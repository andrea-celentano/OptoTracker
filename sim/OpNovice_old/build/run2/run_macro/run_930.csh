#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
cd run2
root -l -q -b  ../doPixels.C\(930\) 
mv run930.ps matrix0/ps
mv run930.out matrix0/pixels
cd ..
