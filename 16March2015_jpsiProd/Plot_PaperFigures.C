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

//============== Functions for data Graphs =================//
void Draw_CMS_JPsi_RaaVspT(TLegend *lgd);
void Draw_ALICEFor_JPsi_RaaVspT(TLegend *lgd);
void Draw_ALICEFor_JPsi_RaaVspT_InMostCentral(TLegend *lgd);
void Draw_CMS_JPsi_RaaVsRap(TLegend *lgd);
void Draw_CMS_JPsi_RaaVsNpart(TLegend *lgd);
void Draw_ALICEFor_JPsi_RaaVsNpart(TLegend *lgd);  
void Draw_ALICEMid_JPsi_RaaVsNpart(TLegend *lgd);
void Draw_CMS_Y1S_RaaVsNpart(TLegend *lgd);
void Draw_CMS_Y2S_RaaVsNpart(TLegend *lgd);
void Draw_ALICEFor_Y1S_RaaVsNpart(TLegend *lgd);
void Draw_CMS_Y1S_RaaVspT(TLegend *lgd);
void Draw_AllDataGraphs();

Double_t Npart(int BinLow, int BinHigh);
Double_t NColl(int BinLow, int BinHigh);

void Plot_PaperFigures() 

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
  gStyle->SetMarkerSize(1.3);

  gROOT->ForceStyle();
  

  TLegend *legd0 = new TLegend(0.16,0.64,0.97,0.93);
  legd0->SetBorderSize(0);
  legd0->SetFillStyle(0);
  legd0->SetFillColor(0);
  legd0->SetTextSize(0.040);
  


  new TCanvas;
  gPad->SetTickx();
  gPad->SetTicky();
  //Draw_ALICEFor_JPsi_RaaVsNpart(legd0);  
  //Draw_CMS_JPsi_RaaVsNpart(legd0);
  Draw_CMS_Y1S_RaaVsNpart(legd0);
  legd0->Draw("same");
  gPad->SaveAs("Y1SRAAVsNPart_ALICEAndCMS.png");
  gPad->SaveAs("Y1SRAAVsNPart_ALICEAndCMS.eps");
  

  //  Draw_AllDataGraphs();
  
  //return;




  //================================ Open Chic Root File ================================================//
  TFile *file_ChiC = new TFile("05052014_ChiCCalculations.root","R");
  

  // ====== Event Variable Graphs  ==============================//
  
  TGraph *ChiC_grTempVsTauL =(TGraph*)file_ChiC->Get("grTempVsTauL");
  ChiC_grTempVsTauL->SetLineColor(2);
  ChiC_grTempVsTauL->SetLineStyle(1);
  ChiC_grTempVsTauL->SetLineWidth(2);
  
  TGraph *ChiC_grTempVsTauC =(TGraph*)file_ChiC->Get("grTempVsTauC");
  ChiC_grTempVsTauC->SetLineColor(4);
  ChiC_grTempVsTauC->SetLineStyle(2);
  ChiC_grTempVsTauC->SetLineWidth(2);
  
  
  TGraph *ChiC_grFQGPVsTauL =(TGraph*)file_ChiC->Get("grFQGPVsTauL");
  ChiC_grFQGPVsTauL->SetLineColor(2);
  ChiC_grFQGPVsTauL->SetLineStyle(1);
  ChiC_grFQGPVsTauL->SetLineWidth(2);
  
  
  TGraph *ChiC_grFQGPVsTauC =(TGraph*)file_ChiC->Get("grFQGPVsTauC");
  ChiC_grFQGPVsTauC->SetLineColor(4);
  ChiC_grFQGPVsTauC->SetLineStyle(2);
  ChiC_grFQGPVsTauC->SetLineWidth(2);
  

  
  // ====== Cross Section graphs ==============================//
  TGraph *ChiC_grSigDQ0 =(TGraph*)file_ChiC->Get("grSigDQ0");
  ChiC_grSigDQ0->SetLineColor(2);
  ChiC_grSigDQ0->SetLineStyle(1);
  ChiC_grSigDQ0->SetLineWidth(2);
  
  TGraph *ChiC_grSigDS =(TGraph*)file_ChiC->Get("grSigD");
  ChiC_grSigDS->SetLineColor(2);
  ChiC_grSigDS->SetLineStyle(1);
  ChiC_grSigDS->SetLineWidth(2);
  
  TGraph *ChiC_grSigFS =(TGraph*)file_ChiC->Get("grSigF");
  ChiC_grSigFS->SetLineColor(4);
  ChiC_grSigFS->SetLineStyle(2);
  ChiC_grSigFS->SetLineWidth(2);
  
  

  // ====== Dissociation rate graphs ==============================//
  
  
  TGraph *ChiC_DissRateVsT_KharPt0 =(TGraph*)file_ChiC->Get("DissRateVsT_KharPt0");
  ChiC_DissRateVsT_KharPt0->SetLineColor(1);
  ChiC_DissRateVsT_KharPt0->SetLineStyle(1);
  ChiC_DissRateVsT_KharPt0->SetLineWidth(2);
  
  TGraph *ChiC_DissRateVsT_KharPt36 =(TGraph*)file_ChiC->Get("DissRateVsT_KharPt36");
  ChiC_DissRateVsT_KharPt36->SetLineColor(4);
  ChiC_DissRateVsT_KharPt36->SetLineStyle(4);
  ChiC_DissRateVsT_KharPt36->SetLineWidth(2);
  
  
  TGraph *ChiC_DissRateVsT_KharPt86 =(TGraph*)file_ChiC->Get("DissRateVsT_KharPt86");
  ChiC_DissRateVsT_KharPt86->SetLineColor(2);
  ChiC_DissRateVsT_KharPt86->SetLineStyle(2);
  ChiC_DissRateVsT_KharPt86->SetLineWidth(2);
  
  
  
  TGraph *ChiC_grDissRateVsPt_T200 =(TGraph*)file_ChiC->Get("grDissRateVsPt_T200");
  ChiC_grDissRateVsPt_T200->SetLineColor(1);
  ChiC_grDissRateVsPt_T200->SetLineStyle(1);
  ChiC_grDissRateVsPt_T200->SetLineWidth(2);
  
  
  TGraph *ChiC_grDissRateVsPt_T400 =(TGraph*)file_ChiC->Get("grDissRateVsPt_T400");
  ChiC_grDissRateVsPt_T400->SetLineColor(4);
  ChiC_grDissRateVsPt_T400->SetLineStyle(4);
  ChiC_grDissRateVsPt_T400->SetLineWidth(2);
  
  TGraph *ChiC_grDissRateVsPt_T600 =(TGraph*)file_ChiC->Get("grDissRateVsPt_T600");
  ChiC_grDissRateVsPt_T600->SetLineColor(2);
  ChiC_grDissRateVsPt_T600->SetLineStyle(2);
  ChiC_grDissRateVsPt_T600->SetLineWidth(2);

  
  
  // ====== Formation rate graphs ==============================//

  TGraph *ChiC_grFormRateVsT_MCInt_P1 =(TGraph*)file_ChiC->Get("grFormRateVsT_MCInt_P1");
  ChiC_grFormRateVsT_MCInt_P1->SetLineColor(1);
  ChiC_grFormRateVsT_MCInt_P1->SetLineStyle(1);
  ChiC_grFormRateVsT_MCInt_P1->SetLineWidth(2);
  
  
  TGraph *ChiC_grFormRateVsT_MCInt_P2 =(TGraph*)file_ChiC->Get("grFormRateVsT_MCInt_P2");
  ChiC_grFormRateVsT_MCInt_P2->SetLineColor(4);
  ChiC_grFormRateVsT_MCInt_P2->SetLineStyle(4);
  ChiC_grFormRateVsT_MCInt_P2->SetLineWidth(2);
  
  
  TGraph *ChiC_grFormRateVsT_MCInt_P3 =(TGraph*)file_ChiC->Get("grFormRateVsT_MCInt_P3");
  ChiC_grFormRateVsT_MCInt_P3->SetLineColor(2);
  ChiC_grFormRateVsT_MCInt_P3->SetLineStyle(2);
  ChiC_grFormRateVsT_MCInt_P3->SetLineWidth(2);
  

  
  TGraph *ChiC_grFormRateVsP_MCInt_T1 =(TGraph*)file_ChiC->Get("grFormRateVsP_MCInt_T1");
  ChiC_grFormRateVsP_MCInt_T1->SetLineColor(1);
  ChiC_grFormRateVsP_MCInt_T1->SetLineStyle(1);
  ChiC_grFormRateVsP_MCInt_T1->SetLineWidth(2);
  
  TGraph *ChiC_grFormRateVsP_MCInt_T2 =(TGraph*)file_ChiC->Get("grFormRateVsP_MCInt_T2");
  ChiC_grFormRateVsP_MCInt_T2->SetLineColor(4);
  ChiC_grFormRateVsP_MCInt_T2->SetLineStyle(4);
  ChiC_grFormRateVsP_MCInt_T2->SetLineWidth(2);

  TGraph *ChiC_grFormRateVsP_MCInt_T3 =(TGraph*)file_ChiC->Get("grFormRateVsP_MCInt_T3");
  ChiC_grFormRateVsP_MCInt_T3->SetLineColor(2);
  ChiC_grFormRateVsP_MCInt_T3->SetLineStyle(2);
  ChiC_grFormRateVsP_MCInt_T3->SetLineWidth(2);
  

  //============================ RAA Graphs =======================//
  
  
 //============================ ALICE RAA Vs Pt Graphs =======================//
  
  TGraph *ChiC_grGluonDissALICEPt_M =(TGraph*)file_ChiC->Get("grGluonDissALICEPt_M");
  ChiC_grGluonDissALICEPt_M->SetLineColor(2);
  ChiC_grGluonDissALICEPt_M->SetLineStyle(2);
  ChiC_grGluonDissALICEPt_M->SetLineWidth(2);

  
  TGraph *ChiC_grPionDissALICEPt_M =(TGraph*)file_ChiC->Get("grPionDissALICEPt_M");
  ChiC_grPionDissALICEPt_M->SetLineColor(4);
  ChiC_grPionDissALICEPt_M->SetLineStyle(4);
  ChiC_grPionDissALICEPt_M->SetLineWidth(2);


  TGraph *ChiC_grRegenALICEPt_M =(TGraph*)file_ChiC->Get("grRegenALICEPt_M");
  ChiC_grRegenALICEPt_M->SetLineColor(8);
  ChiC_grRegenALICEPt_M->SetLineStyle(9);
  ChiC_grRegenALICEPt_M->SetLineWidth(2);



  TGraph *ChiC_grRAAALICEPt_M =(TGraph*)file_ChiC->Get("grRAAALICEPt_M");
  ChiC_grRAAALICEPt_M->SetLineColor(1);
  ChiC_grRAAALICEPt_M->SetLineStyle(1);
  ChiC_grRAAALICEPt_M->SetLineWidth(2);


 //============================ CMS RAA Vs Pt Graphs =======================//

  TGraph *ChiC_grGluonDissCMSPt_M =(TGraph*)file_ChiC->Get("grGluonDissCMSPt_M");
  ChiC_grGluonDissCMSPt_M->SetLineColor(2);
  ChiC_grGluonDissCMSPt_M->SetLineStyle(2);
  ChiC_grGluonDissCMSPt_M->SetLineWidth(2);


  TGraph *ChiC_grPionDissCMSPt_M =(TGraph*)file_ChiC->Get("grPionDissCMSPt_M");
  ChiC_grPionDissCMSPt_M->SetLineColor(4);
  ChiC_grPionDissCMSPt_M->SetLineStyle(4);
  ChiC_grPionDissCMSPt_M->SetLineWidth(2);


  TGraph *ChiC_grRegenCMSPt_M =(TGraph*)file_ChiC->Get("grRegenCMSPt_M");
  ChiC_grRegenCMSPt_M->SetLineColor(8);
  ChiC_grRegenCMSPt_M->SetLineStyle(9);
  ChiC_grRegenCMSPt_M->SetLineWidth(2);



  TGraph *ChiC_grRAACMSPt_M =(TGraph*)file_ChiC->Get("grRAACMSPt_M");
  ChiC_grRAACMSPt_M->SetLineColor(1);
  ChiC_grRAACMSPt_M->SetLineStyle(1);
  ChiC_grRAACMSPt_M->SetLineWidth(2);

 //============================ ALICE RAA Vs NPart Graphs =======================//

 
  TGraph *ChiC_grGluonDissALICENPart_M =(TGraph*)file_ChiC->Get("grDissALICE_M");
  ChiC_grGluonDissALICENPart_M->SetLineColor(2);
  ChiC_grGluonDissALICENPart_M->SetLineStyle(2);
  ChiC_grGluonDissALICENPart_M->SetLineWidth(2);


  TGraph *ChiC_grPionDissALICENPart_M =(TGraph*)file_ChiC->Get("grPionDissALICE_M");
  ChiC_grPionDissALICENPart_M->SetLineColor(4);
  ChiC_grPionDissALICENPart_M->SetLineStyle(4);
  ChiC_grPionDissALICENPart_M->SetLineWidth(2);


  TGraph *ChiC_grRegenALICENPart_M =(TGraph*)file_ChiC->Get("grFormALICE_M");
  ChiC_grRegenALICENPart_M->SetLineColor(8);
  ChiC_grRegenALICENPart_M->SetLineStyle(9);
  ChiC_grRegenALICENPart_M->SetLineWidth(2);



  TGraph *ChiC_grRAAALICENPart_M =(TGraph*)file_ChiC->Get("grRAAALICE_M");
  ChiC_grRAAALICENPart_M->SetLineColor(1);
  ChiC_grRAAALICENPart_M->SetLineStyle(1);
  ChiC_grRAAALICENPart_M->SetLineWidth(2);



//============================ CMS RAA Vs NPart Graphs =======================//

 
  TGraph *ChiC_grGluonDissCMSNPart_M =(TGraph*)file_ChiC->Get("grDissCMS_M");
  ChiC_grGluonDissCMSNPart_M->SetLineColor(2);
  ChiC_grGluonDissCMSNPart_M->SetLineStyle(2);
  ChiC_grGluonDissCMSNPart_M->SetLineWidth(2);


  TGraph *ChiC_grPionDissCMSNPart_M =(TGraph*)file_ChiC->Get("grPionDissCMS_M");
  ChiC_grPionDissCMSNPart_M->SetLineColor(4);
  ChiC_grPionDissCMSNPart_M->SetLineStyle(4);
  ChiC_grPionDissCMSNPart_M->SetLineWidth(2);


  TGraph *ChiC_grRegenCMSNPart_M =(TGraph*)file_ChiC->Get("grFormCMS_M");
  ChiC_grRegenCMSNPart_M->SetLineColor(8);
  ChiC_grRegenCMSNPart_M->SetLineStyle(9);
  ChiC_grRegenCMSNPart_M->SetLineWidth(2);



  TGraph *ChiC_grRAACMSNPart_M =(TGraph*)file_ChiC->Get("grRAACMS_M");
  ChiC_grRAACMSNPart_M->SetLineColor(1);
  ChiC_grRAACMSNPart_M->SetLineStyle(1);
  ChiC_grRAACMSNPart_M->SetLineWidth(2);





  //================================ Open Psi2S Root File ================================================//
  TFile *file_Psi2S = new TFile("050514_PsiCalculations.root","R");
  

 // ====== Event Variable Graphs  ==============================//

  TGraph *Psi2S_grTempVsTauL =(TGraph*)file_Psi2S->Get("grTempVsTauL");
  Psi2S_grTempVsTauL->SetLineColor(2);
  Psi2S_grTempVsTauL->SetLineStyle(1);
  Psi2S_grTempVsTauL->SetLineWidth(2);

  TGraph *Psi2S_grTempVsTauC =(TGraph*)file_Psi2S->Get("grTempVsTauC");
  Psi2S_grTempVsTauC->SetLineColor(4);
  Psi2S_grTempVsTauC->SetLineStyle(2);
  Psi2S_grTempVsTauC->SetLineWidth(2);

 
  TGraph *Psi2S_grFQGPVsTauL =(TGraph*)file_Psi2S->Get("grFQGPVsTauL");
  Psi2S_grFQGPVsTauL->SetLineColor(2);
  Psi2S_grFQGPVsTauL->SetLineStyle(1);
  Psi2S_grFQGPVsTauL->SetLineWidth(2);


  TGraph *Psi2S_grFQGPVsTauC =(TGraph*)file_Psi2S->Get("grFQGPVsTauC");
  Psi2S_grFQGPVsTauC->SetLineColor(4);
  Psi2S_grFQGPVsTauC->SetLineStyle(2);
  Psi2S_grFQGPVsTauC->SetLineWidth(2);



  // ====== Cross Section graphs ==============================//
  TGraph *Psi2S_grSigDQ0 =(TGraph*)file_Psi2S->Get("grSigDQ0");
  Psi2S_grSigDQ0->SetLineColor(2);
  Psi2S_grSigDQ0->SetLineStyle(1);
  Psi2S_grSigDQ0->SetLineWidth(2);

  TGraph *Psi2S_grSigDS =(TGraph*)file_Psi2S->Get("grSigD");
  Psi2S_grSigDS->SetLineColor(2);
  Psi2S_grSigDS->SetLineStyle(1);
  Psi2S_grSigDS->SetLineWidth(2);

  TGraph *Psi2S_grSigFS =(TGraph*)file_Psi2S->Get("grSigF");
  Psi2S_grSigFS->SetLineColor(4);
  Psi2S_grSigFS->SetLineStyle(2);
  Psi2S_grSigFS->SetLineWidth(2);



  // ====== Dissociation rate graphs ==============================//

  
  TGraph *Psi2S_DissRateVsT_KharPt0 =(TGraph*)file_Psi2S->Get("DissRateVsT_KharPt0");
  Psi2S_DissRateVsT_KharPt0->SetLineColor(1);
  Psi2S_DissRateVsT_KharPt0->SetLineStyle(1);
  Psi2S_DissRateVsT_KharPt0->SetLineWidth(2);

  TGraph *Psi2S_DissRateVsT_KharPt36 =(TGraph*)file_Psi2S->Get("DissRateVsT_KharPt36");
  Psi2S_DissRateVsT_KharPt36->SetLineColor(4);
  Psi2S_DissRateVsT_KharPt36->SetLineStyle(4);
  Psi2S_DissRateVsT_KharPt36->SetLineWidth(2);


  TGraph *Psi2S_DissRateVsT_KharPt86 =(TGraph*)file_Psi2S->Get("DissRateVsT_KharPt86");
  Psi2S_DissRateVsT_KharPt86->SetLineColor(2);
  Psi2S_DissRateVsT_KharPt86->SetLineStyle(2);
  Psi2S_DissRateVsT_KharPt86->SetLineWidth(2);



  TGraph *Psi2S_grDissRateVsPt_T200 =(TGraph*)file_Psi2S->Get("grDissRateVsPt_T200");
  Psi2S_grDissRateVsPt_T200->SetLineColor(1);
  Psi2S_grDissRateVsPt_T200->SetLineStyle(1);
  Psi2S_grDissRateVsPt_T200->SetLineWidth(2);


  TGraph *Psi2S_grDissRateVsPt_T400 =(TGraph*)file_Psi2S->Get("grDissRateVsPt_T400");
  Psi2S_grDissRateVsPt_T400->SetLineColor(4);
  Psi2S_grDissRateVsPt_T400->SetLineStyle(4);
  Psi2S_grDissRateVsPt_T400->SetLineWidth(2);

  TGraph *Psi2S_grDissRateVsPt_T600 =(TGraph*)file_Psi2S->Get("grDissRateVsPt_T600");
  Psi2S_grDissRateVsPt_T600->SetLineColor(2);
  Psi2S_grDissRateVsPt_T600->SetLineStyle(2);
  Psi2S_grDissRateVsPt_T600->SetLineWidth(2);



