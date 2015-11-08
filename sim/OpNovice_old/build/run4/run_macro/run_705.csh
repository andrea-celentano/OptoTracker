#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/
/project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/OpNoviceExe -m /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/run4/run_macro/macro705.run
mv run_705_0.root run4/root 
cd run4
root -l -q -b  ../doPixels.C\(705\) 
mv run705.ps matrix0/ps
mv run705.out matrix0/pixels
cd ..
