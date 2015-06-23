//======================== Plot Ramona Mat from 16.04.2015 ==================//
//========================Input dat file is prashant_psi_ups_new.dat ========//
//===========================================================================//
#ifndef __CINT__
#endif
#include "TLatex.h"
#include "TCanvas.h"
#include "TROOT.h"
#include "TAxis.h"
#include "TH1.h"
#include "TTree.h"
#include "TFile.h"
#include "TH1D.h"
#include "TF1.h"
#include "TH1I.h"
#include "TCanvas.h"
#include "TLine.h"
#include "TMath.h"
#include "TVector3.h"
#include "TString.h"
#include "TLegend.h"
#include "TStyle.h"
#include "TGraphErrors.h"
#include <fstream>
#include <map>
#include <string>
#include <iostream>
#include <stdio.h>
#include <string.h>
#include "TObjArray.h"
#include "TGaxis.h"
#include "TLine.h"
#include "TColor.h"
#include "TStyle.h"
#include <iostream>
#include <iomanip>
#include "TGraphAsymmErrors.h"

Double_t IntX( Double_t xMin, Double_t xMax, TGraph *grX);
Double_t NQQ(Double_t Sigma);
void PlotRamonaMat()
{
//==================================//
  gROOT->SetStyle("Plain");
  gStyle->SetPalette(1);
  gStyle->SetOptTitle(0);
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
  gStyle->SetPadLeftMargin(0.12);
  //gStyle->SetTitleXOffset(1.15);
  //gStyle->SetTitleYOffset(1.2);
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

  
  TLatex *tb = new TLatex();
  tb->SetNDC(); 
  tb->SetTextAlign(12);
  tb->SetTextColor(1);
  tb->SetTextSize(0.040);
  //tb->DrawLatex(0.46,0.82,"g+J/#psi #rightarrow c+#bar{c}");



  TFile *OutFile =new TFile("RamonaMat.root","Recreate");
  OutFile->cd();

  //======================== JPsi Rapidity Distributions =======================//
  Int_t NNJPsiRap = 28;
  
  Double_t JPsiRap[28]={-6.75, -6.25, -5.75, -5.25, -4.75, -4.25, -3.75, -3.25, -2.75, -2.25, -1.75, 
			-1.25, -0.75, -0.25, 0.25, 0.75, 1.25, 1.75, 2.25, 2.75, 3.25, 3.75, 4.25, 
			4.75, 5.25, 5.75, 6.25, 6.75};
  


  

  //return;
  //all cross sections in mub, do not include lepton pair branching ratios,
  // y     dsig(pp)/dy  dsig(AA-mid)/dy  dsig(AA-up)/dy   dsig(AA-dn)/dy
  
  Double_t JPsiDSigmaPPDy[28]={0.00351657, 0.07321087, 0.22995148, 0.48780058, 0.82550868, 1.24560450, 1.65917455, 
			   2.00422413, 2.24567726, 2.40433481, 2.55198013, 2.60337050, 2.64293292, 2.64945868, 
			   2.64945868, 2.64293292, 2.60337050, 2.55157227, 2.40433481, 2.24567726, 2.00422413, 
			   1.65917455, 1.24560450, 0.82550868, 0.48780058, 0.22991069, 0.07321087, 0.00351657};


  Double_t JPsiDSigmaAACDy[28]={0.00256503, 0.04674076, 0.18210950, 0.40908360, 0.73863449, 1.16362463, 1.50581919, 
			    1.68323830, 1.75175878, 1.81089848, 1.85535522, 1.87615608, 1.89695695, 1.91327135, 
			    1.91327135, 1.89695695, 1.87615608, 1.85535522, 1.81089848, 1.75175878, 1.68323830, 
			    1.50581919, 1.16362463, 0.73863449, 0.40908360, 0.18210950, 0.04674076, 0.00256503};


  Double_t JPsiDSigmaAAUDy[28]={0.00289050, 0.06349835, 0.20721046, 0.45547039, 0.83312871, 1.26670918, 1.65379708, 
			    1.92474171, 2.11610084, 2.21279026, 2.34674158, 2.39125713, 2.45001543, 2.39787788, 
			    2.39787788, 2.45001543, 2.39136353, 2.34674158, 2.21279026, 2.11610084, 1.92474171, 
			    1.65379708, 1.26667125, 0.83318591, 0.45540400, 0.20722258, 0.06349651, 0.00289050};



  Double_t JPsiDSigmaAALDy[28]={0.00142714, 0.03393077, 0.14982429, 0.37323625, 0.69553042, 1.05189481, 1.29957506, 
			    1.37927667, 1.42067365, 1.37696245, 1.38881560, 1.40527555, 1.44497590, 1.39051587, 
			    1.39051587, 1.44497590, 1.40527555, 1.38891295, 1.37696245, 1.42067365, 1.37920526, 
			    1.29957506, 1.05201770, 0.69553042, 0.37322973, 0.14981912, 0.03393077, 0.00142708};
  



  TH1D *histJPsiDSigmaPPDy = new TH1D("histJPsiDSigmaPPDy","histJPsiDSigmaPPDy",28,-7.0,7.0);

 
  for(int i=1;i<=histJPsiDSigmaPPDy->GetNbinsX();i++)
    {
      
      histJPsiDSigmaPPDy->SetBinContent(i,JPsiDSigmaPPDy[i-1]);
      cout<<histJPsiDSigmaPPDy->GetBinCenter(i)<<"            "<< histJPsiDSigmaPPDy->GetBinContent(i)<<endl;
      
    }

  


  //return;
  //for(int i = 0;i< NNJPsiRap;i++)
  //{
  //  cout<<i<<"  "<<JPsiRap[i] <<"  "<<JPsiRap[i+1] <<"  "<<"Bin: "<<0.5*(JPsiRap[i] + JPsiRap[i+1])<<endl;
  //    }


  TGraph *grJPsiDSigmaPPDy = new TGraph(NNJPsiRap, JPsiRap, JPsiDSigmaPPDy);
  grJPsiDSigmaPPDy->SetName("grJPsiDSigmaPPDy");
  grJPsiDSigmaPPDy->SetTitle("grJPsiDSigmaPPDy");
  grJPsiDSigmaPPDy->SetLineWidth(2);
  grJPsiDSigmaPPDy->SetLineColor(2);
  grJPsiDSigmaPPDy->GetYaxis()->SetTitleOffset(1.5);
  grJPsiDSigmaPPDy->GetYaxis()->SetRangeUser(0.0,3.0);
  grJPsiDSigmaPPDy->GetXaxis()->SetTitle("y^{J/#Psi}");
  grJPsiDSigmaPPDy->GetYaxis()->SetTitle("#frac{d#sigma^{pp}}{dy}(#mu b)");
  
  new TCanvas;
  gPad->SetLeftMargin(0.18);
  gPad->SetTicks();
  grJPsiDSigmaPPDy->Draw("AL");

  gPad->SaveAs("Plots/JPsiDSigmaPPDy.png");
  gPad->SaveAs("Plots/JPsiDSigmaPPDy.pdf");
  gPad->SaveAs("Plots/JPsiDSigmaPPDy.eps");

  Double_t RapBinWidth = 0.5;
 
   

  TGraph *grJPsiDSigmaAACDy = new TGraph(NNJPsiRap, JPsiRap, JPsiDSigmaAACDy);
  grJPsiDSigmaAACDy->SetName("grJPsiDSigmaAACDy");
  grJPsiDSigmaAACDy->SetTitle("grJPsiDSigmaAACDy");
  grJPsiDSigmaAACDy->SetLineWidth(2);
  grJPsiDSigmaAACDy->SetLineColor(2);
  grJPsiDSigmaAACDy->GetYaxis()->SetTitleOffset(1.5);
  grJPsiDSigmaAACDy->GetYaxis()->SetRangeUser(0.0,3.0);
  grJPsiDSigmaAACDy->GetXaxis()->SetTitle("y^{J/#Psi}");
  grJPsiDSigmaAACDy->GetYaxis()->SetTitle("#frac{d#sigma^{AA}}{dy}(#mu b)");
  

  TGraph *grJPsiDSigmaAAUDy = new TGraph(NNJPsiRap, JPsiRap, JPsiDSigmaAAUDy);
  grJPsiDSigmaAAUDy->SetName("grJPsiDSigmaAAUDy");
  grJPsiDSigmaAAUDy->SetTitle("grJPsiDSigmaAAUDy");
  grJPsiDSigmaAAUDy->SetLineWidth(2);
  grJPsiDSigmaAAUDy->SetLineColor(1);
  grJPsiDSigmaAAUDy->GetYaxis()->SetTitleOffset(1.5);
  grJPsiDSigmaAAUDy->GetYaxis()->SetRangeUser(0.0,3.0);
  grJPsiDSigmaAAUDy->GetXaxis()->SetTitle("y^{J/#Psi}");
  grJPsiDSigmaAAUDy->GetYaxis()->SetTitle("#frac{d#sigma^{AA}}{dy}(#mu b)");


  TGraph *grJPsiDSigmaAALDy = new TGraph(NNJPsiRap, JPsiRap, JPsiDSigmaAALDy);
  grJPsiDSigmaAALDy->SetName("grJPsiDSigmaAALDy");
  grJPsiDSigmaAALDy->SetTitle("grJPsiDSigmaAALDy");
  grJPsiDSigmaAALDy->SetLineWidth(2);
  grJPsiDSigmaAALDy->SetLineColor(1);
  grJPsiDSigmaAALDy->GetYaxis()->SetTitleOffset(1.5);
  grJPsiDSigmaAALDy->GetYaxis()->SetRangeUser(0.0,3.0);
  grJPsiDSigmaAALDy->GetXaxis()->SetTitle("y^{J/#Psi}");
  grJPsiDSigmaAALDy->GetYaxis()->SetTitle("#frac{d#sigma^{AA}}{dy}(#mu b)");



  new TCanvas;
  gPad->SetLeftMargin(0.18);
  gPad->SetTicks();
  grJPsiDSigmaAACDy->Draw("AL");
  grJPsiDSigmaAAUDy->Draw("Csame");
  grJPsiDSigmaAALDy->Draw("Csame");
  gPad->SaveAs("Plots/JPsiDSigmaAADy.png");
  gPad->SaveAs("Plots/JPsiDSigmaAADy.pdf");
  gPad->SaveAs("Plots/JPsiDSigmaAADy.eps");

  /*
  cout<<"Hist Integral "<<histJPsiDSigmaPPDy->Integral()*histJPsiDSigmaPPDy->GetBinWidth(0)<<endl;
  cout<<" pp Jpsi cross section y [-6.5,6.5]: "<<IntX(-6.75,6.75,grJPsiDSigmaPPDy)<<" mub "<<histJPsiDSigmaPPDy->Integral()*histJPsiDSigmaPPDy->GetBinWidth(0)<<endl;
  cout<<" pp Jpsi cross section y [-1.0,1.0]: "<<IntX(-0.75,0.75,grJPsiDSigmaPPDy)<<"   mub "<<
    histJPsiDSigmaPPDy->Integral(histJPsiDSigmaPPDy->FindBin(-0.75),histJPsiDSigmaPPDy->FindBin(0.75))*histJPsiDSigmaPPDy->GetBinWidth(0)<<endl;
  cout<<" pp Jpsi cross section y [2.5,4.0]:  "<<IntX(2.75,3.75,grJPsiDSigmaPPDy)<<"    mub "<<
    histJPsiDSigmaPPDy->Integral(histJPsiDSigmaPPDy->FindBin(2.75),histJPsiDSigmaPPDy->FindBin(3.75))*histJPsiDSigmaPPDy->GetBinWidth(0)<<endl;
  cout<<" pp Jpsi cross section y [-2.4,2.4]: "<<IntX(-2.25,2.25,grJPsiDSigmaPPDy)<<"   mub "<<
    histJPsiDSigmaPPDy->Integral(histJPsiDSigmaPPDy->FindBin(-2.25),histJPsiDSigmaPPDy->FindBin(2.25))*histJPsiDSigmaPPDy->GetBinWidth(0)<<endl;
  
  cout<<" AA Jpsi cross section y [-6.5,6.5]: "<<IntX(-6.75,6.75,grJPsiDSigmaAACDy)<<" mub "<<" Shadowing Factor "<<IntX(-6.75,6.75,grJPsiDSigmaAACDy)/IntX(-6.75,6.75,grJPsiDSigmaPPDy)<<endl;
  cout<<" AA Jpsi cross section y [-1.0,1.0]: "<<IntX(-0.75,0.75,grJPsiDSigmaAACDy)<<" mub    "<<" Shadowing Factor "<<IntX(-1.0,1.0,grJPsiDSigmaAACDy)/IntX(-1.0,1.0,grJPsiDSigmaPPDy)<<endl;
  cout<<" AA Jpsi cross section y [2.5,4.0]: "<<IntX(2.75,3.75,grJPsiDSigmaAACDy)<<" mub    "<<" Shadowing Factor "<<IntX(2.5,4.0,grJPsiDSigmaAACDy)/IntX(2.5,4.0,grJPsiDSigmaPPDy)<<endl;
  cout<<" AA Jpsi cross section y [-2.4,2.4]: "<<IntX(-2.25,2.25,grJPsiDSigmaAACDy)<<" mub   "<<" Shadowing Factor "<<IntX(-2.4,2.4,grJPsiDSigmaAACDy)/IntX(-2.4,2.4,grJPsiDSigmaPPDy)<<endl;
  */
 


  cout<<" pp Jpsi cross section y [-6.5,6.5]: "<<IntX(-6.75,6.75,grJPsiDSigmaPPDy)<<" mub "<<endl;




  cout<<" pp Jpsi cross section y [-1.0,1.0]: "<<IntX(-0.75,0.75,grJPsiDSigmaPPDy)<<"   mub "<<endl;
  cout<<" pp Jpsi cross section y [2.5,4.0]:  "<<IntX(2.75,3.75,grJPsiDSigmaPPDy)<<"    mub "<<endl;
  cout<<" pp Jpsi cross section y [-2.4,2.4]: "<<IntX(-2.25,2.25,grJPsiDSigmaPPDy)<<"   mub "<<endl;
  


  cout<<" AA Jpsi cross section y [-6.5,6.5]: "<<IntX(-6.75,6.75,grJPsiDSigmaAACDy)<<" mub "<<" Shadowing Factor "<<IntX(-6.75,6.75,grJPsiDSigmaAACDy)/IntX(-6.75,6.75,grJPsiDSigmaPPDy)<<endl;
  


  cout<<" AA Jpsi cross section y [-1.0,1.0]: L "<<IntX(-0.75,0.75,grJPsiDSigmaAALDy)<<" mub    "<<" Shadowing Factor "<<IntX(-0.75,0.75,grJPsiDSigmaAALDy)/IntX(-0.75,0.75,grJPsiDSigmaPPDy)<<endl;
  cout<<" AA Jpsi cross section y [-1.0,1.0]: C "<<IntX(-0.75,0.75,grJPsiDSigmaAACDy)<<" mub    "<<" Shadowing Factor "<<IntX(-0.75,0.75,grJPsiDSigmaAACDy)/IntX(-0.75,0.75,grJPsiDSigmaPPDy)<<endl;
  cout<<" AA Jpsi cross section y [-1.0,1.0]: U "<<IntX(-0.75,0.75,grJPsiDSigmaAAUDy)<<" mub    "<<" Shadowing Factor "<<IntX(-0.75,0.75,grJPsiDSigmaAAUDy)/IntX(-0.75,0.75,grJPsiDSigmaPPDy)<<endl<<endl;


  cout<<" AA Jpsi cross section y [2.5,4.0]: L "<<IntX(2.75,3.75,grJPsiDSigmaAALDy)<<" mub    "<<" Shadowing Factor "<<IntX(2.75,3.75,grJPsiDSigmaAALDy)/IntX(2.75,3.75,grJPsiDSigmaPPDy)<<endl;
  cout<<" AA Jpsi cross section y [2.5,4.0]: C "<<IntX(2.75,3.75,grJPsiDSigmaAACDy)<<" mub    "<<" Shadowing Factor "<<IntX(2.75,3.75,grJPsiDSigmaAACDy)/IntX(2.75,3.75,grJPsiDSigmaPPDy)<<endl;
  cout<<" AA Jpsi cross section y [2.5,4.0]: U "<<IntX(2.75,3.75,grJPsiDSigmaAAUDy)<<" mub    "<<" Shadowing Factor "<<IntX(2.75,3.75,grJPsiDSigmaAAUDy)/IntX(2.75,3.75,grJPsiDSigmaPPDy)<<endl<<endl;




  cout<<" AA Jpsi cross section y [-2.4,2.4]: L "<<IntX(-2.25,2.25,grJPsiDSigmaAALDy)<<" mub   "<<" Shadowing Factor "<<IntX(-2.25,2.25,grJPsiDSigmaAALDy)/IntX(-2.25,2.25,grJPsiDSigmaPPDy)<<endl;
  cout<<" AA Jpsi cross section y [-2.4,2.4]: C "<<IntX(-2.25,2.25,grJPsiDSigmaAACDy)<<" mub   "<<" Shadowing Factor "<<IntX(-2.25,2.25,grJPsiDSigmaAACDy)/IntX(-2.25,2.25,grJPsiDSigmaPPDy)<<endl;
  cout<<" AA Jpsi cross section y [-2.4,2.4]: U "<<IntX(-2.25,2.25,grJPsiDSigmaAAUDy)<<" mub   "<<" Shadowing Factor "<<IntX(-2.25,2.25,grJPsiDSigmaAAUDy)/IntX(-2.25,2.25,grJPsiDSigmaPPDy)<<endl<<endl;
 






  cout<<" NJpsi y = [-6.5,6.5]: "<< NQQ(IntX(-6.75,6.75,grJPsiDSigmaAACDy))<<endl;
  cout<<" NJpsi y = [-1.0,1.0]: "<< NQQ(IntX(-0.75,0.75,grJPsiDSigmaAACDy))<<endl;
  cout<<" NJpsi y = [2.5,4.0]:  "<< NQQ(IntX(2.75,3.75,grJPsiDSigmaAACDy))<<endl;
  cout<<" NJpsi y = [-2.4,2.4]: "<< NQQ(IntX(-2.25,2.25,grJPsiDSigmaAACDy))<<endl;


  //return;

  //======================== JPsi Pt Distributions =======================//
  //p_T distributions need to be adjusted for rapidity bin width if you
  //use those direct
  //p_T    dsig(pp)/dp_T  dsig(AA-mid)/dp_T  dsig(AA-up)/dp_T   dsig(AA-dn)/dp_T
  
  Int_t JpsiNNPt_Y1 = 49;
  
  Double_t JpsiPt_Y1[100]={0.0};
  
  Double_t PPJpsiCrossSectionVsPt_Y1[100]={0.0};

  Double_t JpsiCrossSectionVsPt_Y1[100]={0.0};
  Double_t JpsiCrossSectionVsPt_Y1U[100]={0.0};
  Double_t JpsiCrossSectionVsPt_Y1L[100]={0.0};
  
  ifstream filein2("InTextFiles/TempFiles/Temp_JPsiCrossSectionVsPtInRap1.txt");
  for(int i=0; i<JpsiNNPt_Y1; i++) 
    {
      filein2 >> JpsiPt_Y1[i] >> PPJpsiCrossSectionVsPt_Y1[i] >> JpsiCrossSectionVsPt_Y1[i] >> JpsiCrossSectionVsPt_Y1U[i] >> JpsiCrossSectionVsPt_Y1L[i]; 
      
      //cout<< JpsiPt_Y1[i] <<"  "<< JpsiCrossSectionVsPt_Y1[i] <<"  "<< JpsiCrossSectionVsPt_Y1U[i] <<"  "<< JpsiCrossSectionVsPt_Y1L[i]<<endl; 
      
    }
  
  TGraph *grPPJpsiCrossSectionVsPt_Y1 = new TGraph(JpsiNNPt_Y1, JpsiPt_Y1, PPJpsiCrossSectionVsPt_Y1);
  grPPJpsiCrossSectionVsPt_Y1->SetName("grPPJpsiCrossSectionVsPt_Y1");
  grPPJpsiCrossSectionVsPt_Y1->SetTitle("grPPJpsiCrossSectionVsPt_Y1");
  grPPJpsiCrossSectionVsPt_Y1->SetLineWidth(2);
  grPPJpsiCrossSectionVsPt_Y1->SetLineColor(2);
  grPPJpsiCrossSectionVsPt_Y1->GetYaxis()->SetRangeUser(0.0,1.5);
  grPPJpsiCrossSectionVsPt_Y1->GetXaxis()->SetTitle("p_{T}^{J/#psi}(GeV/c)");
  grPPJpsiCrossSectionVsPt_Y1->GetYaxis()->SetTitle("#frac{d#sigma^{PP}}{dp_{T}}(#mu b)");
  grPPJpsiCrossSectionVsPt_Y1->GetYaxis()->SetTitleOffset(1.4);
  grPPJpsiCrossSectionVsPt_Y1->GetYaxis()->SetRangeUser(0.000001,10.0);


  TGraph *grJpsiCrossSectionVsPt_Y1 = new TGraph(JpsiNNPt_Y1, JpsiPt_Y1, JpsiCrossSectionVsPt_Y1);
  grJpsiCrossSectionVsPt_Y1->SetName("grJpsiCrossSectionVsPt_Y1");
  grJpsiCrossSectionVsPt_Y1->SetTitle("grJpsiCrossSectionVsPt_Y1");
  grJpsiCrossSectionVsPt_Y1->SetLineWidth(2);
  grJpsiCrossSectionVsPt_Y1->SetLineColor(2);
  grJpsiCrossSectionVsPt_Y1->GetYaxis()->SetRangeUser(0.0,1.5);
  grJpsiCrossSectionVsPt_Y1->GetXaxis()->SetTitle("p_{T}^{J/#psi}(GeV/c)");
  grJpsiCrossSectionVsPt_Y1->GetYaxis()->SetTitle("#frac{d#sigma^{AA}}{dp_{T}}(#mu b)");
  grJpsiCrossSectionVsPt_Y1->GetYaxis()->SetTitleOffset(1.4);
  grJpsiCrossSectionVsPt_Y1->GetYaxis()->SetRangeUser(0.000001,10.0);

  TGraph *grJpsiCrossSectionUVsPt_Y1 = new TGraph(JpsiNNPt_Y1, JpsiPt_Y1, JpsiCrossSectionVsPt_Y1U);
  grJpsiCrossSectionUVsPt_Y1->SetName("grJpsiCrossSectionUVsPt_Y1");
  TGraph *grJpsiCrossSectionLVsPt_Y1 = new TGraph(JpsiNNPt_Y1, JpsiPt_Y1, JpsiCrossSectionVsPt_Y1L);
  grJpsiCrossSectionLVsPt_Y1->SetName("grJpsiCrossSectionLVsPt_Y1");


  new TCanvas;
  gPad->SetTicks();
  gPad->SetLogy(1);
  gPad->SetLeftMargin(0.18);
  grPPJpsiCrossSectionVsPt_Y1->Draw("ALP");
  tb->DrawLatex(0.27,0.20,"|y| #leq 1");

  gPad->SaveAs("Plots/JpsiCrossSectionAAVsPt_Y1.png");
  gPad->SaveAs("Plots/JpsiCrossSectionAAVsPt_Y1.pdf");
  gPad->SaveAs("Plots/JpsiCrossSectionAAVsPt_Y1.eps");

  
  new TCanvas;
  gPad->SetTicks();
  gPad->SetLogy(1);
  gPad->SetLeftMargin(0.18);
  grJpsiCrossSectionVsPt_Y1->Draw("AC");
  grJpsiCrossSectionUVsPt_Y1->Draw("Csame");
  grJpsiCrossSectionLVsPt_Y1->Draw("Csame");
  tb->DrawLatex(0.27,0.20,"|y| #leq 1");

  gPad->SaveAs("Plots/JpsiCrossSectionPPVsPt_Y1.png");
  gPad->SaveAs("Plots/JpsiCrossSectionPPVsPt_Y1.pdf");
  gPad->SaveAs("Plots/JpsiCrossSectionPPVsPt_Y1.eps");

  
  //cout<<" pp Jpsi cross section pT [1.5, 49.5] GeV/c, y [-1.0,1.0]: "<<IntX(1.5,49.5,grPPJpsiCrossSectionVsPt_Y1)<<" mub"<<endl;
  //cout<<" AA Jpsi cross section pT [1.5, 49.5] GeV/c, y [-1.0,1.0]: "<<IntX(1.5,49.5,grJpsiCrossSectionVsPt_Y1)<<" mub "<<" Shadowing Factor "<<
  //IntX(1.5,49.5,grJpsiCrossSectionVsPt_Y1)/IntX(1.5,49.5,grPPJpsiCrossSectionVsPt_Y1)<<endl;


  /*
  //======================= Making histograms to smooth it ===================================//
  
  TH1D *HistJpsiCrossSectionVsPt_Y1 = new TH1D("HistJpsiCrossSectionVsPt_Y1","HistJpsiCrossSectionVsPt_Y1",49,1.0,50.0);
  TH1D *HistJpsiCrossSectionUVsPt_Y1 = new TH1D("HistJpsiCrossSectionUVsPt_Y1","HistJpsiCrossSectionUVsPt_Y1",49,1.0,50.0);
  TH1D *HistJpsiCrossSectionLVsPt_Y1 = new TH1D("HistJpsiCrossSectionLVsPt_Y1","HistJpsiCrossSectionLVsPt_Y1",49,1.0,50.0);
  
  for(int i=1;i<=HistJpsiCrossSectionVsPt_Y1->GetNbinsX();i++)
    {
      HistJpsiCrossSectionVsPt_Y1->SetBinContent(i,JpsiCrossSectionVsPt_Y1[i-1]);
      HistJpsiCrossSectionUVsPt_Y1->SetBinContent(i,JpsiCrossSectionVsPt_Y1U[i-1]);
      HistJpsiCrossSectionLVsPt_Y1->SetBinContent(i,JpsiCrossSectionVsPt_Y1L[i-1]);
      }
  
  for(int i=1;i<=HistJpsiCrossSectionVsPt_Y1->GetNbinsX();i++)
    {
      cout<<HistJpsiCrossSectionVsPt_Y1->GetBinCenter(i)<<"            "<< HistJpsiCrossSectionVsPt_Y1->GetBinContent(i)<<endl;
    }
  
  
  HistJpsiCrossSectionVsPt_Y1->SetTitle("HistJpsiCrossSectionVsPt_Y1");
  HistJpsiCrossSectionVsPt_Y1->SetName("HistJpsiCrossSectionVsPt_Y1");
  HistJpsiCrossSectionVsPt_Y1->GetXaxis()->SetTitle("p_{T}^{J/#psi}(GeV/c)");
  HistJpsiCrossSectionVsPt_Y1->GetYaxis()->SetTitle("#frac{d#sigma^{AA}}{dp_{T}}(#mu b)");
  
  HistJpsiCrossSectionVsPt_Y1->GetYaxis()->SetTitleOffset(1.4);
  HistJpsiCrossSectionVsPt_Y1->GetYaxis()->SetRangeUser(0.000001,10.0);



  HistJpsiCrossSectionUVsPt_Y1->SetTitle("HistJpsiCrossSectionUVsPt_Y1");
  HistJpsiCrossSectionUVsPt_Y1->SetName("HistJpsiCrossSectionUVsPt_Y1");
  HistJpsiCrossSectionUVsPt_Y1->GetXaxis()->SetTitle("p_{T}^{J/#psi}");
  HistJpsiCrossSectionUVsPt_Y1->GetYaxis()->SetTitle("#frac{d#sigma^{AA}}{dp_{T}}(#mu b)");
  
  HistJpsiCrossSectionLVsPt_Y1->SetTitle("HistJpsiCrossSectionLVsPt_Y1");
  HistJpsiCrossSectionLVsPt_Y1->SetName("HistJpsiCrossSectionLVsPt_Y1");
  HistJpsiCrossSectionLVsPt_Y1->GetXaxis()->SetTitle("p_{T}^{J/#psi}");
  HistJpsiCrossSectionLVsPt_Y1->GetYaxis()->SetTitle("#frac{d#sigma^{AA}}{dp_{T}}(#mu b)");

  //HistJpsiCrossSectionVsPt_Y1->Rebin(2);
  //HistJpsiCrossSectionUVsPt_Y1->Rebin(2);
  //HistJpsiCrossSectionLVsPt_Y1->Rebin(2);

  //HistJpsiCrossSectionVsPt_Y1->Scale(1.0/2.0);
  //HistJpsiCrossSectionUVsPt_Y1->Scale(1.0/2.0);
  //HistJpsiCrossSectionLVsPt_Y1->Scale(1.0/2.0);
  
  //HistJpsiCrossSectionVsPt_Y1->Smooth(40);
  //HistJpsiCrossSectionUVsPt_Y1->Smooth(40);
  //HistJpsiCrossSectionLVsPt_Y1->Smooth(40);
  
  
  cout<<" After Rebin : "<<endl;
  cout<<"JPsi Bin Centre: "<<"        "<<"Bin Content"<<endl;
      
  for(int i=1;i<=HistJpsiCrossSectionVsPt_Y1->GetNbinsX();i++)
    {
      cout<<HistJpsiCrossSectionVsPt_Y1->GetBinCenter(i)<<"            "<< HistJpsiCrossSectionVsPt_Y1->GetBinContent(i)<<endl;
    }
  

  new TCanvas;
  gPad->SetTicks();
  gPad->SetLogy(1);
  gPad->SetLeftMargin(0.18);
  HistJpsiCrossSectionUVsPt_Y1->Draw("L");  
  HistJpsiCrossSectionVsPt_Y1->Draw("Lsame");
  HistJpsiCrossSectionLVsPt_Y1->Draw("Lsame");

  tb->DrawLatex(0.26,0.20,"|y| #leq 1");
  gPad->SaveAs("JpsiCrossSectionVsPt_Y1.pdf");
  gPad->SaveAs("JpsiCrossSectionVsPt_Y1.png");
  gPad->SaveAs("JpsiCrossSectionVsPt_Y1.eps");
*/



  Int_t JpsiNNPt_Y2440 = 49;
  
  Double_t JpsiPt_Y2440[100]={0.0};
  
  Double_t PPJpsiCrossSectionVsPt_Y2440[100]={0.0};

  Double_t JpsiCrossSectionVsPt_Y2440[100]={0.0};
  Double_t JpsiCrossSectionVsPt_Y2440U[100]={0.0};
  Double_t JpsiCrossSectionVsPt_Y2440L[100]={0.0};
  
  ifstream filein3("InTextFiles/TempFiles/Temp_JPsiCrossSectionVsPtInRap2440.txt");
  for(int i=0; i<JpsiNNPt_Y2440; i++) 
    {
      filein3 >> JpsiPt_Y2440[i] >> PPJpsiCrossSectionVsPt_Y2440[i] >> JpsiCrossSectionVsPt_Y2440[i] >> JpsiCrossSectionVsPt_Y2440U[i] >> JpsiCrossSectionVsPt_Y2440L[i]; 
      
      //cout<< JpsiPt_Y2440[i] <<"  "<< JpsiCrossSectionVsPt_Y2440[i] <<"  "<< JpsiCrossSectionVsPt_Y2440U[i] <<"  "<< JpsiCrossSectionVsPt_Y2440L[i]<<endl; 
      
    }
  

  TGraph *grPPJpsiCrossSectionVsPt_Y2440 = new TGraph(JpsiNNPt_Y2440, JpsiPt_Y2440, PPJpsiCrossSectionVsPt_Y2440);
  grPPJpsiCrossSectionVsPt_Y2440->SetName("grPPJpsiCrossSectionVsPt_Y2440");
  grPPJpsiCrossSectionVsPt_Y2440->SetTitle("grPPJpsiCrossSectionVsPt_Y2440");
  grPPJpsiCrossSectionVsPt_Y2440->SetLineWidth(2);
  grPPJpsiCrossSectionVsPt_Y2440->SetLineColor(2);
  grPPJpsiCrossSectionVsPt_Y2440->GetYaxis()->SetRangeUser(0.0,1.5);
  grPPJpsiCrossSectionVsPt_Y2440->GetXaxis()->SetTitle("p_{T}^{J/#psi}(GeV/c)");
  grPPJpsiCrossSectionVsPt_Y2440->GetYaxis()->SetTitle("#frac{d#sigma^{PP}}{dp_{T}}(#mu b)");
  grPPJpsiCrossSectionVsPt_Y2440->GetYaxis()->SetTitleOffset(1.4);
  grPPJpsiCrossSectionVsPt_Y2440->GetYaxis()->SetRangeUser(0.0000001,10.0);


 


  TGraph *grJpsiCrossSectionVsPt_Y2440 = new TGraph(JpsiNNPt_Y2440, JpsiPt_Y2440, JpsiCrossSectionVsPt_Y2440);
  grJpsiCrossSectionVsPt_Y2440->SetName("grJpsiCrossSectionVsPt_Y2440");
  grJpsiCrossSectionVsPt_Y2440->SetTitle("grJpsiCrossSectionVsPt_Y2440");
  grJpsiCrossSectionVsPt_Y2440->SetLineWidth(2);
  grJpsiCrossSectionVsPt_Y2440->SetLineColor(2);
  grJpsiCrossSectionVsPt_Y2440->GetYaxis()->SetRangeUser(0.0,1.5);
  grJpsiCrossSectionVsPt_Y2440->GetXaxis()->SetTitle("p_{T}^{J/#psi}(GeV/c)");
  grJpsiCrossSectionVsPt_Y2440->GetYaxis()->SetTitle("#frac{d#sigma^{AA}}{dp_{T}}(#mu b)");
  grJpsiCrossSectionVsPt_Y2440->GetYaxis()->SetTitleOffset(1.4);
  grJpsiCrossSectionVsPt_Y2440->GetYaxis()->SetRangeUser(0.0000001,10.0);

  TGraph *grJpsiCrossSectionUVsPt_Y2440 = new TGraph(JpsiNNPt_Y2440, JpsiPt_Y2440, JpsiCrossSectionVsPt_Y2440U);
  grJpsiCrossSectionUVsPt_Y2440->SetName("grJpsiCrossSectionUVsPt_Y2440");
  TGraph *grJpsiCrossSectionLVsPt_Y2440 = new TGraph(JpsiNNPt_Y2440, JpsiPt_Y2440, JpsiCrossSectionVsPt_Y2440L);
  grJpsiCrossSectionLVsPt_Y2440->SetName("grJpsiCrossSectionLVsPt_Y2440");


  new TCanvas;
  gPad->SetTicks();
  gPad->SetLogy(1);
  gPad->SetLeftMargin(0.18);
  grPPJpsiCrossSectionVsPt_Y2440->Draw("AC");
  tb->DrawLatex(0.27,0.20,"2.4 #leq y #leq 4");

  gPad->SaveAs("Plots/JpsiCrossSectionAAVsPt_Y2440.png");
  gPad->SaveAs("Plots/JpsiCrossSectionAAVsPt_Y2440.pdf");
  gPad->SaveAs("Plots/JpsiCrossSectionAAVsPt_Y2440.eps");


  
  new TCanvas;
  gPad->SetTicks();
  gPad->SetLogy(1);
  gPad->SetLeftMargin(0.18);
  grJpsiCrossSectionVsPt_Y2440->Draw("AC");
  grJpsiCrossSectionUVsPt_Y2440->Draw("Csame");
  grJpsiCrossSectionLVsPt_Y2440->Draw("Csame");
  tb->DrawLatex(0.27,0.20,"2.4 #leq y #leq 4");
  
  gPad->SaveAs("Plots/JpsiCrossSectionPPVsPt_Y2440.png");
  gPad->SaveAs("Plots/JpsiCrossSectionPPVsPt_Y2440.pdf");
  gPad->SaveAs("Plots/JpsiCrossSectionPPVsPt_Y2440.eps");






  Int_t JpsiNNPt_Y21 = 49;
  
  Double_t JpsiPt_Y21[100]={0.0};
  
  Double_t PPJpsiCrossSectionVsPt_Y21[100]={0.0};

  Double_t JpsiCrossSectionVsPt_Y21[100]={0.0};
  Double_t JpsiCrossSectionVsPt_Y21U[100]={0.0};
  Double_t JpsiCrossSectionVsPt_Y21L[100]={0.0};
  
  ifstream filein4("InTextFiles/TempFiles/Temp_JPsiCrossSectionVsPtInRap21.txt");
  for(int i=0; i<JpsiNNPt_Y21; i++) 
    {
      filein4 >> JpsiPt_Y21[i] >> PPJpsiCrossSectionVsPt_Y21[i] >> JpsiCrossSectionVsPt_Y21[i] >> JpsiCrossSectionVsPt_Y21U[i] >> JpsiCrossSectionVsPt_Y21L[i]; 
      
      //cout<< JpsiPt_Y21[i] <<"  "<< JpsiCrossSectionVsPt_Y21[i] <<"  "<< JpsiCrossSectionVsPt_Y21U[i] <<"  "<< JpsiCrossSectionVsPt_Y21L[i]<<endl; 
      
    }
  




  TGraph *grPPJpsiCrossSectionVsPt_Y21 = new TGraph(JpsiNNPt_Y21, JpsiPt_Y21, PPJpsiCrossSectionVsPt_Y21);
  grPPJpsiCrossSectionVsPt_Y21->SetName("grPPJpsiCrossSectionVsPt_Y21");
  grPPJpsiCrossSectionVsPt_Y21->SetTitle("grPPJpsiCrossSectionVsPt_Y21");
  grPPJpsiCrossSectionVsPt_Y21->SetLineWidth(2);
  grPPJpsiCrossSectionVsPt_Y21->SetLineColor(2);
  grPPJpsiCrossSectionVsPt_Y21->GetYaxis()->SetRangeUser(0.0,1.5);
  grPPJpsiCrossSectionVsPt_Y21->GetXaxis()->SetTitle("p_{T}^{J/#psi}(GeV/c)");
  grPPJpsiCrossSectionVsPt_Y21->GetYaxis()->SetTitle("#frac{d#sigma^{PP}}{dp_{T}}(#mu b)");
  grPPJpsiCrossSectionVsPt_Y21->GetYaxis()->SetTitleOffset(1.4);
  grPPJpsiCrossSectionVsPt_Y21->GetYaxis()->SetRangeUser(0.0000001,10.0);




  TGraph *grJpsiCrossSectionVsPt_Y21 = new TGraph(JpsiNNPt_Y21, JpsiPt_Y21, JpsiCrossSectionVsPt_Y21);
  grJpsiCrossSectionVsPt_Y21->SetName("grJpsiCrossSectionVsPt_Y21");
  grJpsiCrossSectionVsPt_Y21->SetTitle("grJpsiCrossSectionVsPt_Y21");
  grJpsiCrossSectionVsPt_Y21->SetLineWidth(2);
  grJpsiCrossSectionVsPt_Y21->SetLineColor(2);
  grJpsiCrossSectionVsPt_Y21->GetYaxis()->SetRangeUser(0.0,1.5);
  grJpsiCrossSectionVsPt_Y21->GetXaxis()->SetTitle("p_{T}^{J/#psi}(GeV/c)");
  grJpsiCrossSectionVsPt_Y21->GetYaxis()->SetTitle("#frac{d#sigma^{AA}}{dp_{T}}(#mu b)");
  grJpsiCrossSectionVsPt_Y21->GetYaxis()->SetTitleOffset(1.4);
  grJpsiCrossSectionVsPt_Y21->GetYaxis()->SetRangeUser(0.0000001,10.0);

  TGraph *grJpsiCrossSectionUVsPt_Y21 = new TGraph(JpsiNNPt_Y21, JpsiPt_Y21, JpsiCrossSectionVsPt_Y21U);
  grJpsiCrossSectionUVsPt_Y21->SetName("grJpsiCrossSectionUVsPt_Y21");
  TGraph *grJpsiCrossSectionLVsPt_Y21 = new TGraph(JpsiNNPt_Y21, JpsiPt_Y21, JpsiCrossSectionVsPt_Y21L);
  grJpsiCrossSectionLVsPt_Y21->SetName("grJpsiCrossSectionLVsPt_Y21");


  new TCanvas;
  gPad->SetTicks();
  gPad->SetLogy(1);
  gPad->SetLeftMargin(0.18);
  grPPJpsiCrossSectionVsPt_Y21->Draw("AC");
  tb->DrawLatex(0.27,0.20,"|y| #leq 2.1");

  gPad->SaveAs("Plots/JpsiCrossSectionAAVsPt_Y21.png");
  gPad->SaveAs("Plots/JpsiCrossSectionAAVsPt_Y21.pdf");
  gPad->SaveAs("Plots/JpsiCrossSectionAAVsPt_Y21.eps");


  
  new TCanvas;
  gPad->SetTicks();
  gPad->SetLogy(1);
  gPad->SetLeftMargin(0.18);
  grJpsiCrossSectionVsPt_Y21->Draw("AC");
  grJpsiCrossSectionUVsPt_Y21->Draw("Csame");
  grJpsiCrossSectionLVsPt_Y21->Draw("Csame");
  tb->DrawLatex(0.27,0.20,"|y| #leq 2.1");

  gPad->SaveAs("Plots/JpsiCrossSectionPPVsPt_Y21.png");
  gPad->SaveAs("Plots/JpsiCrossSectionPPVsPt_Y21.pdf");
  gPad->SaveAs("Plots/JpsiCrossSectionPPVsPt_Y21.eps");

  
  cout<<" pp Jpsi cross section pT [1.5, 49.5] GeV/c, y [-1.0,1.0]: "<<IntX(0.5,49.5,grPPJpsiCrossSectionVsPt_Y1)<<" mub"<<endl;
  cout<<" AA Jpsi cross section pT [1.5, 49.5] GeV/c, y [-1.0,1.0]: "<<IntX(1.5,49.5,grJpsiCrossSectionVsPt_Y1)<<" mub "<<" Shadowing Factor "<<
    IntX(1.5,49.5,grJpsiCrossSectionVsPt_Y1)/IntX(1.5,49.5,grPPJpsiCrossSectionVsPt_Y1)<<endl;
  
  cout<<" pp Jpsi cross section pT [1.5, 49.5] GeV/c, y [2.4,4.0]: "<<IntX(1.5,49.5,grPPJpsiCrossSectionVsPt_Y2440)<<" mub"<<endl;
  cout<<" AA Jpsi cross section pT [1.5, 49.5] GeV/c, y [2.4,4.0]: "<<IntX(1.5,49.5,grJpsiCrossSectionVsPt_Y2440)<<" mub "<<" Shadowing Factor "<<
    IntX(1.5,49.5,grJpsiCrossSectionVsPt_Y2440)/IntX(1.5,49.5,grPPJpsiCrossSectionVsPt_Y2440)<<endl;
  



  cout<<" pp Jpsi cross section pT [6.5, 30.0] GeV/c, y [-2.1,2.1]: "<<IntX(6.5,49.5,grPPJpsiCrossSectionVsPt_Y21)<<" mub"<<endl;
  cout<<" AA Jpsi cross section pT [6.5, 30.0] GeV/c, y [-2.1,2.1]: "<<IntX(6.5,49.5,grJpsiCrossSectionVsPt_Y21)<<" mub "<<" Shadowing Factor "<<
    IntX(6.5,49.5,grJpsiCrossSectionVsPt_Y21)/IntX(6.5,49.5,grPPJpsiCrossSectionVsPt_Y21)<<endl;
  
  //  return;  




  //................................................................................................................//
  //======================================= Upsion Cross sections ==================================================//
  //................................................................................................................//


 //======================== Upsilon Rapidity Distributions =======================//
  
  //all cross sections in mub, do not include lepton pair branching ratios,
  // y     dsig(pp)/dy  dsig(AA-mid)/dy  dsig(AA-up)/dy   dsig(AA-dn)/dy
  
  Int_t NNUpsilonRap = 24;
  Double_t UpsilonRap[24]={0.0};
  Double_t UpsilonDSigmaPPDy[24]={0.0};
  Double_t UpsilonDSigmaAACDy[24]={0.0};
  Double_t UpsilonDSigmaAAUDy[24]={0.0};
  Double_t UpsilonDSigmaAALDy[24]={0.0};
  
  
  ifstream filein5("InTextFiles/TempFiles/Temp_UpsilonCrossSectionVsRap.txt");
  
  for(int i=0; i<NNUpsilonRap; i++) 
    {
      filein5 >> UpsilonRap[i] >> UpsilonDSigmaPPDy[i] >> UpsilonDSigmaAACDy[i] >> UpsilonDSigmaAAUDy[i] >> UpsilonDSigmaAALDy[i]; 
      
    }

  TGraph *grUpsilonDSigmaPPDy = new TGraph(NNUpsilonRap, UpsilonRap, UpsilonDSigmaPPDy);
  grUpsilonDSigmaPPDy->SetName("grUpsilonDSigmaPPDy");
  grUpsilonDSigmaPPDy->SetTitle("grUpsilonDSigmaPPDy");
  grUpsilonDSigmaPPDy->SetLineWidth(2);
  grUpsilonDSigmaPPDy->SetLineColor(2);
  grUpsilonDSigmaPPDy->GetYaxis()->SetTitleOffset(1.8);
  grUpsilonDSigmaPPDy->GetYaxis()->SetRangeUser(0.0,0.04);
  grUpsilonDSigmaPPDy->GetXaxis()->SetTitle("y^{#varUpsilon}");
  grUpsilonDSigmaPPDy->GetYaxis()->SetTitle("#frac{d#sigma^{pp}}{dy}(#mu b)");
  
  new TCanvas;
  gPad->SetLeftMargin(0.2);
  gPad->SetTicks();
  grUpsilonDSigmaPPDy->Draw("AL");

  gPad->SaveAs("Plots/UpsilonDSigmaPPDy.png");
  gPad->SaveAs("Plots/UpsilonDSigmaPPDy.pdf");
  gPad->SaveAs("Plots/UpsilonDSigmaPPDy.eps");

  
  // Double_t RapBinWidth = 0.5;
  Double_t PPUpsilonCross =0.0;

  for(int i =0 ;i<NNUpsilonRap ;i++)
    {
      PPUpsilonCross = PPUpsilonCross + UpsilonDSigmaPPDy[i];

    }

  PPUpsilonCross = PPUpsilonCross*RapBinWidth;

  cout<<" pp Upsilon cross section = "<<PPUpsilonCross<<endl;


  TGraph *grUpsilonDSigmaAACDy = new TGraph(NNUpsilonRap, UpsilonRap, UpsilonDSigmaAACDy);
  grUpsilonDSigmaAACDy->SetName("grUpsilonDSigmaAACDy");
  grUpsilonDSigmaAACDy->SetTitle("grUpsilonDSigmaAACDy");
  grUpsilonDSigmaAACDy->SetLineWidth(2);
  grUpsilonDSigmaAACDy->SetLineColor(2);
  grUpsilonDSigmaAACDy->GetYaxis()->SetTitleOffset(1.8);
  grUpsilonDSigmaAACDy->GetYaxis()->SetRangeUser(0.0,0.04);
  grUpsilonDSigmaAACDy->GetXaxis()->SetTitle("y^{#varUpsilon}");
  grUpsilonDSigmaAACDy->GetYaxis()->SetTitle("#frac{d#sigma^{AA}}{dy}(#mu b)");
  

  TGraph *grUpsilonDSigmaAAUDy = new TGraph(NNUpsilonRap, UpsilonRap, UpsilonDSigmaAAUDy);
  grUpsilonDSigmaAAUDy->SetName("grUpsilonDSigmaAAUDy");
  grUpsilonDSigmaAAUDy->SetTitle("grUpsilonDSigmaAAUDy");
  grUpsilonDSigmaAAUDy->SetLineWidth(2);
  grUpsilonDSigmaAAUDy->SetLineColor(1);
  grUpsilonDSigmaAAUDy->GetYaxis()->SetTitleOffset(1.8);
  grUpsilonDSigmaAAUDy->GetYaxis()->SetRangeUser(0.0,0.04);
  grUpsilonDSigmaAAUDy->GetXaxis()->SetTitle("y^{#varUpsilon}");
  grUpsilonDSigmaAAUDy->GetYaxis()->SetTitle("#frac{d#sigma^{AA}}{dy}(#mu b)");


  TGraph *grUpsilonDSigmaAALDy = new TGraph(NNUpsilonRap, UpsilonRap, UpsilonDSigmaAALDy);
  grUpsilonDSigmaAALDy->SetName("grUpsilonDSigmaAALDy");
  grUpsilonDSigmaAALDy->SetTitle("grUpsilonDSigmaAALDy");
  grUpsilonDSigmaAALDy->SetLineWidth(2);
  grUpsilonDSigmaAALDy->SetLineColor(1);
  grUpsilonDSigmaAALDy->GetYaxis()->SetTitleOffset(1.8);
  grUpsilonDSigmaAALDy->GetYaxis()->SetRangeUser(0.0,0.04);
  grUpsilonDSigmaAALDy->GetXaxis()->SetTitle("y^{#varUpsilon}");
  grUpsilonDSigmaAALDy->GetYaxis()->SetTitle("#frac{d#sigma^{AA}}{dy}(#mu b)");


  new TCanvas;
  gPad->SetLeftMargin(0.20);
  gPad->SetTicks();
  grUpsilonDSigmaAACDy->Draw("AL");
  grUpsilonDSigmaAAUDy->Draw("Csame");
  grUpsilonDSigmaAALDy->Draw("Csame");
  gPad->SaveAs("Plots/UpsilonDSigmaAADy.png");
  gPad->SaveAs("Plots/UpsilonDSigmaAADy.pdf");
  gPad->SaveAs("Plots/UpsilonDSigmaAADy.eps");


  cout<<" pp Upsilon cross section y [-5.75,5.75]: "<<IntX(-5.75,5.75,grUpsilonDSigmaPPDy)<<" mub"<<endl;
  
  cout<<" pp Upsilon cross section y [-1.0,1.0]: "<<IntX(-0.75,0.75,grUpsilonDSigmaPPDy)<<"   mub"<<endl;
  cout<<" pp Upsilon cross section y [2.5,4.0]:  "<<IntX(2.75,3.75,grUpsilonDSigmaPPDy)<<"    mub"<<endl;
  cout<<" pp Upsilon cross section y [-2.4,2.4]: "<<IntX(-2.25,2.25,grUpsilonDSigmaPPDy)<<"   mub"<<endl;
  
  cout<<" AA Upsilon cross section y [-5.75,5.75]: "<<IntX(-5.75,5.75,grUpsilonDSigmaAACDy)<<" mub "<<" Shadowing Factor "<<IntX(-5.75,5.75,grUpsilonDSigmaAACDy)/IntX(-5.75,5.75,grUpsilonDSigmaPPDy)<<endl;
  
  cout<<" AA Upsilon cross section y [-1.0,1.0]: "<<IntX(-0.75,0.75,grUpsilonDSigmaAACDy)<<" mub    "<<" Shadowing Factor "<<IntX(-0.75,0.75,grUpsilonDSigmaAACDy)/IntX(-0.75,0.75,grUpsilonDSigmaPPDy)<<endl;
  cout<<" AA Upsilon cross section y [2.5,4.0]: "<<IntX(2.75,3.75,grUpsilonDSigmaAACDy)<<" mub    "<<" Shadowing Factor "<<IntX(2.75,3.75,grUpsilonDSigmaAACDy)/IntX(2.75,3.75,grUpsilonDSigmaPPDy)<<endl;
  cout<<" AA Upsilon cross section y [-2.4,2.4]: "<<IntX(-2.25,2.25,grUpsilonDSigmaAACDy)<<" mub   "<<" Shadowing Factor "<<IntX(-2.25,2.25,grUpsilonDSigmaAACDy)/IntX(-2.25,2.25,grUpsilonDSigmaPPDy)<<endl;

  
  cout<<" Upsilon y = [-5.75,5.75]: "<< NQQ(IntX(-6.75,6.75,grUpsilonDSigmaAACDy))<<endl;
  cout<<" Upsilon y = [-1.0,1.0]: "<< NQQ(IntX(-0.75,0.75,grUpsilonDSigmaAACDy))<<endl;
  cout<<" Upsilon y = [2.5,4.0]:  "<< NQQ(IntX(2.75,3.75,grUpsilonDSigmaAACDy))<<endl;
  cout<<" Upsilon y = [-2.4,2.4]: "<< NQQ(IntX(-2.25,2.25,grUpsilonDSigmaAACDy))<<endl;





  //return;


  //======================== Upsilon Pt Distributions =======================//
  //p_T distributions need to be adjusted for rapidity bin width if you
  //use those direct
  //p_T    dsig(pp)/dp_T  dsig(AA-mid)/dp_T  dsig(AA-up)/dp_T   dsig(AA-dn)/dp_T
  
  Int_t UpsilonNNPt_Y1 = 49;
  Double_t UpsilonPt_Y1[100]={0.0};
  Double_t PPUpsilonCrossSectionVsPt_Y1[100]={0.0};
  Double_t UpsilonCrossSectionVsPt_Y1[100]={0.0};
  Double_t UpsilonCrossSectionVsPt_Y1U[100]={0.0};
  Double_t UpsilonCrossSectionVsPt_Y1L[100]={0.0};
  
  ifstream filein6("InTextFiles/TempFiles/Temp_UpsilonCrossSectionVsPtInRap1.txt");
  for(int i=0; i<UpsilonNNPt_Y1; i++) 
    {
      filein6 >> UpsilonPt_Y1[i] >> PPUpsilonCrossSectionVsPt_Y1[i] >> UpsilonCrossSectionVsPt_Y1[i] >> UpsilonCrossSectionVsPt_Y1U[i] >> UpsilonCrossSectionVsPt_Y1L[i]; 
                
    }
  

  TGraph *grPPUpsilonCrossSectionVsPt_Y1 = new TGraph(UpsilonNNPt_Y1, UpsilonPt_Y1, PPUpsilonCrossSectionVsPt_Y1);
  grPPUpsilonCrossSectionVsPt_Y1->SetName("grPPUpsilonCrossSectionVsPt_Y1");
  grPPUpsilonCrossSectionVsPt_Y1->SetTitle("grPPUpsilonCrossSectionVsPt_Y1");
  grPPUpsilonCrossSectionVsPt_Y1->SetLineWidth(2);
  grPPUpsilonCrossSectionVsPt_Y1->SetLineColor(2);
  grPPUpsilonCrossSectionVsPt_Y1->GetYaxis()->SetRangeUser(0.0,1.5);
  grPPUpsilonCrossSectionVsPt_Y1->GetXaxis()->SetTitle("p_{T}^{#varUpsilon}(GeV/c)");
  grPPUpsilonCrossSectionVsPt_Y1->GetYaxis()->SetTitle("#frac{d#sigma^{PP}}{dp_{T}}(#mu b)");
  grPPUpsilonCrossSectionVsPt_Y1->GetYaxis()->SetTitleOffset(1.4);
  grPPUpsilonCrossSectionVsPt_Y1->GetYaxis()->SetRangeUser(0.000001,10.0);


 


  TGraph *grUpsilonCrossSectionVsPt_Y1 = new TGraph(UpsilonNNPt_Y1, UpsilonPt_Y1, UpsilonCrossSectionVsPt_Y1);
  grUpsilonCrossSectionVsPt_Y1->SetName("grUpsilonCrossSectionVsPt_Y1");
  grUpsilonCrossSectionVsPt_Y1->SetTitle("grUpsilonCrossSectionVsPt_Y1");
  grUpsilonCrossSectionVsPt_Y1->SetLineWidth(2);
  grUpsilonCrossSectionVsPt_Y1->SetLineColor(2);
  grUpsilonCrossSectionVsPt_Y1->GetYaxis()->SetRangeUser(0.0,1.5);
  grUpsilonCrossSectionVsPt_Y1->GetXaxis()->SetTitle("p_{T}^{#varUpsilon}(GeV/c)");
  grUpsilonCrossSectionVsPt_Y1->GetYaxis()->SetTitle("#frac{d#sigma^{AA}}{dp_{T}}(#mu b)");
  grUpsilonCrossSectionVsPt_Y1->GetYaxis()->SetTitleOffset(1.4);
  grUpsilonCrossSectionVsPt_Y1->GetYaxis()->SetRangeUser(0.000001,10.0);

  TGraph *grUpsilonCrossSectionUVsPt_Y1 = new TGraph(UpsilonNNPt_Y1, UpsilonPt_Y1, UpsilonCrossSectionVsPt_Y1U);
  grUpsilonCrossSectionUVsPt_Y1->SetName("grUpsilonCrossSectionUVsPt_Y1");
  TGraph *grUpsilonCrossSectionLVsPt_Y1 = new TGraph(UpsilonNNPt_Y1, UpsilonPt_Y1, UpsilonCrossSectionVsPt_Y1L);
  grUpsilonCrossSectionLVsPt_Y1->SetName("grUpsilonCrossSectionLVsPt_Y1");


  new TCanvas;
  gPad->SetTicks();
  gPad->SetLogy(1);
  gPad->SetLeftMargin(0.18);
  grPPUpsilonCrossSectionVsPt_Y1->Draw("AC");
  tb->DrawLatex(0.27,0.20,"|y| #leq 1");

  gPad->SaveAs("Plots/UpsilonCrossSectionAAVsPt_Y1.png");
  gPad->SaveAs("Plots/UpsilonCrossSectionAAVsPt_Y1.pdf");
  gPad->SaveAs("Plots/UpsilonCrossSectionAAVsPt_Y1.eps");


  
  new TCanvas;
  gPad->SetTicks();
  gPad->SetLogy(1);
  gPad->SetLeftMargin(0.18);
  grUpsilonCrossSectionVsPt_Y1->Draw("AC");
  grUpsilonCrossSectionUVsPt_Y1->Draw("Csame");
  grUpsilonCrossSectionLVsPt_Y1->Draw("Csame");
  tb->DrawLatex(0.27,0.20,"|y| #leq 1");

  gPad->SaveAs("Plots/UpsilonCrossSectionPPVsPt_Y1.png");
  gPad->SaveAs("Plots/UpsilonCrossSectionPPVsPt_Y1.pdf");
  gPad->SaveAs("Plots/UpsilonCrossSectionPPVsPt_Y1.eps");




  Int_t UpsilonNNPt_Y2440 = 50;

  Double_t UpsilonPt_Y2440[100]={0.0};
  Double_t PPUpsilonCrossSectionVsPt_Y2440[100]={0.0};
  Double_t UpsilonCrossSectionVsPt_Y2440[100]={0.0};
  Double_t UpsilonCrossSectionVsPt_Y2440U[100]={0.0};
  Double_t UpsilonCrossSectionVsPt_Y2440L[100]={0.0};
  
  ifstream filein7("InTextFiles/TempFiles/Temp_UpsilonCrossSectionVsPtInRap2440.txt");
  for(int i=0; i<UpsilonNNPt_Y2440; i++) 
    {
      filein7 >> UpsilonPt_Y2440[i] >> PPUpsilonCrossSectionVsPt_Y2440[i] >> UpsilonCrossSectionVsPt_Y2440[i] >> UpsilonCrossSectionVsPt_Y2440U[i] >> UpsilonCrossSectionVsPt_Y2440L[i]; 
                
    }
  

  TGraph *grPPUpsilonCrossSectionVsPt_Y2440 = new TGraph(UpsilonNNPt_Y2440, UpsilonPt_Y2440, PPUpsilonCrossSectionVsPt_Y2440);
  grPPUpsilonCrossSectionVsPt_Y2440->SetName("grPPUpsilonCrossSectionVsPt_Y2440");
  grPPUpsilonCrossSectionVsPt_Y2440->SetTitle("grPPUpsilonCrossSectionVsPt_Y2440");
  grPPUpsilonCrossSectionVsPt_Y2440->SetLineWidth(2);
  grPPUpsilonCrossSectionVsPt_Y2440->SetLineColor(2);
  grPPUpsilonCrossSectionVsPt_Y2440->GetYaxis()->SetRangeUser(0.0,1.5);
  grPPUpsilonCrossSectionVsPt_Y2440->GetXaxis()->SetTitle("p_{T}^{#varUpsilon}(GeV/c)");
  grPPUpsilonCrossSectionVsPt_Y2440->GetYaxis()->SetTitle("#frac{d#sigma^{PP}}{dp_{T}}(#mu b)");
  grPPUpsilonCrossSectionVsPt_Y2440->GetYaxis()->SetTitleOffset(1.4);
  grPPUpsilonCrossSectionVsPt_Y2440->GetYaxis()->SetRangeUser(0.00000001,0.01);



  TGraph *grUpsilonCrossSectionVsPt_Y2440 = new TGraph(UpsilonNNPt_Y2440, UpsilonPt_Y2440, UpsilonCrossSectionVsPt_Y2440);
  grUpsilonCrossSectionVsPt_Y2440->SetName("grUpsilonCrossSectionVsPt_Y2440");
  grUpsilonCrossSectionVsPt_Y2440->SetTitle("grUpsilonCrossSectionVsPt_Y2440");
  grUpsilonCrossSectionVsPt_Y2440->SetLineWidth(2);
  grUpsilonCrossSectionVsPt_Y2440->SetLineColor(2);
  grUpsilonCrossSectionVsPt_Y2440->GetYaxis()->SetRangeUser(0.0,1.5);
  grUpsilonCrossSectionVsPt_Y2440->GetXaxis()->SetTitle("p_{T}^{#varUpsilon}(GeV/c)");
  grUpsilonCrossSectionVsPt_Y2440->GetYaxis()->SetTitle("#frac{d#sigma^{AA}}{dp_{T}}(#mu b)");
  grUpsilonCrossSectionVsPt_Y2440->GetYaxis()->SetTitleOffset(1.4);
  grUpsilonCrossSectionVsPt_Y2440->GetYaxis()->SetRangeUser(0.00000001,0.01);

  TGraph *grUpsilonCrossSectionUVsPt_Y2440 = new TGraph(UpsilonNNPt_Y2440, UpsilonPt_Y2440, UpsilonCrossSectionVsPt_Y2440U);
  grUpsilonCrossSectionUVsPt_Y2440->SetName("grUpsilonCrossSectionUVsPt_Y2440");
  TGraph *grUpsilonCrossSectionLVsPt_Y2440 = new TGraph(UpsilonNNPt_Y2440, UpsilonPt_Y2440, UpsilonCrossSectionVsPt_Y2440L);
  grUpsilonCrossSectionLVsPt_Y2440->SetName("grUpsilonCrossSectionLVsPt_Y2440");


  new TCanvas;
  gPad->SetTicks();
  gPad->SetLogy(1);
  gPad->SetLeftMargin(0.18);
  grPPUpsilonCrossSectionVsPt_Y2440->Draw("AC");
  tb->DrawLatex(0.27,0.20,"2.4 #leq y #leq 4.0");

  gPad->SaveAs("Plots/UpsilonCrossSectionAAVsPt_Y2440.png");
  gPad->SaveAs("Plots/UpsilonCrossSectionAAVsPt_Y2440.pdf");
  gPad->SaveAs("Plots/UpsilonCrossSectionAAVsPt_Y2440.eps");


  
  
  new TCanvas;
  gPad->SetTicks();
  gPad->SetLogy(1);
  gPad->SetLeftMargin(0.18);
  grUpsilonCrossSectionVsPt_Y2440->Draw("AC");
  grUpsilonCrossSectionUVsPt_Y2440->Draw("Csame");
  grUpsilonCrossSectionLVsPt_Y2440->Draw("Csame");
  tb->DrawLatex(0.27,0.20,"2.4 #leq y #leq 4.0");

  gPad->SaveAs("Plots/UpsilonCrossSectionPPVsPt_Y2440.png");
  gPad->SaveAs("Plots/UpsilonCrossSectionPPVsPt_Y2440.pdf");
  gPad->SaveAs("Plots/UpsilonCrossSectionPPVsPt_Y2440.eps");



 
 Int_t UpsilonNNPt_Y21 = 49;
  Double_t UpsilonPt_Y21[100]={0.0};
  Double_t PPUpsilonCrossSectionVsPt_Y21[100]={0.0};
  Double_t UpsilonCrossSectionVsPt_Y21[100]={0.0};
  Double_t UpsilonCrossSectionVsPt_Y21U[100]={0.0};
  Double_t UpsilonCrossSectionVsPt_Y21L[100]={0.0};
  
  ifstream filein8("InTextFiles/TempFiles/Temp_UpsilonCrossSectionVsPtInRap21.txt");
  for(int i=0; i<UpsilonNNPt_Y21; i++) 
    {
      filein8 >> UpsilonPt_Y21[i] >> PPUpsilonCrossSectionVsPt_Y21[i] >> UpsilonCrossSectionVsPt_Y21[i] >> UpsilonCrossSectionVsPt_Y21U[i] >> UpsilonCrossSectionVsPt_Y21L[i]; 
                
    }
  

  TGraph *grPPUpsilonCrossSectionVsPt_Y21 = new TGraph(UpsilonNNPt_Y21, UpsilonPt_Y21, PPUpsilonCrossSectionVsPt_Y21);
  grPPUpsilonCrossSectionVsPt_Y21->SetName("grPPUpsilonCrossSectionVsPt_Y21");
  grPPUpsilonCrossSectionVsPt_Y21->SetTitle("grPPUpsilonCrossSectionVsPt_Y21");
  grPPUpsilonCrossSectionVsPt_Y21->SetLineWidth(2);
  grPPUpsilonCrossSectionVsPt_Y21->SetLineColor(2);
  grPPUpsilonCrossSectionVsPt_Y21->GetYaxis()->SetRangeUser(0.0,1.5);
  grPPUpsilonCrossSectionVsPt_Y21->GetXaxis()->SetTitle("p_{T}^{#varUpsilon}(GeV/c)");
  grPPUpsilonCrossSectionVsPt_Y21->GetYaxis()->SetTitle("#frac{d#sigma^{PP}}{dp_{T}}(#mu b)");
  grPPUpsilonCrossSectionVsPt_Y21->GetYaxis()->SetTitleOffset(1.4);
  grPPUpsilonCrossSectionVsPt_Y21->GetYaxis()->SetRangeUser(0.000001,10.0);


 


  TGraph *grUpsilonCrossSectionVsPt_Y21 = new TGraph(UpsilonNNPt_Y21, UpsilonPt_Y21, UpsilonCrossSectionVsPt_Y21);
  grUpsilonCrossSectionVsPt_Y21->SetName("grUpsilonCrossSectionVsPt_Y21");
  grUpsilonCrossSectionVsPt_Y21->SetTitle("grUpsilonCrossSectionVsPt_Y21");
  grUpsilonCrossSectionVsPt_Y21->SetLineWidth(2);
  grUpsilonCrossSectionVsPt_Y21->SetLineColor(2);
  grUpsilonCrossSectionVsPt_Y21->GetYaxis()->SetRangeUser(0.0,1.5);
  grUpsilonCrossSectionVsPt_Y21->GetXaxis()->SetTitle("p_{T}^{#varUpsilon}(GeV/c)");
  grUpsilonCrossSectionVsPt_Y21->GetYaxis()->SetTitle("#frac{d#sigma^{AA}}{dp_{T}}(#mu b)");
  grUpsilonCrossSectionVsPt_Y21->GetYaxis()->SetTitleOffset(1.4);
  grUpsilonCrossSectionVsPt_Y21->GetYaxis()->SetRangeUser(0.000001,10.0);

  TGraph *grUpsilonCrossSectionUVsPt_Y21 = new TGraph(UpsilonNNPt_Y21, UpsilonPt_Y21, UpsilonCrossSectionVsPt_Y21U);
  grUpsilonCrossSectionUVsPt_Y21->SetName("grUpsilonCrossSectionUVsPt_Y21");
  TGraph *grUpsilonCrossSectionLVsPt_Y21 = new TGraph(UpsilonNNPt_Y21, UpsilonPt_Y21, UpsilonCrossSectionVsPt_Y21L);
  grUpsilonCrossSectionLVsPt_Y21->SetName("grUpsilonCrossSectionLVsPt_Y21");


  new TCanvas;
  gPad->SetTicks();
  gPad->SetLogy(1);
  gPad->SetLeftMargin(0.18);
  grPPUpsilonCrossSectionVsPt_Y21->Draw("AC");
  tb->DrawLatex(0.27,0.20,"|y| #leq 2.1");

  gPad->SaveAs("Plots/UpsilonCrossSectionAAVsPt_Y21.png");
  gPad->SaveAs("Plots/UpsilonCrossSectionAAVsPt_Y21.pdf");
  gPad->SaveAs("Plots/UpsilonCrossSectionAAVsPt_Y21.eps");


  
  new TCanvas;
  gPad->SetTicks();
  gPad->SetLogy(1);
  gPad->SetLeftMargin(0.18);
  grUpsilonCrossSectionVsPt_Y21->Draw("AC");
  grUpsilonCrossSectionUVsPt_Y21->Draw("Csame");
  grUpsilonCrossSectionLVsPt_Y21->Draw("Csame");
  tb->DrawLatex(0.27,0.20,"|y| #leq 2.1");

  gPad->SaveAs("Plots/UpsilonCrossSectionPPVsPt_Y21.png");
  gPad->SaveAs("Plots/UpsilonCrossSectionPPVsPt_Y21.pdf");
  gPad->SaveAs("Plots/UpsilonCrossSectionPPVsPt_Y21.eps");



  cout<<" pp Upsilon cross section pT [1.5, 49.5] GeV/c, y [-1.0,1.0]: "<<IntX(1.5,49.5,grPPUpsilonCrossSectionVsPt_Y1)<<" mub"<<endl;
  cout<<" AA Upsilon cross section pT [1.5, 49.5] GeV/c, y [-1.0,1.0]: "<<IntX(1.5,49.5,grUpsilonCrossSectionVsPt_Y1)<<" mub "<<" Shadowing Factor "<<
    IntX(1.5,49.5,grUpsilonCrossSectionVsPt_Y1)/IntX(1.5,49.5,grPPUpsilonCrossSectionVsPt_Y1)<<endl;
  
  cout<<" pp Upsilon cross section pT [1.5, 49.5] GeV/c, y [2.4,4.0]: "<<IntX(1.5,49.5,grPPUpsilonCrossSectionVsPt_Y2440)<<" mub"<<endl;
  cout<<" AA Upsilon cross section pT [1.5, 49.5] GeV/c, y [2.4,4.0]: "<<IntX(1.5,49.5,grUpsilonCrossSectionVsPt_Y2440)<<" mub "<<" Shadowing Factor "<<
    IntX(1.5,49.5,grUpsilonCrossSectionVsPt_Y2440)/IntX(1.5,49.5,grPPUpsilonCrossSectionVsPt_Y2440)<<endl;
  

  cout<<" pp Upsilon cross section pT [1.5, 49.5] GeV/c, y [-2.1,2.1]: "<<IntX(1.5,49.5,grPPUpsilonCrossSectionVsPt_Y21)<<" mub"<<endl;
  cout<<" AA Upsilon cross section pT [1.5, 49.5] GeV/c, y [-2.1,2.1]: "<<IntX(1.5,49.5,grUpsilonCrossSectionVsPt_Y21)<<" mub "<<" Shadowing Factor "<<
    IntX(1.5,49.5,grUpsilonCrossSectionVsPt_Y21)/IntX(1.5,49.5,grPPUpsilonCrossSectionVsPt_Y21)<<endl;




  //.......................................................................................................................................//
  //.......................................................................................................................................//
  //=======================================================================================================================================//
  //========================================================= Open Charm Open Bottom Distributions ========================================//
  //=======================================================================================================================================//
  //.......................................................................................................................................//
  //.......................................................................................................................................//

  //all cross sections in mub
  //BTW, I don't have as wide a range in rapidity space with the FONLL grids
  //than in the MNR single distributions, sorry.  It should be OK though.

  //Note also that the rapidity distributions around midrapidity are only on
  //one side, not both!  This is not the same as for quarkonium.

  




//======================== D0 Rapidity Distributions =======================//
  //D0 pp cross sections with uncertainties
  //y         dsig(cent)/dy  dsig(up)/dy  dsig(dn)/dy
  

  Int_t NND0Rap = 8;
  Double_t D0Rap[8]={0.0};
  
  Double_t D0DSigmaPPCDy[8]={0.0};
  Double_t D0DSigmaPPUDy[8]={0.0};
  Double_t D0DSigmaPPLDy[8]={0.0};
  
  
  ifstream filein9("InTextFiles/TempFiles/Temp_D0CrossSectionVsRap.txt");
  
  for(int i=0; i<NND0Rap; i++) 
    {
      filein9 >> D0Rap[i] >> D0DSigmaPPCDy[i] >> D0DSigmaPPUDy[i] >> D0DSigmaPPLDy[i]; 
      
    }
  

  /*
  Double_t D0RapBinWidth = 0.25;
  Double_t PPD0Cross =0.0;

  for(int i =0 ;i<NND0Rap ;i++)
    {
      PPD0Cross = PPD0Cross + D0DSigmaPPCDy[i];
      cout<<D0DSigmaPPCDy[i]<<endl;
    }

  PPD0Cross = PPD0Cross*D0RapBinWidth;
  */
  

  TGraph *grD0DSigmaPPCDy = new TGraph(NND0Rap, D0Rap, D0DSigmaPPCDy);
  grD0DSigmaPPCDy->SetName("grD0DSigmaPPCDy");
  grD0DSigmaPPCDy->SetTitle("grD0DSigmaPPCDy");
  grD0DSigmaPPCDy->SetLineWidth(2);
  grD0DSigmaPPCDy->SetLineColor(2);
  grD0DSigmaPPCDy->GetYaxis()->SetTitleOffset(1.8);
  grD0DSigmaPPCDy->GetYaxis()->SetRangeUser(0.0,1000.0);
  grD0DSigmaPPCDy->GetXaxis()->SetTitle("y^{D^{0}}");
  grD0DSigmaPPCDy->GetYaxis()->SetTitle("#frac{d#sigma^{PP}}{dy}(#mu b)");
  

  TGraph *grD0DSigmaPPUDy = new TGraph(NND0Rap, D0Rap, D0DSigmaPPUDy);
  grD0DSigmaPPUDy->SetName("grD0DSigmaPPUDy");
  grD0DSigmaPPUDy->SetTitle("grD0DSigmaPPUDy");
  grD0DSigmaPPUDy->SetLineWidth(2);
  grD0DSigmaPPUDy->SetLineColor(1);
  grD0DSigmaPPUDy->GetYaxis()->SetTitleOffset(1.8);
  grD0DSigmaPPUDy->GetYaxis()->SetRangeUser(0.0,1000.0);
  grD0DSigmaPPUDy->GetXaxis()->SetTitle("y^{D^{0}}");
  grD0DSigmaPPUDy->GetYaxis()->SetTitle("#frac{d#sigma^{PP}}{dy}(#mu b)");


  TGraph *grD0DSigmaPPLDy = new TGraph(NND0Rap, D0Rap, D0DSigmaPPLDy);
  grD0DSigmaPPLDy->SetName("grD0DSigmaPPLDy");
  grD0DSigmaPPLDy->SetTitle("grD0DSigmaPPLDy");
  grD0DSigmaPPLDy->SetLineWidth(2);
  grD0DSigmaPPLDy->SetLineColor(1);
  grD0DSigmaPPLDy->GetYaxis()->SetTitleOffset(1.8);
  grD0DSigmaPPLDy->GetYaxis()->SetRangeUser(0.0,1000.0);
  grD0DSigmaPPLDy->GetXaxis()->SetTitle("y^{D^{0}}");
  grD0DSigmaPPLDy->GetYaxis()->SetTitle("#frac{d#sigma^{PP}}{dy}(#mu b)");


  new TCanvas;
  gPad->SetLeftMargin(0.20);
  gPad->SetTicks();
  grD0DSigmaPPCDy->GetYaxis()->SetRangeUser(0.0,1000.0);
  grD0DSigmaPPCDy->Draw("ALP");
  grD0DSigmaPPUDy->Draw("LPsame");
  grD0DSigmaPPLDy->Draw("LPsame");
  gPad->SaveAs("Plots/D0DSigmaPPDy.png");
  gPad->SaveAs("Plots/D0DSigmaPPDy.pdf");
  gPad->SaveAs("Plots/D0DSigmaPPDy.eps");


  Double_t D0RapBinWidth = 0.5;
  Double_t PPD0Cross =0.0;
  for(int i =0 ;i<NND0Rap ;i++)
    {
      PPD0Cross = PPD0Cross + D0DSigmaPPCDy[i];
      cout<<D0Rap[i]<<"   "<<D0DSigmaPPCDy[i]<<endl;
    }

  PPD0Cross = 2.0*PPD0Cross*D0RapBinWidth;
  cout<<" pp D0 cross section in rapidity [-4.0-4.0]: "<<PPD0Cross<<" mub "<<endl;
  


  //cout<<" Value at 0.75 "<<grD0DSigmaPPCDy->Eval(0.75)<<endl;
  

  //return;
  //Asymetric bins 
  cout<<"  pp D0 cross section in rapidity [0.25-3.75]: "<< 2.0*IntX(0.25,3.75,grD0DSigmaPPCDy)<<" mub "<<endl; // 4027
  cout<<"  pp D0 cross section in rapidity [-1.0-1.0]: "<< 2.0*IntX(0.25,0.75,grD0DSigmaPPCDy)<<" mub "<<endl;  //1223.3
  cout<<"  pp D0 cross section in rapidity [2.5-4.0]: "<< IntX(2.75,3.75,grD0DSigmaPPCDy)<<" mub "<<endl; //575.95
  cout<<"  pp D0 cross section in rapidity [-2.5-2.5]: "<< 2.0*IntX(0.0,2.25,grD0DSigmaPPCDy)<<" mub "<<endl; //2772.88

  cout<<" Ncc y = [-6.0,6.0]: "<< NQQ(4110.0)<<endl;
  cout<<" Ncc y = [-4.0,4.0]: "<< NQQ(4027)<<endl;
  cout<<" Ncc y = [-1.0,1.0]: "<< NQQ(1223.3)<<endl;
  cout<<" Ncc y = [2.5,4.0]: "<< NQQ(575.95)<<endl;
  cout<<" Ncc y = [-2.4,2.4]: "<< NQQ(2772.88)<<endl;


  //======================== D0 Pt Distributions =======================//
  //p_T distributions have rapidity bin width already divided out 
  //0 < y < 1
  

  //p_T  dsig(cent)/dp_T  dsig(up)/dp_T   dsig(dn)/dp_T
  
  Int_t D0NNPt_Y1 = 50;
  Double_t D0Pt_Y1[100]={0.0};
  
  Double_t D0CrossSectionVsPt_Y1[100]={0.0};
  Double_t D0CrossSectionVsPt_Y1U[100]={0.0};
  Double_t D0CrossSectionVsPt_Y1L[100]={0.0};
  
  ifstream filein10("InTextFiles/TempFiles/Temp_D0CrossSectionVsPtInRap1.txt");
  for(int i=0; i<D0NNPt_Y1; i++) 
    {
      filein10 >> D0Pt_Y1[i] >> D0CrossSectionVsPt_Y1[i] >> D0CrossSectionVsPt_Y1U[i] >> D0CrossSectionVsPt_Y1L[i]; 
                
    }
  
 
  TGraph *grD0CrossSectionVsPt_Y1 = new TGraph(D0NNPt_Y1, D0Pt_Y1, D0CrossSectionVsPt_Y1);
  grD0CrossSectionVsPt_Y1->SetName("grD0CrossSectionVsPt_Y1");
  grD0CrossSectionVsPt_Y1->SetTitle("grD0CrossSectionVsPt_Y1");
  grD0CrossSectionVsPt_Y1->SetLineWidth(2);
  grD0CrossSectionVsPt_Y1->SetLineColor(2);
  grD0CrossSectionVsPt_Y1->GetYaxis()->SetRangeUser(0.0,1.5);
  grD0CrossSectionVsPt_Y1->GetXaxis()->SetTitle("p_{T}^{D^{0}}(GeV/c)");
  grD0CrossSectionVsPt_Y1->GetYaxis()->SetTitle("#frac{d#sigma^{PP}}{dp_{T}}(#mu b)");
  grD0CrossSectionVsPt_Y1->GetYaxis()->SetTitleOffset(1.4);
  grD0CrossSectionVsPt_Y1->GetYaxis()->SetRangeUser(0.000001,1000.0);

  TGraph *grD0CrossSectionUVsPt_Y1 = new TGraph(D0NNPt_Y1, D0Pt_Y1, D0CrossSectionVsPt_Y1U);
  grD0CrossSectionUVsPt_Y1->SetName("grD0CrossSectionUVsPt_Y1");
  TGraph *grD0CrossSectionLVsPt_Y1 = new TGraph(D0NNPt_Y1, D0Pt_Y1, D0CrossSectionVsPt_Y1L);
  grD0CrossSectionLVsPt_Y1->SetName("grD0CrossSectionLVsPt_Y1");

  
  new TCanvas;
  gPad->SetTicks();
  gPad->SetLogy(1);
  gPad->SetLeftMargin(0.18);
  grD0CrossSectionVsPt_Y1->Draw("AC");
  grD0CrossSectionUVsPt_Y1->Draw("Csame");
  grD0CrossSectionLVsPt_Y1->Draw("Csame");
  tb->DrawLatex(0.27,0.20,"0 #leq y #leq 1");

  gPad->SaveAs("Plots/PPD0CrossSectionPPVsPt_Y1.png");
  gPad->SaveAs("Plots/PPD0CrossSectionPPVsPt_Y1.pdf");
  gPad->SaveAs("Plots/PPD0CrossSectionPPVsPt_Y1.eps");



  Int_t D0NNPt_Y2440 = 50;
  Double_t D0Pt_Y2440[100]={0.0};
  
  Double_t D0CrossSectionVsPt_Y2440[100]={0.0};
  Double_t D0CrossSectionVsPt_Y2440U[100]={0.0};
  Double_t D0CrossSectionVsPt_Y2440L[100]={0.0};
  
  ifstream filein11("InTextFiles/TempFiles/Temp_D0CrossSectionVsPtInRap2440.txt");
  for(int i=0; i<D0NNPt_Y2440; i++) 
    {
      filein11 >> D0Pt_Y2440[i] >> D0CrossSectionVsPt_Y2440[i] >> D0CrossSectionVsPt_Y2440U[i] >> D0CrossSectionVsPt_Y2440L[i]; 
                
    }
  
 
  TGraph *grD0CrossSectionVsPt_Y2440 = new TGraph(D0NNPt_Y2440, D0Pt_Y2440, D0CrossSectionVsPt_Y2440);
  grD0CrossSectionVsPt_Y2440->SetName("grD0CrossSectionVsPt_Y2440");
  grD0CrossSectionVsPt_Y2440->SetTitle("grD0CrossSectionVsPt_Y2440");
  grD0CrossSectionVsPt_Y2440->SetLineWidth(2);
  grD0CrossSectionVsPt_Y2440->SetLineColor(2);
  grD0CrossSectionVsPt_Y2440->GetYaxis()->SetRangeUser(0.0,1.5);
  grD0CrossSectionVsPt_Y2440->GetXaxis()->SetTitle("p_{T}^{D^{0}}(GeV/c)");
  grD0CrossSectionVsPt_Y2440->GetYaxis()->SetTitle("#frac{d#sigma^{PP}}{dp_{T}}(#mu b)");
  grD0CrossSectionVsPt_Y2440->GetYaxis()->SetTitleOffset(1.4);
  grD0CrossSectionVsPt_Y2440->GetYaxis()->SetRangeUser(0.000001,1000.0);

  TGraph *grD0CrossSectionUVsPt_Y2440 = new TGraph(D0NNPt_Y2440, D0Pt_Y2440, D0CrossSectionVsPt_Y2440U);
  grD0CrossSectionUVsPt_Y2440->SetName("grD0CrossSectionUVsPt_Y2440");
  TGraph *grD0CrossSectionLVsPt_Y2440 = new TGraph(D0NNPt_Y2440, D0Pt_Y2440, D0CrossSectionVsPt_Y2440L);
  grD0CrossSectionLVsPt_Y2440->SetName("grD0CrossSectionLVsPt_Y2440");

  
  new TCanvas;
  gPad->SetTicks();
  gPad->SetLogy(1);
  gPad->SetLeftMargin(0.18);
  grD0CrossSectionVsPt_Y2440->Draw("AC");
  grD0CrossSectionUVsPt_Y2440->Draw("Csame");
  grD0CrossSectionLVsPt_Y2440->Draw("Csame");
  tb->DrawLatex(0.27,0.20,"2.4 #leq y #leq 4");

  gPad->SaveAs("Plots/PPD0CrossSectionPPVsPt_Y2440.png");
  gPad->SaveAs("Plots/PPD0CrossSectionPPVsPt_Y2440.pdf");
  gPad->SaveAs("Plots/PPD0CrossSectionPPVsPt_Y2440.eps");



  Int_t D0NNPt_Y21 = 50;
  Double_t D0Pt_Y21[100]={0.0};
  
  Double_t D0CrossSectionVsPt_Y21[100]={0.0};
  Double_t D0CrossSectionVsPt_Y21U[100]={0.0};
  Double_t D0CrossSectionVsPt_Y21L[100]={0.0};
  
  ifstream filein12("InTextFiles/TempFiles/Temp_D0CrossSectionVsPtInRap21.txt");
  for(int i=0; i<D0NNPt_Y21; i++) 
    {
      filein12 >> D0Pt_Y21[i] >> D0CrossSectionVsPt_Y21[i] >> D0CrossSectionVsPt_Y21U[i] >> D0CrossSectionVsPt_Y21L[i]; 
                
    }
  
 
  TGraph *grD0CrossSectionVsPt_Y21 = new TGraph(D0NNPt_Y21, D0Pt_Y21, D0CrossSectionVsPt_Y21);
  grD0CrossSectionVsPt_Y21->SetName("grD0CrossSectionVsPt_Y21");
  grD0CrossSectionVsPt_Y21->SetTitle("grD0CrossSectionVsPt_Y21");
  grD0CrossSectionVsPt_Y21->SetLineWidth(2);
  grD0CrossSectionVsPt_Y21->SetLineColor(2);
  grD0CrossSectionVsPt_Y21->GetYaxis()->SetRangeUser(0.0,1.5);
  grD0CrossSectionVsPt_Y21->GetXaxis()->SetTitle("p_{T}^{D^{0}}(GeV/c)");
  grD0CrossSectionVsPt_Y21->GetYaxis()->SetTitle("#frac{d#sigma^{PP}}{dp_{T}}(#mu b)");
  grD0CrossSectionVsPt_Y21->GetYaxis()->SetTitleOffset(1.4);
  grD0CrossSectionVsPt_Y21->GetYaxis()->SetRangeUser(0.000001,1000.0);

  TGraph *grD0CrossSectionUVsPt_Y21 = new TGraph(D0NNPt_Y21, D0Pt_Y21, D0CrossSectionVsPt_Y21U);
  grD0CrossSectionUVsPt_Y21->SetName("grD0CrossSectionUVsPt_Y21");
  TGraph *grD0CrossSectionLVsPt_Y21 = new TGraph(D0NNPt_Y21, D0Pt_Y21, D0CrossSectionVsPt_Y21L);
  grD0CrossSectionLVsPt_Y21->SetName("grD0CrossSectionLVsPt_Y21");

  
  new TCanvas;
  gPad->SetTicks();
  gPad->SetLogy(1);
  gPad->SetLeftMargin(0.18);
  grD0CrossSectionVsPt_Y21->Draw("AC");
  grD0CrossSectionUVsPt_Y21->Draw("Csame");
  grD0CrossSectionLVsPt_Y21->Draw("Csame");
  tb->DrawLatex(0.27,0.20,"0 #leq y #leq 2.1");

  gPad->SaveAs("Plots/PPD0CrossSectionPPVsPt_Y21.png");
  gPad->SaveAs("Plots/PPD0CrossSectionPPVsPt_Y21.pdf");
  gPad->SaveAs("Plots/PPD0CrossSectionPPVsPt_Y21.eps");

  

  /*
  cout<<"  pp D0 cross section in pT [0.5,49.5] rapidity [0.0-1.0]: "<< IntX(0.5,49.5, grD0CrossSectionVsPt_Y1)<<" mub "<<endl;
  cout<<"  pp D0 cross section in pT [0.5,49.5] rapidity [2.4-4.0]: "<< IntX(0.5,49.5, grD0CrossSectionVsPt_Y2440)<<" mub "<<endl;
  cout<<"  pp D0 cross section in pT [0.5,49.5] rapidity [0.0-2.1]: "<< IntX(0.5,49.5, grD0CrossSectionVsPt_Y21)<<" mub "<<endl;


  
  cout<<"  pp D0 cross section in pT [0.5,49.5] rapidity [-1.0-1.0]: "<< 2.0*IntX(0.5,49.5, grD0CrossSectionVsPt_Y1)<<" mub "<<endl;
  cout<<"  pp D0 cross section in pT [0.5,49.5] rapidity [2.4-4.0]: "<< 1.0*IntX(0.5,49.5, grD0CrossSectionVsPt_Y2440)<<" mub "<<endl;
  cout<<"  pp D0 cross section in pT [0.5,49.5] rapidity [-2.1-2.1]: "<< 2.0*IntX(0.5,49.5, grD0CrossSectionVsPt_Y21)<<" mub "<<endl;
  */






  //======================== B0 Rapidity Distributions =======================//
  //B0 pp cross sections with uncertainties
  //y         dsig(cent)/dy  dsig(up)/dy  dsig(dn)/dy
  

  Int_t NNB0Rap = 10;
  Double_t B0Rap[10]={0.0};
  
  Double_t B0DSigmaPPCDy[10]={0.0};
  Double_t B0DSigmaPPUDy[10]={0.0};
  Double_t B0DSigmaPPLDy[10]={0.0};
  
  
  ifstream filein13("InTextFiles/TempFiles/Temp_B0CrossSectionVsRap.txt");
  
  for(int i=0; i<NNB0Rap; i++) 
    {
      filein13 >> B0Rap[i] >> B0DSigmaPPCDy[i] >> B0DSigmaPPUDy[i] >> B0DSigmaPPLDy[i]; 
      
    }

  Double_t B0RapBinWidth = 0.50;
  Double_t PPB0Cross =0.0;

  for(int i =0 ;i<NNB0Rap ;i++)
    {
      PPB0Cross = PPB0Cross + B0DSigmaPPCDy[i];

    }

  PPB0Cross =2.0*PPB0Cross*B0RapBinWidth;

  cout<<" pp B0 cross section in rapidity [-5.0 - 5.0]: "<<PPB0Cross<<" mub "<<endl;



  cout<<" Nbb y = [-5.0,5.0]: "<< NQQ(107.27)<<endl;
  cout<<" Nbb y = [-1.0,1.0]: "<< NQQ(38.679)<<endl;
  cout<<" Nbb y = [2.5,4.0]: "<< NQQ(10.152)<<endl;
  cout<<" Nbb y = [-2.4,2.4]: "<< NQQ(81.336)<<endl;



  TGraph *grB0DSigmaPPCDy = new TGraph(NNB0Rap, B0Rap, B0DSigmaPPCDy);
  grB0DSigmaPPCDy->SetName("grB0DSigmaPPCDy");
  grB0DSigmaPPCDy->SetTitle("grB0DSigmaPPCDy");
  grB0DSigmaPPCDy->SetLineWidth(2);
  grB0DSigmaPPCDy->SetLineColor(2);
  grB0DSigmaPPCDy->GetYaxis()->SetTitleOffset(1.8);
  grB0DSigmaPPCDy->GetYaxis()->SetRangeUser(0.0,1000.0);
  grB0DSigmaPPCDy->GetXaxis()->SetTitle("y^{B^{0}}");
  grB0DSigmaPPCDy->GetYaxis()->SetTitle("#frac{d#sigma^{PP}}{dy}(#mu b)");
  

  TGraph *grB0DSigmaPPUDy = new TGraph(NNB0Rap, B0Rap, B0DSigmaPPUDy);
  grB0DSigmaPPUDy->SetName("grB0DSigmaPPUDy");
  grB0DSigmaPPUDy->SetTitle("grB0DSigmaPPUDy");
  grB0DSigmaPPUDy->SetLineWidth(2);
  grB0DSigmaPPUDy->SetLineColor(1);
  grB0DSigmaPPUDy->GetYaxis()->SetTitleOffset(1.8);
  grB0DSigmaPPUDy->GetYaxis()->SetRangeUser(0.0,1000.0);
  grB0DSigmaPPUDy->GetXaxis()->SetTitle("y^{B^{0}}");
  grB0DSigmaPPUDy->GetYaxis()->SetTitle("#frac{d#sigma^{PP}}{dy}(#mu b)");


  TGraph *grB0DSigmaPPLDy = new TGraph(NNB0Rap, B0Rap, B0DSigmaPPLDy);
  grB0DSigmaPPLDy->SetName("grB0DSigmaPPLDy");
  grB0DSigmaPPLDy->SetTitle("grB0DSigmaPPLDy");
  grB0DSigmaPPLDy->SetLineWidth(2);
  grB0DSigmaPPLDy->SetLineColor(1);
  grB0DSigmaPPLDy->GetYaxis()->SetTitleOffset(1.8);
  grB0DSigmaPPLDy->GetYaxis()->SetRangeUser(0.0,25.0);
  grB0DSigmaPPLDy->GetXaxis()->SetTitle("y^{B^{0}}");
  grB0DSigmaPPLDy->GetYaxis()->SetTitle("#frac{d#sigma^{PP}}{dy}(#mu b)");


  new TCanvas;
  gPad->SetLeftMargin(0.20);
  gPad->SetTicks();
  grB0DSigmaPPCDy->GetYaxis()->SetRangeUser(0.0,25.0);
  grB0DSigmaPPCDy->Draw("AL");
  grB0DSigmaPPUDy->Draw("Lsame");
  grB0DSigmaPPLDy->Draw("Lsame");
  gPad->SaveAs("Plots/B0DSigmaPPDy.png");
  gPad->SaveAs("Plots/B0DSigmaPPDy.pdf");
  gPad->SaveAs("Plots/B0DSigmaPPDy.eps");




  //======================== B0 Pt Distributions =======================//
  //p_T distributions have rapidity bin width already divided out 
  //0 < y < 1
  

  //p_T  dsig(cent)/dp_T  dsig(up)/dp_T   dsig(dn)/dp_T
  
  Int_t B0NNPt_Y1 = 50;
  Double_t B0Pt_Y1[100]={0.0};
  
  Double_t B0CrossSectionVsPt_Y1[100]={0.0};
  Double_t B0CrossSectionVsPt_Y1U[100]={0.0};
  Double_t B0CrossSectionVsPt_Y1L[100]={0.0};
  
  ifstream filein14("InTextFiles/TempFiles/Temp_B0CrossSectionVsPtInRap1.txt");
  for(int i=0; i<B0NNPt_Y1; i++) 
    {
      filein14 >> B0Pt_Y1[i] >> B0CrossSectionVsPt_Y1[i] >> B0CrossSectionVsPt_Y1U[i] >> B0CrossSectionVsPt_Y1L[i]; 
                
    }
  
 
  TGraph *grB0CrossSectionVsPt_Y1 = new TGraph(B0NNPt_Y1, B0Pt_Y1, B0CrossSectionVsPt_Y1);
  grB0CrossSectionVsPt_Y1->SetName("grB0CrossSectionVsPt_Y1");
  grB0CrossSectionVsPt_Y1->SetTitle("grB0CrossSectionVsPt_Y1");
  grB0CrossSectionVsPt_Y1->SetLineWidth(2);
  grB0CrossSectionVsPt_Y1->SetLineColor(2);
  grB0CrossSectionVsPt_Y1->GetYaxis()->SetRangeUser(0.0,1.5);
  grB0CrossSectionVsPt_Y1->GetXaxis()->SetTitle("p_{T}^{B^{0}}(GeV/c)");
  grB0CrossSectionVsPt_Y1->GetYaxis()->SetTitle("#frac{d#sigma^{PP}}{dp_{T}}(#mu b)");
  grB0CrossSectionVsPt_Y1->GetYaxis()->SetTitleOffset(1.4);
  grB0CrossSectionVsPt_Y1->GetYaxis()->SetRangeUser(0.000001,1000.0);

  TGraph *grB0CrossSectionUVsPt_Y1 = new TGraph(B0NNPt_Y1, B0Pt_Y1, B0CrossSectionVsPt_Y1U);
  grB0CrossSectionUVsPt_Y1->SetName("grB0CrossSectionUVsPt_Y1");
  TGraph *grB0CrossSectionLVsPt_Y1 = new TGraph(B0NNPt_Y1, B0Pt_Y1, B0CrossSectionVsPt_Y1L);
  grB0CrossSectionLVsPt_Y1->SetName("grB0CrossSectionLVsPt_Y1");

  
  new TCanvas;
  gPad->SetTicks();
  gPad->SetLogy(1);
  gPad->SetLeftMargin(0.18);
  grB0CrossSectionVsPt_Y1->Draw("AC");
  grB0CrossSectionUVsPt_Y1->Draw("Csame");
  grB0CrossSectionLVsPt_Y1->Draw("Csame");
  tb->DrawLatex(0.27,0.20,"0 #leq y #leq 1");

  gPad->SaveAs("Plots/PPB0CrossSectionPPVsPt_Y1.png");
  gPad->SaveAs("Plots/PPB0CrossSectionPPVsPt_Y1.pdf");
  gPad->SaveAs("Plots/PPB0CrossSectionPPVsPt_Y1.eps");



  Int_t B0NNPt_Y2440 = 50;
  Double_t B0Pt_Y2440[100]={0.0};
  
  Double_t B0CrossSectionVsPt_Y2440[100]={0.0};
  Double_t B0CrossSectionVsPt_Y2440U[100]={0.0};
  Double_t B0CrossSectionVsPt_Y2440L[100]={0.0};
  
  ifstream filein15("InTextFiles/TempFiles/Temp_B0CrossSectionVsPtInRap2440.txt");
  for(int i=0; i<B0NNPt_Y2440; i++) 
    {
      filein15 >> B0Pt_Y2440[i] >> B0CrossSectionVsPt_Y2440[i] >> B0CrossSectionVsPt_Y2440U[i] >> B0CrossSectionVsPt_Y2440L[i]; 
                
    }
  
 
  TGraph *grB0CrossSectionVsPt_Y2440 = new TGraph(B0NNPt_Y2440, B0Pt_Y2440, B0CrossSectionVsPt_Y2440);
  grB0CrossSectionVsPt_Y2440->SetName("grB0CrossSectionVsPt_Y2440");
  grB0CrossSectionVsPt_Y2440->SetTitle("grB0CrossSectionVsPt_Y2440");
  grB0CrossSectionVsPt_Y2440->SetLineWidth(2);
  grB0CrossSectionVsPt_Y2440->SetLineColor(2);
  grB0CrossSectionVsPt_Y2440->GetYaxis()->SetRangeUser(0.0,1.5);
  grB0CrossSectionVsPt_Y2440->GetXaxis()->SetTitle("p_{T}^{B^{0}}(GeV/c)");
  grB0CrossSectionVsPt_Y2440->GetYaxis()->SetTitle("#frac{d#sigma^{PP}}{dp_{T}}(#mu b)");
  grB0CrossSectionVsPt_Y2440->GetYaxis()->SetTitleOffset(1.4);
  grB0CrossSectionVsPt_Y2440->GetYaxis()->SetRangeUser(0.000001,1000.0);

  TGraph *grB0CrossSectionUVsPt_Y2440 = new TGraph(B0NNPt_Y2440, B0Pt_Y2440, B0CrossSectionVsPt_Y2440U);
  grB0CrossSectionUVsPt_Y2440->SetName("grB0CrossSectionUVsPt_Y2440");
  TGraph *grB0CrossSectionLVsPt_Y2440 = new TGraph(B0NNPt_Y2440, B0Pt_Y2440, B0CrossSectionVsPt_Y2440L);
  grB0CrossSectionLVsPt_Y2440->SetName("grB0CrossSectionLVsPt_Y2440");

  
  new TCanvas;
  gPad->SetTicks();
  gPad->SetLogy(1);
  gPad->SetLeftMargin(0.18);
  grB0CrossSectionVsPt_Y2440->Draw("AC");
  grB0CrossSectionUVsPt_Y2440->Draw("Csame");
  grB0CrossSectionLVsPt_Y2440->Draw("Csame");
  tb->DrawLatex(0.27,0.20,"2.4 #leq y #leq 4");

  gPad->SaveAs("Plots/PPB0CrossSectionPPVsPt_Y2440.png");
  gPad->SaveAs("Plots/PPB0CrossSectionPPVsPt_Y2440.pdf");
  gPad->SaveAs("Plots/PPB0CrossSectionPPVsPt_Y2440.eps");



  Int_t B0NNPt_Y21 = 50;
  Double_t B0Pt_Y21[100]={0.0};
  
  Double_t B0CrossSectionVsPt_Y21[100]={0.0};
  Double_t B0CrossSectionVsPt_Y21U[100]={0.0};
  Double_t B0CrossSectionVsPt_Y21L[100]={0.0};
  
  ifstream filein16("InTextFiles/TempFiles/Temp_B0CrossSectionVsPtInRap21.txt");
  for(int i=0; i<B0NNPt_Y21; i++) 
    {
      filein16 >> B0Pt_Y21[i] >> B0CrossSectionVsPt_Y21[i] >> B0CrossSectionVsPt_Y21U[i] >> B0CrossSectionVsPt_Y21L[i]; 
                
    }
  
 
  TGraph *grB0CrossSectionVsPt_Y21 = new TGraph(B0NNPt_Y21, B0Pt_Y21, B0CrossSectionVsPt_Y21);
  grB0CrossSectionVsPt_Y21->SetName("grB0CrossSectionVsPt_Y21");
  grB0CrossSectionVsPt_Y21->SetTitle("grB0CrossSectionVsPt_Y21");
  grB0CrossSectionVsPt_Y21->SetLineWidth(2);
  grB0CrossSectionVsPt_Y21->SetLineColor(2);
  grB0CrossSectionVsPt_Y21->GetYaxis()->SetRangeUser(0.0,1.5);
  grB0CrossSectionVsPt_Y21->GetXaxis()->SetTitle("p_{T}^{B^{0}}(GeV/c)");
  grB0CrossSectionVsPt_Y21->GetYaxis()->SetTitle("#frac{d#sigma^{PP}}{dp_{T}}(#mu b)");
  grB0CrossSectionVsPt_Y21->GetYaxis()->SetTitleOffset(1.4);
  grB0CrossSectionVsPt_Y21->GetYaxis()->SetRangeUser(0.000001,1000.0);

  TGraph *grB0CrossSectionUVsPt_Y21 = new TGraph(B0NNPt_Y21, B0Pt_Y21, B0CrossSectionVsPt_Y21U);
  grB0CrossSectionUVsPt_Y21->SetName("grB0CrossSectionUVsPt_Y21");
  TGraph *grB0CrossSectionLVsPt_Y21 = new TGraph(B0NNPt_Y21, B0Pt_Y21, B0CrossSectionVsPt_Y21L);
  grB0CrossSectionLVsPt_Y21->SetName("grB0CrossSectionLVsPt_Y21");

  
  new TCanvas;
  gPad->SetTicks();
  gPad->SetLogy(1);
  gPad->SetLeftMargin(0.18);
  grB0CrossSectionVsPt_Y21->Draw("AC");
  grB0CrossSectionUVsPt_Y21->Draw("Csame");
  grB0CrossSectionLVsPt_Y21->Draw("Csame");
  tb->DrawLatex(0.27,0.20,"0 #leq y #leq 2.1");

  gPad->SaveAs("Plots/PPB0CrossSectionPPVsPt_Y21.png");
  gPad->SaveAs("Plots/PPB0CrossSectionPPVsPt_Y21.pdf");
  gPad->SaveAs("Plots/PPB0CrossSectionPPVsPt_Y21.eps");

 
  cout<<"  pp B0 cross section in pT [0.5,49.5] rapidity [0.0-1.0]: "<< 1.0*IntX(0.5,49.5, grB0CrossSectionVsPt_Y1)<<" mub "<<endl;
  cout<<"  pp B0 cross section in pT [0.5,49.5] rapidity [2.4-4.0]: "<< 1.6*IntX(0.5,49.5, grB0CrossSectionVsPt_Y2440)<<" mub "<<endl;
  cout<<"  pp B0 cross section in pT [0.5,49.5] rapidity [0.0-2.4]: "<< 2.4*IntX(0.5,49.5, grB0CrossSectionVsPt_Y21)<<" mub "<<endl;



  cout<<"  pp B0 cross section in pT [0.5,49.5] rapidity [-1.0-1.0]: "<< 2.0*IntX(0.5,49.5, grB0CrossSectionVsPt_Y1)<<" mub "<<endl;
  cout<<"  pp B0 cross section in pT [0.5,49.5] rapidity [2.4-4.0]: "<< 1.6*IntX(0.5,49.5, grB0CrossSectionVsPt_Y2440)<<" mub "<<endl;
  cout<<"  pp B0 cross section in pT [0.5,49.5] rapidity [-2.4-2.4]: "<< 4.8*IntX(0.5,49.5, grB0CrossSectionVsPt_Y21)<<" mub "<<endl;



  //============== WRITE TO FILE ==========================//
  grJPsiDSigmaPPDy->Write();
  grJPsiDSigmaAACDy->Write();
  grJPsiDSigmaAAUDy->Write();
  grJPsiDSigmaAALDy->Write();

  grPPJpsiCrossSectionVsPt_Y1->Write();
  grJpsiCrossSectionVsPt_Y1->Write();
  grJpsiCrossSectionUVsPt_Y1->Write();
  grJpsiCrossSectionLVsPt_Y1->Write();
  grPPJpsiCrossSectionVsPt_Y2440->Write();
  grJpsiCrossSectionVsPt_Y2440->Write();
  grJpsiCrossSectionUVsPt_Y2440->Write();
  grJpsiCrossSectionLVsPt_Y2440->Write();
  grPPJpsiCrossSectionVsPt_Y21->Write();
  grJpsiCrossSectionVsPt_Y21->Write();
  grJpsiCrossSectionUVsPt_Y21->Write();
  grJpsiCrossSectionLVsPt_Y21->Write();
  grUpsilonDSigmaPPDy->Write();
  grUpsilonDSigmaAACDy->Write();
  grUpsilonDSigmaAAUDy->Write();
  grUpsilonDSigmaAALDy->Write();
  grPPUpsilonCrossSectionVsPt_Y1->Write();
  grUpsilonCrossSectionVsPt_Y1->Write();
  grUpsilonCrossSectionUVsPt_Y1->Write();
  grUpsilonCrossSectionLVsPt_Y1->Write();
  grPPUpsilonCrossSectionVsPt_Y2440->Write();
  grUpsilonCrossSectionVsPt_Y2440->Write();
  grUpsilonCrossSectionUVsPt_Y2440->Write();
  grUpsilonCrossSectionLVsPt_Y2440->Write();
  grPPUpsilonCrossSectionVsPt_Y21->Write();
  grUpsilonCrossSectionVsPt_Y21->Write();
  grUpsilonCrossSectionUVsPt_Y21->Write();
  grUpsilonCrossSectionLVsPt_Y21->Write();
  grD0DSigmaPPCDy->Write();
  grD0DSigmaPPUDy->Write();
  grD0DSigmaPPLDy->Write();
  grD0CrossSectionVsPt_Y1->Write();
  grD0CrossSectionUVsPt_Y1->Write();
  grD0CrossSectionLVsPt_Y1->Write();
  grD0CrossSectionVsPt_Y2440->Write();
  grD0CrossSectionUVsPt_Y2440->Write();
  grD0CrossSectionLVsPt_Y2440->Write();
  grD0CrossSectionVsPt_Y21->Write();
  grD0CrossSectionUVsPt_Y21->Write();
  grD0CrossSectionLVsPt_Y21->Write();
  grB0DSigmaPPCDy->Write();
  grB0DSigmaPPUDy->Write();
  grB0DSigmaPPLDy->Write();
  grB0CrossSectionVsPt_Y1->Write();
  grB0CrossSectionUVsPt_Y1->Write();
  grB0CrossSectionLVsPt_Y1->Write();
  grB0CrossSectionVsPt_Y2440->Write();
  grB0CrossSectionUVsPt_Y2440->Write();
  grB0CrossSectionLVsPt_Y2440->Write();
  grB0CrossSectionVsPt_Y21->Write();
  grB0CrossSectionUVsPt_Y21->Write();
  grB0CrossSectionLVsPt_Y21->Write();
  


  OutFile->Write();
  OutFile->Close();

}



Double_t IntX( Double_t xMin, Double_t xMax, TGraph *grX)
{
  
  Int_t NNGrf = grX->GetN();
  Double_t x1[NNGrf];
  Double_t y1[NNGrf];
  
  for(int j=0; j<NNGrf;++j)
    {
      grX->GetPoint(j,x1[j],y1[j]);
    }
	
  
  Double_t xStep = TMath::Abs(x1[1]-x1[0]);
   
  //cout<<"xStep : "<<xStep<<endl;

  int NN_x = (int)((xMax-xMin)/xStep);
  Double_t sum=0;
  Double_t yy =0;
  
  for(int i=0;i<=NN_x;i++) 
    {


      Double_t x = xMin+i*xStep;

      yy=grX->Eval(x);

      //cout<<x<<"  "<<yy<<endl;

      sum = sum + yy;
    }
  
  return sum*xStep;
  
  
}
  



Double_t NQQ(Double_t Sigma)
{
  Double_t SigmaPbPbTotal = 7.65*1000000; //mub
  Double_t A = 208.0;

  Double_t N = A*A*Sigma/SigmaPbPbTotal;

  return N;


}
