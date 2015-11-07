#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/MCrun/detector5a
cd /project/Gruppo3/fiber5/celentano/OptoTracker/MCrun/detector5a/matrix1
/project/Gruppo3/fiber5/celentano/OptoTracker/bin/OpNoviceExe -m /project/Gruppo3/fiber5/celentano/OptoTracker/MCrun/detector5a/matrix1/run_macro/macro93.run -det /project/Gruppo3/fiber5/celentano/OptoTracker/MCrun/detector5a/PrototypeGeometry.dat
mv run_93_0.root root/ 
cd /project/Gruppo3/fiber5/celentano/OptoTracker/MCrun/detector5a/matrix1
cd /project/Gruppo3/fiber5/celentano/OptoTracker/MCrun/detector5a/matrix1
/project/Gruppo3/fiber5/celentano/OptoTracker/bin/ReconstructionNew -s /project/Gruppo3/fiber5/celentano/OptoTracker/MCrun/detector5a/matrixMCcalculation.xml -DvoxelID=93 root/run_93_0.root
mv voxel_93.dat /project/Gruppo3/fiber5/celentano/OptoTracker/MCrun/detector5a/matrix1/pixels
cd /project/Gruppo3/fiber5/celentano/OptoTracker/MCrun/detector5a/matrix1
