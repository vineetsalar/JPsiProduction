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


// Dynamics 
Double_t Npart(int BinLow, int BinHigh);
Double_t NColl(int BinLow, int BinHigh);
Double_t TAA(int BinLow, int BinHigh);
Double_t ImpactPara(Int_t BinLow, Int_t BinHigh);

//Shadowing Grphs
Double_t ShVsX(Double_t x, Double_t ShMB);

Double_t CNMVsPtInt(Double_t PtMin, Double_t PtMax, Double_t PtStep, TH1D *HistPt, TH1D *HistSh);




//================================================================================================//
// Jpsi pT from Pythia
TFile *filejpsi=new TFile("../../JPsiPt.root","R");
TH1D *Jpsi_Pt = (TH1D*)filejpsi->Get("diMuonsPt_Gen");

TFile *fileUpsilon=new TFile("../../dimuonGenPt1s2sPbPb_Pt.root","R");
TH1D *Y1S_Pt = (TH1D*)fileUpsilon->Get("diMuonsPt_Gen1S");
TH1D *Y2S_Pt = (TH1D*)fileUpsilon->Get("diMuonsPt_Gen2S");

//================================== Shadowing from root file ==========================//
TFile *fileShadowing = new TFile("17042015_Shadowing.root","R");

TH1D *HistJpsiRaaShVsPt = (TH1D*)fileShadowing->Get("HistJpsiRaaShVsPt");
TH1D *HistJpsiRaaShUVsPt = (TH1D*)fileShadowing->Get("HistJpsiRaaShUVsPt");
TH1D *HistJpsiRaaShLVsPt = (TH1D*)fileShadowing->Get("HistJpsiRaaShLVsPt");


TH1D *HistUpsilonRaaShVsPtMid = (TH1D*)fileShadowing->Get("HistUpsilonRaaShVsPtMid");
TH1D *HistUpsilonRaaShLVsPtMid = (TH1D*)fileShadowing->Get("HistUpsilonRaaShLVsPtMid");
TH1D *HistUpsilonRaaShUVsPtMid = (TH1D*)fileShadowing->Get("HistUpsilonRaaShUVsPtMid");

TH1D *HistUpsilonRaaShVsPtFor = (TH1D*)fileShadowing->Get("HistUpsilonRaaShVsPtFor");
TH1D *HistUpsilonRaaShLVsPtFor = (TH1D*)fileShadowing->Get("HistUpsilonRaaShLVsPtFor");
TH1D *HistUpsilonRaaShUVsPtFor = (TH1D*)fileShadowing->Get("HistUpsilonRaaShUVsPtFor");


void GlauberCalc()
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


  TFile *OutFile = new TFile("ShawQuarkonia.root","RECREATE");

