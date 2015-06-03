
packages = Geometry Simulation Reconstruction MarocAnalysis

all: $(packages) 

$(packages):
	echo Doing $@ && \
	mkdir -p ${OPTO}/packages/$@/build && \
	cd ${OPTO}/packages/$@/build && cmake ../ && \
	make -j16 install

clean:
	for package in ${packages} ; do \
		cd ${OPTO}/packages/$$package/build ; \
		rm -rf * ; \
	done
