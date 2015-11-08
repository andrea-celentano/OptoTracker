#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
cd run2
root -l -q -b  ../doPixels.C\(698\) 
mv run698.ps matrix0/ps
mv run698.out matrix0/pixels
cd ..
