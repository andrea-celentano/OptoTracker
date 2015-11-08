#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
cd run1
root -l -q -b  ../doPixels.C\(486\) 
mv run486.ps matrix0/ps
mv run486.out matrix0/pixels
cd ..
