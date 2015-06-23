#include "TCanvas.h"
#include "TROOT.h"
#include "TAxis.h"
#include "TH1.h"
#include "TFile.h"
#include "TH1D.h"
#include "TH2D.h"
#include "TF1.h"
#include "TH1I.h"
#include "TH1F.h"
#include "TCanvas.h"
#include "TLine.h"
#include "TMath.h"
#include "TVector3.h"
#include "TString.h"
#include "TLegend.h"
#include "TStyle.h"
#include "TLatex.h"
#include "TGraphErrors.h"
#include "TMultiGraph.h"
#include <fstream>
#include <string>
#include <iostream>
#include <stdio.h>
#include <string.h>
#include "TPad.h"

double PowerLaw(double *, double *);
void ReadTheory();



// Theory
int NN = 30;
TGraphErrors *gY1 = new TGraphErrors (NN);  // Y2/Y1
TGraphErrors *gY2 = new TGraphErrors (NN);  // Y3/Y1
// Errors Y2/Y1
TGraphErrors *gY3 = new TGraphErrors (NN);
TGraphErrors *gY4 = new TGraphErrors (NN);
// Errors Y3/Y1
TGraphErrors *gY5 = new TGraphErrors (NN);
TGraphErrors *gY6 = new TGraphErrors (NN);


void UpsiProdRatio()
{
  gStyle->SetCanvasDefH(600);
  gStyle->SetCanvasDefW(600);
  gStyle->SetOptStat(0);
  gStyle->SetLineWidth(0);
  gStyle->SetOptDate(0);
  gStyle->SetOptFit(0);
  gStyle->SetFillColor(0);
  gStyle->SetCanvasColor(10);
  gStyle->SetPadBorderMode(0);
  gStyle->SetPadColor(0);
  gStyle->SetTitleFillColor(0);
  gStyle->SetOptTitle(0);
  gStyle->SetOptStat(1); 
  gStyle->SetTitleXOffset(1.3); 
  gStyle->SetTitleYOffset(1.3); 

  ////////
  ReadTheory();
  // Fit Function (Powerlaw)// 
  TF1 *PtFit = new TF1("PtFit", PowerLaw, 0.0, 100.0, 5);
  PtFit->SetLineColor(1);
  PtFit->SetParNames("A", "n", "p_{0}", "a", "b");
  PtFit->SetParameters(1000, 6, 2, 0.5, 0.0);
  PtFit->FixParameter(4, 0.0); 

  // Y(1S) data
  TGraphErrors *Upsi1sCS = Y1Sdata();
  // Y(2S) data
  TGraphErrors *Upsi2sCS = Y2Sdata();
  // Y(3S) data
  TGraphErrors *Upsi3sCS = Y3Sdata();


  // Fitting Y1S data 
  Upsi1sCS->Fit(PtFit,"","",2.0,20.0);
  TGraphErrors *gUp2DataT = new TGraphErrors (NN);
  TGraphErrors *gUp3DataT = new TGraphErrors (NN);
  for (int i=0; i<NN; i++) {
    double pt = i;
    double yy2 = PtFit->Eval(pt)*gY1->Eval(pt);
    gUp2DataT->SetPoint(i, pt, yy2);
    double yy3 = PtFit->Eval(pt)*gY2->Eval(pt);
    gUp3DataT->SetPoint(i, pt, yy3);
  }


  // Plot 1S, 2S and 3S states
  TLegend *legend_cs = new TLegend(0.1543624,0.1498258,0.4832215,0.3449477);
  legend_cs->SetBorderSize(0);
  legend_cs->SetFillStyle(0);
  legend_cs->SetFillColor(0);
  legend_cs->SetTextSize(0.03);
  legend_cs->AddEntry(Upsi1sCS,"#Upsilon(1S)", "P");
  legend_cs->AddEntry(Upsi2sCS,"#Upsilon(2S)", "P");
  legend_cs->AddEntry(Upsi3sCS,"#Upsilon(3S)", "P");

  new TCanvas;
  gPad->SetTickx();
  gPad->SetTicky();
  gPad->SetLogy(1);

  Upsi1sCS->Draw("AP");
  PtFit->Draw("same");
  Upsi2sCS->Draw("sameP");
  Upsi3sCS->Draw("sameP");

  gUp2DataT->SetLineColor(2);
  gUp3DataT->SetLineColor(4);
  gUp2DataT->Draw("sameL");
  gUp3DataT->Draw("sameL");
  legend_cs->Draw("Same");


  char params[300];
  TLatex *t = new TLatex();
  t->SetNDC(); t->SetTextAlign(12);t->SetTextColor(1);
  t->SetTextSize(0.03);
  t->DrawLatex(0.60,0.84,"CMS");
  t->DrawLatex(0.60,0.79,"pp  #sqrt{s} = 7 TeV");
  t->DrawLatex(0.60,0.74,"|y| < 2 ");

  
  // Plot ratios  ////////////////
  TLegend *legend_ratio = new TLegend(0.1677852,0.6689895,0.4966443,0.8501742);
  legend_ratio->SetBorderSize(0);
  legend_ratio->SetFillStyle(0);
  legend_ratio->SetFillColor(0);
  legend_ratio->SetTextSize(0.03);
 
  new TCanvas;
  gPad->SetTickx();
  gPad->SetTicky();

  Draw2Sby1S(legend_ratio);
  Draw3Sby1S(legend_ratio);

  legend_ratio->Draw("Same");

  // 2s/1s
  gY1->SetLineColor(1);
  gY1->SetLineWidth(2);
  gY1->Draw("sameL");
  // 3s/1s
  gY2->SetLineColor(2);
  gY2->SetLineWidth(2);
  gY2->Draw("sameL");
  // errors
  gY3->SetLineColor(1);
  gY3->Draw("sameL");
  gY4->SetLineColor(1);
  gY4->Draw("sameL");
  gY5->SetLineColor(2);
  gY5->Draw("sameL");
  gY6->SetLineColor(2);
  gY6->Draw("sameL");

}


