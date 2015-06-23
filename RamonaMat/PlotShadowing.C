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
#include "TGraphSmooth.h"
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

TGraph *SmoothGraph(TGraph *InGraph, Int_t N);

void PlotShadowing()
{
  
  //cat TempUpsilonCNM.dat |  awk '{printf("%.4f, ",$2)}'
  
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

  TFile *OutFile =new TFile("17042015_Shadowing.root","Recreate");

  Int_t JpsiNNRap = 14;
  Double_t JpsiRap[100]={0};
  Double_t JpsiRaaShVsRap[100]={0};
  Double_t JpsiRaaShVsRapU[100]={0};
  Double_t JpsiRaaShVsRapL[100]={0};

  ifstream filein1("InTextFiles/TempFiles/Temp_JPsiShRaaVsRap.txt");
  
  for(int i=0; i<JpsiNNRap; i++) 
    {
      filein1 >> JpsiRap[i] >> JpsiRaaShVsRap[i] >> JpsiRaaShVsRapU[i] >> JpsiRaaShVsRapL[i]; 
      
      //cout << JpsiRap[i] <<"  "<<JpsiRaaShVsRap[i]<<"  "<<JpsiRaaShVsRapU[i]<<"  "<<JpsiRaaShVsRapL[i]<<endl; 
      
    }


  TGraph *grJpsiRaaShVsRap = new TGraph(JpsiNNRap, JpsiRap, JpsiRaaShVsRap);
  grJpsiRaaShVsRap->SetName("grJpsiRaaShVsRap");
  grJpsiRaaShVsRap->SetTitle("grJpsiRaaShVsRap");
  grJpsiRaaShVsRap->SetLineWidth(2);
  grJpsiRaaShVsRap->SetLineColor(2);
  grJpsiRaaShVsRap->GetYaxis()->SetRangeUser(0.0,1.5);
  grJpsiRaaShVsRap->GetXaxis()->SetTitle("y^{j/#psi}");
  grJpsiRaaShVsRap->GetYaxis()->SetTitle("R_{AA_{Sh}} ");
 
 
  TGraph *grJpsiRaaShUVsRap = new TGraph(JpsiNNRap, JpsiRap, JpsiRaaShVsRapU);
  grJpsiRaaShUVsRap->SetName("grJpsiRaaShUVsRap"); 
  TGraph *grJpsiRaaShLVsRap = new TGraph(JpsiNNRap, JpsiRap, JpsiRaaShVsRapL);
  grJpsiRaaShLVsRap->SetName("grJpsiRaaShLVsRap"); 
 
  new TCanvas;
  gPad->SetTicks();
  grJpsiRaaShVsRap->Draw("AL");
  grJpsiRaaShUVsRap->Draw("Lsame");
  grJpsiRaaShLVsRap->Draw("Lsame");
  
  gPad->SaveAs("Plots/JpsiRaaShVsRap.pdf");
  gPad->SaveAs("Plots/JpsiRaaShVsRap.png");
  gPad->SaveAs("Plots/JpsiRaaShVsRap.eps");
  


  Int_t JpsiNNPt_Y1 = 49;
  
  Double_t JpsiPt_Y1[100]={0.0};
  Double_t JpsiRaaShVsPt_Y1[100]={0.0};
  Double_t JpsiRaaShVsPt_Y1U[100]={0.0};
  Double_t JpsiRaaShVsPt_Y1L[100]={0.0};
  
  ifstream filein2("InTextFiles/TempFiles/Temp_JPsiShRaaVsPtInRap1.txt");
  for(int i=0; i<JpsiNNPt_Y1; i++) 
    {
      filein2 >> JpsiPt_Y1[i] >> JpsiRaaShVsPt_Y1[i] >> JpsiRaaShVsPt_Y1U[i] >> JpsiRaaShVsPt_Y1L[i]; 
      
      cout<< JpsiPt_Y1[i] <<"  "<< JpsiRaaShVsPt_Y1[i] <<"  "<< JpsiRaaShVsPt_Y1U[i] <<"  "<< JpsiRaaShVsPt_Y1L[i]<<endl; 
      
    }
  
  
  TGraph *grJpsiRaaShVsPt_Y1 = new TGraph(JpsiNNPt_Y1, JpsiPt_Y1, JpsiRaaShVsPt_Y1);
  grJpsiRaaShVsPt_Y1->SetName("grJpsiRaaShVsPt_Y1");
  grJpsiRaaShVsPt_Y1->SetTitle("grJpsiRaaShVsPt_Y1");
  grJpsiRaaShVsPt_Y1->SetLineWidth(2);
  grJpsiRaaShVsPt_Y1->SetLineColor(2);
  grJpsiRaaShVsPt_Y1->GetYaxis()->SetRangeUser(0.0,1.5);
  grJpsiRaaShVsPt_Y1->GetXaxis()->SetTitle("p_{T}^{j/#psi}(GeV/c)");
  grJpsiRaaShVsPt_Y1->GetYaxis()->SetTitle("R_{AA_{Sh}} ");
    

  TGraph *grJpsiRaaShUVsPt_Y1 = new TGraph(JpsiNNPt_Y1, JpsiPt_Y1, JpsiRaaShVsPt_Y1U);
  grJpsiRaaShUVsPt_Y1->SetName("grJpsiRaaShUVsPt_Y1");
  TGraph *grJpsiRaaShLVsPt_Y1 = new TGraph(JpsiNNPt_Y1, JpsiPt_Y1, JpsiRaaShVsPt_Y1L);
  grJpsiRaaShLVsPt_Y1->SetName("grJpsiRaaShLVsPt_Y1");



  new TCanvas;
  gPad->SetTicks();
  grJpsiRaaShVsPt_Y1->Draw("AL");
  grJpsiRaaShUVsPt_Y1->Draw("Lsame");
  grJpsiRaaShLVsPt_Y1->Draw("Lsame");
  tb->DrawLatex(0.16,0.20,"|y| #leq 1");

   
  /*
  TGraph *grOut;
  TGraphSmooth *grSJpsiRaaShVsPt_Y1 = new TGraphSmooth("grSJpsiRaaShVsPt_Y1");
  grOut=grSJpsiRaaShVsPt_Y1->SmoothSuper(grJpsiRaaShVsPt_Y1,"",3);
  new TCanvas;
  gPad->SetTicks();
  grOut->Draw("AL");
  
  TGraphSmooth *grSmooth = new TGraphSmooth("grSmooth");
  grJpsiRaaShVsPt_Y1=grSmooth->SmoothSuper(grJpsiRaaShVsPt_Y1,"",3);

  grJpsiRaaShUVsPt_Y1=grSmooth->SmoothSuper(grJpsiRaaShUVsPt_Y1,"",3);
  grJpsiRaaShUVsPt_Y1->SetLineColor(4);
  
  grJpsiRaaShLVsPt_Y1=grSmooth->SmoothSuper(grJpsiRaaShLVsPt_Y1,"",3);
  grJpsiRaaShLVsPt_Y1->SetLineColor(1);

  new TCanvas;
  gPad->SetTicks();
  //grJpsiRaaShUVsPt_Y1->Draw("AL");
  grJpsiRaaShVsPt_Y1->SetLineColor(2);
  grJpsiRaaShVsPt_Y1->Draw("AL");
  //grJpsiRaaShLVsPt_Y1->Draw("Lsame");

  new TCanvas;
  gPad->SetTicks();
  grJpsiRaaShUVsPt_Y1->Draw("AL");


  new TCanvas;
  gPad->SetTicks();
  grJpsiRaaShLVsPt_Y1->Draw("AL");



  TH1D *HistJpsiRaaShVsPt_Y1_N = new TH1D("HistJpsiRaaShVsPt_Y1_N","HistJpsiRaaShVsPt_Y1_N",50,0.0,50.0);
  
  for(int i=1;i<=HistJpsiRaaShVsPt_Y1_N->GetNbinsX();i++)
    {
      HistJpsiRaaShVsPt_Y1_N->SetBinContent(i,grJpsiRaaShVsPt_Y1->Eval(HistJpsiRaaShVsPt_Y1_N->GetBinCenter(i)));
      cout<<HistJpsiRaaShVsPt_Y1_N->GetBinCenter(i)<<"            "<< HistJpsiRaaShVsPt_Y1_N->GetBinContent(i)<<endl;
    }

  
  new TCanvas;
  gPad->SetTicks();
  HistJpsiRaaShVsPt_Y1_N->Draw("P");

  */

  
  //================= smooth the graphs and draw them================//
  grJpsiRaaShVsPt_Y1=SmoothGraph(grJpsiRaaShVsPt_Y1,10);
  grJpsiRaaShUVsPt_Y1=SmoothGraph(grJpsiRaaShUVsPt_Y1,10);
  grJpsiRaaShLVsPt_Y1=SmoothGraph(grJpsiRaaShLVsPt_Y1,10);
  
  new TCanvas;
  gPad->SetTicks();
  grJpsiRaaShUVsPt_Y1->Draw("AL");
  grJpsiRaaShVsPt_Y1->SetLineColor(2);
  grJpsiRaaShVsPt_Y1->Draw("Lsame");
  grJpsiRaaShLVsPt_Y1->Draw("Lsame");
  
  
  //======================= Making histograms to smooth it ===================================//

  
  TH1D *HistJpsiRaaShVsPt_Y1 = new TH1D("HistJpsiRaaShVsPt_Y1","HistJpsiRaaShVsPt_Y1",50,0.0,50.0);
  TH1D *HistJpsiRaaShUVsPt_Y1 = new TH1D("HistJpsiRaaShUVsPt_Y1","HistJpsiRaaShUVsPt_Y1",50,0.0,50.0);
  TH1D *HistJpsiRaaShLVsPt_Y1 = new TH1D("HistJpsiRaaShLVsPt_Y1","HistJpsiRaaShLVsPt_Y1",50,0.0,50.0);
  
  for(int i=1;i<=HistJpsiRaaShVsPt_Y1->GetNbinsX();i++)
    {
      //HistJpsiRaaShVsPt_Y1->SetBinContent(i,JpsiRaaShVsPt_Y1[i-1]);
      //HistJpsiRaaShUVsPt_Y1->SetBinContent(i,JpsiRaaShVsPt_Y1U[i-1]);
      //HistJpsiRaaShLVsPt_Y1->SetBinContent(i,JpsiRaaShVsPt_Y1L[i-1]);

     //================= smooth the graphs and draw them================//
  grJpsiRaaShVsPt_Y1=SmoothGraph(grJpsiRaaShVsPt_Y1,10);
  grJpsiRaaShUVsPt_Y1=SmoothGraph(grJpsiRaaShUVsPt_Y1,10);
  grJpsiRaaShLVsPt_Y1=SmoothGraph(grJpsiRaaShLVsPt_Y1,10);
  
      HistJpsiRaaShVsPt_Y1->SetBinContent(i,grJpsiRaaShVsPt_Y1->Eval(HistJpsiRaaShVsPt_Y1->GetBinCenter(i)));
      HistJpsiRaaShUVsPt_Y1->SetBinContent(i,grJpsiRaaShUVsPt_Y1->Eval(HistJpsiRaaShUVsPt_Y1->GetBinCenter(i)));
      HistJpsiRaaShLVsPt_Y1->SetBinContent(i,grJpsiRaaShLVsPt_Y1->Eval(HistJpsiRaaShLVsPt_Y1->GetBinCenter(i)));
      
    }
  
  /*
  cout<<" Before Rebin : "<<endl;
 for(int i=1;i<=HistJpsiRaaShVsPt_Y1->GetNbinsX();i++)
    {
      cout<<HistJpsiRaaShVsPt_Y1->GetBinCenter(i)<<"            "<< HistJpsiRaaShVsPt_Y1->GetBinContent(i)<<endl;
    }
  */



  HistJpsiRaaShVsPt_Y1->SetTitle("HistJpsiRaaShVsPt_Y1");
  HistJpsiRaaShVsPt_Y1->SetName("HistJpsiRaaShVsPt_Y1");
  HistJpsiRaaShVsPt_Y1->GetXaxis()->SetTitle("p_{T}^{J/#psi}");
  HistJpsiRaaShVsPt_Y1->GetYaxis()->SetTitle("R_{AA}^{Sh}");
  
  HistJpsiRaaShUVsPt_Y1->SetTitle("HistJpsiRaaShUVsPt_Y1");
  HistJpsiRaaShUVsPt_Y1->SetName("HistJpsiRaaShUVsPt_Y1");
  HistJpsiRaaShUVsPt_Y1->GetXaxis()->SetTitle("p_{T}^{J/#psi}");
  HistJpsiRaaShUVsPt_Y1->GetYaxis()->SetTitle("R_{AA}^{Sh}");
  
  HistJpsiRaaShLVsPt_Y1->SetTitle("HistJpsiRaaShLVsPt_Y1");
  HistJpsiRaaShLVsPt_Y1->SetName("HistJpsiRaaShLVsPt_Y1");
  HistJpsiRaaShLVsPt_Y1->GetXaxis()->SetTitle("p_{T}^{J/#psi}");
  HistJpsiRaaShLVsPt_Y1->GetYaxis()->SetTitle("R_{AA}^{Sh}");

  /*
  HistJpsiRaaShVsPt_Y1->Rebin(2);
  HistJpsiRaaShUVsPt_Y1->Rebin(2);
  HistJpsiRaaShLVsPt_Y1->Rebin(2);

  HistJpsiRaaShVsPt_Y1->Scale(1.0/2.0);
  HistJpsiRaaShUVsPt_Y1->Scale(1.0/2.0);
  HistJpsiRaaShLVsPt_Y1->Scale(1.0/2.0);

  HistJpsiRaaShVsPt_Y1->Smooth(40);
  HistJpsiRaaShUVsPt_Y1->Smooth(40);
  HistJpsiRaaShLVsPt_Y1->Smooth(40);
  
  
  cout<<" After Rebin : "<<endl;
  cout<<"JPsi Bin Centre: "<<"        "<<"Bin Content"<<endl;
  */  
  for(int i=1;i<=HistJpsiRaaShVsPt_Y1->GetNbinsX();i++)
    {
      cout<<HistJpsiRaaShVsPt_Y1->GetBinCenter(i)<<"            "<< HistJpsiRaaShVsPt_Y1->GetBinContent(i)<<endl;
    }
  
  new TCanvas;
  HistJpsiRaaShUVsPt_Y1->Draw("PL");  
  HistJpsiRaaShVsPt_Y1->Draw("PLsame");
  HistJpsiRaaShLVsPt_Y1->Draw("PLsame");
  tb->DrawLatex(0.16,0.20,"|y| #leq 1");
  gPad->SaveAs("Plots/JpsiRaaShVsPt_Y1.pdf");
  gPad->SaveAs("Plots/JpsiRaaShVsPt_Y1.png");
  gPad->SaveAs("Plots/JpsiRaaShVsPt_Y1.eps");
  
  
  
  //return;

  Int_t JpsiNNPt_Y2440 = 49;
  
  Double_t JpsiPt_Y2440[100]={0.0};
  Double_t JpsiRaaShVsPt_Y2440[100]={0.0};
  Double_t JpsiRaaShVsPt_Y2440U[100]={0.0};
  Double_t JpsiRaaShVsPt_Y2440L[100]={0.0};
  
  ifstream filein3("InTextFiles/TempFiles/Temp_JPsiShRaaVsPtInRap2440.txt");
  for(int i=0; i<JpsiNNPt_Y2440; i++) 
    {
      filein3 >> JpsiPt_Y2440[i] >> JpsiRaaShVsPt_Y2440[i] >> JpsiRaaShVsPt_Y2440U[i] >> JpsiRaaShVsPt_Y2440L[i]; 
      
      cout<< JpsiPt_Y2440[i] <<"  "<< JpsiRaaShVsPt_Y2440[i] <<"  "<< JpsiRaaShVsPt_Y2440U[i] <<"  "<< JpsiRaaShVsPt_Y2440L[i]<<endl; 
      
    }
  
  
  TGraph *grJpsiRaaShVsPt_Y2440 = new TGraph(JpsiNNPt_Y2440, JpsiPt_Y2440, JpsiRaaShVsPt_Y2440);
  grJpsiRaaShVsPt_Y2440->SetName("grJpsiRaaShVsPt_Y2440");
  grJpsiRaaShVsPt_Y2440->SetTitle("grJpsiRaaShVsPt_Y2440");
  grJpsiRaaShVsPt_Y2440->SetLineWidth(2);
  grJpsiRaaShVsPt_Y2440->SetLineColor(2);
  grJpsiRaaShVsPt_Y2440->GetYaxis()->SetRangeUser(0.0,1.5);
  grJpsiRaaShVsPt_Y2440->GetXaxis()->SetTitle("p_{T}^{j/#psi}(GeV/c)");
  grJpsiRaaShVsPt_Y2440->GetYaxis()->SetTitle("R_{AA_{Sh}} ");
    

  TGraph *grJpsiRaaShUVsPt_Y2440 = new TGraph(JpsiNNPt_Y2440, JpsiPt_Y2440, JpsiRaaShVsPt_Y2440U);
  grJpsiRaaShUVsPt_Y2440->SetName("grJpsiRaaShUVsPt_Y2440");
  TGraph *grJpsiRaaShLVsPt_Y2440 = new TGraph(JpsiNNPt_Y2440, JpsiPt_Y2440, JpsiRaaShVsPt_Y2440L);
  grJpsiRaaShLVsPt_Y2440->SetName("grJpsiRaaShLVsPt_Y2440");



  new TCanvas;
  gPad->SetTicks();
  grJpsiRaaShVsPt_Y2440->Draw("AL");
  grJpsiRaaShUVsPt_Y2440->Draw("Lsame");
  grJpsiRaaShLVsPt_Y2440->Draw("Lsame");
  tb->DrawLatex(0.16,0.20,"2.4 #leq y #leq 4.0");
  //gPad->SaveAs("Plots/JpsiRaaShVsPt_Y2440.pdf");
  //gPad->SaveAs("Plots/JpsiRaaShVsPt_Y2440.png");
  //gPad->SaveAs("Plots/JpsiRaaShVsPt_Y2440.eps");
  

 //================= smooth the graphs and draw them================//
  grJpsiRaaShVsPt_Y2440=SmoothGraph(grJpsiRaaShVsPt_Y2440,10);
  grJpsiRaaShUVsPt_Y2440=SmoothGraph(grJpsiRaaShUVsPt_Y2440,10);
  grJpsiRaaShLVsPt_Y2440=SmoothGraph(grJpsiRaaShLVsPt_Y2440,10);
  
  new TCanvas;
  gPad->SetTicks();
  grJpsiRaaShUVsPt_Y2440->Draw("AL");
  grJpsiRaaShVsPt_Y2440->SetLineColor(2);
  grJpsiRaaShVsPt_Y2440->Draw("Lsame");
  grJpsiRaaShLVsPt_Y2440->Draw("Lsame");
  //======================= Making histograms to smooth it ===================================//

  
  TH1D *HistJpsiRaaShVsPt_Y2440 = new TH1D("HistJpsiRaaShVsPt_Y2440","HistJpsiRaaShVsPt_Y2440",50,0.0,50.0);
  TH1D *HistJpsiRaaShUVsPt_Y2440 = new TH1D("HistJpsiRaaShUVsPt_Y2440","HistJpsiRaaShUVsPt_Y2440",50,0.0,50.0);
  TH1D *HistJpsiRaaShLVsPt_Y2440 = new TH1D("HistJpsiRaaShLVsPt_Y2440","HistJpsiRaaShLVsPt_Y2440",50,0.0,50.0);
  
  for(int i=1;i<=HistJpsiRaaShVsPt_Y2440->GetNbinsX();i++)
    {
  
      //HistJpsiRaaShVsPt_Y2440->SetBinContent(i,JpsiRaaShVsPt_Y2440[i-1]);
      //HistJpsiRaaShUVsPt_Y2440->SetBinContent(i,JpsiRaaShVsPt_Y2440U[i-1]);
      //HistJpsiRaaShLVsPt_Y2440->SetBinContent(i,JpsiRaaShVsPt_Y2440L[i-1]);
    
      HistJpsiRaaShVsPt_Y2440->SetBinContent(i,grJpsiRaaShVsPt_Y2440->Eval(HistJpsiRaaShVsPt_Y2440->GetBinCenter(i)));
      HistJpsiRaaShUVsPt_Y2440->SetBinContent(i,grJpsiRaaShUVsPt_Y2440->Eval(HistJpsiRaaShUVsPt_Y2440->GetBinCenter(i)));
      HistJpsiRaaShLVsPt_Y2440->SetBinContent(i,grJpsiRaaShLVsPt_Y2440->Eval(HistJpsiRaaShLVsPt_Y2440->GetBinCenter(i)));

    }
  
  cout<<" Before Rebin : "<<endl;
 for(int i=1;i<=HistJpsiRaaShVsPt_Y2440->GetNbinsX();i++)
    {
      cout<<HistJpsiRaaShVsPt_Y2440->GetBinCenter(i)<<"            "<< HistJpsiRaaShVsPt_Y2440->GetBinContent(i)<<endl;
    }




  HistJpsiRaaShVsPt_Y2440->SetTitle("HistJpsiRaaShVsPt_Y2440");
  HistJpsiRaaShVsPt_Y2440->SetName("HistJpsiRaaShVsPt_Y2440");
  HistJpsiRaaShVsPt_Y2440->GetXaxis()->SetTitle("p_{T}^{J/#psi}");
  HistJpsiRaaShVsPt_Y2440->GetYaxis()->SetTitle("R_{AA}^{Sh}");
  
  HistJpsiRaaShUVsPt_Y2440->SetTitle("HistJpsiRaaShUVsPt_Y2440");
  HistJpsiRaaShUVsPt_Y2440->SetName("HistJpsiRaaShUVsPt_Y2440");
  HistJpsiRaaShUVsPt_Y2440->GetXaxis()->SetTitle("p_{T}^{J/#psi}");
  HistJpsiRaaShUVsPt_Y2440->GetYaxis()->SetTitle("R_{AA}^{Sh}");
  
  HistJpsiRaaShLVsPt_Y2440->SetTitle("HistJpsiRaaShLVsPt_Y2440");
  HistJpsiRaaShLVsPt_Y2440->SetName("HistJpsiRaaShLVsPt_Y2440");
  HistJpsiRaaShLVsPt_Y2440->GetXaxis()->SetTitle("p_{T}^{J/#psi}");
  HistJpsiRaaShLVsPt_Y2440->GetYaxis()->SetTitle("R_{AA}^{Sh}");

  /*
  HistJpsiRaaShVsPt_Y2440->Rebin(2);
  HistJpsiRaaShUVsPt_Y2440->Rebin(2);
  HistJpsiRaaShLVsPt_Y2440->Rebin(2);

  HistJpsiRaaShVsPt_Y2440->Scale(1.0/2.0);
  HistJpsiRaaShUVsPt_Y2440->Scale(1.0/2.0);
  HistJpsiRaaShLVsPt_Y2440->Scale(1.0/2.0);

  HistJpsiRaaShVsPt_Y2440->Smooth(40);
  HistJpsiRaaShUVsPt_Y2440->Smooth(40);
  HistJpsiRaaShLVsPt_Y2440->Smooth(40);
  
  
  cout<<" After Rebin : "<<endl;
  cout<<"JPsi Bin Centre: "<<"        "<<"Bin Content"<<endl;
      
  for(int i=1;i<=HistJpsiRaaShVsPt_Y2440->GetNbinsX();i++)
    {
      cout<<HistJpsiRaaShVsPt_Y2440->GetBinCenter(i)<<"            "<< HistJpsiRaaShVsPt_Y2440->GetBinContent(i)<<endl;
    }
  */

  new TCanvas;
  HistJpsiRaaShUVsPt_Y2440->Draw("PL");  
  HistJpsiRaaShVsPt_Y2440->Draw("PLsame");
  HistJpsiRaaShLVsPt_Y2440->Draw("PLsame");
  tb->DrawLatex(0.16,0.20,"2.4 #leq y #leq 4.0");
  gPad->SaveAs("Plots/JpsiRaaShVsPt_Y2440.pdf");
  gPad->SaveAs("Plots/JpsiRaaShVsPt_Y2440.png");
  gPad->SaveAs("Plots/JpsiRaaShVsPt_Y2440.eps");


  //  return;


  Int_t JpsiNNPt_Y21 = 49;
  
  Double_t JpsiPt_Y21[100]={0.0};
  Double_t JpsiRaaShVsPt_Y21[100]={0.0};
  Double_t JpsiRaaShVsPt_Y21U[100]={0.0};
  Double_t JpsiRaaShVsPt_Y21L[100]={0.0};
  
  ifstream filein4("InTextFiles/TempFiles/Temp_JPsiShRaaVsPtInRap21.txt");
  for(int i=0; i<JpsiNNPt_Y21; i++) 
    {
      filein4 >> JpsiPt_Y21[i] >> JpsiRaaShVsPt_Y21[i] >> JpsiRaaShVsPt_Y21U[i] >> JpsiRaaShVsPt_Y21L[i]; 
      
      cout<< JpsiPt_Y21[i] <<"  "<< JpsiRaaShVsPt_Y21[i] <<"  "<< JpsiRaaShVsPt_Y21U[i] <<"  "<< JpsiRaaShVsPt_Y21L[i]<<endl; 
      
    }
  
  
  TGraph *grJpsiRaaShVsPt_Y21 = new TGraph(JpsiNNPt_Y21, JpsiPt_Y21, JpsiRaaShVsPt_Y21);
  grJpsiRaaShVsPt_Y21->SetName("grJpsiRaaShVsPt_Y21");
  grJpsiRaaShVsPt_Y21->SetTitle("grJpsiRaaShVsPt_Y21");
  grJpsiRaaShVsPt_Y21->SetLineWidth(2);
  grJpsiRaaShVsPt_Y21->SetLineColor(2);
  grJpsiRaaShVsPt_Y21->GetYaxis()->SetRangeUser(0.0,1.5);
  grJpsiRaaShVsPt_Y21->GetXaxis()->SetTitle("p_{T}^{j/#psi}(GeV/c)");
  grJpsiRaaShVsPt_Y21->GetYaxis()->SetTitle("R_{AA_{Sh}} ");
    

  TGraph *grJpsiRaaShUVsPt_Y21 = new TGraph(JpsiNNPt_Y21, JpsiPt_Y21, JpsiRaaShVsPt_Y21U);
  grJpsiRaaShUVsPt_Y21->SetName("grJpsiRaaShUVsPt_Y21");
  TGraph *grJpsiRaaShLVsPt_Y21 = new TGraph(JpsiNNPt_Y21, JpsiPt_Y21, JpsiRaaShVsPt_Y21L);
  grJpsiRaaShLVsPt_Y21->SetName("grJpsiRaaShLVsPt_Y21");



  new TCanvas;
  gPad->SetTicks();
  grJpsiRaaShVsPt_Y21->Draw("AL");
  grJpsiRaaShUVsPt_Y21->Draw("Lsame");
  grJpsiRaaShLVsPt_Y21->Draw("Lsame");
  tb->DrawLatex(0.16,0.20,"|y| #leq 2.1");



//================= smooth the graphs and draw them================//
  grJpsiRaaShVsPt_Y21=SmoothGraph(grJpsiRaaShVsPt_Y21,10);
  grJpsiRaaShUVsPt_Y21=SmoothGraph(grJpsiRaaShUVsPt_Y21,10);
  grJpsiRaaShLVsPt_Y21=SmoothGraph(grJpsiRaaShLVsPt_Y21,10);
  
  new TCanvas;
  gPad->SetTicks();
  grJpsiRaaShUVsPt_Y21->Draw("AL");
  grJpsiRaaShVsPt_Y21->SetLineColor(2);
  grJpsiRaaShVsPt_Y21->Draw("Lsame");
  grJpsiRaaShLVsPt_Y21->Draw("Lsame");


  //======================= Making histograms to smooth it ===================================//

  
  TH1D *HistJpsiRaaShVsPt_Y21 = new TH1D("HistJpsiRaaShVsPt_Y21","HistJpsiRaaShVsPt_Y21",50,0.0,50.0);
  TH1D *HistJpsiRaaShUVsPt_Y21 = new TH1D("HistJpsiRaaShUVsPt_Y21","HistJpsiRaaShUVsPt_Y21",50,0.0,50.0);
  TH1D *HistJpsiRaaShLVsPt_Y21 = new TH1D("HistJpsiRaaShLVsPt_Y21","HistJpsiRaaShLVsPt_Y21",50,0.0,50.0);
  
  for(int i=1;i<=HistJpsiRaaShVsPt_Y21->GetNbinsX();i++)
    {
    
      //HistJpsiRaaShVsPt_Y21->SetBinContent(i,JpsiRaaShVsPt_Y21[i-1]);
      //HistJpsiRaaShUVsPt_Y21->SetBinContent(i,JpsiRaaShVsPt_Y21U[i-1]);
      //HistJpsiRaaShLVsPt_Y21->SetBinContent(i,JpsiRaaShVsPt_Y21L[i-1]);
    
      HistJpsiRaaShVsPt_Y21->SetBinContent(i,grJpsiRaaShVsPt_Y21->Eval(HistJpsiRaaShVsPt_Y21->GetBinCenter(i)));
      HistJpsiRaaShUVsPt_Y21->SetBinContent(i,grJpsiRaaShUVsPt_Y21->Eval(HistJpsiRaaShUVsPt_Y21->GetBinCenter(i)));
      HistJpsiRaaShLVsPt_Y21->SetBinContent(i,grJpsiRaaShLVsPt_Y21->Eval(HistJpsiRaaShLVsPt_Y21->GetBinCenter(i)));

    }
  
  cout<<" Before Rebin : "<<endl;
 for(int i=1;i<=HistJpsiRaaShVsPt_Y21->GetNbinsX();i++)
    {
      cout<<HistJpsiRaaShVsPt_Y21->GetBinCenter(i)<<"            "<< HistJpsiRaaShVsPt_Y21->GetBinContent(i)<<endl;
    }




  HistJpsiRaaShVsPt_Y21->SetTitle("HistJpsiRaaShVsPt_Y21");
  HistJpsiRaaShVsPt_Y21->SetName("HistJpsiRaaShVsPt_Y21");
  HistJpsiRaaShVsPt_Y21->GetXaxis()->SetTitle("p_{T}^{J/#psi}");
  HistJpsiRaaShVsPt_Y21->GetYaxis()->SetTitle("R_{AA}^{Sh}");
  
  HistJpsiRaaShUVsPt_Y21->SetTitle("HistJpsiRaaShUVsPt_Y21");
  HistJpsiRaaShUVsPt_Y21->SetName("HistJpsiRaaShUVsPt_Y21");
  HistJpsiRaaShUVsPt_Y21->GetXaxis()->SetTitle("p_{T}^{J/#psi}");
  HistJpsiRaaShUVsPt_Y21->GetYaxis()->SetTitle("R_{AA}^{Sh}");
  
  HistJpsiRaaShLVsPt_Y21->SetTitle("HistJpsiRaaShLVsPt_Y21");
  HistJpsiRaaShLVsPt_Y21->SetName("HistJpsiRaaShLVsPt_Y21");
  HistJpsiRaaShLVsPt_Y21->GetXaxis()->SetTitle("p_{T}^{J/#psi}");
  HistJpsiRaaShLVsPt_Y21->GetYaxis()->SetTitle("R_{AA}^{Sh}");

  /*
  HistJpsiRaaShVsPt_Y21->Rebin(2);
  HistJpsiRaaShUVsPt_Y21->Rebin(2);
  HistJpsiRaaShLVsPt_Y21->Rebin(2);

  HistJpsiRaaShVsPt_Y21->Scale(1.0/2.0);
  HistJpsiRaaShUVsPt_Y21->Scale(1.0/2.0);
  HistJpsiRaaShLVsPt_Y21->Scale(1.0/2.0);

  HistJpsiRaaShVsPt_Y21->Smooth(40);
  HistJpsiRaaShUVsPt_Y21->Smooth(40);
  HistJpsiRaaShLVsPt_Y21->Smooth(40);
  
  
  cout<<" After Rebin : "<<endl;
  cout<<"JPsi Bin Centre: "<<"        "<<"Bin Content"<<endl;
      
  for(int i=1;i<=HistJpsiRaaShVsPt_Y21->GetNbinsX();i++)
    {
      cout<<HistJpsiRaaShVsPt_Y21->GetBinCenter(i)<<"            "<< HistJpsiRaaShVsPt_Y21->GetBinContent(i)<<endl;
    }
  */

  new TCanvas;
  HistJpsiRaaShUVsPt_Y21->Draw("PL");  
  HistJpsiRaaShVsPt_Y21->Draw("PLsame");
  HistJpsiRaaShLVsPt_Y21->Draw("PLsame");
  tb->DrawLatex(0.16,0.20,"|y| #leq 2.1");
  gPad->SaveAs("Plots/JpsiRaaShVsPt_Y21.pdf");
  gPad->SaveAs("Plots/JpsiRaaShVsPt_Y21.png");
  gPad->SaveAs("Plots/JpsiRaaShVsPt_Y21.eps");


  //return;


 


  //========================== Shadowing with Upsilon ==========================================================================//

  Int_t UpsilonNNRap = 11;
  Double_t UpsilonRap[100]={0};
  Double_t UpsilonRaaShVsRap[100]={0};
  Double_t UpsilonRaaShVsRapU[100]={0};
  Double_t UpsilonRaaShVsRapL[100]={0};

  ifstream filein5("InTextFiles/TempFiles/Temp_UpsilonShRaaVsRap.txt");
  
  for(int i=0; i<UpsilonNNRap; i++) 
    {
      filein5 >> UpsilonRap[i] >> UpsilonRaaShVsRap[i] >> UpsilonRaaShVsRapU[i] >> UpsilonRaaShVsRapL[i]; 
      
      //cout << UpsilonRap[i] <<"  "<<UpsilonRaaShVsRap[i]<<"  "<<UpsilonRaaShVsRapU[i]<<"  "<<UpsilonRaaShVsRapL[i]<<endl; 
      
    }


  TGraph *grUpsilonRaaShVsRap = new TGraph(UpsilonNNRap, UpsilonRap, UpsilonRaaShVsRap);
  grUpsilonRaaShVsRap->SetName("grUpsilonRaaShVsRap");
  grUpsilonRaaShVsRap->SetTitle("grUpsilonRaaShVsRap");
  grUpsilonRaaShVsRap->SetLineWidth(2);
  grUpsilonRaaShVsRap->SetLineColor(2);
  grUpsilonRaaShVsRap->GetYaxis()->SetRangeUser(0.0,1.5);
  grUpsilonRaaShVsRap->GetXaxis()->SetTitle("y^{#varUpsilon}");
  grUpsilonRaaShVsRap->GetYaxis()->SetTitle("R_{AA_{Sh}} ");
 
 
  TGraph *grUpsilonRaaShUVsRap = new TGraph(UpsilonNNRap, UpsilonRap, UpsilonRaaShVsRapU);
  grUpsilonRaaShUVsRap->SetName("grUpsilonRaaShUVsRap"); 
  TGraph *grUpsilonRaaShLVsRap = new TGraph(UpsilonNNRap, UpsilonRap, UpsilonRaaShVsRapL);
  grUpsilonRaaShLVsRap->SetName("grUpsilonRaaShLVsRap"); 
 
  new TCanvas;
  gPad->SetTicks();
  grUpsilonRaaShVsRap->Draw("AL");
  grUpsilonRaaShUVsRap->Draw("Lsame");
  grUpsilonRaaShLVsRap->Draw("Lsame");
  
  gPad->SaveAs("Plots/UpsilonRaaShVsRap.pdf");
  gPad->SaveAs("Plots/UpsilonRaaShVsRap.png");
  gPad->SaveAs("Plots/UpsilonRaaShVsRap.eps");
  



  Int_t UpsilonNNPt_Y1 = 49;
  
  Double_t UpsilonPt_Y1[100]={0.0};
  Double_t UpsilonRaaShVsPt_Y1[100]={0.0};
  Double_t UpsilonRaaShVsPt_Y1U[100]={0.0};
  Double_t UpsilonRaaShVsPt_Y1L[100]={0.0};
  
  ifstream filein6("InTextFiles/TempFiles/Temp_UpsilonShRaaVsPtInRap1.txt");
  for(int i=0; i<UpsilonNNPt_Y1; i++) 
    {
      filein6 >> UpsilonPt_Y1[i] >> UpsilonRaaShVsPt_Y1[i] >> UpsilonRaaShVsPt_Y1U[i] >> UpsilonRaaShVsPt_Y1L[i]; 
      
      cout<< UpsilonPt_Y1[i] <<"  "<< UpsilonRaaShVsPt_Y1[i] <<"  "<< UpsilonRaaShVsPt_Y1U[i] <<"  "<< UpsilonRaaShVsPt_Y1L[i]<<endl; 
      
    }
  
  
  TGraph *grUpsilonRaaShVsPt_Y1 = new TGraph(UpsilonNNPt_Y1, UpsilonPt_Y1, UpsilonRaaShVsPt_Y1);
  grUpsilonRaaShVsPt_Y1->SetName("grUpsilonRaaShVsPt_Y1");
  grUpsilonRaaShVsPt_Y1->SetTitle("grUpsilonRaaShVsPt_Y1");
  grUpsilonRaaShVsPt_Y1->SetLineWidth(2);
  grUpsilonRaaShVsPt_Y1->SetLineColor(2);
  grUpsilonRaaShVsPt_Y1->GetYaxis()->SetRangeUser(0.0,1.5);
  grUpsilonRaaShVsPt_Y1->GetXaxis()->SetTitle("p_{T}^{#varUpsilon}(GeV/c)");
  grUpsilonRaaShVsPt_Y1->GetYaxis()->SetTitle("R_{AA_{Sh}} ");
    

  TGraph *grUpsilonRaaShUVsPt_Y1 = new TGraph(UpsilonNNPt_Y1, UpsilonPt_Y1, UpsilonRaaShVsPt_Y1U);
  grUpsilonRaaShUVsPt_Y1->SetName("grUpsilonRaaShUVsPt_Y1");
  TGraph *grUpsilonRaaShLVsPt_Y1 = new TGraph(UpsilonNNPt_Y1, UpsilonPt_Y1, UpsilonRaaShVsPt_Y1L);
  grUpsilonRaaShLVsPt_Y1->SetName("grUpsilonRaaShLVsPt_Y1");



  new TCanvas;
  gPad->SetTicks();
  grUpsilonRaaShVsPt_Y1->Draw("AL");
  grUpsilonRaaShUVsPt_Y1->Draw("Lsame");
  grUpsilonRaaShLVsPt_Y1->Draw("Lsame");
  tb->DrawLatex(0.16,0.20,"|y| #leq 1.0");


  grUpsilonRaaShVsPt_Y1=SmoothGraph(grUpsilonRaaShVsPt_Y1,10);
  grUpsilonRaaShUVsPt_Y1=SmoothGraph(grUpsilonRaaShUVsPt_Y1,10);
  grUpsilonRaaShLVsPt_Y1=SmoothGraph(grUpsilonRaaShLVsPt_Y1,10);


  new TCanvas;
  gPad->SetTicks();
  grUpsilonRaaShUVsPt_Y1->Draw("AL");
  grUpsilonRaaShVsPt_Y1->SetLineColor(2);
  grUpsilonRaaShVsPt_Y1->Draw("Lsame");
  grUpsilonRaaShLVsPt_Y1->Draw("Lsame");

  
  //======================= Making histograms to smooth it ===================================//

  
  TH1D *HistUpsilonRaaShVsPt_Y1 = new TH1D("HistUpsilonRaaShVsPt_Y1","HistUpsilonRaaShVsPt_Y1",50,0.0,50.0);
  TH1D *HistUpsilonRaaShUVsPt_Y1 = new TH1D("HistUpsilonRaaShUVsPt_Y1","HistUpsilonRaaShUVsPt_Y1",50,0.0,50.0);
  TH1D *HistUpsilonRaaShLVsPt_Y1 = new TH1D("HistUpsilonRaaShLVsPt_Y1","HistUpsilonRaaShLVsPt_Y1",50,0.0,50.0);
  
  for(int i=1;i<=HistUpsilonRaaShVsPt_Y1->GetNbinsX();i++)
    {
      //HistUpsilonRaaShVsPt_Y1->SetBinContent(i,UpsilonRaaShVsPt_Y1[i-1]);
      //HistUpsilonRaaShUVsPt_Y1->SetBinContent(i,UpsilonRaaShVsPt_Y1U[i-1]);
      //HistUpsilonRaaShLVsPt_Y1->SetBinContent(i,UpsilonRaaShVsPt_Y1L[i-1]);
      HistUpsilonRaaShVsPt_Y1->SetBinContent(i,grUpsilonRaaShVsPt_Y1->Eval(HistUpsilonRaaShVsPt_Y1->GetBinCenter(i)));
      HistUpsilonRaaShUVsPt_Y1->SetBinContent(i,grUpsilonRaaShUVsPt_Y1->Eval(HistUpsilonRaaShUVsPt_Y1->GetBinCenter(i)));
      HistUpsilonRaaShLVsPt_Y1->SetBinContent(i,grUpsilonRaaShLVsPt_Y1->Eval(HistUpsilonRaaShLVsPt_Y1->GetBinCenter(i)));


    }
  
  cout<<" Before Rebin : "<<endl;
 for(int i=1;i<=HistUpsilonRaaShVsPt_Y1->GetNbinsX();i++)
    {
      cout<<HistUpsilonRaaShVsPt_Y1->GetBinCenter(i)<<"            "<< HistUpsilonRaaShVsPt_Y1->GetBinContent(i)<<endl;
    }



  HistUpsilonRaaShVsPt_Y1->SetTitle("HistUpsilonRaaShVsPt_Y1");
  HistUpsilonRaaShVsPt_Y1->SetName("HistUpsilonRaaShVsPt_Y1");
  HistUpsilonRaaShVsPt_Y1->GetXaxis()->SetTitle("p_{T}^{#varUpsilon}");
  HistUpsilonRaaShVsPt_Y1->GetYaxis()->SetTitle("R_{AA}^{Sh}");
  
  HistUpsilonRaaShUVsPt_Y1->SetTitle("HistUpsilonRaaShUVsPt_Y1");
  HistUpsilonRaaShUVsPt_Y1->SetName("HistUpsilonRaaShUVsPt_Y1");
  HistUpsilonRaaShUVsPt_Y1->GetXaxis()->SetTitle("p_{T}^{#varUpsilon}");
  HistUpsilonRaaShUVsPt_Y1->GetYaxis()->SetTitle("R_{AA}^{Sh}");
  
  HistUpsilonRaaShLVsPt_Y1->SetTitle("HistUpsilonRaaShLVsPt_Y1");
  HistUpsilonRaaShLVsPt_Y1->SetName("HistUpsilonRaaShLVsPt_Y1");
  HistUpsilonRaaShLVsPt_Y1->GetXaxis()->SetTitle("p_{T}^{#varUpsilon}");
  HistUpsilonRaaShLVsPt_Y1->GetYaxis()->SetTitle("R_{AA}^{Sh}");

  /*  
  HistUpsilonRaaShVsPt_Y1->Rebin(2);
  HistUpsilonRaaShUVsPt_Y1->Rebin(2);
  HistUpsilonRaaShLVsPt_Y1->Rebin(2);

  HistUpsilonRaaShVsPt_Y1->Scale(1.0/2.0);
  HistUpsilonRaaShUVsPt_Y1->Scale(1.0/2.0);
  HistUpsilonRaaShLVsPt_Y1->Scale(1.0/2.0);

  HistUpsilonRaaShVsPt_Y1->Smooth(40);
  HistUpsilonRaaShUVsPt_Y1->Smooth(40);
  HistUpsilonRaaShLVsPt_Y1->Smooth(40);
  
  
  cout<<" After Rebin : "<<endl;
  cout<<"JPsi Bin Centre: "<<"        "<<"Bin Content"<<endl;
      
  for(int i=1;i<=HistUpsilonRaaShVsPt_Y1->GetNbinsX();i++)
    {
      cout<<HistUpsilonRaaShVsPt_Y1->GetBinCenter(i)<<"            "<< HistUpsilonRaaShVsPt_Y1->GetBinContent(i)<<endl;
    }
  */

  new TCanvas;
  HistUpsilonRaaShUVsPt_Y1->Draw("PL");  
  HistUpsilonRaaShVsPt_Y1->Draw("PLsame");
  HistUpsilonRaaShLVsPt_Y1->Draw("PLsame");
  gPad->SaveAs("Plots/UpsilonRaaShVsPt_Y1.pdf");
  gPad->SaveAs("Plots/UpsilonRaaShVsPt_Y1.png");
  gPad->SaveAs("Plots/UpsilonRaaShVsPt_Y1.eps");
  tb->DrawLatex(0.16,0.20,"|y| #leq 1.0");

 

  Int_t UpsilonNNPt_Y2440 = 50;
  
  Double_t UpsilonPt_Y2440[100]={0.0};
  Double_t UpsilonRaaShVsPt_Y2440[100]={0.0};
  Double_t UpsilonRaaShVsPt_Y2440U[100]={0.0};
  Double_t UpsilonRaaShVsPt_Y2440L[100]={0.0};
  
  ifstream filein7("InTextFiles/TempFiles/Temp_UpsilonShRaaVsPtInRap2440.txt");
  for(int i=0; i<UpsilonNNPt_Y2440; i++) 
    {
      filein7 >> UpsilonPt_Y2440[i] >> UpsilonRaaShVsPt_Y2440[i] >> UpsilonRaaShVsPt_Y2440U[i] >> UpsilonRaaShVsPt_Y2440L[i]; 
      
      cout<< UpsilonPt_Y2440[i] <<"  "<< UpsilonRaaShVsPt_Y2440[i] <<"  "<< UpsilonRaaShVsPt_Y2440U[i] <<"  "<< UpsilonRaaShVsPt_Y2440L[i]<<endl; 
      
    }
  
  
  TGraph *grUpsilonRaaShVsPt_Y2440 = new TGraph(UpsilonNNPt_Y2440, UpsilonPt_Y2440, UpsilonRaaShVsPt_Y2440);
  grUpsilonRaaShVsPt_Y2440->SetName("grUpsilonRaaShVsPt_Y2440");
  grUpsilonRaaShVsPt_Y2440->SetTitle("grUpsilonRaaShVsPt_Y2440");
  grUpsilonRaaShVsPt_Y2440->SetLineWidth(2);
  grUpsilonRaaShVsPt_Y2440->SetLineColor(2);
  grUpsilonRaaShVsPt_Y2440->GetYaxis()->SetRangeUser(0.0,1.5);
  grUpsilonRaaShVsPt_Y2440->GetXaxis()->SetTitle("p_{T}^{#varUpsilon}(GeV/c)");
  grUpsilonRaaShVsPt_Y2440->GetYaxis()->SetTitle("R_{AA_{Sh}} ");
    

  TGraph *grUpsilonRaaShUVsPt_Y2440 = new TGraph(UpsilonNNPt_Y2440, UpsilonPt_Y2440, UpsilonRaaShVsPt_Y2440U);
  grUpsilonRaaShUVsPt_Y2440->SetName("grUpsilonRaaShUVsPt_Y2440");
  TGraph *grUpsilonRaaShLVsPt_Y2440 = new TGraph(UpsilonNNPt_Y2440, UpsilonPt_Y2440, UpsilonRaaShVsPt_Y2440L);
  grUpsilonRaaShLVsPt_Y2440->SetName("grUpsilonRaaShLVsPt_Y2440");



  new TCanvas;
  gPad->SetTicks();
  grUpsilonRaaShVsPt_Y2440->Draw("AL");
  grUpsilonRaaShUVsPt_Y2440->Draw("Lsame");
  grUpsilonRaaShLVsPt_Y2440->Draw("Lsame");
  tb->DrawLatex(0.16,0.20,"2.4 #leq y #leq 4.0");


 grUpsilonRaaShVsPt_Y2440=SmoothGraph(grUpsilonRaaShVsPt_Y2440,10);
  grUpsilonRaaShUVsPt_Y2440=SmoothGraph(grUpsilonRaaShUVsPt_Y2440,10);
  grUpsilonRaaShLVsPt_Y2440=SmoothGraph(grUpsilonRaaShLVsPt_Y2440,10);


  new TCanvas;
  gPad->SetTicks();
  grUpsilonRaaShUVsPt_Y2440->Draw("AL");
  grUpsilonRaaShVsPt_Y2440->SetLineColor(2);
  grUpsilonRaaShVsPt_Y2440->Draw("Lsame");
  grUpsilonRaaShLVsPt_Y2440->Draw("Lsame");

  //======================= Making histograms to smooth it ===================================//

  
  TH1D *HistUpsilonRaaShVsPt_Y2440 = new TH1D("HistUpsilonRaaShVsPt_Y2440","HistUpsilonRaaShVsPt_Y2440",50,0.0,50.0);
  TH1D *HistUpsilonRaaShUVsPt_Y2440 = new TH1D("HistUpsilonRaaShUVsPt_Y2440","HistUpsilonRaaShUVsPt_Y2440",50,0.0,50.0);
  TH1D *HistUpsilonRaaShLVsPt_Y2440 = new TH1D("HistUpsilonRaaShLVsPt_Y2440","HistUpsilonRaaShLVsPt_Y2440",50,0.0,50.0);
  
  for(int i=1;i<=HistUpsilonRaaShVsPt_Y2440->GetNbinsX();i++)
    {
    
      //HistUpsilonRaaShVsPt_Y2440->SetBinContent(i,UpsilonRaaShVsPt_Y2440[i-1]);
      //HistUpsilonRaaShUVsPt_Y2440->SetBinContent(i,UpsilonRaaShVsPt_Y2440U[i-1]);
      //HistUpsilonRaaShLVsPt_Y2440->SetBinContent(i,UpsilonRaaShVsPt_Y2440L[i-1]);
    
      HistUpsilonRaaShVsPt_Y2440->SetBinContent(i,grUpsilonRaaShVsPt_Y2440->Eval(HistUpsilonRaaShVsPt_Y2440->GetBinCenter(i)));
      HistUpsilonRaaShUVsPt_Y2440->SetBinContent(i,grUpsilonRaaShUVsPt_Y2440->Eval(HistUpsilonRaaShUVsPt_Y2440->GetBinCenter(i)));
      HistUpsilonRaaShLVsPt_Y2440->SetBinContent(i,grUpsilonRaaShLVsPt_Y2440->Eval(HistUpsilonRaaShLVsPt_Y2440->GetBinCenter(i)));

    }
  
  cout<<" Before Rebin : "<<endl;
 for(int i=1;i<=HistUpsilonRaaShVsPt_Y2440->GetNbinsX();i++)
    {
      cout<<HistUpsilonRaaShVsPt_Y2440->GetBinCenter(i)<<"            "<< HistUpsilonRaaShVsPt_Y2440->GetBinContent(i)<<endl;
    }




  HistUpsilonRaaShVsPt_Y2440->SetTitle("HistUpsilonRaaShVsPt_Y2440");
  HistUpsilonRaaShVsPt_Y2440->SetName("HistUpsilonRaaShVsPt_Y2440");
  HistUpsilonRaaShVsPt_Y2440->GetXaxis()->SetTitle("p_{T}^{#varUpsilon}");
  HistUpsilonRaaShVsPt_Y2440->GetYaxis()->SetTitle("R_{AA}^{Sh}");
  
  HistUpsilonRaaShUVsPt_Y2440->SetTitle("HistUpsilonRaaShUVsPt_Y2440");
  HistUpsilonRaaShUVsPt_Y2440->SetName("HistUpsilonRaaShUVsPt_Y2440");
  HistUpsilonRaaShUVsPt_Y2440->GetXaxis()->SetTitle("p_{T}^{#varUpsilon}");
  HistUpsilonRaaShUVsPt_Y2440->GetYaxis()->SetTitle("R_{AA}^{Sh}");
  
  HistUpsilonRaaShLVsPt_Y2440->SetTitle("HistUpsilonRaaShLVsPt_Y2440");
  HistUpsilonRaaShLVsPt_Y2440->SetName("HistUpsilonRaaShLVsPt_Y2440");
  HistUpsilonRaaShLVsPt_Y2440->GetXaxis()->SetTitle("p_{T}^{#varUpsilon}");
  HistUpsilonRaaShLVsPt_Y2440->GetYaxis()->SetTitle("R_{AA}^{Sh}");

  /*
  HistUpsilonRaaShVsPt_Y2440->Rebin(2);
  HistUpsilonRaaShUVsPt_Y2440->Rebin(2);
  HistUpsilonRaaShLVsPt_Y2440->Rebin(2);

  HistUpsilonRaaShVsPt_Y2440->Scale(1.0/2.0);
  HistUpsilonRaaShUVsPt_Y2440->Scale(1.0/2.0);
  HistUpsilonRaaShLVsPt_Y2440->Scale(1.0/2.0);

  HistUpsilonRaaShVsPt_Y2440->Smooth(40);
  HistUpsilonRaaShUVsPt_Y2440->Smooth(40);
  HistUpsilonRaaShLVsPt_Y2440->Smooth(40);
  
  
  cout<<" After Rebin : "<<endl;
  cout<<"JPsi Bin Centre: "<<"        "<<"Bin Content"<<endl;
      
  for(int i=1;i<=HistUpsilonRaaShVsPt_Y2440->GetNbinsX();i++)
    {
      cout<<HistUpsilonRaaShVsPt_Y2440->GetBinCenter(i)<<"            "<< HistUpsilonRaaShVsPt_Y2440->GetBinContent(i)<<endl;
    }
  */

  new TCanvas;
  HistUpsilonRaaShUVsPt_Y2440->Draw("PL");  
  HistUpsilonRaaShVsPt_Y2440->Draw("PLsame");
  HistUpsilonRaaShLVsPt_Y2440->Draw("PLsame");
  tb->DrawLatex(0.16,0.20,"2.4 #leq y #leq 4.0");
  gPad->SaveAs("Plots/UpsilonRaaShVsPt_Y2440.pdf");
  gPad->SaveAs("Plots/UpsilonRaaShVsPt_Y2440.png");
  gPad->SaveAs("Plots/UpsilonRaaShVsPt_Y2440.eps");


  
  Int_t UpsilonNNPt_Y21 = 49;
  
  Double_t UpsilonPt_Y21[100]={0.0};
  Double_t UpsilonRaaShVsPt_Y21[100]={0.0};
  Double_t UpsilonRaaShVsPt_Y21U[100]={0.0};
  Double_t UpsilonRaaShVsPt_Y21L[100]={0.0};
  
  ifstream filein8("InTextFiles/TempFiles/Temp_UpsilonShRaaVsPtInRap21.txt");
  for(int i=0; i<UpsilonNNPt_Y21; i++) 
    {
      filein8 >> UpsilonPt_Y21[i] >> UpsilonRaaShVsPt_Y21[i] >> UpsilonRaaShVsPt_Y21U[i] >> UpsilonRaaShVsPt_Y21L[i]; 
      
      cout<< UpsilonPt_Y21[i] <<"  "<< UpsilonRaaShVsPt_Y21[i] <<"  "<< UpsilonRaaShVsPt_Y21U[i] <<"  "<< UpsilonRaaShVsPt_Y21L[i]<<endl; 
      
    }
  
  
  TGraph *grUpsilonRaaShVsPt_Y21 = new TGraph(UpsilonNNPt_Y21, UpsilonPt_Y21, UpsilonRaaShVsPt_Y21);
  grUpsilonRaaShVsPt_Y21->SetName("grUpsilonRaaShVsPt_Y21");
  grUpsilonRaaShVsPt_Y21->SetTitle("grUpsilonRaaShVsPt_Y21");
  grUpsilonRaaShVsPt_Y21->SetLineWidth(2);
  grUpsilonRaaShVsPt_Y21->SetLineColor(2);
  grUpsilonRaaShVsPt_Y21->GetYaxis()->SetRangeUser(0.0,1.5);
  grUpsilonRaaShVsPt_Y21->GetXaxis()->SetTitle("p_{T}^{#varUpsilon}(GeV/c)");
  grUpsilonRaaShVsPt_Y21->GetYaxis()->SetTitle("R_{AA_{Sh}} ");
    

  TGraph *grUpsilonRaaShUVsPt_Y21 = new TGraph(UpsilonNNPt_Y21, UpsilonPt_Y21, UpsilonRaaShVsPt_Y21U);
  grUpsilonRaaShUVsPt_Y21->SetName("grUpsilonRaaShUVsPt_Y21");
  TGraph *grUpsilonRaaShLVsPt_Y21 = new TGraph(UpsilonNNPt_Y21, UpsilonPt_Y21, UpsilonRaaShVsPt_Y21L);
  grUpsilonRaaShLVsPt_Y21->SetName("grUpsilonRaaShLVsPt_Y21");



  new TCanvas;
  gPad->SetTicks();
  grUpsilonRaaShVsPt_Y21->Draw("AL");
  grUpsilonRaaShUVsPt_Y21->Draw("Lsame");
  grUpsilonRaaShLVsPt_Y21->Draw("Lsame");
  tb->DrawLatex(0.16,0.20,"|y| #leq 2.1");


  grUpsilonRaaShVsPt_Y21=SmoothGraph(grUpsilonRaaShVsPt_Y21,10);
  grUpsilonRaaShUVsPt_Y21=SmoothGraph(grUpsilonRaaShUVsPt_Y21,10);
  grUpsilonRaaShLVsPt_Y21=SmoothGraph(grUpsilonRaaShLVsPt_Y21,10);
  
  
  new TCanvas;
  gPad->SetTicks();
  grUpsilonRaaShUVsPt_Y21->Draw("AL");
  grUpsilonRaaShVsPt_Y21->SetLineColor(2);
  grUpsilonRaaShVsPt_Y21->Draw("Lsame");
  grUpsilonRaaShLVsPt_Y21->Draw("Lsame");
  
  //======================= Making histograms to smooth it ===================================//

  
  TH1D *HistUpsilonRaaShVsPt_Y21 = new TH1D("HistUpsilonRaaShVsPt_Y21","HistUpsilonRaaShVsPt_Y21",49,1.0,50.0);
  TH1D *HistUpsilonRaaShUVsPt_Y21 = new TH1D("HistUpsilonRaaShUVsPt_Y21","HistUpsilonRaaShUVsPt_Y21",49,1.0,50.0);
  TH1D *HistUpsilonRaaShLVsPt_Y21 = new TH1D("HistUpsilonRaaShLVsPt_Y21","HistUpsilonRaaShLVsPt_Y21",49,1.0,50.0);
  
  for(int i=1;i<=HistUpsilonRaaShVsPt_Y21->GetNbinsX();i++)
    {
    
      //HistUpsilonRaaShVsPt_Y21->SetBinContent(i,UpsilonRaaShVsPt_Y21[i-1]);
      //HistUpsilonRaaShUVsPt_Y21->SetBinContent(i,UpsilonRaaShVsPt_Y21U[i-1]);
      //HistUpsilonRaaShLVsPt_Y21->SetBinContent(i,UpsilonRaaShVsPt_Y21L[i-1]);
      
      HistUpsilonRaaShVsPt_Y21->SetBinContent(i,grUpsilonRaaShVsPt_Y21->Eval(HistUpsilonRaaShVsPt_Y21->GetBinCenter(i)));
      HistUpsilonRaaShUVsPt_Y21->SetBinContent(i,grUpsilonRaaShUVsPt_Y21->Eval(HistUpsilonRaaShUVsPt_Y21->GetBinCenter(i)));
      HistUpsilonRaaShLVsPt_Y21->SetBinContent(i,grUpsilonRaaShLVsPt_Y21->Eval(HistUpsilonRaaShLVsPt_Y21->GetBinCenter(i)));
      
    }
  
  cout<<" Before Rebin : "<<endl;
  for(int i=1;i<=HistUpsilonRaaShVsPt_Y21->GetNbinsX();i++)
    {
      cout<<HistUpsilonRaaShVsPt_Y21->GetBinCenter(i)<<"            "<< HistUpsilonRaaShVsPt_Y21->GetBinContent(i)<<endl;
    }

  HistUpsilonRaaShVsPt_Y21->SetTitle("HistUpsilonRaaShVsPt_Y21");
  HistUpsilonRaaShVsPt_Y21->SetName("HistUpsilonRaaShVsPt_Y21");
  HistUpsilonRaaShVsPt_Y21->GetXaxis()->SetTitle("p_{T}^{#varUpsilon}");
  HistUpsilonRaaShVsPt_Y21->GetYaxis()->SetTitle("R_{AA}^{Sh}");
  
  HistUpsilonRaaShUVsPt_Y21->SetTitle("HistUpsilonRaaShUVsPt_Y21");
  HistUpsilonRaaShUVsPt_Y21->SetName("HistUpsilonRaaShUVsPt_Y21");
  HistUpsilonRaaShUVsPt_Y21->GetXaxis()->SetTitle("p_{T}^{#varUpsilon}");
  HistUpsilonRaaShUVsPt_Y21->GetYaxis()->SetTitle("R_{AA}^{Sh}");
  
  HistUpsilonRaaShLVsPt_Y21->SetTitle("HistUpsilonRaaShLVsPt_Y21");
  HistUpsilonRaaShLVsPt_Y21->SetName("HistUpsilonRaaShLVsPt_Y21");
  HistUpsilonRaaShLVsPt_Y21->GetXaxis()->SetTitle("p_{T}^{#varUpsilon}");
  HistUpsilonRaaShLVsPt_Y21->GetYaxis()->SetTitle("R_{AA}^{Sh}");

  
  /*
  HistUpsilonRaaShVsPt_Y21->Rebin(2);
  HistUpsilonRaaShUVsPt_Y21->Rebin(2);
  HistUpsilonRaaShLVsPt_Y21->Rebin(2);

  HistUpsilonRaaShVsPt_Y21->Scale(1.0/2.0);
  HistUpsilonRaaShUVsPt_Y21->Scale(1.0/2.0);
  HistUpsilonRaaShLVsPt_Y21->Scale(1.0/2.0);

  HistUpsilonRaaShVsPt_Y21->Smooth(40);
  HistUpsilonRaaShUVsPt_Y21->Smooth(40);
  HistUpsilonRaaShLVsPt_Y21->Smooth(40);
  */
  
  cout<<" After Rebin : "<<endl;
  cout<<"JPsi Bin Centre: "<<"        "<<"Bin Content"<<endl;
      
  for(int i=1;i<=HistUpsilonRaaShVsPt_Y21->GetNbinsX();i++)
    {
      cout<<HistUpsilonRaaShVsPt_Y21->GetBinCenter(i)<<"            "<< HistUpsilonRaaShVsPt_Y21->GetBinContent(i)<<endl;
    }
  
  new TCanvas;
  HistUpsilonRaaShUVsPt_Y21->Draw("PL");  
  HistUpsilonRaaShVsPt_Y21->Draw("PLsame");
  HistUpsilonRaaShLVsPt_Y21->Draw("PLsame");
  gPad->SaveAs("Plots/UpsilonRaaShVsPt_Y21.pdf");
  gPad->SaveAs("Plots/UpsilonRaaShVsPt_Y21.png");
  gPad->SaveAs("Plots/UpsilonRaaShVsPt_Y21.eps");
  tb->DrawLatex(0.16,0.20,"|y| #leq 2.1");

  
  HistJpsiRaaShVsPt_Y1->Write();
  HistJpsiRaaShUVsPt_Y1->Write();
  HistJpsiRaaShLVsPt_Y1->Write();

  HistJpsiRaaShVsPt_Y2440->Write();
  HistJpsiRaaShUVsPt_Y2440->Write();
  HistJpsiRaaShLVsPt_Y2440->Write();

  HistJpsiRaaShVsPt_Y21->Write();
  HistJpsiRaaShUVsPt_Y21->Write();
  HistJpsiRaaShLVsPt_Y21->Write();
  
  
  HistUpsilonRaaShVsPt_Y1->Write();
  HistUpsilonRaaShUVsPt_Y1->Write();
  HistUpsilonRaaShLVsPt_Y1->Write();
  

  HistUpsilonRaaShVsPt_Y2440->Write();
  HistUpsilonRaaShUVsPt_Y2440->Write();
  HistUpsilonRaaShLVsPt_Y2440->Write();
  
  HistUpsilonRaaShVsPt_Y21->Write();
  HistUpsilonRaaShUVsPt_Y21->Write();
  HistUpsilonRaaShLVsPt_Y21->Write();

  //OutFile->Write();
  //OutFile->Close();


}


TGraph *SmoothGraph(TGraph *InGraph, Int_t N)
{
  TGraph *OutGraph;
  TGraphSmooth *grSmooth = new TGraphSmooth("grSmooth");
  OutGraph=grSmooth->SmoothSuper(InGraph,"",N);
  return OutGraph;
}
