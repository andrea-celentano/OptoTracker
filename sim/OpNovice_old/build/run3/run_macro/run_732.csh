#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
/project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/OpNoviceExe -m /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/run3/run_macro/macro732.run
mv run_732_0.root run3/root 
cd run3
root -l -q -b  ../doPixels.C\(732\) 
mv run732.ps matrix0/ps
mv run732.out matrix0/pixels
cd ..
