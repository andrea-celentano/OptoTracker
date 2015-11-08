#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
cd run2
root -l -q -b  ../doPixels.C\(138\) 
mv run138.ps matrix0/ps
mv run138.out matrix0/pixels
cd ..
