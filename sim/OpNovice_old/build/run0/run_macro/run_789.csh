#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
cd run0
root -l -q -b  ../doPixels.C\(789\) 
mv run789.ps matrix0/ps
mv run789.out matrix0/pixels
cd ..
