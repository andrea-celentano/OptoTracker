#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/MCrun/detector5b
cd /project/Gruppo3/fiber5/celentano/OptoTracker/MCrun/detector5b/matrix1
/project/Gruppo3/fiber5/celentano/OptoTracker/bin/OpNoviceExe -m /project/Gruppo3/fiber5/celentano/OptoTracker/MCrun/detector5b/matrix1/run_macro/macro1.run -det /project/Gruppo3/fiber5/celentano/OptoTracker/MCrun/detector5b/PrototypeGeometry.dat
mv run_1_0.root root/ 
cd /project/Gruppo3/fiber5/celentano/OptoTracker/MCrun/detector5b/matrix1
cd /project/Gruppo3/fiber5/celentano/OptoTracker/MCrun/detector5b/matrix1
/project/Gruppo3/fiber5/celentano/OptoTracker/bin/ReconstructionNew -s /project/Gruppo3/fiber5/celentano/OptoTracker/MCrun/detector5b/matrixMCcalculation.xml -DvoxelID=1 root/run_1_0.root
mv voxel_1.dat /project/Gruppo3/fiber5/celentano/OptoTracker/MCrun/detector5b/matrix1/pixels
cd /project/Gruppo3/fiber5/celentano/OptoTracker/MCrun/detector5b/matrix1