#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
cd run2
root -l -q -b  ../doPixels.C\(346\) 
mv run346.ps matrix0/ps
mv run346.out matrix0/pixels
cd ..
