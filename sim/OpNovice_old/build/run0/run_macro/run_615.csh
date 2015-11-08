#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
cd run0
root -l -q -b  ../doPixels.C\(615\) 
mv run615.ps matrix0/ps
mv run615.out matrix0/pixels
cd ..