// ====== Formation rate graphs ==============================//

  TGraph *Psi2S_grFormRateVsT_MCInt_P1 =(TGraph*)file_Psi2S->Get("grFormRateVsT_MCInt_P1");
  Psi2S_grFormRateVsT_MCInt_P1->SetLineColor(1);
  Psi2S_grFormRateVsT_MCInt_P1->SetLineStyle(1);
  Psi2S_grFormRateVsT_MCInt_P1->SetLineWidth(2);


  TGraph *Psi2S_grFormRateVsT_MCInt_P2 =(TGraph*)file_Psi2S->Get("grFormRateVsT_MCInt_P2");
  Psi2S_grFormRateVsT_MCInt_P2->SetLineColor(4);
  Psi2S_grFormRateVsT_MCInt_P2->SetLineStyle(4);
  Psi2S_grFormRateVsT_MCInt_P2->SetLineWidth(2);


  TGraph *Psi2S_grFormRateVsT_MCInt_P3 =(TGraph*)file_Psi2S->Get("grFormRateVsT_MCInt_P3");
  Psi2S_grFormRateVsT_MCInt_P3->SetLineColor(2);
  Psi2S_grFormRateVsT_MCInt_P3->SetLineStyle(2);
  Psi2S_grFormRateVsT_MCInt_P3->SetLineWidth(2);



  TGraph *Psi2S_grFormRateVsP_MCInt_T1 =(TGraph*)file_Psi2S->Get("grFormRateVsP_MCInt_T1");
  Psi2S_grFormRateVsP_MCInt_T1->SetLineColor(1);
  Psi2S_grFormRateVsP_MCInt_T1->SetLineStyle(1);
  Psi2S_grFormRateVsP_MCInt_T1->SetLineWidth(2);

  TGraph *Psi2S_grFormRateVsP_MCInt_T2 =(TGraph*)file_Psi2S->Get("grFormRateVsP_MCInt_T2");
  Psi2S_grFormRateVsP_MCInt_T2->SetLineColor(4);
  Psi2S_grFormRateVsP_MCInt_T2->SetLineStyle(4);
  Psi2S_grFormRateVsP_MCInt_T2->SetLineWidth(2);

  TGraph *Psi2S_grFormRateVsP_MCInt_T3 =(TGraph*)file_Psi2S->Get("grFormRateVsP_MCInt_T3");
  Psi2S_grFormRateVsP_MCInt_T3->SetLineColor(2);
  Psi2S_grFormRateVsP_MCInt_T3->SetLineStyle(2);
  Psi2S_grFormRateVsP_MCInt_T3->SetLineWidth(2);


  //============================ RAA Graphs =======================//

 
 //============================ ALICE RAA Vs Pt Graphs =======================//

  TGraph *Psi2S_grGluonDissALICEPt_M =(TGraph*)file_Psi2S->Get("grGluonDissALICEPt_M");
  Psi2S_grGluonDissALICEPt_M->SetLineColor(2);
  Psi2S_grGluonDissALICEPt_M->SetLineStyle(2);
  Psi2S_grGluonDissALICEPt_M->SetLineWidth(2);


  TGraph *Psi2S_grPionDissALICEPt_M =(TGraph*)file_Psi2S->Get("grPionDissALICEPt_M");
  Psi2S_grPionDissALICEPt_M->SetLineColor(4);
  Psi2S_grPionDissALICEPt_M->SetLineStyle(4);
  Psi2S_grPionDissALICEPt_M->SetLineWidth(2);


  TGraph *Psi2S_grRegenALICEPt_M =(TGraph*)file_Psi2S->Get("grRegenALICEPt_M");
  Psi2S_grRegenALICEPt_M->SetLineColor(8);
  Psi2S_grRegenALICEPt_M->SetLineStyle(9);
  Psi2S_grRegenALICEPt_M->SetLineWidth(2);



  TGraph *Psi2S_grRAAALICEPt_M =(TGraph*)file_Psi2S->Get("grRAAALICEPt_M");
  Psi2S_grRAAALICEPt_M->SetLineColor(1);
  Psi2S_grRAAALICEPt_M->SetLineStyle(1);
  Psi2S_grRAAALICEPt_M->SetLineWidth(2);


 //============================ CMS RAA Vs Pt Graphs =======================//

  TGraph *Psi2S_grGluonDissCMSPt_M =(TGraph*)file_Psi2S->Get("grGluonDissCMSPt_M");
  Psi2S_grGluonDissCMSPt_M->SetLineColor(2);
  Psi2S_grGluonDissCMSPt_M->SetLineStyle(2);
  Psi2S_grGluonDissCMSPt_M->SetLineWidth(2);


  TGraph *Psi2S_grPionDissCMSPt_M =(TGraph*)file_Psi2S->Get("grPionDissCMSPt_M");
  Psi2S_grPionDissCMSPt_M->SetLineColor(4);
  Psi2S_grPionDissCMSPt_M->SetLineStyle(4);
  Psi2S_grPionDissCMSPt_M->SetLineWidth(2);


  TGraph *Psi2S_grRegenCMSPt_M =(TGraph*)file_Psi2S->Get("grRegenCMSPt_M");
  Psi2S_grRegenCMSPt_M->SetLineColor(8);
  Psi2S_grRegenCMSPt_M->SetLineStyle(9);
  Psi2S_grRegenCMSPt_M->SetLineWidth(2);



  TGraph *Psi2S_grRAACMSPt_M =(TGraph*)file_Psi2S->Get("grRAACMSPt_M");
  Psi2S_grRAACMSPt_M->SetLineColor(1);
  Psi2S_grRAACMSPt_M->SetLineStyle(1);
  Psi2S_grRAACMSPt_M->SetLineWidth(2);

 //============================ ALICE RAA Vs NPart Graphs =======================//

 
  TGraph *Psi2S_grGluonDissALICENPart_M =(TGraph*)file_Psi2S->Get("grDissALICE_M");
  Psi2S_grGluonDissALICENPart_M->SetLineColor(2);
  Psi2S_grGluonDissALICENPart_M->SetLineStyle(2);
  Psi2S_grGluonDissALICENPart_M->SetLineWidth(2);


  TGraph *Psi2S_grPionDissALICENPart_M =(TGraph*)file_Psi2S->Get("grPionDissALICE_M");
  Psi2S_grPionDissALICENPart_M->SetLineColor(4);
  Psi2S_grPionDissALICENPart_M->SetLineStyle(4);
  Psi2S_grPionDissALICENPart_M->SetLineWidth(2);


  TGraph *Psi2S_grRegenALICENPart_M =(TGraph*)file_Psi2S->Get("grFormALICE_M");
  Psi2S_grRegenALICENPart_M->SetLineColor(8);
  Psi2S_grRegenALICENPart_M->SetLineStyle(9);
  Psi2S_grRegenALICENPart_M->SetLineWidth(2);



  TGraph *Psi2S_grRAAALICENPart_M =(TGraph*)file_Psi2S->Get("grRAAALICE_M");
  Psi2S_grRAAALICENPart_M->SetLineColor(1);
  Psi2S_grRAAALICENPart_M->SetLineStyle(1);
  Psi2S_grRAAALICENPart_M->SetLineWidth(2);



//============================ CMS RAA Vs NPart Graphs =======================//

 
  TGraph *Psi2S_grGluonDissCMSNPart_M =(TGraph*)file_Psi2S->Get("grDissCMS_M");
  Psi2S_grGluonDissCMSNPart_M->SetLineColor(2);
  Psi2S_grGluonDissCMSNPart_M->SetLineStyle(2);
  Psi2S_grGluonDissCMSNPart_M->SetLineWidth(2);


  TGraph *Psi2S_grPionDissCMSNPart_M =(TGraph*)file_Psi2S->Get("grPionDissCMS_M");
  Psi2S_grPionDissCMSNPart_M->SetLineColor(4);
  Psi2S_grPionDissCMSNPart_M->SetLineStyle(4);
  Psi2S_grPionDissCMSNPart_M->SetLineWidth(2);


  TGraph *Psi2S_grRegenCMSNPart_M =(TGraph*)file_Psi2S->Get("grFormCMS_M");
  Psi2S_grRegenCMSNPart_M->SetLineColor(8);
  Psi2S_grRegenCMSNPart_M->SetLineStyle(9);
  Psi2S_grRegenCMSNPart_M->SetLineWidth(2);



  TGraph *Psi2S_grRAACMSNPart_M =(TGraph*)file_Psi2S->Get("grRAACMS_M");
  Psi2S_grRAACMSNPart_M->SetLineColor(1);
  Psi2S_grRAACMSNPart_M->SetLineStyle(1);
  Psi2S_grRAACMSNPart_M->SetLineWidth(2);



  //================================ Open JPsi Root File ================================================//
  TFile *file_JPsi = new TFile("050514_JPsiCalculations.root","R");
  
  //TFile *file_JPsi = new TFile("JPsiCalculations.root","R");

  // ====== Event Variable Graphs  ==============================//
  TGraph *JPsi_grTempVsTauL =(TGraph*)file_JPsi->Get("grTempVsTauL");
  JPsi_grTempVsTauL->SetLineColor(2);
  JPsi_grTempVsTauL->SetLineStyle(1);
  JPsi_grTempVsTauL->SetLineWidth(2);

  TGraph *JPsi_grTempVsTauC =(TGraph*)file_JPsi->Get("grTempVsTauC");
  JPsi_grTempVsTauC->SetLineColor(4);
  JPsi_grTempVsTauC->SetLineStyle(2);
  JPsi_grTempVsTauC->SetLineWidth(2);

 
  TGraph *JPsi_grFQGPVsTauL =(TGraph*)file_JPsi->Get("grFQGPVsTauL");
  JPsi_grFQGPVsTauL->SetLineColor(2);
  JPsi_grFQGPVsTauL->SetLineStyle(1);
  JPsi_grFQGPVsTauL->SetLineWidth(2);


  TGraph *JPsi_grFQGPVsTauC =(TGraph*)file_JPsi->Get("grFQGPVsTauC");
  JPsi_grFQGPVsTauC->SetLineColor(4);
  JPsi_grFQGPVsTauC->SetLineStyle(2);
  JPsi_grFQGPVsTauC->SetLineWidth(2);



  // ====== Cross Section graphs ==============================//
  TGraph *JPsi_grSigDQ0 =(TGraph*)file_JPsi->Get("grSigDQ0");
  JPsi_grSigDQ0->SetLineColor(2);
  JPsi_grSigDQ0->SetLineStyle(1);
  JPsi_grSigDQ0->SetLineWidth(2);

  TGraph *JPsi_grSigDS =(TGraph*)file_JPsi->Get("grSigD");
  JPsi_grSigDS->SetLineColor(2);
  JPsi_grSigDS->SetLineStyle(1);
  JPsi_grSigDS->SetLineWidth(2);

  TGraph *JPsi_grSigFS =(TGraph*)file_JPsi->Get("grSigF");
  JPsi_grSigFS->SetLineColor(4);
  JPsi_grSigFS->SetLineStyle(2);
  JPsi_grSigFS->SetLineWidth(2);



  // ====== Dissociation rate graphs ==============================//

  
  TGraph *JPsi_DissRateVsT_KharPt0 =(TGraph*)file_JPsi->Get("DissRateVsT_KharPt0");
  JPsi_DissRateVsT_KharPt0->SetLineColor(1);
  JPsi_DissRateVsT_KharPt0->SetLineStyle(1);
  JPsi_DissRateVsT_KharPt0->SetLineWidth(2);

  TGraph *JPsi_DissRateVsT_KharPt36 =(TGraph*)file_JPsi->Get("DissRateVsT_KharPt36");
  JPsi_DissRateVsT_KharPt36->SetLineColor(4);
  JPsi_DissRateVsT_KharPt36->SetLineStyle(4);
  JPsi_DissRateVsT_KharPt36->SetLineWidth(2);


  TGraph *JPsi_DissRateVsT_KharPt86 =(TGraph*)file_JPsi->Get("DissRateVsT_KharPt86");
  JPsi_DissRateVsT_KharPt86->SetLineColor(2);
  JPsi_DissRateVsT_KharPt86->SetLineStyle(2);
  JPsi_DissRateVsT_KharPt86->SetLineWidth(2);



  TGraph *JPsi_grDissRateVsPt_T200 =(TGraph*)file_JPsi->Get("grDissRateVsPt_T200");
  JPsi_grDissRateVsPt_T200->SetLineColor(1);
  JPsi_grDissRateVsPt_T200->SetLineStyle(1);
  JPsi_grDissRateVsPt_T200->SetLineWidth(2);


  TGraph *JPsi_grDissRateVsPt_T400 =(TGraph*)file_JPsi->Get("grDissRateVsPt_T400");
  JPsi_grDissRateVsPt_T400->SetLineColor(4);
  JPsi_grDissRateVsPt_T400->SetLineStyle(4);
  JPsi_grDissRateVsPt_T400->SetLineWidth(2);

  TGraph *JPsi_grDissRateVsPt_T600 =(TGraph*)file_JPsi->Get("grDissRateVsPt_T600");
  JPsi_grDissRateVsPt_T600->SetLineColor(2);
  JPsi_grDissRateVsPt_T600->SetLineStyle(2);
  JPsi_grDissRateVsPt_T600->SetLineWidth(2);



