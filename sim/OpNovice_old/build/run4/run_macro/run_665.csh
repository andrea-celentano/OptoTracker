#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/
/project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/OpNoviceExe -m /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/run4/run_macro/macro665.run
mv run_665_0.root run4/root 
cd run4
root -l -q -b  ../doPixels.C\(665\) 
mv run665.ps matrix0/ps
mv run665.out matrix0/pixels
cd ..
