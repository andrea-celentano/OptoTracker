#!/bin/tcsh -f
cd /work/OptoTracker/MCrun/detector3/
cd run0
/work/OptoTracker/bin/OpNoviceExe -m /work/OptoTracker/MCrun/detector3/run0/run_macro/macro119.run -det /work/OptoTracker/MCrun/detector3//PrototypeGeometry.dat
mv run_119_0.root root/ 
cd /work/OptoTracker/MCrun/detector3/
cd run0
/work/OptoTracker/bin/ReconstructionNew -s /work/OptoTracker/MCrun/detector3/matrixAnalysis.xml -DvoxelID=119 root/run_119_0.root
mv voxel_119.dat matrix/pixels
cd /work/OptoTracker/MCrun/detector3/
