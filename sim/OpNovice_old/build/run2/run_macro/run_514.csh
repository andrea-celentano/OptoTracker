#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
cd run2
root -l -q -b  ../doPixels.C\(514\) 
mv run514.ps matrix0/ps
mv run514.out matrix0/pixels
cd ..
