#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
cd run1
root -l -q -b  ../doPixels.C\(269\) 
mv run269.ps matrix0/ps
mv run269.out matrix0/pixels
cd ..
