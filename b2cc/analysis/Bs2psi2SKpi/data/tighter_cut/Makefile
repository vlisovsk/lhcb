# $Id: Makefile,v 1.30 2009/11/11 17:18:14 gcowan Exp $
SHELL = /bin/sh
UNAME = $(shell uname)

# Root variables
ROOTCFLAGS   = -L$(ROOTSYS)/lib $(shell $(ROOTSYS)/bin/root-config --cflags)
ROOTLIBS     = -L$(ROOTSYS)/lib $(shell $(ROOTSYS)/bin/root-config --libs)
ROOTGLIBS    = -L$(ROOTSYS)/lib $(shell $(ROOTSYS)/bin/root-config --glibs)

 #GSLPATH      =/usr/local#/afs/cern.ch/sw/lcg/external/GSL/1.8/$(CMTCONFIG)
 #GSLINC       =$(GSLPATH)/include
 #GSLLIB       =$(GSLPATH)/lib

################
##linux
CXX          = g++
RM           = rm -f
AR           = ar cru

##Flags
#CXXFLAGS     += -D_DEBUG
CXXFLAGS     = -O3 -gstabs -fPIC -funroll-loops -D__ROOFIT_NOBANNER # -Wall

GARBAGE  = $(OBJDIR)/*.o *.so *.rootmap 
INCDIR = /Home/gcowan1/software/RapidFit/trunk/pdfs/dalitz/include

#################
##Dependencies
# Linux
ifeq "$(UNAME)" "Linux"
RANLIB       = ranlib
CXXFLAGS    += -I$(INCDIR) $(ROOTCFLAGS) #-I$(GSLINC)
LINKFLAGS    =
endif

# OS X
ifeq "$(UNAME)" "Darwin"
RANLIB       = ranlib
CXXFLAGS    += -I$(INCDIR) $(ROOTCFLAGS) #-I$(GSLINC)
LINKFLAGS    = -m64
endif

##Libraries
LIBS       += $(ROOTLIBS) -lHtml -lThread -lMinuit -lMathCore -lMinuit2 -lRooStats -lRooFit -lRooFitCore -lFoam #-lProof #-lboost_thread #-lMathMore

plot_distributions_mJpsipi : plot_distributions_mJpsipi.C
	$(CXX) $(CXXFLAGS) $(LIBS) /Home/gcowan1/software/RapidFit/trunk/pdfs/dalitz/src/CalculateAngles.cc /Home/gcowan1/software/RapidFit/trunk/pdfs/dalitz/src/DPHelpers.cc plot_distributions_mJpsipi.C -o plot_distributions_mJpsipi

clean   :
	$(RM) $(GARBAGE)

cleanall:
	$(RM) $(GARBAGE)


