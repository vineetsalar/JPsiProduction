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

// Dynamics 
Double_t Npart(int BinLow, int BinHigh);

//============== Functions for data Graphs =================//
void Draw_CMS_JPsi_RaaVspT(TLegend *lgd);
void Draw_ALICEFor_JPsi_RaaVspT(TLegend *lgd);
void Draw_Phenix_JPsi_RaaVspT(TLegend *lgd);

void Draw_CMS_JPsi_RaaVsRap(TLegend *lgd);
void Draw_CMS_JPsi_RaaVsNpart(TLegend *lgd);
void Draw_ALICEFor_JPsi_RaaVsNpart(TLegend *lgd);  
void Draw_ALICEMid_JPsi_RaaVsNpart(TLegend *lgd);

void Draw_CMS_Y1S_RaaVsNpart(TLegend *lgd);
void Draw_CMS_Y2S_RaaVsNpart(TLegend *lgd);
void Draw_ALICEFor_Y1S_RaaVsNpart(TLegend *lgd);

void Draw_AllDataGraphs();

void AbDrawData()
{
  gStyle->SetPalette(1);
  gStyle->SetFrameBorderMode(0);
  gStyle->SetFrameFillColor(0);
  gStyle->SetCanvasColor(0);
  gStyle->SetTitleFillColor(0);
  gStyle->SetStatColor(0);
  gStyle->SetPadBorderSize(0);
  gStyle->SetCanvasBorderSize(0);
  gStyle->SetOptTitle(0); 
 
  gStyle->SetCanvasDefH(600);
  gStyle->SetCanvasDefW(600);

  gStyle->SetOptStat(1);
  gStyle->SetTitleOffset(1.7,"y");
  gStyle->SetTitleSize(0.043, "xyz");
  //gSystem->Load("DRateQuasiFree_C.so");
  //gSystem->Load("DRateQuasiFree_C.d");
  
  gStyle->SetCanvasDefH(600);
  gStyle->SetCanvasDefW(600);
  

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
  //gStyle->SetPadRightMargin(0.065);
  gStyle->SetPadLeftMargin(0.12);
  
  //gStyle->SetTitleXOffset(1.15);
  gStyle->SetTitleYOffset(1.15);

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

  //Draw_AllDataGraphs();

  TLegend *legend_ratio = new TLegend(0.13255,0.728,0.446,0.93554);
  legend_ratio->SetBorderSize(0);
  legend_ratio->SetFillStyle(0);
  legend_ratio->SetFillColor(0);
  legend_ratio->SetTextSize(0.03);
  
  new TCanvas;
  gPad->SetTickx();
  gPad->SetTicky();

  Draw_CMS_JPsi_RaaVspT(legend_ratio); 
  Draw_ALICEFor_JPsi_RaaVspT(legend_ratio);
  Draw_Phenix_JPsi_RaaVspT(legend_ratio);

  legend_ratio->Draw("Same");
  gPad->SaveAs("Raa_Pt_CMS_ALICE_PHENIX.png");
  gPad->SaveAs("Raa_Pt_CMS_ALICE_PHENIX.pdf");

  
  /*Draw_ALICEFor_JPsi_RaaVspT(TLegend *lgd);
  Draw_CMS_JPsi_RaaVsRap(TLegend *lgd);
  Draw_CMS_JPsi_RaaVsNpart(TLegend *lgd);
  Draw_ALICEFor_JPsi_RaaVsNpart(TLegend *lgd);  
  Draw_ALICEMid_JPsi_RaaVsNpart(TLegend *lgd);

  Draw_CMS_Y1S_RaaVsNpart(TLegend *lgd);
  Draw_CMS_Y2S_RaaVsNpart(TLegend *lgd);
  Draw_ALICEFor_Y1S_RaaVsNpart(TLegend *lgd); // */


  return;



}




//==================================================================================================//
//=========================== Making Functions for Data Graphs ====================================//
//=================================================================================================//

//1. CMS Raa Vs pT Data 