// ====== Formation rate graphs ==============================//

  TGraph *JPsi_grFormRateVsT_MCInt_P1 =(TGraph*)file_JPsi->Get("grFormRateVsT_MCInt_P1");
  JPsi_grFormRateVsT_MCInt_P1->SetLineColor(1);
  JPsi_grFormRateVsT_MCInt_P1->SetLineStyle(1);
  JPsi_grFormRateVsT_MCInt_P1->SetLineWidth(2);


  TGraph *JPsi_grFormRateVsT_MCInt_P2 =(TGraph*)file_JPsi->Get("grFormRateVsT_MCInt_P2");
  JPsi_grFormRateVsT_MCInt_P2->SetLineColor(4);
  JPsi_grFormRateVsT_MCInt_P2->SetLineStyle(4);
  JPsi_grFormRateVsT_MCInt_P2->SetLineWidth(2);


  TGraph *JPsi_grFormRateVsT_MCInt_P3 =(TGraph*)file_JPsi->Get("grFormRateVsT_MCInt_P3");
  JPsi_grFormRateVsT_MCInt_P3->SetLineColor(2);
  JPsi_grFormRateVsT_MCInt_P3->SetLineStyle(2);
  JPsi_grFormRateVsT_MCInt_P3->SetLineWidth(2);



  TGraph *JPsi_grFormRateVsP_MCInt_T1 =(TGraph*)file_JPsi->Get("grFormRateVsP_MCInt_T1");
  JPsi_grFormRateVsP_MCInt_T1->SetLineColor(1);
  JPsi_grFormRateVsP_MCInt_T1->SetLineStyle(1);
  JPsi_grFormRateVsP_MCInt_T1->SetLineWidth(2);

  TGraph *JPsi_grFormRateVsP_MCInt_T2 =(TGraph*)file_JPsi->Get("grFormRateVsP_MCInt_T2");
  JPsi_grFormRateVsP_MCInt_T2->SetLineColor(4);
  JPsi_grFormRateVsP_MCInt_T2->SetLineStyle(4);
  JPsi_grFormRateVsP_MCInt_T2->SetLineWidth(2);

  TGraph *JPsi_grFormRateVsP_MCInt_T3 =(TGraph*)file_JPsi->Get("grFormRateVsP_MCInt_T3");
  JPsi_grFormRateVsP_MCInt_T3->SetLineColor(2);
  JPsi_grFormRateVsP_MCInt_T3->SetLineStyle(2);
  JPsi_grFormRateVsP_MCInt_T3->SetLineWidth(2);


  //============================ RAA Graphs =======================//

 
 //============================ ALICE RAA Vs Pt Graphs =======================//

  TGraph *JPsi_grGluonDissALICEPt_M =(TGraph*)file_JPsi->Get("grGluonDissALICEPt_M");
  JPsi_grGluonDissALICEPt_M->SetLineColor(2);
  JPsi_grGluonDissALICEPt_M->SetLineStyle(2);
  JPsi_grGluonDissALICEPt_M->SetLineWidth(2);


  TGraph *JPsi_grPionDissALICEPt_M =(TGraph*)file_JPsi->Get("grPionDissALICEPt_M");
  JPsi_grPionDissALICEPt_M->SetLineColor(4);
  JPsi_grPionDissALICEPt_M->SetLineStyle(4);
  JPsi_grPionDissALICEPt_M->SetLineWidth(2);


  TGraph *JPsi_grRegenALICEPt_M =(TGraph*)file_JPsi->Get("grRegenALICEPt_M");
  JPsi_grRegenALICEPt_M->SetLineColor(8);
  JPsi_grRegenALICEPt_M->SetLineStyle(9);
  JPsi_grRegenALICEPt_M->SetLineWidth(2);



  TGraph *JPsi_grRAAALICEPt_M =(TGraph*)file_JPsi->Get("grRAAALICEPt_M");
  JPsi_grRAAALICEPt_M->SetLineColor(1);
  JPsi_grRAAALICEPt_M->SetLineStyle(1);
  JPsi_grRAAALICEPt_M->SetLineWidth(2);


 //============================ CMS RAA Vs Pt Graphs =======================//

  TGraph *JPsi_grGluonDissCMSPt_M =(TGraph*)file_JPsi->Get("grGluonDissCMSPt_M");
  JPsi_grGluonDissCMSPt_M->SetLineColor(2);
  JPsi_grGluonDissCMSPt_M->SetLineStyle(2);
  JPsi_grGluonDissCMSPt_M->SetLineWidth(2);


  TGraph *JPsi_grPionDissCMSPt_M =(TGraph*)file_JPsi->Get("grPionDissCMSPt_M");
  JPsi_grPionDissCMSPt_M->SetLineColor(4);
  JPsi_grPionDissCMSPt_M->SetLineStyle(4);
  JPsi_grPionDissCMSPt_M->SetLineWidth(2);


  TGraph *JPsi_grRegenCMSPt_M =(TGraph*)file_JPsi->Get("grRegenCMSPt_M");
  JPsi_grRegenCMSPt_M->SetLineColor(8);
  JPsi_grRegenCMSPt_M->SetLineStyle(9);
  JPsi_grRegenCMSPt_M->SetLineWidth(2);



  TGraph *JPsi_grRAACMSPt_M =(TGraph*)file_JPsi->Get("grRAACMSPt_M");
  JPsi_grRAACMSPt_M->SetLineColor(1);
  JPsi_grRAACMSPt_M->SetLineStyle(1);
  JPsi_grRAACMSPt_M->SetLineWidth(2);

 //============================ ALICE RAA Vs NPart Graphs =======================//

 
  TGraph *JPsi_grGluonDissALICENPart_M =(TGraph*)file_JPsi->Get("grDissALICE_M");
  JPsi_grGluonDissALICENPart_M->SetLineColor(2);
  JPsi_grGluonDissALICENPart_M->SetLineStyle(2);
  JPsi_grGluonDissALICENPart_M->SetLineWidth(2);


  TGraph *JPsi_grPionDissALICENPart_M =(TGraph*)file_JPsi->Get("grPionDissALICE_M");
  JPsi_grPionDissALICENPart_M->SetLineColor(4);
  JPsi_grPionDissALICENPart_M->SetLineStyle(4);
  JPsi_grPionDissALICENPart_M->SetLineWidth(2);


  TGraph *JPsi_grRegenALICENPart_M =(TGraph*)file_JPsi->Get("grFormALICE_M");
  JPsi_grRegenALICENPart_M->SetLineColor(8);
  JPsi_grRegenALICENPart_M->SetLineStyle(9);
  JPsi_grRegenALICENPart_M->SetLineWidth(2);



  TGraph *JPsi_grRAAALICENPart_M =(TGraph*)file_JPsi->Get("grRAAALICE_M");
  JPsi_grRAAALICENPart_M->SetLineColor(1);
  JPsi_grRAAALICENPart_M->SetLineStyle(1);
  JPsi_grRAAALICENPart_M->SetLineWidth(2);



//============================ CMS RAA Vs NPart Graphs =======================//

 
  TGraph *JPsi_grGluonDissCMSNPart_M =(TGraph*)file_JPsi->Get("grDissCMS_M");
  JPsi_grGluonDissCMSNPart_M->SetLineColor(2);
  JPsi_grGluonDissCMSNPart_M->SetLineStyle(2);
  JPsi_grGluonDissCMSNPart_M->SetLineWidth(2);


  TGraph *JPsi_grPionDissCMSNPart_M =(TGraph*)file_JPsi->Get("grPionDissCMS_M");
  JPsi_grPionDissCMSNPart_M->SetLineColor(4);
  JPsi_grPionDissCMSNPart_M->SetLineStyle(4);
  JPsi_grPionDissCMSNPart_M->SetLineWidth(2);


  TGraph *JPsi_grRegenCMSNPart_M =(TGraph*)file_JPsi->Get("grFormCMS_M");
  JPsi_grRegenCMSNPart_M->SetLineColor(8);
  JPsi_grRegenCMSNPart_M->SetLineStyle(9);
  JPsi_grRegenCMSNPart_M->SetLineWidth(2);



  TGraph *JPsi_grRAACMSNPart_M =(TGraph*)file_JPsi->Get("grRAACMS_M");
  JPsi_grRAACMSNPart_M->SetLineColor(1);
  JPsi_grRAACMSNPart_M->SetLineStyle(1);
  JPsi_grRAACMSNPart_M->SetLineWidth(2);

  //=========================  Now make feed-down corrections in JPsi =========================//
  Double_t ChiCFactor = 0.32;
  Double_t Psi2SFactor = 0.081;
  Double_t JPsiFactor = 0.60;


  //====================== Cross - section Graphs ====================================//
  for (int j=0; j < JPsi_grSigDQ0->GetN();++j){
    Double_t x0,y0;
    Double_t x1,y1;
    Double_t x2,y2;
    Double_t x3,y3;
    JPsi_grSigDQ0->GetPoint(j,x1,y1);
    Psi2S_grSigDQ0->GetPoint(j,x2,y2);
    ChiC_grSigDQ0->GetPoint(j,x3,y3);
    x0=x1;
    //y0=JPsiFactor*y1 + Psi2SFactor*y2 + ChiCFactor*y3;
    y0=y1;
    JPsi_grSigDQ0->SetPoint(j,x0,y0);  
  }

  new TCanvas;
  JPsi_grSigDQ0->Draw("AL");
  

  

  // ================= RAA Vs Pt Graphs for charmonia with feed down =====================//

  for (int j=0; j < JPsi_grRAAALICEPt_M->GetN();++j){
    Double_t x0,y0;
    Double_t x1,y1;
    Double_t x2,y2;
    Double_t x3,y3;
    JPsi_grRAAALICEPt_M->GetPoint(j,x1,y1);
    Psi2S_grRAAALICEPt_M->GetPoint(j,x2,y2);
    ChiC_grRAAALICEPt_M->GetPoint(j,x3,y3);
    x0=x1;
    y0=JPsiFactor*y1 + Psi2SFactor*y2 + ChiCFactor*y3;
    JPsi_grRAAALICEPt_M->SetPoint(j,x0,y0);  


    JPsi_grGluonDissALICEPt_M->GetPoint(j,x1,y1);
    Psi2S_grGluonDissALICEPt_M->GetPoint(j,x2,y2);
    ChiC_grGluonDissALICEPt_M->GetPoint(j,x3,y3);
    x0=x1;
    y0=JPsiFactor*y1 + Psi2SFactor*y2 + ChiCFactor*y3;
    JPsi_grGluonDissALICEPt_M->SetPoint(j,x0,y0);  
  

    JPsi_grPionDissALICEPt_M->GetPoint(j,x1,y1);
    Psi2S_grPionDissALICEPt_M->GetPoint(j,x2,y2);
    ChiC_grPionDissALICEPt_M->GetPoint(j,x3,y3);
    x0=x1;
    y0=JPsiFactor*y1 + Psi2SFactor*y2 + ChiCFactor*y3;
    JPsi_grPionDissALICEPt_M->SetPoint(j,x0,y0); 

    
    JPsi_grRegenALICEPt_M->GetPoint(j,x1,y1);
    Psi2S_grRegenALICEPt_M->GetPoint(j,x2,y2);
    ChiC_grRegenALICEPt_M->GetPoint(j,x3,y3);
    x0=x1;
    y0=JPsiFactor*y1 + Psi2SFactor*y2 + ChiCFactor*y3;
    JPsi_grRegenALICEPt_M->SetPoint(j,x0,y0);


 }


 TLegend *legd1 = new TLegend(0.16,0.64,0.97,0.93);
 legd1->SetBorderSize(0);
 legd1->SetFillStyle(0);
 legd1->SetFillColor(0);
 legd1->SetTextSize(0.030);
  
 new TCanvas;
 gPad->SetTicks();
 Draw_ALICEFor_JPsi_RaaVspT(legd1);  
 legd1->AddEntry(JPsi_grGluonDissALICEPt_M,"Gluon Dissociation","L");
 legd1->AddEntry(JPsi_grPionDissALICEPt_M,"Comover","L");
 legd1->AddEntry(JPsi_grRegenALICEPt_M,"Formation","L");
 legd1->AddEntry(JPsi_grRAAALICEPt_M,"Total (R_{AA})","L");
 JPsi_grRAAALICEPt_M->Draw("Lsame");
 JPsi_grGluonDissALICEPt_M->Draw("Lsame");
 JPsi_grPionDissALICEPt_M->Draw("Lsame");
 JPsi_grRegenALICEPt_M->Draw("Lsame");
 legd1->Draw("same");
 gPad->SaveAs("Figures/Fig5a_ALICE_RAAPt.eps");
 gPad->SaveAs("Figures/Fig5a_ALICE_RAAPt.png");


 for (int j=0; j < JPsi_grRAACMSPt_M->GetN();++j){
   Double_t x0,y0;
   Double_t x1,y1;
   Double_t x2,y2;
   Double_t x3,y3;
   JPsi_grRAACMSPt_M->GetPoint(j,x1,y1);
   Psi2S_grRAACMSPt_M->GetPoint(j,x2,y2);
   ChiC_grRAACMSPt_M->GetPoint(j,x3,y3);
   x0=x1;
   y0=JPsiFactor*y1 + Psi2SFactor*y2 + ChiCFactor*y3;
   JPsi_grRAACMSPt_M->SetPoint(j,x0,y0);  


   JPsi_grGluonDissCMSPt_M->GetPoint(j,x1,y1);
   Psi2S_grGluonDissCMSPt_M->GetPoint(j,x2,y2);
   ChiC_grGluonDissCMSPt_M->GetPoint(j,x3,y3);
   x0=x1;
   y0=JPsiFactor*y1 + Psi2SFactor*y2 + ChiCFactor*y3;
   JPsi_grGluonDissCMSPt_M->SetPoint(j,x0,y0);  
   

   JPsi_grPionDissCMSPt_M->GetPoint(j,x1,y1);
   Psi2S_grPionDissCMSPt_M->GetPoint(j,x2,y2);
   ChiC_grPionDissCMSPt_M->GetPoint(j,x3,y3);
   x0=x1;
   y0=JPsiFactor*y1 + Psi2SFactor*y2 + ChiCFactor*y3;
   JPsi_grPionDissCMSPt_M->SetPoint(j,x0,y0); 
   
   
   JPsi_grRegenCMSPt_M->GetPoint(j,x1,y1);
   Psi2S_grRegenCMSPt_M->GetPoint(j,x2,y2);
   ChiC_grRegenCMSPt_M->GetPoint(j,x3,y3);
   x0=x1;
   y0=JPsiFactor*y1 + Psi2SFactor*y2 + ChiCFactor*y3;
   JPsi_grRegenCMSPt_M->SetPoint(j,x0,y0);
   
   
 }

 
 TLegend *legd2 = new TLegend(0.15,0.69,0.90,0.92);
 legd2->SetBorderSize(0);
 legd2->SetFillStyle(0);
 legd2->SetFillColor(0);
 legd2->SetTextSize(0.030);
 
 new TCanvas;
 gPad->SetTicks();
 Draw_CMS_JPsi_RaaVspT(legd2);  
 legd2->AddEntry(JPsi_grGluonDissCMSPt_M,"Gluon Dissociation","L");
 legd2->AddEntry(JPsi_grPionDissCMSPt_M,"Comover","L");
 legd2->AddEntry(JPsi_grRegenCMSPt_M,"Formation","L");
 legd2->AddEntry(JPsi_grRAACMSPt_M,"Total (R_{AA})","L");
 JPsi_grRAACMSPt_M->Draw("Lsame");
 JPsi_grGluonDissCMSPt_M->Draw("Lsame");
 JPsi_grPionDissCMSPt_M->Draw("Lsame");
 JPsi_grRegenCMSPt_M->Draw("Lsame");
 legd2->Draw("same");
 gPad->SaveAs("Figures/Fig5b_CMS_RAAPt.eps");
 gPad->SaveAs("Figures/Fig5b_CMS_RAAPt.png");


 //============== ALICE RAA Vs NPart JPsi ====================//


for (int j=0; j < JPsi_grRAAALICENPart_M->GetN();++j){
    Double_t x0,y0;
    Double_t x1,y1;
    Double_t x2,y2;
    Double_t x3,y3;
    JPsi_grRAAALICENPart_M->GetPoint(j,x1,y1);
    Psi2S_grRAAALICENPart_M->GetPoint(j,x2,y2);
    ChiC_grRAAALICENPart_M->GetPoint(j,x3,y3);
    x0=x1;

    y0=JPsiFactor*y1 + Psi2SFactor*y2 + ChiCFactor*y3;
    //y0=y2/y1;
    JPsi_grRAAALICENPart_M->SetPoint(j,x0,y0);  


    JPsi_grGluonDissALICENPart_M->GetPoint(j,x1,y1);
    Psi2S_grGluonDissALICENPart_M->GetPoint(j,x2,y2);
    ChiC_grGluonDissALICENPart_M->GetPoint(j,x3,y3);
    x0=x1;
    y0=JPsiFactor*y1 + Psi2SFactor*y2 + ChiCFactor*y3;
    JPsi_grGluonDissALICENPart_M->SetPoint(j,x0,y0);  
  

    JPsi_grPionDissALICENPart_M->GetPoint(j,x1,y1);
    Psi2S_grPionDissALICENPart_M->GetPoint(j,x2,y2);
    ChiC_grPionDissALICENPart_M->GetPoint(j,x3,y3);
    x0=x1;
    y0=JPsiFactor*y1 + Psi2SFactor*y2 + ChiCFactor*y3;
    JPsi_grPionDissALICENPart_M->SetPoint(j,x0,y0); 

    
    JPsi_grRegenALICENPart_M->GetPoint(j,x1,y1);
    Psi2S_grRegenALICENPart_M->GetPoint(j,x2,y2);
    ChiC_grRegenALICENPart_M->GetPoint(j,x3,y3);
    x0=x1;
    
    y0=JPsiFactor*y1 + Psi2SFactor*y2 + ChiCFactor*y3;
    
    JPsi_grRegenALICENPart_M->SetPoint(j,x0,y0);


 }

 TLegend *legd3 = new TLegend(0.17,0.56,0.54,0.91);
 legd3->SetBorderSize(0);
 legd3->SetFillStyle(0);
 legd3->SetFillColor(0);
 legd3->SetTextSize(0.030);
 
 new TCanvas;
 gPad->SetTicks();
 Draw_ALICEFor_JPsi_RaaVsNpart(legd3);
 legd3->AddEntry(JPsi_grGluonDissALICENPart_M,"Gluon Dissociation","L");
 legd3->AddEntry(JPsi_grPionDissALICENPart_M,"Comover","L");
 legd3->AddEntry(JPsi_grRegenALICENPart_M,"Formation","L");
 legd3->AddEntry(JPsi_grRAAALICENPart_M,"Total (R_{AA})","L");
 JPsi_grRAAALICENPart_M->Draw("Lsame");
 JPsi_grGluonDissALICENPart_M->Draw("Lsame");
 JPsi_grPionDissALICENPart_M->Draw("Lsame");
 JPsi_grRegenALICENPart_M->Draw("Lsame");
 legd3->Draw("same");
 gPad->SaveAs("Figures/Fig6a_ALICE_RAANPart.eps");
 gPad->SaveAs("Figures/Fig6a_ALICE_RAANPart.png");



 //============== CMS RAA Vs NPart JPsi ====================//


