#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
cd run0
root -l -q -b  ../doPixels.C\(288\) 
mv run288.ps matrix0/ps
mv run288.out matrix0/pixels
cd ..
