#!/bin/tcsh -f

set EXE=$OPTO/software/bin/OpNoviceExe
set DET=PrototypeGeometry.new.dat

$EXE -m center.mac -det $DET &   
$EXE -m xp15yp15.mac -det $DET & 
$EXE -m xm15ym15.mac -det $DET & 
$EXE -m xm10y0.mac -det $DET & 
$EXE -m x0ym10.mac -det $DET & 
$EXE -m xp10y0.mac -det $DET & 
$EXE -m x0yp10.mac -det $DET & 
wait
# mv xm15ym15..root xm15ym15_$1.root
# mv xp15yp15_0.root xp15yp15_$1.root
# mv center_0.root center_$1.root
# mv xm10y0_0.root xm10y0_$1.root
# mv x0ym10_0.root x0ym10_$1.root
# mv xp10y0_0.root xp10y0_$1.root
# mv x0yp10_0.root x0yp10_$1.root
