#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
cd run1
root -l -q -b  ../doPixels.C\(296\) 
mv run296.ps matrix0/ps
mv run296.out matrix0/pixels
cd ..
