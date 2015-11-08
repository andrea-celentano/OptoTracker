#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/
/project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/OpNoviceExe -m /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/run6/run_macro/macro44.run
mv run_44_0.root run6/root 
cd run6
root -l -q -b  ../doPixels.C\(44\) 
mv run44.ps matrix0/ps
mv run44.out matrix0/pixels
cd ..