void Draw_CMS_JPsi_RaaVspT(TLegend *legend_ratio)
{
  
  int nbinsPtCMS=4;
  Double_t PtCMSD[4]={7.31,8.97,11.32,16.52};
  Double_t ErrPtCMS[4]={0};
  Double_t RaaPtCMS[4] = {0.35,0.34,0.34,0.29}; 
  Double_t RaaPtStatErrCMS[4] = {0.09,0.03,0.03,0.04};
  Double_t RaaPtSystErrCMS[4] = {0.04,0.04,0.03,0.03};
  
  TGraphErrors *grRaaPtCMS = new TGraphErrors(nbinsPtCMS, PtCMSD, RaaPtCMS, ErrPtCMS, RaaPtStatErrCMS);  
  grRaaPtCMS->SetMarkerStyle(21);
  grRaaPtCMS->SetMarkerColor(kRed+1);
  grRaaPtCMS->SetMarkerSize(1.3);
  //grRaaPtCMS->SetFillColor(kRed);
  grRaaPtCMS->SetLineColor(1);
  grRaaPtCMS->GetYaxis()->SetRangeUser(0,1.5);
  grRaaPtCMS->GetXaxis()->SetTitle("p_{T}(GeV/c)");
  grRaaPtCMS->GetYaxis()->SetTitle("R_{AA}");
  
  TLine *lh5 = new TLine(0.0,1.0,20.0,1.0);
  lh5->SetLineColor(1);
  lh5->SetLineStyle(1);
  lh5->SetLineWidth(1.5);
  
  TLatex *tb= new TLatex;
  tb->SetNDC(); 
  tb->SetTextAlign(12);
  tb->SetTextColor(1);
  tb->SetTextSize(0.040);
  
  TBox *RaaPtJPsiCMSSys[4];
  for(int j=0;j<4;j++){
    RaaPtJPsiCMSSys[j] = new TBox(PtCMSD[j]-0.4,  RaaPtCMS[j]-RaaPtSystErrCMS[j], PtCMSD[j]+0.4,  RaaPtCMS[j]+RaaPtSystErrCMS[j]);
  }
  
  for(int j=0;j<4;j++){
    RaaPtJPsiCMSSys[j]->SetFillStyle(1001);
    RaaPtJPsiCMSSys[j]->SetFillColor(kPink+1);
    RaaPtJPsiCMSSys[j]->SetLineColor(1);
  }
  
  TBox *CMSGlobalSysJPsiPt;
  //CMSGlobalSysJPsiPt = new TBox(27.0-1.0, 1 - 0.075, 27.0+1.0, 1 + 0.075);
  CMSGlobalSysJPsiPt = new TBox(19.165,0.923,19.948,1.067);
  CMSGlobalSysJPsiPt->SetFillStyle(3001);
  CMSGlobalSysJPsiPt->SetLineColor(2);
  CMSGlobalSysJPsiPt->SetFillColor(2);
  
  TAxis *XaxisgrRaaPtCMS = grRaaPtCMS->GetXaxis();
  XaxisgrRaaPtCMS->SetLimits(0.0,20.0);
  grRaaPtCMS->Draw("AP");
  for(int j=0;j<4;j++) RaaPtJPsiCMSSys[j]->Draw("same"); 
  grRaaPtCMS->Draw("Psame");
  CMSGlobalSysJPsiPt->Draw("same"); 
  tb->SetTextSize(0.030);
  //tb->DrawLatex(0.20,0.20,"PbPb #sqrt{s_{NN}} = 2.76 TeV");
  tb->DrawLatex(0.71476,0.91289,"J/#psi #rightarrow #mu^{+} #mu^{-}");  
  lh5->Draw("same");
  //legend_ratio->AddEntry(grRaaPtCMS,"PbPb #sqrt{s_{NN}} = 2.76 TeV and Au-Au #sqrt{s_{NN}} = 0.2 TeV", "");
  legend_ratio->AddEntry(grRaaPtCMS,"Pb+Pb #sqrt{s_{NN}} = 2.76 TeV", "");
  legend_ratio->AddEntry(grRaaPtCMS,"Prompt J/#psi CMS: |y| < 2.4", "P");

  //legend_ratio->AddEntry(grRaaPtCMS,"PbPb #sqrt{s_{NN}} = 2.76 TeV and Au-Au #sqrt{s_{NN}} = 0.2 TeV", "");
  //legend_ratio->AddEntry(grRaaPtCMS,"CMS: J/#psi #rightarrow #mu^{+} #mu^{-}, |y| < 2.4 & p_{T}^{J/#psi} > 6.5 GeV/c", "P");
  //legend_ratio->AddEntry(grRaaPtCMS,"CMS: J/#psi #rightarrow #mu^{+} #mu^{-}, |y| < 2.4 & p_{T}^{J/#psi} > 6.5 GeV/c", "P");
}


void Draw_ALICEFor_JPsi_RaaVspT(TLegend *legend_ratio)
{
  // Centrality, rapidity and transverse momentum dependence of
  // J/psi suppression in Pb-Pb collisions at sqrt{s} = 2.76 TeV ALICE
  // arxiv.1311.0214v1
  
  //================= ALICE Forward Rapidity Raa Vs Pt ===================================//
  int nbinsPtALICEFor=7;
  Double_t PtALICEFor[7]={0.50,1.50,2.50,3.50,4.50,5.50,7.0};
  Double_t ErrPtALICEFor[7]={0};

  //Double_t RaaPtALICEFor[7] = {0.61,0.53,0.45,0.38,0.37,0.34,0.35}; 
  //Double_t RaaPtStatErrALICEFor[7] = {0.06,0.04,0.03,0.04,0.05,0.06,0.07};
  //Double_t RaaPtSystErrALICEFor[7] = {0.08,0.07,0.06,0.05,0.05,0.05,0.04};


  Double_t RaaPtALICEFor[7] = {0.78,0.68,0.52,0.43,0.41,0.32,0.36}; 
  Double_t RaaPtStatErrALICEFor[7] = {0.08,0.05,0.04,0.04,0.05,0.05,0.08};
  Double_t RaaPtSystErrALICEFor[7] = {0.11,0.08,0.06,0.05,0.05,0.04,0.04};
  


  TGraphErrors *grRaaPtALICEFor = new TGraphErrors(nbinsPtALICEFor, PtALICEFor, RaaPtALICEFor, ErrPtALICEFor, RaaPtStatErrALICEFor);  
  grRaaPtALICEFor->SetMarkerStyle(20);
  grRaaPtALICEFor->SetMarkerColor(4);
  grRaaPtALICEFor->SetMarkerSize(1.3);
  grRaaPtALICEFor->SetLineColor(1);
  grRaaPtALICEFor->GetYaxis()->SetRangeUser(0,1.5);
  grRaaPtALICEFor->GetXaxis()->SetTitle("p_{T}(GeV/c)");
  grRaaPtALICEFor->GetYaxis()->SetTitle("R_{AA}");

  TLine *lh4 = new TLine(0.0,1.0,7.6,1.0);
  lh4->SetLineColor(1);
  lh4->SetLineStyle(1);
  lh4->SetLineWidth(1.5);
  //lh4->Draw("same");
  
  TLatex *tb= new TLatex;
  tb->SetNDC(); 
  tb->SetTextAlign(12);
  tb->SetTextColor(1);
  tb->SetTextSize(0.040);
  
  TBox *RaaPtJPsiALICEForSys[12];
  for(int j=0;j<7;j++){
    RaaPtJPsiALICEForSys[j] = new TBox(PtALICEFor[j]-0.4,  RaaPtALICEFor[j]-RaaPtSystErrALICEFor[j], PtALICEFor[j]+0.4,  RaaPtALICEFor[j]+RaaPtSystErrALICEFor[j]);
  }
  
  for(int j=0;j<7;j++){
    RaaPtJPsiALICEForSys[j]->SetFillStyle(1001);
    RaaPtJPsiALICEForSys[j]->SetFillColor(kAzure-4);
    RaaPtJPsiALICEForSys[j]->SetLineColor(1);
  }
  
  TBox *ALICEGlobalSysJPsiPtFor;
  //ALICEGlobalSysJPsiPtFor = new TBox(7.2-0.2, 1 - 0.14, 7.2+0.2, 1 + 0.14);
  //ALICEGlobalSysJPsiPtFor = new TBox(18.424,0.858,19.165,1.137); // By Abd
  ALICEGlobalSysJPsiPtFor = new TBox(18.424,1.0-0.08,19.165,1.0+0.08); // By Abd
  ALICEGlobalSysJPsiPtFor->SetFillStyle(3001);
  ALICEGlobalSysJPsiPtFor->SetLineColor(4);
  ALICEGlobalSysJPsiPtFor->SetFillColor(4);
  
  grRaaPtALICEFor->Draw("sameP");
  for(int j=0;j<7;j++) RaaPtJPsiALICEForSys[j]->Draw("sameL"); 
  grRaaPtALICEFor->Draw("Psame");
  ALICEGlobalSysJPsiPtFor->Draw("sameL"); 
  legend_ratio->SetTextColor(4);
  //tb->DrawLatex(0.22,0.16,"J/#psi #rightarrow #mu^{+} #mu^{-}, p_{T}^{J/#psi} > 0.0 GeV/c");  
  //legend_ratio->AddEntry(grRaaPtALICEFor,"ALICE: J/#psi #rightarrow #mu^{+} #mu^{-}, 2.5 < |y| < 2.4 & p_{T}^{J/#psi} > 0.0 GeV/c", "P");  
  legend_ratio->AddEntry(grRaaPtALICEFor,"J/#psi ALICE: 2.5 < |y| < 2.4", "P");  
}


