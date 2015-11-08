#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
cd run2
root -l -q -b  ../doPixels.C\(106\) 
mv run106.ps matrix0/ps
mv run106.out matrix0/pixels
cd ..
