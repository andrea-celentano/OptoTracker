#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/MCrun/detector3a
cd /project/Gruppo3/fiber5/celentano/OptoTracker/MCrun/detector3a/matrix1
/project/Gruppo3/fiber5/celentano/OptoTracker/bin/OpNoviceExe -m /project/Gruppo3/fiber5/celentano/OptoTracker/MCrun/detector3a/matrix1/run_macro/macro21.run -det /project/Gruppo3/fiber5/celentano/OptoTracker/MCrun/detector3a/PrototypeGeometry.dat
mv run_21_0.root root/ 
cd /project/Gruppo3/fiber5/celentano/OptoTracker/MCrun/detector3a/matrix1
cd /project/Gruppo3/fiber5/celentano/OptoTracker/MCrun/detector3a/matrix1
/project/Gruppo3/fiber5/celentano/OptoTracker/bin/ReconstructionNew -s /project/Gruppo3/fiber5/celentano/OptoTracker/MCrun/detector3a/matrixMCcalculation.xml -DvoxelID=21 root/run_21_0.root
mv voxel_21.dat /project/Gruppo3/fiber5/celentano/OptoTracker/MCrun/detector3a/matrix1/pixels
cd /project/Gruppo3/fiber5/celentano/OptoTracker/MCrun/detector3a/matrix1
