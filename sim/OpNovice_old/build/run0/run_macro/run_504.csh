#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
cd run0
root -l -q -b  ../doPixels.C\(504\) 
mv run504.ps matrix0/ps
mv run504.out matrix0/pixels
cd ..
