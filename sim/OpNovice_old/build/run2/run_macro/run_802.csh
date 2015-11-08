#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
cd run2
root -l -q -b  ../doPixels.C\(802\) 
mv run802.ps matrix0/ps
mv run802.out matrix0/pixels
cd ..
