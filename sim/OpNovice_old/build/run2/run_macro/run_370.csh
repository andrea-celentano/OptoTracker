#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
cd run2
root -l -q -b  ../doPixels.C\(370\) 
mv run370.ps matrix0/ps
mv run370.out matrix0/pixels
cd ..
