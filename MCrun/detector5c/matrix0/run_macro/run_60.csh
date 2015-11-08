#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/MCrun/detector5c
cd /project/Gruppo3/fiber5/celentano/OptoTracker/MCrun/detector5c/matrix0
/project/Gruppo3/fiber5/celentano/OptoTracker/bin/OpNoviceExe -m /project/Gruppo3/fiber5/celentano/OptoTracker/MCrun/detector5c/matrix0/run_macro/macro60.run -det /project/Gruppo3/fiber5/celentano/OptoTracker/MCrun/detector5c/PrototypeGeometry.dat
mv run_60_0.root root/ 
cd /project/Gruppo3/fiber5/celentano/OptoTracker/MCrun/detector5c/matrix0
cd /project/Gruppo3/fiber5/celentano/OptoTracker/MCrun/detector5c/matrix0
/project/Gruppo3/fiber5/celentano/OptoTracker/bin/ReconstructionNew -s /project/Gruppo3/fiber5/celentano/OptoTracker/MCrun/detector5c/matrixMCcalculation.xml -DvoxelID=60 root/run_60_0.root
mv voxel_60.dat /project/Gruppo3/fiber5/celentano/OptoTracker/MCrun/detector5c/matrix0/pixels
cd /project/Gruppo3/fiber5/celentano/OptoTracker/MCrun/detector5c/matrix0