for (int j=0; j < JPsi_grRAACMSNPart_M->GetN();++j){
    Double_t x0,y0;
    Double_t x1,y1;
    Double_t x2,y2;
    Double_t x3,y3;
    JPsi_grRAACMSNPart_M->GetPoint(j,x1,y1);
    Psi2S_grRAACMSNPart_M->GetPoint(j,x2,y2);
    ChiC_grRAACMSNPart_M->GetPoint(j,x3,y3);
    x0=x1;
    y0=JPsiFactor*y1 + Psi2SFactor*y2 + ChiCFactor*y3;
    // y0=y2/y1;
    JPsi_grRAACMSNPart_M->SetPoint(j,x0,y0);  

    cout<<y0<<endl;
    JPsi_grGluonDissCMSNPart_M->GetPoint(j,x1,y1);
    Psi2S_grGluonDissCMSNPart_M->GetPoint(j,x2,y2);
    ChiC_grGluonDissCMSNPart_M->GetPoint(j,x3,y3);
    x0=x1;
    y0=JPsiFactor*y1 + Psi2SFactor*y2 + ChiCFactor*y3;
    JPsi_grGluonDissCMSNPart_M->SetPoint(j,x0,y0);  
  

    JPsi_grPionDissCMSNPart_M->GetPoint(j,x1,y1);
    Psi2S_grPionDissCMSNPart_M->GetPoint(j,x2,y2);
    ChiC_grPionDissCMSNPart_M->GetPoint(j,x3,y3);
    x0=x1;
    y0=JPsiFactor*y1 + Psi2SFactor*y2 + ChiCFactor*y3;
    JPsi_grPionDissCMSNPart_M->SetPoint(j,x0,y0); 

    
    JPsi_grRegenCMSNPart_M->GetPoint(j,x1,y1);
    Psi2S_grRegenCMSNPart_M->GetPoint(j,x2,y2);
    ChiC_grRegenCMSNPart_M->GetPoint(j,x3,y3);
    x0=x1;
    y0=JPsiFactor*y1 + Psi2SFactor*y2 + ChiCFactor*y3;
    JPsi_grRegenCMSNPart_M->SetPoint(j,x0,y0);


 }

 TLegend *legd4 = new TLegend(0.17,0.66,0.63,0.93);
 legd4->SetBorderSize(0);
 legd4->SetFillStyle(0);
 legd4->SetFillColor(0);
 legd4->SetTextSize(0.030);
 
 new TCanvas;
 gPad->SetTicks();
 Draw_CMS_JPsi_RaaVsNpart(legd4);
 legd4->AddEntry(JPsi_grGluonDissCMSNPart_M,"Gluon Dissociation","L");
 legd4->AddEntry(JPsi_grPionDissCMSNPart_M,"Comover","L");
 legd4->AddEntry(JPsi_grRegenCMSNPart_M,"Formation","L");
 legd4->AddEntry(JPsi_grRAACMSNPart_M,"Total (R_{AA})","L");
 JPsi_grRAACMSNPart_M->Draw("Lsame");
 JPsi_grGluonDissCMSNPart_M->Draw("Lsame");
 JPsi_grPionDissCMSNPart_M->Draw("Lsame");
 JPsi_grRegenCMSNPart_M->Draw("Lsame");
 legd4->Draw("same");
 gPad->SaveAs("Figures/Fig6b_CMS_RAANPart.eps");
 gPad->SaveAs("Figures/Fig6b_CMS_RAANPart.png");


 //===================================================================================//
 //======================================== Upsilon Figures ========================//
 //===================================================================================//




  //================================ Open ChiB Root File ================================================//
  TFile *file_ChiB = new TFile("05052014_ChiBCalculations.root","R");
  

  // ====== Event Variable Graphs  ==============================//
  
  TGraph *ChiB_grTempVsTauL =(TGraph*)file_ChiB->Get("grTempVsTauL");
  ChiB_grTempVsTauL->SetLineColor(2);
  ChiB_grTempVsTauL->SetLineStyle(1);
  ChiB_grTempVsTauL->SetLineWidth(2);
  
  TGraph *ChiB_grTempVsTauC =(TGraph*)file_ChiB->Get("grTempVsTauC");
  ChiB_grTempVsTauC->SetLineColor(4);
  ChiB_grTempVsTauC->SetLineStyle(2);
  ChiB_grTempVsTauC->SetLineWidth(2);
  
  
  TGraph *ChiB_grFQGPVsTauL =(TGraph*)file_ChiB->Get("grFQGPVsTauL");
  ChiB_grFQGPVsTauL->SetLineColor(2);
  ChiB_grFQGPVsTauL->SetLineStyle(1);
  ChiB_grFQGPVsTauL->SetLineWidth(2);
  
  
  TGraph *ChiB_grFQGPVsTauC =(TGraph*)file_ChiB->Get("grFQGPVsTauC");
  ChiB_grFQGPVsTauC->SetLineColor(4);
  ChiB_grFQGPVsTauC->SetLineStyle(2);
  ChiB_grFQGPVsTauC->SetLineWidth(2);
  

  
  // ====== Cross Section graphs ==============================//
  TGraph *ChiB_grSigDQ0 =(TGraph*)file_ChiB->Get("grSigDQ0");
  ChiB_grSigDQ0->SetLineColor(2);
  ChiB_grSigDQ0->SetLineStyle(1);
  ChiB_grSigDQ0->SetLineWidth(2);
  
  TGraph *ChiB_grSigDS =(TGraph*)file_ChiB->Get("grSigD");
  ChiB_grSigDS->SetLineColor(2);
  ChiB_grSigDS->SetLineStyle(1);
  ChiB_grSigDS->SetLineWidth(2);
  
  TGraph *ChiB_grSigFS =(TGraph*)file_ChiB->Get("grSigF");
  ChiB_grSigFS->SetLineColor(4);
  ChiB_grSigFS->SetLineStyle(2);
  ChiB_grSigFS->SetLineWidth(2);
  
  

  // ====== Dissociation rate graphs ==============================//
  
  
  TGraph *ChiB_DissRateVsT_KharPt0 =(TGraph*)file_ChiB->Get("DissRateVsT_KharPt0");
  ChiB_DissRateVsT_KharPt0->SetLineColor(1);
  ChiB_DissRateVsT_KharPt0->SetLineStyle(1);
  ChiB_DissRateVsT_KharPt0->SetLineWidth(2);
  
  TGraph *ChiB_DissRateVsT_KharPt36 =(TGraph*)file_ChiB->Get("DissRateVsT_KharPt36");
  ChiB_DissRateVsT_KharPt36->SetLineColor(4);
  ChiB_DissRateVsT_KharPt36->SetLineStyle(4);
  ChiB_DissRateVsT_KharPt36->SetLineWidth(2);
  
  
  TGraph *ChiB_DissRateVsT_KharPt86 =(TGraph*)file_ChiB->Get("DissRateVsT_KharPt86");
  ChiB_DissRateVsT_KharPt86->SetLineColor(2);
  ChiB_DissRateVsT_KharPt86->SetLineStyle(2);
  ChiB_DissRateVsT_KharPt86->SetLineWidth(2);
  
  
  
  TGraph *ChiB_grDissRateVsPt_T200 =(TGraph*)file_ChiB->Get("grDissRateVsPt_T200");
  ChiB_grDissRateVsPt_T200->SetLineColor(1);
  ChiB_grDissRateVsPt_T200->SetLineStyle(1);
  ChiB_grDissRateVsPt_T200->SetLineWidth(2);
  
  
  TGraph *ChiB_grDissRateVsPt_T400 =(TGraph*)file_ChiB->Get("grDissRateVsPt_T400");
  ChiB_grDissRateVsPt_T400->SetLineColor(4);
  ChiB_grDissRateVsPt_T400->SetLineStyle(4);
  ChiB_grDissRateVsPt_T400->SetLineWidth(2);
  
  TGraph *ChiB_grDissRateVsPt_T600 =(TGraph*)file_ChiB->Get("grDissRateVsPt_T600");
  ChiB_grDissRateVsPt_T600->SetLineColor(2);
  ChiB_grDissRateVsPt_T600->SetLineStyle(2);
  ChiB_grDissRateVsPt_T600->SetLineWidth(2);

  
  
  // ====== Formation rate graphs ==============================//

  TGraph *ChiB_grFormRateVsT_MCInt_P1 =(TGraph*)file_ChiB->Get("grFormRateVsT_MCInt_P1");
  ChiB_grFormRateVsT_MCInt_P1->SetLineColor(1);
  ChiB_grFormRateVsT_MCInt_P1->SetLineStyle(1);
  ChiB_grFormRateVsT_MCInt_P1->SetLineWidth(2);
  
  
  TGraph *ChiB_grFormRateVsT_MCInt_P2 =(TGraph*)file_ChiB->Get("grFormRateVsT_MCInt_P2");
  ChiB_grFormRateVsT_MCInt_P2->SetLineColor(4);
  ChiB_grFormRateVsT_MCInt_P2->SetLineStyle(4);
  ChiB_grFormRateVsT_MCInt_P2->SetLineWidth(2);
  
  
  TGraph *ChiB_grFormRateVsT_MCInt_P3 =(TGraph*)file_ChiB->Get("grFormRateVsT_MCInt_P3");
  ChiB_grFormRateVsT_MCInt_P3->SetLineColor(2);
  ChiB_grFormRateVsT_MCInt_P3->SetLineStyle(2);
  ChiB_grFormRateVsT_MCInt_P3->SetLineWidth(2);
  

  
  TGraph *ChiB_grFormRateVsP_MCInt_T1 =(TGraph*)file_ChiB->Get("grFormRateVsP_MCInt_T1");
  ChiB_grFormRateVsP_MCInt_T1->SetLineColor(1);
  ChiB_grFormRateVsP_MCInt_T1->SetLineStyle(1);
  ChiB_grFormRateVsP_MCInt_T1->SetLineWidth(2);
  
  TGraph *ChiB_grFormRateVsP_MCInt_T2 =(TGraph*)file_ChiB->Get("grFormRateVsP_MCInt_T2");
  ChiB_grFormRateVsP_MCInt_T2->SetLineColor(4);
  ChiB_grFormRateVsP_MCInt_T2->SetLineStyle(4);
  ChiB_grFormRateVsP_MCInt_T2->SetLineWidth(2);

  TGraph *ChiB_grFormRateVsP_MCInt_T3 =(TGraph*)file_ChiB->Get("grFormRateVsP_MCInt_T3");
  ChiB_grFormRateVsP_MCInt_T3->SetLineColor(2);
  ChiB_grFormRateVsP_MCInt_T3->SetLineStyle(2);
  ChiB_grFormRateVsP_MCInt_T3->SetLineWidth(2);
  

  //============================ RAA Graphs =======================//
  
  
 //============================ ALICE RAA Vs Pt Graphs =======================//
  
  TGraph *ChiB_grGluonDissALICEPt_M =(TGraph*)file_ChiB->Get("grGluonDissALICEPt_M");
  ChiB_grGluonDissALICEPt_M->SetLineColor(2);
  ChiB_grGluonDissALICEPt_M->SetLineStyle(2);
  ChiB_grGluonDissALICEPt_M->SetLineWidth(2);

  
  TGraph *ChiB_grPionDissALICEPt_M =(TGraph*)file_ChiB->Get("grPionDissALICEPt_M");
  ChiB_grPionDissALICEPt_M->SetLineColor(4);
  ChiB_grPionDissALICEPt_M->SetLineStyle(4);
  ChiB_grPionDissALICEPt_M->SetLineWidth(2);


  TGraph *ChiB_grRegenALICEPt_M =(TGraph*)file_ChiB->Get("grRegenALICEPt_M");
  ChiB_grRegenALICEPt_M->SetLineColor(8);
  ChiB_grRegenALICEPt_M->SetLineStyle(9);
  ChiB_grRegenALICEPt_M->SetLineWidth(2);



  TGraph *ChiB_grRAAALICEPt_M =(TGraph*)file_ChiB->Get("grRAAALICEPt_M");
  ChiB_grRAAALICEPt_M->SetLineColor(1);
  ChiB_grRAAALICEPt_M->SetLineStyle(1);
  ChiB_grRAAALICEPt_M->SetLineWidth(2);


 //============================ CMS RAA Vs Pt Graphs =======================//

  TGraph *ChiB_grGluonDissCMSPt_M =(TGraph*)file_ChiB->Get("grGluonDissCMSPt_M");
  ChiB_grGluonDissCMSPt_M->SetLineColor(2);
  ChiB_grGluonDissCMSPt_M->SetLineStyle(2);
  ChiB_grGluonDissCMSPt_M->SetLineWidth(2);


  TGraph *ChiB_grPionDissCMSPt_M =(TGraph*)file_ChiB->Get("grPionDissCMSPt_M");
  ChiB_grPionDissCMSPt_M->SetLineColor(4);
  ChiB_grPionDissCMSPt_M->SetLineStyle(4);
  ChiB_grPionDissCMSPt_M->SetLineWidth(2);


  TGraph *ChiB_grRegenCMSPt_M =(TGraph*)file_ChiB->Get("grRegenCMSPt_M");
  ChiB_grRegenCMSPt_M->SetLineColor(8);
  ChiB_grRegenCMSPt_M->SetLineStyle(9);
  ChiB_grRegenCMSPt_M->SetLineWidth(2);



  TGraph *ChiB_grRAACMSPt_M =(TGraph*)file_ChiB->Get("grRAACMSPt_M");
  ChiB_grRAACMSPt_M->SetLineColor(1);
  ChiB_grRAACMSPt_M->SetLineStyle(1);
  ChiB_grRAACMSPt_M->SetLineWidth(2);

 //============================ ALICE RAA Vs NPart Graphs =======================//

 
  TGraph *ChiB_grGluonDissALICENPart_M =(TGraph*)file_ChiB->Get("grDissALICE_M");
  ChiB_grGluonDissALICENPart_M->SetLineColor(2);
  ChiB_grGluonDissALICENPart_M->SetLineStyle(2);
  ChiB_grGluonDissALICENPart_M->SetLineWidth(2);


  TGraph *ChiB_grPionDissALICENPart_M =(TGraph*)file_ChiB->Get("grPionDissALICE_M");
  ChiB_grPionDissALICENPart_M->SetLineColor(4);
  ChiB_grPionDissALICENPart_M->SetLineStyle(4);
  ChiB_grPionDissALICENPart_M->SetLineWidth(2);


  TGraph *ChiB_grRegenALICENPart_M =(TGraph*)file_ChiB->Get("grFormALICE_M");
  ChiB_grRegenALICENPart_M->SetLineColor(8);
  ChiB_grRegenALICENPart_M->SetLineStyle(9);
  ChiB_grRegenALICENPart_M->SetLineWidth(2);



  TGraph *ChiB_grRAAALICENPart_M =(TGraph*)file_ChiB->Get("grRAAALICE_M");
  ChiB_grRAAALICENPart_M->SetLineColor(1);
  ChiB_grRAAALICENPart_M->SetLineStyle(1);
  ChiB_grRAAALICENPart_M->SetLineWidth(2);



