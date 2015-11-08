#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/
/project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/OpNoviceExe -m /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/run4/run_macro/macro547.run
mv run_547_0.root run4/root 
cd run4
root -l -q -b  ../doPixels.C\(547\) 
mv run547.ps matrix0/ps
mv run547.out matrix0/pixels
cd ..
