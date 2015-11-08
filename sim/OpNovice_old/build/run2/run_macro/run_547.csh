#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
cd run2
root -l -q -b  ../doPixels.C\(547\) 
mv run547.ps matrix0/ps
mv run547.out matrix0/pixels
cd ..
