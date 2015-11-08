#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/
/project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/OpNoviceExe -m /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/run4/run_macro/macro150.run
mv run_150_0.root run4/root 
cd run4
root -l -q -b  ../doPixels.C\(150\) 
mv run150.ps matrix0/ps
mv run150.out matrix0/pixels
cd ..
