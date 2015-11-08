#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
cd run0
root -l -q -b  ../doPixels.C\(929\) 
mv run929.ps matrix0/ps
mv run929.out matrix0/pixels
cd ..
