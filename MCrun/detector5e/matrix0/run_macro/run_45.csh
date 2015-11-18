#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/MCrun/detector5e
cd /project/Gruppo3/fiber5/celentano/OptoTracker/MCrun/detector5e/matrix0
/project/Gruppo3/fiber5/celentano/OptoTracker/bin/OpNoviceExe -m /project/Gruppo3/fiber5/celentano/OptoTracker/MCrun/detector5e/matrix0/run_macro/macro45.run -det /project/Gruppo3/fiber5/celentano/OptoTracker/MCrun/detector5e/PrototypeGeometry.dat
mv run_45_0.root root/ 
cd /project/Gruppo3/fiber5/celentano/OptoTracker/MCrun/detector5e/matrix0
cd /project/Gruppo3/fiber5/celentano/OptoTracker/MCrun/detector5e/matrix0
/project/Gruppo3/fiber5/celentano/OptoTracker/bin/ReconstructionNew -s /project/Gruppo3/fiber5/celentano/OptoTracker/MCrun/detector5e/matrixMCcalculation.xml -DvoxelID=45 root/run_45_0.root
mv voxel_45.dat /project/Gruppo3/fiber5/celentano/OptoTracker/MCrun/detector5e/matrix0/pixels
cd /project/Gruppo3/fiber5/celentano/OptoTracker/MCrun/detector5e/matrix0
