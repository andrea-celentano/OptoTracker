#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/MCrun/detector5c
cd /project/Gruppo3/fiber5/celentano/OptoTracker/MCrun/detector5c/matrix0
/project/Gruppo3/fiber5/celentano/OptoTracker/bin/OpNoviceExe -m /project/Gruppo3/fiber5/celentano/OptoTracker/MCrun/detector5c/matrix0/run_macro/macro54.run -det /project/Gruppo3/fiber5/celentano/OptoTracker/MCrun/detector5c/PrototypeGeometry.dat
mv run_54_0.root root/ 
cd /project/Gruppo3/fiber5/celentano/OptoTracker/MCrun/detector5c/matrix0
cd /project/Gruppo3/fiber5/celentano/OptoTracker/MCrun/detector5c/matrix0
/project/Gruppo3/fiber5/celentano/OptoTracker/bin/ReconstructionNew -s /project/Gruppo3/fiber5/celentano/OptoTracker/MCrun/detector5c/matrixMCcalculation.xml -DvoxelID=54 root/run_54_0.root
mv voxel_54.dat /project/Gruppo3/fiber5/celentano/OptoTracker/MCrun/detector5c/matrix0/pixels
cd /project/Gruppo3/fiber5/celentano/OptoTracker/MCrun/detector5c/matrix0
