#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/
/project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/OpNoviceExe -m /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/run7/run_macro/macro107.run
mv run_107_0.root run7/root 
cd run7
root -l -q -b  ../doPixels.C\(107\) 
mv run107.ps matrix0/ps
mv run107.out matrix0/pixels
cd ..