void Draw_Phenix_JPsi_RaaVspT(TLegend *legend_ratio)
{

  //================= Phenix Forward Rapidity Raa Vs Pt ===================================//
  //r_aa at forward rapidity (|y| in [1.2,2.2])
  //"J/psi Production vs Centrality, Transverse Momentum, and Rapidity in Au+Au Collisions at s(NN)**(1/2) = 200-GeV" 
  //Preprint:   nucl-ex/0611020   inSPIRE, Citations
  //Submitted:  2006-11-12
  //Published:   Phys. Rev. Lett. 98, 232301 (2007) ,   2007-06-07

  Double_t PtPhenix[7]={0.50,1.50,2.50,3.50,4.50};
  Double_t ErrPtPhenix[7]={0};
  
  // 0-20%
  //int nbinsPtPhenix=6;
  //Double_t RaaPtPhenix[7] = {0.18,0.18,0.19,0.17,0.60,0.26}; 
  //Double_t RaaPtStatErrPhenix[7] = {0.03,0.03,0.04,0.07,0.17,0.06};
  //Double_t RaaPtSystErrPhenix[7] = {0.03,0.02,0.03,0.02,0.08,0.05};

  // 0-93%
  int nbinsPtPhenix=5;
  Double_t RaaPtPhenix[7] = {0.152,0.207,0.352,0.323,0.499}; 
  Double_t RaaPtStatErrPhenix[7] = {0.016,0.016,0.024,0.036,0.071};
  Double_t RaaPtSystErrPhenix[7] = {0.015,0.020,0.035,0.032,0.049};
  
  TGraphErrors *grRaaPtPhenix = new TGraphErrors(nbinsPtPhenix, PtPhenix, RaaPtPhenix, ErrPtPhenix, RaaPtStatErrPhenix);  
  grRaaPtPhenix->SetMarkerStyle(34);
  grRaaPtPhenix->SetMarkerColor(kGreen+2);
  grRaaPtPhenix->SetMarkerSize(1.3);
  grRaaPtPhenix->SetLineColor(1);
   
  TLine *lh4 = new TLine(0.0,1.0,7.6,1.0);
  lh4->SetLineColor(1);
  lh4->SetLineStyle(1);
  lh4->SetLineWidth(1.5);
  //lh4->Draw("same");
  
  TLatex *tb= new TLatex;
  tb->SetNDC(); 
  tb->SetTextAlign(12);
  tb->SetTextColor(1);
  tb->SetTextSize(0.040);
  
  TBox *RaaPtJPsiPhenixSys[12];
  for(int j=0;j<nbinsPtPhenix;j++){
    RaaPtJPsiPhenixSys[j] = new TBox(PtPhenix[j]-0.4,  RaaPtPhenix[j]-RaaPtSystErrPhenix[j], PtPhenix[j]+0.4,  RaaPtPhenix[j]+RaaPtSystErrPhenix[j]);
  }
  
  for(int j=0;j<nbinsPtPhenix;j++){
    RaaPtJPsiPhenixSys[j]->SetFillStyle(1001);
    RaaPtJPsiPhenixSys[j]->SetFillColor(kGreen+6);
    RaaPtJPsiPhenixSys[j]->SetLineColor(1);
  }
  
  TBox *PhenixGlobalSysJPsiPtFor;
  PhenixGlobalSysJPsiPtFor = new TBox(28.42,0.88,29.0,1.16);
  PhenixGlobalSysJPsiPtFor->SetFillStyle(3001);
  PhenixGlobalSysJPsiPtFor->SetLineColor(1);
  PhenixGlobalSysJPsiPtFor->SetFillColor(1);
  
  grRaaPtPhenix->Draw("sameP");
  for(int j=0;j<nbinsPtPhenix;j++) RaaPtJPsiPhenixSys[j]->Draw("sameL"); 
  grRaaPtPhenix->Draw("Psame");
  //PhenixGlobalSysJPsiPtFor->Draw("sameL"); 
  //tb->DrawLatex(0.22,0.16,"J/#psi #rightarrow #mu^{+} #mu^{-}, p_{T}^{J/#psi} > 0.0 GeV/c"); 
  legend_ratio->SetTextColor(1);
  //legend_ratio->AddEntry(grRaaPtPhenix,"PHENIX: J/#psi #rightarrow #mu^{+} #mu^{-}, 1.2 < |y| < 2.2 & p_{T}^{J/#psi} > 0.0 GeV/c", "P"); 
  legend_ratio->AddEntry(grRaaPtPhenix,"Au+Au #sqrt{s_{NN}} = 200 GeV,  J/#psi PHENIX: 1.2 < |y| < 2.2", "P"); 
}


