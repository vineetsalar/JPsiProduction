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

// \pm 20 % 
// 0 -> Nominal
// 1 -> SigmaD*0.5
// 2 -> SigmaD*1.5
// 3 -> Tau0 = 0.1  //0.2
// 4 -> Tau0 = 0.6  //0.4

Int_t Var =4;




void Plot_PaperFigures_NF_Band() 

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
  



  TLatex *tb= new TLatex;
  tb->SetNDC(); 
  tb->SetTextAlign(12);
  tb->SetTextColor(1);
  tb->SetTextSize(0.040);


  TFile *file_Shadowing =  new TFile("ShawQuarkonia.root","R");;

  TGraph *grShJPsiVsPtALICE_Shade =(TGraph*)file_Shadowing->Get("grShJPsiVsPtALICE_Shade");
  TGraph *grShJPsiVsPtALICE =(TGraph*)file_Shadowing->Get("grShJPsiVsPtALICE");
  TGraph *grShUJPsiVsPtALICE =(TGraph*)file_Shadowing->Get("grShUJPsiVsPtALICE");
  TGraph *grShLJPsiVsPtALICE =(TGraph*)file_Shadowing->Get("grShLJPsiVsPtALICE");


  TGraph *grShJPsiVsPtCMS_Shade =(TGraph*)file_Shadowing->Get("grShJPsiVsPtCMS_Shade");
  TGraph *grShJPsiVsPtCMS =(TGraph*)file_Shadowing->Get("grShJPsiVsPtCMS");
  TGraph *grShUJPsiVsPtCMS =(TGraph*)file_Shadowing->Get("grShUJPsiVsPtCMS");
  TGraph *grShLJPsiVsPtCMS =(TGraph*)file_Shadowing->Get("grShLJPsiVsPtCMS");



  TGraph *grShJPsiVsNPart_Shade =(TGraph*)file_Shadowing->Get("grShJPsiVsNPart_Shade");
  TGraph *grShJPsiVsNPart =(TGraph*)file_Shadowing->Get("grShJPsiVsNPart");
  TGraph *grShUJPsiVsNPart =(TGraph*)file_Shadowing->Get("grShJPsiUVsNPart");
  TGraph *grShLJPsiVsNPart =(TGraph*)file_Shadowing->Get("grShJPsiLVsNPart");



  TGraph *grShJPsiPtCutVsNPart_Shade =(TGraph*)file_Shadowing->Get("grShJPsiPtCutLVsNPart_Shade");
  TGraph *grShJPsiPtCutVsNPart =(TGraph*)file_Shadowing->Get("grShJPsiPtCutVsNPart");
  TGraph *grShUJPsiPtCutVsNPart =(TGraph*)file_Shadowing->Get("grShJPsiPtCutUVsNPart");
  TGraph *grShLJPsiPtCutVsNPart =(TGraph*)file_Shadowing->Get("grShJPsiPtCutLVsNPart");


  TGraph *grShUpsilonVsNPartMid_Shade =(TGraph*)file_Shadowing->Get("grShUpsilonVsNPartMid_Shade");
  TGraph *grShUpsilonVsNPartMid =(TGraph*)file_Shadowing->Get("grShUpsilonVsNPartMid");
  TGraph *grShUUpsilonVsNPartMid =(TGraph*)file_Shadowing->Get("grShUpsilonUVsNPartMid");
  TGraph *grShLUpsilonVsNPartMid =(TGraph*)file_Shadowing->Get("grShUpsilonLVsNPartMid");
  




  
  //================================ Open JPsi Root File ================================================//
  



  TFile *file_JPsi;

  TFile *file_JPsi_V1;
  TFile *file_JPsi_V2;
  TFile *file_JPsi_V3;
  TFile *file_JPsi_V4;





  file_JPsi = new TFile("04032015_JPsiCalculations.root","R");
  
  file_JPsi_V1 = new TFile("SigmaDFac05_JPsiCalculations.root","R");
  file_JPsi_V2 = new TFile("SigmaDFac15_JPsiCalculations.root","R");
  file_JPsi_V3= new TFile("Tau001_JPsiCalculations.root","R");
  file_JPsi_V4 = new TFile("Tau006_JPsiCalculations.root","R");
   
  // ====== Event Variable Graphs  ==============================//
  TGraph *JPsi_grTempVsTauL =(TGraph*)file_JPsi->Get("grTempVsTauL");
  JPsi_grTempVsTauL->SetLineColor(2);
  JPsi_grTempVsTauL->SetLineStyle(9);
  JPsi_grTempVsTauL->SetLineWidth(2);


  TGraph *JPsi_grTempVsTauC =(TGraph*)file_JPsi->Get("grTempVsTauC");
  JPsi_grTempVsTauC->SetLineColor(4);
  JPsi_grTempVsTauC->SetLineStyle(2);
  JPsi_grTempVsTauC->SetLineWidth(2);


  TGraph *JPsi_grTempVsTauLatt =(TGraph*)file_JPsi->Get("grTempVsTauLatt");
  JPsi_grTempVsTauLatt->SetLineColor(1);
  JPsi_grTempVsTauLatt->SetLineStyle(1);
  JPsi_grTempVsTauLatt->SetLineWidth(2);

 


  TGraph *JPsi_grFQGPVsTauL =(TGraph*)file_JPsi->Get("grFQGPVsTauL");
  JPsi_grFQGPVsTauL->SetLineColor(2);
  JPsi_grFQGPVsTauL->SetLineStyle(9);
  JPsi_grFQGPVsTauL->SetLineWidth(2);


  TGraph *JPsi_grFQGPVsTauC =(TGraph*)file_JPsi->Get("grFQGPVsTauC");
  JPsi_grFQGPVsTauC->SetLineColor(4);
  JPsi_grFQGPVsTauC->SetLineStyle(2);
  JPsi_grFQGPVsTauC->SetLineWidth(2);


  TGraph *JPsi_grFQGPVsTauLatt =(TGraph*)file_JPsi->Get("grFQGPVsTauLatt");
  JPsi_grFQGPVsTauLatt->SetLineColor(1);
  JPsi_grFQGPVsTauLatt->SetLineStyle(1);
  JPsi_grFQGPVsTauLatt->SetLineWidth(2);

  
  TLegend *legdA = new TLegend( 0.15,0.79,0.87,0.93);
  legdA->SetBorderSize(0);
  legdA->SetTextSize(0.040);
  legdA->SetFillStyle(0);
  legdA->SetFillColor(0);
  legdA->AddEntry(JPsi_grTempVsTauL,"FO-EOS, Longitudinal expansion","L");
  legdA->AddEntry(JPsi_grTempVsTauC,"FO-EOS, Cylindrical expansion","L");
  legdA->AddEntry(JPsi_grTempVsTauLatt,"Lattice EOS, Cylindrical expansion","L");
  
  TLine *l1 = new TLine(0.0,0.16,10.0,0.16);
  l1->SetLineWidth(2);
  l1->SetLineColor(2);
  
  new TCanvas;  
  gPad->SetTicks(1);
  TAxis *Xaxis3 = JPsi_grTempVsTauL->GetXaxis();
  Xaxis3->SetLimits(0.0,20.0);
  JPsi_grTempVsTauL->GetYaxis()->SetRangeUser(0.0,0.7);
  JPsi_grTempVsTauL->Draw("AL");
  JPsi_grTempVsTauC->Draw("Lsame");
  JPsi_grTempVsTauLatt->Draw("Lsame");
  
  tb->DrawLatex(0.16,0.18,"(a)");
  legdA->Draw("Lsame");
  gPad->SaveAs("plots/Fig1a_TauVsTemp.eps");
  gPad->SaveAs("plots/Fig1a_TauVsTemp.png");
  gPad->SaveAs("plots/Fig1a_TauVsTemp.pdf");


  TLegend *legdB = new TLegend( 0.15,0.79,0.87,0.93);
  legdB->SetBorderSize(0);
  legdB->SetFillStyle(0);
  legdB->SetFillColor(0);
  legdB->SetTextSize(0.040);
  legdB->AddEntry(JPsi_grFQGPVsTauL,"FO-EOS, Longitudinal expansion","L");
  legdB->AddEntry(JPsi_grFQGPVsTauC,"FO-EOS, Cylindrical expansion","L");
  legdB->AddEntry(JPsi_grFQGPVsTauLatt,"Lattice EOS, Cylindrical expansion","L");
  
  new TCanvas;  
  gPad->SetTicks(1);
  JPsi_grFQGPVsTauL->GetYaxis()->SetRangeUser(0.0,1.4);
  TAxis *Xaxis4 = JPsi_grFQGPVsTauL->GetXaxis();
  Xaxis4->SetLimits(0.,20.0);
  JPsi_grFQGPVsTauL->Draw("AL");
  
  JPsi_grFQGPVsTauC->Draw("Lsame");
  JPsi_grFQGPVsTauLatt->Draw("Lsame");
  
  legdB->Draw("Lsame");
  tb->DrawLatex(0.16,0.18,"(b)");
  
  gPad->SaveAs("plots/Fig1b_TauVsFQGP.eps");
  gPad->SaveAs("plots/Fig1b_TauVsFQGP.png");
  gPad->SaveAs("plots/Fig1b_TauVsFQGP.pdf");
  

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
  JPsi_DissRateVsT_KharPt36->SetLineStyle(9);
  JPsi_DissRateVsT_KharPt36->SetLineWidth(2);


  TGraph *JPsi_DissRateVsT_KharPt86 =(TGraph*)file_JPsi->Get("DissRateVsT_KharPt86");
  JPsi_DissRateVsT_KharPt86->SetLineColor(2);
  JPsi_DissRateVsT_KharPt86->SetLineStyle(7);
  JPsi_DissRateVsT_KharPt86->SetLineWidth(2);

  
  TGraph *JPsi_grDissRateVsPt_T200 =(TGraph*)file_JPsi->Get("grDissRateVsPt_T200");
  JPsi_grDissRateVsPt_T200->SetLineColor(1);
  JPsi_grDissRateVsPt_T200->SetLineStyle(1);
  JPsi_grDissRateVsPt_T200->SetLineWidth(2);


  TGraph *JPsi_grDissRateVsPt_T400 =(TGraph*)file_JPsi->Get("grDissRateVsPt_T400");
  JPsi_grDissRateVsPt_T400->SetLineColor(4);
  JPsi_grDissRateVsPt_T400->SetLineStyle(9);
  JPsi_grDissRateVsPt_T400->SetLineWidth(2);

  
  TGraph *JPsi_grDissRateVsPt_T600 =(TGraph*)file_JPsi->Get("grDissRateVsPt_T600");
  JPsi_grDissRateVsPt_T600->SetLineColor(2);
  JPsi_grDissRateVsPt_T600->SetLineStyle(7);
  JPsi_grDissRateVsPt_T600->SetLineWidth(2);


  // ====== Formation rate graphs ==============================//
  TGraph *JPsi_grFormRateVsT_MCInt_P1 =(TGraph*)file_JPsi->Get("grFormRateVsT_MCInt_P1");
  JPsi_grFormRateVsT_MCInt_P1->SetLineColor(1);
  JPsi_grFormRateVsT_MCInt_P1->SetLineStyle(1);
  JPsi_grFormRateVsT_MCInt_P1->SetLineWidth(2);

  TGraph *JPsi_grFormRateVsT_MCInt_P2 =(TGraph*)file_JPsi->Get("grFormRateVsT_MCInt_P2");
  JPsi_grFormRateVsT_MCInt_P2->SetLineColor(4);
  JPsi_grFormRateVsT_MCInt_P2->SetLineStyle(9);
  JPsi_grFormRateVsT_MCInt_P2->SetLineWidth(2);


  TGraph *JPsi_grFormRateVsT_MCInt_P3 =(TGraph*)file_JPsi->Get("grFormRateVsT_MCInt_P3");
  JPsi_grFormRateVsT_MCInt_P3->SetLineColor(2);
  JPsi_grFormRateVsT_MCInt_P3->SetLineStyle(7);
  JPsi_grFormRateVsT_MCInt_P3->SetLineWidth(2);


  TGraph *JPsi_grFormRateVsP_MCInt_T1 =(TGraph*)file_JPsi->Get("grFormRateVsP_MCInt_T1");
  JPsi_grFormRateVsP_MCInt_T1->SetLineColor(2);
  JPsi_grFormRateVsP_MCInt_T1->SetLineStyle(7);
  JPsi_grFormRateVsP_MCInt_T1->SetLineWidth(2);

  TGraph *JPsi_grFormRateVsP_MCInt_T2 =(TGraph*)file_JPsi->Get("grFormRateVsP_MCInt_T2");
  JPsi_grFormRateVsP_MCInt_T2->SetLineColor(4);
  JPsi_grFormRateVsP_MCInt_T2->SetLineStyle(9);
  JPsi_grFormRateVsP_MCInt_T2->SetLineWidth(2);

  TGraph *JPsi_grFormRateVsP_MCInt_T3 =(TGraph*)file_JPsi->Get("grFormRateVsP_MCInt_T3");
  JPsi_grFormRateVsP_MCInt_T3->SetLineColor(1);
  JPsi_grFormRateVsP_MCInt_T3->SetLineStyle(1);
  JPsi_grFormRateVsP_MCInt_T3->SetLineWidth(2);


  //============================ RAA Graphs =======================//

 
 //============================ ALICE RAA Vs Pt Graphs =======================//
  TGraph *JPsi_grGluonDissALICEPt_M =(TGraph*)file_JPsi->Get("grGluonDissALICEPt_M");
  JPsi_grGluonDissALICEPt_M->SetLineColor(2);
  JPsi_grGluonDissALICEPt_M->SetLineStyle(7);
  JPsi_grGluonDissALICEPt_M->SetLineWidth(2);


  TGraph *JPsi_grPionDissALICEPt_M =(TGraph*)file_JPsi->Get("grPionDissALICEPt_M");
  JPsi_grPionDissALICEPt_M->SetLineColor(4);
  JPsi_grPionDissALICEPt_M->SetLineStyle(9);
  JPsi_grPionDissALICEPt_M->SetLineWidth(2);


  TGraph *JPsi_grCNMEffALICEPt_M =(TGraph*)file_JPsi->Get("grShadowDissALICEPt_M");
  JPsi_grCNMEffALICEPt_M->SetLineColor(6);
  JPsi_grCNMEffALICEPt_M->SetLineStyle(6);
  JPsi_grCNMEffALICEPt_M->SetLineWidth(2);


  TGraph *JPsi_grRegenALICEPt_M =(TGraph*)file_JPsi->Get("grRegenALICEPt_M");
  JPsi_grRegenALICEPt_M->SetLineColor(8);
  JPsi_grRegenALICEPt_M->SetLineStyle(2);
  JPsi_grRegenALICEPt_M->SetLineWidth(2);



  TGraph *JPsi_grRAAALICEPt_M =(TGraph*)file_JPsi->Get("grRAAALICEPt_M");
  JPsi_grRAAALICEPt_M->SetLineColor(1);
  JPsi_grRAAALICEPt_M->SetLineStyle(1);
  JPsi_grRAAALICEPt_M->SetLineWidth(2);

  TGraph *JPsi_grRAAALICEPt_M_V1 =(TGraph*)file_JPsi_V1->Get("grRAAALICEPt_M");
  JPsi_grRAAALICEPt_M_V1->SetLineColor(1);
  JPsi_grRAAALICEPt_M_V1->SetLineStyle(1);
  JPsi_grRAAALICEPt_M_V1->SetLineWidth(2);

  
  TGraph *JPsi_grRAAALICEPt_M_V2 =(TGraph*)file_JPsi_V2->Get("grRAAALICEPt_M");
  JPsi_grRAAALICEPt_M_V2->SetLineColor(1);
  JPsi_grRAAALICEPt_M_V2->SetLineStyle(1);
  JPsi_grRAAALICEPt_M_V2->SetLineWidth(2);
  
  
  TGraph *JPsi_grRAAALICEPt_M_V3 =(TGraph*)file_JPsi_V3->Get("grRAAALICEPt_M");
  JPsi_grRAAALICEPt_M_V3->SetLineColor(1);
  JPsi_grRAAALICEPt_M_V3->SetLineStyle(1);
  JPsi_grRAAALICEPt_M_V3->SetLineWidth(2);

  
  TGraph *JPsi_grRAAALICEPt_M_V4 =(TGraph*)file_JPsi_V4->Get("grRAAALICEPt_M");
  JPsi_grRAAALICEPt_M_V4->SetLineColor(1);
  JPsi_grRAAALICEPt_M_V4->SetLineStyle(1);
  JPsi_grRAAALICEPt_M_V4->SetLineWidth(2);



  //============================ CMS RAA Vs Pt Graphs =======================//
  TGraph *JPsi_grGluonDissCMSPt_M =(TGraph*)file_JPsi->Get("grGluonDissCMSPt_M");
  JPsi_grGluonDissCMSPt_M->SetLineColor(2);
  JPsi_grGluonDissCMSPt_M->SetLineStyle(7);
  JPsi_grGluonDissCMSPt_M->SetLineWidth(2);


  TGraph *JPsi_grPionDissCMSPt_M =(TGraph*)file_JPsi->Get("grPionDissCMSPt_M");
  JPsi_grPionDissCMSPt_M->SetLineColor(4);
  JPsi_grPionDissCMSPt_M->SetLineStyle(9);
  JPsi_grPionDissCMSPt_M->SetLineWidth(2);


  TGraph *JPsi_grCNMEffCMSPt_M =(TGraph*)file_JPsi->Get("grShadowDissCMSPt_M");
  JPsi_grCNMEffCMSPt_M->SetLineColor(6);
  JPsi_grCNMEffCMSPt_M->SetLineStyle(6);
  JPsi_grCNMEffCMSPt_M->SetLineWidth(2);


  TGraph *JPsi_grRegenCMSPt_M =(TGraph*)file_JPsi->Get("grRegenCMSPt_M");
  JPsi_grRegenCMSPt_M->SetLineColor(8);
  JPsi_grRegenCMSPt_M->SetLineStyle(2);
  JPsi_grRegenCMSPt_M->SetLineWidth(2);

  
  TGraph *JPsi_grRAACMSPt_M =(TGraph*)file_JPsi->Get("grRAACMSPt_M");
  JPsi_grRAACMSPt_M->SetLineColor(1);
  JPsi_grRAACMSPt_M->SetLineStyle(1);
  JPsi_grRAACMSPt_M->SetLineWidth(2);


  TGraph *JPsi_grRAACMSPt_M_V1 =(TGraph*)file_JPsi_V1->Get("grRAACMSPt_M");
  JPsi_grRAACMSPt_M_V1->SetLineColor(1);
  JPsi_grRAACMSPt_M_V1->SetLineStyle(1);
  JPsi_grRAACMSPt_M_V1->SetLineWidth(2);

  
  TGraph *JPsi_grRAACMSPt_M_V2 =(TGraph*)file_JPsi_V2->Get("grRAACMSPt_M");
  JPsi_grRAACMSPt_M_V2->SetLineColor(1);
  JPsi_grRAACMSPt_M_V2->SetLineStyle(1);
  JPsi_grRAACMSPt_M_V2->SetLineWidth(2);
  
  
  TGraph *JPsi_grRAACMSPt_M_V3 =(TGraph*)file_JPsi_V3->Get("grRAACMSPt_M");
  JPsi_grRAACMSPt_M_V3->SetLineColor(1);
  JPsi_grRAACMSPt_M_V3->SetLineStyle(1);
  JPsi_grRAACMSPt_M_V3->SetLineWidth(2);

  
  TGraph *JPsi_grRAACMSPt_M_V4 =(TGraph*)file_JPsi_V4->Get("grRAACMSPt_M");
  JPsi_grRAACMSPt_M_V4->SetLineColor(1);
  JPsi_grRAACMSPt_M_V4->SetLineStyle(1);
  JPsi_grRAACMSPt_M_V4->SetLineWidth(2);





 //============================ ALICE RAA Vs NPart Graphs =======================//
 
  TGraph *JPsi_grGluonDissALICENPart_M =(TGraph*)file_JPsi->Get("grDissALICE_M");
  JPsi_grGluonDissALICENPart_M->SetLineColor(2);
  JPsi_grGluonDissALICENPart_M->SetLineStyle(7);
  JPsi_grGluonDissALICENPart_M->SetLineWidth(2);


  TGraph *JPsi_grPionDissALICENPart_M =(TGraph*)file_JPsi->Get("grPionDissALICE_M");
  JPsi_grPionDissALICENPart_M->SetLineColor(4);
  JPsi_grPionDissALICENPart_M->SetLineStyle(9);
  JPsi_grPionDissALICENPart_M->SetLineWidth(2);


  TGraph *JPsi_grCNMEffALICENPart_M =(TGraph*)file_JPsi->Get("grCNMALICE_M");
  JPsi_grCNMEffALICENPart_M->SetLineColor(6);
  JPsi_grCNMEffALICENPart_M->SetLineStyle(6);
  JPsi_grCNMEffALICENPart_M->SetLineWidth(2);


  TGraph *JPsi_grRegenALICENPart_M =(TGraph*)file_JPsi->Get("grFormALICE_M");
  JPsi_grRegenALICENPart_M->SetLineColor(8);
  JPsi_grRegenALICENPart_M->SetLineStyle(2);
  JPsi_grRegenALICENPart_M->SetLineWidth(2);


  TGraph *JPsi_grRAAALICENPart_M =(TGraph*)file_JPsi->Get("grRAAALICE_M");
  JPsi_grRAAALICENPart_M->SetLineColor(1);
  JPsi_grRAAALICENPart_M->SetLineStyle(1);
  JPsi_grRAAALICENPart_M->SetLineWidth(2);





  TGraph *JPsi_grRAAALICENPart_M_V1 =(TGraph*)file_JPsi_V1->Get("grRAAALICE_M");
  JPsi_grRAAALICENPart_M_V1->SetLineColor(1);
  JPsi_grRAAALICENPart_M_V1->SetLineStyle(1);
  JPsi_grRAAALICENPart_M_V1->SetLineWidth(2);


  TGraph *JPsi_grRAAALICENPart_M_V2 =(TGraph*)file_JPsi_V2->Get("grRAAALICE_M");
  JPsi_grRAAALICENPart_M_V2->SetLineColor(1);
  JPsi_grRAAALICENPart_M_V2->SetLineStyle(1);
  JPsi_grRAAALICENPart_M_V2->SetLineWidth(2);



  TGraph *JPsi_grRAAALICENPart_M_V3 =(TGraph*)file_JPsi_V3->Get("grRAAALICE_M");
  JPsi_grRAAALICENPart_M_V3->SetLineColor(1);
  JPsi_grRAAALICENPart_M_V3->SetLineStyle(1);
  JPsi_grRAAALICENPart_M_V3->SetLineWidth(2);



  TGraph *JPsi_grRAAALICENPart_M_V4 =(TGraph*)file_JPsi_V4->Get("grRAAALICE_M");
  JPsi_grRAAALICENPart_M_V4->SetLineColor(1);
  JPsi_grRAAALICENPart_M_V4->SetLineStyle(1);
  JPsi_grRAAALICENPart_M_V4->SetLineWidth(2);




