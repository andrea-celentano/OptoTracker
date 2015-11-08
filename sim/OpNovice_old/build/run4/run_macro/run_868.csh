#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/
/project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/OpNoviceExe -m /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/run4/run_macro/macro868.run
mv run_868_0.root run4/root 
cd run4
root -l -q -b  ../doPixels.C\(868\) 
mv run868.ps matrix0/ps
mv run868.out matrix0/pixels
cd ..
