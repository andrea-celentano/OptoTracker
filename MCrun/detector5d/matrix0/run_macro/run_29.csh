#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/MCrun/detector5d
cd /project/Gruppo3/fiber5/celentano/OptoTracker/MCrun/detector5d/matrix0
/project/Gruppo3/fiber5/celentano/OptoTracker/bin/OpNoviceExe -m /project/Gruppo3/fiber5/celentano/OptoTracker/MCrun/detector5d/matrix0/run_macro/macro29.run -det /project/Gruppo3/fiber5/celentano/OptoTracker/MCrun/detector5d/PrototypeGeometry.dat
mv run_29_0.root root/ 
cd /project/Gruppo3/fiber5/celentano/OptoTracker/MCrun/detector5d/matrix0
cd /project/Gruppo3/fiber5/celentano/OptoTracker/MCrun/detector5d/matrix0
/project/Gruppo3/fiber5/celentano/OptoTracker/bin/ReconstructionNew -s /project/Gruppo3/fiber5/celentano/OptoTracker/MCrun/detector5d/matrixMCcalculation.xml -DvoxelID=29 root/run_29_0.root
mv voxel_29.dat /project/Gruppo3/fiber5/celentano/OptoTracker/MCrun/detector5d/matrix0/pixels
cd /project/Gruppo3/fiber5/celentano/OptoTracker/MCrun/detector5d/matrix0
