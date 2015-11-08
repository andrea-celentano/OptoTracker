#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
cd run0
root -l -q -b  ../doPixels.C\(367\) 
mv run367.ps matrix0/ps
mv run367.out matrix0/pixels
cd ..
