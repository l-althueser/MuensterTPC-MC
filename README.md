# MuensterTPC-Simulation
The MuensterTPC-Simulation was developed in order to built and test a small dual phase xenon TPC (height: 17cm, diameter: 8cm) at Muenster. This includes simulations with optical photons, external and internal radioactive sources. This software stands under the BSD license (see [LICENSE](./LICENSE)).

## Installation Prerequisites
This software can only be used with `GEANT4 10.02.p01 64bit` in Linux or Windows Subsystem for Linux. 

## Installing the MuensterTPC-Simulation
There are two ways to install this simulation. Option one is to youse the GitHub interface to download and extract the master branch to a specific directory ([download link](https://github.com/l-althueser/MuensterTPC-Simulation/archive/master.zip)). Option two will follow the real GitHub way of doing this ..  

First `cd` to the folder you want the Analyzer to be installed (this should be your `geant4_workdir`). Therefore we assume that Geant4 is correctly installed. Then run:
```
cd $G4WORKDIR
git clone https://github.com/l-althueser/MuensterTPC-Simulation.git
```
Second you have to compile the Geant4 code and link correctly to the generated binary file. (Note: You can always rename `MuensterTPC-Simulation.cc` to `MuensterTPC-*.cc` and the makefile will still work.)
```
cd MuensterTPC-Simulation
make clean
make
make link
```
Now you should be able to run the simulation in `interactive` mode by typing:
```
./MuensterTPC-Simulation
```

## MuensterTPC-Simulation Tutorial
This section assumes that the MuensterTPC-Simulation is installed and all prerequisits are given. 

### Usage
The simulation offers the possibility to use some arguments in order to adjust every run time parameter.
```
./MuensterTPC-Simulation -p <custom_preinit.mac> -f <source_definition.mac> -o <outputfilename> -n <number_of_events> -v <verbositie_level> -i
```
* `-p <custom_preinit.mac>`: A default `preinit.mac` will be used if no custom file is given.
* `-p <custom_preinit.mac>`: A default `preinit.mac` will be used if no custom file is given.
* `-f <source_definition.mac>`: This parameter has to be specified if `-i` is not set.
* `-o <outputfilename>`: The output file name will be `events.root` or `<source_definition>.root` if not specified.
* `-n <number_of_events>`: Has to be specified if `-i` is not set.
* `-v <verbositie_level>`: The verbosity level is `0` per default.
* `-i`: This activates the `interactive` mode in a Qt window.

### Simple `opticalphotn` simulation
```
./MuensterTPC-Simulation -f ./macros/src_optPhot_DP.mac -o optPhot_1e8.root -n 100000000
```
