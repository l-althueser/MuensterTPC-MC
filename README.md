# MuensterTPCsim

## Simulations of the Muenster TPC (GEANT4 10.02.p01 64bit)

@author Lutz Althueser  
@date   2016-02-02  
@updated 2016-03-17  

@comment   

**HowTo**:	
start visualization:	./muensterTPCsim  
start batch mode:	./muensterTPCsim /.../.../*.mac  
 
----

## Make a new branch/fork:
* rename the folder and the main *.cc file
* (no changes in the makefile needed)
* delete the old link to the binaries
* execute a 'make clean'
* execute a 'make'
* execute a 'make link'

----

## Changes:

### @changelog 20160202 
* (Geant4 10.02.p01 | ROOT 5.34.34 | Ubuntu 14.04 64bit)
* (new cmake version .. (not needed to use the binaries))
* fixed Kr-83m bug
* added progress line
* added MT ...
* set all paths in the Makefile to relative paths

### @changelog 20150928 
* (Geant4 10.1.p01 (p02,p03) | ROOT 5.34 | Ubuntu 14.04 64bit)
* new Makefile
* some new parameters for the DetectorConstruction
* some fixes
* added comments

### @changelog 20150805
* (Geant4 10.1 | ROOT 5.34 | Ubuntu 14.04 64bit)
* add possibility to change the LXe volume material /Xe/gun/setMat
* add maxTrackLength to optical photons - after 100m they will disappear
* some fixes
	
### @changelog 20150624_alth 
* (Geant4 10.1 | ROOT 5.34 | Ubuntu 14.04 64bit)
* new filehandling of the analysis scripts (now no directory configuration is needed)
* add instructions to create a new branch for the simulation and data parts

### @changelog 20150507_alth 
* (Geant4 10.1 | ROOT 5.34 | Ubuntu 14.04 64bit)
* Xenon100->muensterTPC
* various bug fixes
* new EventAction
* new values for Scintillation
* new branches in the root file
* recoding of some parts of the simulation

### @changelog 20150410_alth 
* (Geant4 10.1 | ROOT 5.34 | Ubuntu 14.04 64bit)
* completly new PhysicsList
* new RandomNumbersGenerator
* some new libs included (Units etc.)
* Qt-Plot
* dataanalysis
 
### @changelog 20121017 
* (Geant4 9.5.2 | ROOT 5.X | 64bit )

