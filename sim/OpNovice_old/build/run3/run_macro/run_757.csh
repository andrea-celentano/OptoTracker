#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
/project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/OpNoviceExe -m /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/run3/run_macro/macro757.run
mv run_757_0.root run3/root 
cd run3
root -l -q -b  ../doPixels.C\(757\) 
mv run757.ps matrix0/ps
mv run757.out matrix0/pixels
cd ..