//============================ CMS RAA Vs NPart Graphs =======================//

 
  TGraph *ChiB_grGluonDissCMSNPart_M =(TGraph*)file_ChiB->Get("grDissCMS_M");
  ChiB_grGluonDissCMSNPart_M->SetLineColor(2);
  ChiB_grGluonDissCMSNPart_M->SetLineStyle(2);
  ChiB_grGluonDissCMSNPart_M->SetLineWidth(2);


  TGraph *ChiB_grPionDissCMSNPart_M =(TGraph*)file_ChiB->Get("grPionDissCMS_M");
  ChiB_grPionDissCMSNPart_M->SetLineColor(4);
  ChiB_grPionDissCMSNPart_M->SetLineStyle(4);
  ChiB_grPionDissCMSNPart_M->SetLineWidth(2);


  TGraph *ChiB_grRegenCMSNPart_M =(TGraph*)file_ChiB->Get("grFormCMS_M");
  ChiB_grRegenCMSNPart_M->SetLineColor(8);
  ChiB_grRegenCMSNPart_M->SetLineStyle(9);
  ChiB_grRegenCMSNPart_M->SetLineWidth(2);



  TGraph *ChiB_grRAACMSNPart_M =(TGraph*)file_ChiB->Get("grRAACMS_M");
  ChiB_grRAACMSNPart_M->SetLineColor(1);
  ChiB_grRAACMSNPart_M->SetLineStyle(1);
  ChiB_grRAACMSNPart_M->SetLineWidth(2);





  //================================ Open Y2S Root File ================================================//
  TFile *file_Y2S = new TFile("05052014_Y2SCalculations.root","R");
  

  // ====== Event Variable Graphs  ==============================//
  
  TGraph *Y2S_grTempVsTauL =(TGraph*)file_Y2S->Get("grTempVsTauL");
  Y2S_grTempVsTauL->SetLineColor(2);
  Y2S_grTempVsTauL->SetLineStyle(1);
  Y2S_grTempVsTauL->SetLineWidth(2);
  
  TGraph *Y2S_grTempVsTauC =(TGraph*)file_Y2S->Get("grTempVsTauC");
  Y2S_grTempVsTauC->SetLineColor(4);
  Y2S_grTempVsTauC->SetLineStyle(2);
  Y2S_grTempVsTauC->SetLineWidth(2);
  
  
  TGraph *Y2S_grFQGPVsTauL =(TGraph*)file_Y2S->Get("grFQGPVsTauL");
  Y2S_grFQGPVsTauL->SetLineColor(2);
  Y2S_grFQGPVsTauL->SetLineStyle(1);
  Y2S_grFQGPVsTauL->SetLineWidth(2);
  
  
  TGraph *Y2S_grFQGPVsTauC =(TGraph*)file_Y2S->Get("grFQGPVsTauC");
  Y2S_grFQGPVsTauC->SetLineColor(4);
  Y2S_grFQGPVsTauC->SetLineStyle(2);
  Y2S_grFQGPVsTauC->SetLineWidth(2);
  

  
  // ====== Cross Section graphs ==============================//
  TGraph *Y2S_grSigDQ0 =(TGraph*)file_Y2S->Get("grSigDQ0");
  Y2S_grSigDQ0->SetLineColor(2);
  Y2S_grSigDQ0->SetLineStyle(1);
  Y2S_grSigDQ0->SetLineWidth(2);
  
  TGraph *Y2S_grSigDS =(TGraph*)file_Y2S->Get("grSigD");
  Y2S_grSigDS->SetLineColor(2);
  Y2S_grSigDS->SetLineStyle(1);
  Y2S_grSigDS->SetLineWidth(2);
  
  TGraph *Y2S_grSigFS =(TGraph*)file_Y2S->Get("grSigF");
  Y2S_grSigFS->SetLineColor(4);
  Y2S_grSigFS->SetLineStyle(2);
  Y2S_grSigFS->SetLineWidth(2);
  
  

  // ====== Dissociation rate graphs ==============================//
  
  
  TGraph *Y2S_DissRateVsT_KharPt0 =(TGraph*)file_Y2S->Get("DissRateVsT_KharPt0");
  Y2S_DissRateVsT_KharPt0->SetLineColor(1);
  Y2S_DissRateVsT_KharPt0->SetLineStyle(1);
  Y2S_DissRateVsT_KharPt0->SetLineWidth(2);
  
  TGraph *Y2S_DissRateVsT_KharPt36 =(TGraph*)file_Y2S->Get("DissRateVsT_KharPt36");
  Y2S_DissRateVsT_KharPt36->SetLineColor(4);
  Y2S_DissRateVsT_KharPt36->SetLineStyle(4);
  Y2S_DissRateVsT_KharPt36->SetLineWidth(2);
  
  
  TGraph *Y2S_DissRateVsT_KharPt86 =(TGraph*)file_Y2S->Get("DissRateVsT_KharPt86");
  Y2S_DissRateVsT_KharPt86->SetLineColor(2);
  Y2S_DissRateVsT_KharPt86->SetLineStyle(2);
  Y2S_DissRateVsT_KharPt86->SetLineWidth(2);
  
  
  
  TGraph *Y2S_grDissRateVsPt_T200 =(TGraph*)file_Y2S->Get("grDissRateVsPt_T200");
  Y2S_grDissRateVsPt_T200->SetLineColor(1);
  Y2S_grDissRateVsPt_T200->SetLineStyle(1);
  Y2S_grDissRateVsPt_T200->SetLineWidth(2);
  
  
  TGraph *Y2S_grDissRateVsPt_T400 =(TGraph*)file_Y2S->Get("grDissRateVsPt_T400");
  Y2S_grDissRateVsPt_T400->SetLineColor(4);
  Y2S_grDissRateVsPt_T400->SetLineStyle(4);
  Y2S_grDissRateVsPt_T400->SetLineWidth(2);
  
  TGraph *Y2S_grDissRateVsPt_T600 =(TGraph*)file_Y2S->Get("grDissRateVsPt_T600");
  Y2S_grDissRateVsPt_T600->SetLineColor(2);
  Y2S_grDissRateVsPt_T600->SetLineStyle(2);
  Y2S_grDissRateVsPt_T600->SetLineWidth(2);

  
  
  // ====== Formation rate graphs ==============================//

  TGraph *Y2S_grFormRateVsT_MCInt_P1 =(TGraph*)file_Y2S->Get("grFormRateVsT_MCInt_P1");
  Y2S_grFormRateVsT_MCInt_P1->SetLineColor(1);
  Y2S_grFormRateVsT_MCInt_P1->SetLineStyle(1);
  Y2S_grFormRateVsT_MCInt_P1->SetLineWidth(2);
  
  
  TGraph *Y2S_grFormRateVsT_MCInt_P2 =(TGraph*)file_Y2S->Get("grFormRateVsT_MCInt_P2");
  Y2S_grFormRateVsT_MCInt_P2->SetLineColor(4);
  Y2S_grFormRateVsT_MCInt_P2->SetLineStyle(4);
  Y2S_grFormRateVsT_MCInt_P2->SetLineWidth(2);
  
  
  TGraph *Y2S_grFormRateVsT_MCInt_P3 =(TGraph*)file_Y2S->Get("grFormRateVsT_MCInt_P3");
  Y2S_grFormRateVsT_MCInt_P3->SetLineColor(2);
  Y2S_grFormRateVsT_MCInt_P3->SetLineStyle(2);
  Y2S_grFormRateVsT_MCInt_P3->SetLineWidth(2);
  

  
  TGraph *Y2S_grFormRateVsP_MCInt_T1 =(TGraph*)file_Y2S->Get("grFormRateVsP_MCInt_T1");
  Y2S_grFormRateVsP_MCInt_T1->SetLineColor(1);
  Y2S_grFormRateVsP_MCInt_T1->SetLineStyle(1);
  Y2S_grFormRateVsP_MCInt_T1->SetLineWidth(2);
  
  TGraph *Y2S_grFormRateVsP_MCInt_T2 =(TGraph*)file_Y2S->Get("grFormRateVsP_MCInt_T2");
  Y2S_grFormRateVsP_MCInt_T2->SetLineColor(4);
  Y2S_grFormRateVsP_MCInt_T2->SetLineStyle(4);
  Y2S_grFormRateVsP_MCInt_T2->SetLineWidth(2);

  TGraph *Y2S_grFormRateVsP_MCInt_T3 =(TGraph*)file_Y2S->Get("grFormRateVsP_MCInt_T3");
  Y2S_grFormRateVsP_MCInt_T3->SetLineColor(2);
  Y2S_grFormRateVsP_MCInt_T3->SetLineStyle(2);
  Y2S_grFormRateVsP_MCInt_T3->SetLineWidth(2);
  

  //============================ RAA Graphs =======================//
  
  
 //============================ ALICE RAA Vs Pt Graphs =======================//
  
  TGraph *Y2S_grGluonDissALICEPt_M =(TGraph*)file_Y2S->Get("grGluonDissALICEPt_M");
  Y2S_grGluonDissALICEPt_M->SetLineColor(2);
  Y2S_grGluonDissALICEPt_M->SetLineStyle(2);
  Y2S_grGluonDissALICEPt_M->SetLineWidth(2);

  
  TGraph *Y2S_grPionDissALICEPt_M =(TGraph*)file_Y2S->Get("grPionDissALICEPt_M");
  Y2S_grPionDissALICEPt_M->SetLineColor(4);
  Y2S_grPionDissALICEPt_M->SetLineStyle(4);
  Y2S_grPionDissALICEPt_M->SetLineWidth(2);


  TGraph *Y2S_grRegenALICEPt_M =(TGraph*)file_Y2S->Get("grRegenALICEPt_M");
  Y2S_grRegenALICEPt_M->SetLineColor(8);
  Y2S_grRegenALICEPt_M->SetLineStyle(9);
  Y2S_grRegenALICEPt_M->SetLineWidth(2);



  TGraph *Y2S_grRAAALICEPt_M =(TGraph*)file_Y2S->Get("grRAAALICEPt_M");
  Y2S_grRAAALICEPt_M->SetLineColor(1);
  Y2S_grRAAALICEPt_M->SetLineStyle(1);
  Y2S_grRAAALICEPt_M->SetLineWidth(2);


 //============================ CMS RAA Vs Pt Graphs =======================//

  TGraph *Y2S_grGluonDissCMSPt_M =(TGraph*)file_Y2S->Get("grGluonDissCMSPt_M");
  Y2S_grGluonDissCMSPt_M->SetLineColor(2);
  Y2S_grGluonDissCMSPt_M->SetLineStyle(2);
  Y2S_grGluonDissCMSPt_M->SetLineWidth(2);


  TGraph *Y2S_grPionDissCMSPt_M =(TGraph*)file_Y2S->Get("grPionDissCMSPt_M");
  Y2S_grPionDissCMSPt_M->SetLineColor(4);
  Y2S_grPionDissCMSPt_M->SetLineStyle(4);
  Y2S_grPionDissCMSPt_M->SetLineWidth(2);


  TGraph *Y2S_grRegenCMSPt_M =(TGraph*)file_Y2S->Get("grRegenCMSPt_M");
  Y2S_grRegenCMSPt_M->SetLineColor(8);
  Y2S_grRegenCMSPt_M->SetLineStyle(9);
  Y2S_grRegenCMSPt_M->SetLineWidth(2);



  TGraph *Y2S_grRAACMSPt_M =(TGraph*)file_Y2S->Get("grRAACMSPt_M");
  Y2S_grRAACMSPt_M->SetLineColor(1);
  Y2S_grRAACMSPt_M->SetLineStyle(1);
  Y2S_grRAACMSPt_M->SetLineWidth(2);

 //============================ ALICE RAA Vs NPart Graphs =======================//

 
  TGraph *Y2S_grGluonDissALICENPart_M =(TGraph*)file_Y2S->Get("grDissALICE_M");
  Y2S_grGluonDissALICENPart_M->SetLineColor(2);
  Y2S_grGluonDissALICENPart_M->SetLineStyle(2);
  Y2S_grGluonDissALICENPart_M->SetLineWidth(2);


  TGraph *Y2S_grPionDissALICENPart_M =(TGraph*)file_Y2S->Get("grPionDissALICE_M");
  Y2S_grPionDissALICENPart_M->SetLineColor(4);
  Y2S_grPionDissALICENPart_M->SetLineStyle(4);
  Y2S_grPionDissALICENPart_M->SetLineWidth(2);


  TGraph *Y2S_grRegenALICENPart_M =(TGraph*)file_Y2S->Get("grFormALICE_M");
  Y2S_grRegenALICENPart_M->SetLineColor(8);
  Y2S_grRegenALICENPart_M->SetLineStyle(9);
  Y2S_grRegenALICENPart_M->SetLineWidth(2);



  TGraph *Y2S_grRAAALICENPart_M =(TGraph*)file_Y2S->Get("grRAAALICE_M");
  Y2S_grRAAALICENPart_M->SetLineColor(1);
  Y2S_grRAAALICENPart_M->SetLineStyle(1);
  Y2S_grRAAALICENPart_M->SetLineWidth(2);



//============================ CMS RAA Vs NPart Graphs =======================//

 
  TGraph *Y2S_grGluonDissCMSNPart_M =(TGraph*)file_Y2S->Get("grDissCMS_M");
  Y2S_grGluonDissCMSNPart_M->SetLineColor(2);
  Y2S_grGluonDissCMSNPart_M->SetLineStyle(2);
  Y2S_grGluonDissCMSNPart_M->SetLineWidth(2);


  TGraph *Y2S_grPionDissCMSNPart_M =(TGraph*)file_Y2S->Get("grPionDissCMS_M");
  Y2S_grPionDissCMSNPart_M->SetLineColor(4);
  Y2S_grPionDissCMSNPart_M->SetLineStyle(4);
  Y2S_grPionDissCMSNPart_M->SetLineWidth(2);


  TGraph *Y2S_grRegenCMSNPart_M =(TGraph*)file_Y2S->Get("grFormCMS_M");
  Y2S_grRegenCMSNPart_M->SetLineColor(8);
  Y2S_grRegenCMSNPart_M->SetLineStyle(9);
  Y2S_grRegenCMSNPart_M->SetLineWidth(2);



  TGraph *Y2S_grRAACMSNPart_M =(TGraph*)file_Y2S->Get("grRAACMS_M");
  Y2S_grRAACMSNPart_M->SetLineColor(1);
  Y2S_grRAACMSNPart_M->SetLineStyle(1);
  Y2S_grRAACMSNPart_M->SetLineWidth(2);



//================================ Open Y3S Root File ================================================//
  TFile *file_Y3S = new TFile("05052014_Y3SCalculations.root","R");
  

  // ====== Event Variable Graphs  ==============================//
  
  TGraph *Y3S_grTempVsTauL =(TGraph*)file_Y3S->Get("grTempVsTauL");
  Y3S_grTempVsTauL->SetLineColor(2);
  Y3S_grTempVsTauL->SetLineStyle(1);
  Y3S_grTempVsTauL->SetLineWidth(2);
  
  TGraph *Y3S_grTempVsTauC =(TGraph*)file_Y3S->Get("grTempVsTauC");
  Y3S_grTempVsTauC->SetLineColor(4);
  Y3S_grTempVsTauC->SetLineStyle(2);
  Y3S_grTempVsTauC->SetLineWidth(2);
  
  
  TGraph *Y3S_grFQGPVsTauL =(TGraph*)file_Y3S->Get("grFQGPVsTauL");
  Y3S_grFQGPVsTauL->SetLineColor(2);
  Y3S_grFQGPVsTauL->SetLineStyle(1);
  Y3S_grFQGPVsTauL->SetLineWidth(2);
  
  
  TGraph *Y3S_grFQGPVsTauC =(TGraph*)file_Y3S->Get("grFQGPVsTauC");
  Y3S_grFQGPVsTauC->SetLineColor(4);
  Y3S_grFQGPVsTauC->SetLineStyle(2);
  Y3S_grFQGPVsTauC->SetLineWidth(2);
  

  
  // ====== Cross Section graphs ==============================//
  TGraph *Y3S_grSigDQ0 =(TGraph*)file_Y3S->Get("grSigDQ0");
  Y3S_grSigDQ0->SetLineColor(2);
  Y3S_grSigDQ0->SetLineStyle(1);
  Y3S_grSigDQ0->SetLineWidth(2);
  
  TGraph *Y3S_grSigDS =(TGraph*)file_Y3S->Get("grSigD");
  Y3S_grSigDS->SetLineColor(2);
  Y3S_grSigDS->SetLineStyle(1);
  Y3S_grSigDS->SetLineWidth(2);
  
  TGraph *Y3S_grSigFS =(TGraph*)file_Y3S->Get("grSigF");
  Y3S_grSigFS->SetLineColor(4);
  Y3S_grSigFS->SetLineStyle(2);
  Y3S_grSigFS->SetLineWidth(2);
  
  

  // ====== Dissociation rate graphs ==============================//
  
  
  TGraph *Y3S_DissRateVsT_KharPt0 =(TGraph*)file_Y3S->Get("DissRateVsT_KharPt0");
  Y3S_DissRateVsT_KharPt0->SetLineColor(1);
  Y3S_DissRateVsT_KharPt0->SetLineStyle(1);
  Y3S_DissRateVsT_KharPt0->SetLineWidth(2);
  
  TGraph *Y3S_DissRateVsT_KharPt36 =(TGraph*)file_Y3S->Get("DissRateVsT_KharPt36");
  Y3S_DissRateVsT_KharPt36->SetLineColor(4);
  Y3S_DissRateVsT_KharPt36->SetLineStyle(4);
  Y3S_DissRateVsT_KharPt36->SetLineWidth(2);
  
  
  TGraph *Y3S_DissRateVsT_KharPt86 =(TGraph*)file_Y3S->Get("DissRateVsT_KharPt86");
  Y3S_DissRateVsT_KharPt86->SetLineColor(2);
  Y3S_DissRateVsT_KharPt86->SetLineStyle(2);
  Y3S_DissRateVsT_KharPt86->SetLineWidth(2);
  
  
  
  TGraph *Y3S_grDissRateVsPt_T200 =(TGraph*)file_Y3S->Get("grDissRateVsPt_T200");
  Y3S_grDissRateVsPt_T200->SetLineColor(1);
  Y3S_grDissRateVsPt_T200->SetLineStyle(1);
  Y3S_grDissRateVsPt_T200->SetLineWidth(2);
  
  
  TGraph *Y3S_grDissRateVsPt_T400 =(TGraph*)file_Y3S->Get("grDissRateVsPt_T400");
  Y3S_grDissRateVsPt_T400->SetLineColor(4);
  Y3S_grDissRateVsPt_T400->SetLineStyle(4);
  Y3S_grDissRateVsPt_T400->SetLineWidth(2);
  
  TGraph *Y3S_grDissRateVsPt_T600 =(TGraph*)file_Y3S->Get("grDissRateVsPt_T600");
  Y3S_grDissRateVsPt_T600->SetLineColor(2);
  Y3S_grDissRateVsPt_T600->SetLineStyle(2);
  Y3S_grDissRateVsPt_T600->SetLineWidth(2);

  
  
  // ====== Formation rate graphs ==============================//

  TGraph *Y3S_grFormRateVsT_MCInt_P1 =(TGraph*)file_Y3S->Get("grFormRateVsT_MCInt_P1");
  Y3S_grFormRateVsT_MCInt_P1->SetLineColor(1);
  Y3S_grFormRateVsT_MCInt_P1->SetLineStyle(1);
  Y3S_grFormRateVsT_MCInt_P1->SetLineWidth(2);
  
  
  TGraph *Y3S_grFormRateVsT_MCInt_P2 =(TGraph*)file_Y3S->Get("grFormRateVsT_MCInt_P2");
  Y3S_grFormRateVsT_MCInt_P2->SetLineColor(4);
  Y3S_grFormRateVsT_MCInt_P2->SetLineStyle(4);
  Y3S_grFormRateVsT_MCInt_P2->SetLineWidth(2);
  
  
  TGraph *Y3S_grFormRateVsT_MCInt_P3 =(TGraph*)file_Y3S->Get("grFormRateVsT_MCInt_P3");
  Y3S_grFormRateVsT_MCInt_P3->SetLineColor(2);
  Y3S_grFormRateVsT_MCInt_P3->SetLineStyle(2);
  Y3S_grFormRateVsT_MCInt_P3->SetLineWidth(2);
  

  
  TGraph *Y3S_grFormRateVsP_MCInt_T1 =(TGraph*)file_Y3S->Get("grFormRateVsP_MCInt_T1");
  Y3S_grFormRateVsP_MCInt_T1->SetLineColor(1);
  Y3S_grFormRateVsP_MCInt_T1->SetLineStyle(1);
  Y3S_grFormRateVsP_MCInt_T1->SetLineWidth(2);
  
  TGraph *Y3S_grFormRateVsP_MCInt_T2 =(TGraph*)file_Y3S->Get("grFormRateVsP_MCInt_T2");
  Y3S_grFormRateVsP_MCInt_T2->SetLineColor(4);
  Y3S_grFormRateVsP_MCInt_T2->SetLineStyle(4);
  Y3S_grFormRateVsP_MCInt_T2->SetLineWidth(2);

  TGraph *Y3S_grFormRateVsP_MCInt_T3 =(TGraph*)file_Y3S->Get("grFormRateVsP_MCInt_T3");
  Y3S_grFormRateVsP_MCInt_T3->SetLineColor(2);
  Y3S_grFormRateVsP_MCInt_T3->SetLineStyle(2);
  Y3S_grFormRateVsP_MCInt_T3->SetLineWidth(2);
  

  //============================ RAA Graphs =======================//
  
  
 //============================ ALICE RAA Vs Pt Graphs =======================//
  
  TGraph *Y3S_grGluonDissALICEPt_M =(TGraph*)file_Y3S->Get("grGluonDissALICEPt_M");
  Y3S_grGluonDissALICEPt_M->SetLineColor(2);
  Y3S_grGluonDissALICEPt_M->SetLineStyle(2);
  Y3S_grGluonDissALICEPt_M->SetLineWidth(2);

  
  TGraph *Y3S_grPionDissALICEPt_M =(TGraph*)file_Y3S->Get("grPionDissALICEPt_M");
  Y3S_grPionDissALICEPt_M->SetLineColor(4);
  Y3S_grPionDissALICEPt_M->SetLineStyle(4);
  Y3S_grPionDissALICEPt_M->SetLineWidth(2);


  TGraph *Y3S_grRegenALICEPt_M =(TGraph*)file_Y3S->Get("grRegenALICEPt_M");
  Y3S_grRegenALICEPt_M->SetLineColor(8);
  Y3S_grRegenALICEPt_M->SetLineStyle(9);
  Y3S_grRegenALICEPt_M->SetLineWidth(2);



  TGraph *Y3S_grRAAALICEPt_M =(TGraph*)file_Y3S->Get("grRAAALICEPt_M");
  Y3S_grRAAALICEPt_M->SetLineColor(1);
  Y3S_grRAAALICEPt_M->SetLineStyle(1);
  Y3S_grRAAALICEPt_M->SetLineWidth(2);


 //============================ CMS RAA Vs Pt Graphs =======================//

  TGraph *Y3S_grGluonDissCMSPt_M =(TGraph*)file_Y3S->Get("grGluonDissCMSPt_M");
  Y3S_grGluonDissCMSPt_M->SetLineColor(2);
  Y3S_grGluonDissCMSPt_M->SetLineStyle(2);
  Y3S_grGluonDissCMSPt_M->SetLineWidth(2);


  TGraph *Y3S_grPionDissCMSPt_M =(TGraph*)file_Y3S->Get("grPionDissCMSPt_M");
  Y3S_grPionDissCMSPt_M->SetLineColor(4);
  Y3S_grPionDissCMSPt_M->SetLineStyle(4);
  Y3S_grPionDissCMSPt_M->SetLineWidth(2);


  TGraph *Y3S_grRegenCMSPt_M =(TGraph*)file_Y3S->Get("grRegenCMSPt_M");
  Y3S_grRegenCMSPt_M->SetLineColor(8);
  Y3S_grRegenCMSPt_M->SetLineStyle(9);
  Y3S_grRegenCMSPt_M->SetLineWidth(2);



  TGraph *Y3S_grRAACMSPt_M =(TGraph*)file_Y3S->Get("grRAACMSPt_M");
  Y3S_grRAACMSPt_M->SetLineColor(1);
  Y3S_grRAACMSPt_M->SetLineStyle(1);
  Y3S_grRAACMSPt_M->SetLineWidth(2);

 //============================ ALICE RAA Vs NPart Graphs =======================//

 
  TGraph *Y3S_grGluonDissALICENPart_M =(TGraph*)file_Y3S->Get("grDissALICE_M");
  Y3S_grGluonDissALICENPart_M->SetLineColor(2);
  Y3S_grGluonDissALICENPart_M->SetLineStyle(2);
  Y3S_grGluonDissALICENPart_M->SetLineWidth(2);


  TGraph *Y3S_grPionDissALICENPart_M =(TGraph*)file_Y3S->Get("grPionDissALICE_M");
  Y3S_grPionDissALICENPart_M->SetLineColor(4);
  Y3S_grPionDissALICENPart_M->SetLineStyle(4);
  Y3S_grPionDissALICENPart_M->SetLineWidth(2);


  TGraph *Y3S_grRegenALICENPart_M =(TGraph*)file_Y3S->Get("grFormALICE_M");
  Y3S_grRegenALICENPart_M->SetLineColor(8);
  Y3S_grRegenALICENPart_M->SetLineStyle(9);
  Y3S_grRegenALICENPart_M->SetLineWidth(2);



  TGraph *Y3S_grRAAALICENPart_M =(TGraph*)file_Y3S->Get("grRAAALICE_M");
  Y3S_grRAAALICENPart_M->SetLineColor(1);
  Y3S_grRAAALICENPart_M->SetLineStyle(1);
  Y3S_grRAAALICENPart_M->SetLineWidth(2);