void ReadTheory()
{
  ifstream filein("lhc.txt");
  ofstream fileout("lhcM.txt");

  int NN1; 
  double pT[100], y1[100], y2[100], y3[100], y4[100], y5[100], y6[100];

  filein >> NN1;
  for (int i=0; i<NN1; i++) {
    filein >> pT[i] >> y1[i];
    gY1->SetPoint(i, pT[i], y1[i]);
  }

  filein >> NN1;
  for (int i=0; i<NN1; i++) {
    filein >> pT[i] >> y2[i];
    gY2->SetPoint(i, pT[i], y2[i]);
  }

  filein >> NN1;
  for (int i=0; i<NN1; i++) {
    filein >> pT[i] >> y3[i];
    gY3->SetPoint(i, pT[i], y3[i]);
  }

  filein >> NN1;
  for (int i=0; i<NN1; i++) {
    filein >> pT[i] >> y4[i];
    gY4->SetPoint(i, pT[i], y4[i]);
  }

  filein >> NN1;
  for (int i=0; i<NN1; i++) {
    filein >> pT[i] >> y5[i];
    gY5->SetPoint(i, pT[i], y5[i]);
  }

  filein >> NN1;
  for (int i=0; i<NN1; i++) {
    filein >> pT[i] >> y6[i];
    gY6->SetPoint(i, pT[i], y6[i]);
  }
}


Double_t PowerLaw(Double_t *x, Double_t *par)
{
  double m = 9.46;
  //  double mt = sqrt(m*m + x[0]*x[0]);
  double mt = x[0];

  double fun = par[0]*TMath::Power((TMath::Exp(- (par[3]*mt+par[4]*mt*mt)/par[2]) + mt/par[2]), -par[1]);

 return fun;
}


TGraphErrors *Y1Sdata()
{
  // Y(1S)
  double U1sPt[20] = {0,1,2,3,4,5,6,7,8,9,10,12,14,17,20,30};
  double U1sCS[20] = {0.30, 0.90, 1.04, 0.88, 0.90, 0.82, 0.64, 0.51, 0.33, 0.25, 0.36, 0.18, 0.14, 0.06, 0.06};
  double Nptbin, dPt, dy=4;
  Nptbin = 15;
 
  double PTbin[100], DelPTbin[100];
  for (Int_t ih = 0; ih < Nptbin; ih++) {
    PTbin[ih] = (U1sPt[ih] + U1sPt[ih+1])/2.0;
    DelPTbin[ih] = U1sPt[ih+1] - U1sPt[ih];
    DelPTbin[ih] = DelPTbin[ih]/2.0;
    dPt = U1sPt[ih+1] - U1sPt[ih];
    U1sCS[ih] = U1sCS[ih]/(dPt*dy); // dPt*dy
  }

  TGraphErrors *Upsi1sCS = new TGraphErrors(Nptbin,PTbin,U1sCS,0,0);
  Upsi1sCS->SetMarkerStyle(8);
  Upsi1sCS->SetMarkerColor(1);
  Upsi1sCS->GetXaxis()->SetTitle("P_{T}^{#Upsilon} GeV/c");
  Upsi1sCS->GetYaxis()->SetTitle("d^{2}#sigma/dp_{T}dy #times B(#mu#mu) (nb/(GeV/c))");
  Upsi1sCS->GetXaxis()->SetRangeUser(0.0,30.0);
  Upsi1sCS->GetYaxis()->SetRangeUser(2e-4,3.0);

  return Upsi1sCS;
}



