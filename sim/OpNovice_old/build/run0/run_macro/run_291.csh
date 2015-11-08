#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
cd run0
root -l -q -b  ../doPixels.C\(291\) 
mv run291.ps matrix0/ps
mv run291.out matrix0/pixels
cd ..