void Draw_CMS_JPsi_RaaVsRap(TLegend *lgd)
{
  //=============== CMS Raa Vs Rap Data ===============================================================//
  //AvpT 10.92,9.65,8.92
  int nbinsRapCMS=3;
  Double_t RapCMSD[3]={0.6,1.4,2.0};
  Double_t ErrRapCMS[3]={0.6,0.2,0.4};
  Double_t RaaRapCMS[3] = {0.31,0.33,0.36}; 
  Double_t RaaRapStatErrCMS[3] = {0.02,0.03,0.03};
  Double_t RaaRapSystErrCMS[3] = {0.03,0.04,0.04};

  TGraphErrors *grRaaRapCMS = new TGraphErrors(nbinsRapCMS, RapCMSD, RaaRapCMS, ErrRapCMS, RaaRapStatErrCMS);  
  grRaaRapCMS->SetMarkerStyle(20);
  grRaaRapCMS->SetMarkerColor(2);
  grRaaRapCMS->GetYaxis()->SetRangeUser(0,1.5);
  grRaaRapCMS->GetXaxis()->SetTitle("|y|");
  grRaaRapCMS->GetYaxis()->SetTitle("R_{AA}");
  
  TAxis *XaxisgrRaaRapCMS = grRaaRapCMS->GetXaxis();
  XaxisgrRaaRapCMS->SetLimits(0.0,2.4);
  
  grRaaRapCMS->Draw("AP"); 

  TLine *lh_grRaaRapCMS = new TLine(0.0,1.0,2.4,1.0);
  lh_grRaaRapCMS->SetLineColor(1);
  lh_grRaaRapCMS->SetLineStyle(1);
  lh_grRaaRapCMS->SetLineWidth(1.5);
  lh_grRaaRapCMS->Draw("same");

  TLatex *tb= new TLatex;
  tb->SetNDC(); 
  tb->SetTextAlign(12);
  tb->SetTextColor(1);
  tb->SetTextSize(0.040);
  tb->DrawLatex(0.20,0.20,"Pb+Pb #sqrt{s_{NN}} = 2.76 TeV");
  tb->DrawLatex(0.20,0.15,"J/#psi #rightarrow #mu^{+} #mu^{-}, p_{T}^{J/#psi} > 6.5 GeV/c");  
  
  TBox *RaaRapJPsiCMSSys[4];
  for(int j=0;j<3;j++){
    RaaRapJPsiCMSSys[j] = new TBox(RapCMSD[j]-0.05,  RaaRapCMS[j]-RaaRapSystErrCMS[j], RapCMSD[j]+0.05,  RaaRapCMS[j]+RaaRapSystErrCMS[j]);
  }
  
  for(int j=0;j<3;j++){
    RaaRapJPsiCMSSys[j]->SetFillStyle(0000);
    RaaRapJPsiCMSSys[j]->SetLineColor(2);
    RaaRapJPsiCMSSys[j]->Draw("same"); 
  }
  
  TBox *CMSGlobalSysJPsiRap;
  CMSGlobalSysJPsiRap = new TBox(0.2-0.05, 1 - 0.05, 0.2+0.05, 1 + 0.05);
  CMSGlobalSysJPsiRap->SetFillStyle(3001);
  CMSGlobalSysJPsiRap->SetLineColor(2);
  CMSGlobalSysJPsiRap->SetFillColor(2);
  CMSGlobalSysJPsiRap->Draw("same"); 


  lgd->AddEntry(grRaaRapCMS,"CMS Data", "P");
}





