#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
cd run1
root -l -q -b  ../doPixels.C\(163\) 
mv run163.ps matrix0/ps
mv run163.out matrix0/pixels
cd ..
