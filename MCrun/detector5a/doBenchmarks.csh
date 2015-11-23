#!/bin/tcsh -f

set MC = $OPTO/bin/OpNoviceExe
set RECON = $OPTO/bin/ReconstructionNew
set DET = PrototypeGeometry.dat
set STEERING = reconCharge.xml

set BENCHS = (alphaCenter alphaLateral alphaLateral2 muonCenter muonLateral)

foreach bench ($BENCHS)
echo $bench
#$MC -det $DET -m ${bench}.mac

foreach file (${bench}_*.root)
echo $file
set nchar = ‘echo $file | awk ’{print length($0)}’‘
echo $nchar
@ length = $nchar -5 
set name = ‘echo $file | awk ’{print substr($0,0,${length})}’‘
echo $name
$RECON -s $STEERING $file -DCHARGE_TXT=\"${file}Out.txt\" -DCHARGE_ROOT=\"${file}Out.root\"
end