void Draw_CMS_JPsi_RaaVsNpart(TLegend *lgd)
{

int nbins = 12;
  Double_t RaaCMS[20]={0.23,0.24,0.29,0.33,0.38,0.40,0.45,0.41,0.52,0.52,0.64,0.64};
  Double_t StatErrCMS[20]={0.01,0.01,0.02,0.02,0.02,0.03,0.03,0.03,0.04,0.04,0.05,0.05};
  Double_t SystErrCMS[20]={0.02,0.03,0.03,0.03,0.04,0.04,0.05,0.04,0.05,0.05,0.07,0.13};
  Double_t NPartCMS[20]={Npart(0,2),Npart(2,4),Npart(4,6),Npart(6,8),Npart(8,10),Npart(10,12),
			 Npart(12,14),Npart(14,16),Npart(16,18),Npart(18,20),Npart(20,24),
			 Npart(24,40)};
  Double_t ErrNPartCMS[20]={0};
  
  TGraphErrors *grRaaCMS = new TGraphErrors(nbins, NPartCMS, RaaCMS, ErrNPartCMS, StatErrCMS);  
  grRaaCMS->SetMarkerStyle(21);
  grRaaCMS->SetMarkerColor(2);
  grRaaCMS->GetYaxis()->SetRangeUser(0,1.7);
  grRaaCMS->GetXaxis()->SetTitle("N_{Part}");
  grRaaCMS->GetYaxis()->SetTitle("R_{AA}");
  
  grRaaCMS->Draw("AP");
  TBox *RaaJPsiSys[12];
  for(int j=0;j<12;j++){
    RaaJPsiSys[j] = new TBox(NPartCMS[j]-3,  RaaCMS[j]-SystErrCMS[j], NPartCMS[j]+3, RaaCMS[j]+SystErrCMS[j]);
  }
  
  for(int j=0;j<12;j++){
    RaaJPsiSys[j]->SetFillStyle(0000);
    RaaJPsiSys[j]->SetLineColor(6);
    RaaJPsiSys[j]->Draw("same"); 
  }
  
  TLine *lh2 = new TLine(0.0,1.0,400,1.0);
  lh2->SetLineColor(1);
  lh2->SetLineStyle(1);
  lh2->SetLineWidth(2);
  lh2->Draw("same");
  
  TBox *GlobalSysJPsi;
  GlobalSysJPsi = new TBox(400-5, 1 - 0.06, 400+5, 1 + 0.06);
  GlobalSysJPsi->SetFillStyle(3001);
  GlobalSysJPsi->SetLineColor(6);
  GlobalSysJPsi->SetFillColor(6);
  GlobalSysJPsi->Draw("same"); 
  
  TLatex *tb= new TLatex;
  tb->SetNDC(); 
  tb->SetTextAlign(12);
  tb->SetTextColor(1);
  tb->SetTextSize(0.040);
  tb->DrawLatex(0.17,0.23,"PbPb #sqrt{s_{NN}} = 2.76 TeV");
  tb->DrawLatex(0.17,0.17,"p_{T}^{J/#psi} > 6.5 GeV/c");

  lgd->AddEntry(grRaaCMS,"CMS Data", "P");

}



void Draw_ALICEFor_JPsi_RaaVsNpart(TLegend *lgd)
{
  int nbinsALICE=9;
  Double_t NPartALICE[10]={357,262,187,128,86,53,30,16,8};
  Double_t ErrNPartALICE[10]={0};
  Double_t RaaALICE[10] = {0.47,0.48,0.51,0.51,0.52,0.61,0.70,0.74,0.94}; 
  Double_t SystErrALICE[10] = {0.03,0.02,0.02,0.02,0.03,0.05,0.06,0.09,0.1};
  
  TGraphErrors *grRaaALICE = new TGraphErrors(nbinsALICE, NPartALICE, RaaALICE, ErrNPartALICE, SystErrALICE);  
  grRaaALICE->SetMarkerStyle(20);
  grRaaALICE->SetMarkerColor(4);
  grRaaALICE->GetYaxis()->SetRangeUser(0,1.7);
  
  TAxis *Xaxis2 = grRaaALICE->GetXaxis();
  Xaxis2->SetLimits(0.,430.0);
  
  grRaaALICE->GetXaxis()->SetTitle("N_{Part}");
  grRaaALICE->GetYaxis()->SetTitle("R_{AA}");

  grRaaALICE->Draw("AP");
 
  TLine *lh3 = new TLine(0.0,1.0,420,1.0);
  lh3->SetLineColor(1);
  lh3->SetLineStyle(1);
  lh3->SetLineWidth(1.5);
  lh3->Draw("same");
 
  //TLatex *tb= new TLatex;
  //tb->SetNDC(); 
  //tb->SetTextAlign(12);
  //tb->SetTextColor(1);
  //tb->SetTextSize(0.040);
  //tb->DrawLatex(0.22,0.22,"PbPb #sqrt{s_{NN}} = 2.76 TeV");
  //tb->DrawLatex(0.22,0.16,"J/#psi #rightarrow #mu^{+} #mu^{-}, p_{T}^{J/#psi} > 0.0 GeV/c");  
   
  
  TBox *RaaJPsiALICESys[12];
  for(int j=0;j<9;j++){
    RaaJPsiALICESys[j] = new TBox(NPartALICE[j]-3,  RaaALICE[j]-SystErrALICE[j], NPartALICE[j]+3, RaaALICE[j]+SystErrALICE[j]);
  }
  
  for(int j=0;j<9;j++){
    RaaJPsiALICESys[j]->SetFillStyle(0000);
    RaaJPsiALICESys[j]->SetLineColor(4);
    RaaJPsiALICESys[j]->Draw("same"); 
  }
  
  TBox *ALICEGlobalSysJPsi;
  ALICEGlobalSysJPsi = new TBox(400-5, 1 - 0.14, 400+5, 1 + 0.14);
  ALICEGlobalSysJPsi->SetFillStyle(3001);
  ALICEGlobalSysJPsi->SetLineColor(4);
  ALICEGlobalSysJPsi->SetFillColor(4);
  ALICEGlobalSysJPsi->Draw("same"); 

  Draw_ALICEMid_JPsi_RaaVsNpart(lgd);

  lgd->AddEntry(grRaaALICE,"ALICE Data p_{T}^{J/#psi} > 0.0 GeV/c, 2.5 #leq y^{J/#psi} #leq 4.0","P");

}



