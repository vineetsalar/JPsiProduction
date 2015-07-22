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

Double_t Npart(int BinLow, int BinHigh);
Double_t NColl(int BinLow, int BinHigh);

void Draw_AllDataGraphs();

void Draw_CMS_Y1S_RaaVspT(TLegend *lgd);
void Draw_CMS_Y2S_RaaVspT(TLegend *lgd);

void Draw_CMS_Y1S_RaaVsRap(TLegend *lgd);
void Draw_CMS_Y2S_RaaVsRap(TLegend *lgd);



void Plot_PaperFigures_NF_Band_UpsilonPt()
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
  


  TFile *file_Shadowing =  new TFile("22072015_InRootFiles/YPt_ShawQuarkonia.root","R");
   
  TGraph *grShUpsilonVsPtCMS_Shade =(TGraph*)file_Shadowing->Get("grShUpsilonVsPt_Y21_Shade");
  TGraph *grShUpsilonVsPtCMS =(TGraph*)file_Shadowing->Get("grShUpsilonVsPt_Y21");
  TGraph *grShUUpsilonVsPtCMS =(TGraph*)file_Shadowing->Get("grShUUpsilonVsPt_Y21");
  TGraph *grShLUpsilonVsPtCMS =(TGraph*)file_Shadowing->Get("grShLUpsilonVsPt_Y21");



   TFile *file_Upsilon1S = new TFile("22072015_InRootFiles/22072015_Y1SCalculations_PtTest.root","R");
   TFile *file_Upsilon1S_V1 = new TFile("22072015_InRootFiles/22072015_Tau001_Y1SCalculations_PtTest.root","R");
   TFile *file_Upsilon1S_V2 = new TFile("22072015_InRootFiles/22072015_Tau006_Y1SCalculations_PtTest.root","R");
   TFile *file_Upsilon1S_V3= new TFile("22072015_InRootFiles/22072015_Fac005_Y1SCalculations_PtTest.root","R");
   TFile *file_Upsilon1S_V4 = new TFile("22072015_InRootFiles/22072015_Fac015_Y1SCalculations_PtTest.root","R");




 //============================ CMS RAA Vs Pt Graphs =======================//
  TGraph *Upsilon1S_grGluonDissCMSPt_M =(TGraph*)file_Upsilon1S->Get("grGluonDissCMSPt_M");
  Upsilon1S_grGluonDissCMSPt_M->SetLineColor(2);
  Upsilon1S_grGluonDissCMSPt_M->SetLineStyle(7);
  Upsilon1S_grGluonDissCMSPt_M->SetLineWidth(2);


  TGraph *Upsilon1S_grPionDissCMSPt_M =(TGraph*)file_Upsilon1S->Get("grPionDissCMSPt_M");
  Upsilon1S_grPionDissCMSPt_M->SetLineColor(4);
  Upsilon1S_grPionDissCMSPt_M->SetLineStyle(9);
  Upsilon1S_grPionDissCMSPt_M->SetLineWidth(2);


  TGraph *Upsilon1S_grCNMEffCMSPt_M =(TGraph*)file_Upsilon1S->Get("grShadowDissCMSPt_M");
  Upsilon1S_grCNMEffCMSPt_M->SetLineColor(6);
  Upsilon1S_grCNMEffCMSPt_M->SetLineStyle(6);
  Upsilon1S_grCNMEffCMSPt_M->SetLineWidth(2);


  TGraph *Upsilon1S_grRegenCMSPt_M =(TGraph*)file_Upsilon1S->Get("grRegenCMSPt_M");
  Upsilon1S_grRegenCMSPt_M->SetLineColor(8);
  Upsilon1S_grRegenCMSPt_M->SetLineStyle(2);
  Upsilon1S_grRegenCMSPt_M->SetLineWidth(2);

  
  TGraph *Upsilon1S_grRAACMSPt_M =(TGraph*)file_Upsilon1S->Get("grRAACMSPt_M");
  Upsilon1S_grRAACMSPt_M->SetLineColor(1);
  Upsilon1S_grRAACMSPt_M->SetLineStyle(1);
  Upsilon1S_grRAACMSPt_M->SetLineWidth(2);


  TGraph *Upsilon1S_grRAACMSPt_M_V1 =(TGraph*)file_Upsilon1S_V1->Get("grRAACMSPt_M");
  Upsilon1S_grRAACMSPt_M_V1->SetLineColor(1);
  Upsilon1S_grRAACMSPt_M_V1->SetLineStyle(1);
  Upsilon1S_grRAACMSPt_M_V1->SetLineWidth(2);

  
  TGraph *Upsilon1S_grRAACMSPt_M_V2 =(TGraph*)file_Upsilon1S_V2->Get("grRAACMSPt_M");
  Upsilon1S_grRAACMSPt_M_V2->SetLineColor(1);
  Upsilon1S_grRAACMSPt_M_V2->SetLineStyle(1);
  Upsilon1S_grRAACMSPt_M_V2->SetLineWidth(2);
  
  
  TGraph *Upsilon1S_grRAACMSPt_M_V3 =(TGraph*)file_Upsilon1S_V3->Get("grRAACMSPt_M");
  Upsilon1S_grRAACMSPt_M_V3->SetLineColor(1);
  Upsilon1S_grRAACMSPt_M_V3->SetLineStyle(1);
  Upsilon1S_grRAACMSPt_M_V3->SetLineWidth(2);

  
  TGraph *Upsilon1S_grRAACMSPt_M_V4 =(TGraph*)file_Upsilon1S_V4->Get("grRAACMSPt_M");
  Upsilon1S_grRAACMSPt_M_V4->SetLineColor(1);
  Upsilon1S_grRAACMSPt_M_V4->SetLineStyle(1);
  Upsilon1S_grRAACMSPt_M_V4->SetLineWidth(2);



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


  //================== RAA CMS Vs pT ========================================//    

    Int_t NNPtCMS = 40;
    Double_t PtCMS[100]= {0.25,0.75,1.25,1.75,2.25,2.75,3.25,3.75,4.25,4.75,5.25,5.75,6.25,6.75,7.25,7.75,8.25,8.75,
			  9.25,9.75,10.25,10.75,11.25,11.75,12.25,12.75,13.25,13.75,14.25,14.75,15.25,15.75,16.25,
			  16.75,17.25,17.75,18.25,18.75,19.25,19.75,20.25,20.75,21.25,21.75,22.25,22.75,23.25,23.75,
			  24.25,24.75,25.25,25.75,26.25,26.75,27.25,27.75,28.25,28.75,29.25,29.75,30.25,30.75};

    Double_t RAACMSPt[100];
    Double_t RAAUCMSPt[100];
    Double_t RAALCMSPt[100];

    for (int j=0; j < Upsilon1S_grRAACMSPt_M->GetN();++j){
      
      Double_t Pt, GluonTotal, PionTotal, ShadowTotal, RegenTotal, RAATotal;
      Double_t Upsilon1S_Gluon, Upsilon1S_Pion, Upsilon1S_Shadow, Upsilon1S_Regen,Upsilon1S_Total;
      
      Upsilon1S_grGluonDissCMSPt_M->GetPoint(j,Pt,Upsilon1S_Gluon);
      Upsilon1S_grPionDissCMSPt_M->GetPoint(j,Pt,Upsilon1S_Pion);
      Upsilon1S_grCNMEffCMSPt_M->GetPoint(j,Pt,Upsilon1S_Shadow);
      Upsilon1S_grRegenCMSPt_M->GetPoint(j,Pt,Upsilon1S_Regen);
      Upsilon1S_grRAACMSPt_M->GetPoint(j,Pt,Upsilon1S_Total);
      
      RAATotal = Upsilon1S_Total;
      GluonTotal = Upsilon1S_Gluon;
      PionTotal = Upsilon1S_Pion; 
      ShadowTotal = Upsilon1S_Shadow;
      RegenTotal = Upsilon1S_Regen;
      
      Upsilon1S_grRAACMSPt_M->SetPoint(j,Pt,RAATotal);
      Upsilon1S_grGluonDissCMSPt_M->SetPoint(j,Pt,GluonTotal);  
      Upsilon1S_grPionDissCMSPt_M->SetPoint(j,Pt,PionTotal);  
      Upsilon1S_grCNMEffCMSPt_M->SetPoint(j,Pt,ShadowTotal);  
      Upsilon1S_grRegenCMSPt_M->SetPoint(j,Pt,RegenTotal);
    
    
      Double_t y=0.0;
      Double_t y1=0.0;
      Double_t y2=0.0;
      Double_t y3=0.0;
      Double_t y4=0.0;
      Double_t yMax =0.0;
      Double_t yMin =0.0;

      Upsilon1S_grRAACMSPt_M->GetPoint(j,Pt,y);
      Upsilon1S_grRAACMSPt_M_V1->GetPoint(j,Pt,y1);
      Upsilon1S_grRAACMSPt_M_V2->GetPoint(j,Pt,y2);
      Upsilon1S_grRAACMSPt_M_V3->GetPoint(j,Pt,y3);
      Upsilon1S_grRAACMSPt_M_V4->GetPoint(j,Pt,y4);
      
      yMax = y + TMath::Sqrt( (TMath::Max(y1,y2)-y)*(TMath::Max(y1,y2)-y) + (TMath::Max(y3,y4)-y)*(TMath::Max(y3,y4)-y) );
      yMin = y - TMath::Sqrt( (TMath::Min(y1,y2)-y)*(TMath::Min(y1,y2)-y) + (TMath::Min(y3,y4)-y)*(TMath::Min(y3,y4)-y) );    


      RAACMSPt[j] = y;
      RAAUCMSPt[j] = yMax;
      RAALCMSPt[j] = yMin;
    

      }
    
      TGraph *Upsilon1S_grRAACMSPt_M_Shade = new TGraph(2*NNPtCMS);  
      for(Int_t i=0;i<NNPtCMS;i++)
	{
	  Upsilon1S_grRAACMSPt_M_Shade->SetPoint(i,PtCMS[i],RAAUCMSPt[i]);
	  Upsilon1S_grRAACMSPt_M_Shade->SetPoint(NNPtCMS+i,PtCMS[NNPtCMS-i-1],RAALCMSPt[NNPtCMS-i-1]);
	}
      
  
      TGraph *Upsilon1S_grRAAUCMSPt_M = new TGraph(NNPtCMS,PtCMS,RAAUCMSPt); 
      TGraph *Upsilon1S_grRAALCMSPt_M = new TGraph(NNPtCMS,PtCMS,RAALCMSPt); 
      
  
      Upsilon1S_grRAACMSPt_M_Shade->GetXaxis()->SetTitle("p_{T}(GeV/c)");
      Upsilon1S_grRAACMSPt_M_Shade->GetYaxis()->SetTitle("R_{AA}");
      Upsilon1S_grRAACMSPt_M_Shade->GetYaxis()->SetRangeUser(0.0,1.5);
      Upsilon1S_grRAACMSPt_M_Shade->SetName("Upsilon1S_grRAACMSPt_M_Shade");
      Upsilon1S_grRAACMSPt_M_Shade->SetTitle("Upsilon1S_grRAACMSPt_M_Shade");
    

      grShUpsilonVsPtCMS_Shade->SetFillStyle(3004);
      grShUpsilonVsPtCMS_Shade->SetFillColor(46);

      Upsilon1S_grRAACMSPt_M_Shade->SetFillStyle(3013);    
      Upsilon1S_grRAACMSPt_M_Shade->SetFillColor(16);  


      TLegend *legd2 = new TLegend(0.18,0.60,0.93,0.94);
      legd2->SetBorderSize(0);
      legd2->SetFillStyle(0);
      legd2->SetFillColor(0);
      legd2->SetTextSize(0.040);
 
      new TCanvas;
      gPad->SetTicks();
      gPad->SetBottomMargin(0.14);
      gPad->SetLeftMargin(0.14);
      
      Draw_CMS_Y1S_RaaVspT(legd2);  
      
      legd2->AddEntry(Upsilon1S_grGluonDissCMSPt_M,"Gluon Dissociation","L");
      legd2->AddEntry(Upsilon1S_grPionDissCMSPt_M,"Comover","L");
      legd2->AddEntry(Upsilon1S_grCNMEffCMSPt_M,"CNM Effects","L");
      legd2->AddEntry(Upsilon1S_grRegenCMSPt_M,"Formation","L");
      legd2->AddEntry(Upsilon1S_grRAACMSPt_M,"Total (R_{AA})","L");
      
      Upsilon1S_grRAACMSPt_M->SetLineWidth(3);
      Upsilon1S_grGluonDissCMSPt_M->SetLineWidth(3);
      Upsilon1S_grPionDissCMSPt_M->SetLineWidth(3);
      Upsilon1S_grRegenCMSPt_M->SetLineWidth(3);
      Upsilon1S_grCNMEffCMSPt_M->SetLineWidth(3);
      


      Upsilon1S_grRAACMSPt_M->Draw("Csame");
      Upsilon1S_grGluonDissCMSPt_M->Draw("Csame");
      Upsilon1S_grPionDissCMSPt_M->Draw("Csame");
      Upsilon1S_grRegenCMSPt_M->Draw("Csame");
      Upsilon1S_grCNMEffCMSPt_M->Draw("Csame");
      
      legd2->Draw("same");
      tb->DrawLatex(0.86,0.91,"(a)");
  
      Upsilon1S_grRAACMSPt_M_Shade->Draw("fCsame");
      Upsilon1S_grRAAUCMSPt_M->SetLineColor(12);
      Upsilon1S_grRAAUCMSPt_M->Draw("Csame");
      Upsilon1S_grRAALCMSPt_M->SetLineColor(12);
      Upsilon1S_grRAALCMSPt_M->Draw("Csame");
      
      grShUpsilonVsPtCMS_Shade->Draw("fCsame");
      grShUUpsilonVsPtCMS->SetLineColor(46);
      grShUUpsilonVsPtCMS->Draw("CSame");
      grShLUpsilonVsPtCMS->SetLineColor(46);
      grShLUpsilonVsPtCMS->Draw("CSame");
      
      Upsilon1S_grRAACMSPt_M->Draw("Csame");
      Upsilon1S_grCNMEffCMSPt_M->Draw("Csame");

      gPad->SaveAs("plots/Fig9a_CMS_Y1SRAAPt.eps");
      gPad->SaveAs("plots/Fig9a_CMS_Y1SRAAPt.png");
      gPad->SaveAs("plots/Fig9a_CMS_Y1SRAAPt.pdf");
      
 


      //============================================================ Y2S =======================================================//



      TFile *file_Upsilon2S = new TFile("22072015_InRootFiles/22072015_Y2SCalculations_PtTest.root","R");
      TFile *file_Upsilon2S_V1 = new TFile("22072015_InRootFiles/22072015_Tau001_Y2SCalculations_PtTest.root","R");
      TFile *file_Upsilon2S_V2 = new TFile("22072015_InRootFiles/22072015_Tau006_Y2SCalculations_PtTest.root","R");
      TFile *file_Upsilon2S_V3= new TFile("22072015_InRootFiles/22072015_Fac05_Y2SCalculations_PtTest.root","R");
      TFile *file_Upsilon2S_V4 = new TFile("22072015_InRootFiles/22072015_Fac15_Y2SCalculations_PtTest.root","R");




      //============================ CMS RAA Vs Pt Graphs =======================//
      TGraph *Upsilon2S_grGluonDissCMSPt_M =(TGraph*)file_Upsilon2S->Get("grGluonDissCMSPt_M");
      Upsilon2S_grGluonDissCMSPt_M->SetLineColor(2);
      Upsilon2S_grGluonDissCMSPt_M->SetLineStyle(7);
  Upsilon2S_grGluonDissCMSPt_M->SetLineWidth(2);


  TGraph *Upsilon2S_grPionDissCMSPt_M =(TGraph*)file_Upsilon2S->Get("grPionDissCMSPt_M");
  Upsilon2S_grPionDissCMSPt_M->SetLineColor(4);
  Upsilon2S_grPionDissCMSPt_M->SetLineStyle(9);
  Upsilon2S_grPionDissCMSPt_M->SetLineWidth(2);


  TGraph *Upsilon2S_grCNMEffCMSPt_M =(TGraph*)file_Upsilon2S->Get("grShadowDissCMSPt_M");
  Upsilon2S_grCNMEffCMSPt_M->SetLineColor(6);
  Upsilon2S_grCNMEffCMSPt_M->SetLineStyle(6);
  Upsilon2S_grCNMEffCMSPt_M->SetLineWidth(2);


  TGraph *Upsilon2S_grRegenCMSPt_M =(TGraph*)file_Upsilon2S->Get("grRegenCMSPt_M");
  Upsilon2S_grRegenCMSPt_M->SetLineColor(8);
  Upsilon2S_grRegenCMSPt_M->SetLineStyle(2);
  Upsilon2S_grRegenCMSPt_M->SetLineWidth(2);

  
  TGraph *Upsilon2S_grRAACMSPt_M =(TGraph*)file_Upsilon2S->Get("grRAACMSPt_M");
  Upsilon2S_grRAACMSPt_M->SetLineColor(1);
  Upsilon2S_grRAACMSPt_M->SetLineStyle(1);
  Upsilon2S_grRAACMSPt_M->SetLineWidth(2);


  TGraph *Upsilon2S_grRAACMSPt_M_V1 =(TGraph*)file_Upsilon2S_V1->Get("grRAACMSPt_M");
  Upsilon2S_grRAACMSPt_M_V1->SetLineColor(1);
  Upsilon2S_grRAACMSPt_M_V1->SetLineStyle(1);
  Upsilon2S_grRAACMSPt_M_V1->SetLineWidth(2);

  
  TGraph *Upsilon2S_grRAACMSPt_M_V2 =(TGraph*)file_Upsilon2S_V2->Get("grRAACMSPt_M");
  Upsilon2S_grRAACMSPt_M_V2->SetLineColor(1);
  Upsilon2S_grRAACMSPt_M_V2->SetLineStyle(1);
  Upsilon2S_grRAACMSPt_M_V2->SetLineWidth(2);
  
  
  TGraph *Upsilon2S_grRAACMSPt_M_V3 =(TGraph*)file_Upsilon2S_V3->Get("grRAACMSPt_M");
  Upsilon2S_grRAACMSPt_M_V3->SetLineColor(1);
  Upsilon2S_grRAACMSPt_M_V3->SetLineStyle(1);
  Upsilon2S_grRAACMSPt_M_V3->SetLineWidth(2);

  
  TGraph *Upsilon2S_grRAACMSPt_M_V4 =(TGraph*)file_Upsilon2S_V4->Get("grRAACMSPt_M");
  Upsilon2S_grRAACMSPt_M_V4->SetLineColor(1);
  Upsilon2S_grRAACMSPt_M_V4->SetLineStyle(1);
  Upsilon2S_grRAACMSPt_M_V4->SetLineWidth(2);



  //================== RAA CMS Vs pT ========================================//    


  //Int_t NNPtCMS = 40;
  //Double_t PtCMS[100]= {0.25,0.75,1.25,1.75,2.25,2.75,3.25,3.75,4.25,4.75,5.25,5.75,6.25,6.75,7.25,7.75,8.25,8.75,
  //			  9.25,9.75,10.25,10.75,11.25,11.75,12.25,12.75,13.25,13.75,14.25,14.75,15.25,15.75,16.25,
  //			  16.75,17.25,17.75,18.25,18.75,19.25,19.75,20.25,20.75,21.25,21.75,22.25,22.75,23.25,23.75,
  //			  24.25,24.75,25.25,25.75,26.25,26.75,27.25,27.75,28.25,28.75,29.25,29.75,30.25,30.75};

  //Double_t RAACMSPt[100];
  //Double_t RAAUCMSPt[100];
  //Double_t RAALCMSPt[100];


    for (int j=0; j < Upsilon2S_grRAACMSPt_M->GetN();++j){
      
      Double_t Pt, GluonTotal, PionTotal, ShadowTotal, RegenTotal, RAATotal;
      Double_t Upsilon2S_Gluon, Upsilon2S_Pion, Upsilon2S_Shadow, Upsilon2S_Regen,Upsilon2S_Total;
      
      Upsilon2S_grGluonDissCMSPt_M->GetPoint(j,Pt,Upsilon2S_Gluon);
      Upsilon2S_grPionDissCMSPt_M->GetPoint(j,Pt,Upsilon2S_Pion);
      Upsilon2S_grCNMEffCMSPt_M->GetPoint(j,Pt,Upsilon2S_Shadow);
      Upsilon2S_grRegenCMSPt_M->GetPoint(j,Pt,Upsilon2S_Regen);
      Upsilon2S_grRAACMSPt_M->GetPoint(j,Pt,Upsilon2S_Total);
      
      RAATotal = Upsilon2S_Total;
      GluonTotal = Upsilon2S_Gluon;
      PionTotal = Upsilon2S_Pion; 
      ShadowTotal = Upsilon2S_Shadow;
      RegenTotal = Upsilon2S_Regen;
      
      Upsilon2S_grRAACMSPt_M->SetPoint(j,Pt,RAATotal);
      Upsilon2S_grGluonDissCMSPt_M->SetPoint(j,Pt,GluonTotal);  
      Upsilon2S_grPionDissCMSPt_M->SetPoint(j,Pt,PionTotal);  
      Upsilon2S_grCNMEffCMSPt_M->SetPoint(j,Pt,ShadowTotal);  
      Upsilon2S_grRegenCMSPt_M->SetPoint(j,Pt,RegenTotal);
    
    
      Double_t y=0.0;
      Double_t y1=0.0;
      Double_t y2=0.0;
      Double_t y3=0.0;
      Double_t y4=0.0;
      Double_t yMax =0.0;
      Double_t yMin =0.0;

      Upsilon2S_grRAACMSPt_M->GetPoint(j,Pt,y);
      Upsilon2S_grRAACMSPt_M_V1->GetPoint(j,Pt,y1);
      Upsilon2S_grRAACMSPt_M_V2->GetPoint(j,Pt,y2);
      Upsilon2S_grRAACMSPt_M_V3->GetPoint(j,Pt,y3);
      Upsilon2S_grRAACMSPt_M_V4->GetPoint(j,Pt,y4);
      
      yMax = y + TMath::Sqrt( (TMath::Max(y1,y2)-y)*(TMath::Max(y1,y2)-y) + (TMath::Max(y3,y4)-y)*(TMath::Max(y3,y4)-y) );
      yMin = y - TMath::Sqrt( (TMath::Min(y1,y2)-y)*(TMath::Min(y1,y2)-y) + (TMath::Min(y3,y4)-y)*(TMath::Min(y3,y4)-y) );    


      RAACMSPt[j] = y;
      RAAUCMSPt[j] = yMax;
      RAALCMSPt[j] = yMin;
    

      }
    
      TGraph *Upsilon2S_grRAACMSPt_M_Shade = new TGraph(2*NNPtCMS);  
      for(Int_t i=0;i<NNPtCMS;i++)
	{
	  Upsilon2S_grRAACMSPt_M_Shade->SetPoint(i,PtCMS[i],RAAUCMSPt[i]);
	  Upsilon2S_grRAACMSPt_M_Shade->SetPoint(NNPtCMS+i,PtCMS[NNPtCMS-i-1],RAALCMSPt[NNPtCMS-i-1]);
	}
      
  
      TGraph *Upsilon2S_grRAAUCMSPt_M = new TGraph(NNPtCMS,PtCMS,RAAUCMSPt); 
      TGraph *Upsilon2S_grRAALCMSPt_M = new TGraph(NNPtCMS,PtCMS,RAALCMSPt); 
      
  
      Upsilon2S_grRAACMSPt_M_Shade->GetXaxis()->SetTitle("p_{T}(GeV/c)");
      Upsilon2S_grRAACMSPt_M_Shade->GetYaxis()->SetTitle("R_{AA}");
      Upsilon2S_grRAACMSPt_M_Shade->GetYaxis()->SetRangeUser(0.0,1.5);
      Upsilon2S_grRAACMSPt_M_Shade->SetName("Upsilon2S_grRAACMSPt_M_Shade");
      Upsilon2S_grRAACMSPt_M_Shade->SetTitle("Upsilon2S_grRAACMSPt_M_Shade");
    

      grShUpsilonVsPtCMS_Shade->SetFillStyle(3004);
      grShUpsilonVsPtCMS_Shade->SetFillColor(46);

      Upsilon2S_grRAACMSPt_M_Shade->SetFillStyle(3013);    
      Upsilon2S_grRAACMSPt_M_Shade->SetFillColor(16);  


      TLegend *legd3 = new TLegend(0.18,0.60,0.93,0.94);
      legd3->SetBorderSize(0);
      legd3->SetFillStyle(0);
      legd3->SetFillColor(0);
      legd3->SetTextSize(0.040);
 
      new TCanvas;
      gPad->SetTicks();
      gPad->SetBottomMargin(0.14);
      gPad->SetLeftMargin(0.14);
      
      Draw_CMS_Y2S_RaaVspT(legd3);  
      
      legd3->AddEntry(Upsilon2S_grGluonDissCMSPt_M,"Gluon Dissociation","L");
      legd3->AddEntry(Upsilon2S_grPionDissCMSPt_M,"Comover","L");
      legd3->AddEntry(Upsilon2S_grCNMEffCMSPt_M,"CNM Effects","L");
      legd3->AddEntry(Upsilon2S_grRegenCMSPt_M,"Formation","L");
      legd3->AddEntry(Upsilon2S_grRAACMSPt_M,"Total (R_{AA})","L");
      
      Upsilon2S_grRAACMSPt_M->SetLineWidth(3);
      Upsilon2S_grGluonDissCMSPt_M->SetLineWidth(3);
      Upsilon2S_grPionDissCMSPt_M->SetLineWidth(3);
      Upsilon2S_grRegenCMSPt_M->SetLineWidth(3);
      Upsilon2S_grCNMEffCMSPt_M->SetLineWidth(3);
      


      Upsilon2S_grRAACMSPt_M->Draw("Csame");
      Upsilon2S_grGluonDissCMSPt_M->Draw("Csame");
      Upsilon2S_grPionDissCMSPt_M->Draw("Csame");
      Upsilon2S_grRegenCMSPt_M->Draw("Csame");
      Upsilon2S_grCNMEffCMSPt_M->Draw("Csame");
      
      legd3->Draw("same");
      tb->DrawLatex(0.86,0.91,"(b)");
  
      Upsilon2S_grRAACMSPt_M_Shade->Draw("fCsame");
      Upsilon2S_grRAAUCMSPt_M->SetLineColor(12);
      Upsilon2S_grRAAUCMSPt_M->Draw("Csame");
      Upsilon2S_grRAALCMSPt_M->SetLineColor(12);
      Upsilon2S_grRAALCMSPt_M->Draw("Csame");
      
      grShUpsilonVsPtCMS_Shade->Draw("fCsame");
      grShUUpsilonVsPtCMS->SetLineColor(46);
      grShUUpsilonVsPtCMS->Draw("CSame");
      grShLUpsilonVsPtCMS->SetLineColor(46);
      grShLUpsilonVsPtCMS->Draw("CSame");
      
      Upsilon2S_grRAACMSPt_M->Draw("Csame");
      Upsilon2S_grCNMEffCMSPt_M->Draw("Csame");

      gPad->SaveAs("plots/Fig9b_CMS_Y2SRAAPt.eps");
      gPad->SaveAs("plots/Fig9b_CMS_Y2SRAAPt.png");
      gPad->SaveAs("plots/Fig9b_CMS_Y2SRAAPt.pdf");
      




 








} 











