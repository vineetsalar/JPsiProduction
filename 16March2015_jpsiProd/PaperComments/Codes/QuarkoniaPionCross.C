// c++ classes
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <iomanip>
#include <fstream>
#include <ctime>
// ROOT classes
#include "TROOT.h"
#include "TH1F.h"
#include "TF1.h"
#include "TGraph.h"
#include "TGraphErrors.h"
#include <TMath.h>
#include "TVector3.h"
#include <TLegend.h>
#include "TCanvas.h"
#include <TPad.h>
#include "TStyle.h"
#include "TFile.h"
#include "TRandom.h"
#include "TLine.h"
#include "TLatex.h"
#include "TSystem.h"

// constants
Double_t pi = TMath::Pi();
Double_t pi2 = pi*pi;
Double_t pi3 = pi2*pi;
Double_t twopi3 = 8.0*pi*pi*pi;
Double_t hbarc = 0.197327;
Double_t hbarc2 = hbarc*hbarc;
Double_t hbarc3 = hbarc2*hbarc;

// =================================== LHAPDF =====================//
//#include "LHAPDF/LHAPDF.h"
//using namespace std;
//using namespace LHAPDF;




//sigma in fm^2 (1 fm^2 = 10 mb)
//==================== Parameters JPsi =======================//
Double_t mJpsi = 3.0999;
//Values in paper hep-ph::0102095v2
//Double_t mQ = 1.94;
//Double_t ep0=0.78;

//Values in our paper
Double_t mQ = 1.87;
Double_t ep0=0.64;
Double_t mQ2 = mQ*mQ;
Double_t ep02=ep0*ep0;
//Double_t epCon = 4.0*pi*pow(8./3.0,3)*pow(ep0, 3)/pow(mQ, 1.5);
//Double_t redMass = mQ/2.0;
Double_t a0 = 1.0/TMath::Sqrt(mQ*ep0);
Double_t epConMod = (8.0*pi*16.0*16.0/27.0)*(a0/mQ);



/*
//sigma in fm^2 (1 fm^2 = 10 mb)
//==================== Parameters Upsilon =======================//
Double_t mJpsi = 9.44999;

//Values in paper hep-ph::0102095v2
//Double_t mQ = 5.10;
//Double_t ep0=0.75;

Double_t mQ =4.2 ;
Double_t ep0=1.1;
Double_t mQ2 = mQ*mQ;
Double_t ep02=ep0*ep0;
Double_t a0 = 1.0/TMath::Sqrt(mQ*ep0);
Double_t epConMod = (8.0*pi*16.0*16.0/27.0)*(a0/mQ);
*/


//=============== GMV Gluon Diss Constants ========================//
Double_t mPion = 0.140;
//Double_t mPion = 0.938;
Double_t SigmaDMod(Double_t w);
Double_t GluonDiss_GMV(Double_t Q2, Double_t x);

Double_t SigmaDQuPion_ss(Double_t ss);
Double_t SigmaDQuPion(Double_t Lambda);
Double_t SigmaDQuPionFunc(Double_t Lambda, Double_t x);
//Double_t PartonDissFunction(Int_t nf, Double_t Q2, Double_t x);

Int_t QQbarVar =1;



//========================= Function for Inetial temperature ===============//
Double_t ALICEPara(Double_t Eta);
Double_t IntALICEPara(Double_t EtaMin, Double_t EtaMax, Double_t EtaStep);


