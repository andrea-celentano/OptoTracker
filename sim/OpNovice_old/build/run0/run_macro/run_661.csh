#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
cd run0
root -l -q -b  ../doPixels.C\(661\) 
mv run661.ps matrix0/ps
mv run661.out matrix0/pixels
cd ..