void Draw_AllDataGraphs()
{
 
  TLegend *legend_ratio = new TLegend(0.1677852,0.72,0.83,0.90);
  legend_ratio->SetBorderSize(0);
  legend_ratio->SetFillStyle(0);
  legend_ratio->SetFillColor(0);
  legend_ratio->SetTextSize(0.04);


  new TCanvas;
  gPad->SetTickx();
  gPad->SetTicky();
  Draw_CMS_Y1S_RaaVspT(legend_ratio);
  legend_ratio->Draw("same");



  new TCanvas;
  gPad->SetTickx();
  gPad->SetTicky();
  Draw_CMS_Y2S_RaaVspT(legend_ratio);
  legend_ratio->Draw("same");




  new TCanvas;
  gPad->SetTickx();
  gPad->SetTicky();
  Draw_CMS_Y1S_RaaVsRap(legend_ratio);
  legend_ratio->Draw("same");



  new TCanvas;
  gPad->SetTickx();
  gPad->SetTicky();
  Draw_CMS_Y2S_RaaVsRap(legend_ratio);
  legend_ratio->Draw("same");

  return;


}




void Draw_CMS_Y1S_RaaVspT(TLegend *lgd)
{

  //================= CMS Y1S Raa Vs Pt ===================================//
  const int nbinsPt=5;

  Double_t PtCMS[nbinsPt]={1.25,3.75,6.5,10.0,16.0};
  Double_t ErrPtCMS[nbinsPt]={0};
  
  Double_t RaaPtCMS[nbinsPt] = {0.42,0.404,0.444,0.473,0.429}; 
  Double_t RaaPtStatErrCMS[nbinsPt] = {0.028,0.0283,0.0333,0.0417,0.0477};
  Double_t RaaPtSystErrCMS[nbinsPt] = {0.0636,0.0508,0.0722,0.051,0.0432};

  
  TGraphErrors *grRaaPtCMS = new TGraphErrors(nbinsPt, PtCMS, RaaPtCMS, ErrPtCMS, RaaPtStatErrCMS);  
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
  
  TBox *RaaPtCMSSys[nbinsPt];
  for(int j=0;j<nbinsPt;j++){
    RaaPtCMSSys[j] = new TBox(PtCMS[j]-0.5,  RaaPtCMS[j]-RaaPtSystErrCMS[j], PtCMS[j]+0.5,  RaaPtCMS[j]+RaaPtSystErrCMS[j]);
  }
  
  for(int j=0;j<nbinsPt;j++){
    RaaPtCMSSys[j]->SetFillStyle(0000);
    RaaPtCMSSys[j]->SetLineColor(4);
    RaaPtCMSSys[j]->Draw("same"); 
  }
    
  TBox *CMSGlobalSysPt;
  CMSGlobalSysPt = new TBox(18-0.2, 1 - 0.083, 18+0.2, 1 + 0.083);
  CMSGlobalSysPt->SetFillStyle(3001);
  CMSGlobalSysPt->SetLineColor(4);
  CMSGlobalSysPt->SetFillColor(4);
  //CMSGlobalSysPt->Draw("same"); 
    
  lgd->AddEntry(grRaaPtCMS,"CMS Data", "P");  

  }




