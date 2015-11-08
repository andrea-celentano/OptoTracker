#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/
/project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/OpNoviceExe -m /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/build/run6/run_macro/macro171.run
mv run_171_0.root run6/root 
cd run6
root -l -q -b  ../doPixels.C\(171\) 
mv run171.ps matrix0/ps
mv run171.out matrix0/pixels
cd ..
