#!/bin/bash
export RIVET_ANALYSIS_PATH=$PWD


rivet-build RivetBRAHMS_2007_I742956.so BRAHMS_2007_I742956.cc

rivet-build RivetSTAR_2003_I631869.so STAR_2003_I631869.cc
rivet-build RivetSTAR_2006_I709170.so STAR_2006_I709170.cc
rivet-build RivetSTAR_2012_I930463.so STAR_2012_I930463.cc 

rivet-build RivetSTAR_2019_I1771348.so STAR_2019_I1771348.cc 
rivet-build RivetSTAR_2020_I1783875.so STAR_2020_I1783875.cc
rivet-build RivetSTAR_2021_I1853218.so STAR_2021_I1853218.cc



mkfifo pp200GeV.hepmc 
cat pp200GeV.hepmc > /dev/null &

pythia8-main144 -c pp200GeV.cmnd -c main144HepMC.cmnd -c main144Rivet.cmnd -o pp200GeV

pkill -f "cat pp200GeV.hepmc"
rm -f pp200GeV.hepmc
