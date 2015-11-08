#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
cd run0
root -l -q -b  ../doPixels.C\(424\) 
mv run424.ps matrix0/ps
mv run424.out matrix0/pixels
cd ..
