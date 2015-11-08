#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
cd run0
root -l -q -b  ../doPixels.C\(116\) 
mv run116.ps matrix0/ps
mv run116.out matrix0/pixels
cd ..