void Draw_ALICEMid_JPsi_RaaVsNpart(TLegend *lgd)
{
  //ALICE MID rapidity
  int nbinsALICEMid=3;
  Double_t NPartALICEMid[3]={357,193,46};
  Double_t ErrNPartALICEMid[3]={0};
  Double_t RaaALICEMid[3] = {0.82,0.65,0.73}; 
  Double_t SystErrALICEMid[3] = {0.15,0.10,0.16};
  
  TGraphErrors *grRaaALICEMid = new TGraphErrors(nbinsALICEMid, NPartALICEMid, RaaALICEMid, ErrNPartALICEMid, SystErrALICEMid);  
  grRaaALICEMid->SetMarkerStyle(20);
  grRaaALICEMid->SetMarkerColor(2);
  //grRaaALICEMid->SetLineColor(2);
  grRaaALICEMid->GetYaxis()->SetRangeUser(0,1.5);
  
  TAxis *Xaxis = grRaaALICEMid->GetXaxis();
  Xaxis->SetLimits(0.,430.0);
  grRaaALICEMid->GetXaxis()->SetTitle("N_{Part}");
  grRaaALICEMid->GetYaxis()->SetTitle("R_{AA}");
  
  grRaaALICEMid->Draw("Psame");
  
  //TLatex *tb= new TLatex;
  //tb->SetNDC(); 
  //tb->SetTextAlign(12);
  //tb->SetTextColor(1);
  //tb->SetTextSize(0.040);
  //tb->DrawLatex(0.55,0.90,"PbPb #sqrt{s_{NN}} = 2.76 TeV");
  //tb->DrawLatex(0.22,0.16,"J/#psi #rightarrow #mu^{+} #mu^{-}, p_{T}^{J/#psi} > 0.0 GeV/c");  
  //tb->DrawLatex(0.55,0.85,"p_{T}^{J/#psi} > 0.0 GeV/c");  
  
  TLine *lh3 = new TLine(0.0,1.0,420,1.0);
  lh3->SetLineColor(1);
  lh3->SetLineStyle(1);
  lh3->SetLineWidth(1.5);
  lh3->Draw("same");
    
  TBox *RaaJPsiALICEMidSys[12];
  for(int j=0;j<3;j++){
    RaaJPsiALICEMidSys[j] = new TBox(NPartALICEMid[j]-3,  RaaALICEMid[j]-SystErrALICEMid[j], NPartALICEMid[j]+3, RaaALICEMid[j]+SystErrALICEMid[j]);
  }
  
  for(int j=0;j<3;j++){
    RaaJPsiALICEMidSys[j]->SetFillStyle(0000);
    RaaJPsiALICEMidSys[j]->SetLineColor(2);
    RaaJPsiALICEMidSys[j]->Draw("same"); 
  }
  
  TBox *ALICEMidGlobalSysJPsi;
  ALICEMidGlobalSysJPsi = new TBox(385-5, 1 - 0.26, 385+5, 1 + 0.26);
  
  ALICEMidGlobalSysJPsi->SetFillStyle(3001);
  ALICEMidGlobalSysJPsi->SetLineColor(2);
  ALICEMidGlobalSysJPsi->SetFillColor(2);
  ALICEMidGlobalSysJPsi->Draw("same"); 

  lgd->AddEntry(grRaaALICEMid,"ALICE Data p_{T}^{J/#psi} > 0.0 GeV/c, |y^{J/#psi}| #leq 1.0","P");
  
}

void Draw_CMS_Y1S_RaaVsNpart(TLegend *lgd)
{

  double ErNPartCMS[7]={0};
  double NPartCMSD[7]={Npart(0,2),Npart(2,4),Npart(4,8),Npart(8,12),Npart(12,16),Npart(16,20),Npart(20,40)}; 
  double RaaCMS1Sdata[7] = {0.41,0.43,0.48,0.61,0.68,0.59,1.01};
  double ErRaaCMS1Sdata[7] = {0.04,0.05,0.04,0.05,0.07,0.10,0.12};
  double ErSysRaaCMS1Sdata[7] = {0.05,0.05,0.05,0.07,0.08,0.08,0.17};
  
  TGraphErrors *RaaYCMS1Sdata = new TGraphErrors(7,NPartCMSD,RaaCMS1Sdata,ErNPartCMS,ErRaaCMS1Sdata);
  RaaYCMS1Sdata->SetMarkerStyle(21);
  RaaYCMS1Sdata->SetMarkerColor(kRed+0);
  RaaYCMS1Sdata->SetMarkerSize(1.2);
  RaaYCMS1Sdata->GetYaxis()->SetRangeUser(0.0,1.7);
  RaaYCMS1Sdata->GetXaxis()->SetTitle("N_{part}");
  RaaYCMS1Sdata->GetYaxis()->SetTitle("R_{AA}");
  RaaYCMS1Sdata->Draw("AP");
  
  
  TBox *RaaCMS1SSys[10];
  for(int j=0;j<7;j++){
    RaaCMS1SSys[j] = new TBox(NPartCMSD[j]-3,RaaCMS1Sdata[j]-ErSysRaaCMS1Sdata[j],NPartCMSD[j]+3,RaaCMS1Sdata[j]+ErSysRaaCMS1Sdata[j]);
  }
  
  for(int j=0;j<7;j++){
    RaaCMS1SSys[j]->SetFillStyle(0000);
    RaaCMS1SSys[j]->SetLineColor(6);
    RaaCMS1SSys[j]->Draw("same"); 
  }
    
  TLine *lh = new TLine(0.0,1.0,400,1.0);
  lh->SetLineColor(1);
  lh->SetLineStyle(1);
  lh->SetLineWidth(1.5);
  lh->Draw("same");
  
  TBox *GlobalSys1;
  GlobalSys1 = new TBox(400-5, 1 - 0.215, 400+5, 1 + 0.215);
  GlobalSys1->SetFillStyle(0000);
  GlobalSys1->SetLineColor(3);
  GlobalSys1->Draw("same"); 
  
  TBox *GlobalSys2;
  GlobalSys2 = new TBox(390-5, 1 - 0.125, 390+5, 1 + 0.125);
  GlobalSys2->SetFillStyle(3001);
  GlobalSys2->SetFillColor(6);
  GlobalSys2->SetLineColor(6);
  GlobalSys2->Draw("same"); 
  
  
  TLatex *tb= new TLatex;
  tb->SetNDC(); 
  tb->SetTextAlign(12);
  tb->SetTextColor(1);
  tb->SetTextSize(0.040);
  tb->DrawLatex(0.21,0.30,"PbPb #sqrt{s_{NN}} = 2.76 TeV");
  tb->DrawLatex(0.21,0.24,"#varUpsilon(1S) #rightarrow #mu^{+} #mu^{-}");
  
  lgd->AddEntry(RaaYCMS1Sdata,"CMS Data", "P");
  Draw_ALICEFor_Y1S_RaaVsNpart(lgd);
  
}

