#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/
/project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/OpNoviceExe -m /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/run4/run_macro/macro369.run
mv run_369_0.root run4/root 
cd run4
root -l -q -b  ../doPixels.C\(369\) 
mv run369.ps matrix0/ps
mv run369.out matrix0/pixels
cd ..
