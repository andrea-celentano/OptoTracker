#!/bin/tcsh -f

set EXE=$OPTO/software/bin/MarocAnalysis
set DET=PrototypeGeometry.new.dat

#$EXE -s data/testAlpha_3_00001.root -b data/testAlpha_3_00005.root -d $DET -ss PrototypeSetup.dat -batch -o center_$1   -r ../../MCrun/detector2a/center.$1.MCout.root -XY 0 0&
#$EXE -s data/testAlpha_3_00004.root -b data/testAlpha_3_00008.root -d $DET -ss PrototypeSetup.dat -batch -o xp15yp15_$1 -r ../../MCrun/detector2a/xp15yp15.$1.MCout.root -XY 1.5 1.5&
#$EXE -s data/testAlpha_3_00010.root -b data/testAlpha_3_00011.root -d $DET -ss PrototypeSetup.dat -batch -o xm15ym15_$1 -r ../../MCrun/detector2a/xm15ym15.$1.MCout.root -XY -1.5 -1.5&
$EXE -s data/testAlpha_3_00017.root -b data/testAlpha_3_00018.root -d $DET -ss PrototypeSetup.dat -batch -o xm10y0_$1 -r ../../MCrun/detector2a/xm10y0.$1.MCout.root -XY -1 0&
$EXE -s data/testAlpha_3_00021.root -b data/testAlpha_3_00022.root -d $DET -ss PrototypeSetup.dat -batch -o x0ym10_$1 -r ../../MCrun/detector2a/x0ym10.$1.MCout.root -XY 0 -1&
$EXE -s data/testAlpha_3_00019.root -b data/testAlpha_3_00020.root -d $DET -ss PrototypeSetup.dat -batch -o xp10y0_$1 -r ../../MCrun/detector2a/xp10y0.$1.MCout.root -XY 1 0&
$EXE -s data/testAlpha_3_00023.root -b data/testAlpha_3_00024.root -d $DET -ss PrototypeSetup.dat -batch -o x0yp10_$1 -r ../../MCrun/detector2a/x0yp10.$1.MCout.root -XY 0 1&

wait
