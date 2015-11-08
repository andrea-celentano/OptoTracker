#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
cd run2
root -l -q -b  ../doPixels.C\(992\) 
mv run992.ps matrix0/ps
mv run992.out matrix0/pixels
cd ..
