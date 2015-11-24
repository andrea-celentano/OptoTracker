#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/MCrun/detector5e
cd /project/Gruppo3/fiber5/celentano/OptoTracker/MCrun/detector5e/matrix1
/project/Gruppo3/fiber5/celentano/OptoTracker/bin/OpNoviceExe -m /project/Gruppo3/fiber5/celentano/OptoTracker/MCrun/detector5e/matrix1/run_macro/macro56.run -det /project/Gruppo3/fiber5/celentano/OptoTracker/MCrun/detector5e/PrototypeGeometry.dat
mv run_56_0.root root/ 
cd /project/Gruppo3/fiber5/celentano/OptoTracker/MCrun/detector5e/matrix1
cd /project/Gruppo3/fiber5/celentano/OptoTracker/MCrun/detector5e/matrix1
/project/Gruppo3/fiber5/celentano/OptoTracker/bin/ReconstructionNew -s /project/Gruppo3/fiber5/celentano/OptoTracker/MCrun/detector5e/matrixMCcalculation.xml -DvoxelID=56 root/run_56_0.root
mv voxel_56.dat /project/Gruppo3/fiber5/celentano/OptoTracker/MCrun/detector5e/matrix1/pixels
cd /project/Gruppo3/fiber5/celentano/OptoTracker/MCrun/detector5e/matrix1
