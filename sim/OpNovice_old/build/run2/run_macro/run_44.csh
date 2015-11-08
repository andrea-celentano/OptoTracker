#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
cd run2
root -l -q -b  ../doPixels.C\(44\) 
mv run44.ps matrix0/ps
mv run44.out matrix0/pixels
cd ..
