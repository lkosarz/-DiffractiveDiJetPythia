#===============================================================================
#   File: Makefile
#
#   Example Makefile for Pythia8 written for HF in STAR
#   Author: Thomas Ullrich
#   Last modified: September 9, 2008
#
#   This needs 3 packages installed: Pythia8, LHAPDF, and ROOT
#
#   This is setup for Mac OS X 10.5.4 but should be easy to 
#   adapt for other (Unix) platforms. In principle changing the
#   program name (PROGRAM), the location of PYTHIA (PYTHIAPATH),
#   and the LHAPDF libraries (LHAPDFPATH) should do the job.
#   Note that the environment variable ROOTSYS needs to be set.
#   Otherwise define it here in the makefile.
#===============================================================================
PROGRAM  =  pythiaDiffractiveDiJet
#PYTHIAPATH   = /users/PAS2524/lkosarz/Pythia/pythia8312
PYTHIAPATH   = /opt/local
LHAPDFPATH   = /users/PAS2524/lkosarz/LHAPDF/LHAPDF-6.5.4

DICTHEADERS = PythiaEvent.h LinkDef.h

ROOTINC = `root-config --incdir`
ROOTLIB = `root-config --libdir`

CXX      =  gcc
CXXFLAGS = -O  -W -Wall -m64 -std=c++20
CPPFLAGS = -I$(PYTHIAPATH)/include -I$(ROOTSYS)/include -I$(ROOTINC)
LDFLAGS  = -L$(PYTHIAPATH)/lib -L$(ROOTSYS)/lib -L$(ROOTLIB) -L$(LHAPDFPATH) -lpythia8 -lHepMC3 -lstdc++ -lCore -lThread -lRIO -lNet -lHist -lMathCore -lGraf -lGraf3d -lGpad -lTree -lRint -lPostscript -lMatrix -lPhysics -lfreetype -lpthread -lm -ldl

#LDFLAGS  = -L$(PYTHIAPATH)/lib/archive -L$(ROOTSYS)/lib -L$(LHAPDFPATH) -lLHAPDF -lpythia8 -llhapdfdummy -lCore -lCint -lRIO -lNet -lHist -lGraf -lGraf3d -lGpad -lTree -lRint -lPostscript -lMatrix -lPhysics -lfreetype -lpthread -lm -ldl

$(PROGRAM):	$(PROGRAM).cpp DictOutput.cxx libPythiaEvent.so
		$(CXX) $(CXXFLAGS) $(PROGRAM).cpp $(CPPFLAGS) DictOutput.cxx $(LDFLAGS) libPythiaEvent.so -o $(PROGRAM)
		
DictOutput.cxx : PythiaEvent.h
	rootcint -f $@ -c $(DICTHEADERS)
	
libPythiaEvent.so :
	$(CXX) -shared -o $@ $(CXXFLAGS) $(CPPFLAGS) $^ $(LDFLAGS)

clean:
		rm -f $(PROGRAM) core *.o *.so DictOutput.cxx