void Draw_CMS_Y2S_RaaVspT(TLegend *lgd)
{

  //================= CMS Y2S Raa Vs Pt ===================================//
  const int nbinsPt=3;

  Double_t PtCMS[nbinsPt]={2.5,8.5,16.0};
  Double_t ErrPtCMS[nbinsPt]={0};
  
  Double_t RaaPtCMS[nbinsPt] = {0.0821,0.0656,0.141}; 
  Double_t RaaPtStatErrCMS[nbinsPt] = {0.0471,0.0457,0.0585};
  Double_t RaaPtSystErrCMS[nbinsPt] = {0.0182,0.0115,0.025};
  
  TGraphErrors *grRaaPtCMS = new TGraphErrors(nbinsPt, PtCMS, RaaPtCMS, ErrPtCMS, RaaPtStatErrCMS);  
  grRaaPtCMS->SetMarkerStyle(20);
  grRaaPtCMS->SetMarkerColor(4);
  grRaaPtCMS->GetYaxis()->SetRangeUser(-0.2,3.0);
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
  
  TBox *RaaPtCMSSys[nbinsPt];
  for(int j=0;j<nbinsPt;j++){
    RaaPtCMSSys[j] = new TBox(PtCMS[j]-0.5,  RaaPtCMS[j]-RaaPtSystErrCMS[j], PtCMS[j]+0.5,  RaaPtCMS[j]+RaaPtSystErrCMS[j]);
  }
  
  for(int j=0;j<nbinsPt;j++){
    RaaPtCMSSys[j]->SetFillStyle(0000);
    RaaPtCMSSys[j]->SetLineColor(4);
    RaaPtCMSSys[j]->Draw("same"); 
  }
    
  TBox *CMSGlobalSysPt;
  CMSGlobalSysPt = new TBox(18-0.2, 1 - 0.083, 18+0.2, 1 + 0.083);
  CMSGlobalSysPt->SetFillStyle(3001);
  CMSGlobalSysPt->SetLineColor(4);
  CMSGlobalSysPt->SetFillColor(4);
  //CMSGlobalSysPt->Draw("same"); 
    
  lgd->AddEntry(grRaaPtCMS,"CMS Data", "P");  

  }



