#!/bin/tcsh -f
cd /project/Gruppo3/fiber5/celentano/OptoTracker/MCrun/detector3
cd /project/Gruppo3/fiber5/celentano/OptoTracker/MCrun/detector3/run0/matrix0
/project/Gruppo3/fiber5/celentano/OptoTracker/bin/OpNoviceExe -m /project/Gruppo3/fiber5/celentano/OptoTracker/MCrun/detector3/run0/matrix0/run_macro/macro108.run -det /project/Gruppo3/fiber5/celentano/OptoTracker/MCrun/detector3/PrototypeGeometry.dat
mv run_108_0.root root/ 
cd /project/Gruppo3/fiber5/celentano/OptoTracker/MCrun/detector3/run0/matrix0
cd /project/Gruppo3/fiber5/celentano/OptoTracker/MCrun/detector3/run0/matrix0
/project/Gruppo3/fiber5/celentano/OptoTracker/bin/ReconstructionNew -s /project/Gruppo3/fiber5/celentano/OptoTracker/MCrun/detector3/matrixMCcalculation.xml -DvoxelID=108 root/run_108_0.root
mv voxel_108.dat /project/Gruppo3/fiber5/celentano/OptoTracker/MCrun/detector3/run0/matrix0/pixels
cd /project/Gruppo3/fiber5/celentano/OptoTracker/MCrun/detector3/run0/matrix0