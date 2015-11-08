#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
cd run1
root -l -q -b  ../doPixels.C\(532\) 
mv run532.ps matrix0/ps
mv run532.out matrix0/pixels
cd ..
