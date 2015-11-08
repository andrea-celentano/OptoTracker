#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
cd run2
root -l -q -b  ../doPixels.C\(892\) 
mv run892.ps matrix0/ps
mv run892.out matrix0/pixels
cd ..
