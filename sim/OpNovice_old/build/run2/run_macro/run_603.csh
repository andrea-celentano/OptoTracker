#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
cd run2
root -l -q -b  ../doPixels.C\(603\) 
mv run603.ps matrix0/ps
mv run603.out matrix0/pixels
cd ..
