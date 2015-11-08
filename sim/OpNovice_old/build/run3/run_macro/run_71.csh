#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
/project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/OpNoviceExe -m /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/run3/run_macro/macro71.run
mv run_71_0.root run3/root 
cd run3
root -l -q -b  ../doPixels.C\(71\) 
mv run71.ps matrix0/ps
mv run71.out matrix0/pixels
cd ..
