#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
cd run1
root -l -q -b  ../doPixels.C\(770\) 
mv run770.ps matrix0/ps
mv run770.out matrix0/pixels
cd ..
