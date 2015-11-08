#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
cd run1
root -l -q -b  ../doPixels.C\(439\) 
mv run439.ps matrix0/ps
mv run439.out matrix0/pixels
cd ..
