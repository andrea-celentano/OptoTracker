#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
cd run2
root -l -q -b  ../doPixels.C\(320\) 
mv run320.ps matrix0/ps
mv run320.out matrix0/pixels
cd ..
