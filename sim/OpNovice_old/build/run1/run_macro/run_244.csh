#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
cd run1
root -l -q -b  ../doPixels.C\(244\) 
mv run244.ps matrix0/ps
mv run244.out matrix0/pixels
cd ..