//============================ CMS RAA Vs NPart Graphs =======================//

 
  TGraph *Y3S_grGluonDissCMSNPart_M =(TGraph*)file_Y3S->Get("grDissCMS_M");
  Y3S_grGluonDissCMSNPart_M->SetLineColor(2);
  Y3S_grGluonDissCMSNPart_M->SetLineStyle(2);
  Y3S_grGluonDissCMSNPart_M->SetLineWidth(2);


  TGraph *Y3S_grPionDissCMSNPart_M =(TGraph*)file_Y3S->Get("grPionDissCMS_M");
  Y3S_grPionDissCMSNPart_M->SetLineColor(4);
  Y3S_grPionDissCMSNPart_M->SetLineStyle(4);
  Y3S_grPionDissCMSNPart_M->SetLineWidth(2);


  TGraph *Y3S_grRegenCMSNPart_M =(TGraph*)file_Y3S->Get("grFormCMS_M");
  Y3S_grRegenCMSNPart_M->SetLineColor(8);
  Y3S_grRegenCMSNPart_M->SetLineStyle(9);
  Y3S_grRegenCMSNPart_M->SetLineWidth(2);



  TGraph *Y3S_grRAACMSNPart_M =(TGraph*)file_Y3S->Get("grRAACMS_M");
  Y3S_grRAACMSNPart_M->SetLineColor(1);
  Y3S_grRAACMSNPart_M->SetLineStyle(1);
  Y3S_grRAACMSNPart_M->SetLineWidth(2);







  //================================ Open Y1S Root File ================================================//
  TFile *file_Y1S = new TFile("05052014_Y1SCalculations.root","R");
  

  // ====== Event Variable Graphs  ==============================//
  
  TGraph *Y1S_grTempVsTauL =(TGraph*)file_Y1S->Get("grTempVsTauL");
  Y1S_grTempVsTauL->SetLineColor(2);
  Y1S_grTempVsTauL->SetLineStyle(1);
  Y1S_grTempVsTauL->SetLineWidth(2);
  
  TGraph *Y1S_grTempVsTauC =(TGraph*)file_Y1S->Get("grTempVsTauC");
  Y1S_grTempVsTauC->SetLineColor(4);
  Y1S_grTempVsTauC->SetLineStyle(2);
  Y1S_grTempVsTauC->SetLineWidth(2);
  
  
  TGraph *Y1S_grFQGPVsTauL =(TGraph*)file_Y1S->Get("grFQGPVsTauL");
  Y1S_grFQGPVsTauL->SetLineColor(2);
  Y1S_grFQGPVsTauL->SetLineStyle(1);
  Y1S_grFQGPVsTauL->SetLineWidth(2);
  
  
  TGraph *Y1S_grFQGPVsTauC =(TGraph*)file_Y1S->Get("grFQGPVsTauC");
  Y1S_grFQGPVsTauC->SetLineColor(4);
  Y1S_grFQGPVsTauC->SetLineStyle(2);
  Y1S_grFQGPVsTauC->SetLineWidth(2);
  

  
  // ====== Cross Section graphs ==============================//
  TGraph *Y1S_grSigDQ0 =(TGraph*)file_Y1S->Get("grSigDQ0");
  Y1S_grSigDQ0->SetLineColor(2);
  Y1S_grSigDQ0->SetLineStyle(1);
  Y1S_grSigDQ0->SetLineWidth(2);
  
  TGraph *Y1S_grSigDS =(TGraph*)file_Y1S->Get("grSigD");
  Y1S_grSigDS->SetLineColor(2);
  Y1S_grSigDS->SetLineStyle(1);
  Y1S_grSigDS->SetLineWidth(2);
  
  TGraph *Y1S_grSigFS =(TGraph*)file_Y1S->Get("grSigF");
  Y1S_grSigFS->SetLineColor(4);
  Y1S_grSigFS->SetLineStyle(2);
  Y1S_grSigFS->SetLineWidth(2);
  
  

  // ====== Dissociation rate graphs ==============================//
  
  
  TGraph *Y1S_DissRateVsT_KharPt0 =(TGraph*)file_Y1S->Get("DissRateVsT_KharPt0");
  Y1S_DissRateVsT_KharPt0->SetLineColor(1);
  Y1S_DissRateVsT_KharPt0->SetLineStyle(1);
  Y1S_DissRateVsT_KharPt0->SetLineWidth(2);
  
  TGraph *Y1S_DissRateVsT_KharPt36 =(TGraph*)file_Y1S->Get("DissRateVsT_KharPt36");
  Y1S_DissRateVsT_KharPt36->SetLineColor(4);
  Y1S_DissRateVsT_KharPt36->SetLineStyle(4);
  Y1S_DissRateVsT_KharPt36->SetLineWidth(2);
  
  
  TGraph *Y1S_DissRateVsT_KharPt86 =(TGraph*)file_Y1S->Get("DissRateVsT_KharPt86");
  Y1S_DissRateVsT_KharPt86->SetLineColor(2);
  Y1S_DissRateVsT_KharPt86->SetLineStyle(2);
  Y1S_DissRateVsT_KharPt86->SetLineWidth(2);
  
  
  
  TGraph *Y1S_grDissRateVsPt_T200 =(TGraph*)file_Y1S->Get("grDissRateVsPt_T200");
  Y1S_grDissRateVsPt_T200->SetLineColor(1);
  Y1S_grDissRateVsPt_T200->SetLineStyle(1);
  Y1S_grDissRateVsPt_T200->SetLineWidth(2);
  
  
  TGraph *Y1S_grDissRateVsPt_T400 =(TGraph*)file_Y1S->Get("grDissRateVsPt_T400");
  Y1S_grDissRateVsPt_T400->SetLineColor(4);
  Y1S_grDissRateVsPt_T400->SetLineStyle(4);
  Y1S_grDissRateVsPt_T400->SetLineWidth(2);
  
  TGraph *Y1S_grDissRateVsPt_T600 =(TGraph*)file_Y1S->Get("grDissRateVsPt_T600");
  Y1S_grDissRateVsPt_T600->SetLineColor(2);
  Y1S_grDissRateVsPt_T600->SetLineStyle(2);
  Y1S_grDissRateVsPt_T600->SetLineWidth(2);

  
  
  // ====== Formation rate graphs ==============================//

  TGraph *Y1S_grFormRateVsT_MCInt_P1 =(TGraph*)file_Y1S->Get("grFormRateVsT_MCInt_P1");
  Y1S_grFormRateVsT_MCInt_P1->SetLineColor(1);
  Y1S_grFormRateVsT_MCInt_P1->SetLineStyle(1);
  Y1S_grFormRateVsT_MCInt_P1->SetLineWidth(2);
  
  
  TGraph *Y1S_grFormRateVsT_MCInt_P2 =(TGraph*)file_Y1S->Get("grFormRateVsT_MCInt_P2");
  Y1S_grFormRateVsT_MCInt_P2->SetLineColor(4);
  Y1S_grFormRateVsT_MCInt_P2->SetLineStyle(4);
  Y1S_grFormRateVsT_MCInt_P2->SetLineWidth(2);
  
  
  TGraph *Y1S_grFormRateVsT_MCInt_P3 =(TGraph*)file_Y1S->Get("grFormRateVsT_MCInt_P3");
  Y1S_grFormRateVsT_MCInt_P3->SetLineColor(2);
  Y1S_grFormRateVsT_MCInt_P3->SetLineStyle(2);
  Y1S_grFormRateVsT_MCInt_P3->SetLineWidth(2);
  

  
  TGraph *Y1S_grFormRateVsP_MCInt_T1 =(TGraph*)file_Y1S->Get("grFormRateVsP_MCInt_T1");
  Y1S_grFormRateVsP_MCInt_T1->SetLineColor(1);
  Y1S_grFormRateVsP_MCInt_T1->SetLineStyle(1);
  Y1S_grFormRateVsP_MCInt_T1->SetLineWidth(2);
  
  TGraph *Y1S_grFormRateVsP_MCInt_T2 =(TGraph*)file_Y1S->Get("grFormRateVsP_MCInt_T2");
  Y1S_grFormRateVsP_MCInt_T2->SetLineColor(4);
  Y1S_grFormRateVsP_MCInt_T2->SetLineStyle(4);
  Y1S_grFormRateVsP_MCInt_T2->SetLineWidth(2);

  TGraph *Y1S_grFormRateVsP_MCInt_T3 =(TGraph*)file_Y1S->Get("grFormRateVsP_MCInt_T3");
  Y1S_grFormRateVsP_MCInt_T3->SetLineColor(2);
  Y1S_grFormRateVsP_MCInt_T3->SetLineStyle(2);
  Y1S_grFormRateVsP_MCInt_T3->SetLineWidth(2);
  

  //============================ RAA Graphs =======================//
  
  
 //============================ ALICE RAA Vs Pt Graphs =======================//
  
  TGraph *Y1S_grGluonDissALICEPt_M =(TGraph*)file_Y1S->Get("grGluonDissALICEPt_M");
  Y1S_grGluonDissALICEPt_M->SetLineColor(2);
  Y1S_grGluonDissALICEPt_M->SetLineStyle(2);
  Y1S_grGluonDissALICEPt_M->SetLineWidth(2);

  
  TGraph *Y1S_grPionDissALICEPt_M =(TGraph*)file_Y1S->Get("grPionDissALICEPt_M");
  Y1S_grPionDissALICEPt_M->SetLineColor(4);
  Y1S_grPionDissALICEPt_M->SetLineStyle(4);
  Y1S_grPionDissALICEPt_M->SetLineWidth(2);


  TGraph *Y1S_grRegenALICEPt_M =(TGraph*)file_Y1S->Get("grRegenALICEPt_M");
  Y1S_grRegenALICEPt_M->SetLineColor(8);
  Y1S_grRegenALICEPt_M->SetLineStyle(9);
  Y1S_grRegenALICEPt_M->SetLineWidth(2);



  TGraph *Y1S_grRAAALICEPt_M =(TGraph*)file_Y1S->Get("grRAAALICEPt_M");
  Y1S_grRAAALICEPt_M->SetLineColor(1);
  Y1S_grRAAALICEPt_M->SetLineStyle(1);
  Y1S_grRAAALICEPt_M->SetLineWidth(2);


 //============================ CMS RAA Vs Pt Graphs =======================//

  TGraph *Y1S_grGluonDissCMSPt_M =(TGraph*)file_Y1S->Get("grGluonDissCMSPt_M");
  Y1S_grGluonDissCMSPt_M->SetLineColor(2);
  Y1S_grGluonDissCMSPt_M->SetLineStyle(2);
  Y1S_grGluonDissCMSPt_M->SetLineWidth(2);


  TGraph *Y1S_grPionDissCMSPt_M =(TGraph*)file_Y1S->Get("grPionDissCMSPt_M");
  Y1S_grPionDissCMSPt_M->SetLineColor(4);
  Y1S_grPionDissCMSPt_M->SetLineStyle(4);
  Y1S_grPionDissCMSPt_M->SetLineWidth(2);


  TGraph *Y1S_grRegenCMSPt_M =(TGraph*)file_Y1S->Get("grRegenCMSPt_M");
  Y1S_grRegenCMSPt_M->SetLineColor(8);
  Y1S_grRegenCMSPt_M->SetLineStyle(9);
  Y1S_grRegenCMSPt_M->SetLineWidth(2);



  TGraph *Y1S_grRAACMSPt_M =(TGraph*)file_Y1S->Get("grRAACMSPt_M");
  Y1S_grRAACMSPt_M->SetLineColor(1);
  Y1S_grRAACMSPt_M->SetLineStyle(1);
  Y1S_grRAACMSPt_M->SetLineWidth(2);

 //============================ ALICE RAA Vs NPart Graphs =======================//

 
  TGraph *Y1S_grGluonDissALICENPart_M =(TGraph*)file_Y1S->Get("grDissALICE_M");
  Y1S_grGluonDissALICENPart_M->SetLineColor(2);
  Y1S_grGluonDissALICENPart_M->SetLineStyle(2);
  Y1S_grGluonDissALICENPart_M->SetLineWidth(2);


  TGraph *Y1S_grPionDissALICENPart_M =(TGraph*)file_Y1S->Get("grPionDissALICE_M");
  Y1S_grPionDissALICENPart_M->SetLineColor(4);
  Y1S_grPionDissALICENPart_M->SetLineStyle(4);
  Y1S_grPionDissALICENPart_M->SetLineWidth(2);


  TGraph *Y1S_grRegenALICENPart_M =(TGraph*)file_Y1S->Get("grFormALICE_M");
  Y1S_grRegenALICENPart_M->SetLineColor(8);
  Y1S_grRegenALICENPart_M->SetLineStyle(9);
  Y1S_grRegenALICENPart_M->SetLineWidth(2);



  TGraph *Y1S_grRAAALICENPart_M =(TGraph*)file_Y1S->Get("grRAAALICE_M");
  Y1S_grRAAALICENPart_M->SetLineColor(1);
  Y1S_grRAAALICENPart_M->SetLineStyle(1);
  Y1S_grRAAALICENPart_M->SetLineWidth(2);