void QuarkoniaPionCross()
{
  //==================================//
  gROOT->SetStyle("Plain");
  gStyle->SetPalette(1);
  gStyle->SetOptTitle(0);
  //gStyle->SetOptStat("nmr");
  gStyle->SetOptStat(0);
  gStyle->SetOptFit(0);
  gStyle->SetTitleFillColor(0);
  gStyle->SetStatColor(0);
  gStyle->SetFrameBorderMode(0);
  gStyle->SetFrameFillColor(0);
  gStyle->SetFrameLineColor(kBlack);
  gStyle->SetCanvasColor(0);
  gStyle->SetCanvasBorderMode(0);
  gStyle->SetCanvasBorderSize(0);
  gStyle->SetPadColor(0);
  gStyle->SetPadBorderMode(0);
  gStyle->SetPadBorderSize(0);
  gStyle->SetTextSize(0.04);
  gStyle->SetTextFont(42);
  gStyle->SetLabelFont(42,"xyz");
  gStyle->SetTitleFont(42,"xyz");
  gStyle->SetTitleSize(0.048,"xyz");
  gStyle->SetPadBottomMargin(0.12);
  gStyle->SetPadTopMargin(0.03);
  gStyle->SetPadRightMargin(0.065);
  gStyle->SetPadLeftMargin(0.16);
  //gStyle->SetTitleXOffset(1.15);
  gStyle->SetTitleYOffset(1.5);
  gStyle->SetPadTickX(1);
  gStyle->SetPadTickY(1);
  gStyle->SetCanvasDefH(600);
  gStyle->SetCanvasDefW(600);
  gStyle->SetHistMinimumZero(kTRUE);
  gStyle->SetErrorX(0);   
  gStyle->SetEndErrorSize(0);
  gStyle->SetMarkerStyle(20);
  gStyle->SetMarkerSize(1.0);
  gROOT->ForceStyle();

  /*

  // ======================================== Gluon Diss from LHAPDF =============================//
 //first you have to set path for LD_LIBRARY_PATH by export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/home/vineet/LHAPDF/lib
  //then load libLHAPDF.so
  //then .include include path
  //gSystem->Load("libLHAPDF.so");
  //.include /home/vineet/LHAPDF/include
  //gSystem->Load("eps09.so");


  const int SUBSET = 0;
  const string NAME = "cteq5l";
  // const string NAME = "MRST98lo";
  //const string NAME = "GRV98lo";
  
  LHAPDF::initPDFSet(NAME, LHAPDF::LHGRID, SUBSET);
  //LHAPDF::initPDFSet(NAME, LHAPDF::LHPDF, SUBSET);
  
  cout << "alphas(mz) = " << LHAPDF::alphasPDF(91.188) << endl;
  cout << "qcdlam4    = " << LHAPDF::getLam4(SUBSET) << endl;
  cout << "qcdlam5    = " << LHAPDF::getLam5(SUBSET) << endl;
  cout << "orderPDF   = " << LHAPDF::getOrderPDF() << endl;
  cout << "xmin       = " << LHAPDF::getXmin(SUBSET) << endl;
  cout << "xmax       = " << LHAPDF::getXmax(SUBSET) << endl;
  cout << "q2min      = " << LHAPDF::getQ2min(SUBSET) << endl;
  cout << "q2max      = " << LHAPDF::getQ2max(SUBSET) << endl;
  cout << "orderalfas = " << LHAPDF::getOrderAlphaS() << endl;
  cout << "num flav   = " << LHAPDF::getNf() << endl;
  cout << "name       = " << NAME << endl;
  cout << "number     = " << LHAPDF::numberPDF() << endl;
  cout << endl;  
  LHAPDF::initPDF(SUBSET);
  */
 
  //====================== Parameterize Charged Particle Density =====================================// 
  Double_t Eta[200]={0.0};
  Double_t DNDEta[200]={0.0};
  
  Double_t EtaMin = -8.0;
  Double_t EtaMax = 8.1;
  Double_t EtaStep = 0.1;

  Int_t NEta = (EtaMax - EtaMin)/EtaStep;

  for(int i =0; i<=NEta;i++)
    { 
      Eta[i] = EtaMin + i*EtaStep; 
      DNDEta[i]= ALICEPara(Eta[i]);
    
      cout<<Eta[i]<<"   "<<DNDEta[i]<<endl;

    }


  TGraph *grDNDEta = new TGraph(NEta, Eta, DNDEta);
  grDNDEta->SetLineWidth(2);
  grDNDEta->SetLineColor(4);
  grDNDEta->SetLineStyle(1);

  grDNDEta->GetXaxis()->SetTitle("#eta");
  grDNDEta->GetYaxis()->SetTitle("dN_{ch}/d#eta");
  grDNDEta->GetYaxis()->SetRangeUser(0.0,2200.0);


  new TCanvas;
  gPad->SetTicks();
  grDNDEta->Draw("AL");


  

  cout<<" Integration of DnDEta :" <<endl;
  //cout<<IntALICEPara(-2.4, 2.4, 0.01)<<" CMS   "<<IntALICEPara(-2.4, 2.4, 0.001)<<"   "<<IntALICEPara(-2.4, 2.4, 0.0001)<<endl;
  
  cout<<IntALICEPara(-2.4, 2.4, 0.001)/(4.8*1600.0)<<" CMS   "<<IntALICEPara(2.5, 4.0, 0.001)/(1.5*1600.0)<<" ALICE  "<<endl;


  return;
















  //====================================== Parameterize Gluon-Diss Function =============================//
  Double_t xmin = 0.0001;
  Double_t xmax=1.0;
  Double_t xstep = 0.001;
  Double_t xx[1000]={0.0};
  
  Double_t xGx1[1000]={0.0};
  Double_t xGx2[1000]={0.0};
  Double_t xGx3[1000]={0.0};
 

  int Nx = (xmax - xmin)/xstep;

  for(int i=0;i<Nx;i++)
    {
      xx[i]=xmin + i*xstep;

      xGx1[i]=0.1*GluonDiss_GMV(10,xx[i]);
      xGx2[i]=GluonDiss_GMV(100,xx[i]);
      xGx3[i]=10.0*GluonDiss_GMV(10000,xx[i]);

      //xGx1[i]=0.1*PartonDissFunction(0, 10, xx[i])/xx[i];
      //xGx2[i]=PartonDissFunction(0, 100, xx[i])/xx[i];
      //xGx3[i]=10.0*PartonDissFunction(0, 10000, xx[i])/xx[i];

    }

  TGraph *grxGx1 = new TGraph(Nx, xx, xGx1);
  grxGx1->SetLineWidth(1);
  grxGx1->SetLineColor(1);
  grxGx1->SetLineStyle(9);

  grxGx1->GetXaxis()->SetTitle("x");
  grxGx1->GetYaxis()->SetTitle("xGx");




  TGraph *grxGx2 = new TGraph(Nx, xx, xGx2);
  grxGx2->SetLineWidth(2);
  grxGx2->SetLineColor(1);
  grxGx2->SetLineStyle(9);

  TGraph *grxGx3 = new TGraph(Nx, xx, xGx3);
  grxGx3->SetLineColor(1);
  grxGx3->SetLineWidth(3);
  grxGx3->SetLineStyle(9);
  grxGx3->GetXaxis()->SetTitle("x");
  grxGx3->GetYaxis()->SetTitle("xGx");

  TAxis *Yaxis1 = grxGx3->GetYaxis();
  Yaxis1->SetLimits(0.001,1000.0);
  grxGx3->GetYaxis()->SetRangeUser(0.001,1000.0);


  TLegend *lcat= new TLegend(0.59,0.74,0.88,0.93);
  lcat->SetBorderSize(0);
  lcat->SetFillStyle(0);
  lcat->SetFillColor(0);
  lcat->SetTextSize(0.040);


  lcat->AddEntry(grxGx1,"Q^{2}=10","L");
  lcat->AddEntry(grxGx2,"Q^{2}=100","L");
  lcat->AddEntry(grxGx3,"Q^{2}=10^{4}","L");

  new TCanvas;
  gPad->SetLogx(1);
  gPad->SetLogy(1);
  gPad->SetTicks(1);

  grxGx3->Draw("AL");
  grxGx2->Draw("Lsame");
  grxGx1->Draw("Lsame");
  lcat->Draw("same");
  gPad->RedrawAxis();



//====================================== Gluon-Hadron Cross Section =============================//

//SigmaDQuPion(Double_t Lambda)

  Double_t LbyEp0min = 2.0;
  Double_t LbyEp0max=1000.0;

  Double_t LbyEp0step = 1.0;
  
  Double_t LbyEp0[10000]={2.0,3.0,4.0,5.0,6.0,7.0,8.0,10.0,20.0,30.0,50.0,80.0,100.0,200.0,400.0,600.0,800.0,900.0,1000.0,1200.0,
			  1500.0,2000.0,2500.0,3000.0,3500.0,4000.0,4500.0,5000.0};
  Double_t SigmaYp[10000]={0.0};

  int NLbyEp0 = (LbyEp0max - LbyEp0min)/LbyEp0step;

  NLbyEp0=28;

  for(int i=0; i<NLbyEp0; i++)
    {
      // LbyEp0[i] = LbyEp0min + i *LbyEp0step;
      
      SigmaYp[i] = SigmaDQuPion(LbyEp0[i]*ep0)*hbarc2*10.0;
      
      cout<<" Lambad / epsilon0 "<<LbyEp0[i] << " SigmaYp " << SigmaYp[i] << endl;

    }

  TGraph *grxSigmaYp = new TGraph(NLbyEp0, LbyEp0,SigmaYp);
  grxSigmaYp->SetLineWidth(2);
  grxSigmaYp->SetLineColor(1);
  grxSigmaYp->SetLineStyle(1);
  grxSigmaYp->GetXaxis()->SetTitle("#lambda/#epsilon_{0}");
  grxSigmaYp->GetYaxis()->SetTitle("#sigma_{#varUpsilonp}(mb)");


  new TCanvas;
  gPad->SetLogx(1);
  gPad->SetLogy(1);
  gPad->SetTicks(1);
  gPad->SetTicks(1);

  grxSigmaYp->Draw("AL");


  //return;

  




// ===================================== Calculate the cross section =====================================//

  cout<<"a0 "<<a0<<endl;
  
  Int_t NNJPsi = 49;

  Double_t SSJPsi[100]={4.00, 4.01, 4.03, 4.06, 4.09, 4.11, 4.12, 4.17, 4.22, 4.27, 4.28, 4.33, 4.43, 4.52, 4.73, 4.85, 5.11, 5.52, 5.92, 6.46, 7.05, 7.79, 8.60, 9.61, 10.79, 12.20, 13.70, 15.22, 17.40, 19.43, 21.96, 24.95, 28.36, 31.86, 35.99, 41.15, 46.49, 53.15, 59.35, 67.85, 76.65, 88.14, 100.16, 113.16, 128.60, 142.80, 162.26, 186.56, 210.78, 242.35};




  Double_t SigmaJPsiPion[100]={0.01, 0.02, 0.02, 0.02, 0.03, 0.04, 0.04, 0.05, 0.07, 0.08, 0.10, 0.12, 0.15, 0.18, 0.23, 0.27, 0.33, 0.39, 0.47, 0.55, 0.64, 0.71, 0.82, 0.92, 1.03, 1.15, 1.28, 1.37, 1.49, 1.59, 1.76, 1.89, 2.03, 2.17, 2.29, 2.48, 2.62, 2.82, 2.95, 3.18, 3.27, 3.54, 3.71, 3.92, 4.10, 4.37, 4.50, 4.79, 5.02, 5.35};
  

  TGraph *grSigmaJPsiPion = new TGraph(NNJPsi, SSJPsi, SigmaJPsiPion);
  grSigmaJPsiPion->SetName("grSigmaJPsiPion");
  grSigmaJPsiPion->SetTitle("grSigmaJPsiPion");
  grSigmaJPsiPion->SetLineWidth(2);
  grSigmaJPsiPion->SetLineColor(2);
  grSigmaJPsiPion->SetMarkerColor(2);
  grSigmaJPsiPion->GetXaxis()->SetTitle("s^{1/2} (GeV)");
  grSigmaJPsiPion->GetYaxis()->SetTitle("#sigma_{J/#psi #pi} (mb) ");
  

  TCanvas *C1 =new TCanvas;
  C1->SetLogx();
  C1->SetLogy();
  grSigmaJPsiPion->Draw("APL");



  Double_t CalcSigmaJPsiPion[3000]={0.0};
  Double_t CalcSSJPsiPion[3000]={0.0};
  //  Double_t RootS =0;  
  

  
  for(int i =0; i<NNJPsi; i++)
    {

      //      RootS = RootSMin + i*RootSStep;

      CalcSSJPsiPion[i]=SSJPsi[i];
      
      CalcSigmaJPsiPion[i] =SigmaDQuPion_ss(SSJPsi[i]*SSJPsi[i])*hbarc2*10.0;  
                 
      cout<<" Value of calculated pi-jpsi cross : "<< SSJPsi[i] <<"   "<<CalcSigmaJPsiPion[i]<<endl;

    }

  TGraph *grCalcSigmaJPsiPion = new TGraph(NNJPsi, CalcSSJPsiPion, CalcSigmaJPsiPion);
  
  grCalcSigmaJPsiPion->SetName("grCalcSigmaJPsiPion");
  grCalcSigmaJPsiPion->SetTitle("grCalcSigmaJPsiPion");
  grCalcSigmaJPsiPion->SetLineWidth(2);
  grCalcSigmaJPsiPion->SetLineColor(1);
  grCalcSigmaJPsiPion->SetMarkerColor(1);
  grCalcSigmaJPsiPion->GetXaxis()->SetTitle("s^{1/2} (GeV)");
  grCalcSigmaJPsiPion->GetYaxis()->SetTitle("#sigma_{J/#psi #pi} (mb) ");
  
  TCanvas *C2 =new TCanvas;
  C2->SetLogx();
  C2->SetLogy();
  grCalcSigmaJPsiPion->Draw("APL");
  

  TCanvas *C3 =new TCanvas;
  C3->SetLogx();
  C3->SetLogy();
  grSigmaJPsiPion->Draw("APL");
  grCalcSigmaJPsiPion->Draw("Lsame");




  Double_t RootSMin = 4.0;
  Double_t RootSMax = 300.0;
  Double_t RootSStep = 1.0;
  Int_t NRootS = (RootSMax-RootSMin)/RootSStep;
  
  Double_t VarifySigmaJPsiPion[3000]={0.0};
  Double_t VarifySSJPsiPion[3000]={0.0};
  
  Double_t RootS =0;

  for(int i =0; i<NRootS; i++)
    {
      RootS = RootSMin + i*RootSStep;
      VarifySSJPsiPion[i]=RootS;
      VarifySigmaJPsiPion[i]=grCalcSigmaJPsiPion->Eval(VarifySSJPsiPion[i]);
    }


  TGraph *grVarifySigmaJPsiPion = new TGraph(NRootS, VarifySSJPsiPion, VarifySigmaJPsiPion);
  
  grVarifySigmaJPsiPion->SetName("grVarifySigmaJPsiPion");
  grVarifySigmaJPsiPion->SetTitle("grVarifySigmaJPsiPion");
  grVarifySigmaJPsiPion->SetLineWidth(2);
  grVarifySigmaJPsiPion->SetLineColor(4);
  grVarifySigmaJPsiPion->SetMarkerColor(1);
  grVarifySigmaJPsiPion->GetXaxis()->SetTitle("s^{1/2} (GeV)");
  grVarifySigmaJPsiPion->GetYaxis()->SetTitle("#sigma_{J/#psi #pi} (mb) ");


  new TCanvas;
  gPad->SetLogx();
  gPad->SetLogy();
  gPad->SetGridx();
  gPad->SetGridy();
  gPad->SetTicks();
  grCalcSigmaJPsiPion->Draw("APL");
  grVarifySigmaJPsiPion->Draw("Lsame");



  return;
























Int_t NNY1S = 39;

 Double_t SSY1S[100]={10.68, 10.56, 10.62, 10.62, 10.75, 10.81, 10.88, 11.01, 11.08, 11.41, 11.69, 12.34, 12.95, 13.76, 14.78, 16.28, 17.71, 20.09, 21.99, 24.65, 27.97, 31.36, 35.58, 40.13, 42.88, 48.36, 54.21, 61.89, 68.96, 78.72, 89.32, 100.74, 115.00, 128.92, 147.16, 164.98, 187.19, 214.97, 242.45};

 Double_t SigmaY1SPion[100]={0.01, 0.01, 0.02, 0.02, 0.02, 0.03, 0.04, 0.05, 0.05, 0.07, 0.08, 0.10, 0.12, 0.14, 0.16, 0.19, 0.22, 0.25, 0.28, 0.31, 0.34, 0.37, 0.40, 0.43, 0.45, 0.48, 0.51, 0.56, 0.60, 0.62, 0.67, 0.71, 0.74, 0.79, 0.85, 0.86, 0.91, 0.97, 1.02};
  


  TGraph *grSigmaY1SPion = new TGraph(NNY1S, SSY1S, SigmaY1SPion);
  grSigmaY1SPion->SetName("grSigmaY1SPion");
  grSigmaY1SPion->SetTitle("grSigmaY1SPion");
  grSigmaY1SPion->SetLineWidth(2);
  grSigmaY1SPion->SetLineColor(4);
  grSigmaY1SPion->SetMarkerColor(4);
  grSigmaY1SPion->GetXaxis()->SetTitle("s^{1/2} (GeV)");
  grSigmaY1SPion->GetYaxis()->SetTitle("#sigma_{#varUpsilon(1S) #pi} (mb) ");
  


  TCanvas *C4 =new TCanvas;
  C4->SetLogx();
  C4->SetLogy();
  grSigmaY1SPion->Draw("APL");


  new TCanvas;
  gPad->SetLogx();
  gPad->SetLogy();
  gPad->SetGridx();
  gPad->SetGridy();
  gPad->SetTicks();
  grSigmaY1SPion->Draw("APL");
  grCalcSigmaJPsiPion->Draw("Lsame");


  TFile *OutFile = new TFile("OutQuarkoniaPionCross.root","Recreate");
  grSigmaJPsiPion->Write();
  grSigmaY1SPion->Write();
  grCalcSigmaJPsiPion->Write();
  OutFile->Write();
  OutFile->Close();
}



