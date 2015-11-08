#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
cd run0
root -l -q -b  ../doPixels.C\(176\) 
mv run176.ps matrix0/ps
mv run176.out matrix0/pixels
cd ..