//============================ CMS RAA Vs NPart Graphs =======================//

 
  TGraph *Y1S_grGluonDissCMSNPart_M =(TGraph*)file_Y1S->Get("grDissCMS_M");
  Y1S_grGluonDissCMSNPart_M->SetLineColor(2);
  Y1S_grGluonDissCMSNPart_M->SetLineStyle(2);
  Y1S_grGluonDissCMSNPart_M->SetLineWidth(2);


  TGraph *Y1S_grPionDissCMSNPart_M =(TGraph*)file_Y1S->Get("grPionDissCMS_M");
  Y1S_grPionDissCMSNPart_M->SetLineColor(4);
  Y1S_grPionDissCMSNPart_M->SetLineStyle(4);
  Y1S_grPionDissCMSNPart_M->SetLineWidth(2);


  TGraph *Y1S_grRegenCMSNPart_M =(TGraph*)file_Y1S->Get("grFormCMS_M");
  Y1S_grRegenCMSNPart_M->SetLineColor(8);
  Y1S_grRegenCMSNPart_M->SetLineStyle(9);
  Y1S_grRegenCMSNPart_M->SetLineWidth(2);



  TGraph *Y1S_grRAACMSNPart_M =(TGraph*)file_Y1S->Get("grRAACMS_M");
  Y1S_grRAACMSNPart_M->SetLineColor(1);
  Y1S_grRAACMSNPart_M->SetLineStyle(1);
  Y1S_grRAACMSNPart_M->SetLineWidth(2);


 //=========================  Now make feed-down corrections in Upsilon =========================//
 Double_t ChiBFactor = 0.27;
 Double_t Y3SFactor = 0.113;
 Double_t Y2SFactor = 0.107;
 Double_t Y1SFactor = 0.509;




//============== CMS RAA Vs NPart Y1S ====================//


for (int j=0; j < Y1S_grRAACMSNPart_M->GetN();++j){
    Double_t x0,y0;
    Double_t x1,y1;
    Double_t x2,y2;
    Double_t x3,y3;
    Double_t x4,y4;
    
    Y1S_grRAACMSNPart_M->GetPoint(j,x1,y1);
    Y2S_grRAACMSNPart_M->GetPoint(j,x2,y2);
    ChiB_grRAACMSNPart_M->GetPoint(j,x3,y3);
    Y3S_grRAACMSNPart_M->GetPoint(j,x4,y4);

    x0=x1;
    y0=Y1SFactor*y1 + Y2SFactor*y2 + ChiBFactor*y3 + Y3SFactor*y4 ;
    
    Y1S_grRAACMSNPart_M->SetPoint(j,x0,y0);  

    Y1S_grGluonDissCMSNPart_M->GetPoint(j,x1,y1);
    Y2S_grGluonDissCMSNPart_M->GetPoint(j,x2,y2);
    ChiB_grGluonDissCMSNPart_M->GetPoint(j,x3,y3);
    Y3S_grGluonDissCMSNPart_M->GetPoint(j,x4,y4);
    x0=x1;
    y0=Y1SFactor*y1 + Y2SFactor*y2 + ChiBFactor*y3 +  Y3SFactor*y4;
    Y1S_grGluonDissCMSNPart_M->SetPoint(j,x0,y0);  
  

    Y1S_grPionDissCMSNPart_M->GetPoint(j,x1,y1);
    Y2S_grPionDissCMSNPart_M->GetPoint(j,x2,y2);
    ChiB_grPionDissCMSNPart_M->GetPoint(j,x3,y3);
    Y3S_grPionDissCMSNPart_M->GetPoint(j,x4,y4);
    x0=x1;
    y0=Y1SFactor*y1 + Y2SFactor*y2 + ChiBFactor*y3 + Y3SFactor*y4;
    Y1S_grPionDissCMSNPart_M->SetPoint(j,x0,y0); 

    
    Y1S_grRegenCMSNPart_M->GetPoint(j,x1,y1);
    Y2S_grRegenCMSNPart_M->GetPoint(j,x2,y2);
    ChiB_grRegenCMSNPart_M->GetPoint(j,x3,y3);
    Y3S_grRegenCMSNPart_M->GetPoint(j,x4,y4);
    x0=x1;
    y0=Y1SFactor*y1 + Y2SFactor*y2 + ChiBFactor*y3 + Y3SFactor*y4;
    Y1S_grRegenCMSNPart_M->SetPoint(j,x0,y0);

 }

 TLegend *legd5 = new TLegend(0.16,0.63,0.85,0.93);
 legd5->SetBorderSize(0);
 legd5->SetFillStyle(0);
 legd5->SetFillColor(0);
 legd5->SetTextSize(0.028);
 
 new TCanvas;
 gPad->SetTicks();
 Draw_CMS_Y1S_RaaVsNpart(legd5);
 legd5->AddEntry(Y1S_grGluonDissCMSNPart_M,"Gluon Dissociation","L");
 legd5->AddEntry(Y1S_grPionDissCMSNPart_M,"Comover","L");
 legd5->AddEntry(Y1S_grRegenCMSNPart_M,"Formation","L");
 legd5->AddEntry(Y1S_grRAACMSNPart_M,"Total (R_{AA})","L");
 Y1S_grRAACMSNPart_M->Draw("Lsame");
 Y1S_grGluonDissCMSNPart_M->Draw("Lsame");
 Y1S_grPionDissCMSNPart_M->Draw("Lsame");
 Y1S_grRegenCMSNPart_M->Draw("Lsame");
 legd5->Draw("same");
 gPad->SaveAs("Figures/Fig7a_CMS_Y1SRAANPart.eps");
 gPad->SaveAs("Figures/Fig7a_CMS_Y1SRAANPart.png");



//============== CMS RAA Vs NPart Y2S ====================//
 Double_t ChiBFactor2 = 0.0;
 Double_t Y2SFactor2 = 0.50;
 Double_t Y3SFactor2 = 0.50;

 for (int j=0; j < Y2S_grRAACMSNPart_M->GetN();++j){
    

   Double_t x0,y0;
   Double_t x1,y1;
   Double_t x2,y2;
   Double_t x3,y3;

   Y2S_grRAACMSNPart_M->GetPoint(j,x1,y1);
   Y3S_grRAACMSNPart_M->GetPoint(j,x2,y2);
   ChiB_grRAACMSNPart_M->GetPoint(j,x3,y3);
   x0=x1;
   y0=Y2SFactor2*y1 + Y3SFactor2*y2 + ChiBFactor2*y3;
   Y2S_grRAACMSNPart_M->SetPoint(j,x0,y0);  

    Y2S_grGluonDissCMSNPart_M->GetPoint(j,x1,y1);
    Y3S_grGluonDissCMSNPart_M->GetPoint(j,x2,y2);
    ChiB_grGluonDissCMSNPart_M->GetPoint(j,x3,y3);
    x0=x1;
    y0=Y2SFactor2*y1 + Y3SFactor2*y2 + ChiBFactor2*y3;
    Y2S_grGluonDissCMSNPart_M->SetPoint(j,x0,y0);  
  

    Y2S_grPionDissCMSNPart_M->GetPoint(j,x1,y1);
    Y3S_grPionDissCMSNPart_M->GetPoint(j,x2,y2);
    ChiB_grPionDissCMSNPart_M->GetPoint(j,x3,y3);
    x0=x1;
    y0=Y2SFactor2*y1 + Y3SFactor2*y2 + ChiBFactor2*y3;
    Y2S_grPionDissCMSNPart_M->SetPoint(j,x0,y0); 

    
    Y2S_grRegenCMSNPart_M->GetPoint(j,x1,y1);
    Y2S_grRegenCMSNPart_M->GetPoint(j,x2,y2);
    ChiB_grRegenCMSNPart_M->GetPoint(j,x3,y3);
    x0=x1;
    y0=Y2SFactor2*y1 + Y2SFactor2*y2 + ChiBFactor2*y3;
    Y2S_grRegenCMSNPart_M->SetPoint(j,x0,y0);

 }

 TLegend *legd6 = new TLegend(0.19,0.69,0.88,0.94);
 legd6->SetBorderSize(0);
 legd6->SetFillStyle(0);
 legd6->SetFillColor(0);
 legd6->SetTextSize(0.030);
 
 new TCanvas;
 gPad->SetTicks();
 Draw_CMS_Y2S_RaaVsNpart(legd6);
 legd6->AddEntry(Y2S_grGluonDissCMSNPart_M,"Gluon Dissociation","L");
 legd6->AddEntry(Y2S_grPionDissCMSNPart_M,"Comover","L");
 legd6->AddEntry(Y2S_grRegenCMSNPart_M,"Formation","L");
 legd6->AddEntry(Y2S_grRAACMSNPart_M,"Total (R_{AA})","L");
 Y2S_grRAACMSNPart_M->Draw("Lsame");
 Y2S_grGluonDissCMSNPart_M->Draw("Lsame");
 Y2S_grPionDissCMSNPart_M->Draw("Lsame");
 Y2S_grRegenCMSNPart_M->Draw("Lsame");
 legd6->Draw("same");
 gPad->SaveAs("Figures/Fig7b_CMS_Y2SRAANPart.eps");
 gPad->SaveAs("Figures/Fig7b_CMS_Y2SRAANPart.png");






}



//==================================================================================================//
//=========================== Making Functions for Data Graphs ====================================//
//=================================================================================================//



//1. CMS Raa Vs pT Data 

void Draw_CMS_JPsi_RaaVspT(TLegend *lgd)
{
  
  int nbinsPtCMS=4;
  Double_t PtCMSD[4]={7.31,8.97,11.32,16.52};
  Double_t ErrPtCMS[4]={0};
  Double_t RaaPtCMS[4] = {0.35,0.34,0.34,0.29}; 
  Double_t RaaPtStatErrCMS[4] = {0.09,0.03,0.03,0.04};
  Double_t RaaPtSystErrCMS[4] = {0.04,0.04,0.03,0.03};
  
  TGraphErrors *grRaaPtCMS = new TGraphErrors(nbinsPtCMS, PtCMSD, RaaPtCMS, ErrPtCMS, RaaPtStatErrCMS);  
  grRaaPtCMS->SetMarkerStyle(20);
  grRaaPtCMS->SetMarkerColor(2);
  grRaaPtCMS->GetYaxis()->SetRangeUser(0,1.7);
  grRaaPtCMS->GetXaxis()->SetTitle("p_{T}(GeV/c)");
  grRaaPtCMS->GetYaxis()->SetTitle("R_{AA}");
  
  TAxis *XaxisgrRaaPtCMS = grRaaPtCMS->GetXaxis();
  XaxisgrRaaPtCMS->SetLimits(0.0,30.0);


  TLine *lh5 = new TLine(0.0,1.0,30.0,1.0);
  lh5->SetLineColor(1);
  lh5->SetLineStyle(1);
  lh5->SetLineWidth(2);
  
  
  grRaaPtCMS->Draw("AP");
  lh5->Draw("same");

  TLatex *tb= new TLatex;
  tb->SetNDC(); 
  tb->SetTextAlign(12);
  tb->SetTextColor(1);
  tb->SetTextSize(0.040);
  //tb->DrawLatex(0.20,0.20,"PbPb #sqrt{s_{NN}} = 2.76 TeV");
  //tb->DrawLatex(0.20,0.15,"J/#psi #rightarrow #mu^{+} #mu^{-}, p_{T}^{J/#psi} > 6.5 GeV/c");  
   
    
  TBox *RaaPtJPsiCMSSys[4];
  for(int j=0;j<4;j++){
    RaaPtJPsiCMSSys[j] = new TBox(PtCMSD[j]-0.5,  RaaPtCMS[j]-RaaPtSystErrCMS[j], PtCMSD[j]+0.5,  RaaPtCMS[j]+RaaPtSystErrCMS[j]);
  }
  
  for(int j=0;j<4;j++){
    RaaPtJPsiCMSSys[j]->SetFillStyle(0000);
    RaaPtJPsiCMSSys[j]->SetLineColor(2);
    RaaPtJPsiCMSSys[j]->Draw("same"); 
  }
  
  TBox *CMSGlobalSysJPsiPt;
  CMSGlobalSysJPsiPt = new TBox(27.0-1.0, 1 - 0.075, 27.0+1.0, 1 + 0.075);
  CMSGlobalSysJPsiPt->SetFillStyle(3001);
  CMSGlobalSysJPsiPt->SetLineColor(2);
  CMSGlobalSysJPsiPt->SetFillColor(2);
  CMSGlobalSysJPsiPt->Draw("same"); 

  lgd->AddEntry(grRaaPtCMS,"CMS Data p_{T}^{J/#psi}>6.5 GeV/c, |y^{J/#psi}|<2.4", "P");

}



void Draw_ALICEFor_JPsi_RaaVspT(TLegend *lgd)
{

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

  TAxis *Xaxis2 = grRaaPtALICEFor->GetXaxis();
  Xaxis2->SetLimits(0.0,10.0);

  grRaaPtALICEFor->GetYaxis()->SetRangeUser(0,1.7);
  grRaaPtALICEFor->GetXaxis()->SetTitle("p_{T}(GeV/c)");
  grRaaPtALICEFor->GetYaxis()->SetTitle("R_{AA}");
  

  grRaaPtALICEFor->Draw("AP");

  TLine *lh4 = new TLine(0.0,1.0,10.0,1.0);
  lh4->SetLineColor(1);
  lh4->SetLineStyle(1);
  lh4->SetLineWidth(2);
  lh4->Draw("same");


  TLatex *tb= new TLatex;
  tb->SetNDC(); 
  tb->SetTextAlign(12);
  tb->SetTextColor(1);
  tb->SetTextSize(0.040);
  //tb->DrawLatex(0.22,0.22,"PbPb #sqrt{s_{NN}} = 2.76 TeV");
  //tb->DrawLatex(0.22,0.16,"J/#psi #rightarrow #mu^{+} #mu^{-}, p_{T}^{J/#psi} > 0.0 GeV/c");  
  
  TBox *RaaPtJPsiALICEForSys[12];
  for(int j=0;j<7;j++){
    RaaPtJPsiALICEForSys[j] = new TBox(PtALICEFor[j]-0.1,  RaaPtALICEFor[j]-RaaPtSystErrALICEFor[j], PtALICEFor[j]+0.1,  RaaPtALICEFor[j]+RaaPtSystErrALICEFor[j]);
  }
  
  for(int j=0;j<7;j++){
    RaaPtJPsiALICEForSys[j]->SetFillStyle(0000);
    RaaPtJPsiALICEForSys[j]->SetLineColor(4);
    RaaPtJPsiALICEForSys[j]->Draw("same"); 
  }
  
  
  TBox *ALICEGlobalSysJPsiPtFor;
  //ALICEGlobalSysJPsiPtFor = new TBox(9.6-0.2, 1 - 0.14, 9.6+0.2, 1 + 0.14);
  ALICEGlobalSysJPsiPtFor = new TBox(9.6-0.2, 1 - 0.08, 9.6+0.2, 1 + 0.08);
  ALICEGlobalSysJPsiPtFor->SetFillStyle(3001);
  ALICEGlobalSysJPsiPtFor->SetLineColor(4);
  ALICEGlobalSysJPsiPtFor->SetFillColor(4);
  ALICEGlobalSysJPsiPtFor->Draw("same"); 
    
  lgd->AddEntry(grRaaPtALICEFor,"ALICE Data p_{T}^{J/#psi} > 0.0 GeV/c, 2.5<y^{J/#psi}<4.0", "P");  

}

