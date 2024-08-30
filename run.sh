#!/bin/sh

#starpro
#setup 64b
#setup ROOT 5.34.38
#source /star/u/huangbc/.cshrc
#cd /star/u/zbtang/myTools/root/
#source bin/thisroot.csh

export ROOTLIB=`root-config --libdir`

	#export PYTHIA8=/users/PAS2524/lkosarz/Pythia/pythia8312
	export PYTHIA8=/opt/local
	export LHAPDFSYS=/users/PAS2524/lkosarz/LHAPDF/LHAPDF-6.5.4
	export PATH=${PATH}:${LHAPDFSYS}/bin	
	export LD_LIBRARY_PATH=${LD_LIBRARY_PATH}:${LHAPDFSYS}/lib:${PYTHIA8}/lib:${ROOTLIB}
	
	export PYTHIA8DATA=${PYTHIA8}/share/Pythia8/xmldoc


./pythiaDiffractiveDiJet ep_diffractiveDiJets.cmnd diffractiveDiJets_ep_18x275GeV | tee test.log