Double_t SigmaDQuPion_ss(Double_t ss)
{
  Double_t Lambda = (ss - mJpsi*mJpsi - mPion*mPion) /(2.0*mJpsi); 
    
  Double_t Func =0.0;
  
  if(Lambda > ep0) Func=SigmaDQuPion(Lambda);
  
  //cout<<" Func: "<<Func<<endl;
  return Func;

  

}

Double_t SigmaDQuPion(Double_t Lambda)
{

  Double_t LambdaPlus = 0.5 * ( TMath::Sqrt(Lambda*Lambda - mPion*mPion) + Lambda);
  Double_t Constt = (LambdaPlus*LambdaPlus) / (Lambda*Lambda - mPion*mPion);
  
  //Double_t Sigma = 0.0;
 
  Double_t xmin= 0.00001;
  Double_t xmax=1.0;
 
  Double_t xstep=0.00001;
  
  int NN_x= (int)((xmax-xmin)/xstep);
  
  Double_t sum=0;
  
  for(int i=1;i<=NN_x;i++) 
    {
      Double_t x = xmin+i*xstep;
      sum = sum + SigmaDQuPionFunc(Lambda,x);
      
      //cout<<" sum "<<sum<<endl;

    }
  
 
  return Constt*sum*xstep;
}





Double_t SigmaDQuPionFunc(Double_t Lambda, Double_t x)
{
  Double_t LambdaPlus = 0.5 * ( TMath::Sqrt(Lambda*Lambda - mPion*mPion) + Lambda);
 
  Double_t Omega = x*LambdaPlus;
 
  Double_t Func =0.0;
  Double_t Scale =ep02;

  Func = SigmaDMod(Omega)*(GluonDiss_GMV(Scale,x)/x);
 
  //Func = SigmaDMod(Omega)*(PartonDissFunction(0,Scale,x)/x);

  return Func; 
}




