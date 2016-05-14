# --------------------------------------------------------------
# GNUmakefile of MuensterTPCsim
#
# @author Lutz Althueser
# @date   2015-07-07
#
# changes:
#		20150928: - added support for changeable main class file name
#							- added 'link' parameter to automatic link the binaries
#							- disable warnings with the '-w' flag
#							- turn on optimmization by deleting the '-g' flag
# --------------------------------------------------------------

# get full name of the main class file
name := $(shell find -name 'muensterTPCsim*.cc' -exec basename {} .cc \;)
G4TARGET := $(name)
G4EXLIB := true

G4DEBUG := 0

ROOTCFLAGS      = $(shell root-config --cflags) -Wno-shadow -w
ROOTLIBS        = $(shell root-config --nonew --libs)
ROOTGLIBS       = $(shell root-config --glibs)

EXTRALIBS +=$(ROOTLIBS)
CPPFLAGS += $(ROOTCFLAGS)

.PHONY: all
all: lib bin

include $(G4INSTALL)/config/binmake.gmk

# call this routine with 'make link' to create a new symlink of the binary
link: 
	[ -f $(name) ] || ln -s $(G4WORKDIR)/bin/Linux-g++/$(name) ./$(name)
