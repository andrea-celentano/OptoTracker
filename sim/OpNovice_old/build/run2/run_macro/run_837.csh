#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
cd run2
root -l -q -b  ../doPixels.C\(837\) 
mv run837.ps matrix0/ps
mv run837.out matrix0/pixels
cd ..
