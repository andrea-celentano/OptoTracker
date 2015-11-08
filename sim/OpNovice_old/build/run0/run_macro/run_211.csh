#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
cd run0
root -l -q -b  ../doPixels.C\(211\) 
mv run211.ps matrix0/ps
mv run211.out matrix0/pixels
cd ..
