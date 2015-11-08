#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
cd run2
root -l -q -b  ../doPixels.C\(777\) 
mv run777.ps matrix0/ps
mv run777.out matrix0/pixels
cd ..
