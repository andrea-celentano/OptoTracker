#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
cd run0
root -l -q -b  ../doPixels.C\(786\) 
mv run786.ps matrix0/ps
mv run786.out matrix0/pixels
cd ..
