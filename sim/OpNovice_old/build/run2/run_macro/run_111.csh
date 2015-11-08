#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
cd run2
root -l -q -b  ../doPixels.C\(111\) 
mv run111.ps matrix0/ps
mv run111.out matrix0/pixels
cd ..
