#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
cd run0
root -l -q -b  ../doPixels.C\(585\) 
mv run585.ps matrix0/ps
mv run585.out matrix0/pixels
cd ..
