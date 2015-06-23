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
#include "TLine.h"
#include "TMath.h"
#include "TVector3.h"
#include "TString.h"
#include "TStyle.h"
#include "TGraphErrors.h"
#include <fstream>
#include <map>
#include <string>
#include <iostream>
#include <stdio.h>
#include <string.h>
#include "TObjArray.h"


Double_t hbarc = 0.197327;
Double_t hbarc2 = hbarc*hbarc;
Double_t hbarc3 = hbarc2*hbarc;


void PlotHybridEOS()
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
  gStyle->SetPadLeftMargin(0.15);
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



  TFile *OutFile =new TFile("LatticeEOS_s95p-v1.2.root","Recreate");


  Double_t Temp[5000];
  Double_t ee[5000];
  Double_t PP[5000];
  Double_t ss[5000];
  Double_t ssG[5000];
  
  Double_t FQGP[5000];


  Double_t FQGP2[5000];

  char fin[500];
  sprintf(fin,"s95p-v1.2_TempDens.txt");
  ifstream filein(fin);

  int NN=3510;



  Double_t pi = TMath::Pi();
  Double_t pi2 = pi*pi;
  Double_t Aq = 0.9*pi2*(7.0*2.5/60.0 + 16.0/90.0);
  Double_t FourAq = 4.0*Aq;

  Double_t Ah = pi2*10.0/90.0;
  Double_t FourAh = 4.0*Ah;

  TLine *lq = new TLine(0.0,FourAq,2.2,FourAq);
  lq->SetLineColor(1);
  lq->SetLineStyle(1);
  lq->SetLineWidth(2);



  TLine *lh = new TLine(0.0,FourAh,2.2,FourAh);
  lh->SetLineColor(2);
  lh->SetLineStyle(1);
  lh->SetLineWidth(2);

  



  for (int jj=0; jj<NN; jj++) {
    

    filein >>Temp[jj]>>ee[jj]>>PP[jj]>>ss[jj]>>FQGP[jj];
    
    //cout<<Temp[jj]<<"  "<<ee[jj]<<"  "<<PP[jj]<<"  "<<ss[jj]<<"  "<<FQGP[jj]<<endl;
    
    ssG[jj]=hbarc3*ss[jj];
  
    PP[jj]=hbarc3*PP[jj]/(Temp[jj]*Temp[jj]*Temp[jj]*Temp[jj]);
    ee[jj]=hbarc3*ee[jj]/(Temp[jj]*Temp[jj]*Temp[jj]*Temp[jj]);

    ss[jj]=hbarc3*ss[jj]/(Temp[jj]*Temp[jj]*Temp[jj]);
  
    
    FQGP2[jj] = (ss[jj] - FourAh)/(FourAq -FourAh); 
    
    if(FQGP2[jj]>=1.0){FQGP2[jj] =1.0;}
    if(FQGP2[jj]<=0.0){FQGP2[jj] =0.0;}

  }






  TGraph *grfTempVsEE = new TGraph(NN,Temp,ee);
  grfTempVsEE->GetXaxis()->SetTitle("T (GeV/c)");
  grfTempVsEE->GetYaxis()->SetTitle("#epsilon/T^{4}");
  grfTempVsEE->SetName("grfTempVsEEByTFour");
  new TCanvas;
  grfTempVsEE->Draw("AL");



  TGraph *grfTempVsPP = new TGraph(NN,Temp,PP);
  grfTempVsPP->GetXaxis()->SetTitle("T (GeV/c)");
  grfTempVsPP->GetYaxis()->SetTitle("P/T^{4}");
  grfTempVsPP->SetName("grfTempVsPPByTFour");
  new TCanvas;
  grfTempVsPP->Draw("AL");



  TGraph *grfTempVsSS = new TGraph(NN,Temp,ss);
  grfTempVsSS->GetXaxis()->SetTitle("T (GeV/c)");
  grfTempVsSS->GetYaxis()->SetTitle("s/T^{3}");
  grfTempVsSS->SetName("grfTempVsSSByTCube");
  new TCanvas;
  grfTempVsSS->Draw("AL");

  lq->Draw("same");
  lh->Draw("same");



  TGraph *grfTempVsFQGP = new TGraph(NN,Temp,FQGP);
  grfTempVsFQGP->GetXaxis()->SetTitle("T (GeV/c)");
  grfTempVsFQGP->GetYaxis()->SetTitle("F_{QGP}");
  grfTempVsFQGP->SetName("TempVsFQGP");
  new TCanvas;
  grfTempVsFQGP->Draw("AL");



  TGraph *grfTempVsFQGP2 = new TGraph(NN,Temp,FQGP2);
  grfTempVsFQGP2->GetXaxis()->SetTitle("T (GeV/c)");
  grfTempVsFQGP2->GetYaxis()->SetTitle("F_{QGP2}");
  grfTempVsFQGP2->SetName("TempVsFQGP2");
  grfTempVsFQGP2->SetLineColor(2);
  
  new TCanvas;
  grfTempVsFQGP->Draw("AL");
  grfTempVsFQGP2->Draw("Lsame");
 





  TGraph *grfSSVsTemp = new TGraph(NN,ssG,Temp);
  grfSSVsTemp->GetXaxis()->SetTitle("s");
  grfSSVsTemp->GetYaxis()->SetTitle("Temp");
  grfSSVsTemp->SetName("grfSSVsTemp");
  new TCanvas;
  grfSSVsTemp->Draw("AL");
  

  grfTempVsEE->Write();
  grfTempVsPP->Write();
  grfTempVsSS->Write();
  grfTempVsFQGP->Write();
  grfTempVsFQGP2->Write();
  grfSSVsTemp->Write();

  OutFile->Write();
  OutFile->Close();


}
