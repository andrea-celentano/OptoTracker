#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/MCrun/detector5c
cd /project/Gruppo3/fiber5/celentano/OptoTracker/MCrun/detector5c/matrix1
/project/Gruppo3/fiber5/celentano/OptoTracker/bin/OpNoviceExe -m /project/Gruppo3/fiber5/celentano/OptoTracker/MCrun/detector5c/matrix1/run_macro/macro82.run -det /project/Gruppo3/fiber5/celentano/OptoTracker/MCrun/detector5c/PrototypeGeometry.dat
mv run_82_0.root root/ 
cd /project/Gruppo3/fiber5/celentano/OptoTracker/MCrun/detector5c/matrix1
cd /project/Gruppo3/fiber5/celentano/OptoTracker/MCrun/detector5c/matrix1
/project/Gruppo3/fiber5/celentano/OptoTracker/bin/ReconstructionNew -s /project/Gruppo3/fiber5/celentano/OptoTracker/MCrun/detector5c/matrixMCcalculation.xml -DvoxelID=82 root/run_82_0.root
mv voxel_82.dat /project/Gruppo3/fiber5/celentano/OptoTracker/MCrun/detector5c/matrix1/pixels
cd /project/Gruppo3/fiber5/celentano/OptoTracker/MCrun/detector5c/matrix1