Double_t SigmaDMod(Double_t w)
{
  Double_t SigmaDw = 0.0;

  if( (QQbarVar == 1 || QQbarVar == 4)  && w > ep0 ) { SigmaDw = epConMod*pow( (w/ep0-1.0), 1.5)/pow(w/ep0,5.0);}  
 
  if( (QQbarVar == 2 || QQbarVar == 5) && w > ep0 ) {SigmaDw = epConMod*pow( (w/ep0 - 1.0), 1.5) * pow( (w/ep0 - 3.0), 2.0)  /pow((w/ep0),7.0);}  

  return SigmaDw;
}



Double_t GluonDiss_GMV(Double_t Q2, Double_t x)
{


  Double_t MuLOSq = 0.25; 

  Double_t SNum = TMath::Log(Q2/(0.232*0.232));
 
  Double_t SDeno = TMath::Log(MuLOSq/(0.232*0.232));
 

 Double_t s =TMath::Log(SNum/SDeno);


 Double_t s1 = TMath::Log(TMath::Log(Q2/(0.232*0.232))/TMath::Log(MuLOSq/(0.232*0.232)));

 //cout<<"s "<<s<<"  "<<s1<<endl;

Double_t alpha = 0.599;

Double_t beta = 1.263;


Double_t a = 0.341*TMath::Sqrt(s) + 0.482;
Double_t b =0.0;


Double_t A  = 0.678 + 0.877*s - 0.175*s*s;
Double_t B = 0.338 - 1.579*s;
Double_t C = 0.406*s*s-0.233*s;
Double_t D = 0.390 + 1.053*s;
Double_t E = 0.618 + 2.070*s;
Double_t EPrime = 3.676;


  Double_t xGx1 = TMath::Power((1.0-x),D)*TMath::Power(x,a)*(A + B*TMath::Sqrt(x)+C*x)*TMath::Power(TMath::Log(1.0/x),b);
  

  Double_t xGx2 = TMath::Power( (1.0-x),D)*TMath::Power(s,alpha)*TMath::Exp(-E + TMath::Sqrt(EPrime*TMath::Power(s,beta)*TMath::Log(1.0/x)));
  Double_t xGx = xGx1 + xGx2;
  
  return xGx;   

}



