// -*- C++ -*-
#include "Rivet/Analysis.hh"
#include "Rivet/Projections/FinalState.hh"
#include "Rivet/Projections/FastJets.hh"
#include "Rivet/Projections/PromptFinalState.hh"
#include "math.h"

namespace Rivet {


  /// @brief Add a short analysis description here
  class BRAHMS_2007_I742956 : public Analysis {
  public:

    /// Constructor
    RIVET_DEFAULT_ANALYSIS_CTOR(BRAHMS_2007_I742956);

    /// Book histograms and initialise projections before the run
    void init() {
       
        const FinalState fs(Cuts::abseta < 5);
        declare(fs, "fs");
    
        book(_h["CrsSecPIplus"], 1, 1, 1);
        book(_h["CrsSecPIminus"], 2, 1, 1);
        book(_h["CrsSecKplus"], 3, 1, 1);
        book(_h["CrsSecKminus"], 4, 1, 1);
        book(_h["CrsSecP"], 5, 1, 1);
        book(_h["CrsSecAntiP"], 6, 1, 1);

        book(_h["CrsSecPIplus2"], 7, 1, 1);
        book(_h["CrsSecPIminus2"], 8, 1, 1);
        book(_h["CrsSecKplus2"], 9, 1, 1);
        book(_h["CrsSecKminus2"], 10, 1, 1);
        book(_h["CrsSecP2"], 11, 1, 1);
        book(_h["CrsSecAntiP2"], 12, 1, 1);
        
        
    }


    /// Perform the per-event analysis
    void analyze(const Event& event) {

        Particles fsParticles = apply<FinalState>(event,"fs").particles();
	
        for(const Particle& p : fsParticles)
        {

            double ySize = .1;
            
            double pT = p.pT() / GeV;
            
            if((p.rapidity()>2.9)&&(p.rapidity()<3.0)){ // Interested in regions near 2.95
                if(p.pid() == 211) _h["CrsSecPIplus"]->fill(pT,(1.0/pT)*(1.0/(2.0*pi))*(1.0/ySize)); //Pion
                if(p.pid() == -211) _h["CrsSecPIminus"]->fill(pT,(1.0/pT)*(1.0/(2.0*pi))*(1.0/ySize));
            
                if(p.pid() == 321) _h["CrsSecKplus"]->fill(pT,(1.0/pT)*(1.0/(2.0*pi))*(1.0/ySize)); //Kaon
                if(p.pid() == -321) _h["CrsSecKminus"]->fill(pT,(1.0/pT)*(1.0/(2.0*pi))*(1.0/ySize));
            
                if(p.pid() == 2212) _h["CrsSecP"]->fill(pT,(1.0/pT)*(1.0/(2.0*pi))*(1.0/ySize)); //Pion
                if(p.pid() == -2212) _h["CrsSecAntiP"]->fill(pT,(1.0/pT)*(1.0/(2.0*pi))*(1.0/ySize));
            }
            if((p.rapidity()>3.25)&&(p.rapidity()<3.35)){ // Interested in regions near 3.3
                if(p.pid() == 211) _h["CrsSecPIplus2"]->fill(pT,(1.0/pT)*(1.0/(2.0*pi))*(1.0/ySize)); //Pion
                if(p.pid() == -211) _h["CrsSecPIminus2"]->fill(pT,(1.0/pT)*(1.0/(2.0*pi))*(1.0/ySize));
            
                if(p.pid() == 321) _h["CrsSecKplus2"]->fill(pT,(1.0/pT)*(1.0/(2.0*pi))*(1.0/ySize)); //Kaon
                if(p.pid() == -321) _h["CrsSecKminus2"]->fill(pT,(1.0/pT)*(1.0/(2.0*pi))*(1.0/ySize));
            
                if(p.pid() == 2212) _h["CrsSecP2"]->fill(pT,(1.0/pT)*(1.0/(2.0*pi))*(1.0/ySize)); //Pion
                if(p.pid() == -2212) _h["CrsSecAntiP2"]->fill(pT,(1.0/pT)*(1.0/(2.0*pi))*(1.0/ySize));
            }
        
        }
        
    }


    /// Normalise histograms etc., after the run
    void finalize() {
        
        scale(_h["CrsSecPIplus"], ((crossSection()/millibarn)/sumOfWeights())); // XSec is in units of mb in paper. Typicall run prints out in picobarns
        scale(_h["CrsSecPIminus"], ((crossSection()/millibarn)/sumOfWeights()));
        scale(_h["CrsSecKplus"], ((crossSection()/millibarn)/sumOfWeights()));
        scale(_h["CrsSecKminus"], ((crossSection()/millibarn)/sumOfWeights()));
        scale(_h["CrsSecP"], ((crossSection()/millibarn)/sumOfWeights()));
        scale(_h["CrsSecAntiP"], ((crossSection()/millibarn)/sumOfWeights()));
        scale(_h["CrsSecPIplus2"], ((crossSection()/millibarn)/sumOfWeights()));
        scale(_h["CrsSecPIminus2"], ((crossSection()/millibarn)/sumOfWeights()));
        scale(_h["CrsSecKplus2"], ((crossSection()/millibarn)/sumOfWeights()));
        scale(_h["CrsSecKminus2"], ((crossSection()/millibarn)/sumOfWeights()));
        scale(_h["CrsSecP2"], ((crossSection()/millibarn)/sumOfWeights()));
        scale(_h["CrsSecAntiP2"], ((crossSection()/millibarn)/sumOfWeights()));
                
    }
 

    map<string, Histo1DPtr> _h;
    

  };


  RIVET_DECLARE_PLUGIN(BRAHMS_2007_I742956);

}
