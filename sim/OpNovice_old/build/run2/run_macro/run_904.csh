#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
cd run2
root -l -q -b  ../doPixels.C\(904\) 
mv run904.ps matrix0/ps
mv run904.out matrix0/pixels
cd ..
