These analyses now work in Rivet 4.1.  

The script RunFIFOpp200GeV.sh can be used to run these analyses in the PYTHIA-Rivet docker container to allow for testing.  This uses the following configuration files to run the PYTHIA example code main144 to generate HEPMC files in FIFO mode and pipe them into Rivet without writing them to disk:
main144HepMC.cmnd
main144Rivet.cmnd
pp200GeV.cmnd
