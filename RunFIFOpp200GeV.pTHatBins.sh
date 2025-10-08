#!/bin/bash
export RIVET_ANALYSIS_PATH=$PWD




rivet-build RivetBRAHMS_2007_I742956.so BRAHMS_2007_I742956.cc

rivet-build RivetSTAR_2003_I631869.so STAR_2003_I631869.cc
rivet-build RivetSTAR_2006_I709170TEST.so STAR_2006_I709170TEST.cc
rivet-build RivetSTAR_2012_I930463.so STAR_2012_I930463.cc 

rivet-build RivetSTAR_2019_I1771348.so STAR_2019_I1771348.cc 
rivet-build RivetSTAR_2020_I1783875.so STAR_2020_I1783875.cc
rivet-build RivetSTAR_2021_I1853218.so STAR_2021_I1853218.cc



mkfifo pp200GeV.hepmc 
cat pp200GeV.hepmc > /dev/null &
pythia8-main144 -c pp200GeV.1.cmnd -c main144HepMC.cmnd -c main144Rivet.cmnd -o pp200GeV.1
pkill -f "cat pp200GeV.hepmc"
rm -f pp200GeV.hepmc


mkfifo pp200GeV.hepmc 
cat pp200GeV.hepmc > /dev/null &
pythia8-main144 -c pp200GeV.2.cmnd -c main144HepMC.cmnd -c main144Rivet.cmnd -o pp200GeV.2
pkill -f "cat pp200GeV.hepmc"
rm -f pp200GeV.hepmc

mkfifo pp200GeV.hepmc 
cat pp200GeV.hepmc > /dev/null &
pythia8-main144 -c pp200GeV.3.cmnd -c main144HepMC.cmnd -c main144Rivet.cmnd -o pp200GeV.3
pkill -f "cat pp200GeV.hepmc"
rm -f pp200GeV.hepmc

mkfifo pp200GeV.hepmc 
cat pp200GeV.hepmc > /dev/null &
pythia8-main144 -c pp200GeV.4.cmnd -c main144HepMC.cmnd -c main144Rivet.cmnd -o pp200GeV.4
pkill -f "cat pp200GeV.hepmc"
rm -f pp200GeV.hepmc

mkfifo pp200GeV.hepmc 
cat pp200GeV.hepmc > /dev/null &
pythia8-main144 -c pp200GeV.5.cmnd -c main144HepMC.cmnd -c main144Rivet.cmnd -o pp200GeV.5
pkill -f "cat pp200GeV.hepmc"
rm -f pp200GeV.hepmc

mkfifo pp200GeV.hepmc 
cat pp200GeV.hepmc > /dev/null &
pythia8-main144 -c pp200GeV.6.cmnd -c main144HepMC.cmnd -c main144Rivet.cmnd -o pp200GeV.6
pkill -f "cat pp200GeV.hepmc"
rm -f pp200GeV.hepmc

mkfifo pp200GeV.hepmc 
cat pp200GeV.hepmc > /dev/null &
pythia8-main144 -c pp200GeV.7.cmnd -c main144HepMC.cmnd -c main144Rivet.cmnd -o pp200GeV.7
pkill -f "cat pp200GeV.hepmc"
rm -f pp200GeV.hepmc

mkfifo pp200GeV.hepmc 
cat pp200GeV.hepmc > /dev/null &
pythia8-main144 -c pp200GeV.8.cmnd -c main144HepMC.cmnd -c main144Rivet.cmnd -o pp200GeV.8
pkill -f "cat pp200GeV.hepmc"
rm -f pp200GeV.hepmc

rivet-merge --pwd pp200GeV.1.yoda pp200GeV.2.yoda pp200GeV.3.yoda pp200GeV.4.yoda pp200GeV.5.yoda pp200GeV.6.yoda pp200GeV.7.yoda pp200GeV.8.yoda -o pp200pThatbins.yoda
rivet-mkhtml --pwd pp200pThatbins.yoda
