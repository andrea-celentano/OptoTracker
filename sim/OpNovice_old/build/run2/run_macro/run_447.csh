#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
cd run2
root -l -q -b  ../doPixels.C\(447\) 
mv run447.ps matrix0/ps
mv run447.out matrix0/pixels
cd ..