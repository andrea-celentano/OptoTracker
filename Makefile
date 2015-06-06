
packages = Geometry Simulation Reconstruction MarocAnalysis

all: $(packages) 

$(packages):
	echo Doing $@ && \
	mkdir -p ${OPTO}/packages/$@/build && \
	cd ${OPTO}/packages/$@/build && cmake ../ && \
	cmake -DCMAKE_BUILD_TYPE=Release ../ ; \
	make -j16 install

clean:
	for package in ${packages} ; do \
		cd ${OPTO}/packages/$$package/build ; \
		rm -rf * ; \
	done ; \
	cd ${OPTO}/bin ; rm * ; cd ${OPTO}/lib ; rm *

debug:
	for package in ${packages} ; do \
                cd ${OPTO}/packages/$$package/build ; \
                cmake -DCMAKE_BUILD_TYPE=Debug ../ ; \
		make -j16 install ; \
        done