TGraphErrors *Y2Sdata()
{
  // Y(2S)
  double U2sPt[20] = {0,2,4,6,9,12,16,20,30};
  double U2sCS[20] = {0.25, 0.48, 0.41, 0.41, 0.21, 0.09, 0.04, 0.02};

  double Nptbin, dPt, dy=4;
  double PTbin[100], DelPTbin[100];

  Nptbin = 8;
  for (Int_t ih = 0; ih < Nptbin; ih++) {
    PTbin[ih] = (U2sPt[ih] + U2sPt[ih+1])/2.0;
    DelPTbin[ih] = U2sPt[ih+1] - U2sPt[ih];
    DelPTbin[ih] = DelPTbin[ih]/2.0;
    dPt = U2sPt[ih+1] - U2sPt[ih];
    U2sCS[ih] = U2sCS[ih]/(dPt*dy); // dPt*dy
  }

  TGraphErrors *Upsi2sCS = new TGraphErrors(Nptbin,PTbin,U2sCS,0,0);
  Upsi2sCS->SetMarkerStyle(21);
  Upsi2sCS->SetMarkerColor(2);
  Upsi2sCS->GetXaxis()->SetTitle("P_{T}^{#Upsilon} GeV/c");
  Upsi2sCS->GetYaxis()->SetTitle("d^{2}#sigma/dp_{T}dy #times B(#mu#mu) (nb/(GeV/c))");
  Upsi2sCS->GetXaxis()->SetRangeUser(0.0,30.0);
  Upsi2sCS->GetYaxis()->SetRangeUser(2e-4,3.0);

  return Upsi2sCS;

}



TGraphErrors *Y3Sdata()
{
  double U3sPt[20] = {0,3,6,9,14,20,30};
  double U3sCS[20] = {0.26, 0.29, 0.24, 0.16, 0.05, 0.03};

  double Nptbin, dPt, dy=4;
  double PTbin[100], DelPTbin[100];
  Nptbin = 6;

  for (Int_t ih = 0; ih < Nptbin; ih++) {
    PTbin[ih] = (U3sPt[ih] + U3sPt[ih+1])/2.0;
    DelPTbin[ih] = U3sPt[ih+1] - U3sPt[ih];
    DelPTbin[ih] = DelPTbin[ih]/2.0;
    dPt = U3sPt[ih+1] - U3sPt[ih];
    U3sCS[ih] = U3sCS[ih]/(dPt*dy); // dPt*dy
  }

  TGraphErrors *Upsi3sCS = new TGraphErrors(Nptbin,PTbin,U3sCS,0,0);
  Upsi3sCS->SetMarkerStyle(22);
  Upsi3sCS->SetMarkerColor(4);
  Upsi3sCS->GetXaxis()->SetTitle("P_{T}^{#Upsilon} GeV/c");
  Upsi3sCS->GetYaxis()->SetTitle("d^{2}#sigma/dp_{T}dy #times B(#mu#mu) (nb/(GeV/c))");
  Upsi3sCS->GetXaxis()->SetRangeUser(0.0,30.0);
  Upsi3sCS->GetYaxis()->SetRangeUser(2e-4,3.0);

  return Upsi3sCS;
}

