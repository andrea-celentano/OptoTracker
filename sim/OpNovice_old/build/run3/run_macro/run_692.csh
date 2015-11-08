#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/
/project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/OpNoviceExe -m /project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice/build/run3/run_macro/macro692.run
mv run_692_0.root run3/root 
cd run3
root -l -q -b  ../doPixels.C\(692\) 
mv run692.ps matrix0/ps
mv run692.out matrix0/pixels
cd ..
