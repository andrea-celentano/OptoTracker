#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
cd run0
root -l -q -b  ../doPixels.C\(707\) 
mv run707.ps matrix0/ps
mv run707.out matrix0/pixels
cd ..
