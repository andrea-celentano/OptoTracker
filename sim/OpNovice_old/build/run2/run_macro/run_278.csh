#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
cd run2
root -l -q -b  ../doPixels.C\(278\) 
mv run278.ps matrix0/ps
mv run278.out matrix0/pixels
cd ..