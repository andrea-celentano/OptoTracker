#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
cd run2
root -l -q -b  ../doPixels.C\(8\) 
mv run8.ps matrix0/ps
mv run8.out matrix0/pixels
cd ..
