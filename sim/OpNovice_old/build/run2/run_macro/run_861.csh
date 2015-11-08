#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
cd run2
root -l -q -b  ../doPixels.C\(861\) 
mv run861.ps matrix0/ps
mv run861.out matrix0/pixels
cd ..
