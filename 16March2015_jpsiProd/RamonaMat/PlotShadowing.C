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

  TFile *OutFile =new TFile("Shadowing.root","Recreate");

  Int_t JpsiNNPt = 39;
  Double_t JpsiPt[100]={0.25,0.75,1.25,1.75,2.25,2.75,3.25,3.75,4.25,4.75,5.25,5.75,6.25,6.75,7.25,7.75,8.25,8.75,9.25,9.75,10.25,10.75,11.25,11.75,12.25
		    ,12.75,13.25,13.75,14.25,14.75,15.25,15.75,16.25,16.75,17.25,17.75,18.25,18.75,19.25,19.75};
  Double_t JpsiRaaShVsPt[100]={0.6582, 0.7488, 0.7926, 0.8896, 0.9150, 0.9576, 0.9852, 0.9929, 1.0206, 1.0290, 1.0314, 1.0175, 1.0533, 1.0525, 1.0399, 1.0164, 
		       1.0241, 1.0234, 1.0193, 1.0544, 1.0133, 1.0242, 1.0146, 0.9935, 1.0126, 0.9885, 0.9995, 0.9901, 1.0036, 0.9780, 0.9933, 0.9770, 
		       0.9810, 0.9497, 0.9771, 0.9984, 1.0358, 0.9507, 0.9315, 0.9819};
  Double_t JpsiRaaShVsPtU[100]={0.8606, 0.7488, 1.1658, 0.9846, 1.0305, 1.1000, 1.0158, 1.1478, 1.0558, 1.0844, 1.0371, 1.1083, 1.1108, 1.0992, 1.0789, 1.1944, 
		      1.0625, 1.0282, 1.0288, 1.0781, 1.0969, 1.1493, 1.0598, 1.0422, 1.0160, 1.0357, 1.0756, 1.0121, 1.0488, 1.1067, 1.0186, 0.9892, 
		      1.1820, 1.1278, 1.1103, 1.0352, 1.0463, 1.1037, 1.1140, 1.0477};
  Double_t JpsiRaaShVsPtL[100]={0.3671, 0.5741, 0.7812, 0.6967, 0.8744, 0.9102, 0.8580, 0.9743, 0.9400, 0.9850, 0.9266, 1.0020, 1.0236, 1.0308, 1.0205, 1.0164, 
		      0.9819, 0.9844, 0.9843, 0.9851, 1.0133, 1.0148, 0.9810, 0.9651, 0.9295, 0.9368, 0.9765, 0.9326, 0.9409, 0.9408, 0.9022, 0.8690, 
		      0.9810, 0.9239, 0.9456, 0.8732, 0.7331, 0.8756, 0.9025, 0.8686};



  TGraph *grJpsiRaaShVsPt = new TGraph(JpsiNNPt, JpsiPt, JpsiRaaShVsPt);
  grJpsiRaaShVsPt->SetName("grJpsiRaaShVsPt");
  grJpsiRaaShVsPt->SetTitle("grJpsiRaaShVsPt");
  grJpsiRaaShVsPt->SetLineWidth(2);
  grJpsiRaaShVsPt->SetLineColor(2);
  grJpsiRaaShVsPt->GetYaxis()->SetRangeUser(0.0,1.5);
  grJpsiRaaShVsPt->GetXaxis()->SetTitle("p_{T}^{j/#psi}(GeV/c)");
  grJpsiRaaShVsPt->GetYaxis()->SetTitle("R_{AA_{Sh}} ");
    

  TGraph *grJpsiRaaShUVsPt = new TGraph(JpsiNNPt, JpsiPt, JpsiRaaShVsPtU);
  grJpsiRaaShUVsPt->SetName("grJpsiRaaShUVsPt");
  TGraph *grJpsiRaaShLVsPt = new TGraph(JpsiNNPt, JpsiPt, JpsiRaaShVsPtL);
  grJpsiRaaShLVsPt->SetName("grJpsiRaaShLVsPt");



  TH1D *HistJpsiRaaShVsPt = new TH1D("HistJpsiRaaShVsPt","HistJpsiRaaShVsPt",40,0,20.0);
  TH1D *HistJpsiRaaShUVsPt = new TH1D("HistJpsiRaaShUVsPt","HistJpsiRaaShUVsPt",40,0,20.0);
  TH1D *HistJpsiRaaShLVsPt = new TH1D("HistJpsiRaaShLVsPt","HistJpsiRaaShLVsPt",40,0,20.0);

  for(int i=1;i<=HistJpsiRaaShVsPt->GetNbinsX();i++)
    {
      HistJpsiRaaShVsPt->SetBinContent(i,JpsiRaaShVsPt[i-1]);
      HistJpsiRaaShUVsPt->SetBinContent(i,JpsiRaaShVsPtU[i-1]);
      HistJpsiRaaShLVsPt->SetBinContent(i,JpsiRaaShVsPtL[i-1]);
    }

 
 
  //  HistJpsiRaaShVsPt->SetLineColor(2);
  
  HistJpsiRaaShVsPt->SetTitle("HistJpsiRaaShVsPt");
  HistJpsiRaaShVsPt->SetName("HistJpsiRaaShVsPt");
  HistJpsiRaaShVsPt->GetXaxis()->SetTitle("p_{T}^{J/#psi}");
  HistJpsiRaaShVsPt->GetYaxis()->SetTitle("R_{AA}^{Sh}");



  HistJpsiRaaShUVsPt->SetTitle("HistJpsiRaaShUVsPt");
  HistJpsiRaaShUVsPt->SetName("HistJpsiRaaShUVsPt");
  HistJpsiRaaShUVsPt->GetXaxis()->SetTitle("p_{T}^{J/#psi}");
  HistJpsiRaaShUVsPt->GetYaxis()->SetTitle("R_{AA}^{Sh}");



  HistJpsiRaaShLVsPt->SetTitle("HistJpsiRaaShLVsPt");
  HistJpsiRaaShLVsPt->SetName("HistJpsiRaaShLVsPt");
  HistJpsiRaaShLVsPt->GetXaxis()->SetTitle("p_{T}^{J/#psi}");
  HistJpsiRaaShLVsPt->GetYaxis()->SetTitle("R_{AA}^{Sh}");





  HistJpsiRaaShVsPt->Rebin(2);
  HistJpsiRaaShUVsPt->Rebin(2);
  HistJpsiRaaShLVsPt->Rebin(2);

  HistJpsiRaaShVsPt->Scale(1.0/2.0);
  HistJpsiRaaShUVsPt->Scale(1.0/2.0);
  HistJpsiRaaShLVsPt->Scale(1.0/2.0);

  HistJpsiRaaShVsPt->Smooth(40);
  HistJpsiRaaShUVsPt->Smooth(40);
  HistJpsiRaaShLVsPt->Smooth(40);

  cout<<"JPsi Bin Centre: "<<"        "<<"Bin Content"<<endl;
      
  for(int i=1;i<=HistJpsiRaaShVsPt->GetNbinsX();i++)
    {
      cout<<HistJpsiRaaShVsPt->GetBinCenter(i)<<"            "<< HistJpsiRaaShVsPt->GetBinContent(i)<<endl;
    }
  

  new TCanvas;
  HistJpsiRaaShUVsPt->Draw("PL");  
  HistJpsiRaaShVsPt->Draw("PLsame");
  HistJpsiRaaShLVsPt->Draw("PLsame");
  gPad->SaveAs("JpsiRaaShVsPt.pdf");
  gPad->SaveAs("JpsiRaaShVsPt.png");
  gPad->SaveAs("JpsiRaaShVsPt.eps");



  new TCanvas;
  gPad->SetTicks();
  grJpsiRaaShVsPt->Draw("AL");
  grJpsiRaaShUVsPt->Draw("Lsame");
  grJpsiRaaShLVsPt->Draw("Lsame");
  //gPad->SaveAs("JpsiRaaShVsPt.pdf");
  //gPad->SaveAs("JpsiRaaShVsPt.png");
  //gPad->SaveAs("JpsiRaaShVsPt.eps");
  
  //return;

  Int_t JpsiNNRap = 14;
  Double_t JpsiRap[100]={ 0.2500, 0.7500, 1.2500, 1.7500, 2.2500, 2.7500, 3.2500, 3.7500, 4.2500, 4.7500, 5.2500, 5.7500, 6.2500, 6.7500};
  Double_t JpsiRaaShVsRap[100]={0.8320, 0.8336, 0.8386, 0.8386, 0.8584, 0.8756, 0.9198, 0.9497, 0.9564, 0.9091, 0.8417, 0.7800, 0.6715, 0.7532};
  Double_t JpsiRaaShVsRapU[100]={0.9494, 0.9747, 0.9591, 0.9927, 0.9841, 1.0110, 1.0029, 0.9883, 1.0324, 1.0470, 0.9206, 0.9599, 0.8692, 0.8063};
  Double_t JpsiRaaShVsRapL[100]={0.6863, 0.7039, 0.7016, 0.7302, 0.7433, 0.7914, 0.8159, 0.8082, 0.9046, 0.8691, 0.7447, 0.6662, 0.4684, 0.2645};


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
  
  gPad->SaveAs("JpsiRaaShVsRap.pdf");
  gPad->SaveAs("JpsiRaaShVsRap.png");
  gPad->SaveAs("JpsiRaaShVsRap.eps");




  //========================== Shadowing with Upsilon ==========================================================================//

  Int_t UpsilonNNPtMid = 47;
  Double_t UpsilonPtMid[100]={2.5, 3.5, 4.5, 5.5, 6.5, 7.5, 8.5, 9.5, 10.5, 11.5, 12.5, 13.5, 14.5, 15.5, 16.5, 17.5, 18.5, 19.5, 20.5, 21.5, 22.5, 23.5, 
			      24.5, 25.5, 26.5, 27.5, 28.5, 29.5, 30.5, 31.5, 32.5, 33.5, 34.5, 35.5, 36.5, 37.5, 38.5, 39.5, 40.5, 41.5, 42.5, 43.5, 44.5, 
			      45.5, 46.5, 47.5, 48.5, 49.5};
  Double_t UpsilonRaaShVsPtMid[100]={0.7325, 0.9814, 1.1692, 1.2211, 1.1716, 1.1458, 1.1441, 1.1289, 1.1323, 1.1243, 1.1060, 1.1069, 1.1214, 1.1165, 1.1127, 
				     1.1172, 1.0992, 1.1060, 1.1175, 1.1438, 1.0812, 1.1100, 1.1058, 1.0999, 1.1119, 1.0806, 1.1198, 1.1039, 1.0781, 1.0931, 
				     1.0729, 1.1009, 1.1313, 1.1180, 1.0705, 1.0925, 1.0587, 1.1001, 1.1029, 1.0512, 1.1121, 1.0596, 1.0913, 1.0762, 1.0909, 
				     1.0805, 1.0622, 1.0421};
  Double_t UpsilonRaaShVsPtMidU[100]={0.7934, 1.0377, 1.2272, 1.2744, 1.2293, 1.1880, 1.1884, 1.1689, 1.1761, 1.1670, 1.1535, 1.1507, 1.1795, 1.1611, 1.1681, 
				      1.1620, 1.1486, 1.1496, 1.1625, 1.1739, 1.1687, 1.1586, 1.1512, 1.1678, 1.1520, 1.1487, 1.2033, 1.1626, 1.1496, 1.1450, 
				      1.1255, 1.1760, 1.1882, 1.1613, 1.1250, 1.1518, 1.1270, 1.1376, 1.1654, 1.1081, 1.1749, 1.1131, 1.1634, 1.1027, 1.1765, 
				      1.1172, 1.1430, 1.0807};
  Double_t UpsilonRaaShVsPtMidL[100]={0.6676, 0.9284, 1.1210, 1.1812, 1.1314, 1.1080, 1.1089, 1.0876, 1.0911, 1.0806, 1.0687, 1.0616, 1.0887, 1.0780, 1.0838, 
				      1.0647, 1.0458, 1.0686, 1.0782, 1.0502, 1.0612, 1.0707, 1.0525, 1.0787, 1.0564, 1.0341, 1.0849, 1.0666, 1.0457, 1.0421, 
				      1.0047, 1.0728, 1.0652, 1.0640, 1.0286, 1.0296, 1.0360, 1.0268, 1.0654, 1.0054, 1.0542, 1.0260, 1.0571, 1.0045, 1.0590, 
				      0.9877, 1.0286, 0.9307};



  TGraph *grUpsilonRaaShVsPtMid = new TGraph(UpsilonNNPtMid, UpsilonPtMid, UpsilonRaaShVsPtMid);
  grUpsilonRaaShVsPtMid->SetName("grUpsilonRaaShVsPtMid");
  grUpsilonRaaShVsPtMid->SetTitle("grUpsilonRaaShVsPtMid");
  grUpsilonRaaShVsPtMid->SetLineWidth(2);
  grUpsilonRaaShVsPtMid->SetLineColor(2);
  grUpsilonRaaShVsPtMid->GetYaxis()->SetRangeUser(0.0,1.5);
  grUpsilonRaaShVsPtMid->GetXaxis()->SetTitle("p_{T}^{#varUpsilon}(GeV/c)");
  grUpsilonRaaShVsPtMid->GetYaxis()->SetTitle("R_{AA_{Sh}} ");
    

  TGraph *grUpsilonRaaShUVsPtMid = new TGraph(UpsilonNNPtMid, UpsilonPtMid, UpsilonRaaShVsPtMidU);
  grUpsilonRaaShUVsPtMid->SetName("grUpsilonRaaShUVsPtMid"); 
  TGraph *grUpsilonRaaShLVsPtMid = new TGraph(UpsilonNNPtMid, UpsilonPtMid, UpsilonRaaShVsPtMidL);
  grUpsilonRaaShLVsPtMid->SetName("grUpsilonRaaShLVsPtMid"); 




  

  new TCanvas;
  gPad->SetTicks();
  grUpsilonRaaShVsPtMid->Draw("AL");
  grUpsilonRaaShUVsPtMid->Draw("Lsame");
  grUpsilonRaaShLVsPtMid->Draw("Lsame");
  //gPad->SaveAs("UpsilonRaaShVsPtMid.pdf");
  //gPad->SaveAs("UpsilonRaaShVsPtMid.png");
  //gPad->SaveAs("UpsilonRaaShVsPtMid.eps");



  TH1D *HistUpsilonRaaShVsPtMid = new TH1D("HistUpsilonRaaShVsPtMid","HistUpsilonRaaShVsPtMid",48,2,50.0);
  TH1D *HistUpsilonRaaShUVsPtMid = new TH1D("HistUpsilonRaaShUVsPtMid","HistUpsilonRaaShUVsPtMid",48,2,50.0);
  TH1D *HistUpsilonRaaShLVsPtMid = new TH1D("HistUpsilonRaaShLVsPtMid","HistUpsilonRaaShLVsPtMid",48,2,50.0);

  for(int i=1;i<=HistUpsilonRaaShVsPtMid->GetNbinsX();i++)
    {

      HistUpsilonRaaShVsPtMid->SetBinContent(i,UpsilonRaaShVsPtMid[i-1]);
      HistUpsilonRaaShUVsPtMid->SetBinContent(i,UpsilonRaaShVsPtMidU[i-1]);
      HistUpsilonRaaShLVsPtMid->SetBinContent(i,UpsilonRaaShVsPtMidL[i-1]);
      
  



    }
  
 
  HistUpsilonRaaShUVsPtMid->SetTitle("HistUpsilonRaaShUVsPtMid");
  HistUpsilonRaaShUVsPtMid->SetName("HistUpsilonRaaShUVsPtMid");
  HistUpsilonRaaShUVsPtMid->GetXaxis()->SetTitle("p_{T}^{#varUpsilon}");
  HistUpsilonRaaShUVsPtMid->GetYaxis()->SetTitle("R_{AA}^{Sh}(Mid)");


  HistUpsilonRaaShLVsPtMid->SetTitle("HistUpsilonRaaShLVsPtMid");
  HistUpsilonRaaShLVsPtMid->SetName("HistUpsilonRaaShLVsPtMid");
  HistUpsilonRaaShLVsPtMid->GetXaxis()->SetTitle("p_{T}^{#varUpsilon}");
  HistUpsilonRaaShLVsPtMid->GetYaxis()->SetTitle("R_{AA}^{Sh}(Mid)");
  

  HistUpsilonRaaShVsPtMid->SetTitle("HistUpsilonRaaShVsPtMid");
  HistUpsilonRaaShVsPtMid->SetName("HistUpsilonRaaShVsPtMid");
  HistUpsilonRaaShVsPtMid->GetXaxis()->SetTitle("p_{T}^{#varUpsilon}");
  HistUpsilonRaaShVsPtMid->GetYaxis()->SetTitle("R_{AA}^{Sh}(Mid)");





  HistUpsilonRaaShVsPtMid->Rebin(2);
  HistUpsilonRaaShUVsPtMid->Rebin(2);
  HistUpsilonRaaShLVsPtMid->Rebin(2);

  HistUpsilonRaaShVsPtMid->Scale(1.0/2.0);
  HistUpsilonRaaShUVsPtMid->Scale(1.0/2.0);
  HistUpsilonRaaShLVsPtMid->Scale(1.0/2.0);


  HistUpsilonRaaShUVsPtMid->Smooth(40);
  HistUpsilonRaaShVsPtMid->Smooth(40);
  HistUpsilonRaaShLVsPtMid->Smooth(40);

  cout<<" Mid rapidity Upsilon Bin Centre "<<"     "<<" bin content "<<endl;
  for(int i=1;i<=HistUpsilonRaaShVsPtMid->GetNbinsX();i++)
    {
      cout<<HistUpsilonRaaShVsPtMid->GetBinCenter(i)<<"  "<< HistUpsilonRaaShVsPtMid->GetBinContent(i)<<endl;
    }
  

  new TCanvas;
  HistUpsilonRaaShUVsPtMid->Draw("PL");  
  HistUpsilonRaaShVsPtMid->Draw("PLsame");
  HistUpsilonRaaShLVsPtMid->Draw("PLsame");

  gPad->SaveAs("UpsilonRaaShVsPtMid.pdf");
  gPad->SaveAs("UpsilonRaaShVsPtMid.png");
  gPad->SaveAs("UpsilonRaaShVsPtMid.eps");

  cout<<HistUpsilonRaaShVsPtMid->Interpolate(3)<<" interpolate "<<endl;

  //return;


  Int_t UpsilonNNPtFor = 47;
  Double_t UpsilonPtFor[100]={2.5, 3.5, 4.5, 5.5, 6.5, 7.5, 8.5, 9.5, 10.5, 11.5, 12.5, 13.5, 14.5, 15.5, 16.5, 17.5, 18.5, 19.5, 20.5, 21.5, 22.5, 23.5, 
			      24.5, 25.5, 26.5, 27.5, 28.5, 29.5, 30.5, 31.5, 32.5, 33.5, 34.5, 35.5, 36.5, 37.5, 38.5, 39.5, 40.5, 41.5, 42.5, 43.5, 44.5, 
			      45.5, 46.5, 47.5, 48.5, 49.5};
  Double_t UpsilonRaaShVsPtFor[100]={0.749588073, 0.939018798, 1.23414331, 1.37243751, 1.26140065, 1.21020283, 1.16753247, 1.15905707, 1.10106154, 1.08611336, 1.06680485, 
				     1.03013945, 1.15885167, 1.00753072, 1.08912167, 0.983012993, 1.08302294, 0.92442244, 0.985747487, 0.974486749, 0.956914893, 1.13263395, 
				     0.993426458, 1.10415934, 0.940695297, 0.910306099, 1.03724123, 0.891063515, 0.94824219, 0.979034423, 0.973466003, 1.03086233, 0.912688031, 
				     0.951786161, 0.86365343, 0.971247357, 0.938081415, 0.899217836, 0.9838135, 0.926533701, 0.733280166, 0.687583933, 0.955049132, 0.91581314, 
				     0.658167674, 0.761636989, 0.82565337, 0.8619891};
  Double_t UpsilonRaaShVsPtForU[100]={0.792898269, 0.960782109, 1.25885853, 1.38427586, 1.30166225, 1.23794292, 1.19581382, 1.18177729, 1.16233376, 1.11377117, 1.09027757, 1.11983596, 
				      1.16748771, 1.13076162, 1.16352455, 1.06500975, 1.14042116, 1.01022616, 1.08290372, 1.05765145, 1.13062155, 1.20894299, 1.07763292, 1.22835005, 
				      1.07074454, 1.05793045, 1.13656065, 1.09745244, 1.12944337, 1.0470116, 1.15963696, 1.16991377, 1.04425424, 1.08066786, 1.06056469, 1.08615941, 
				      1.26129103, 1.21294129, 1.065927, 1.22524897, 0.872050181, 0.771380737, 1.24507459, 1.21619744, 0.845253483, 1.09227517, 0.882915153, 1.23031392};
  Double_t UpsilonRaaShVsPtForL[100]={0.729536812, 0.874903447, 1.17538761, 1.34135556, 1.24482269, 1.19701694, 1.14005437, 1.1276816, 1.0852136, 1.02726516, 1.01619314, 0.999664485, 
				      1.01315879, 0.95627529, 1.01279731, 0.924568824, 1.00535664, 0.847093551, 0.890847313, 0.869626162, 0.866667494, 1.00241232, 0.91082284, 0.890152904, 
				      0.816141783, 0.887152553, 0.794929287, 0.796343547, 0.866527222, 0.765012611, 0.812553064, 0.828533361, 0.755570504, 0.759378778, 0.734118493, 
				      0.715929744, 0.721766274, 0.829395682, 0.553049146, 0.671805521, 0.602426957, 0.475134118, 0.664025006, 0.672235951, 0.491660635, 0.714483888, 
				      0.466871681, 0.70933221};



  TGraph *grUpsilonRaaShVsPtFor = new TGraph(UpsilonNNPtFor, UpsilonPtFor, UpsilonRaaShVsPtFor);
  grUpsilonRaaShVsPtFor->SetName("grUpsilonRaaShVsPtFor");
  grUpsilonRaaShVsPtFor->SetTitle("grUpsilonRaaShVsPtFor");
  grUpsilonRaaShVsPtFor->SetLineWidth(2);
  grUpsilonRaaShVsPtFor->SetLineColor(2);
  grUpsilonRaaShVsPtFor->GetYaxis()->SetRangeUser(0.0,1.5);
  grUpsilonRaaShVsPtFor->GetXaxis()->SetTitle("p_{T}^{#varUpsilon}(GeV/c)");
  grUpsilonRaaShVsPtFor->GetYaxis()->SetTitle("R_{AA_{Sh}} ");
    

  TGraph *grUpsilonRaaShUVsPtFor = new TGraph(UpsilonNNPtFor, UpsilonPtFor, UpsilonRaaShVsPtForU);
  grUpsilonRaaShUVsPtFor->SetName("grUpsilonRaaShUVsPtFor");
  TGraph *grUpsilonRaaShLVsPtFor = new TGraph(UpsilonNNPtFor, UpsilonPtFor, UpsilonRaaShVsPtForL);
  grUpsilonRaaShLVsPtFor->SetName("grUpsilonRaaShLVsPtFor");

  new TCanvas;
  gPad->SetTicks();
  grUpsilonRaaShVsPtFor->Draw("AL");
  grUpsilonRaaShUVsPtFor->Draw("Lsame");
  grUpsilonRaaShLVsPtFor->Draw("Lsame");
  //gPad->SaveAs("UpsilonRaaShVsPtFor.pdf");
  // gPad->SaveAs("UpsilonRaaShVsPtFor.png");
  //gPad->SaveAs("UpsilonRaaShVsPtFor.eps");




  //=============================== Make Histogramm ===============================//
  TH1D *HistUpsilonRaaShVsPtFor = new TH1D("HistUpsilonRaaShVsPtFor","HistUpsilonRaaShVsPtFor",48,2,50.0);
  TH1D *HistUpsilonRaaShUVsPtFor = new TH1D("HistUpsilonRaaShUVsPtFor","HistUpsilonRaaShUVsPtFor",48,2,50.0);
  TH1D *HistUpsilonRaaShLVsPtFor = new TH1D("HistUpsilonRaaShLVsPtFor","HistUpsilonRaaShLVsPtFor",48,2,50.0);

  for(int i=1;i<=HistUpsilonRaaShVsPtFor->GetNbinsX();i++)
    {

      HistUpsilonRaaShVsPtFor->SetBinContent(i,UpsilonRaaShVsPtFor[i-1]);
      HistUpsilonRaaShUVsPtFor->SetBinContent(i,UpsilonRaaShVsPtForU[i-1]);
      HistUpsilonRaaShLVsPtFor->SetBinContent(i,UpsilonRaaShVsPtForL[i-1]);
      cout<<HistUpsilonRaaShVsPtFor->GetBinCenter(i)<<"  "<< HistUpsilonRaaShVsPtFor->GetBinContent(i)<<endl;
    }


  
  HistUpsilonRaaShVsPtFor->Rebin(2);
  HistUpsilonRaaShUVsPtFor->Rebin(2);
  HistUpsilonRaaShLVsPtFor->Rebin(2);


  HistUpsilonRaaShVsPtFor->Scale(1.0/2.0);
  HistUpsilonRaaShUVsPtFor->Scale(1.0/2.0);
  HistUpsilonRaaShLVsPtFor->Scale(1.0/2.0);


  HistUpsilonRaaShUVsPtFor->Smooth(40);
  HistUpsilonRaaShVsPtFor->Smooth(40);
  HistUpsilonRaaShLVsPtFor->Smooth(40);

  HistUpsilonRaaShUVsPtFor->SetTitle("HistUpsilonRaaShUVsPtFor");
  HistUpsilonRaaShUVsPtFor->SetName("HistUpsilonRaaShUVsPtFor");
  HistUpsilonRaaShUVsPtFor->GetXaxis()->SetTitle("p_{T}^{#varUpsilon}");
  HistUpsilonRaaShUVsPtFor->GetYaxis()->SetTitle("R_{AA}^{Sh}(For)");



  HistUpsilonRaaShLVsPtFor->SetTitle("HistUpsilonRaaShLVsPtFor");
  HistUpsilonRaaShLVsPtFor->SetName("HistUpsilonRaaShLVsPtFor");
  HistUpsilonRaaShLVsPtFor->GetXaxis()->SetTitle("p_{T}^{#varUpsilon}");
  HistUpsilonRaaShLVsPtFor->GetYaxis()->SetTitle("R_{AA}^{Sh}(For)");
  

  HistUpsilonRaaShVsPtFor->SetTitle("HistUpsilonRaaShVsPtFor");
  HistUpsilonRaaShVsPtFor->SetName("HistUpsilonRaaShVsPtFor");
  HistUpsilonRaaShVsPtFor->GetXaxis()->SetTitle("p_{T}^{#varUpsilon}");
  HistUpsilonRaaShVsPtFor->GetYaxis()->SetTitle("R_{AA}^{Sh}(For)");
  


  cout<<" For rapidity Upsilon Bin Centre "<<"     "<<" bin content "<<endl;

    for(int i=1;i<=HistUpsilonRaaShVsPtFor->GetNbinsX();i++)
      {
	cout<<HistUpsilonRaaShVsPtFor->GetBinCenter(i)<<"  "<< HistUpsilonRaaShVsPtFor->GetBinContent(i)<<endl;
      }



  new TCanvas;
  HistUpsilonRaaShUVsPtFor->Draw("PL");  
  HistUpsilonRaaShVsPtFor->Draw("PLsame");
  HistUpsilonRaaShLVsPtFor->Draw("PLsame");

  gPad->SaveAs("UpsilonRaaShVsPtFor.pdf");
  gPad->SaveAs("UpsilonRaaShVsPtFor.png");
  gPad->SaveAs("UpsilonRaaShVsPtFor.eps");



  //return;
  /*
  Int_t UpsilonNNRap = 21;
  Double_t UpsilonRap[100]={-5.25, -4.75, -4.25, -3.75, -3.25, -2.75, -2.25, -1.75, -1.25, -0.75, -0.25, 0.25, 0.75, 1.25, 1.75, 2.25, 2.75, 3.25, 3.75, 4.25, 4.75, 5.25};
  Double_t UpsilonRaaShVsRap[100]={0.605213613, 0.797513812, 0.859806762, 0.954254796, 0.969441212, 1.032, 1.01947837, 1.00551939, 0.988928484, 0.96019842, 0.958617498, 
				   0.958617498, 0.96019842, 0.988928484, 1.00551939, 1.01947837, 1.032, 0.969441212, 0.954254796, 0.859806762, 0.797513812, 0.605301275};
  Double_t UpsilonRaaShVsRapU[100]={0.893381094, 1.02454934, 0.960270715, 1.0011311, 1.00034727, 1.07081343, 1.08146511, 1.06249615, 1.05838769, 1.02942724, 1.02907934, 
				    1.02916378, 1.02934145, 1.05838769, 1.06252567, 1.08150795, 1.070742, 1.00034727, 1.0011311, 0.960274105, 1.02454934, 0.893510496};
  Double_t UpsilonRaaShVsRapL[100]={0.328129918, 0.570120437, 0.747823669, 0.892722104, 0.936362812, 0.986280394, 0.978952858, 0.951182932, 0.925979972, 0.89546438, 
				    0.886632023, 0.886632023, 0.895443484, 0.925979972, 0.951182932, 0.978948153, 0.986228075, 0.936362812, 0.892722104, 0.747805912, 
				    0.570120437, 0.328311135};


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
  gPad->SaveAs("UpsilonRaaShVsRap.pdf");
  gPad->SaveAs("UpsilonRaaShVsRap.png");
  gPad->SaveAs("UpsilonRaaShVsRap.eps");
  */



  /*
  grJpsiRaaShVsPt->Write();
  grJpsiRaaShUVsPt->Write();
  grJpsiRaaShLVsPt->Write();
  grJpsiRaaShVsRap->Write();
  grJpsiRaaShUVsRap->Write();
  grJpsiRaaShLVsRap->Write();
  grUpsilonRaaShVsPtMid->Write();
  grUpsilonRaaShUVsPtMid->Write();
  grUpsilonRaaShLVsPtMid->Write();
  grUpsilonRaaShVsPtFor->Write();
  grUpsilonRaaShUVsPtFor->Write();
  grUpsilonRaaShLVsPtFor->Write();
 
  //grUpsilonRaaShVsRap->Write();
  //grUpsilonRaaShUVsRap->Write();
  //grUpsilonRaaShLVsRap->Write();
  */
  
  
  HistJpsiRaaShVsPt->Write();
  HistJpsiRaaShUVsPt->Write();
  HistJpsiRaaShLVsPt->Write();
  
  HistUpsilonRaaShVsPtMid->Write();
  HistUpsilonRaaShUVsPtMid->Write();
  HistUpsilonRaaShLVsPtMid->Write();
  
  HistUpsilonRaaShVsPtFor->Write();
  HistUpsilonRaaShUVsPtFor->Write();
  HistUpsilonRaaShLVsPtFor->Write();
    
  //OutFile->Write();
  //OutFile->Close();


}
