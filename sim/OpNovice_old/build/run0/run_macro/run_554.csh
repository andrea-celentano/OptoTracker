#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
cd run0
root -l -q -b  ../doPixels.C\(554\) 
mv run554.ps matrix0/ps
mv run554.out matrix0/pixels
cd ..