// ====================  Npart vs Ncoll graphs =========================================
  Double_t NPartVal[50];
  Double_t NCollVal[50];
  Double_t BVal[50];
  Double_t RMinusBVal[50];
  Double_t RootNPartVal[50];
  Double_t NCollByNPartVal[50];

  Double_t ElipseAreaVal[50]={0.0};


  Double_t AA = 208.0;
  Double_t RR = 1.2 * TMath::Power(AA,1.0/3.0);

  for(int i=0;i<40;i++){

    NPartVal[i]=Npart(i,i+1);

    //NCollVal[i]=(10.0-(NColl(i,i+1)/(0.5*NPartVal[i])))/8.75;

    NCollVal[i]=(NColl(i,i+1)/(0.5*NPartVal[i]));

    BVal[i]=ImpactPara(i,i+1);

    RMinusBVal[i]= RR - 0.5*ImpactPara(i,i+1);
    
    RootNPartVal[i]=TMath::Sqrt(NPartVal[i]);
    
    NCollByNPartVal[i]=2.0*NCollVal[i]/NPartVal[i];
    
    if(RR > ImpactPara(i,i+1) /2)ElipseAreaVal[i]= pi*RMinusBVal[i]*TMath::Sqrt( RR*RR - 0.25*ImpactPara(i,i+1)*ImpactPara(i,i+1));
  }
  


 
  TGraph *grbVsNPart = new TGraph(40, BVal, NPartVal);
  grbVsNPart->SetLineWidth(2);
  grbVsNPart->SetMarkerStyle(20);
  grbVsNPart->GetXaxis()->SetTitle("b(fm)");
  grbVsNPart->GetYaxis()->SetTitle("N_{Part}");
  
  new TCanvas;
  grbVsNPart->Draw("AP");

  TGraph *grbVsNColl = new TGraph(40, BVal, NCollVal);
  grbVsNColl->SetLineWidth(2);
  grbVsNColl->SetMarkerStyle(20);
  grbVsNColl->GetXaxis()->SetTitle("b(fm)");
  grbVsNColl->GetYaxis()->SetTitle("N_{Coll}");
  
  new TCanvas;
  grbVsNColl->Draw("AP");


  TGraph *grbVsNCollByNPart = new TGraph(40, BVal, NCollByNPartVal);
  grbVsNCollByNPart->SetLineWidth(2);
  grbVsNCollByNPart->SetMarkerStyle(20);
  grbVsNCollByNPart->GetXaxis()->SetTitle("b(fm)");
  grbVsNCollByNPart->GetYaxis()->SetTitle("N_{Coll}/(N_{Part}/2)");
  
  new TCanvas;
  grbVsNCollByNPart->Draw("AP");



  TGraph *grRMinusBVsNPart = new TGraph(40, RMinusBVal, RootNPartVal);
  grRMinusBVsNPart->SetLineWidth(2);
  grRMinusBVsNPart->SetMarkerStyle(20);
  grRMinusBVsNPart->GetXaxis()->SetTitle("R-b/2(fm)");
  grRMinusBVsNPart->GetYaxis()->SetTitle("N_{Part}^{1/2}");
  
  new TCanvas;
  grRMinusBVsNPart->Draw("AP");


  TGraph *grAreaVsNPart = new TGraph(40, ElipseAreaVal, NPartVal);
  grAreaVsNPart->SetLineWidth(2);
  grAreaVsNPart->SetMarkerStyle(20);
  grAreaVsNPart->GetXaxis()->SetTitle("#sigma_{ab}");
  grAreaVsNPart->GetYaxis()->SetTitle("N_{Part}");
  
  new TCanvas;
  grAreaVsNPart->Draw("AP");


  TGraph *grAreaVsNColl = new TGraph(40, ElipseAreaVal, NCollVal);
  grAreaVsNColl->SetLineWidth(2);
  grAreaVsNColl->SetMarkerStyle(20);
  grAreaVsNColl->GetXaxis()->SetTitle("#sigma_{ab}");
  grAreaVsNColl->GetYaxis()->SetTitle("N_{Coll}");
  
  new TCanvas;
  grAreaVsNColl->Draw("AP");



  
  TGraph *grNPartVsNColl = new TGraph(40, NPartVal,NCollVal);
  grNPartVsNColl->SetLineWidth(2);
  grNPartVsNColl->SetMarkerStyle(20);
  grNPartVsNColl->GetXaxis()->SetTitle("N_{Part}");
  grNPartVsNColl->GetYaxis()->SetTitle("N_{Coll}/(N_{Part}/2)");
  
  
  TF1 *fa1 = new TF1("fa1","pol4",0.1,500.0);
  grNPartVsNColl->Fit("fa1","M","",1.0,400.0);
  fa1->SetLineColor(2);
  

  new TCanvas;
  gPad->SetTicks();
  grNPartVsNColl->Draw("AP");
  fa1->Draw("same");

  //========================================= Shadowing ========================//
 // j/psi pT histogram  
  cout << "J/psi hist Integral = " << Jpsi_Pt->Integral() << endl;
  cout<<Jpsi_Pt->GetMean()<<"   "<<Jpsi_Pt->GetRMS()<<"  "<<Jpsi_Pt->GetSize()<<"  "<<Jpsi_Pt->FindBin(6.5)<<"  "<<Jpsi_Pt->GetBinWidth(1)<<endl;
  
  Jpsi_Pt->Rebin(5); 
  
  cout << "J/psi hist Integral = " << Jpsi_Pt->Integral() << endl;
  cout<<Jpsi_Pt->GetMean()<<"   "<<Jpsi_Pt->GetRMS()<<"  "<<Jpsi_Pt->GetSize()<<"  "<<Jpsi_Pt->FindBin(6.5)<<"  "<<Jpsi_Pt->GetBinWidth(1)<<endl;
  
  for(int i=0;i<Jpsi_Pt->GetSize();i++)
    {
      cout<<" Jpsi Bin Centre "<<Jpsi_Pt->GetBinCenter(i)<<endl;
    }


  Y1S_Pt->Rebin(20); 
  cout << "Y1S hist Integral = " << Y1S_Pt->Integral() << endl;
  cout<<Y1S_Pt->GetMean()<<"   "<<Y1S_Pt->GetRMS()<<"  "<<Y1S_Pt->GetSize()<<"  "<<Y1S_Pt->FindBin(6.5)<<"  "<<Y1S_Pt->GetBinWidth(1)<<endl;
  

  Y2S_Pt->Rebin(20); 
  cout << "Y2S hist Integral = " << Y2S_Pt->Integral() << endl;
  cout<<Y2S_Pt->GetMean()<<"   "<<Y2S_Pt->GetRMS()<<"  "<<Y2S_Pt->GetSize()<<"  "<<Y2S_Pt->FindBin(6.5)<<"  "<<Y2S_Pt->GetBinWidth(1)<<endl;
 


  for(int i=0;i<HistUpsilonRaaShVsPtMid->GetSize();i++)
    {
      cout<<" Upsilon Bin Centre "<<HistUpsilonRaaShVsPtMid->GetBinCenter(i)<<endl;
    }

  for(int i=0;i<Y1S_Pt->GetSize();i++)
    {
      cout<<" Upsilon Pt Bin Centre "<<Y1S_Pt->GetBinCenter(i)<<endl;
    }



  //========= Shadowing from Ramona Calculations ==================//
  
  //======================== Find Min Bias Value =================//

  //new TCanvas;
  //HistJpsiRaaShVsPt->Draw();
    
    //PtMin=0.25; ALICE
    //PtMin=6.25; CMS
    
    //Double_t Ptmax=0;
    //if(isUps==0)Ptmax=20.75;
    //if(isUps==1 || isUps ==2)Ptmax=40.25;


  cout<<" Value of integrated shadowing: Jpsi "<< "ALICE    "<<"     "<< "CMS  "<<endl;
  cout<<"                                     "<< CNMVsPtInt(0.25,20.75, 0.5, Jpsi_Pt, HistJpsiRaaShUVsPt)<<"      "<<CNMVsPtInt(6.25,20.75, 0.5, Jpsi_Pt, HistJpsiRaaShUVsPt)<<endl;
  cout<<"                                     "<< CNMVsPtInt(0.25,20.75, 0.5, Jpsi_Pt, HistJpsiRaaShVsPt)<<"      "<<CNMVsPtInt(6.25,20.75, 0.5, Jpsi_Pt, HistJpsiRaaShVsPt)<<endl;
  cout<<"                                     "<< CNMVsPtInt(0.25,20.75, 0.5, Jpsi_Pt, HistJpsiRaaShLVsPt)<<"      "<<CNMVsPtInt(6.25,20.75, 0.5, Jpsi_Pt, HistJpsiRaaShLVsPt)<<endl;



  cout<<" Value of integrated shadowing: Y "<< "ALICE    "<<"     "<< "CMS  "<<endl;
  cout<<"                                  "<< CNMVsPtInt(1.0, 37.0, 2.0, Y1S_Pt, HistUpsilonRaaShUVsPtFor)<<"      "<<CNMVsPtInt(1.0, 37.0, 2.0, Y1S_Pt, HistUpsilonRaaShUVsPtMid) <<endl;
  cout<<"                                  "<< CNMVsPtInt(1.0, 37.0, 2.0, Y1S_Pt, HistUpsilonRaaShVsPtFor)<<"      "<<CNMVsPtInt(1.0, 37.0, 2.0, Y1S_Pt, HistUpsilonRaaShVsPtMid) <<endl;
  cout<<"                                  "<< CNMVsPtInt(1.0, 37.0, 2.0, Y1S_Pt, HistUpsilonRaaShLVsPtFor)<<"      "<<CNMVsPtInt(1.0, 37.0, 2.0, Y1S_Pt, HistUpsilonRaaShLVsPtMid) <<endl;
  


  cout<<" ======================== YYY =================================="<<endl;
  for(int i =1;i<Y1S_Pt->GetNbinsX();i++)
    {
      cout<<Y1S_Pt->GetBinCenter(i)<<"    "<<HistUpsilonRaaShVsPtMid->GetBinCenter(i)<<endl;
    }
 
  //====================================== Bands for Shadowing vs Pt Graphs ============================//
  
  Int_t NNPtALICE = 21;
  Double_t ShALICEPt[25];
  Double_t ShUALICEPt[25];
  Double_t ShLALICEPt[25];
  Double_t PtALICE[25]={0.25,0.75,1.25,1.75,2.25,2.75,3.25,3.75,4.25,4.75,5.25,5.75,6.25,6.75,7.25,7.75,8.25,8.75,9.25,9.75,10.25};
  
  for(int i=0; i<NNPtALICE; i++) 
    {
      ShALICEPt[i]=HistJpsiRaaShVsPt->Interpolate(PtALICE[i]);  
      ShUALICEPt[i]=HistJpsiRaaShUVsPt->Interpolate(PtALICE[i]);  
      ShLALICEPt[i]=HistJpsiRaaShLVsPt->Interpolate(PtALICE[i]);  
    }
  
  
  
  TGraph *grShJPsiVsPtALICE = new TGraph(NNPtALICE,PtALICE,ShALICEPt);
  grShJPsiVsPtALICE->SetName("grShJPsiVsPtALICE");
  grShJPsiVsPtALICE->SetTitle("grShJPsiVsPtALICE");
  grShJPsiVsPtALICE->SetLineWidth(2);
  grShJPsiVsPtALICE->SetLineColor(1);
  grShJPsiVsPtALICE->SetLineStyle(1);
  grShJPsiVsPtALICE->GetXaxis()->SetTitle("p_{T}(GeV/c)");
  grShJPsiVsPtALICE->GetYaxis()->SetTitle("R_{AA}^{Shadowing}");
  grShJPsiVsPtALICE->GetYaxis()->SetRangeUser(0.0,1.2);




  TGraph *grShUJPsiVsPtALICE = new TGraph(NNPtALICE,PtALICE,ShUALICEPt);
  grShUJPsiVsPtALICE->SetName("grShUJPsiVsPtALICE");
  grShUJPsiVsPtALICE->SetTitle("grShUJPsiVsPtALICE");
  grShUJPsiVsPtALICE->SetLineWidth(2);
  grShUJPsiVsPtALICE->SetLineColor(1);
  grShUJPsiVsPtALICE->SetLineStyle(1);
  grShUJPsiVsPtALICE->GetXaxis()->SetTitle("p_{T}(GeV/c)");
  grShUJPsiVsPtALICE->GetYaxis()->SetTitle("R_{AA}^{Shadowing}");
  grShUJPsiVsPtALICE->GetYaxis()->SetRangeUser(0.0,1.2);


 TGraph *grShLJPsiVsPtALICE = new TGraph(NNPtALICE,PtALICE,ShLALICEPt);
  grShLJPsiVsPtALICE->SetName("grShLJPsiVsPtALICE");
  grShLJPsiVsPtALICE->SetTitle("grShLJPsiVsPtALICE");
  grShLJPsiVsPtALICE->SetLineWidth(2);
  grShLJPsiVsPtALICE->SetLineColor(1);
  grShLJPsiVsPtALICE->SetLineStyle(1);
  grShLJPsiVsPtALICE->GetXaxis()->SetTitle("p_{T}(GeV/c)");
  grShLJPsiVsPtALICE->GetYaxis()->SetTitle("R_{AA}^{Shadowing}");
  grShLJPsiVsPtALICE->GetYaxis()->SetRangeUser(0.0,1.2);




  TGraph *grShJPsiVsPtALICE_Shade = new TGraph(2*NNPtALICE);

  for(Int_t i=0;i<NNPtALICE;i++)
    {
      //HistJpsiRaaShVsPt_Shade->SetPoint(i,NPartValSh[i],ShJPsiU[i]);
      //HistJpsiRaaShVsPt_Shade->SetPoint(Nxx+i,NPartValSh[Nxx-i-1],ShJPsiL[Nxx-i-1]);
      grShJPsiVsPtALICE_Shade->SetPoint(i,PtALICE[i],ShUALICEPt[i]);
      grShJPsiVsPtALICE_Shade->SetPoint(NNPtALICE+i,PtALICE[NNPtALICE-i-1],ShLALICEPt[NNPtALICE-i-1]);
    }
  
  grShJPsiVsPtALICE_Shade->GetXaxis()->SetTitle("p_{T}");
  grShJPsiVsPtALICE_Shade->GetYaxis()->SetTitle("R_{AA}^{Sh}(J/#psi)");
  grShJPsiVsPtALICE_Shade->GetYaxis()->SetRangeUser(0.0,1.5);
  grShJPsiVsPtALICE_Shade->SetName("grShJPsiVsPtALICE_Shade");
  grShJPsiVsPtALICE_Shade->SetTitle("grShJPsiVsPtALICE_Shade");


  new TCanvas;
  gPad->SetTicks();
  grShJPsiVsPtALICE_Shade->SetFillStyle(3013);
  grShJPsiVsPtALICE_Shade->SetFillColor(16);
  grShJPsiVsPtALICE_Shade->Draw("Af");
  grShJPsiVsPtALICE->Draw("CSame");
  grShUJPsiVsPtALICE->Draw("lSame");
  grShLJPsiVsPtALICE->Draw("lSame");





  Int_t NNPtCMS = 59;
  Double_t ShCMSPt[100];
  Double_t ShUCMSPt[100];
  Double_t ShLCMSPt[100];
  Double_t PtCMS[100]={0.25,0.75,1.25,1.75,2.25,2.75,3.25,3.75,4.25,4.75,5.25,5.75,6.25,6.75,7.25,7.75,8.25,8.75,
  		       9.25,9.75,10.25,10.75,11.25,11.75,12.25,12.75,13.25,13.75,14.25,14.75,15.25,15.75,16.25,
  		       16.75,17.25,17.75,18.25,18.75,19.25,19.75,20.25,20.75,21.25,21.75,22.25,22.75,23.25,23.75,
  		       24.25,24.75,25.25,25.75,26.25,26.75,27.25,27.75,28.25,28.75,29.25,29.75,30.25,30.75};
  
  for(int i=0; i<NNPtCMS; i++) 
    {
      ShCMSPt[i]=HistJpsiRaaShVsPt->Interpolate(PtCMS[i]);  
      ShUCMSPt[i]=HistJpsiRaaShUVsPt->Interpolate(PtCMS[i]);  
      ShLCMSPt[i]=HistJpsiRaaShLVsPt->Interpolate(PtCMS[i]);  
    }
  
  
  
  TGraph *grShJPsiVsPtCMS = new TGraph(NNPtCMS,PtCMS,ShCMSPt);
  grShJPsiVsPtCMS->SetName("grShJPsiVsPtCMS");
  grShJPsiVsPtCMS->SetTitle("grShJPsiVsPtCMS");
  grShJPsiVsPtCMS->SetLineWidth(2);
  grShJPsiVsPtCMS->SetLineColor(1);
  grShJPsiVsPtCMS->SetLineStyle(1);
  grShJPsiVsPtCMS->GetXaxis()->SetTitle("p_{T}(GeV/c)");
  grShJPsiVsPtCMS->GetYaxis()->SetTitle("R_{AA}^{Shadowing}");
  grShJPsiVsPtCMS->GetYaxis()->SetRangeUser(0.0,1.2);




  TGraph *grShUJPsiVsPtCMS = new TGraph(NNPtCMS,PtCMS,ShUCMSPt);
  grShUJPsiVsPtCMS->SetName("grShUJPsiVsPtCMS");
  grShUJPsiVsPtCMS->SetTitle("grShUJPsiVsPtCMS");
  grShUJPsiVsPtCMS->SetLineWidth(2);
  grShUJPsiVsPtCMS->SetLineColor(1);
  grShUJPsiVsPtCMS->SetLineStyle(1);
  grShUJPsiVsPtCMS->GetXaxis()->SetTitle("p_{T}(GeV/c)");
  grShUJPsiVsPtCMS->GetYaxis()->SetTitle("R_{AA}^{Shadowing}");
  grShUJPsiVsPtCMS->GetYaxis()->SetRangeUser(0.0,1.2);


 TGraph *grShLJPsiVsPtCMS = new TGraph(NNPtCMS,PtCMS,ShLCMSPt);
  grShLJPsiVsPtCMS->SetName("grShLJPsiVsPtCMS");
  grShLJPsiVsPtCMS->SetTitle("grShLJPsiVsPtCMS");
  grShLJPsiVsPtCMS->SetLineWidth(2);
  grShLJPsiVsPtCMS->SetLineColor(1);
  grShLJPsiVsPtCMS->SetLineStyle(1);
  grShLJPsiVsPtCMS->GetXaxis()->SetTitle("p_{T}(GeV/c)");
  grShLJPsiVsPtCMS->GetYaxis()->SetTitle("R_{AA}^{Shadowing}");
  grShLJPsiVsPtCMS->GetYaxis()->SetRangeUser(0.0,1.2);




  TGraph *grShJPsiVsPtCMS_Shade = new TGraph(2*NNPtCMS);

  for(Int_t i=0;i<NNPtCMS;i++)
    {
      //HistJpsiRaaShVsPt_Shade->SetPoint(i,NPartValSh[i],ShJPsiU[i]);
      //HistJpsiRaaShVsPt_Shade->SetPoint(Nxx+i,NPartValSh[Nxx-i-1],ShJPsiL[Nxx-i-1]);
      grShJPsiVsPtCMS_Shade->SetPoint(i,PtCMS[i],ShUCMSPt[i]);
      grShJPsiVsPtCMS_Shade->SetPoint(NNPtCMS+i,PtCMS[NNPtCMS-i-1],ShLCMSPt[NNPtCMS-i-1]);
    }
  
  grShJPsiVsPtCMS_Shade->GetXaxis()->SetTitle("p_{T}");
  grShJPsiVsPtCMS_Shade->GetYaxis()->SetTitle("R_{AA}^{Sh}(J/#psi)");
  grShJPsiVsPtCMS_Shade->GetYaxis()->SetRangeUser(0.0,1.5);
  grShJPsiVsPtCMS_Shade->SetName("grShJPsiVsPtCMS_Shade");
  grShJPsiVsPtCMS_Shade->SetTitle("grShJPsiVsPtCMS_Shade");


  new TCanvas;
  gPad->SetTicks();
  grShJPsiVsPtCMS_Shade->SetFillStyle(3013);
  grShJPsiVsPtCMS_Shade->SetFillColor(16);
  grShJPsiVsPtCMS_Shade->Draw("Af");
  grShJPsiVsPtCMS->Draw("CSame");
  grShUJPsiVsPtCMS->Draw("lSame");
  grShLJPsiVsPtCMS->Draw("lSame");



  
  //===================== Shadowing Vs xx =============================//
  Double_t xx[100]={0.0};
  Double_t NPartValSh[100]={0.0};

  Double_t ShJPsi[100]={0.0};
  Double_t ShJPsiU[100]={0.0};
  Double_t ShJPsiL[100]={0.0};


  Double_t ShJPsiPtCut[100]={0.0};
  Double_t ShJPsiPtCutU[100]={0.0};
  Double_t ShJPsiPtCutL[100]={0.0};

  Double_t ShUpsilonMid[100]={0.0};
  Double_t ShUpsilonUMid[100]={0.0};
  Double_t ShUpsilonLMid[100]={0.0};


  Double_t ShUpsilonFor[100]={0.0};
  Double_t ShUpsilonUFor[100]={0.0};
  Double_t ShUpsilonLFor[100]={0.0};


  Double_t xxMin =1.0;
  Double_t xxMax =9.0;
  Double_t xxStep =0.1;
  Int_t Nxx=(xxMax -  xxMin)/xxStep;
  
  for(int i=0;i<Nxx;i++)
    {
      xx[i]=xxMin + xxStep*i;
      NPartValSh[i] = fa1->GetX(xx[i]);
      
      ShJPsi[i]= ShVsX(xx[i],0.932);
      ShJPsiU[i]= ShVsX(xx[i],1.025);
      ShJPsiL[i]= ShVsX(xx[i],0.840);

      ShJPsiPtCut[i]= ShVsX(xx[i],1.034);
      ShJPsiPtCutU[i]= ShVsX(xx[i],1.090);
      ShJPsiPtCutL[i]= ShVsX(xx[i],1.002);


      ShUpsilonMid[i]= ShVsX(xx[i],0.953);
      ShUpsilonUMid[i]= ShVsX(xx[i],1.008);
      ShUpsilonLMid[i]= ShVsX(xx[i],0.900);


      ShUpsilonFor[i]= ShVsX(xx[i],0.953);
      ShUpsilonUFor[i]= ShVsX(xx[i],0.987);
      ShUpsilonLFor[i]= ShVsX(xx[i],0.913);
      
      //ShUpsilon[i]= ShVsX(xx[i],0.80);
      //cout<<xx[i]<<"   "<<NPartValSh[i]<<"   "<<Sh[i]<<endl;
    }
 
  TGraph *grShVsX = new TGraph(Nxx, xx, ShJPsi);
  grShVsX->SetLineWidth(2);
  grShVsX->SetMarkerStyle(20);
  grShVsX->GetXaxis()->SetTitle("N_{Coll}/#frac{N_{Part}}{2}");
  grShVsX->GetYaxis()->SetTitle("Sh");
  grShVsX->GetYaxis()->SetRangeUser(0.0,1.0);
  
  new TCanvas;
  gPad->SetBottomMargin(0.14);
  grShVsX->Draw("AP");


  TGraph *grShJPsiVsNPart = new TGraph(Nxx, NPartValSh, ShJPsi);
  grShJPsiVsNPart->SetLineWidth(2);
  grShJPsiVsNPart->SetMarkerStyle(20);
  grShJPsiVsNPart->GetXaxis()->SetTitle("N_{Part}");
  grShJPsiVsNPart->GetYaxis()->SetTitle("R_{AA}^{Sh}(J/#psi)");
  grShJPsiVsNPart->GetYaxis()->SetRangeUser(0.0,1.0);
  grShJPsiVsNPart->SetName("grShJPsiVsNPart");
  grShJPsiVsNPart->SetTitle("grShJPsiVsNPart");
  
  
  TGraph *grShJPsiUVsNPart = new TGraph(Nxx, NPartValSh, ShJPsiU);
  grShJPsiUVsNPart->SetLineWidth(2);
  grShJPsiUVsNPart->SetMarkerStyle(20);
  grShJPsiUVsNPart->GetXaxis()->SetTitle("N_{Part}");
  grShJPsiUVsNPart->GetYaxis()->SetTitle("R_{AA}^{Sh}(J/#psi)");
  grShJPsiUVsNPart->GetYaxis()->SetRangeUser(0.0,1.2);
  grShJPsiUVsNPart->SetName("grShJPsiUVsNPart");
  grShJPsiUVsNPart->SetTitle("grShJPsiUVsNPart");
  


  TGraph *grShJPsiLVsNPart = new TGraph(Nxx, NPartValSh, ShJPsiL);
  grShJPsiLVsNPart->SetLineWidth(2);
  grShJPsiLVsNPart->SetMarkerStyle(20);
  grShJPsiLVsNPart->GetXaxis()->SetTitle("N_{Part}");
  grShJPsiLVsNPart->GetYaxis()->SetTitle("R_{AA}^{Sh}(J/#psi)");
  grShJPsiLVsNPart->GetYaxis()->SetRangeUser(0.0,1.2);
  grShJPsiLVsNPart->SetName("grShJPsiLVsNPart");
  grShJPsiLVsNPart->SetTitle("grShJPsiLVsNPart");
  

  TGraph *grShJPsiVsNPart_Shade = new TGraph(2*Nxx);
  for(Int_t i=0;i<Nxx;i++)
    {
      grShJPsiVsNPart_Shade->SetPoint(i,NPartValSh[i],ShJPsiU[i]);
      grShJPsiVsNPart_Shade->SetPoint(Nxx+i,NPartValSh[Nxx-i-1],ShJPsiL[Nxx-i-1]);
    }

  grShJPsiVsNPart_Shade->GetXaxis()->SetTitle("N_{Part}");
  grShJPsiVsNPart_Shade->GetYaxis()->SetTitle("R_{AA}^{Sh}(J/#psi)");
  grShJPsiVsNPart_Shade->GetYaxis()->SetRangeUser(0.0,1.2);
  grShJPsiVsNPart_Shade->SetName("grShJPsiVsNPart_Shade");
  grShJPsiVsNPart_Shade->SetTitle("grShJPsiVsNPart_Shade");



  new TCanvas;
  gPad->SetTicks();
  grShJPsiVsNPart_Shade->SetFillStyle(3013);
  grShJPsiVsNPart_Shade->SetFillColor(16);
  grShJPsiVsNPart_Shade->Draw("Af");
  grShJPsiUVsNPart->Draw("CSame");
  grShJPsiVsNPart->Draw("lSame");
  grShJPsiLVsNPart->Draw("lSame");


  //return;

  TGraph *grShJPsiPtCutVsNPart = new TGraph(Nxx, NPartValSh, ShJPsiPtCut);
  grShJPsiPtCutVsNPart->SetLineWidth(2);
  grShJPsiPtCutVsNPart->SetMarkerStyle(20);
  grShJPsiPtCutVsNPart->GetXaxis()->SetTitle("N_{Part}");
  grShJPsiPtCutVsNPart->GetYaxis()->SetTitle("R_{AA}^{Sh}(J/#psi)");
  grShJPsiPtCutVsNPart->GetYaxis()->SetRangeUser(0.0,1.0);
  grShJPsiPtCutVsNPart->SetName("grShJPsiPtCutVsNPart");
  grShJPsiPtCutVsNPart->SetTitle("grShJPsiPtCutVsNPart");
  
  
  TGraph *grShJPsiPtCutUVsNPart = new TGraph(Nxx, NPartValSh, ShJPsiPtCutU);
  grShJPsiPtCutUVsNPart->SetLineWidth(2);
  grShJPsiPtCutUVsNPart->SetMarkerStyle(20);
  grShJPsiPtCutUVsNPart->GetXaxis()->SetTitle("N_{Part}");
  grShJPsiPtCutUVsNPart->GetYaxis()->SetTitle("R_{AA}^{Sh}(J/#psi)");
  grShJPsiPtCutUVsNPart->GetYaxis()->SetRangeUser(0.0,1.2);
  grShJPsiPtCutUVsNPart->SetName("grShJPsiPtCutUVsNPart");
  grShJPsiPtCutUVsNPart->SetTitle("grShJPsiPtCutUVsNPart");
  


  TGraph *grShJPsiPtCutLVsNPart = new TGraph(Nxx, NPartValSh, ShJPsiPtCutL);
  grShJPsiPtCutLVsNPart->SetLineWidth(2);
  grShJPsiPtCutLVsNPart->SetMarkerStyle(20);
  grShJPsiPtCutLVsNPart->GetXaxis()->SetTitle("N_{Part}");
  grShJPsiPtCutLVsNPart->GetYaxis()->SetTitle("R_{AA}^{Sh}(J/#psi)");
  grShJPsiPtCutLVsNPart->GetYaxis()->SetRangeUser(0.0,1.2);
  grShJPsiPtCutLVsNPart->SetName("grShJPsiPtCutLVsNPart");
  grShJPsiPtCutLVsNPart->SetTitle("grShJPsiPtCutLVsNPart");
  
  
  
  TGraph *grShJPsiPtCutVsNPart_Shade = new TGraph(2*Nxx);
  for(Int_t i=0;i<Nxx;i++)
    {
      grShJPsiPtCutVsNPart_Shade->SetPoint(i,NPartValSh[i],ShJPsiPtCutU[i]);
      grShJPsiPtCutVsNPart_Shade->SetPoint(Nxx+i,NPartValSh[Nxx-i-1],ShJPsiPtCutL[Nxx-i-1]);
    }


  grShJPsiPtCutVsNPart_Shade->GetXaxis()->SetTitle("N_{Part}");
  grShJPsiPtCutVsNPart_Shade->GetYaxis()->SetTitle("R_{AA}^{Sh}(J/#psi)");
  grShJPsiPtCutVsNPart_Shade->GetYaxis()->SetRangeUser(0.0,1.2);
  grShJPsiPtCutVsNPart_Shade->SetName("grShJPsiPtCutLVsNPart_Shade");
  grShJPsiPtCutVsNPart_Shade->SetTitle("grShJPsiPtCutLVsNPart_Shade");


  new TCanvas;
  gPad->SetTicks();
  grShJPsiPtCutVsNPart_Shade->SetFillStyle(3013);
  grShJPsiPtCutVsNPart_Shade->SetFillColor(16);
  grShJPsiPtCutVsNPart_Shade->Draw("Af");
  grShJPsiPtCutUVsNPart->Draw("CSame");
  grShJPsiPtCutVsNPart->Draw("lSame");
  grShJPsiPtCutLVsNPart->Draw("lSame");


  
  TGraph *grShUpsilonVsNPartMid = new TGraph(Nxx, NPartValSh, ShUpsilonMid);
  grShUpsilonVsNPartMid->SetLineWidth(2);
  grShUpsilonVsNPartMid->SetMarkerStyle(20);
  grShUpsilonVsNPartMid->GetXaxis()->SetTitle("N_{Part}");
  grShUpsilonVsNPartMid->GetYaxis()->SetTitle("R_{AA}^{Sh}(#varUpsilon)");
  grShUpsilonVsNPartMid->SetName("grShUpsilonVsNPartMid");
  grShUpsilonVsNPartMid->SetTitle("grShUpsilonVsNPartMid");
  grShUpsilonVsNPartMid->GetYaxis()->SetRangeUser(0.0,1.2);



  TGraph *grShUpsilonUVsNPartMid = new TGraph(Nxx, NPartValSh, ShUpsilonUMid);
  grShUpsilonUVsNPartMid->SetLineWidth(2);
  grShUpsilonUVsNPartMid->SetMarkerStyle(20);
  grShUpsilonUVsNPartMid->GetXaxis()->SetTitle("N_{Part}");
  grShUpsilonUVsNPartMid->GetYaxis()->SetTitle("R_{AA}^{Sh}(#varUpsilon)");
  grShUpsilonUVsNPartMid->SetName("grShUpsilonUVsNPartMid");
  grShUpsilonUVsNPartMid->SetTitle("grShUpsilonUVsNPartMid");
  grShUpsilonUVsNPartMid->GetYaxis()->SetRangeUser(0.0,1.2);




   TGraph *grShUpsilonLVsNPartMid = new TGraph(Nxx, NPartValSh, ShUpsilonLMid);
   grShUpsilonLVsNPartMid->SetLineWidth(2);
   grShUpsilonLVsNPartMid->SetMarkerStyle(20);
   grShUpsilonLVsNPartMid->GetXaxis()->SetTitle("N_{Part}");
   grShUpsilonLVsNPartMid->GetYaxis()->SetTitle("R_{AA}^{Sh}(#varUpsilon)");
   grShUpsilonLVsNPartMid->SetName("grShUpsilonLVsNPartMid");
   grShUpsilonLVsNPartMid->SetTitle("grShUpsilonLVsNPartMid");
   //grShUpsilonLVsNPartMid->GetYaxis()->SetRangeUser(0.0,1.0);

   
   TGraph *grShUpsilonVsNPartMid_Shade = new TGraph(2*Nxx);
   for(Int_t i=0;i<Nxx;i++)
     {
       grShUpsilonVsNPartMid_Shade->SetPoint(i,NPartValSh[i],ShUpsilonUMid[i]);
       grShUpsilonVsNPartMid_Shade->SetPoint(Nxx+i,NPartValSh[Nxx-i-1],ShUpsilonLMid[Nxx-i-1]);
     }
   
   grShUpsilonVsNPartMid_Shade->GetXaxis()->SetTitle("N_{Part}");
   grShUpsilonVsNPartMid_Shade->GetYaxis()->SetTitle("R_{AA}^{Sh}(#varUpsilon)");
   grShUpsilonVsNPartMid_Shade->SetName("grShUpsilonVsNPartMid_Shade");
   grShUpsilonVsNPartMid_Shade->SetTitle("grShUpsilonVsNPartMid_Shade");
   
   
   new TCanvas;
   gPad->SetTicks();
   grShUpsilonVsNPartMid_Shade->SetFillStyle(3013);
   grShUpsilonVsNPartMid_Shade->SetFillColor(16);
   grShUpsilonVsNPartMid_Shade->Draw("Af");
   grShUpsilonUVsNPartMid->Draw("CSame");
   grShUpsilonVsNPartMid->Draw("CSame");
   grShUpsilonLVsNPartMid->Draw("CSame");
   

   
   
   TGraph *grShUpsilonVsNPartFor = new TGraph(Nxx, NPartValSh, ShUpsilonFor);
   grShUpsilonVsNPartFor->SetLineWidth(2);
   grShUpsilonVsNPartFor->SetMarkerStyle(20);
   grShUpsilonVsNPartFor->GetXaxis()->SetTitle("N_{Part}");
   grShUpsilonVsNPartFor->GetYaxis()->SetTitle("R_{AA}^{Sh}(#varUpsilon)");
   grShUpsilonVsNPartFor->SetName("grShUpsilonVsNPartFor");
   grShUpsilonVsNPartFor->SetTitle("grShUpsilonVsNPartFor");
   grShUpsilonVsNPartFor->GetYaxis()->SetRangeUser(0.0,1.2);
   

   
   TGraph *grShUpsilonUVsNPartFor = new TGraph(Nxx, NPartValSh, ShUpsilonUFor);
   grShUpsilonUVsNPartFor->SetLineWidth(2);
   grShUpsilonUVsNPartFor->SetMarkerStyle(20);
   grShUpsilonUVsNPartFor->GetXaxis()->SetTitle("N_{Part}");
   grShUpsilonUVsNPartFor->GetYaxis()->SetTitle("R_{AA}^{Sh}(#varUpsilon)");
   grShUpsilonUVsNPartFor->SetName("grShUpsilonUVsNPartFor");
   grShUpsilonUVsNPartFor->SetTitle("grShUpsilonUVsNPartFor");
   grShUpsilonUVsNPartFor->GetYaxis()->SetRangeUser(0.0,1.2);
  


   TGraph *grShUpsilonLVsNPartFor = new TGraph(Nxx, NPartValSh, ShUpsilonLFor);
   grShUpsilonLVsNPartFor->SetLineWidth(2);
   grShUpsilonLVsNPartFor->SetMarkerStyle(20);
   grShUpsilonLVsNPartFor->GetXaxis()->SetTitle("N_{Part}");
   grShUpsilonLVsNPartFor->GetYaxis()->SetTitle("R_{AA}^{Sh}(#varUpsilon)");
   grShUpsilonLVsNPartFor->SetName("grShUpsilonLVsNPartFor");
   grShUpsilonLVsNPartFor->SetTitle("grShUpsilonLVsNPartFor");
   

   
   TGraph *grShUpsilonVsNPartFor_Shade = new TGraph(2*Nxx);
   for(Int_t i=0;i<Nxx;i++)
     {
       grShUpsilonVsNPartFor_Shade->SetPoint(i,NPartValSh[i],ShUpsilonUFor[i]);
       grShUpsilonVsNPartFor_Shade->SetPoint(Nxx+i,NPartValSh[Nxx-i-1],ShUpsilonLFor[Nxx-i-1]);
     }
   
   grShUpsilonVsNPartFor_Shade->GetXaxis()->SetTitle("N_{Part}");
   grShUpsilonVsNPartFor_Shade->GetYaxis()->SetTitle("R_{AA}^{Sh}(#varUpsilon)");
   grShUpsilonVsNPartFor_Shade->SetName("grShUpsilonVsNPartFor_Shade");
   grShUpsilonVsNPartFor_Shade->SetTitle("grShUpsilonVsNPartFor_Shade");
   grShUpsilonVsNPartFor_Shade->GetYaxis()->SetRangeUser(0.0,1.2);
   
   new TCanvas;
   gPad->SetTicks();
   grShUpsilonVsNPartFor_Shade->SetFillStyle(3013);
   grShUpsilonVsNPartFor_Shade->SetFillColor(16);
   grShUpsilonVsNPartFor_Shade->Draw("Af");
   grShUpsilonUVsNPartFor->Draw("CSame");
   grShUpsilonVsNPartFor->Draw("CSame");
   grShUpsilonLVsNPartFor->Draw("CSame");


   grShJPsiVsNPart->Write();
   grShJPsiUVsNPart->Write();
   grShJPsiLVsNPart->Write();
   grShJPsiVsNPart_Shade->Write();


   grShJPsiPtCutVsNPart->Write();
   grShJPsiPtCutUVsNPart->Write();
   grShJPsiPtCutLVsNPart->Write();
   grShJPsiPtCutVsNPart_Shade->Write();

   grShUpsilonVsNPartMid->Write();
   grShUpsilonUVsNPartMid->Write();
   grShUpsilonLVsNPartMid->Write();
   grShUpsilonVsNPartMid_Shade->Write();


   grShUpsilonVsNPartFor->Write();
   grShUpsilonUVsNPartFor->Write();
   grShUpsilonLVsNPartFor->Write();
   grShUpsilonVsNPartFor_Shade->Write();

   grShJPsiVsPtCMS_Shade->Write();
   grShJPsiVsPtCMS->Write();
   grShUJPsiVsPtCMS->Write();
   grShLJPsiVsPtCMS->Write();
   
   
   grShJPsiVsPtALICE_Shade->Write();
   grShJPsiVsPtALICE->Write();
   grShUJPsiVsPtALICE->Write();
   grShLJPsiVsPtALICE->Write();
   


   //OutFile->Close();


}

