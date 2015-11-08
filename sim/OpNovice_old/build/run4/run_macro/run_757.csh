#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/
/project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/OpNoviceExe -m /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/run4/run_macro/macro757.run
mv run_757_0.root run4/root 
cd run4
root -l -q -b  ../doPixels.C\(757\) 
mv run757.ps matrix0/ps
mv run757.out matrix0/pixels
cd ..