void Draw_ALICEFor_JPsi_RaaVspT_InMostCentral(TLegend *lgd)
{

  //================= ALICE Forward Rapidity Raa Vs Pt ===================================//
  int nbinsPtALICEFor=7;
  Double_t PtALICEFor[7]={0.50,1.50,2.50,3.50,4.50,5.50,7.0};
  Double_t ErrPtALICEFor[7]={0};

  Double_t RaaPtALICEFor[7] = {0.80,0.69,0.51,0.38,0.36,0.28,0.28}; 
  Double_t RaaPtStatErrALICEFor[7] = {0.08,0.05,0.04,0.04,0.05,0.05,0.06};
  Double_t RaaPtSystErrALICEFor[7] = {0.11,0.08,0.06,0.05,0.04,0.03,0.03};
  

  TGraphErrors *grRaaPtALICEFor = new TGraphErrors(nbinsPtALICEFor, PtALICEFor, RaaPtALICEFor, ErrPtALICEFor, RaaPtStatErrALICEFor);  
  grRaaPtALICEFor->SetMarkerStyle(20);
  grRaaPtALICEFor->SetMarkerColor(4);

  TAxis *Xaxis2 = grRaaPtALICEFor->GetXaxis();
  Xaxis2->SetLimits(0.0,10.0);

  grRaaPtALICEFor->GetYaxis()->SetRangeUser(0,1.7);
  grRaaPtALICEFor->GetXaxis()->SetTitle("p_{T}(GeV/c)");
  grRaaPtALICEFor->GetYaxis()->SetTitle("R_{AA}");
  

  grRaaPtALICEFor->Draw("AP");

  TLine *lh4 = new TLine(0.0,1.0,10.0,1.0);
  lh4->SetLineColor(1);
  lh4->SetLineStyle(1);
  lh4->SetLineWidth(2);
  lh4->Draw("same");


  TLatex *tb= new TLatex;
  tb->SetNDC(); 
  tb->SetTextAlign(12);
  tb->SetTextColor(1);
  tb->SetTextSize(0.040);
  //tb->DrawLatex(0.22,0.22,"PbPb #sqrt{s_{NN}} = 2.76 TeV");
  //tb->DrawLatex(0.22,0.16,"J/#psi #rightarrow #mu^{+} #mu^{-}, p_{T}^{J/#psi} > 0.0 GeV/c");  
  
  TBox *RaaPtJPsiALICEForSys[12];
  for(int j=0;j<7;j++){
    RaaPtJPsiALICEForSys[j] = new TBox(PtALICEFor[j]-0.1,  RaaPtALICEFor[j]-RaaPtSystErrALICEFor[j], PtALICEFor[j]+0.1,  RaaPtALICEFor[j]+RaaPtSystErrALICEFor[j]);
  }
  
  for(int j=0;j<7;j++){
    RaaPtJPsiALICEForSys[j]->SetFillStyle(0000);
    RaaPtJPsiALICEForSys[j]->SetLineColor(4);
    RaaPtJPsiALICEForSys[j]->Draw("same"); 
  }
  
  
  TBox *ALICEGlobalSysJPsiPtFor;
  //ALICEGlobalSysJPsiPtFor = new TBox(9.6-0.2, 1 - 0.14, 9.6+0.2, 1 + 0.14);
  ALICEGlobalSysJPsiPtFor = new TBox(9.6-0.2, 1 - 0.08, 9.6+0.2, 1 + 0.08);
  ALICEGlobalSysJPsiPtFor->SetFillStyle(3001);
  ALICEGlobalSysJPsiPtFor->SetLineColor(4);
  ALICEGlobalSysJPsiPtFor->SetFillColor(4);
  ALICEGlobalSysJPsiPtFor->Draw("same"); 
    
  lgd->AddEntry(grRaaPtALICEFor,"ALICE Data 2.5<y^{J/#psi}<4.0, Cent [0-20 %]", "P");  

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
  lh_grRaaRapCMS->SetLineWidth(2);
  lh_grRaaRapCMS->Draw("same");

  TLatex *tb= new TLatex;
  tb->SetNDC(); 
  tb->SetTextAlign(12);
  tb->SetTextColor(1);
  tb->SetTextSize(0.040);
  //tb->DrawLatex(0.20,0.20,"PbPb #sqrt{s_{NN}} = 2.76 TeV");
  //tb->DrawLatex(0.20,0.15,"J/#psi #rightarrow #mu^{+} #mu^{-}, p_{T}^{J/#psi} > 6.5 GeV/c");  
  
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
  
  //grRaaCMS->Draw("Psame");
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
  //tb->DrawLatex(0.17,0.23,"PbPb #sqrt{s_{NN}} = 2.76 TeV");
  //tb->DrawLatex(0.17,0.17,"p_{T}^{J/#psi} > 6.5 GeV/c");

  lgd->AddEntry(grRaaCMS,"CMS Data p_{T}^{J/#psi} > 6.5 GeV/c, |y^{J/#psi}|<2.4", "P");

}



void Draw_ALICEFor_JPsi_RaaVsNpart(TLegend *lgd)
{
  int nbinsALICE=9;

  //Double_t NPartALICE[10]={357,262,187,128,86,53,30,16,8};
  //Double_t ErrNPartALICE[10]={0};
  //Double_t RaaALICE[10] = {0.47,0.48,0.51,0.51,0.52,0.61,0.70,0.74,0.94}; 
  //Double_t SystErrALICE[10] = {0.03,0.02,0.02,0.02,0.03,0.05,0.06,0.09,0.1};


  Double_t NPartALICE[10]={356,260,186,129,85,52,30,16,8};
  Double_t ErrNPartALICE[10]={0};
  Double_t RaaALICE[10] = {0.56,0.57,0.60,0.58,0.61,0.73,0.84,0.85,1.09}; 
  Double_t StatErrALICE[10] = {0.02,0.02,0.02,0.02,0.03,0.04,0.04,0.06,0.10};
  Double_t SystErrALICE[10] = {0.02,0.02,0.02,0.03,0.03,0.04,0.06,0.07,0.1};
  
  TGraphErrors *grRaaALICE = new TGraphErrors(nbinsALICE, NPartALICE, RaaALICE, ErrNPartALICE, StatErrALICE);  
  grRaaALICE->SetMarkerStyle(20);
  grRaaALICE->SetMarkerColor(4);
  grRaaALICE->GetYaxis()->SetRangeUser(0,2.4);
  
  TAxis *Xaxis2 = grRaaALICE->GetXaxis();
  Xaxis2->SetLimits(0.,430.0);
  
  grRaaALICE->GetXaxis()->SetTitle("N_{Part}");
  grRaaALICE->GetYaxis()->SetTitle("R_{AA}");

  grRaaALICE->Draw("AP");
 
  TLine *lh3 = new TLine(0.0,1.0,420,1.0);
  lh3->SetLineColor(1);
  lh3->SetLineStyle(1);
  lh3->SetLineWidth(2);
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
  //Double_t NPartALICEMid[3]={357,193,46};
  //Double_t ErrNPartALICEMid[3]={0};
  //Double_t RaaALICEMid[3] = {0.82,0.65,0.73}; 
  //Double_t SystErrALICEMid[3] = {0.15,0.10,0.16};


  Double_t NPartALICEMid[3]={356,192,38};
  Double_t ErrNPartALICEMid[3]={0};
  Double_t RaaALICEMid[3] = {0.73,0.70,0.79}; 
  Double_t StatErrALICEMid[3] = {0.09,0.08,0.15};
  Double_t SystErrALICEMid[3] = {0.06,0.05,0.09};
  
  //MB Value
  //124.4 +- 2.2	 0. –  90.	0.72 ± 0.06 (stat) ± 0.04 (sys)


  TGraphErrors *grRaaALICEMid = new TGraphErrors(nbinsALICEMid, NPartALICEMid, RaaALICEMid, ErrNPartALICEMid, StatErrALICEMid);  
  grRaaALICEMid->SetMarkerStyle(20);
  grRaaALICEMid->SetMarkerColor(2);
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
  lh3->SetLineWidth(2);
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
  ALICEMidGlobalSysJPsi = new TBox(385-5, 1 - 0.13, 385+5, 1 + 0.13);
  
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
  RaaYCMS1Sdata->SetMarkerStyle(33);
  //RaaYCMS1Sdata->SetMarkerColor(kRed+0);
  RaaYCMS1Sdata->SetMarkerColor(kGreen+2);
  //RaaYCMS1Sdata->SetMarkerSize(1.1);
  RaaYCMS1Sdata->SetMarkerSize(2.0);
  RaaYCMS1Sdata->GetYaxis()->SetRangeUser(0.0,2.1);
  RaaYCMS1Sdata->GetXaxis()->CenterTitle();
  RaaYCMS1Sdata->GetXaxis()->SetTitle("N_{part}");
  RaaYCMS1Sdata->GetYaxis()->SetTitle("R_{AA}");
  RaaYCMS1Sdata->Draw("AP");
  
  
  TBox *RaaCMS1SSys[10];
  for(int j=0;j<7;j++){
    RaaCMS1SSys[j] = new TBox(NPartCMSD[j]-4,RaaCMS1Sdata[j]-ErSysRaaCMS1Sdata[j],NPartCMSD[j]+4,RaaCMS1Sdata[j]+ErSysRaaCMS1Sdata[j]);
  }
  
  for(int j=0;j<7;j++){
    //RaaCMS1SSys[j]->SetFillStyle(0000);
    RaaCMS1SSys[j]->SetFillStyle(3001);
    RaaCMS1SSys[j]->SetLineColor(kGreen+2);
    RaaCMS1SSys[j]->SetFillColor(kGreen-4);
    RaaCMS1SSys[j]->Draw("same"); 
  }
    
  RaaYCMS1Sdata->Draw("Psame");

  TLine *lh = new TLine(0.0,1.0,400,1.0);
  lh->SetLineColor(1);
  lh->SetLineStyle(1);
  lh->SetLineWidth(2);
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
  //tb->DrawLatex(0.21,0.24,"#varUpsilon(1S) #rightarrow #mu^{+} #mu^{-}");
  
  //lgd->AddEntry(RaaYCMS1Sdata,"CMS Data p_{T}^{#varUpsilon(1S)} > 0.0 GeV/c, |y^{#varUpsilon(1S)}| #leq 2.4", "P");

  lgd->AddEntry(RaaYCMS1Sdata,"CMS:#varUpsilon(1S), |y| #leq 2.4", "P");
  Draw_ALICEFor_Y1S_RaaVsNpart(lgd);
  
}


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
  RaaYCMS2Sdata->SetMarkerSize(1.1);
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
  lh->SetLineWidth(2);
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
 
  lgd->AddEntry(RaaYCMS2Sdata,"CMS Data p_{T}^{#varUpsilon(2S)} > 0.0 GeV/c, |y^{#varUpsilon(2S)}| #leq 2.4", "P");

}
 
void Draw_ALICEFor_Y1S_RaaVsNpart(TLegend *lgd)
{
  /*
  double ErNPartALICE[2]={0};
  double NPartALICED[2]={76.0,310.0};
  double RaaALICE1Sdata[2] = {0.63,0.34};
  double ErRaaALICE1Sdata[2] = {0.11,0.07};
  double ErSys1RaaALICE1Sdata[2] = {0.05,0.03};
  //box asymetric
  double ErSys2RaaALICE1Sdata[4] = {0.1,0.14,0.05,0.07};
  */

  double ErNPartALICE[2]={0};
  double NPartALICED[2]={72.0,308.0};
  double RaaALICE1Sdata[2] = {0.4406,0.2051};
  double ErRaaALICE1Sdata[2] = {0.1658,0.0952};
  
  double ErSys1RaaALICE1Sdata[2] = {0.068,0.0354};
  
  //box asymetric
  double ErSys2RaaALICE1Sdata[4] = {0.1,0.14,0.05,0.07};


  TGraphErrors *RaaYALICE1Sdata = new TGraphErrors(2,NPartALICED,RaaALICE1Sdata,ErNPartALICE,ErRaaALICE1Sdata);
  RaaYALICE1Sdata->SetMarkerStyle(20);
  RaaYALICE1Sdata->SetMarkerColor(4);
  RaaYALICE1Sdata->SetMarkerSize(1.1);
  RaaYALICE1Sdata->GetYaxis()->SetRangeUser(0.0,1.5);
  RaaYALICE1Sdata->GetXaxis()->SetTitle("N_{part}");
  RaaYALICE1Sdata->GetYaxis()->SetTitle("R_{AA}");
  TAxis *XAxis_RaaYALICE1Sdata=RaaYALICE1Sdata->GetXaxis();
  XAxis_RaaYALICE1Sdata->SetLimits(0.0,350);
  XAxis_RaaYALICE1Sdata->Draw();
 
  RaaYALICE1Sdata->Draw("Psame");
  
  TBox *RaaALICE1SSys1[10];
  for(int j=0;j<2;j++){
    RaaALICE1SSys1[j] = new TBox(NPartALICED[j]-4,RaaALICE1Sdata[j]-ErSys1RaaALICE1Sdata[j],NPartALICED[j]+4,RaaALICE1Sdata[j]+ErSys1RaaALICE1Sdata[j]);
  }
  
  for(int j=0;j<2;j++){
    RaaALICE1SSys1[j]->SetFillStyle(0000);
    RaaALICE1SSys1[j]->SetLineColor(4);
    RaaALICE1SSys1[j]->Draw("same"); 
  }
  
  
  TBox *RaaALICE1SSys2[10];
  
  RaaALICE1SSys2[0] = new TBox(NPartALICED[0]-4,RaaALICE1Sdata[0]-ErSys2RaaALICE1Sdata[0],NPartALICED[0]+4,RaaALICE1Sdata[0]+ErSys2RaaALICE1Sdata[1]);
  RaaALICE1SSys2[1] = new TBox(NPartALICED[1]-4,RaaALICE1Sdata[1]-ErSys2RaaALICE1Sdata[2],NPartALICED[1]+4,RaaALICE1Sdata[1]+ErSys2RaaALICE1Sdata[3]);
  
  
  for(int j=0;j<2;j++){
    RaaALICE1SSys2[j]->SetFillStyle(0000);
    RaaALICE1SSys2[j]->SetLineColor(4);
    //RaaALICE1SSys2[j]->Draw("same"); 
  }
    
  TBox *GlobalSys1;
  GlobalSys1 = new TBox(380-5, 1 - 0.10, 380+5, 1 + 0.10);
  GlobalSys1->SetFillStyle(3001);
  GlobalSys1->SetFillColor(4);
  GlobalSys1->SetLineColor(4);
  GlobalSys1->Draw("same");


  TLine *lhALICE1S = new TLine(0.0,1.0,350,1.0);
  lhALICE1S->SetLineColor(1);
  lhALICE1S->SetLineStyle(1);
  lhALICE1S->SetLineWidth(2);
  lhALICE1S->Draw("same");
  
  // lgd->AddEntry(RaaYALICE1Sdata,"ALICE Data p_{T}^{#varUpsilon(1S)} > 0.0 GeV/c, 2.5 #leq y^{#varUpsilon(1S)} #leq 4.0", "P");

  lgd->AddEntry(RaaYALICE1Sdata,"ALICE: #varUpsilon(1S), 2.5 #leq y #leq 4.0", "P");

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
  Draw_CMS_Y1S_RaaVspT(legend_ratio);
  legend_ratio->Draw("same");

  return;

  new TCanvas;
  gPad->SetTickx();
  gPad->SetTicky();
  Draw_CMS_JPsi_RaaVsNpart(legend_ratio);
  legend_ratio->Draw("same");


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



void Draw_CMS_Y1S_RaaVspT(TLegend *lgd)
{

  //================= CMS Y1S Raa Vs Pt ===================================//
  int nbinsPtCMS=3;
  Double_t PtCMS[3]={3.03,8.04,13.17};
  Double_t ErrPtCMS[3]={0};
  Double_t RaaPtCMS[3] = {0.44,0.91,1.77}; 
  Double_t RaaPtStatErrCMS[3] = {0.10,0.38,0.76};
  Double_t RaaPtSystErrCMS1[3] = {0.06,0.13,0.24};
  Double_t RaaPtSystErrCMS2[3] = {0.04,0.08,0.15};
  Double_t RaaPtSystErrCMS[3] = {0.0};
 
  for(int j=0;j<3;j++){RaaPtSystErrCMS[j]=TMath::Sqrt(RaaPtSystErrCMS1[j]*RaaPtSystErrCMS1[j] + RaaPtSystErrCMS2[j]*RaaPtSystErrCMS2[j]);}

  TGraphErrors *grRaaPtCMS = new TGraphErrors(nbinsPtCMS, PtCMS, RaaPtCMS, ErrPtCMS, RaaPtStatErrCMS);  
  grRaaPtCMS->SetMarkerStyle(20);
  grRaaPtCMS->SetMarkerColor(4);
  grRaaPtCMS->GetYaxis()->SetRangeUser(0,3.0);
  grRaaPtCMS->GetXaxis()->SetTitle("p_{T}(GeV/c)");
  grRaaPtCMS->GetYaxis()->SetTitle("R_{AA}");
   
  TAxis *Xaxis2 = grRaaPtCMS->GetXaxis();
  Xaxis2->SetLimits(0.,20.0);

  


  grRaaPtCMS->Draw("AP");

  TLine *lh4 = new TLine(0.0,1.0,20.0,1.0);
  lh4->SetLineColor(1);
  lh4->SetLineStyle(1);
  lh4->SetLineWidth(2);
  lh4->Draw("same");


  TLatex *tb= new TLatex;
  tb->SetNDC(); 
  tb->SetTextAlign(12);
  tb->SetTextColor(1);
  tb->SetTextSize(0.040);
  //tb->DrawLatex(0.55,0.22,"PbPb #sqrt{s_{NN}} = 2.76 TeV");
  //tb->DrawLatex(0.55,0.16,"#varUpsilon #rightarrow #mu^{+} #mu^{-}, p_{T}^{#varUpsilon} > 0.0 GeV/c");  
  
  TBox *RaaPtJPsiCMSSys[3];
  for(int j=0;j<3;j++){
    RaaPtJPsiCMSSys[j] = new TBox(PtCMS[j]-0.1,  RaaPtCMS[j]-RaaPtSystErrCMS[j], PtCMS[j]+0.1,  RaaPtCMS[j]+RaaPtSystErrCMS[j]);
  }
  
  for(int j=0;j<3;j++){
    RaaPtJPsiCMSSys[j]->SetFillStyle(0000);
    RaaPtJPsiCMSSys[j]->SetLineColor(4);
    RaaPtJPsiCMSSys[j]->Draw("same"); 
  }
  
  
  TBox *CMSGlobalSysJPsiPt;
  CMSGlobalSysJPsiPt = new TBox(18-0.2, 1 - 0.083, 18+0.2, 1 + 0.083);
  CMSGlobalSysJPsiPt->SetFillStyle(3001);
  CMSGlobalSysJPsiPt->SetLineColor(4);
  CMSGlobalSysJPsiPt->SetFillColor(4);
  CMSGlobalSysJPsiPt->Draw("same"); 
    
  lgd->AddEntry(grRaaPtCMS,"CMS Data", "P");  

  }
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

Double_t NColl(int BinLow, int BinHigh)
{
  Double_t NCollArray[40]={1747.8600, 1567.5300, 1388.3900, 1231.7700, 1098.2000, 980.4390, 861.6090, 766.0420, 676.5150, 593.4730,
			   521.9120, 456.5420, 398.5460, 346.6470, 299.3050, 258.3440, 221.2160, 188.6770, 158.9860, 134.7000,
			   112.5470, 93.4537, 77.9314, 63.5031, 52.0469, 42.3542, 33.9204, 27.3163, 21.8028, 17.2037,
			   13.5881, 10.6538, 8.3555, 6.4089, 5.1334, 3.7322, 3.0663, 2.4193, 2.1190, 1.7695};
  
  Double_t sum=0;
  for(int i=BinLow;i<BinHigh;i++){
    sum+=NCollArray[i];
  }
  Double_t NColl = sum/(BinHigh-BinLow);
  return NColl;
}