//============================ CMS RAA Vs NPart Graphs =======================//

 
  TGraph *JPsi_grGluonDissCMSNPart_M =(TGraph*)file_JPsi->Get("grDissCMS_M");
  JPsi_grGluonDissCMSNPart_M->SetLineColor(2);
  JPsi_grGluonDissCMSNPart_M->SetLineStyle(7);
  JPsi_grGluonDissCMSNPart_M->SetLineWidth(2);


  TGraph *JPsi_grPionDissCMSNPart_M =(TGraph*)file_JPsi->Get("grPionDissCMS_M");
  JPsi_grPionDissCMSNPart_M->SetLineColor(4);
  JPsi_grPionDissCMSNPart_M->SetLineStyle(9);
  JPsi_grPionDissCMSNPart_M->SetLineWidth(2);


  TGraph *JPsi_grCNMEffCMSNPart_M =(TGraph*)file_JPsi->Get("grCNMCMS_M");
  JPsi_grCNMEffCMSNPart_M->SetLineColor(6);
  JPsi_grCNMEffCMSNPart_M->SetLineStyle(6);
  JPsi_grCNMEffCMSNPart_M->SetLineWidth(2);



  TGraph *JPsi_grRegenCMSNPart_M =(TGraph*)file_JPsi->Get("grFormCMS_M");
  JPsi_grRegenCMSNPart_M->SetLineColor(8);
  JPsi_grRegenCMSNPart_M->SetLineStyle(2);
  JPsi_grRegenCMSNPart_M->SetLineWidth(2);



  TGraph *JPsi_grRAACMSNPart_M =(TGraph*)file_JPsi->Get("grRAACMS_M");
  JPsi_grRAACMSNPart_M->SetLineColor(1);
  JPsi_grRAACMSNPart_M->SetLineStyle(1);
  JPsi_grRAACMSNPart_M->SetLineWidth(2);

    

  TGraph *JPsi_grRAACMSNPart_M_V1 =(TGraph*)file_JPsi_V1->Get("grRAACMS_M");
  JPsi_grRAACMSNPart_M_V1->SetLineColor(1);
  JPsi_grRAACMSNPart_M_V1->SetLineStyle(1);
  JPsi_grRAACMSNPart_M_V1->SetLineWidth(2);



  TGraph *JPsi_grRAACMSNPart_M_V2 =(TGraph*)file_JPsi_V2->Get("grRAACMS_M");
  JPsi_grRAACMSNPart_M_V2->SetLineColor(1);
  JPsi_grRAACMSNPart_M_V2->SetLineStyle(1);
  JPsi_grRAACMSNPart_M_V2->SetLineWidth(2);


  TGraph *JPsi_grRAACMSNPart_M_V3 =(TGraph*)file_JPsi_V3->Get("grRAACMS_M");
  JPsi_grRAACMSNPart_M_V3->SetLineColor(1);
  JPsi_grRAACMSNPart_M_V3->SetLineStyle(1);
  JPsi_grRAACMSNPart_M_V3->SetLineWidth(2);

  TGraph *JPsi_grRAACMSNPart_M_V4 =(TGraph*)file_JPsi_V4->Get("grRAACMS_M");
  JPsi_grRAACMSNPart_M_V4->SetLineColor(1);
  JPsi_grRAACMSNPart_M_V4->SetLineStyle(1);
  JPsi_grRAACMSNPart_M_V4->SetLineWidth(2);





  // ========= Diss Rate JPsi ===================//
  
  // Diss rates
  TLegend *legd_dissT = new TLegend( 0.24,0.67,0.69,0.86);
  legd_dissT->SetBorderSize(0);
  legd_dissT->SetFillStyle(0);
  legd_dissT->SetFillColor(0);
  legd_dissT->SetTextSize(0.040);
  
  legd_dissT->AddEntry(JPsi_DissRateVsT_KharPt0, "p_{T}= 0", "l");
  legd_dissT->AddEntry(JPsi_DissRateVsT_KharPt36, "p_{T}= 3.6 GeV/c", "l");
  legd_dissT->AddEntry(JPsi_DissRateVsT_KharPt86, "p_{T}= 8.6 GeV/c", "l");
  
  new TCanvas;
  gPad->SetTicks();
  JPsi_DissRateVsT_KharPt0->Draw("AC");
  JPsi_DissRateVsT_KharPt36->Draw("Csame");
  JPsi_DissRateVsT_KharPt86->Draw("Csame");
  legd_dissT->Draw();
  
  tb->DrawLatex(0.16,0.90,"(a)");
  gPad->SaveAs("plots/Fig3a_DRateVsT.png");    
  gPad->SaveAs("plots/Fig3a_DRateVsT.eps");    
  



  TLegend *legd_dissPt = new TLegend( 0.43,0.73,0.88,0.91);
  legd_dissPt->SetBorderSize(0);
  legd_dissPt->SetFillStyle(0);
  legd_dissPt->SetFillColor(0);
  legd_dissPt->SetTextSize(0.040);
  

  legd_dissPt->AddEntry(JPsi_grDissRateVsPt_T200, "T=0.2 GeV", "l");
  legd_dissPt->AddEntry(JPsi_grDissRateVsPt_T400, "T=0.4 GeV", "l");
  legd_dissPt->AddEntry(JPsi_grDissRateVsPt_T600, "T=0.6 GeV", "l");


  new TCanvas; 
  gPad->SetTicks();
  JPsi_grDissRateVsPt_T200->GetYaxis()->SetRangeUser(0.0,5.0);
  JPsi_grDissRateVsPt_T200->Draw("AC");
  JPsi_grDissRateVsPt_T400->Draw("Csame");
  JPsi_grDissRateVsPt_T600->Draw("Csame");
  legd_dissPt->Draw();
  tb->DrawLatex(0.16,0.90,"(b)");
    
  gPad->SaveAs("plots/Fig3b_DRateVsPt.png");    
  gPad->SaveAs("plots/Fig3b_DRateVsPt.eps");

 

  // ========= Form Rate JPsi ===================//
  // JPsi_grFormRateVsP_MCInt_T3

  TLegend *lgd_FRVsT = new TLegend( 0.51,0.78,0.84,0.92);
  lgd_FRVsT->SetBorderSize(0);
  lgd_FRVsT->SetFillStyle(0);
  lgd_FRVsT->SetFillColor(0);
  lgd_FRVsT->SetTextSize(0.040);
  lgd_FRVsT->AddEntry(JPsi_grFormRateVsT_MCInt_P1, "p_{T} = 2.25 GeV/c", "L");
  lgd_FRVsT->AddEntry(JPsi_grFormRateVsT_MCInt_P2, "p_{T} = 3.25 GeV/c", "L");
  lgd_FRVsT->AddEntry(JPsi_grFormRateVsT_MCInt_P3, "p_{T} = 4.25 GeV/c", "L");
  
  new TCanvas;
  gPad->SetTicks();
  gPad->SetLogy();
  JPsi_grFormRateVsT_MCInt_P1->GetXaxis()->SetTitle("Temperature (GeV)");
  JPsi_grFormRateVsT_MCInt_P1->GetYaxis()->SetTitleOffset(1.1);
  JPsi_grFormRateVsT_MCInt_P1->GetYaxis()->SetTitle("d#lambda_{F}/dp_{T}(fm^{2}GeV^{-1})");
  JPsi_grFormRateVsT_MCInt_P1->GetYaxis()->SetRangeUser(0.00001,1.0);
  JPsi_grFormRateVsT_MCInt_P1->Draw("AC");
  JPsi_grFormRateVsT_MCInt_P2->Draw("Csame");
  JPsi_grFormRateVsT_MCInt_P3->Draw("Csame");
  

  lgd_FRVsT->Draw("same");
  tb->DrawLatex(0.16,0.90,"(a)");
  gPad->SaveAs("plots/Fig4a_FRateVsT.png");
  gPad->SaveAs("plots/Fig4a_FRateVsT.pdf");
  gPad->SaveAs("plots/Fig4a_FRateVsT.eps");
 


  TLegend *legd_formPt = new TLegend( 0.44,0.73,0.90,0.92);
  legd_formPt->SetBorderSize(0);
  legd_formPt->SetFillStyle(0);
  legd_formPt->SetFillColor(0);
  legd_formPt->SetTextSize(0.040);  

  //JPsi_grFormRateVsP_MCInt_T3

  legd_formPt->AddEntry(JPsi_grFormRateVsP_MCInt_T1,"T=0.2 GeV", "L");
  legd_formPt->AddEntry(JPsi_grFormRateVsP_MCInt_T2,"T=0.4 GeV", "L");
  legd_formPt->AddEntry(JPsi_grFormRateVsP_MCInt_T3,"T=0.6 GeV", "L");
  
  new TCanvas;
  gPad->SetTicks();
  gPad->SetLogy();
  gPad->SetLeftMargin(0.14);

  JPsi_grFormRateVsP_MCInt_T1->GetXaxis()->SetTitle("p_{T}(GeV/c)");
  JPsi_grFormRateVsP_MCInt_T1->GetYaxis()->SetTitleOffset(1.2);
  JPsi_grFormRateVsP_MCInt_T1->GetYaxis()->SetTitle("d#lambda_{F}/dp_{T} (fm^{2}GeV^{-1})");
  JPsi_grFormRateVsP_MCInt_T1->GetYaxis()->SetRangeUser(0.0001,1.0);
  
  JPsi_grFormRateVsP_MCInt_T1->Draw("AC");
  JPsi_grFormRateVsP_MCInt_T2->Draw("Csame");
  JPsi_grFormRateVsP_MCInt_T3->Draw("Csame");
  legd_formPt->Draw("same");
  tb->DrawLatex(0.16,0.90,"(b)");
  gPad->SaveAs("plots/Fig4b_FRateVsPt.png");
  gPad->SaveAs("plots/Fig4b_FRateVsPt.eps");
  gPad->SaveAs("plots/Fig4b_FRateVsPt.pdf");
  






  // ================= RAA Vs Pt Graphs for JPsi ALICE =====================//
  Int_t NNPtALICE = 21;
  Double_t PtALICE[25]={0.25,0.75,1.25,1.75,2.25,2.75,3.25,3.75,4.25,4.75,5.25,5.75,6.25,6.75,7.25,7.75,8.25,8.75,9.25,9.75,10.25}; 
  Double_t RAAALICEPt[25];
  Double_t RAAUALICEPt[25];
  Double_t RAALALICEPt[25];
 

  for (int j=0; j < JPsi_grRAAALICEPt_M->GetN();++j){
    
    Double_t Pt, GluonTotal, PionTotal, ShadowTotal, RegenTotal, RAATotal;
    Double_t JPsi_Gluon, JPsi_Pion, JPsi_Shadow, JPsi_Regen,JPsi_Total;
    
    Double_t y=0.0;
    Double_t y1=0.0;
    Double_t y2=0.0;
    Double_t y3=0.0;
    Double_t y4=0.0;
    Double_t yMax =0.0;
    Double_t yMin =0.0;


    JPsi_grGluonDissALICEPt_M->GetPoint(j,Pt,JPsi_Gluon);
    JPsi_grPionDissALICEPt_M->GetPoint(j,Pt,JPsi_Pion);
    JPsi_grCNMEffALICEPt_M->GetPoint(j,Pt,JPsi_Shadow);
    JPsi_grRegenALICEPt_M->GetPoint(j,Pt,JPsi_Regen);
    
    JPsi_grRAAALICEPt_M->GetPoint(j,Pt,JPsi_Total);

    JPsi_grRAAALICEPt_M->GetPoint(j,Pt,y);
    JPsi_grRAAALICEPt_M_V1->GetPoint(j,Pt,y1);
    JPsi_grRAAALICEPt_M_V2->GetPoint(j,Pt,y2);
    JPsi_grRAAALICEPt_M_V3->GetPoint(j,Pt,y3);
    JPsi_grRAAALICEPt_M_V4->GetPoint(j,Pt,y4);
    
    yMax = TMath::Max(TMath::Max(y1,y2),TMath::Max(y3,y4));
    yMin = TMath::Min(TMath::Min(y1,y2),TMath::Min(y3,y4));
    
    
    RAAALICEPt[j] = y;
    RAAUALICEPt[j] = yMax;
    RAALALICEPt[j] = yMin;
    
    RAATotal = JPsi_Total;
    GluonTotal = JPsi_Gluon;
    PionTotal = JPsi_Pion; 
    ShadowTotal = JPsi_Shadow;
    RegenTotal = JPsi_Regen;

    JPsi_grRAAALICEPt_M->SetPoint(j,Pt,RAATotal);
    JPsi_grGluonDissALICEPt_M->SetPoint(j,Pt,GluonTotal);  
    JPsi_grPionDissALICEPt_M->SetPoint(j,Pt,PionTotal);  
    JPsi_grCNMEffALICEPt_M->SetPoint(j,Pt,ShadowTotal);  
    JPsi_grRegenALICEPt_M->SetPoint(j,Pt,RegenTotal);
    
    cout<<Pt<<"   "<<RAALALICEPt[j]<<"    "<<RAAALICEPt[j]<<"    "<<RAAUALICEPt[j]<<endl;
  }

  //================ Make new RAA Shade Graph here =========================//

  
  TGraph *JPsi_grRAAALICEPt_M_Shade = new TGraph(2*NNPtALICE);  
  for(Int_t i=0;i<NNPtALICE;i++)
    {
      JPsi_grRAAALICEPt_M_Shade->SetPoint(i,PtALICE[i],RAAUALICEPt[i]);
      JPsi_grRAAALICEPt_M_Shade->SetPoint(NNPtALICE+i,PtALICE[NNPtALICE-i-1],RAALALICEPt[NNPtALICE-i-1]);
    }
    
  
  TGraph *JPsi_grRAAUALICEPt_M = new TGraph(NNPtALICE,PtALICE,RAAUALICEPt); 
  TGraph *JPsi_grRAALALICEPt_M = new TGraph(NNPtALICE,PtALICE,RAALALICEPt); 
  
  
  JPsi_grRAAALICEPt_M_Shade->GetXaxis()->SetTitle("p_{T}(GeV/c)");
  JPsi_grRAAALICEPt_M_Shade->GetYaxis()->SetTitle("R_{AA}");
  JPsi_grRAAALICEPt_M_Shade->GetYaxis()->SetRangeUser(0.0,1.5);
  JPsi_grRAAALICEPt_M_Shade->SetName("JPsi_grRAAALICEPt_M_Shade");
  JPsi_grRAAALICEPt_M_Shade->SetTitle("JPsi_grRAAALICEPt_M_Shade");
    
    
    new TCanvas;
    gPad->SetTicks();
    grShJPsiVsPtALICE_Shade->SetFillStyle(3013);
    grShJPsiVsPtALICE_Shade->SetFillColor(46);
    grShJPsiVsPtALICE_Shade->Draw("Af");
    grShJPsiVsPtALICE->Draw("CSame");
    grShUJPsiVsPtALICE->Draw("lSame");
    grShLJPsiVsPtALICE->Draw("lSame");
        
    JPsi_grRAAALICEPt_M_Shade->SetFillStyle(3013);    
    JPsi_grRAAALICEPt_M_Shade->SetFillColor(16);  
    JPsi_grRAAALICEPt_M_Shade->Draw("fsame");


    TLegend *legd1 = new TLegend(0.16,0.56,0.89,0.93);
    legd1->SetBorderSize(0);
    legd1->SetFillStyle(0);
    legd1->SetFillColor(0);
    legd1->SetTextSize(0.030);
    
    new TCanvas;
    gPad->SetTicks();
    Draw_ALICEFor_JPsi_RaaVspT(legd1);  
    legd1->AddEntry(JPsi_grGluonDissALICEPt_M,"Gluon Dissociation","L");
    legd1->AddEntry(JPsi_grPionDissALICEPt_M,"Pion Dissociation","L");
    legd1->AddEntry(JPsi_grCNMEffALICEPt_M,"CNM Effects","L");
    legd1->AddEntry(JPsi_grRegenALICEPt_M,"Formation","L");
    legd1->AddEntry(JPsi_grRAAALICEPt_M,"Total (R_{AA})","L");
    
    JPsi_grRAAALICEPt_M->Draw("Csame");
    JPsi_grGluonDissALICEPt_M->Draw("Csame");
    JPsi_grPionDissALICEPt_M->Draw("Csame");
    JPsi_grRegenALICEPt_M->Draw("Csame");
    JPsi_grCNMEffALICEPt_M->Draw("Csame");
    legd1->Draw("same");

    JPsi_grRAAALICEPt_M_Shade->Draw("fsame");
    JPsi_grRAAUALICEPt_M->SetLineColor(12);
    JPsi_grRAAUALICEPt_M->Draw("lsame");
    JPsi_grRAALALICEPt_M->SetLineColor(12);
    JPsi_grRAALALICEPt_M->Draw("lsame");
    grShJPsiVsPtALICE_Shade->Draw("fsame");
    grShUJPsiVsPtALICE->SetLineColor(46);
    grShUJPsiVsPtALICE->Draw("lSame");
    grShLJPsiVsPtALICE->SetLineColor(46);
    grShLJPsiVsPtALICE->Draw("lSame");
    JPsi_grRAAALICEPt_M->Draw("Csame");
    JPsi_grCNMEffALICEPt_M->Draw("Csame");

    gPad->SaveAs("plots/Fig5a_ALICE_RAAPt.eps");
    gPad->SaveAs("plots/Fig5a_ALICE_RAAPt.png");
  

    //  return;  



    //================== RAA CMS Vs pT ========================================//    

    Int_t NNPtCMS = 59;
    Double_t PtCMS[100]= {0.25,0.75,1.25,1.75,2.25,2.75,3.25,3.75,4.25,4.75,5.25,5.75,6.25,6.75,7.25,7.75,8.25,8.75,
			  9.25,9.75,10.25,10.75,11.25,11.75,12.25,12.75,13.25,13.75,14.25,14.75,15.25,15.75,16.25,
			  16.75,17.25,17.75,18.25,18.75,19.25,19.75,20.25,20.75,21.25,21.75,22.25,22.75,23.25,23.75,
			  24.25,24.75,25.25,25.75,26.25,26.75,27.25,27.75,28.25,28.75,29.25,29.75,30.25,30.75};

    Double_t RAACMSPt[100];
    Double_t RAAUCMSPt[100];
    Double_t RAALCMSPt[100];

    for (int j=0; j < JPsi_grRAACMSPt_M->GetN();++j){
      
      Double_t Pt, GluonTotal, PionTotal, ShadowTotal, RegenTotal, RAATotal;
      Double_t JPsi_Gluon, JPsi_Pion, JPsi_Shadow, JPsi_Regen,JPsi_Total;
      
      JPsi_grGluonDissCMSPt_M->GetPoint(j,Pt,JPsi_Gluon);
      JPsi_grPionDissCMSPt_M->GetPoint(j,Pt,JPsi_Pion);
      JPsi_grCNMEffCMSPt_M->GetPoint(j,Pt,JPsi_Shadow);
      JPsi_grRegenCMSPt_M->GetPoint(j,Pt,JPsi_Regen);
      JPsi_grRAACMSPt_M->GetPoint(j,Pt,JPsi_Total);
      
      RAATotal = JPsi_Total;
      GluonTotal = JPsi_Gluon;
      PionTotal = JPsi_Pion; 
      ShadowTotal = JPsi_Shadow;
      RegenTotal = JPsi_Regen;
      
      JPsi_grRAACMSPt_M->SetPoint(j,Pt,RAATotal);
      JPsi_grGluonDissCMSPt_M->SetPoint(j,Pt,GluonTotal);  
      JPsi_grPionDissCMSPt_M->SetPoint(j,Pt,PionTotal);  
      JPsi_grCNMEffCMSPt_M->SetPoint(j,Pt,ShadowTotal);  
      JPsi_grRegenCMSPt_M->SetPoint(j,Pt,RegenTotal);
    
    
      Double_t y=0.0;
      Double_t y1=0.0;
      Double_t y2=0.0;
      Double_t y3=0.0;
      Double_t y4=0.0;
      Double_t yMax =0.0;
      Double_t yMin =0.0;

      //JPsi_grGluonDissCMSPt_M->GetPoint(j,Pt,JPsi_Gluon);
      //JPsi_grPionDissCMSPt_M->GetPoint(j,Pt,JPsi_Pion);
      //JPsi_grCNMEffCMSPt_M->GetPoint(j,Pt,JPsi_Shadow);
      //JPsi_grRegenCMSPt_M->GetPoint(j,Pt,JPsi_Regen);
      //JPsi_grRAACMSPt_M->GetPoint(j,Pt,JPsi_Total);
      
      JPsi_grRAACMSPt_M->GetPoint(j,Pt,y);
      JPsi_grRAACMSPt_M_V1->GetPoint(j,Pt,y1);
      JPsi_grRAACMSPt_M_V2->GetPoint(j,Pt,y2);
      JPsi_grRAACMSPt_M_V3->GetPoint(j,Pt,y3);
      JPsi_grRAACMSPt_M_V4->GetPoint(j,Pt,y4);
      
      yMax = TMath::Max(TMath::Max(y1,y2),TMath::Max(y3,y4));
      yMin = TMath::Min(TMath::Min(y1,y2),TMath::Min(y3,y4));
    
    
      RAACMSPt[j] = y;
      RAAUCMSPt[j] = yMax;
      RAALCMSPt[j] = yMin;
    

      }
    
      TGraph *JPsi_grRAACMSPt_M_Shade = new TGraph(2*NNPtCMS);  
      for(Int_t i=0;i<NNPtCMS;i++)
	{
	  JPsi_grRAACMSPt_M_Shade->SetPoint(i,PtCMS[i],RAAUCMSPt[i]);
	  JPsi_grRAACMSPt_M_Shade->SetPoint(NNPtCMS+i,PtCMS[NNPtCMS-i-1],RAALCMSPt[NNPtCMS-i-1]);
	}
      
  
      TGraph *JPsi_grRAAUCMSPt_M = new TGraph(NNPtCMS,PtCMS,RAAUCMSPt); 
      TGraph *JPsi_grRAALCMSPt_M = new TGraph(NNPtCMS,PtCMS,RAALCMSPt); 
      
  
      JPsi_grRAACMSPt_M_Shade->GetXaxis()->SetTitle("p_{T}(GeV/c)");
      JPsi_grRAACMSPt_M_Shade->GetYaxis()->SetTitle("R_{AA}");
      JPsi_grRAACMSPt_M_Shade->GetYaxis()->SetRangeUser(0.0,1.5);
      JPsi_grRAACMSPt_M_Shade->SetName("JPsi_grRAACMSPt_M_Shade");
      JPsi_grRAACMSPt_M_Shade->SetTitle("JPsi_grRAACMSPt_M_Shade");
    



      new TCanvas;
      gPad->SetTicks();
      grShJPsiVsPtCMS_Shade->SetFillStyle(3013);
      grShJPsiVsPtCMS_Shade->SetFillColor(46);
      grShJPsiVsPtCMS_Shade->Draw("Af");
      grShJPsiVsPtCMS->Draw("CSame");
      grShUJPsiVsPtCMS->Draw("lSame");
      grShLJPsiVsPtCMS->Draw("lSame");
      
      JPsi_grRAACMSPt_M_Shade->SetFillStyle(3013);    
      JPsi_grRAACMSPt_M_Shade->SetFillColor(16);  
      JPsi_grRAACMSPt_M_Shade->Draw("fsame");


    

      TLegend *legd2 = new TLegend(0.16,0.58,0.91,0.92);
      legd2->SetBorderSize(0);
      legd2->SetFillStyle(0);
      legd2->SetFillColor(0);
      legd2->SetTextSize(0.030);
 
      new TCanvas;
      gPad->SetTicks();
      Draw_CMS_JPsi_RaaVspT(legd2);  
      
      legd2->AddEntry(JPsi_grGluonDissCMSPt_M,"Gluon Dissociation","L");
      legd2->AddEntry(JPsi_grPionDissCMSPt_M,"Comover","L");
      legd2->AddEntry(JPsi_grCNMEffCMSPt_M,"CNM Effects","L");
      legd2->AddEntry(JPsi_grRegenCMSPt_M,"Formation","L");
      legd2->AddEntry(JPsi_grRAACMSPt_M,"Total (R_{AA})","L");
      
      JPsi_grRAACMSPt_M->Draw("Csame");
      JPsi_grGluonDissCMSPt_M->Draw("Csame");
      JPsi_grPionDissCMSPt_M->Draw("Csame");
      JPsi_grRegenCMSPt_M->Draw("Csame");
      JPsi_grCNMEffCMSPt_M->Draw("Csame");
      legd2->Draw("same");
      
  
      JPsi_grRAACMSPt_M_Shade->Draw("fsame");
      JPsi_grRAAUCMSPt_M->SetLineColor(12);
      JPsi_grRAAUCMSPt_M->Draw("lsame");
      JPsi_grRAALCMSPt_M->SetLineColor(12);
      JPsi_grRAALCMSPt_M->Draw("lsame");
      grShJPsiVsPtCMS_Shade->Draw("fsame");
      grShUJPsiVsPtCMS->SetLineColor(46);
      grShUJPsiVsPtCMS->Draw("lSame");
      grShLJPsiVsPtCMS->SetLineColor(46);
      grShLJPsiVsPtCMS->Draw("lSame");
      JPsi_grRAACMSPt_M->Draw("Csame");
      JPsi_grCNMEffCMSPt_M->Draw("Csame");

      
      gPad->SaveAs("plots/Fig5b_CMS_RAAPt.eps");
      gPad->SaveAs("plots/Fig5b_CMS_RAAPt.png");
      

       
 
 //============== ALICE RAA Vs NPart JPsi ====================//


      
      Int_t NNNPartALICE = 0;
      Double_t NPartALICE[20]={0}; 
      Double_t RAAALICENPart[20]={0};
      Double_t RAAUALICENPart[20]={0};
      Double_t RAALALICENPart[20]={0};

      NNNPartALICE=JPsi_grRAAALICENPart_M->GetN();
      cout<<" NNNPartALICE "<<NNNPartALICE<<endl;
 
      for (int j=0; j < JPsi_grRAAALICENPart_M->GetN();++j){
	
	Double_t NPart, GluonTotal, PionTotal, ShadowTotal, RegenTotal, RAATotal;
	Double_t JPsi_Gluon, JPsi_Pion, JPsi_Shadow, JPsi_Regen,JPsi_Total,JPsi_RAA;
	
	JPsi_grGluonDissALICENPart_M->GetPoint(j,NPart,JPsi_Gluon);
	JPsi_grPionDissALICENPart_M->GetPoint(j,NPart,JPsi_Pion);
	JPsi_grCNMEffALICENPart_M->GetPoint(j,NPart,JPsi_Shadow);
	JPsi_grRegenALICENPart_M->GetPoint(j,NPart,JPsi_Regen);
	JPsi_grRAAALICENPart_M->GetPoint(j,NPart,JPsi_RAA);
        
	PionTotal = JPsi_Pion;
	ShadowTotal = JPsi_Shadow; 
        GluonTotal = JPsi_Gluon/(PionTotal*ShadowTotal); 
        RegenTotal = JPsi_Regen;
    	RAATotal = JPsi_RAA;    
	
	JPsi_grRAAALICENPart_M->SetPoint(j,NPart,RAATotal);
        JPsi_grGluonDissALICENPart_M->SetPoint(j,NPart,GluonTotal);  
        JPsi_grPionDissALICENPart_M->SetPoint(j,NPart,PionTotal);  
	JPsi_grCNMEffALICENPart_M->SetPoint(j,NPart,ShadowTotal);  
	JPsi_grRegenALICENPart_M->SetPoint(j,NPart,RegenTotal);
	
	Double_t y=0.0;
	Double_t y1=0.0;
	Double_t y2=0.0;
	Double_t y3=0.0;
	Double_t y4=0.0;
	Double_t yMax =0.0;
	Double_t yMin =0.0;
	

	JPsi_grRAAALICENPart_M->GetPoint(j,NPart,y);
	JPsi_grRAAALICENPart_M_V1->GetPoint(j,NPart,y1);
	JPsi_grRAAALICENPart_M_V2->GetPoint(j,NPart,y2);
	JPsi_grRAAALICENPart_M_V3->GetPoint(j,NPart,y3);
	JPsi_grRAAALICENPart_M_V4->GetPoint(j,NPart,y4);
	yMax = TMath::Max(TMath::Max(y1,y2),TMath::Max(y3,y4));
	yMin = TMath::Min(TMath::Min(y1,y2),TMath::Min(y3,y4));
	NPartALICE[j]=NPart;
	RAAALICENPart[j] = y;
	RAAUALICENPart[j] = yMax;
	RAALALICENPart[j] = yMin;
	// cout<<" Comover "<<PionTotal<<" CNM "<<ShadowTotal<<" Gluon "<<GluonTotal<<"  Regen "<< RegenTotal<<" RAA "<<RAATotal<<endl;
	cout<<NPart<<"   "<<RAALALICENPart[j]<<"   "<<RAAALICENPart[j]<<"   "<<RAAUALICENPart[j]<<endl;
      }
      
      //================ Make new RAA Shade Graph here =========================//
      
  
      TGraph *JPsi_grRAAALICENPart_M_Shade = new TGraph(2*NNNPartALICE);  
      for(Int_t i=0;i<NNNPartALICE;i++)
	{
	  JPsi_grRAAALICENPart_M_Shade->SetPoint(i,NPartALICE[i],RAAUALICENPart[i]);
	  JPsi_grRAAALICENPart_M_Shade->SetPoint(NNNPartALICE+i,NPartALICE[NNNPartALICE-i-1],RAALALICENPart[NNNPartALICE-i-1]);
	}
      
  
      TGraph *JPsi_grRAAUALICENPart_M = new TGraph(NNNPartALICE,NPartALICE,RAAUALICENPart); 
      TGraph *JPsi_grRAALALICENPart_M = new TGraph(NNNPartALICE,NPartALICE,RAALALICENPart); 
      
  
      JPsi_grRAAALICENPart_M_Shade->GetXaxis()->SetTitle("p_{T}(GeV/c)");
      JPsi_grRAAALICENPart_M_Shade->GetYaxis()->SetTitle("R_{AA}");
      JPsi_grRAAALICENPart_M_Shade->GetYaxis()->SetRangeUser(0.0,1.5);
      JPsi_grRAAALICENPart_M_Shade->SetName("JPsi_grRAAALICENPart_M_Shade");
      JPsi_grRAAALICENPart_M_Shade->SetTitle("JPsi_grRAAALICENPart_M_Shade");
    
    
      new TCanvas;
      gPad->SetTicks();
      grShJPsiVsNPart_Shade->SetFillStyle(3013);
      grShJPsiVsNPart_Shade->SetFillColor(46);
      
      grShJPsiVsNPart_Shade->Draw("Af");
      grShJPsiVsNPart->Draw("CSame");
      grShUJPsiVsNPart->Draw("lSame");
      grShLJPsiVsNPart->Draw("lSame");
      

      new TCanvas;
      gPad->SetTicks();
      JPsi_grRAAALICENPart_M_Shade->SetFillStyle(3013);    
      JPsi_grRAAALICENPart_M_Shade->SetFillColor(16);  
      JPsi_grRAAALICENPart_M_Shade->Draw("Af");


    
      TLegend *legd3 = new TLegend(0.16,0.57,0.89,0.94);
      legd3->SetBorderSize(0);
      legd3->SetFillStyle(0);
      legd3->SetFillColor(0);
      legd3->SetTextSize(0.030);
 
      new TCanvas;
      gPad->SetTicks();
      
      Draw_ALICEFor_JPsi_RaaVsNpart(legd3);
      
      legd3->AddEntry(JPsi_grGluonDissALICENPart_M,"Gluon Dissociation","L");
      legd3->AddEntry(JPsi_grPionDissALICENPart_M,"Comover","L");
      legd3->AddEntry(JPsi_grCNMEffALICENPart_M,"CNM Effects","L");
      legd3->AddEntry(JPsi_grRegenALICENPart_M,"Formation","L");
      legd3->AddEntry(JPsi_grRAAALICENPart_M,"Total (R_{AA})","L");
    
      JPsi_grRAAALICENPart_M->Draw("Csame");
      JPsi_grGluonDissALICENPart_M->Draw("Csame");
      JPsi_grPionDissALICENPart_M->Draw("Csame");
      JPsi_grCNMEffALICENPart_M->Draw("Csame");
      JPsi_grRegenALICENPart_M->Draw("Csame");
      legd3->Draw("same");
      

      
      JPsi_grRAAALICENPart_M_Shade->Draw("fsame");
      JPsi_grRAAUALICENPart_M->SetLineColor(12);
      JPsi_grRAAUALICENPart_M->Draw("lsame");
      JPsi_grRAALALICENPart_M->SetLineColor(12);
      JPsi_grRAALALICENPart_M->Draw("lsame");
  
      
      grShJPsiVsNPart_Shade->Draw("fsame");
      grShUJPsiVsNPart->SetLineColor(46);
      grShUJPsiVsNPart->Draw("lSame");
      grShLJPsiVsNPart->SetLineColor(46);
      grShLJPsiVsNPart->Draw("lSame");
      JPsi_grRAAALICENPart_M->Draw("Csame");
      JPsi_grCNMEffALICENPart_M->Draw("Csame");
    
    
      

    gPad->SaveAs("plots/Fig6a_ALICE_RAANPart.eps");
    gPad->SaveAs("plots/Fig6a_ALICE_RAANPart.png");


 //============== CMS RAA Vs NPart JPsi ====================//

    Int_t NNNPartCMS = 0;
    Double_t NPartCMS[20]={0}; 
    Double_t RAACMSNPart[20]={0};
    Double_t RAAUCMSNPart[20]={0};
    Double_t RAALCMSNPart[20]={0};
    
    NNNPartCMS=JPsi_grRAACMSNPart_M->GetN();
    cout<<" NNNPartCMS "<<NNNPartCMS<<endl;



 for (int j=0; j < JPsi_grRAACMSNPart_M->GetN();++j){
  
    Double_t NPart, GluonTotal, PionTotal, ShadowTotal, RegenTotal, RAATotal;
    Double_t JPsi_Gluon, JPsi_Pion, JPsi_Shadow, JPsi_Regen,JPsi_Total,JPsi_RAA;
    
    JPsi_grGluonDissCMSNPart_M->GetPoint(j,NPart,JPsi_Gluon);
    JPsi_grPionDissCMSNPart_M->GetPoint(j,NPart,JPsi_Pion);
    JPsi_grCNMEffCMSNPart_M->GetPoint(j,NPart,JPsi_Shadow);
    JPsi_grRegenCMSNPart_M->GetPoint(j,NPart,JPsi_Regen);
    JPsi_grRAACMSNPart_M->GetPoint(j,NPart,JPsi_RAA);
        

    PionTotal = JPsi_Pion;
    ShadowTotal = JPsi_Shadow; 
    GluonTotal = JPsi_Gluon/(PionTotal*ShadowTotal); 
    RegenTotal = JPsi_Regen;
    RAATotal = JPsi_RAA;    

    JPsi_grRAACMSNPart_M->SetPoint(j,NPart,RAATotal);
    JPsi_grGluonDissCMSNPart_M->SetPoint(j,NPart,GluonTotal);  
    JPsi_grPionDissCMSNPart_M->SetPoint(j,NPart,PionTotal);  
    JPsi_grCNMEffCMSNPart_M->SetPoint(j,NPart,ShadowTotal);  
    JPsi_grRegenCMSNPart_M->SetPoint(j,NPart,RegenTotal);
    
 
    Double_t y=0.0;
    Double_t y1=0.0;
    Double_t y2=0.0;
    Double_t y3=0.0;
    Double_t y4=0.0;
    Double_t yMax =0.0;
    Double_t yMin =0.0;
	
    
    JPsi_grRAACMSNPart_M->GetPoint(j,NPart,y);
    JPsi_grRAACMSNPart_M_V1->GetPoint(j,NPart,y1);
    JPsi_grRAACMSNPart_M_V2->GetPoint(j,NPart,y2);
    JPsi_grRAACMSNPart_M_V3->GetPoint(j,NPart,y3);
    JPsi_grRAACMSNPart_M_V4->GetPoint(j,NPart,y4);
    yMax = TMath::Max(TMath::Max(y1,y2),TMath::Max(y3,y4));
    yMin = TMath::Min(TMath::Min(y1,y2),TMath::Min(y3,y4));
    NPartCMS[j]=NPart;
    RAACMSNPart[j] = y;
    RAAUCMSNPart[j] = yMax;
    RAALCMSNPart[j] = yMin;
    // cout<<" Comover "<<PionTotal<<" CNM "<<ShadowTotal<<" Gluon "<<GluonTotal<<"  Regen "<< RegenTotal<<" RAA "<<RAATotal<<endl;
    cout<<NPart<<"   "<<RAALCMSNPart[j]<<"   "<<RAACMSNPart[j]<<"   "<<RAAUCMSNPart[j]<<endl;

    
 }
 
 TGraph *JPsi_grRAACMSNPart_M_Shade = new TGraph(2*NNNPartCMS);  
 for(Int_t i=0;i<NNNPartCMS;i++)
   {
     JPsi_grRAACMSNPart_M_Shade->SetPoint(i,NPartCMS[i],RAAUCMSNPart[i]);
     JPsi_grRAACMSNPart_M_Shade->SetPoint(NNNPartCMS+i,NPartCMS[NNNPartCMS-i-1],RAALCMSNPart[NNNPartCMS-i-1]);
   }
 
  
 TGraph *JPsi_grRAAUCMSNPart_M = new TGraph(NNNPartCMS,NPartCMS,RAAUCMSNPart); 
 TGraph *JPsi_grRAALCMSNPart_M = new TGraph(NNNPartCMS,NPartCMS,RAALCMSNPart); 
 
 
 JPsi_grRAACMSNPart_M_Shade->GetXaxis()->SetTitle("N_{Part}");
 JPsi_grRAACMSNPart_M_Shade->GetYaxis()->SetTitle("R_{AA}");
 JPsi_grRAACMSNPart_M_Shade->GetYaxis()->SetRangeUser(0.0,1.5);
 JPsi_grRAACMSNPart_M_Shade->SetName("JPsi_grRAACMSNPart_M_Shade");
 JPsi_grRAACMSNPart_M_Shade->SetTitle("JPsi_grRAACMSNPart_M_Shade");
 
 
 new TCanvas;
 gPad->SetTicks();
 

 
 grShJPsiPtCutVsNPart_Shade->SetFillStyle(3013);
 grShJPsiPtCutVsNPart_Shade->SetFillColor(46);
 grShJPsiPtCutVsNPart_Shade->Draw("Af");
 grShJPsiPtCutVsNPart->Draw("CSame");
 grShUJPsiPtCutVsNPart->Draw("lSame");
 grShLJPsiPtCutVsNPart->Draw("lSame");
 

 new TCanvas;
 gPad->SetTicks();
 JPsi_grRAACMSNPart_M_Shade->SetFillStyle(3013);    
 JPsi_grRAACMSNPart_M_Shade->SetFillColor(16);  
 JPsi_grRAACMSNPart_M_Shade->Draw("Af");
 


 TLegend *legd4 = new TLegend(0.18,0.57,0.81,0.93);
 legd4->SetBorderSize(0);
 legd4->SetFillStyle(0);
 legd4->SetFillColor(0);
 legd4->SetTextSize(0.030);
 
 new TCanvas;
 gPad->SetTicks();
 Draw_CMS_JPsi_RaaVsNpart(legd4);
 legd4->AddEntry(JPsi_grGluonDissCMSNPart_M,"Gluon Dissociation","L");
 legd4->AddEntry(JPsi_grPionDissCMSNPart_M,"Comover","L");
 legd4->AddEntry(JPsi_grCNMEffCMSNPart_M,"CNM Effects","L");
 legd4->AddEntry(JPsi_grRegenCMSNPart_M,"Formation","L");
 legd4->AddEntry(JPsi_grRAACMSNPart_M,"Total (R_{AA})","L");
 
 JPsi_grRAACMSNPart_M->Draw("Csame");
 JPsi_grGluonDissCMSNPart_M->Draw("Csame");
 JPsi_grPionDissCMSNPart_M->Draw("Csame");
 JPsi_grCNMEffCMSNPart_M->Draw("Csame"); 
 JPsi_grRegenCMSNPart_M->Draw("Csame");
 legd4->Draw("same");
 

 JPsi_grRAACMSNPart_M_Shade->Draw("fsame");
 JPsi_grRAAUCMSNPart_M->SetLineColor(12);
 JPsi_grRAAUCMSNPart_M->Draw("lsame");
 JPsi_grRAALCMSNPart_M->SetLineColor(12);
 JPsi_grRAALCMSNPart_M->Draw("lsame");
  
 
 grShJPsiPtCutVsNPart_Shade->Draw("fsame");
 grShUJPsiPtCutVsNPart->SetLineColor(46);
 grShUJPsiPtCutVsNPart->Draw("lSame");
 grShLJPsiPtCutVsNPart->SetLineColor(46);
 grShLJPsiPtCutVsNPart->Draw("lSame");
 JPsi_grRAACMSNPart_M->Draw("Csame");
 JPsi_grCNMEffCMSNPart_M->Draw("Csame");

 gPad->SaveAs("plots/Fig6b_CMS_RAANPart.eps");
 gPad->SaveAs("plots/Fig6b_CMS_RAANPart.png");


