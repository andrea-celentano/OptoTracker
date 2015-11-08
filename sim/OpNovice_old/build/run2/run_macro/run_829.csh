#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
cd run2
root -l -q -b  ../doPixels.C\(829\) 
mv run829.ps matrix0/ps
mv run829.out matrix0/pixels
cd ..
