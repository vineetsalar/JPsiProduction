//
// simple Glauber MC calculation
// 
// Lecture QGP physics: from fixed target to LHC
// Prof. Dr. J. Stachel, PD Dr. Klaus Reygers
//
// http://www.physi.uni-heidelberg.de/~reygers/lectures/2011/qgp/qgp_lecture_ss2011.html
//
 // c++ classes
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <iomanip>
#include <fstream>
#include <ctime>
// ROOT classes
#include "TH1F.h"
#include "TF1.h"
#include "TGraph.h"
#include "TGraphErrors.h"
#include <TMath.h>
#include <TLegend.h>
#include "TCanvas.h"
#include <TPad.h>
#include "TStyle.h"
#include "TFile.h"
#include "TRandom.h"
#include "TLine.h"
#include "TLatex.h"

// some constants
const Int_t A_max = 250;
const Float_t sigma_nn_inel_fm2 = 64. / 10; // 1 mb = 0.1 fm^2

// histograms
TH1F* hImpactAll = new TH1F("hImpactAll","hImpactAll",100.,0.,20.);
TH1F* hImpactInel = new TH1F("hImpactInel","hImpactInel",100.,0.,20.);

// impact parameter distribution,
// in principle 2*pi*b, but overall normalization is irrelevant here
TF1* fImpact = new TF1("fImpact","x",0.,20.); 

// --- a simple class for a nucleon -----------------------------------
class nucleon {
public:
  Float_t x, y, z;
  Int_t ncoll;
};

// --- a simple class for a nucleus -----------------------------------
class nucleus {

  Int_t A; // mass number
  TF1* ws; // Woods-Saxon distribution
  TF1* th; // probability distribution for angle theta

  void DefineShape(const Float_t&, const Float_t&);

public:
  nucleon nucleon[A_max]; // nucleons

  void DistributeNucleons(const Float_t&);
  Int_t GetMassNumber() {return A;};
};

nucleus::nucleus(const Int_t mass_number, const Float_t& r, const Float_t& d) {
  A = mass_number;
  DefineShape(r,d);
};

//! Defines Woods-Saxon distribution
void nucleus::DefineShape(const Float_t& ws_radius, const Float_t& ws_diffuseness) {

  // probability distribution for the radius
  ws = new TF1("Woods-Saxon","x*x/(1+exp((x-[0])/[1]))",0.,20.);
  ws->SetParameter(0, ws_radius);
  ws->SetParameter(1, ws_diffuseness);
  // also define probability distribution of theta
  th = new TF1("th","sin(x)",0.,TMath::Pi());

};

void nucleus::DistributeNucleons(const float& x_offset) {

  // loop over all nucleons
  for(int i=0; i<A; i++) {
    
    float r     = ws->GetRandom(); // radius from Woods-Saxon
    float theta = th->GetRandom();
    float phi   = 2.* TMath::Pi() * gRandom->Rndm();
    
    // coordinates in local coordinate system
    nucleon[i].x = r * sin(theta) * cos(phi) + x_offset;
    nucleon[i].y = r * sin(theta) * sin(phi);
    nucleon[i].z = r * cos(theta);
   
    // set collision counter to zero
    nucleon[i].ncoll = 0;
 
  }
};

// --- the main part: Glauber MC calculation -------------------------
void glauber_mc() {

  nucleus* Target = new nucleus(208, 6.68, 0.546);
  nucleus* Projectile = new nucleus(208, 6.68, 0.546);
  
  cout << Projectile->GetMassNumber() << endl;

  Int_t n_events = 1000;

  // produce n_events Glauber MC collisions
  for (int i=0; i< n_events; i++) {

    // sample impact parameter distribution
    float b = fImpact->GetRandom();

    // Distribute nucleons according to Woods-Saxon dsitribution
    // and displace them by -b/2 and b/2 on the x axis.
    // Moreover, set collision counter of each nucleon to zero
    Target->DistributeNucleons(-b/2);
    Projectile->DistributeNucleons(+b/2);

    int Npart = 0;
    int Ncoll = 0;

    for (int ip=0; ip<Projectile->GetMassNumber(); ip++) {
      for (int it=0; it<Target->GetMassNumber(); it++) {

	// squared transverse distance of the nucleons
	float dx   = Projectile->nucleon[ip].x - Target->nucleon[it].x;
	float dy   = Projectile->nucleon[ip].y - Target->nucleon[it].y;
	float dxy2 = dx*dx + dy*dy; 

	// check if there is a nn collision
	if (dxy2 < sigma_nn_inel_fm2/TMath::Pi()) {
	  Ncoll++;       
          if (Projectile->nucleon[ip].ncoll++ == 0) Npart++;
          if (Target->nucleon[it].ncoll++ == 0) Npart++;
	}

      }
    }
    if (i%200 == 0) cout << "Event " << i << ": Npart = " << Npart << ", Ncoll = " << Ncoll << endl; 

    // fill histrograms
    hImpactAll->Fill(b);
    if (Ncoll>0) hImpactInel->Fill(b);
    
  }  // event loop


  new TCanvas;
  hImpactAll->Draw();

  new TCanvas;
  hImpactInel->Draw();



}