//================================ Open Y1S Root File ================================================//
 TFile *file_Y1S;
 TFile *file_Y1S_V1;
 TFile *file_Y1S_V2;
 TFile *file_Y1S_V3;
 TFile *file_Y1S_V4;
 
 file_Y1S= new TFile("04032015_Y1SCalculations.root","R");
 

 file_Y1S_V1 = new TFile("SigmaDFac05_Y1SCalculations.root","R");
 file_Y1S_V2 = new TFile("SigmaDFac15_Y1SCalculations.root","R");
 file_Y1S_V3 = new TFile("Tau001_Y1SCalculations.root","R");
 file_Y1S_V4 = new TFile("Tau006_Y1SCalculations.root","R"); 

  //============================ CMS RAA Vs NPart Graphs =======================//

 
  TGraph *Y1S_grGluonDissCMSNPart_M =(TGraph*)file_Y1S->Get("grDissCMS_M");
  Y1S_grGluonDissCMSNPart_M->SetLineColor(2);
  Y1S_grGluonDissCMSNPart_M->SetLineStyle(7);
  Y1S_grGluonDissCMSNPart_M->SetLineWidth(2);


  TGraph *Y1S_grPionDissCMSNPart_M =(TGraph*)file_Y1S->Get("grPionDissCMS_M");
  Y1S_grPionDissCMSNPart_M->SetLineColor(4);
  Y1S_grPionDissCMSNPart_M->SetLineStyle(9);
  Y1S_grPionDissCMSNPart_M->SetLineWidth(2);


  TGraph *Y1S_grCNMEffCMSNPart_M =(TGraph*)file_Y1S->Get("grCNMCMS_M");
  Y1S_grCNMEffCMSNPart_M->SetLineColor(6);
  Y1S_grCNMEffCMSNPart_M->SetLineStyle(6);
  Y1S_grCNMEffCMSNPart_M->SetLineWidth(2);


  TGraph *Y1S_grRegenCMSNPart_M =(TGraph*)file_Y1S->Get("grFormCMS_M");
  Y1S_grRegenCMSNPart_M->SetLineColor(8);
  Y1S_grRegenCMSNPart_M->SetLineStyle(2);
  Y1S_grRegenCMSNPart_M->SetLineWidth(2);


  TGraph *Y1S_grRAACMSNPart_M =(TGraph*)file_Y1S->Get("grRAACMS_M");
  Y1S_grRAACMSNPart_M->SetLineColor(1);
  Y1S_grRAACMSNPart_M->SetLineStyle(1);
  Y1S_grRAACMSNPart_M->SetLineWidth(2);

  


  TGraph *Y1S_grRAACMSNPart_M_V1 =(TGraph*)file_Y1S_V1->Get("grRAACMS_M");
  Y1S_grRAACMSNPart_M_V1->SetLineColor(1);
  Y1S_grRAACMSNPart_M_V1->SetLineStyle(1);
  Y1S_grRAACMSNPart_M_V1->SetLineWidth(2);



  TGraph *Y1S_grRAACMSNPart_M_V2 =(TGraph*)file_Y1S_V2->Get("grRAACMS_M");
  Y1S_grRAACMSNPart_M_V2->SetLineColor(1);
  Y1S_grRAACMSNPart_M_V2->SetLineStyle(1);
  Y1S_grRAACMSNPart_M_V2->SetLineWidth(2);


  TGraph *Y1S_grRAACMSNPart_M_V3 =(TGraph*)file_Y1S_V3->Get("grRAACMS_M");
  Y1S_grRAACMSNPart_M_V3->SetLineColor(1);
  Y1S_grRAACMSNPart_M_V3->SetLineStyle(1);
  Y1S_grRAACMSNPart_M_V3->SetLineWidth(2);

  TGraph *Y1S_grRAACMSNPart_M_V4 =(TGraph*)file_Y1S_V4->Get("grRAACMS_M");
  Y1S_grRAACMSNPart_M_V4->SetLineColor(1);
  Y1S_grRAACMSNPart_M_V4->SetLineStyle(1);
  Y1S_grRAACMSNPart_M_V4->SetLineWidth(2);




  //============== CMS RAA Vs NPart Y1S ====================//
  
  Int_t Y1S_NNNPartCMS = 0;
  Double_t Y1S_NPartCMS[20]={0}; 
  

  Double_t Y1S_RAACMSNPart[20]={0};
  Double_t Y1S_RAAUCMSNPart[20]={0};
  Double_t Y1S_RAALCMSNPart[20]={0};
  
  Y1S_NNNPartCMS=Y1S_grRAACMSNPart_M->GetN();
  cout<<" Y1S NNNPartCMS "<<Y1S_NNNPartCMS<<endl;



 for (int j=0; j < Y1S_grRAACMSNPart_M->GetN();++j){
  
    Double_t NPart, GluonTotal, PionTotal, ShadowTotal, RegenTotal, RAATotal;
    Double_t Y1S_Gluon, Y1S_Pion, Y1S_Shadow, Y1S_Regen,Y1S_Total,Y1S_RAA;
    
    Y1S_grGluonDissCMSNPart_M->GetPoint(j,NPart,Y1S_Gluon);
    Y1S_grPionDissCMSNPart_M->GetPoint(j,NPart,Y1S_Pion);
    Y1S_grCNMEffCMSNPart_M->GetPoint(j,NPart,Y1S_Shadow);
    Y1S_grRegenCMSNPart_M->GetPoint(j,NPart,Y1S_Regen);
    Y1S_grRAACMSNPart_M->GetPoint(j,NPart,Y1S_RAA);
        

    PionTotal = Y1S_Pion;
    ShadowTotal = Y1S_Shadow; 
    GluonTotal = Y1S_Gluon/(PionTotal*ShadowTotal); 
    RegenTotal = Y1S_Regen;
    RAATotal = Y1S_RAA;    

    Y1S_grRAACMSNPart_M->SetPoint(j,NPart,RAATotal);
    Y1S_grGluonDissCMSNPart_M->SetPoint(j,NPart,GluonTotal);  
    Y1S_grPionDissCMSNPart_M->SetPoint(j,NPart,PionTotal);  
    Y1S_grCNMEffCMSNPart_M->SetPoint(j,NPart,ShadowTotal);  
    Y1S_grRegenCMSNPart_M->SetPoint(j,NPart,RegenTotal);
    
 
    Double_t y=0.0;
    Double_t y1=0.0;
    Double_t y2=0.0;
    Double_t y3=0.0;
    Double_t y4=0.0;
    Double_t yMax =0.0;
    Double_t yMin =0.0;
	
    
    Y1S_grRAACMSNPart_M->GetPoint(j,NPart,y);
    Y1S_grRAACMSNPart_M_V1->GetPoint(j,NPart,y1);
    Y1S_grRAACMSNPart_M_V2->GetPoint(j,NPart,y2);
    Y1S_grRAACMSNPart_M_V3->GetPoint(j,NPart,y3);
    Y1S_grRAACMSNPart_M_V4->GetPoint(j,NPart,y4);
    yMax = TMath::Max(TMath::Max(y1,y2),TMath::Max(y3,y4));
    yMin = TMath::Min(TMath::Min(y1,y2),TMath::Min(y3,y4));
    

    Y1S_NPartCMS[j]=NPart;
    Y1S_RAACMSNPart[j] = y;
    Y1S_RAAUCMSNPart[j] = yMax;
    Y1S_RAALCMSNPart[j] = yMin;
    

    // cout<<" Comover "<<PionTotal<<" CNM "<<ShadowTotal<<" Gluon "<<GluonTotal<<"  Regen "<< RegenTotal<<" RAA "<<RAATotal<<endl;
    cout<<NPart<<"   "<<Y1S_RAALCMSNPart[j]<<"   "<<Y1S_RAACMSNPart[j]<<"   "<<Y1S_RAAUCMSNPart[j]<<endl;


 }


 TGraph *Y1S_grRAACMSNPart_M_Shade = new TGraph(2*Y1S_NNNPartCMS);  
 for(Int_t i=0;i<Y1S_NNNPartCMS;i++)
   {
     Y1S_grRAACMSNPart_M_Shade->SetPoint(i,Y1S_NPartCMS[i],Y1S_RAAUCMSNPart[i]);
     Y1S_grRAACMSNPart_M_Shade->SetPoint(Y1S_NNNPartCMS+i,Y1S_NPartCMS[NNNPartCMS-i-1],Y1S_RAALCMSNPart[NNNPartCMS-i-1]);
   }
 
  
 TGraph *Y1S_grRAAUCMSNPart_M = new TGraph(Y1S_NNNPartCMS,Y1S_NPartCMS,Y1S_RAAUCMSNPart); 
 TGraph *Y1S_grRAALCMSNPart_M = new TGraph(Y1S_NNNPartCMS,Y1S_NPartCMS,Y1S_RAALCMSNPart); 
 
 
 Y1S_grRAACMSNPart_M_Shade->GetXaxis()->SetTitle("N_{Part}");
 Y1S_grRAACMSNPart_M_Shade->GetYaxis()->SetTitle("R_{AA}");
 Y1S_grRAACMSNPart_M_Shade->GetYaxis()->SetRangeUser(0.0,1.5);
 Y1S_grRAACMSNPart_M_Shade->SetName("Y1S_grRAACMSNPart_M_Shade");
 Y1S_grRAACMSNPart_M_Shade->SetTitle("Y1S_grRAACMSNPart_M_Shade");
 
 
 new TCanvas;
 gPad->SetTicks();
 
 grShUpsilonVsNPartMid_Shade->SetFillStyle(3013);
 grShUpsilonVsNPartMid_Shade->SetFillColor(46);
 grShUpsilonVsNPartMid_Shade->Draw("Af");
 
 grShUpsilonVsNPartMid->SetLineColor(46);
 grShUpsilonVsNPartMid->Draw("CSame");
 grShUUpsilonVsNPartMid->SetLineColor(46);
 grShUUpsilonVsNPartMid->Draw("lSame");
 grShLUpsilonVsNPartMid->SetLineColor(46);
 grShLUpsilonVsNPartMid->Draw("lSame");
 

 Y1S_grRAACMSNPart_M_Shade->SetFillStyle(3013);    
 Y1S_grRAACMSNPart_M_Shade->SetFillColor(16);  
 Y1S_grRAACMSNPart_M_Shade->Draw("fSame");
 


 TLegend *legd5 = new TLegend(0.18,0.57,0.87,0.93);
 legd5->SetBorderSize(0);
 legd5->SetFillStyle(0);
 legd5->SetFillColor(0);
 legd5->SetTextSize(0.028);


 new TCanvas;
 gPad->SetTicks();
 Draw_CMS_Y1S_RaaVsNpart(legd5);
 legd5->AddEntry(Y1S_grGluonDissCMSNPart_M,"Gluon Dissociation","L");
 legd5->AddEntry(Y1S_grPionDissCMSNPart_M,"Comover","L");
 legd5->AddEntry(Y1S_grCNMEffCMSNPart_M,"CNM Effects","L");
 //legd5->AddEntry(Y1S_grRegenCMSNPart_M,"Formation","L");
 legd5->AddEntry(Y1S_grRAACMSNPart_M,"Total (R_{AA})","L");
 
 Y1S_grRAACMSNPart_M->Draw("Csame");
 Y1S_grGluonDissCMSNPart_M->Draw("Csame");
 Y1S_grPionDissCMSNPart_M->Draw("Csame");
 Y1S_grCNMEffCMSNPart_M->Draw("Csame"); 
 //Y1S_grRegenCMSNPart_M->Draw("Csame");
 
 legd5->Draw("same");



 Y1S_grRAACMSNPart_M_Shade->Draw("fsame");
 Y1S_grRAAUCMSNPart_M->SetLineColor(12);
 Y1S_grRAAUCMSNPart_M->Draw("lsame");
 Y1S_grRAALCMSNPart_M->SetLineColor(12);
 Y1S_grRAALCMSNPart_M->Draw("lsame");

 grShUpsilonVsNPartMid_Shade->Draw("fSame");
 //grShUpsilonVsNPartMid->Draw("CSame");
 grShUUpsilonVsNPartMid->Draw("lSame");
 grShLUpsilonVsNPartMid->Draw("lSame");


 Y1S_grRAACMSNPart_M->Draw("Csame");
 Y1S_grCNMEffCMSNPart_M->Draw("Csame"); 

 gPad->SaveAs("plots/Fig7a_CMS_Y1SRAANPart.eps");
 gPad->SaveAs("plots/Fig7a_CMS_Y1SRAANPart.png");






 //================================ Open Y2S Root File ================================================//
  
 /*
 TFile *file_Y2S;
 if(Var ==0){file_Y2S= new TFile("04032015_Y2SCalculations.root","R");}
 if(Var ==1){file_Y2S = new TFile("SigmaDFac05_Y2SCalculations.root","R");}
 if(Var ==2){file_Y2S = new TFile("SigmaDFac15_Y2SCalculations.root","R");}
 if(Var ==3){file_Y2S = new TFile("Tau001_Y2SCalculations.root","R");}
 if(Var ==4){file_Y2S = new TFile("Tau006_Y2SCalculations.root","R");} 
 */

 TFile *file_Y2S;
 TFile *file_Y2S_V1;
 TFile *file_Y2S_V2;
 TFile *file_Y2S_V3;
 TFile *file_Y2S_V4;
 
 file_Y2S= new TFile("04032015_Y2SCalculations.root","R");
 

 file_Y2S_V1 = new TFile("SigmaDFac05_Y2SCalculations.root","R");
 file_Y2S_V2 = new TFile("SigmaDFac15_Y2SCalculations.root","R");
 file_Y2S_V3 = new TFile("Tau001_Y2SCalculations.root","R");
 file_Y2S_V4 = new TFile("Tau006_Y2SCalculations.root","R"); 



  //============================ CMS RAA Vs NPart Graphs =======================//

 
  TGraph *Y2S_grGluonDissCMSNPart_M =(TGraph*)file_Y2S->Get("grDissCMS_M");
  Y2S_grGluonDissCMSNPart_M->SetLineColor(2);
  Y2S_grGluonDissCMSNPart_M->SetLineStyle(7);
  Y2S_grGluonDissCMSNPart_M->SetLineWidth(2);


  TGraph *Y2S_grPionDissCMSNPart_M =(TGraph*)file_Y2S->Get("grPionDissCMS_M");
  Y2S_grPionDissCMSNPart_M->SetLineColor(4);
  Y2S_grPionDissCMSNPart_M->SetLineStyle(9);
  Y2S_grPionDissCMSNPart_M->SetLineWidth(2);


  TGraph *Y2S_grCNMEffCMSNPart_M =(TGraph*)file_Y2S->Get("grCNMCMS_M");
  Y2S_grCNMEffCMSNPart_M->SetLineColor(6);
  Y2S_grCNMEffCMSNPart_M->SetLineStyle(6);
  Y2S_grCNMEffCMSNPart_M->SetLineWidth(2);


  TGraph *Y2S_grRegenCMSNPart_M =(TGraph*)file_Y2S->Get("grFormCMS_M");
  Y2S_grRegenCMSNPart_M->SetLineColor(8);
  Y2S_grRegenCMSNPart_M->SetLineStyle(2);
  Y2S_grRegenCMSNPart_M->SetLineWidth(2);


  TGraph *Y2S_grRAACMSNPart_M =(TGraph*)file_Y2S->Get("grRAACMS_M");
  Y2S_grRAACMSNPart_M->SetLineColor(1);
  Y2S_grRAACMSNPart_M->SetLineStyle(1);
  Y2S_grRAACMSNPart_M->SetLineWidth(2);

  

  TGraph *Y2S_grRAACMSNPart_M_V1 =(TGraph*)file_Y2S_V1->Get("grRAACMS_M");
  Y2S_grRAACMSNPart_M_V1->SetLineColor(1);
  Y2S_grRAACMSNPart_M_V1->SetLineStyle(1);
  Y2S_grRAACMSNPart_M_V1->SetLineWidth(2);



  TGraph *Y2S_grRAACMSNPart_M_V2 =(TGraph*)file_Y2S_V2->Get("grRAACMS_M");
  Y2S_grRAACMSNPart_M_V2->SetLineColor(1);
  Y2S_grRAACMSNPart_M_V2->SetLineStyle(1);
  Y2S_grRAACMSNPart_M_V2->SetLineWidth(2);


  TGraph *Y2S_grRAACMSNPart_M_V3 =(TGraph*)file_Y2S_V3->Get("grRAACMS_M");
  Y2S_grRAACMSNPart_M_V3->SetLineColor(1);
  Y2S_grRAACMSNPart_M_V3->SetLineStyle(1);
  Y2S_grRAACMSNPart_M_V3->SetLineWidth(2);

  TGraph *Y2S_grRAACMSNPart_M_V4 =(TGraph*)file_Y2S_V4->Get("grRAACMS_M");
  Y2S_grRAACMSNPart_M_V4->SetLineColor(1);
  Y2S_grRAACMSNPart_M_V4->SetLineStyle(1);
  Y2S_grRAACMSNPart_M_V4->SetLineWidth(2);



  //============== CMS RAA Vs NPart Y2S ====================//

  Int_t Y2S_NNNPartCMS = 0;
  Double_t Y2S_NPartCMS[20]={0}; 
  
  
  Double_t Y2S_RAACMSNPart[20]={0};
  Double_t Y2S_RAAUCMSNPart[20]={0};
  Double_t Y2S_RAALCMSNPart[20]={0};
  
  Y2S_NNNPartCMS=Y2S_grRAACMSNPart_M->GetN();
  cout<<" Y2S NNNPartCMS "<<Y2S_NNNPartCMS<<endl;




 for (int j=0; j < Y2S_grRAACMSNPart_M->GetN();++j){
  
    Double_t NPart, GluonTotal, PionTotal, ShadowTotal, RegenTotal, RAATotal;
    Double_t Y2S_Gluon, Y2S_Pion, Y2S_Shadow, Y2S_Regen,Y2S_Total,Y2S_RAA;
    
    Y2S_grGluonDissCMSNPart_M->GetPoint(j,NPart,Y2S_Gluon);
    Y2S_grPionDissCMSNPart_M->GetPoint(j,NPart,Y2S_Pion);
    Y2S_grCNMEffCMSNPart_M->GetPoint(j,NPart,Y2S_Shadow);
    Y2S_grRegenCMSNPart_M->GetPoint(j,NPart,Y2S_Regen);
    Y2S_grRAACMSNPart_M->GetPoint(j,NPart,Y2S_RAA);
        

    PionTotal = Y2S_Pion;
    ShadowTotal = Y2S_Shadow; 
    GluonTotal = Y2S_Gluon/(PionTotal*ShadowTotal); 
    RegenTotal = Y2S_Regen;
    RAATotal = Y2S_RAA;    

    Y2S_grRAACMSNPart_M->SetPoint(j,NPart,RAATotal);
    Y2S_grGluonDissCMSNPart_M->SetPoint(j,NPart,GluonTotal);  
    Y2S_grPionDissCMSNPart_M->SetPoint(j,NPart,PionTotal);  
    Y2S_grCNMEffCMSNPart_M->SetPoint(j,NPart,ShadowTotal);  
    Y2S_grRegenCMSNPart_M->SetPoint(j,NPart,RegenTotal);
  


    Double_t y=0.0;
    Double_t y1=0.0;
    Double_t y2=0.0;
    Double_t y3=0.0;
    Double_t y4=0.0;
    Double_t yMax =0.0;
    Double_t yMin =0.0;
	
    
    Y2S_grRAACMSNPart_M->GetPoint(j,NPart,y);
    Y2S_grRAACMSNPart_M_V1->GetPoint(j,NPart,y1);
    Y2S_grRAACMSNPart_M_V2->GetPoint(j,NPart,y2);
    Y2S_grRAACMSNPart_M_V3->GetPoint(j,NPart,y3);
    Y2S_grRAACMSNPart_M_V4->GetPoint(j,NPart,y4);
    yMax = TMath::Max(TMath::Max(y1,y2),TMath::Max(y3,y4));
    yMin = TMath::Min(TMath::Min(y1,y2),TMath::Min(y3,y4));
    

    Y2S_NPartCMS[j]=NPart;
    Y2S_RAACMSNPart[j] = y;
    Y2S_RAAUCMSNPart[j] = yMax;
    Y2S_RAALCMSNPart[j] = yMin;
    

    // cout<<" Comover "<<PionTotal<<" CNM "<<ShadowTotal<<" Gluon "<<GluonTotal<<"  Regen "<< RegenTotal<<" RAA "<<RAATotal<<endl;
    cout<<NPart<<"   "<<Y2S_RAALCMSNPart[j]<<"   "<<Y2S_RAACMSNPart[j]<<"   "<<Y2S_RAAUCMSNPart[j]<<endl;


  
 }

 

 TGraph *Y2S_grRAACMSNPart_M_Shade = new TGraph(2*Y2S_NNNPartCMS);  
 for(Int_t i=0;i<Y2S_NNNPartCMS;i++)
   {
     Y2S_grRAACMSNPart_M_Shade->SetPoint(i,Y2S_NPartCMS[i],Y2S_RAAUCMSNPart[i]);
     Y2S_grRAACMSNPart_M_Shade->SetPoint(Y2S_NNNPartCMS+i,Y2S_NPartCMS[NNNPartCMS-i-1],Y2S_RAALCMSNPart[NNNPartCMS-i-1]);
   }
 
  
 TGraph *Y2S_grRAAUCMSNPart_M = new TGraph(Y2S_NNNPartCMS,Y2S_NPartCMS,Y2S_RAAUCMSNPart); 
 TGraph *Y2S_grRAALCMSNPart_M = new TGraph(Y2S_NNNPartCMS,Y2S_NPartCMS,Y2S_RAALCMSNPart); 
 
 
 Y2S_grRAACMSNPart_M_Shade->GetXaxis()->SetTitle("N_{Part}");
 Y2S_grRAACMSNPart_M_Shade->GetYaxis()->SetTitle("R_{AA}");
 Y2S_grRAACMSNPart_M_Shade->GetYaxis()->SetRangeUser(0.0,1.5);
 Y2S_grRAACMSNPart_M_Shade->SetName("Y2S_grRAACMSNPart_M_Shade");
 Y2S_grRAACMSNPart_M_Shade->SetTitle("Y2S_grRAACMSNPart_M_Shade");
 
 
 new TCanvas;
 gPad->SetTicks();
 grShUpsilonVsNPartMid_Shade->GetYaxis()->SetRangeUser(0.0,2.2);
 grShUpsilonVsNPartMid_Shade->SetFillStyle(3013);
 grShUpsilonVsNPartMid_Shade->SetFillColor(46);
 grShUpsilonVsNPartMid_Shade->Draw("Af");
 
 grShUpsilonVsNPartMid->SetLineColor(46);
 grShUpsilonVsNPartMid->Draw("CSame");
 
 grShUUpsilonVsNPartMid->SetLineColor(46);
 grShUUpsilonVsNPartMid->Draw("lSame");
 
 grShLUpsilonVsNPartMid->SetLineColor(46);
 grShLUpsilonVsNPartMid->Draw("lSame");
 

 Y2S_grRAACMSNPart_M_Shade->SetFillStyle(3013);    
 Y2S_grRAACMSNPart_M_Shade->SetFillColor(16);  
 Y2S_grRAACMSNPart_M_Shade->Draw("fSame");




 TLegend *legd6 = new TLegend(0.19,0.61,0.87,0.93);
 legd6->SetBorderSize(0);
 legd6->SetFillStyle(0);
 legd6->SetFillColor(0);
 legd6->SetTextSize(0.030);

 new TCanvas;
 gPad->SetTicks();
 Draw_CMS_Y2S_RaaVsNpart(legd6);
 legd6->AddEntry(Y2S_grGluonDissCMSNPart_M,"Gluon Dissociation","L");
 legd6->AddEntry(Y2S_grPionDissCMSNPart_M,"Comover","L");
 legd6->AddEntry(Y2S_grCNMEffCMSNPart_M,"CNM Effects","L");
 //legd6->AddEntry(Y2S_grRegenCMSNPart_M,"Formation","L");
 legd6->AddEntry(Y2S_grRAACMSNPart_M,"Total (R_{AA})","L");
 
 Y2S_grRAACMSNPart_M->Draw("Csame");
 Y2S_grGluonDissCMSNPart_M->Draw("Csame");
 Y2S_grPionDissCMSNPart_M->Draw("Csame");
 Y2S_grCNMEffCMSNPart_M->Draw("Csame"); 
 //Y2S_grRegenCMSNPart_M->Draw("Csame");
 
 legd6->Draw("same");




 Y2S_grRAACMSNPart_M_Shade->Draw("fsame");
 Y2S_grRAAUCMSNPart_M->SetLineColor(12);
 Y2S_grRAAUCMSNPart_M->Draw("lsame");
 Y2S_grRAALCMSNPart_M->SetLineColor(12);
 Y2S_grRAALCMSNPart_M->Draw("lsame");

 grShUpsilonVsNPartMid_Shade->Draw("fSame");
 //grShUpsilonVsNPartMid->Draw("CSame");
 grShUUpsilonVsNPartMid->Draw("lSame");
 grShLUpsilonVsNPartMid->Draw("lSame");


 Y2S_grRAACMSNPart_M->Draw("Csame");
 Y2S_grCNMEffCMSNPart_M->Draw("Csame");





 gPad->SaveAs("plots/Fig7b_CMS_Y2SRAANPart.eps");
 gPad->SaveAs("plots/Fig7b_CMS_Y2SRAANPart.png");





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
  grRaaPtCMS->GetYaxis()->SetRangeUser(0,2.2);
  grRaaPtCMS->GetXaxis()->SetTitle("p_{T}(GeV/c)");
  grRaaPtCMS->GetYaxis()->SetTitle("R_{AA}");
  
  TAxis *XaxisgrRaaPtCMS = grRaaPtCMS->GetXaxis();
  XaxisgrRaaPtCMS->SetLimits(0.0,20.0);


  TLine *lh5 = new TLine(0.0,1.0,20.0,1.0);
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
  CMSGlobalSysJPsiPt = new TBox(17.0-0.5, 1 - 0.075, 17.0+0.5, 1 + 0.075);
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

  grRaaPtALICEFor->GetYaxis()->SetRangeUser(0,2.2);
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

  grRaaPtALICEFor->GetYaxis()->SetRangeUser(0,2.2);
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
  grRaaRapCMS->GetYaxis()->SetRangeUser(0,2.2);
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
  grRaaCMS->GetYaxis()->SetRangeUser(0,2.2);
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
  //Double_t RaaALICE[10] = {0.47,0.48,0.51,0.51,0.52,0.61,0.70,0.74,0.94};

  Double_t StatErrALICE[10] = {0.02,0.02,0.02,0.02,0.03,0.04,0.04,0.06,0.10};
  Double_t SystErrALICE[10] = {0.02,0.02,0.02,0.03,0.03,0.04,0.06,0.07,0.1};
  
  TGraphErrors *grRaaALICE = new TGraphErrors(nbinsALICE, NPartALICE, RaaALICE, ErrNPartALICE, StatErrALICE);  
  grRaaALICE->SetMarkerStyle(20);
  grRaaALICE->SetMarkerColor(4);
  grRaaALICE->GetYaxis()->SetRangeUser(0,2.2);
  
  TAxis *Xaxis2 = grRaaALICE->GetXaxis();
  Xaxis2->SetLimits(0.0,400.0);
  
  grRaaALICE->GetXaxis()->SetTitle("N_{Part}");
  grRaaALICE->GetYaxis()->SetTitle("R_{AA}");

  grRaaALICE->Draw("AP");
 
  TLine *lh3 = new TLine(0.0,1.0,380,1.0);
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
  ALICEGlobalSysJPsi = new TBox(370-5, 1 - 0.14, 370+5, 1 + 0.14);
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
  grRaaALICEMid->SetMarkerStyle(21);
  grRaaALICEMid->SetMarkerColor(2);
  grRaaALICEMid->GetYaxis()->SetRangeUser(0,2.2);
  
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
  
  TLine *lh3 = new TLine(0.0,1.0,400,1.0);
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
  RaaYCMS1Sdata->GetYaxis()->SetRangeUser(0.0,2.2);
  RaaYCMS1Sdata->GetXaxis()->CenterTitle();
  RaaYCMS1Sdata->GetXaxis()->SetTitle("N_{part}");
  RaaYCMS1Sdata->GetYaxis()->SetTitle("R_{AA}");
  RaaYCMS1Sdata->Draw("AP");
  
  
  TBox *RaaCMS1SSys[10];
  for(int j=0;j<7;j++){
    RaaCMS1SSys[j] = new TBox(NPartCMSD[j]-4,RaaCMS1Sdata[j]-ErSysRaaCMS1Sdata[j],NPartCMSD[j]+4,RaaCMS1Sdata[j]+ErSysRaaCMS1Sdata[j]);
  }
  
  for(int j=0;j<7;j++){
    RaaCMS1SSys[j]->SetFillStyle(0000);
    //RaaCMS1SSys[j]->SetFillStyle(3001);
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
  //tb->DrawLatex(0.21,0.30,"PbPb #sqrt{s_{NN}} = 2.76 TeV");
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
  RaaYCMS2Sdata->GetYaxis()->SetRangeUser(0.0,2.2);
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
  RaaYALICE1Sdata->GetYaxis()->SetRangeUser(0.0,2.2);
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

