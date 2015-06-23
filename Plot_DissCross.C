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

void Plot_DissCross() 

{
  
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
  

  //================================ MC Root File ================================================//
  TFile *file_Jpsi;
  file_Jpsi =new TFile("JPsiOut.root","R");
  TGraph *Jpsi =(TGraph*)file_Jpsi->Get("Graph");
  Jpsi->SetLineColor(2);
  Jpsi->SetLineStyle(2);
  Jpsi->SetLineWidth(2);


  TFile *file_Upsilon;
  file_Upsilon =new TFile("UpsilonOut.root","R");
  TGraph *Upsilon =(TGraph*)file_Upsilon->Get("Graph");
  Upsilon->SetLineColor(1);
  Upsilon->SetLineStyle(9);
  Upsilon->SetLineWidth(2);


  TLegend *lcat1;
  lcat1 = new TLegend(.49, .76, .87, .89);
 
  
  lcat1->SetBorderSize(0);
  lcat1->SetFillStyle(1001);
  lcat1->SetFillColor(10);
  lcat1-> SetTextSize(0.050);
  
  lcat1->AddEntry(Jpsi,"g+J/#psi #rightarrow c+#bar{c}", "L");
  lcat1->AddEntry(Upsilon,"g+#varUpsilon #rightarrow b+#bar{b}", "L");
 
  new TCanvas;
  Jpsi->GetXaxis()->SetTitle("gluon energy q^{0}(GeV)");
  Jpsi->GetYaxis()->SetTitle("#sigma_{D}(mb)");
  Jpsi->Draw("AL");
  Upsilon->Draw("Lsame");
  lcat1->Draw("same");

  gPad->SaveAs("SigmaDq0.pdf");
  gPad->SaveAs("SigmaDq0.png");
  gPad->SaveAs("SigmaDq0.eps");



}


