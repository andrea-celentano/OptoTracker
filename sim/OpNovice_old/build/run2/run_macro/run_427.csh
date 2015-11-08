#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
cd run2
root -l -q -b  ../doPixels.C\(427\) 
mv run427.ps matrix0/ps
mv run427.out matrix0/pixels
cd ..
