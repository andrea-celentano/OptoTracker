#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
cd run2
root -l -q -b  ../doPixels.C\(103\) 
mv run103.ps matrix0/ps
mv run103.out matrix0/pixels
cd ..