/*
Double_t PartonDissFunction(Int_t nf, Double_t Q2, Double_t x)
{
  
  //0 is for gluon

  double  Q=TMath::Sqrt(Q2);
  double F = 0.0;
  if ( ( x > 0.00000001 && x < 1.0 ) && (Q<100000 && Q > 0.3) ) F =  LHAPDF::xfx(x, Q, nf);  
  
  //F=F/x;  
  
  return F;
  
}
*/

Double_t IntALICEPara(Double_t EtaMin, Double_t EtaMax, Double_t EtaStep)
{
  Int_t NEta = (EtaMax - EtaMin)/EtaStep;
  
  Double_t Sum =0.0;
  Double_t Eta =0.0;
  
  for(int i=0;i<=NEta;i++)
    {
      Eta = EtaMin + i*EtaStep;
      Sum = Sum +ALICEPara(Eta); 
    }
  
  return Sum*EtaStep;
  
}



Double_t ALICEPara(Double_t Eta)
{
  Double_t Eta2 = Eta*Eta;
  Double_t A1 = 2102.0;
  Double_t Sigma1 = 3.7;

  Double_t A2 = 485.0;
  Double_t Sigma2 = 1.2;

  Double_t Func =0;

  Double_t Func1 = A1*TMath::Exp(-(Eta2/(2.0*Sigma1*Sigma1)));
  Double_t Func2 = A2*TMath::Exp(-(Eta2/(2.0*Sigma2*Sigma2)));


  Func = Func1-Func2;

  //Double_t Norm = 1.0/(TMath::Sqrt(2.0*pi)*4.0);
  //Double_t Func3 = TMath::Exp(-(Eta2/(2.0*4.0*4.0)));


  return Func;



}