void Draw2Sby1S(TLegend *legend_ratio)
{
  // 2S/1S
  double Nptbin, dPt, dy=4;
  double PTbin[100], DelPTbin[100];
  Nptbin = 6;

  double UratioPt[10] = {0,3,6,9,14,20,30};
  double Uratio2s1s[10] = {0.22,0.25,0.28,0.33,0.35,0.36};
  double Uratio2s1sStatErr[10] = {0.03,0.03,0.04,0.04,0.08,0.14};
  double Uratio2s1sSysErr[10] = {0.04,0.05,0.04,0.05,0.05,0.06};

  for (Int_t ih = 0; ih < Nptbin; ih++) {
    PTbin[ih] = (UratioPt[ih] + UratioPt[ih+1])/2.0;
    DelPTbin[ih] = UratioPt[ih+1] - UratioPt[ih];
    DelPTbin[ih] = DelPTbin[ih]/2.0;
  }

  TGraphErrors *UpsiRatio2s1s = new TGraphErrors(Nptbin,PTbin,Uratio2s1s,0,Uratio2s1sStatErr);
  UpsiRatio2s1s->SetMarkerStyle(20);
  UpsiRatio2s1s->SetMarkerColor(1);
  //UpsiRatio2s1s->GetXaxis()->SetTitle("#Upsilon(2S)/#Upsilon(1S)");
  UpsiRatio2s1s->GetXaxis()->SetTitle("P_{T}^{#Upsilon} GeV/c");
  UpsiRatio2s1s->GetYaxis()->SetTitle("#sigma #times B(#mu#mu) ratio");
  UpsiRatio2s1s->GetXaxis()->SetRangeUser(0.0,30.0);
  UpsiRatio2s1s->GetYaxis()->SetRangeUser(0.0,0.8);

  TBox *URatio2s1sSys[10];
  for(int j=0;j<6;j++){
    URatio2s1sSys[j] = new TBox(PTbin[j]-0.4,Uratio2s1s[j]-Uratio2s1sSysErr[j],PTbin[j]+0.4,Uratio2s1s[j]+Uratio2s1sSysErr[j]);
  }
  for(int j=0;j<6;j++){
    URatio2s1sSys[j]->SetFillStyle(0000);
    URatio2s1sSys[j]->SetLineColor(6);
    URatio2s1sSys[j]->SetLineWidth(2);
  }

  UpsiRatio2s1s->GetXaxis()->SetRangeUser(0,30);
  UpsiRatio2s1s->Draw("AP");
  for(int j=0;j<6;j++) URatio2s1sSys[j]->Draw("same"); 

  legend_ratio->AddEntry(UpsiRatio2s1s,"#Upsilon(2S)/#Upsilon(1S)", "P");
}

void Draw3Sby1S(TLegend *legend_ratio)
{
 // 3S/1S

  double Nptbin, dPt, dy=4;
  double PTbin[100], DelPTbin[100];
  Nptbin = 6;

  double UratioPt[10] = {0,3,6,9,14,20,30};
  double Uratio3s1s[10] = {0.11,0.11,0.17,0.20,0.26,0.44};
  double Uratio3s1sStatErr[10] = {0.02,0.02,0.03,0.03,0.07,0.16};
  double Uratio3s1sSysErr[10] = {0.02,0.03,0.03,0.03,0.04,0.08};

  for (Int_t ih = 0; ih < Nptbin; ih++) {
    PTbin[ih] = (UratioPt[ih] + UratioPt[ih+1])/2.0;
    DelPTbin[ih] = UratioPt[ih+1] - UratioPt[ih];
    DelPTbin[ih] = DelPTbin[ih]/2.0;
  }

  TGraphErrors *UpsiRatio3s1s = new TGraphErrors(Nptbin,PTbin,Uratio3s1s,0,Uratio3s1sStatErr);
  UpsiRatio3s1s->SetMarkerStyle(21);
  UpsiRatio3s1s->SetMarkerColor(2);

  TBox *URatio3s1sSys[10];
  for(int j=0;j<6;j++){
    URatio3s1sSys[j] = new TBox(PTbin[j]-0.4,Uratio3s1s[j]-Uratio3s1sSysErr[j],PTbin[j]+0.4,Uratio3s1s[j]+Uratio3s1sSysErr[j]);
  }
  
  for(int j=0;j<6;j++){
    URatio3s1sSys[j]->SetFillStyle(0000);
    URatio3s1sSys[j]->SetLineColor(6);
    URatio3s1sSys[j]->SetLineWidth(2);
  }

  UpsiRatio3s1s->Draw("sameP");
  for(int j=0;j<6;j++) URatio3s1sSys[j]->Draw("same"); 

  legend_ratio->AddEntry(UpsiRatio3s1s,"#Upsilon(3S)/#Upsilon(1S)", "P");
  legend_ratio->AddEntry(URatio3s1sSys[0],"Syst. unc.", "F");
 
}
