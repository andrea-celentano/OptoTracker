#!/bin/tcsh -f

set MC = $OPTO/software/bin/OpNoviceExe
set RECON = $OPTO/software/bin/ReconstructionNew
set DET = PrototypeGeometry.dat
set STEERING = reconCharge.xml

set BENCHS = (alphaCenter alphaLateral alphaLateral2 alphaLateral3 muonCenter muonLateral)

foreach bench ($BENCHS)
echo $bench
$MC -det $DET -m ${bench}.mac

    foreach file (${bench}.*.MCout.root)
	set nchar = `echo $file | awk '{print length($0)}'`
	set length = 0
	@ length = $nchar - 11 
	set name = `echo $file $length | awk '{print substr($1,1,$2)}'`
	echo $name  #This is ${bench}.RunNumber
	$RECON -s $STEERING $file -DCHARGE_TXT=\"${name}.ChargeOut.txt\" -DCHARGE_ROOT=\"${name}ChargeOut.root\"
    end
end
