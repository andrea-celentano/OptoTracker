#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/MCrun/detector5d
cd /project/Gruppo3/fiber5/celentano/OptoTracker/MCrun/detector5d/matrix1
/project/Gruppo3/fiber5/celentano/OptoTracker/bin/OpNoviceExe -m /project/Gruppo3/fiber5/celentano/OptoTracker/MCrun/detector5d/matrix1/run_macro/macro11.run -det /project/Gruppo3/fiber5/celentano/OptoTracker/MCrun/detector5d/PrototypeGeometry.dat
mv run_11_0.root root/ 
cd /project/Gruppo3/fiber5/celentano/OptoTracker/MCrun/detector5d/matrix1
cd /project/Gruppo3/fiber5/celentano/OptoTracker/MCrun/detector5d/matrix1
/project/Gruppo3/fiber5/celentano/OptoTracker/bin/ReconstructionNew -s /project/Gruppo3/fiber5/celentano/OptoTracker/MCrun/detector5d/matrixMCcalculation.xml -DvoxelID=11 root/run_11_0.root
mv voxel_11.dat /project/Gruppo3/fiber5/celentano/OptoTracker/MCrun/detector5d/matrix1/pixels
cd /project/Gruppo3/fiber5/celentano/OptoTracker/MCrun/detector5d/matrix1
