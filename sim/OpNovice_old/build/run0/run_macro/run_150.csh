#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
cd run0
root -l -q -b  ../doPixels.C\(150\) 
mv run150.ps matrix0/ps
mv run150.out matrix0/pixels
cd ..
