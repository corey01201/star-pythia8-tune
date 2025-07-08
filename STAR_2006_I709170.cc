// -*- C++ -*-
#include "Rivet/Analysis.hh"
#include "Rivet/Projections/FinalState.hh"

namespace Rivet {

  class STAR_2006_I709170: public Analysis {
  public:

    /// Constructor
    RIVET_DEFAULT_ANALYSIS_CTOR(STAR_2006_I709170);


    /// Book projections and histograms
    void init() {

      FinalState pionfs(Cuts::abseta < 2.5 && Cuts::pT > 0.3*GeV && Cuts::abspid == PID::PIPLUS);
      FinalState protonfs(Cuts::abseta < 2.5 && Cuts::pT > 0.4*GeV && Cuts::abspid == PID::PROTON);
      declare(pionfs, "PionFS");
      declare(protonfs, "ProtonFS");

      book(_h["pT_piplus"],      2, 1, 1); // full range pion binning
      book(_h["pT_piminus"],     7, 1, 1); // full range pion binning
      book(_h["tmp_pT_piplus"],  "TMP/pT_piplus",  refData(25, 1, 2)); // pi histo compatible with more restricted proton binning
      book(_h["tmp_pT_piminus"], "TMP/pT_piminus", refData(26, 1, 2)); // pi histo compatible with more restricted proton binning
      book(_h["pT_proton"],      12, 1, 1);
      book(_h["pT_antiproton"],  17, 1, 1);

      book(_e["piminus_piplus"], 23, 1, 2);
      book(_e["antipr_pr"]     , 24, 1, 2);
      book(_e["pr_piplus"]     , 25, 1, 2);
      book(_e["antipr_piminus"], 26, 1, 2);
    }


    /// Do the analysis
    void analyze(const Event& event) {

      const FinalState& pionfs = apply<FinalState>(event, "PionFS");
      for (const Particle& p : pionfs.particles(Cuts::absrap < 0.5)) {
        const double pT = p.pT() / GeV;
        _h[(p.pid() > 0)? "pT_piplus"     : "pT_piminus"]->fill(pT, 1.0/pT);
        _h[(p.pid() > 0)? "tmp_pT_piplus" : "tmp_pT_piminus"]->fill(pT, 1.0/pT);
      }

      const FinalState& protonfs = apply<FinalState>(event, "ProtonFS");
      for (const Particle& p : protonfs.particles(Cuts::absrap < 0.5)) {
        const double pT = p.pT() / GeV;
        _h[(p.pid() > 0)? "pT_proton" : "pT_antiproton"]->fill(pT, 1.0/pT);
      }
    }


    /// Finalize
    void finalize() {
      divide(_h["pT_piminus"],    _h["pT_piplus"],      _e["piminus_piplus"]);
      divide(_h["pT_antiproton"], _h["pT_proton"],      _e["_antipr_pr"]);
      divide(_h["pT_proton"],     _h["tmp_pT_piplus"],  _e["_pr_piplus"]);
      divide(_h["pT_antiproton"], _h["tmp_pT_piminus"], _e["antipr_piminus"]);
      scale(_h, 1.0/ TWOPI / sumOfWeights());
    }


  private:

    map<string,Histo1DPtr> _h;
    map<string,Estimate1DPtr> _e;

  };


  // The hook for the plugin system
  RIVET_DECLARE_PLUGIN(STAR_2006_I709170);

}