//////////////////////////////////////////////////////////////////////////////////////////////////
Double_t ImpactPara(Int_t BinLow, Int_t BinHigh)
{

  Double_t B[40]={1.87663,3.02075,3.88968,4.60791,5.24572,5.76362,6.29562,6.75185,7.18228,7.60734,7.99763,8.37317,
		  8.72411,9.061,9.39947,9.71608,10.024,10.3287,10.6321,10.9012,11.1962,11.4625,11.7259,12.0007,12.2434,
		  12.5018,12.7655,13.005,13.2398,13.503,13.7387,13.9905,14.2377,14.5011,14.6931,14.9996,15.1928,15.385,
		  15.4879,15.5952};

  Double_t sum=0;
  for(int i=BinLow;i<BinHigh;i++){
    sum+=B[i];
  }
  Double_t impactpara = sum/(BinHigh-BinLow);
  return impactpara;

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



Double_t TAA(int BinLow, int BinHigh)
{

  Double_t SigmaPPInelastic = 64.0; //mbarn 

  Double_t NCollArray[40]={1747.8600, 1567.5300, 1388.3900, 1231.7700, 1098.2000, 980.4390, 861.6090, 766.0420, 676.5150, 593.4730,
			   521.9120, 456.5420, 398.5460, 346.6470, 299.3050, 258.3440, 221.2160, 188.6770, 158.9860, 134.7000,
			   112.5470, 93.4537, 77.9314, 63.5031, 52.0469, 42.3542, 33.9204, 27.3163, 21.8028, 17.2037,
			   13.5881, 10.6538, 8.3555, 6.4089, 5.1334, 3.7322, 3.0663, 2.4193, 2.1190, 1.7695};
  Double_t sum=0;
  for(int i=BinLow;i<BinHigh;i++){
    sum+=NCollArray[i];
  }
  Double_t NColl = sum/(BinHigh-BinLow);
  Double_t taa = NColl/SigmaPPInelastic;

  return taa;

}


Double_t ShVsX(Double_t x, Double_t ShMB)
{

  Double_t y =0.0;
  Double_t XMB = NColl(0,40)/(0.5*Npart(0,40));

  y = 1.0 + ( (ShMB - 1.0)/ (XMB-1.0))*(x-1.0);
  return y;

}




Double_t CNMVsPtInt(Double_t PtMin, Double_t PtMax, Double_t PtStep, TH1D *HistPt, TH1D *HistSh)
{
  //PtMin=0.25; ALICE
  //PtMin=6.25; CMS
  
  //Double_t Ptmax=0;
  //if(isUps==0)Ptmax=20.75;
  //if(isUps==1 || isUps ==2)Ptmax=40.25;

  //Double_t Ptstep=0.5;
  int NN_Pt= (int)((PtMax-PtMin)/PtStep);
 
  Double_t sum=0;
  Double_t sumPt=0;
  Double_t yield =0;
 
  Double_t ShadowingFactor=0;

  Double_t yy = 0.0; 

  //TH1D *HistPt, 
  //TH1D *HistSh
  
  for(int i=0;i<=NN_Pt;i++) {
   
    Double_t Pt=PtMin+i*PtStep;
  
    //cout<<HistPt->GetName()<<"    "<<Pt<<endl;

    //yield=HistPt->GetBinContent(HistPt->FindBin(Pt));
    //yy =HistSh->GetBinContent(HistSh->FindBin(Pt));


    yield=HistPt->Interpolate(Pt);
    yy =HistSh->Interpolate(Pt);

    //cout<<Pt<<"  "<<yy<<"   "<<yield<<endl;
    sum = sum + (yy*yield);
  
    sumPt = sumPt+yield;  
    
  }
  //cout<<sum<<"sum  "<<sumPt<<endl;  

  return sum/sumPt;

  //return yy;
}