//void Draw_ALICEFor_Y1S_RaaVsNpart(TLegend *lgd)
void Draw_CMS_Y2S_RaaVsNpart(TLegend *lgd)
{
  double ErNPartCMS[7]={0};
  double NPartCMSD[7]={Npart(0,2),Npart(2,4),Npart(4,8),Npart(8,12),Npart(12,16),Npart(16,20),Npart(20,40)};
  double RaaCMS2Sdata[7] = {0.11,0.04,0.07,0.26,0.24,0.25,0.30};
  double ErRaaCMS2Sdata[7] = {0.06,0.06,0.05,0.08,0.1,0.14,0.16};
  double ErSysRaaCMS2Sdata[7] = {0.02,0.02,0.02,0.04,0.04,0.05,0.07};
  
  TGraphErrors *RaaYCMS2Sdata = new TGraphErrors(7,NPartCMSD,RaaCMS2Sdata,ErNPartCMS,ErRaaCMS2Sdata);
  RaaYCMS2Sdata->SetMarkerStyle(21);
  RaaYCMS2Sdata->SetMarkerColor(kRed+0);
  RaaYCMS2Sdata->SetMarkerSize(1.2);
  RaaYCMS2Sdata->GetYaxis()->SetRangeUser(0.0,1.7);
  RaaYCMS2Sdata->GetXaxis()->SetTitle("N_{part}");
  RaaYCMS2Sdata->GetYaxis()->SetTitle("R_{AA}");
  
  RaaYCMS2Sdata->Draw("AP");
  
  TBox *RaaCMS2SSys[10];
  for(int j=0;j<7;j++){
    if(j<7){
      RaaCMS2SSys[j] = new TBox(NPartCMSD[j]-3,RaaCMS2Sdata[j]-ErSysRaaCMS2Sdata[j],NPartCMSD[j]+3,RaaCMS2Sdata[j]+ErSysRaaCMS2Sdata[j]);
    }
  }
    
  for(int j=0;j<7;j++){
    RaaCMS2SSys[j]->SetFillStyle(0000);
    RaaCMS2SSys[j]->SetLineColor(6);
    RaaCMS2SSys[j]->Draw("same"); 
  }
  

  TLine *lh = new TLine(0.0,1.0,400,1.0);
  lh->SetLineColor(1);
  lh->SetLineStyle(1);
  lh->SetLineWidth(1.5);
  lh->Draw("same");
  
  TBox *GlobalSys1;
  GlobalSys1 = new TBox(400-5, 1 - 0.215, 400+5, 1 + 0.215);
  GlobalSys1->SetFillStyle(0000);
  GlobalSys1->SetLineColor(3);
  GlobalSys1->Draw("same"); 
  
  TBox *GlobalSys2;
  GlobalSys2 = new TBox(390-5, 1 - 0.125, 390+5, 1 + 0.125);
  GlobalSys2->SetFillStyle(3001);
  GlobalSys2->SetFillColor(6);
  GlobalSys2->SetLineColor(6);
  GlobalSys2->Draw("same"); 

  TLatex *tb= new TLatex;
  tb->SetNDC(); 
  tb->SetTextAlign(12);
  tb->SetTextColor(1);
  tb->SetTextSize(0.040);
  //tb->DrawLatex(0.21,0.30,"PbPb #sqrt{s_{NN}} = 2.76 TeV");
  //tb->DrawLatex(0.21,0.24,"#varUpsilon(2S) #rightarrow #mu^{+} #mu^{-}");
 
  lgd->AddEntry(RaaYCMS2Sdata,"CMS Data", "P");

}
 
