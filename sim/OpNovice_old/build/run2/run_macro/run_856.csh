#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
cd run2
root -l -q -b  ../doPixels.C\(856\) 
mv run856.ps matrix0/ps
mv run856.out matrix0/pixels
cd ..