void Draw_CMS_Y1S_RaaVsRap(TLegend *lgd)
{
  const int nbinsRap=6;

  Double_t RapCMS[nbinsRap]={0.2,0.6,1.0,1.4,1.8,2.2};
  Double_t ErrRapCMS[nbinsRap]={0};
  
  Double_t RaaRapCMS[nbinsRap] = {0.402,0.377,0.452,0.461,0.466,0.35}; 
  Double_t RaaRapStatErrCMS[nbinsRap] = {0.025,0.025,0.030,0.034,0.039,0.053};
  Double_t RaaRapSystErrCMS[nbinsRap] = {0.0404,0.038,0.046,0.0466,0.0484,0.0373};
  
  TGraphErrors *grRaaRapCMS = new TGraphErrors(nbinsRap, RapCMS, RaaRapCMS, ErrRapCMS, RaaRapStatErrCMS);  
  grRaaRapCMS->SetMarkerStyle(20);
  grRaaRapCMS->SetMarkerColor(4);
  grRaaRapCMS->GetYaxis()->SetRangeUser(0,3.0);
  grRaaRapCMS->GetXaxis()->SetTitle("p_{T}(GeV/c)");
  grRaaRapCMS->GetYaxis()->SetTitle("R_{AA}");
   
  TAxis *Xaxis2 = grRaaRapCMS->GetXaxis();
  Xaxis2->SetLimits(0.,2.4);
  
  grRaaRapCMS->Draw("AP");
  
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
  
  TBox *RaaRapCMSSys[nbinsRap];
  for(int j=0;j<nbinsRap;j++){
    RaaRapCMSSys[j] = new TBox(RapCMS[j]-0.1,  RaaRapCMS[j]-RaaRapSystErrCMS[j], RapCMS[j]+0.1,  RaaRapCMS[j]+RaaRapSystErrCMS[j]);
  }
  
  for(int j=0;j<nbinsRap;j++){
    RaaRapCMSSys[j]->SetFillStyle(0000);
    RaaRapCMSSys[j]->SetLineColor(4);
    RaaRapCMSSys[j]->Draw("same"); 
  }
    
  TBox *CMSGlobalSysRap;
  CMSGlobalSysRap = new TBox(18-0.2, 1 - 0.083, 18+0.2, 1 + 0.083);
  CMSGlobalSysRap->SetFillStyle(3001);
  CMSGlobalSysRap->SetLineColor(4);
  CMSGlobalSysRap->SetFillColor(4);
  //CMSGlobalSysRap->Draw("same"); 
    
  lgd->AddEntry(grRaaRapCMS,"CMS Data", "P");  

  }



