#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
cd run1
root -l -q -b  ../doPixels.C\(791\) 
mv run791.ps matrix0/ps
mv run791.out matrix0/pixels
cd ..
