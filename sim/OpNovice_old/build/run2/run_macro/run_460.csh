#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
cd run2
root -l -q -b  ../doPixels.C\(460\) 
mv run460.ps matrix0/ps
mv run460.out matrix0/pixels
cd ..
