#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
/project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/OpNoviceExe -m /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/run3/run_macro/macro369.run
mv run_369_0.root run3/root 
cd run3
root -l -q -b  ../doPixels.C\(369\) 
mv run369.ps matrix0/ps
mv run369.out matrix0/pixels
cd ..
