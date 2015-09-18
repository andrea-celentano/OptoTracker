#!/bin/tcsh -f
cd /work/OptoTracker/MCrun/detector3/
cd run0
/work/OptoTracker/bin/OpNoviceExe -m /work/OptoTracker/MCrun/detector3/run0/run_macro/macro101.run -det /work/OptoTracker/MCrun/detector3//PrototypeGeometry.dat
mv run_101_0.root root/ 
cd /work/OptoTracker/MCrun/detector3/
cd run0
/work/OptoTracker/bin/ReconstructionNew -s /work/OptoTracker/MCrun/detector3/matrixAnalysis.xml -DvoxelID=101 root/run_101_0.root
mv voxel_101.dat matrix/pixels
cd /work/OptoTracker/MCrun/detector3/
