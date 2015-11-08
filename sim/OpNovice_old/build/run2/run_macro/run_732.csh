#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
cd run2
root -l -q -b  ../doPixels.C\(732\) 
mv run732.ps matrix0/ps
mv run732.out matrix0/pixels
cd ..
