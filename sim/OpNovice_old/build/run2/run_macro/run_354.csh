#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
cd run2
root -l -q -b  ../doPixels.C\(354\) 
mv run354.ps matrix0/ps
mv run354.out matrix0/pixels
cd ..