void Draw_ALICEFor_Y1S_RaaVsNpart(TLegend *lgd)
{
  double ErNPartALICE[2]={0};
  double NPartALICED[2]={76.0,310.0};
  double RaaALICE1Sdata[2] = {0.63,0.34};
  double ErRaaALICE1Sdata[2] = {0.11,0.07};
  double ErSys1RaaALICE1Sdata[2] = {0.05,0.03};
  //box asymetric
  double ErSys2RaaALICE1Sdata[4] = {0.1,0.14,0.05,0.07};
  TGraphErrors *RaaYALICE1Sdata = new TGraphErrors(2,NPartALICED,RaaALICE1Sdata,ErNPartALICE,ErRaaALICE1Sdata);
  RaaYALICE1Sdata->SetMarkerStyle(20);
  RaaYALICE1Sdata->SetMarkerColor(4);
  RaaYALICE1Sdata->SetMarkerSize(1.2);
  RaaYALICE1Sdata->GetYaxis()->SetRangeUser(0.0,1.5);
  RaaYALICE1Sdata->GetXaxis()->SetTitle("N_{part}");
  RaaYALICE1Sdata->GetYaxis()->SetTitle("R_{AA}");
  TAxis *XAxis_RaaYALICE1Sdata=RaaYALICE1Sdata->GetXaxis();
  XAxis_RaaYALICE1Sdata->SetLimits(0.0,350);
  XAxis_RaaYALICE1Sdata->Draw();
 
  RaaYALICE1Sdata->Draw("Psame");
  
  TBox *RaaALICE1SSys1[10];
  for(int j=0;j<2;j++){
    RaaALICE1SSys1[j] = new TBox(NPartALICED[j]-3,RaaALICE1Sdata[j]-ErSys1RaaALICE1Sdata[j],NPartALICED[j]+3,RaaALICE1Sdata[j]+ErSys1RaaALICE1Sdata[j]);
  }
  
  for(int j=0;j<2;j++){
    RaaALICE1SSys1[j]->SetFillStyle(3001);
    RaaALICE1SSys1[j]->SetLineColor(2);
    RaaALICE1SSys1[j]->Draw("same"); 
  }
  
  
  TBox *RaaALICE1SSys2[10];
  
  RaaALICE1SSys2[0] = new TBox(NPartALICED[0]-4,RaaALICE1Sdata[0]-ErSys2RaaALICE1Sdata[0],NPartALICED[0]+4,RaaALICE1Sdata[0]+ErSys2RaaALICE1Sdata[1]);
  RaaALICE1SSys2[1] = new TBox(NPartALICED[1]-4,RaaALICE1Sdata[1]-ErSys2RaaALICE1Sdata[2],NPartALICED[1]+4,RaaALICE1Sdata[1]+ErSys2RaaALICE1Sdata[3]);
  
  
  for(int j=0;j<2;j++){
    RaaALICE1SSys2[j]->SetFillStyle(0000);
    RaaALICE1SSys2[j]->SetLineColor(4);
    RaaALICE1SSys2[j]->Draw("same"); 
  }
    
  TLine *lhALICE1S = new TLine(0.0,1.0,350,1.0);
  lhALICE1S->SetLineColor(1);
  lhALICE1S->SetLineStyle(1);
  lhALICE1S->SetLineWidth(1.5);
  lhALICE1S->Draw("same");
  
  lgd->AddEntry(RaaYALICE1Sdata,"ALICE Data", "P");

}


void Draw_AllDataGraphs()
{
 
  TLegend *legend_ratio = new TLegend(0.1677852,0.6689895,0.4966443,0.8501742);
  legend_ratio->SetBorderSize(0);
  legend_ratio->SetFillStyle(0);
  legend_ratio->SetFillColor(0);
  legend_ratio->SetTextSize(0.03);

  new TCanvas;
  gPad->SetTickx();
  gPad->SetTicky();
  //Draw_CMS_JPsi_RaaVsNpart(legend_ratio);
  //Draw_CMS_JPsi_RaaVspT(legend_ratio);
  //legend_ratio->Draw("same");

}

/*  
  new TCanvas;
  gPad->SetTickx();
  gPad->SetTicky();
  Draw_ALICEFor_JPsi_RaaVsNpart(legend_ratio);  
  legend_ratio->Draw("same");

  
  
  new TCanvas;
  gPad->SetTickx();
  gPad->SetTicky();
  Draw_CMS_JPsi_RaaVspT(legend_ratio);
  legend_ratio->Draw("same");

  new TCanvas;
  gPad->SetTickx();
  gPad->SetTicky();
  Draw_ALICEFor_JPsi_RaaVspT(legend_ratio);
  legend_ratio->Draw("same");
  
  new TCanvas;
  gPad->SetTickx();
  gPad->SetTicky();
  Draw_CMS_JPsi_RaaVsRap(legend_ratio);
  legend_ratio->Draw("same");
  
  new TCanvas;
  gPad->SetTickx();
  gPad->SetTicky();
  Draw_ALICEMid_JPsi_RaaVsNpart(legend_ratio);  
  legend_ratio->Draw("same");


  new TCanvas;
  gPad->SetTickx();
  gPad->SetTicky();
  Draw_CMS_Y1S_RaaVsNpart(legend_ratio);  
  legend_ratio->Draw("same");


  new TCanvas;
  gPad->SetTickx();
  gPad->SetTicky();
  Draw_CMS_Y2S_RaaVsNpart(legend_ratio);  
  legend_ratio->Draw("same");

  new TCanvas;
  gPad->SetTickx();
  gPad->SetTicky();
  Draw_ALICEFor_Y1S_RaaVsNpart(legend_ratio);  
  legend_ratio->Draw("same");
   
}
*/

//////////////////////////////////////////////////////////////////////////////////////////////////
Double_t Npart(int BinLow, int BinHigh)
{
  Double_t NpartArray[40]={393.622,368.96,342.32,316.49,293.49,271.98,249.65,230.53,212.28,194.50,178.54,
			 163.25,149.05,135.92,123.28,111.67,100.79,90.71,80.93,72.60,64.15,56.61,49.95,
			 43.39,37.83,32.70,27.86,23.79,20.20,16.85,14.04,11.60,9.55,7.72,6.44,4.96,4.22,
			 3.50,3.17,2.79};
  Double_t sum=0;
  for(int i=BinLow;i<BinHigh;i++){
    sum+=NpartArray[i];
  }
  Double_t NPart = sum/(BinHigh-BinLow);
  return NPart;
}
