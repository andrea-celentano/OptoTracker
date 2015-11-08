#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
cd run2
root -l -q -b  ../doPixels.C\(571\) 
mv run571.ps matrix0/ps
mv run571.out matrix0/pixels
cd ..
