#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
cd run0
root -l -q -b  ../doPixels.C\(476\) 
mv run476.ps matrix0/ps
mv run476.out matrix0/pixels
cd ..
