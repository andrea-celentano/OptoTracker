#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/MCrun/detector5e
cd /project/Gruppo3/fiber5/celentano/OptoTracker/MCrun/detector5e/matrix2
/project/Gruppo3/fiber5/celentano/OptoTracker/bin/OpNoviceExe -m /project/Gruppo3/fiber5/celentano/OptoTracker/MCrun/detector5e/matrix2/run_macro/macro43.run -det /project/Gruppo3/fiber5/celentano/OptoTracker/MCrun/detector5e/PrototypeGeometry.dat
mv run_43_0.root root/ 
cd /project/Gruppo3/fiber5/celentano/OptoTracker/MCrun/detector5e/matrix2
cd /project/Gruppo3/fiber5/celentano/OptoTracker/MCrun/detector5e/matrix2
/project/Gruppo3/fiber5/celentano/OptoTracker/bin/ReconstructionNew -s /project/Gruppo3/fiber5/celentano/OptoTracker/MCrun/detector5e/matrixMCcalculation.xml -DvoxelID=43 root/run_43_0.root
mv voxel_43.dat /project/Gruppo3/fiber5/celentano/OptoTracker/MCrun/detector5e/matrix2/pixels
cd /project/Gruppo3/fiber5/celentano/OptoTracker/MCrun/detector5e/matrix2
