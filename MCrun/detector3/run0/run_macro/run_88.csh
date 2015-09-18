#!/bin/tcsh -f
cd /work/OptoTracker/MCrun/detector3/
cd run0
/work/OptoTracker/bin/OpNoviceExe -m /work/OptoTracker/MCrun/detector3/run0/run_macro/macro88.run -det /work/OptoTracker/MCrun/detector3//PrototypeGeometry.dat
mv run_88_0.root root/ 
cd /work/OptoTracker/MCrun/detector3/
cd run0
/work/OptoTracker/bin/ReconstructionNew -s /work/OptoTracker/MCrun/detector3/matrixAnalysis.xml -DvoxelID=88 root/run_88_0.root
mv voxel_88.dat matrix/pixels
cd /work/OptoTracker/MCrun/detector3/
