#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
cd run2
root -l -q -b  ../doPixels.C\(144\) 
mv run144.ps matrix0/ps
mv run144.out matrix0/pixels
cd ..