void Draw_CMS_Y2S_RaaVsRap(TLegend *lgd)
{

  
  const int nbinsRap=2;

  Double_t RapCMS[nbinsRap]={0.6,1.8};
  Double_t ErrRapCMS[nbinsRap]={0};
  
  Double_t RaaRapCMS[nbinsRap] = {0.113,0.135}; 
  Double_t RaaRapStatErrCMS[nbinsRap] = {0.033,0.048};
  Double_t RaaRapSystErrCMS[nbinsRap] = {0.034,0.073};

  TGraphErrors *grRaaRapCMS = new TGraphErrors(nbinsRap, RapCMS, RaaRapCMS, ErrRapCMS, RaaRapStatErrCMS);  
  grRaaRapCMS->SetMarkerStyle(20);
  grRaaRapCMS->SetMarkerColor(4);
  grRaaRapCMS->GetYaxis()->SetRangeUser(-0.2,3.0);
  grRaaRapCMS->GetXaxis()->SetTitle("p_{T}(GeV/c)");
  grRaaRapCMS->GetYaxis()->SetTitle("R_{AA}");
   
  TAxis *Xaxis2 = grRaaRapCMS->GetXaxis();
  Xaxis2->SetLimits(0.,2.4);
  
  grRaaRapCMS->Draw("AP");
  
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
  
  TBox *RaaRapCMSSys[nbinsRap];
  for(int j=0;j<nbinsRap;j++){
    RaaRapCMSSys[j] = new TBox(RapCMS[j]-0.1,  RaaRapCMS[j]-RaaRapSystErrCMS[j], RapCMS[j]+0.1,  RaaRapCMS[j]+RaaRapSystErrCMS[j]);
  }
  
  for(int j=0;j<nbinsRap;j++){
    RaaRapCMSSys[j]->SetFillStyle(0000);
    RaaRapCMSSys[j]->SetLineColor(4);
    RaaRapCMSSys[j]->Draw("same"); 
  }
    
  TBox *CMSGlobalSysRap;
  CMSGlobalSysRap = new TBox(18-0.2, 1 - 0.083, 18+0.2, 1 + 0.083);
  CMSGlobalSysRap->SetFillStyle(3001);
  CMSGlobalSysRap->SetLineColor(4);
  CMSGlobalSysRap->SetFillColor(4);
  //CMSGlobalSysRap->Draw("same"); 
    
  lgd->AddEntry(grRaaRapCMS,"CMS Data", "P");  

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
