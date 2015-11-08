#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
cd run0
root -l -q -b  ../doPixels.C\(190\) 
mv run190.ps matrix0/ps
mv run190.out matrix0/pixels
cd ..
