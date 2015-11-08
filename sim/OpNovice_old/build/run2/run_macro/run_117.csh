#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
cd run2
root -l -q -b  ../doPixels.C\(117\) 
mv run117.ps matrix0/ps
mv run117.out matrix0/pixels
cd ..
