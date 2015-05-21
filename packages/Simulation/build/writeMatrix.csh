#!/bin/tcsh -f


set file=pixels/run0.out
cat $file > matrix.dat
echo " " >> matrix.dat
foreach x(`seq 1 1 999`)
    set file=pixels/run$x.out
    if ( -f $file ) then 
	echo $file
	cat $file >> matrix.dat
	echo " " >> matrix.dat
    endif
end
