
// ======================= Plan is to make calculations for differnt quarkonias and then add them with proper factors ==========//
//=============================================================================================================================//
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
const double rJpsi = 0.45;//fm
const double rJpsi2 = rJpsi*rJpsi;
Double_t mg = 0.0;

//============================== Different Quarkonias parameters =================================================//
//===============================================================================================================//

//==== Switch for Upsilon =============//
int isUps=0;



//==================== Parameters JPsi =======================//
Double_t mJpsi = 3.1;
Double_t mD = 1.869;
Double_t mQ = 1.87;
Double_t mQ2 = mQ*mQ;
Double_t ep0=0.64;
Double_t ep02=2.0*(2.0*mQ-mJpsi);
Double_t epCon = 4.0*pi*pow(8./3.0, 3)*pow(ep0, 3)/pow(mQ, 1.5);
Double_t redMass = mQ/2.0;

//const Double_t nCC0 = (10.0*1658)/362.0; ;  
//const Double_t nJpsi0 = (0.18*1658)/362.0; ; 

const Double_t nCC0 = (10.0*1658)/362.0; ;  
const Double_t nJpsi0 = (0.18*1658)/362.0; ; 


//const Double_t FormTau=0.89;
const Double_t FormTau=0.0;
const Double_t CNMSigmaMid=0.15;
const Double_t CNMSigmaFor=0.15; //fm2
//sigma in fm^2 (1 fm^2 = 10 mb)
Double_t SigmaPionDiss = 0.10;
int QQbarVar=1; 

/*
//==================== Parameters Psi =======================//
Double_t mJpsi = 3.68;
Double_t mD = 1.869;
Double_t mQ = 1.87;
Double_t mQ2 = mQ*mQ;
Double_t ep0=0.05;
Double_t ep02=2.0*(2.0*mQ-mJpsi);
Double_t epCon = 4.0*pi*pow(8./3.0, 3)*pow(ep0, 3)/pow(mQ, 1.5);
Double_t redMass = mQ/2.0;
const Double_t nCC0 = (10.0*1658)/362.0; ;  
const Double_t nJpsi0 = (0.18*1658)/362.0; ; 
//const Double_t FormTau=0.89;
const Double_t FormTau=0.0;
const Double_t CNMSigmaMid=0.15;
const Double_t CNMSigmaFor=0.15; //fm2
//sigma in fm^2 (1 fm^2 = 10 mb)
Double_t SigmaPionDiss = 0.10;
int QQbarVar=2; 



//==================== Parameters Chic =======================//
Double_t mJpsi = 3.53;
Double_t mD = 1.869;
Double_t mQ = 1.87;
Double_t mQ2 = mQ*mQ;
Double_t ep0=0.20;
Double_t ep02=2.0*(2.0*mQ-mJpsi);
Double_t epCon = 4.0*pi*pow(8./3.0, 3)*pow(ep0, 3)/pow(mQ, 1.5);
Double_t redMass = mQ/2.0;
const Double_t nCC0 = (10.0*1658)/362.0; ;  
const Double_t nJpsi0 = (0.18*1658)/362.0; ; 

//const Double_t FormTau=0.89;
const Double_t FormTau=0.0;
const Double_t CNMSigmaMid=0.15;
const Double_t CNMSigmaFor=0.15; //fm2
//sigma in fm^2 (1 fm^2 = 10 mb)
Double_t SigmaPionDiss = 0.10;
int QQbarVar=3; 


//Parameters Y(1S)
Double_t mJpsi = 9.46;
Double_t mD = 5.280;
Double_t mQ = 4.2;
Double_t mQ2 = mQ*mQ;
//Double_t ep0=0.7;
Double_t ep0=1.10;
Double_t ep02=ep0*ep0;
Double_t epCon = 4.0*pi*pow(8./3.0, 3)*pow(ep0, 3)/pow(mQ, 1.5);
Double_t redMass = mQ/2.0;
const Double_t nCC0 = (0.5*1658)/362.0;
const Double_t nJpsi0 = (0.01*1658)/362.0; 
const Double_t FormTau=0.0;
const Double_t CNMSigmaMid=0.15;
const Double_t CNMSigmaFor=0.15;
Double_t SigmaPionDiss = 0.10;
int QQbarVar=4; 

//Parameters Y(2S)
Double_t mJpsi = 10.02;
Double_t mD = 5.280;
Double_t mQ = 4.2;
Double_t mQ2 = mQ*mQ;
Double_t ep0=0.54;
Double_t ep02=ep0*ep0;
Double_t epCon = 4.0*pi*pow(8./3.0, 3)*pow(ep0, 3)/pow(mQ, 1.5);
Double_t redMass = mQ/2.0;
const Double_t nCC0 = 0.5;
const Double_t nJpsi0 = 0.01; 
const Double_t FormTau=0.0;
const Double_t CNMSigmaMid=0.20;
const Double_t CNMSigmaFor=0.20;
Double_t SigmaPionDiss = 0.10;
int QQbarVar=5; 

//Parameters Y(3S)
Double_t mJpsi = 10.36;
Double_t mD = 5.280;
Double_t mQ = 4.2;
Double_t mQ2 = mQ*mQ;
Double_t ep0=0.20;
Double_t ep02=ep0*ep0;
Double_t epCon = 4.0*pi*pow(8./3.0, 3)*pow(ep0, 3)/pow(mQ, 1.5);
Double_t redMass = mQ/2.0;
const Double_t nCC0 = 0.5;
const Double_t nJpsi0 = 0.01; 
const Double_t FormTau=0.0;
const Double_t CNMSigmaMid=0.20;
const Double_t CNMSigmaFor=0.20;
Double_t SigmaPionDiss = 0.10;
int QQbarVar=6; 

//Parameters Chib(1P)
Double_t mJpsi = 9.99;
Double_t mD = 5.280;
Double_t mQ = 4.2;
Double_t mQ2 = mQ*mQ;
Double_t ep0=0.67;
Double_t ep02=ep0*ep0;
Double_t epCon = 4.0*pi*pow(8./3.0, 3)*pow(ep0, 3)/pow(mQ, 1.5);
Double_t redMass = mQ/2.0;
const Double_t nCC0 = 0.5;
const Double_t nJpsi0 = 0.01; 
const Double_t FormTau=0.0;
const Double_t CNMSigmaMid=0.20;
const Double_t CNMSigmaFor=0.20;
Double_t SigmaPionDiss = 0.10;
int QQbarVar=7; 
*/

//Matter at extream condition
//T0 is 550 - 580 MeV and tau0 is 0.3
const Double_t mPi = 0.140; 
const Double_t R0 = 7.11;  //1.2*TMath::Power(208,1.0/3.0)
const Double_t R05 = 0.92*R0;
const Double_t tau0 = 0.3;

//const Double_t SS=3.6*1.5*1600;
const Double_t SS=5.0*1.5*1600;
const Double_t Nf=2.5;
const Double_t aq = (7.0*Nf/60.0 + 16.0/90.0)*pi2;
const Double_t ah = 4.5*pi2/90.0;

Double_t aT = 0.1;
//Double_t aT = 0.1;
//Double_t z0=1.8*tau0; //0
//Double_t vZ=1.4;     //1.0
//for longitudnal
//Double_t aT = 0.0;   // 0
Double_t z0=0.0; //0
Double_t vZ=1.0;     //1.0

const Double_t VTau0 = (R05+0.5*aT*tau0*tau0)*(R05+0.5*aT*tau0*tau0)*(z0+vZ*tau0)*pi;
const Double_t T0=TMath::Power(SS/(4.0*aq*VTau0),1.0/3.0)*hbarc;
const Double_t TC = 0.170;
const Double_t TF = 0.140;
//const Double_t tauf = pow(T0/TC, 3.)*tau0;
const Double_t nPart0 = 393;
const Double_t nColl0 = 1747;

int NTau; double stepTau;
double Tau[10000], TempTau[10000], fQGP[10000];


// Functions Xu and Kharjeev
Double_t DissFuncXu(Double_t pT, Double_t T, Double_t n);
Double_t DissRateXu(Double_t pT, Double_t T);
Double_t SigmaD(Int_t Flag, Double_t q0);
Double_t SigmaFS(Double_t s);


// Formation functions
Double_t FormRate(Double_t Temp);
Double_t FormFun(Double_t p1, Double_t p2, Double_t theta1, Double_t theta2, Double_t phi1, 
		 Double_t phi2);

Double_t FormRateMC_P(Double_t Temp, Double_t Pt);

Double_t FormFun2(Double_t p1, Double_t p2, Double_t CosTheta);
Double_t IntFormFun2(Double_t T);
Double_t IntFormFun2_P(Double_t P, Double_t T);
Double_t IntFormFun2_P_IntP(Double_t T);
Double_t IntForm(Double_t PtMin, Double_t R0Cent);
Double_t IntFormVsPt(Double_t PtMin, Double_t R0Cent);

Double_t RegenratedQuarkoniaNPart(Double_t NCC, Double_t NJPsi, Double_t R0);


// Dissociation functions
Double_t IntDiss_All(Double_t PtMin);
Double_t IntDiss_PtInt(Double_t PtMin);
Double_t SigmaQuasiGluon(Int_t Flag, Double_t PJPsi, Double_t T);
Double_t SigmaGluonDissS(Double_t s);
Double_t SigmaGluonDissS_Med(Double_t s, Double_t T);
Double_t EDiss(Double_t Flag, Double_t T );
Double_t SigmaThermalAct(Double_t Flag, Double_t T);


//============ jpsi pion =================//
Double_t fpion(Double_t pPi, Double_t T);
Double_t PionJPsiDiss(Double_t P1, Double_t T);
Double_t RhoPi(Double_t T);
Double_t PionDiss_All(Double_t PtMin);
Double_t PionDiss_PtInt(Double_t PtMin);

//============ Imaginary Potential =================//
Double_t RateImag(Double_t T);
Double_t phi(Double_t r);



// Dynamics 
Double_t Npart(int BinLow, int BinHigh);
Double_t NColl(int BinLow, int BinHigh);
Double_t CalculateTandf(int Flag, Double_t T0Cent, Double_t R0Cent, Double_t tauCCent, Double_t tauhCent, Double_t taufCent);
Double_t TauToTemp_All(Int_t Flag, Double_t T0Cent, Double_t R0Cent, Double_t Tau);
Double_t FQGP(Int_t Flag, Double_t R0Cent, Double_t TauCCent, Double_t TauHCent, Double_t Tau);
Double_t Tau0ToTauC(Int_t Flag, Double_t T0Cent, Double_t R0Cent);
Double_t TauCToTauh(Int_t Flag, Double_t TauC, Double_t R0Cent);
Double_t TauhToTauf(Int_t Flag, Double_t Tauh, Double_t R0Cent);
Double_t Shadowing(Double_t SigmaAbs, Double_t NPart);
Double_t fGluon(Double_t p, Double_t T);
Double_t fcharm(Double_t p, Double_t T);



//============== Functions for data Graphs =================//
void Draw_CMS_JPsi_RaaVspT(TLegend *lgd);
void Draw_ALICEFor_JPsi_RaaVspT(TLegend *lgd);
void Draw_CMS_JPsi_RaaVsRap(TLegend *lgd);
void Draw_CMS_JPsi_RaaVsNpart(TLegend *lgd);
void Draw_ALICEFor_JPsi_RaaVsNpart(TLegend *lgd);  
void Draw_ALICEMid_JPsi_RaaVsNpart(TLegend *lgd);

void Draw_CMS_Y1S_RaaVsNpart(TLegend *lgd);
void Draw_CMS_Y2S_RaaVsNpart(TLegend *lgd);
void Draw_ALICEFor_Y1S_RaaVsNpart(TLegend *lgd);
void Draw_CMS_Y1S_RaaVspT(TLegend *lgd);

void Draw_AllDataGraphs();



//================================================================================================//
// Jpsi pT from Pythia
TFile *filejpsi=new TFile("JPsiPt.root","R");
TH1D *Jpsi_Pt = (TH1D*)filejpsi->Get("diMuonsPt_Gen");
TH1D *JPsiPtCut;

TFile *fileUpsilon=new TFile("dimuonGenPt1s2sPbPb_Pt.root","R");
TH1D *Y1S_Pt = (TH1D*)fileUpsilon->Get("diMuonsPt_Gen1S");
TH1D *Y2S_Pt = (TH1D*)fileUpsilon->Get("diMuonsPt_Gen2S");

TFile *fileFormRateALICE=new TFile("FormOut.root","R");
TGraph *grNJpsiStat = (TGraph*)fileFormRateALICE->Get("FormALICE");



//================================== Shadowing from root file ==========================//
TFile *fileShadowing = new TFile("Shadowing.root","R");

TH1D *HistJpsiRaaShVsPt = (TH1D*)fileShadowing->Get("HistJpsiRaaShVsPt");
TH1D *HistJpsiRaaShUVsPt = (TH1D*)fileShadowing->Get("HistJpsiRaaShUVsPt");
TH1D *HistJpsiRaaShLVsPt = (TH1D*)fileShadowing->Get("HistJpsiRaaShLVsPt");

TH1D *HistUpsilonRaaShVsPtMid = (TH1D*)fileShadowing->Get("HistUpsilonRaaShVsPtMid");
TH1D *HistUpsilonRaaShLVsPtMid = (TH1D*)fileShadowing->Get("HistUpsilonRaaShLVsPtMid");
TH1D *HistUpsilonRaaShUVsPtMid = (TH1D*)fileShadowing->Get("HistUpsilonRaaShUVsPtMid");


TH1D *HistUpsilonRaaShVsPtFor = (TH1D*)fileShadowing->Get("HistUpsilonRaaShVsPtFor");
TH1D *HistUpsilonRaaShLVsPtFor = (TH1D*)fileShadowing->Get("HistUpsilonRaaShLVsPtFor");
TH1D *HistUpsilonRaaShUVsPtFor = (TH1D*)fileShadowing->Get("HistUpsilonRaaShUVsPtFor");












void jpsiProd()
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
  gStyle->SetPadLeftMargin(0.17);
  //  gStyle->SetPadBottomMargin(0.10);
  //  gStyle->SetPadTopMargin(0.03);
  //  gStyle->SetPadRightMargin(0.04);  
  //gStyle->SetPadLeftMargin(0.10);
  
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

  
  cout<<" T0 "<<T0<<"  aq "<<aq<<" ah "<<ah<<endl;
  
  Char_t OutFileName[100];

  if(QQbarVar==1){sprintf(OutFileName,"JPsiCalculations.root");}
  if(QQbarVar==2){sprintf(OutFileName,"PsiCalculations.root");}
  if(QQbarVar==3){sprintf(OutFileName,"ChiCCalculations.root");}

  if(QQbarVar==4){sprintf(OutFileName,"Y1SCalculations.root");}
  if(QQbarVar==5){sprintf(OutFileName,"Y2SCalculations.root");}
  if(QQbarVar==6){sprintf(OutFileName,"Y3SCalculations.root");}
  if(QQbarVar==7){sprintf(OutFileName,"ChiBCalculations.root");}


  TFile *OutFile =new TFile(OutFileName,"RECREATE");
  
  TLatex *tb = new TLatex();
  tb->SetNDC(); 
  tb->SetTextAlign(12);
  tb->SetTextColor(1);
  tb->SetTextSize(0.040);
  
  int Disso=0;
  int Form =1;
  
  TLegend *lcat[100];
  for(int i =0;i<90;i++)
    {
      lcat[i]= new TLegend( 0.55,0.59,0.84,0.78);;
      lcat[i]->SetBorderSize(0);
      lcat[i]->SetFillStyle(0);
      lcat[i]->SetFillColor(0);
      lcat[i]->SetTextSize(0.040);
    }

  
  // j/psi pT histogram  
  cout << "J/psi hist Integral = " << Jpsi_Pt->Integral() << endl;
  cout<<Jpsi_Pt->GetMean()<<"   "<<Jpsi_Pt->GetRMS()<<"  "<<Jpsi_Pt->GetSize()<<"  "<<Jpsi_Pt->FindBin(6.5)<<"  "<<Jpsi_Pt->GetBinWidth(1)<<endl;
  Jpsi_Pt->Rebin(5); 
  cout << "J/psi hist Integral = " << Jpsi_Pt->Integral() << endl;
  cout<<Jpsi_Pt->GetMean()<<"   "<<Jpsi_Pt->GetRMS()<<"  "<<Jpsi_Pt->GetSize()<<"  "<<Jpsi_Pt->FindBin(6.5)<<"  "<<Jpsi_Pt->GetBinWidth(1)<<endl;
  Y1S_Pt->Rebin(5); 
  cout << "Y1S hist Integral = " << Y1S_Pt->Integral() << endl;
  cout<<Y1S_Pt->GetMean()<<"   "<<Y1S_Pt->GetRMS()<<"  "<<Y1S_Pt->GetSize()<<"  "<<Y1S_Pt->FindBin(6.5)<<"  "<<Y1S_Pt->GetBinWidth(1)<<endl;
  Y2S_Pt->Rebin(5); 
  cout << "Y2S hist Integral = " << Y2S_Pt->Integral() << endl;
  cout<<Y2S_Pt->GetMean()<<"   "<<Y2S_Pt->GetRMS()<<"  "<<Y2S_Pt->GetSize()<<"  "<<Y2S_Pt->FindBin(6.5)<<"  "<<Y2S_Pt->GetBinWidth(1)<<endl;
  


  //new TCanvas;
  //Jpsi_Pt->Draw();

  //TH1D *Hist = new TH1D("HistPt","HistPt",100.0,0.0,50.0);
  //for(int i=0;i<Jpsi_Pt->GetSize();i++){cout<<Jpsi_Pt->GetBinCenter(i)<<"   "<<Hist->GetBinCenter(i)<<endl;}


  //================== Test Data Graphs ===========================//
  //Draw_AllDataGraphs();
  //return;
 //============== JPsi gluon dissociation cross section graph =======================//
  Double_t smin=0.0;
  Double_t smax = 500.0;
  Double_t step = 0.4;
  int NS = (int)((smax-smin)/step); 
  Double_t ss[2000], sigF[2000],sigD[2000];
  
  
  cout<<" SS "<<" SigmaF "<<" SigmaD "<<endl;
  for(int i=0; i<NS; i++) {
    ss[i] = smin + step*i;

    
    sigF[i] = SigmaFS(ss[i])*hbarc2;
    sigD[i] =SigmaGluonDissS(ss[i])*hbarc2;
  
    //cout<<sigF[i]<<"   "<<sigD[i]<<endl;

  }
  
  
  TGraph *grSigF = new TGraph(NS, ss, sigF);
  grSigF->SetName("grSigF");
  grSigF->SetTitle("grSigF");
  
  grSigF->SetLineWidth(2);
  grSigF->GetXaxis()->SetTitle("s (GeV^{2})");
  grSigF->GetYaxis()->SetTitle("#sigma_{F} (fm^{2}) ");
  


  TGraph *grSigD = new TGraph(NS, ss, sigD);
  grSigD->SetName("grSigD");
  grSigD->SetTitle("grSigD");
  grSigD->SetLineWidth(2);
  grSigD->SetLineColor(2);
  grSigD->GetXaxis()->SetTitle("s (GeV^{2})");
  grSigD->GetYaxis()->SetTitle("#sigmaD (fm^{2}) ");
    
  new TCanvas;
  gPad->SetTicks();
  grSigF->Draw("AL");
  //grSigD->Draw("Lsame");


  Double_t q0min=0.0;
  Double_t q0max = 3.0;
  Double_t q0step = 0.01;
  int NQ0 = (int)((q0max-q0min)/q0step); 
  Double_t Q0[2000], SigDQ0[2000];
  
  for(int i=0; i<NQ0; i++) {
    Q0[i] = q0min + q0step*i;
    SigDQ0[i] = SigmaD(1,Q0[i])*hbarc2*10.0;
  }
  
  TGraph *grSigDQ0 = new TGraph(NQ0, Q0, SigDQ0);
  grSigDQ0->SetName("grSigDQ0");
  grSigDQ0->SetTitle("grSigDQ0");
  grSigDQ0->SetLineWidth(2);
  grSigDQ0->GetXaxis()->SetTitle("q^{0} (GeV)");
  grSigDQ0->GetYaxis()->SetTitle("#sigma (mb)");
  
    
  lcat[2] = new TLegend( 0.45,0.67,0.95,0.77);
  lcat[2]->SetBorderSize(0);
  lcat[2]->SetFillStyle(0);
  lcat[2]->SetFillColor(0);
  lcat[2]->SetTextSize(0.040);
  lcat[2]->AddEntry(grSigDQ0,"Dipole Approx","L");
    
  new TCanvas;
  gPad->SetTicks();
  grSigDQ0->Draw("APL");
  tb->DrawLatex(0.46,0.82,"g+J/#psi #rightarrow c+#bar{c}");
  lcat[2]->Draw("same");

  gPad->SaveAs("Fig2_SigmaDq0.eps");
  gPad->SaveAs("Fig2_SigmaDq0.pdf");
  gPad->SaveAs("Fig2_SigmaDq0.png");
  

  grSigDQ0->Write();
  grSigF->Write();
  grSigD->Write();
  
  
  //return;

  // ====================  Npart vs Ncoll graphs =========================================
  Double_t NPartVal[50];
  Double_t NCollVal[50];
  Double_t dNdEtaNPartBy2Val[50];
  Double_t NuclShadowing[50];
  for(int i=0;i<40;i++){
    NuclShadowing[i]=Shadowing(0.2,Npart(i,i+1));
    NPartVal[i]=Npart(i,i+1);
    NCollVal[i]=NColl(i,i+1);
    dNdEtaNPartBy2Val[i]= ( 2.441*(0.788*NPartVal[i] + (1-0.788)*NCollVal[i]) )/(0.5*NPartVal[i]) ;
  }

  cout << "NColl(0,40)"<< "    " << "NColl(0,2)" << endl;
  cout << NColl(0,40)<< "    " << NColl(0,2) << endl;
  
  TGraph *grNPartVsNColl = new TGraph(40, NPartVal,NCollVal);
  grNPartVsNColl->SetLineWidth(2);
  grNPartVsNColl->SetMarkerStyle(20);
  grNPartVsNColl->GetXaxis()->SetTitle("N_{Part}");
  grNPartVsNColl->GetYaxis()->SetTitle("N_{Coll}");
  
  TF1 *fa2 = new TF1("fa2","pol2",0.1,500.0);
  grNPartVsNColl->Fit("fa2","M","",0.0,400.0);
  
  //new TCanvas;
  //gPad->SetTicks();
  //grNPartVsNColl->Draw("AP");
  
  //gPad->SaveAs("NCollVsNpart.png");  
  //gPad->SaveAs("NCollVsNpart.eps");  
  
  TGraph *grTwoCompModel = new TGraph(40, NPartVal, dNdEtaNPartBy2Val);
  grTwoCompModel->SetLineWidth(2);
  grTwoCompModel->SetMarkerStyle(21);
  grTwoCompModel->GetXaxis()->SetTitle("N_{Part}");
  grTwoCompModel->GetYaxis()->SetTitle("#frac{dN}{d#eta}/(#frac{N_{Part}}{2})");
  
  //new TCanvas;
  //gPad->SetTicks();
  //grdNDetaNpart->Draw("AP");
  //grTwoCompModel->Draw("Psame");
  
  TGraph *grNPartVsNuclAbs = new TGraph(40, NPartVal,NuclShadowing);
  grNPartVsNuclAbs->SetLineWidth(2);
  grNPartVsNuclAbs->SetMarkerStyle(20);
  grNPartVsNuclAbs->GetXaxis()->SetTitle("N_{Part}");
  grNPartVsNuclAbs->GetYaxis()->SetTitle("S_{Nucl Abs}");
  grNPartVsNuclAbs->GetYaxis()->SetRangeUser(0.0,1.0);
  
  //new TCanvas;
  //grNPartVsNuclAbs->Draw("AL");
  
  // ================ dn/deta graph for making Temp as a function of nPart ==========================================//
  Double_t NPartdNdEta[10] = {382.8,329.7,260.5,186.4,128.9,85.0,52.8,30.0,15.8};
  Double_t Err_NPartdNdEta[10] = {3.1,4.6,4.4,3.9,3.3,2.6,2.0,1.3,0.6};
  
  Double_t dNdEtabyNpartby2[10] = {8.4,7.9,7.4,7.0,6.6,6.1,5.7,5.1,4.4};
  Double_t Err_dNdEtabyNpartby2[10] = {0.3,0.3,0.3,0.3,0.3,0.3,0.3,0.3,0.4};
  
  TGraphErrors *grdNDetaNpart = new TGraphErrors(9,NPartdNdEta,dNdEtabyNpartby2,Err_NPartdNdEta,Err_dNdEtabyNpartby2);
  grdNDetaNpart->SetLineWidth(2);
  grdNDetaNpart->SetMarkerStyle(20);
  grdNDetaNpart->GetYaxis()->SetRangeUser(3.5,9.0);
  grdNDetaNpart->GetYaxis()->SetTitle("#frac{dN}{d#eta}/(#frac{N_{Part}}{2})");
  grdNDetaNpart->GetXaxis()->SetTitle("N_{Part}");
  
  //new TCanvas;
  //gPad->SetTicks();
  //gPad->SetBottomMargin(0.14);
  //grdNDetaNpart->Draw("AP");
  //gPad->SaveAs("dNdEtaVsNpart.png");  
  //gPad->SaveAs("dNdEtaVsNpart.eps");     
  
  TF1 *funDnDetaNPart = new TF1("funDnDetaNPart","[0]*TMath::Power(x,[1])/(0.5*x)",0.0,500);
  funDnDetaNPart->SetParameters(1.317,1.190);
  funDnDetaNPart->SetLineColor(4);
  
  TF1 *funTwoComp = new TF1("funTwoComp","[0]*( [1]*x + (1-[1])*([2] + [3]*x +[4]*x*x)) /(0.5*x)",0.0,500);
  funTwoComp->SetLineColor(2);
  funTwoComp->SetParameter(0,2.441);
  funTwoComp->SetParameter(1,0.788);
  funTwoComp->SetParameter(2,-13.4708);
  funTwoComp->SetParameter(3,1.69143);
  funTwoComp->SetParameter(4,0.00709679);

  lcat[3] = new TLegend( 0.37,0.22,0.87,0.40);
  lcat[3]->SetBorderSize(0);
  lcat[3]->SetFillStyle(0);
  lcat[3]->SetFillColor(0);
  lcat[3]->SetTextSize(0.040);
  lcat[3]->AddEntry(funDnDetaNPart,"#alpha N_{Part}^{#beta}","L");
  lcat[3]->AddEntry(funTwoComp,"fN_{Part} + (1-f)N_{Coll}","L");

  new TCanvas;
  grdNDetaNpart->Fit("funDnDetaNPart","M","",10.0,400.0);
  grdNDetaNpart->Fit("funTwoComp","M","",10.0,400.0);

  grdNDetaNpart->Draw("AP");
  funDnDetaNPart->Draw("same");
  funTwoComp->Draw("same");
  lcat[3]->Draw("same");
  
  Double_t TempNpart[400];
  Double_t TempNpart3[400];
  Double_t NpartVal[400];
  
  for(int i=0;i<=80;i++)
    {
      NpartVal[i]=i*5;
      TempNpart[i]=T0*TMath::Power(funDnDetaNPart->Eval(NpartVal[i])/dNdEtabyNpartby2[0],1.0/3); //ALICE Func
      TempNpart3[i]=T0*TMath::Power(funTwoComp->Eval(NpartVal[i])/dNdEtabyNpartby2[0],1.0/3); //Two Comp model
    }

  TGraph *grTempVsNpart = new TGraph(80, NpartVal,TempNpart);
  grTempVsNpart->SetLineWidth(2);
  grTempVsNpart->SetMarkerStyle(20);
  grTempVsNpart->SetMarkerColor(4);
  
  grTempVsNpart->GetXaxis()->SetTitle("N_{Part}");
  grTempVsNpart->GetYaxis()->SetTitle("T (GeV)");
  grTempVsNpart->GetYaxis()->SetRangeUser(0.1,1.0);
  
  TGraph *grTempVsNpart3 = new TGraph(80, NpartVal,TempNpart3);
  grTempVsNpart3->SetLineWidth(2);
  grTempVsNpart3->SetMarkerStyle(20);
  grTempVsNpart3->SetMarkerColor(2);


  new TCanvas;
  gPad->SetTicks();
  grTempVsNpart->Draw("AP");
  grTempVsNpart3->Draw("Psame");
  lcat[3]->Draw("same");
  gPad->SaveAs("NpartVsTemp.png");  
  gPad->SaveAs("NpartVsTemp.eps");  
  
  
  //================================= Temp Vs Tau Graphs ====================================//
 
  //int NTau; double stepTau;
  //double Tau[10000], TempTau[10000], fQGP[10000];
 
  Double_t T0Cen = T0*TMath::Power((funTwoComp->Eval(Npart(0,2)))/dNdEtabyNpartby2[0],1.0/3.0);
  double TauL[10000], TempTauL[10000], fQGPL[10000];
  int NTauL;
  Double_t TauC1=Tau0ToTauC(1,T0Cen,R05);
  Double_t TauH1 = TauCToTauh(1,TauC1,R05);
  Double_t TauF1 =TauhToTauf(1,TauH1,R05);
  CalculateTandf(1, T0Cen, R05, TauC1, TauH1,TauF1);
  
  NTauL= NTau;
  cout<<" Long " << T0Cen<<"  "<<R05<<"  "<<TauC1<<"  "<<TauH1<<"   "<<TauF1<<endl;
  for(int i=0;i<NTauL;i++){
    TauL[i]=Tau[i];
    TempTauL[i] = TempTau[i];
    fQGPL[i]=fQGP[i];
  }
 
  double TauC[10000], TempTauC[10000], fQGPC[10000];
  int NTauC;  

  Double_t TauC2=Tau0ToTauC(2,T0Cen,R05);
  Double_t TauH2 = TauCToTauh(2,TauC2,R05);
  Double_t TauF2=TauhToTauf(2, TauH2, R05);
  CalculateTandf(2,T0Cen,R05,TauC2,TauH2,TauF2);
  NTauC= NTau;
  for(int i=0;i<NTau;i++){
    TauC[i]=Tau[i];
    TempTauC[i] = TempTau[i];
    fQGPC[i]=fQGP[i];
  }


  cout<<" Cylind  " << T0Cen<<"  "<<R05<<"  "<<TauC2<<"  "<<TauH2<<"  "<<TauF2<<endl;

  TGraph *grTempVsTauAna = new TGraph(NTauL,TauL,TempTauL);
  grTempVsTauAna->SetName("grTempVsTauL");
  grTempVsTauAna->SetTitle("grTempVsTauL");
  grTempVsTauAna->SetLineColor(2);
  grTempVsTauAna->SetLineWidth(2);
  grTempVsTauAna->SetLineStyle(1);
  grTempVsTauAna->GetYaxis()->SetTitle("Temperature (GeV)");
  grTempVsTauAna->GetXaxis()->SetTitle("#tau (fm)");
  
  TGraph *grTempVsTauAnaB = new TGraph(NTauC,TauC,TempTauC);
  grTempVsTauAnaB->SetName("grTempVsTauC");
  grTempVsTauAnaB->SetTitle("grTempVsTauC");
  grTempVsTauAnaB->SetLineColor(4);
  grTempVsTauAnaB->SetLineWidth(2);
  grTempVsTauAnaB->SetLineStyle(2);

  TLegend *legd5 = new TLegend( 0.25,0.78,0.89,0.92);
  legd5->SetBorderSize(0);
  legd5->SetFillStyle(0);
  legd5->SetFillColor(0);
  legd5->SetTextSize(0.040);
  legd5->AddEntry(grTempVsTauAna,"Longitudinal expansion","L");
  legd5->AddEntry(grTempVsTauAnaB,"Cylindrical expansion","L");
  
  TLine *l1 = new TLine(0.0,0.16,10.0,0.16);
  l1->SetLineWidth(2);
  l1->SetLineColor(2);

  new TCanvas;  
  gPad->SetTicks(1);
  TAxis *Xaxis3 = grTempVsTauAna->GetXaxis();
  Xaxis3->SetLimits(0.0,20.0);
  grTempVsTauAna->GetYaxis()->SetRangeUser(0.0,0.7);
  grTempVsTauAna->Draw("AL");
  grTempVsTauAnaB->Draw("Lsame");
  tb->DrawLatex(0.16,0.90,"(a)");
  legd5->Draw("Lsame");
  gPad->SaveAs("Fig1a_TauVsTemp.eps");
  gPad->SaveAs("Fig1a_TauVsTemp.png");
  gPad->SaveAs("Fig1a_TauVsTemp.pdf");

  TGraph *grFQGPVsTau = new TGraph(NTauL,TauL,fQGPL);
  grFQGPVsTau->SetName("grFQGPVsTauL");
  grFQGPVsTau->SetTitle("grFQGPVsTauL");
  grFQGPVsTau->SetLineColor(2);
  grFQGPVsTau->SetLineWidth(2);
  grFQGPVsTau->SetLineStyle(1);
  grFQGPVsTau->GetYaxis()->SetTitle("QGP fraction");
  grFQGPVsTau->GetXaxis()->SetTitle("#tau (fm)");

  TGraph *grFQGPVsTau2 = new TGraph(NTauC,TauC,fQGPC);
  grFQGPVsTau2->SetName("grFQGPVsTauC");
  grFQGPVsTau2->SetTitle("grFQGPVsTauC");
  grFQGPVsTau2->SetLineColor(4);
  grFQGPVsTau2->SetLineWidth(2);
  grFQGPVsTau2->SetLineStyle(2);

  
  new TCanvas;  
  gPad->SetTicks(1);
  grFQGPVsTau->GetYaxis()->SetRangeUser(0.0,1.4);
  TAxis *Xaxis4 = grFQGPVsTau->GetXaxis();
  Xaxis4->SetLimits(0.,20.0);
  grFQGPVsTau->Draw("AL");
  grFQGPVsTau2->Draw("Lsame");
  legd5->Draw("Lsame");
  tb->DrawLatex(0.16,0.90,"(b)");
  gPad->SaveAs("Fig1b_TauVsFQGP.eps");
  gPad->SaveAs("Fig1b_TauVsFQGP.png");
  gPad->SaveAs("TFig1b_auVsFQGP.pdf");
  
  //return;
  // ========================================= Shadowing ALICE JPsi ===============================//
  //ALICE 
  int nbinsALICERpPb=2;
  Double_t RapALICE[2]={-3.71,2.78};
  Double_t ErrRapALICE[2]={0.75,0.75};
  Double_t RpPbALICE[2] = {1.08,0.70}; 
  Double_t StatErrRpPbALICE[2] = {0.01,0.01};

  TGraphErrors *grRpPbALICE = new TGraphErrors(nbinsALICERpPb, RapALICE, RpPbALICE, ErrRapALICE, StatErrRpPbALICE);
  grRpPbALICE->SetMarkerStyle(20);
  grRpPbALICE->SetMarkerColor(2);
  grRpPbALICE->GetXaxis()->SetTitle("y_{CM}");
  grRpPbALICE->GetYaxis()->SetTitle("R_{pPb}");
  grRpPbALICE->GetYaxis()->SetRangeUser(0.0,1.4);

  Double_t RapVal[11]={-5.0,-4.0-3.0,-2.0,-1.0,0.0,1.0,2.0,3.0,4.0,5.0};
  Double_t ShadowRap[11];
  
  for(int i=0;i<=10;i++) {
    RapVal[i]=i-5;    
    ShadowRap[i]=Shadowing(0.25,Npart(0,2));
    //cout<<i<<"  "<<RapVal[i]<<"  "<<ShadowRap[i]<<endl;
  }
  
  TGraph *grRapVsNuclAbs = new TGraph(11, RapVal,ShadowRap);
  grRapVsNuclAbs->SetLineWidth(2);
  grRapVsNuclAbs->SetMarkerStyle(20);
  grRapVsNuclAbs->GetXaxis()->SetTitle("y_{CM}");
  grRapVsNuclAbs->GetYaxis()->SetTitle("S_{Nucl Abs}");
  grRapVsNuclAbs->GetYaxis()->SetRangeUser(0.0,1.0);
  
  // new TCanvas;
  //grRapVsNuclAbs->Draw("AP");
  //new TCanvas;
  //gPad->SetTicks();
  //grRpPbALICE->Draw("AP");
  //grRapVsNuclAbs->Draw("Lsame");

  TF1 *FuncCNM =new TF1("FuncCNM","TMath::Exp(-([0]*[1]*x))",-5.0,5.0);
  FuncCNM->FixParameter(0,0.14);
 
  //new TCanvas;
  //gPad->SetTicks();
  //grRpPbALICE->Draw("AP");
  //grRpPbALICE->Fit("FuncCNM","M","",-4.5,5.0);

  //========================================================================//
  //================== JPsi - pion dissociation rates =====================//
  //=======================================================================//


  Double_t TempPi[1000];  
  Double_t LambdaDPi[1000]={0};
  Double_t RhoPiVal[1000]={0};
  Double_t SigmaV[1000]={0};

  Double_t TempMinPi=0.1;
  Double_t TempMaxPi=0.24;
  Double_t TempStepPi=0.005;


  int NTempPi= (int)((TempMaxPi-TempMinPi)/TempStepPi);

  for(int l = 0; l<=NTempPi; l++) {
    TempPi[l]=TempMinPi+TempStepPi*l;
    LambdaDPi[l]= PionJPsiDiss(2.0,TempPi[l]); //GeV
    RhoPiVal[l]=RhoPi(TempPi[l]);//GeV3
    SigmaV[l]=(LambdaDPi[l]/RhoPiVal[l])*(10.0*hbarc2);
    //SigmaV[l]=(RhoPiVal[l]);
  
  }

  TGraph *grLambdaDPi = new TGraph(NTempPi,TempPi,SigmaV);
  grLambdaDPi->SetMarkerStyle(20);
  grLambdaDPi->SetLineWidth(2);
  grLambdaDPi->SetLineColor(2);
  grLambdaDPi->GetXaxis()->SetTitle("T(GeV)");
  //grLambdaDPi->GetYaxis()->SetTitle("#lambda_{D_{#pi}}(mb)");
  grLambdaDPi->GetYaxis()->SetTitle("<#sigma v_{rel}> (mb)");
  grLambdaDPi->GetYaxis()->SetRangeUser(0.0,1.0);

  new TCanvas;
  gPad->SetTicks(1);
  grLambdaDPi->Draw("AL");

  //return;

//========================================================================//
  // Dissociation rates as a function of temp.
  Double_t Temp[1000];  
  Double_t LambdaD_Khar[1000]={0},  LambdaD_KharAll[1000]={0};
  Double_t LambdaD_Khar36[1000]={0},  LambdaD_Khar86[1000]={0};
  
  //from different program
  Double_t LambdaD_GluonDissVac[1000]={0}; 
  Double_t LambdaFR[1000]={0},LambdaFR0[1000]={0};
  
  Double_t LambdaF_TripleInt[1000]={0};
  Double_t LambdaF[1000]={0};
 
  Double_t LambdaFMC_P[1000]={0};

  Double_t LambdaFMC_P1[1000]={0};
  Double_t LambdaFMC_P2[1000]={0};
  Double_t LambdaFMC_P3[1000]={0};

  Double_t TempMin=0.17;
  Double_t TempMax=1.0;
  Double_t TempStep=0.05;
  int NTemp= (int)((TempMax-TempMin)/TempStep);
  
  cout<<" ==================== Formation Rate ===================== " <<endl;
  cout<<"Temp: "<<" MC Int  "<< " Triple Int " << " (MC Int - Triple Int / MC Int)%"<<endl;
 
  //NTemp=1;
  
  //char HistName[100]; 

  for(int l = 0; l<=NTemp; l++) {
    Temp[l]=TempMin+TempStep*l;
    //Dissociation Rates
    if(Disso ==1){
      LambdaD_GluonDissVac[l]=SigmaQuasiGluon(1,0.0,Temp[l])/hbarc;
      LambdaD_Khar[l]= SigmaQuasiGluon(1,0.0,Temp[l])/hbarc;
      LambdaD_Khar36[l]= SigmaQuasiGluon(1,3.6,Temp[l])/hbarc;
      LambdaD_Khar86[l]= SigmaQuasiGluon(1,8.6,Temp[l])/hbarc;
    }
    
    
    //Formation Rates with temperature
    if(Form ==2){
      LambdaF[l] = IntFormFun2(Temp[l]);  //Triple int
      LambdaF_TripleInt[l] = IntFormFun2_P_IntP(Temp[l]);
      LambdaFR[l] = FormRate(Temp[l]); //MC      
      
      //Double_t Y1=Jpsi_Pt->GetBinContent(Jpsi_Pt->FindBin(0.25))/Jpsi_Pt->GetBinWidth(0);
      //Double_t Y2=Jpsi_Pt->GetBinContent(Jpsi_Pt->FindBin(1.25))/Jpsi_Pt->GetBinWidth(0);
      //Double_t Y3=Jpsi_Pt->GetBinContent(Jpsi_Pt->FindBin(2.25))/Jpsi_Pt->GetBinWidth(0);
	
      LambdaFMC_P1[l]=FormRateMC_P(Temp[l],2.25);
      LambdaFMC_P2[l]=FormRateMC_P(Temp[l],3.25);
      LambdaFMC_P3[l]=FormRateMC_P(Temp[l],4.25);
      
      cout<<Temp[l]<<"   "<< LambdaFR[l]<<"     "<<LambdaF[l]<<"   "<<  LambdaF_TripleInt[l] <<endl;
    }
  }
  


 // MC Int 
  TGraph *grFormRateR = new TGraph(NTemp,Temp,LambdaFR);
  grFormRateR->SetLineWidth(2);
  grFormRateR->SetLineColor(2);
  
  //MC Pt =0
  TGraph *grFormRateR0 = new TGraph(NTemp,Temp,LambdaFR0);
  grFormRateR0->SetLineWidth(2);
  grFormRateR0->SetLineColor(1);
  
  //Triple Integral
  TGraph *grFormRate_TripleInt = new TGraph(NTemp,Temp,LambdaF);
  grFormRate_TripleInt->SetMarkerStyle(20);
  grFormRate_TripleInt->SetLineWidth(2);
  grFormRate_TripleInt->SetLineColor(4);
  
  TGraph *grFormRate_TripleInt_P = new TGraph(NTemp,Temp,LambdaF_TripleInt);
  grFormRate_TripleInt_P->SetMarkerStyle(20);
  grFormRate_TripleInt_P->SetLineWidth(2);
  grFormRate_TripleInt_P->SetLineColor(6);
  
  
  TLegend *legd3 = new TLegend( 0.31,0.71,0.95,0.85);
  legd3->SetBorderSize(0);
  legd3->SetFillStyle(0);
  legd3->SetFillColor(0);
  legd3->SetTextSize(0.040);
  legd3->AddEntry(grFormRateR, "Form (MC) Full Integral", "L");
  legd3->AddEntry(grFormRate_TripleInt, "Form Triple Integral", "L");
  
  TLegend *legd4 = new TLegend( 0.20,0.72,0.84,0.86);
  legd4->SetBorderSize(0);
  legd4->SetFillStyle(0);
  legd4->SetFillColor(0);
  legd4->SetTextSize(0.040);
  legd4->AddEntry(grFormRateR, "Form (MC) Full Integral", "L");
  legd4->AddEntry(grFormRate_TripleInt, "Form Triple Integral", "L");
  legd4->AddEntry(grFormRate_TripleInt_P, "Form Triple Integral p2=P-p1", "L");
  
  new TCanvas;
  gPad->SetTicks();
  grFormRateR->Draw("AL");
  grFormRate_TripleInt->Draw("sameL");
  legd3->Draw("same");
  

  
  new TCanvas;
  grFormRateR->GetXaxis()->SetTitle("T (GeV)");
  grFormRateR->GetYaxis()->SetTitle("Form Rate(fm^{2})");
  grFormRateR->GetYaxis()->SetRangeUser(0.0,0.0145);
  gPad->SetTicks();
  grFormRateR->Draw("AL");
  grFormRate_TripleInt->Draw("sameL");
  grFormRate_TripleInt_P->Draw("sameL");
  legd4->Draw("same");
  

  
  TLegend *legd6 = new TLegend( 0.23,0.72,0.87,0.86);
  legd6->SetBorderSize(0);
  legd6->SetFillStyle(0);
  legd6->SetFillColor(0);
  legd6->SetTextSize(0.040);
  legd6->AddEntry(grFormRateR, "p_{T} integrated (MC Integral)", "L");
  legd6->AddEntry(grFormRateR0, "p_{T}= 0 (MC Integral)", "L");
  legd6->AddEntry(grFormRate_TripleInt, "p_{T} integrated (Triple Integral)", "L");
  
  new TCanvas;
  gPad->SetTicks();
  grFormRateR0->GetXaxis()->SetTitle("T (GeV)");
  grFormRateR0->GetYaxis()->SetTitle("Formation Rate (fm^{2})"); 
  grFormRateR0->GetXaxis()->SetRangeUser(0.1,1.0);
  grFormRateR0->GetYaxis()->SetRangeUser(0.0,0.01);
  grFormRateR0->Draw("AL");
  grFormRateR->Draw("Lsame");
  grFormRate_TripleInt->Draw("sameL");
  legd6->Draw("same");
  gPad->SaveAs("Fig4a_FormRateVsT.png");
  gPad->SaveAs("Fig4a_FormRateVsT.eps");
  




  TGraph *grFormRateVsT_MCInt_P1 = new TGraph(NTemp,Temp,LambdaFMC_P1);
  grFormRateVsT_MCInt_P1->SetName("grFormRateVsT_MCInt_P1");
  grFormRateVsT_MCInt_P1->SetTitle("grFormRateVsT_MCInt_P1");
  grFormRateVsT_MCInt_P1->SetLineWidth(2);
  grFormRateVsT_MCInt_P1->SetLineColor(2);
  grFormRateVsT_MCInt_P1->SetLineStyle(1);

  TGraph *grFormRateVsT_MCInt_P2 = new TGraph(NTemp,Temp,LambdaFMC_P2);
  grFormRateVsT_MCInt_P2->SetName("grFormRateVsT_MCInt_P2");
  grFormRateVsT_MCInt_P2->SetTitle("grFormRateVsT_MCInt_P2");
  grFormRateVsT_MCInt_P2->SetLineWidth(2);
  grFormRateVsT_MCInt_P2->SetLineColor(1);
  grFormRateVsT_MCInt_P2->SetLineStyle(2);


  TGraph *grFormRateVsT_MCInt_P3 = new TGraph(NTemp,Temp,LambdaFMC_P3);
  grFormRateVsT_MCInt_P3->SetName("grFormRateVsT_MCInt_P3");
  grFormRateVsT_MCInt_P3->SetTitle("grFormRateVsT_MCInt_P3");
  grFormRateVsT_MCInt_P3->SetLineWidth(2);
  grFormRateVsT_MCInt_P3->SetLineColor(4);
  grFormRateVsT_MCInt_P3->SetLineStyle(4);



  TLegend *lgd_FRVsT = new TLegend( 0.51,0.78,0.84,0.92);
  lgd_FRVsT->SetBorderSize(0);
  lgd_FRVsT->SetFillStyle(0);
  lgd_FRVsT->SetFillColor(0);
  lgd_FRVsT->SetTextSize(0.040);
  lgd_FRVsT->AddEntry(grFormRateVsT_MCInt_P1, "p_{T} = 2.25 GeV/c", "L");
  lgd_FRVsT->AddEntry(grFormRateVsT_MCInt_P2, "p_{T} = 3.25 GeV/c", "L");
  lgd_FRVsT->AddEntry(grFormRateVsT_MCInt_P3, "p_{T} = 4.25 GeV/c", "L");
  
  new TCanvas;
  gPad->SetTicks();
  gPad->SetLogy();
  grFormRateVsT_MCInt_P1->GetXaxis()->SetTitle("Temperature (GeV)");
  grFormRateVsT_MCInt_P1->GetYaxis()->SetTitleOffset(1.1);
  grFormRateVsT_MCInt_P1->GetYaxis()->SetTitle("d#lambda_{F}/dp_{T}(fm^{2}GeV^{-1})");
  grFormRateVsT_MCInt_P1->GetYaxis()->SetRangeUser(0.00001,1.0);
  grFormRateVsT_MCInt_P1->Draw("AL");
  grFormRateVsT_MCInt_P2->Draw("Lsame");
  grFormRateVsT_MCInt_P3->Draw("Lsame");
  

  lgd_FRVsT->Draw("same");
  tb->DrawLatex(0.16,0.90,"(a)");
  gPad->SaveAs("Fig4a_FRateVsT.png");
  gPad->SaveAs("Fig4a_FRateVsT.pdf");
  gPad->SaveAs("Fig4a_FRateVsT.eps");


  // return;





  Double_t DissRateKharVsPt1[10000]={0};
  Double_t DissRateKharVsPt2[10000]={0};
  Double_t DissRateKharVsPt3[10000]={0};
  
  
  Double_t LambdaF_P1[10000]={0};
  Double_t LambdaF_P2[10000]={0};
  Double_t LambdaF_P3[10000]={0};
  
  Double_t DissRatePionVsPt1[10000]={0};

  Double_t P[10000];
  Double_t PMax=0.0;
  Double_t PMin=0.25;
  Double_t PStep=0.1;
  //PionJPsiDiss(Double_t P1, Double_t T)
  
  if(Disso==1){PMax=20.0;}
  if(Form==1){PMax=8.75;PStep = 0.5;}
  
  int NP=int((PMax-PMin)/PStep);
  
  if(Form ==1){cout<<" Formation Rate vs P_{J/psi}(GeV/c) :"<<endl;}
  
  for(int l = 0; l<=NP; l++) {
    P[l]=PMin+PStep*l;
    if(Disso ==1){
      DissRateKharVsPt1[l]= SigmaQuasiGluon(1,P[l],0.200)/hbarc;
      DissRateKharVsPt2[l]= SigmaQuasiGluon(1,P[l],0.400)/hbarc;
      DissRateKharVsPt3[l]= SigmaQuasiGluon(1,P[l],0.600)/hbarc;
      DissRatePionVsPt1[l]=PionJPsiDiss(P[l], 0.100)/hbarc;
      cout<<P[l]<<"  "<< DissRateKharVsPt1[l]<<"   "<<DissRateKharVsPt2[l]<<"   "<<DissRateKharVsPt3[l]<<endl;
    } 
  
    if(Form ==2){
      //P[l]=3.46;
      //LambdaF_P1[l]=IntFormFun2_P(P[l],0.100);
      //LambdaF_P2[l]=IntFormFun2_P(P[l],0.200);
      //LambdaF_P3[l]=IntFormFun2_P(P[l],0.300);
      LambdaF_P1[l]=FormRateMC_P(0.200,P[l]);
      LambdaF_P2[l]=FormRateMC_P(0.400,P[l]);
      LambdaF_P3[l]=FormRateMC_P(0.600,P[l]);
      cout<<P[l]<<"  "<< LambdaF_P1[l] <<"  "<<LambdaF_P2[l]<<"   "<<LambdaF_P3[l]<<endl;
    }
    //
  
  }
       
  TGraph *grFormRate_TripleInt_P1 = new TGraph(NP,P,LambdaF_P1);
  grFormRate_TripleInt_P1->SetName("grFormRateVsP_MCInt_T1");
  grFormRate_TripleInt_P1->SetTitle("grFormRateVsP_MCInt_T1");
  grFormRate_TripleInt_P1->SetMarkerStyle(20);
  grFormRate_TripleInt_P1->SetLineWidth(2);
  grFormRate_TripleInt_P1->SetLineColor(2);
  grFormRate_TripleInt_P1->SetLineStyle(1);
  grFormRate_TripleInt_P1->GetXaxis()->SetTitle("P(GeV)");
  grFormRate_TripleInt_P1->GetYaxis()->SetTitle("FormRate(Triple Int)");
  
  TGraph *grFormRate_TripleInt_P2 = new TGraph(NP,P,LambdaF_P2);
  grFormRate_TripleInt_P2->SetName("grFormRateVsP_MCInt_T2");
  grFormRate_TripleInt_P2->SetTitle("grFormRateVsP_MCInt_T2");
  grFormRate_TripleInt_P2->SetLineWidth(2);
  grFormRate_TripleInt_P2->SetLineColor(1);
  grFormRate_TripleInt_P2->SetLineStyle(2);

  TGraph *grFormRate_TripleInt_P3 = new TGraph(NP,P,LambdaF_P3);
  grFormRate_TripleInt_P3->SetName("grFormRateVsP_MCInt_T3");
  grFormRate_TripleInt_P3->SetTitle("grFormRateVsP_MCInt_T3");
  grFormRate_TripleInt_P3->SetLineWidth(2);
  grFormRate_TripleInt_P3->SetLineColor(4);
  grFormRate_TripleInt_P3->SetLineStyle(4);

  TLegend *legd_formPt = new TLegend( 0.44,0.73,0.90,0.92);
  //legd_formPt->SetNDC();
  legd_formPt->SetBorderSize(0);
  legd_formPt->SetFillStyle(0);
  legd_formPt->SetFillColor(0);
  legd_formPt->SetTextSize(0.040);  

  legd_formPt->AddEntry(grFormRate_TripleInt_P1,"T=0.2 GeV", "L");
  legd_formPt->AddEntry(grFormRate_TripleInt_P2,"T=0.4 GeV", "L");
  legd_formPt->AddEntry(grFormRate_TripleInt_P3,"T=0.6 GeV", "L");
  
  new TCanvas;
  gPad->SetTicks();
  gPad->SetLogy();
  gPad->SetLeftMargin(0.14);
  grFormRate_TripleInt_P1->GetXaxis()->SetTitle("p_{T}(GeV/c)");
  grFormRate_TripleInt_P1->GetYaxis()->SetTitleOffset(1.2);
  grFormRate_TripleInt_P1->GetYaxis()->SetTitle("d#lambda_{F}/dp_{T} (fm^{2}GeV^{-1})");
  grFormRate_TripleInt_P1->GetYaxis()->SetRangeUser(0.0001,1.0);
  
  grFormRate_TripleInt_P1->Draw("AL");
  grFormRate_TripleInt_P2->Draw("Lsame");
  grFormRate_TripleInt_P3->Draw("Lsame");
 legd_formPt->Draw("same");
  //tb->DrawLatex(0.55,0.83,"Triple Integral");
  tb->DrawLatex(0.16,0.90,"(b)");
  gPad->SaveAs("Fig4b_FRateVsPt.png");
  gPad->SaveAs("Fig4b_FRateVsPt.eps");
  gPad->SaveAs("Fig4b_FRateVsPt.pdf");
  
  //  return;

  //====================== Dissociation rates =====================//
  
  TGraph *DissRate_Khar = new TGraph(NTemp,Temp,LambdaD_Khar);
  DissRate_Khar->SetName("DissRateVsT_KharPt0");
  DissRate_Khar->SetTitle("DissRateVsT_KharPt0");
  DissRate_Khar->SetLineWidth(2);
  DissRate_Khar->SetLineColor(1);
  DissRate_Khar->SetLineStyle(1);
  DissRate_Khar->GetXaxis()->SetTitle("Temperature (GeV)");
  DissRate_Khar->GetYaxis()->SetTitle("Dissociation Rate #lambda_{D}#rho_{g} (fm^{-1})");
  //DissRate_Khar->GetYaxis()->SetTitle("#Gamma[p_{J/#psi},T] (fm^{-1})");
  

  TGraph *DissRate_KharAll = new TGraph(NTemp,Temp,LambdaD_KharAll);
  DissRate_KharAll->SetLineWidth(2);
  DissRate_KharAll->SetLineColor(2);
  DissRate_KharAll->SetLineStyle(1);
  
  TGraph *DissRate_Khar36 = new TGraph(NTemp,Temp,LambdaD_Khar36);
  DissRate_Khar36->SetName("DissRateVsT_KharPt36");
  DissRate_Khar36->SetTitle("DissRateVsT_KharPt36");
  DissRate_Khar36->SetLineWidth(2);
  DissRate_Khar36->SetLineColor(4);
  DissRate_Khar36->SetLineStyle(4);
  
  TGraph *DissRate_Khar86 = new TGraph(NTemp,Temp,LambdaD_Khar86);
  DissRate_Khar86->SetName("DissRateVsT_KharPt86");
  DissRate_Khar86->SetTitle("DissRateVsT_KharPt86");
  DissRate_Khar86->SetLineWidth(2);
  DissRate_Khar86->SetLineColor(6);
  DissRate_Khar86->SetLineStyle(6);
  
  TGraph *DissRate_GluonDissVac = new TGraph(NTemp,Temp,LambdaD_GluonDissVac);
  DissRate_GluonDissVac->SetLineWidth(2);
  DissRate_GluonDissVac->SetLineColor(2);
  
  


  // Diss rates
  TLegend *legd_dissT = new TLegend( 0.24,0.67,0.69,0.86);
  legd_dissT->SetBorderSize(0);
  legd_dissT->SetFillStyle(0);
  legd_dissT->SetFillColor(0);
  legd_dissT->SetTextSize(0.040);
  
  legd_dissT->AddEntry(DissRate_Khar, "p_{T}= 0", "l");
  legd_dissT->AddEntry(DissRate_Khar36, "p_{T}= 3.6 GeV/c", "l");
  legd_dissT->AddEntry(DissRate_Khar86, "p_{T}= 8.6 GeV/c", "l");
  
  
  new TCanvas;
  gPad->SetTicks();
  DissRate_Khar->Draw("AL");
  DissRate_Khar36->Draw("Lsame");
  DissRate_Khar86->Draw("Lsame");
  legd_dissT->Draw();
  tb->DrawLatex(0.16,0.90,"(a)");
  gPad->SaveAs("Fig3a_DRateVsT.png");    
  gPad->SaveAs("Fig3a_DRateVsT.eps");    
  
  legd_dissT->Clear();
  

  //DRate vs Pt graph
  TGraph *grDissRateVsPt1 = new TGraph(NP,P,DissRateKharVsPt1);
  grDissRateVsPt1->SetName("grDissRateVsPt_T200");
  grDissRateVsPt1->SetTitle("grDissRateVsPt_T200");
  grDissRateVsPt1->SetLineWidth(2);
  grDissRateVsPt1->SetLineColor(2);
  grDissRateVsPt1->GetXaxis()->SetTitle("p_{T}(GeV/c)");
  grDissRateVsPt1->GetYaxis()->SetTitle("Dissociation Rate #lambda_{D}#rho_{g} (fm^{-1})");
  
  
  TGraph *grDissRateVsPt2 = new TGraph(NP,P,DissRateKharVsPt2);
  grDissRateVsPt2->SetName("grDissRateVsPt_T400");
  grDissRateVsPt2->SetTitle("grDissRateVsPt_T400");
  grDissRateVsPt2->SetLineWidth(2);
  grDissRateVsPt2->SetLineStyle(6);  
  grDissRateVsPt2->SetLineColor(1);

  
  TGraph *grDissRateVsPt3 = new TGraph(NP,P,DissRateKharVsPt3);
  grDissRateVsPt3->SetName("grDissRateVsPt_T600");
  grDissRateVsPt3->SetTitle("grDissRateVsPt_T600");
  grDissRateVsPt3->SetLineWidth(2);
  grDissRateVsPt3->SetLineStyle(4);
  grDissRateVsPt3->SetLineColor(4);
  
  

  TGraph *grDissRatePionVsPt1 = new TGraph(NP,P,DissRatePionVsPt1);
  grDissRatePionVsPt1->SetLineWidth(2);
  grDissRatePionVsPt1->SetLineColor(8);
  grDissRatePionVsPt1->GetXaxis()->SetTitle("p_{T}(GeV/c)");
  grDissRatePionVsPt1->GetYaxis()->SetTitle("Dissociation Rate #lambda_{D_{#pi}}#rho_{g} (fm^{-1})");




  TLegend *legd_dissPt = new TLegend( 0.31,0.67,0.76,0.86);
  legd_dissPt->SetBorderSize(0);
  legd_dissPt->SetFillStyle(0);
  legd_dissPt->SetFillColor(0);
  legd_dissPt->SetTextSize(0.040);
  legd_dissPt->AddEntry(grDissRateVsPt1, "T=0.2 GeV", "l");
  legd_dissPt->AddEntry(grDissRateVsPt2, "T=0.4 GeV", "l");
  legd_dissPt->AddEntry(grDissRateVsPt3, "T=0.6 GeV", "l");


  new TCanvas; 
  gPad->SetTicks();
  grDissRateVsPt1->GetYaxis()->SetRangeUser(0.0,5.0);
  grDissRateVsPt1->Draw("AL");
  grDissRateVsPt2->Draw("Lsame");
  grDissRateVsPt3->Draw("Lsame");
  legd_dissPt->Draw();
  tb->DrawLatex(0.16,0.90,"(b)");
  //grDissRatePionVsPt1->Draw("Lsame");
  gPad->SaveAs("Fig3b_DRateVsPt.png");    
  gPad->SaveAs("Fig3b_DRateVsPt.eps");



  //legd_dissPt->Delete();

  // return;
  //____________________________________________________________________________________________________//
  //____________________________________________________________________________________________________//
  //____________________________________________________________________________________________________//  
  cout << endl <<" J/psi RAA " << endl;
 
      
  //==============================================================================================//
  //================================= RAA Vs Pt Calculations ===================================//
  //=============================================================================================//
  
  int NNPtALICE =21.0;
  Double_t RAAALICEPt[25];
  Double_t PionDissALICEPt[25];
  Double_t ShadowDissALICEPt[25];
  Double_t GluonDissALICEPt[25];

  Double_t NJPsiRegenALICEPt[25];
  Double_t NJPsi0ALICEPt[25];
  Double_t FormationALICEPt[25];

  Double_t PtALICE[25]={0.25,0.75,1.25,1.75,2.25,2.75,3.25,3.75,4.25,4.75,5.25,5.75,6.25,6.75,7.25,7.75,8.25,8.75,9.25,9.75,10.25};
  
  Double_t T0MB =T0*TMath::Power((funTwoComp->Eval(Npart(0,40)))/dNdEtabyNpartby2[0],1.0/3.0);
  Double_t R0MB = R05*TMath::Power(Npart(0,40)/Npart(0,2),0.5);          
  

  Double_t NCCMB=nCC0*NColl(0,40)/NColl(0,2);
  Double_t NJPsiMB=nJpsi0*NColl(0,40)/NColl(0,2);

  Double_t tauCMB=Tau0ToTauC(2,T0MB,R0MB);
  Double_t tauHMB=TauCToTauh(2,tauCMB,R0MB);
  Double_t tauFMB=TauhToTauf(2,tauHMB,R0MB);

  CalculateTandf(2, T0MB, R0MB, tauCMB, tauHMB,tauFMB);
  
  cout<<" Calculating ALICE RAA Vs Pt "<<endl;
  
  cout<<" shadow "<<"   "<< " gluon "<<"   "<< " Pion "<< "   "<< " Diss  "<< "   "<<" For "<< "  "<< " RAA " <<endl;  

  Double_t IntRaa=0.0;
 
  NNPtALICE=0;
  
  for(int i=0; i<NNPtALICE; i++) {
    PionDissALICEPt[i]=PionDiss_All(PtALICE[i]);
    GluonDissALICEPt[i]=IntDiss_All(PtALICE[i]);
    
    ShadowDissALICEPt[i]=HistJpsiRaaShVsPt->Interpolate(PtALICE[i]);

    NJPsiRegenALICEPt[i]=GluonDissALICEPt[i]*NCCMB*NCCMB*IntFormVsPt(PtALICE[i],R0MB);
    NJPsi0ALICEPt[i]= Jpsi_Pt->GetBinContent(Jpsi_Pt->FindBin(PtALICE[i]))/Jpsi_Pt->GetBinWidth(0);
    Double_t JPsiIntSh = 1.0/0.65;
    FormationALICEPt[i]=NJPsiRegenALICEPt[i]/( NJPsiMB * JPsiIntSh * NJPsi0ALICEPt[i]);
    RAAALICEPt[i]= ShadowDissALICEPt[i]*PionDissALICEPt[i]*GluonDissALICEPt[i] + FormationALICEPt[i]; 
    
    cout<<ShadowDissALICEPt[i]<<"   "<<GluonDissALICEPt[i]<<"   "<<PionDissALICEPt[i]<<"   "<<ShadowDissALICEPt[i]*PionDissALICEPt[i]*GluonDissALICEPt[i]<<"  "<<
      FormationALICEPt[i]<<"  "<<RAAALICEPt[i]<<endl;
  }

  //cout<<" Running Big loop "<<endl;
  //cout<<" 1 "<<RegenratedQuarkoniaNPart(NCCMB,NJPsiMB,R0MB)<<endl;

    
  // RAA vs pT graphs
  TGraph *grRAAALICEPt_M = new TGraph(NNPtALICE,PtALICE,RAAALICEPt);
  grRAAALICEPt_M->SetName("grRAAALICEPt_M");
  grRAAALICEPt_M->SetTitle("grRAAALICEPt_M");
  grRAAALICEPt_M->SetLineWidth(2);
  grRAAALICEPt_M->SetLineColor(1);
  grRAAALICEPt_M->SetLineStyle(1);
  grRAAALICEPt_M->GetXaxis()->SetTitle("p_{T}(GeV/c)");
  grRAAALICEPt_M->GetYaxis()->SetTitle("R_{AA}");
  grRAAALICEPt_M->GetYaxis()->SetRangeUser(0.0,1.0);
  

  //Pion diss vs pT graphs
  TGraph *grPionDissALICEPt_M = new TGraph(NNPtALICE,PtALICE,PionDissALICEPt);
  grPionDissALICEPt_M->SetName("grPionDissALICEPt_M");
  grPionDissALICEPt_M->SetTitle("grPionDissALICEPt_M");
  grPionDissALICEPt_M->SetLineWidth(2);
  grPionDissALICEPt_M->SetLineColor(8);
  grPionDissALICEPt_M->SetLineStyle(2);
  grPionDissALICEPt_M->GetXaxis()->SetTitle("p_{T}(GeV/c)");
  grPionDissALICEPt_M->GetYaxis()->SetTitle("#pi Dissociation");
  grPionDissALICEPt_M->GetYaxis()->SetRangeUser(0.0,1.0);
  

  //Shadow diss vs pT graphs
  TGraph *grShadowDissALICEPt_M = new TGraph(NNPtALICE,PtALICE,ShadowDissALICEPt);
  grShadowDissALICEPt_M->SetName("grShadowDissALICEPt_M");
  grShadowDissALICEPt_M->SetTitle("grShadowDissALICEPt_M");
  grShadowDissALICEPt_M->SetLineWidth(2);
  grShadowDissALICEPt_M->SetLineColor(6);
  grShadowDissALICEPt_M->SetLineStyle(2);
  grShadowDissALICEPt_M->GetXaxis()->SetTitle("p_{T}(GeV/c)");
  grShadowDissALICEPt_M->GetYaxis()->SetTitle("R_{AA}^{Shadowing}");
  grShadowDissALICEPt_M->GetYaxis()->SetRangeUser(0.0,1.0);

  
  //Gluon diss vs pT graphs
  TGraph *grGluonDissALICEPt_M = new TGraph(NNPtALICE,PtALICE,GluonDissALICEPt);
  grGluonDissALICEPt_M->SetName("grGluonDissALICEPt_M");
  grGluonDissALICEPt_M->SetTitle("grGluonDissALICEPt_M");
  grGluonDissALICEPt_M->SetLineWidth(2);
  grGluonDissALICEPt_M->SetLineColor(4);
  grGluonDissALICEPt_M->SetLineStyle(6);
  grGluonDissALICEPt_M->GetXaxis()->SetTitle("p_{T}(GeV/c)");
  grGluonDissALICEPt_M->GetYaxis()->SetTitle("gluon Dissociation");
  grGluonDissALICEPt_M->GetYaxis()->SetRangeUser(0.0,1.0);

  //Regenration vs pT graphs
  TGraph *grRegenALICEPt_M = new TGraph(NNPtALICE,PtALICE,FormationALICEPt);
  grRegenALICEPt_M->SetName("grRegenALICEPt_M");
  grRegenALICEPt_M->SetTitle("grRegenALICEPt_M");
  grRegenALICEPt_M->SetLineWidth(2);
  grRegenALICEPt_M->SetLineColor(2);
  grRegenALICEPt_M->SetLineStyle(4);
  grRegenALICEPt_M->GetXaxis()->SetTitle("p_{T}(GeV/c)");
  grRegenALICEPt_M->GetYaxis()->SetTitle("Regenration");
  grRegenALICEPt_M->GetYaxis()->SetRangeUser(0.0,1.0);

  TLegend *leg_ALICEJPsiRaaPt = new TLegend(0.16,0.64,0.97,0.93);
  leg_ALICEJPsiRaaPt->SetBorderSize(0);
  leg_ALICEJPsiRaaPt->SetFillStyle(0);
  leg_ALICEJPsiRaaPt->SetFillColor(0);
  leg_ALICEJPsiRaaPt->SetTextSize(0.030);
  
  new TCanvas;
  gPad->SetTicks();
  Draw_ALICEFor_JPsi_RaaVspT(leg_ALICEJPsiRaaPt);  
  leg_ALICEJPsiRaaPt->AddEntry(grGluonDissALICEPt_M,"Gluon Dissociation","L");
  leg_ALICEJPsiRaaPt->AddEntry(grRegenALICEPt_M,"Formation","L");
  leg_ALICEJPsiRaaPt->AddEntry(grPionDissALICEPt_M,"Comover","L");
  leg_ALICEJPsiRaaPt->AddEntry(grShadowDissALICEPt_M,"CNM Effects","L");
  leg_ALICEJPsiRaaPt->AddEntry(grRAAALICEPt_M,"Total (R_{AA})","L");
  grRAAALICEPt_M->Draw("Lsame");
  grPionDissALICEPt_M->Draw("Lsame");
  grShadowDissALICEPt_M->Draw("Lsame");
  grGluonDissALICEPt_M->Draw("Lsame");
  grRegenALICEPt_M->Draw("Lsame");
  leg_ALICEJPsiRaaPt->Draw("same"); 
  gPad->SaveAs("Fig5a_ALICE_RAAPt.eps");
  gPad->SaveAs("Fig5a_ALICE_RAAPt.png");
  
  int NNPtCMS = 60;
  Double_t RAACMSPt[100];
  Double_t PionDissCMSPt[100];
  Double_t ShadowDissCMSPt[100];
  Double_t GluonDissCMSPt[100];

  Double_t NJPsiRegenCMSPt[100];
  Double_t NJPsi0CMSPt[100];
  Double_t FormationCMSPt[100];
  

  Double_t PtCMS[100]={0.75,1.25,1.75,2.25,2.75,3.25,3.75,4.25,4.75,5.25,5.75,6.25,6.75,7.25,7.75,8.25,8.75,
  		       9.25,9.75,10.25,10.75,11.25,11.75,12.25,12.75,13.25,13.75,14.25,14.75,15.25,15.75,16.25,
  		       16.75,17.25,17.75,18.25,18.75,19.25,19.75,20.25,20.75,21.25,21.75,22.25,22.75,23.25,23.75,
  		       24.25,24.75,25.25,25.75,26.25,26.75,27.25,27.75,28.25,28.75,29.25,29.75,30.25,30.75};

  
  for(int i=0; i<NNPtCMS; i++) {
    
    GluonDissCMSPt[i]=IntDiss_All(PtCMS[i]);
    PionDissCMSPt[i]=PionDiss_All(PtCMS[i]);
    ShadowDissCMSPt[i]=HistJpsiRaaShVsPt->Interpolate(PtCMS[i]);
   
    //NJPsiRegenCMSPt[i]=GluonDissCMSPt[i]*NCCMB*NCCMB*IntFormVsPt(PtCMS[i],R0MB);
    //NJPsi0CMSPt[i]=Jpsi_Pt->GetBinContent(Jpsi_Pt->FindBin(PtCMS[i]))/Jpsi_Pt->GetBinWidth(0);
    //FormationCMSPt[i]=NJPsiRegenCMSPt[i]/(NJPsiMB*NJPsi0CMSPt[i]);
    FormationCMSPt[i]=0.0;
    //RAACMSPt[i]=GluonDissCMSPt[i]*PionDissCMSPt[i];
    RAACMSPt[i]= ShadowDissCMSPt[i]*PionDissCMSPt[i]*GluonDissCMSPt[i] + FormationCMSPt[i];
    cout<<PtCMS[i]<<"  "<<RAACMSPt[i]<<endl;
  }

  // RAA vs pT graphs
  TGraph *grRAACMSPt_M = new TGraph(NNPtCMS,PtCMS,RAACMSPt);
  grRAACMSPt_M->SetName("grRAACMSPt_M");
  grRAACMSPt_M->SetTitle("grRAACMSPt_M");
  grRAACMSPt_M->SetLineWidth(2);
  grRAACMSPt_M->SetLineColor(1);
  grRAACMSPt_M->SetLineStyle(1);
  grRAACMSPt_M->GetXaxis()->SetTitle("p_{T}(GeV/c)");
  grRAACMSPt_M->GetYaxis()->SetTitle("R_{AA}");
  grRAACMSPt_M->GetYaxis()->SetRangeUser(0.0,1.0);

 

  //Gluon diss vs pT graphs
  TGraph *grGluonDissCMSPt_M = new TGraph(NNPtCMS,PtCMS,GluonDissCMSPt);
  grGluonDissCMSPt_M->SetName("grGluonDissCMSPt_M");
  grGluonDissCMSPt_M->SetTitle("grGluonDissCMSPt_M");
  grGluonDissCMSPt_M->SetLineWidth(2);
  grGluonDissCMSPt_M->SetLineColor(4);
  grGluonDissCMSPt_M->SetLineStyle(6);
  grGluonDissCMSPt_M->GetXaxis()->SetTitle("p_{T}(GeV/c)");
  grGluonDissCMSPt_M->GetYaxis()->SetTitle("gluon Dissociation");
  grGluonDissCMSPt_M->GetYaxis()->SetRangeUser(0.0,1.0);
  

  //Pion diss vs pT graphs
  TGraph *grPionDissCMSPt_M = new TGraph(NNPtCMS,PtCMS,PionDissCMSPt);
  grPionDissCMSPt_M->SetName("grPionDissCMSPt_M");
  grPionDissCMSPt_M->SetTitle("grPionDissCMSPt_M");
  grPionDissCMSPt_M->SetLineWidth(2);
  grPionDissCMSPt_M->SetLineColor(8);
  grPionDissCMSPt_M->SetLineStyle(2);
  grPionDissCMSPt_M->GetXaxis()->SetTitle("p_{T}(GeV/c)");
  grPionDissCMSPt_M->GetYaxis()->SetTitle("#pi Dissociation");
  grPionDissCMSPt_M->GetYaxis()->SetRangeUser(0.0,1.0);

  //Shadow diss vs pT graphs
  TGraph *grShadowDissCMSPt_M = new TGraph(NNPtCMS,PtCMS,ShadowDissCMSPt);
  grShadowDissCMSPt_M->SetName("grShadowDissCMSPt_M");
  grShadowDissCMSPt_M->SetTitle("grShadowDissCMSPt_M");
  grShadowDissCMSPt_M->SetLineWidth(2);
  grShadowDissCMSPt_M->SetLineColor(6);
  grShadowDissCMSPt_M->SetLineStyle(2);
  grShadowDissCMSPt_M->GetXaxis()->SetTitle("p_{T}(GeV/c)");
  grShadowDissCMSPt_M->GetYaxis()->SetTitle("R_{AA}^{Shadowing}");
  grShadowDissCMSPt_M->GetYaxis()->SetRangeUser(0.0,1.0);

  
  //Regenration vs pT graphs
  TGraph *grRegenCMSPt_M = new TGraph(NNPtCMS,PtCMS,FormationCMSPt);
  grRegenCMSPt_M->SetName("grRegenCMSPt_M");
  grRegenCMSPt_M->SetTitle("grRegenCMSPt_M");
  grRegenCMSPt_M->SetLineWidth(2);
  grRegenCMSPt_M->SetLineColor(2);
  grRegenCMSPt_M->SetLineStyle(4);
  grRegenCMSPt_M->GetXaxis()->SetTitle("p_{T}(GeV/c)");
  grRegenCMSPt_M->GetYaxis()->SetTitle("Formation");
  grRegenCMSPt_M->GetYaxis()->SetRangeUser(0.0,1.0);


  TLegend *leg_CMSJPsiRaaPt = new TLegend(0.15,0.69,0.90,0.92);
  leg_CMSJPsiRaaPt->SetBorderSize(0);
  leg_CMSJPsiRaaPt->SetFillStyle(0);
  leg_CMSJPsiRaaPt->SetFillColor(0);
  leg_CMSJPsiRaaPt->SetTextSize(0.040);
   
  new TCanvas;
  gPad->SetTicks();
  if(isUps==0){Draw_CMS_JPsi_RaaVspT(leg_CMSJPsiRaaPt);} 
  if(isUps==1){Draw_CMS_Y1S_RaaVspT(leg_CMSJPsiRaaPt);}

  leg_CMSJPsiRaaPt->AddEntry(grGluonDissCMSPt_M,"Gluon Dissociation","L");
  leg_CMSJPsiRaaPt->AddEntry(grPionDissCMSPt_M,"Comover","L");
  leg_CMSJPsiRaaPt->AddEntry(grShadowDissCMSPt_M,"CNM Effects","L");
  leg_CMSJPsiRaaPt->AddEntry(grRAACMSPt_M,"Total (R_{AA})","L");
  
  grRAACMSPt_M->Draw("Lsame");
  grPionDissCMSPt_M->Draw("Lsame");
  grShadowDissCMSPt_M->Draw("Lsame");
  grGluonDissCMSPt_M->Draw("Lsame");
  //grRegenCMSPt_M->Draw("Lsame");
  leg_CMSJPsiRaaPt->Draw("same"); 
  gPad->SaveAs("Fig5b_CMS_RAAPt.eps");
  gPad->SaveAs("Fig5b_CMS_RAAPt.png");

  
  grRAAALICEPt_M->Write();
  grPionDissALICEPt_M->Write();
  grGluonDissALICEPt_M->Write();
  grRegenALICEPt_M->Write();
  
  grRAACMSPt_M->Write();
  grPionDissCMSPt_M->Write();
  grGluonDissCMSPt_M->Write();
  grRegenCMSPt_M->Write();

  //OutFile->Write();
  //OutFile->Close();

  //return;

  //==============================================================================================//
  //================================= RAA Vs Rapidity Calculations ==============================//
  //=============================================================================================//
  
  int NNRapCMS = 3;
  Double_t RAACMSRap[3];
  Double_t PionDissCMSRap[3];
  Double_t GluonDissCMSRap[3];
  //AvPt in Rap bins
  Double_t AvPtCMS[3]={10.92,9.65,8.92};
  
  Double_t RapCMS[3]={0.6,1.4,2.0};
  
  Double_t GluonDissRap = IntDiss_PtInt(6.25);
  Double_t PionDissRap =  PionDiss_PtInt(6.25);

    for(int i=0; i<NNRapCMS; i++) {
      //GluonDissCMSRap[i]=IntDiss_All(AvPtCMS[i]);
      //PionDissCMSRap[i]=PionDiss_All(AvPtCMS[i]);;
      GluonDissCMSRap[i]= GluonDissRap;
      PionDissCMSRap[i]=PionDissRap;
      RAACMSRap[i]=GluonDissCMSRap[i]*PionDissCMSRap[i];
      cout<<RapCMS[i]<<"  "<<RAACMSRap[i]<<endl;
    }
  
    // RAA vs Rap graphs
    TGraph *grRAACMSRap_M = new TGraph(NNRapCMS,RapCMS,RAACMSRap);
    grRAACMSRap_M->SetName("grRAACMSRap_M");
    grRAACMSRap_M->SetTitle("grRAACMSRap_M");
    grRAACMSRap_M->SetLineWidth(2);
    grRAACMSRap_M->GetXaxis()->SetTitle("|y|");
    grRAACMSRap_M->GetYaxis()->SetTitle("R_{AA}");
    grRAACMSRap_M->GetYaxis()->SetRangeUser(0.0,1.0);
  

    //Pion diss vs Rap graphs
    TGraph *grPionDissCMSRap_M = new TGraph(NNRapCMS,RapCMS,PionDissCMSRap);
    grPionDissCMSRap_M->SetName("grPionDissCMSRap_M");
    grPionDissCMSRap_M->SetTitle("grPionDissCMSRap_M");
    grPionDissCMSRap_M->SetLineWidth(2);
    grPionDissCMSRap_M->SetLineColor(2);
    grPionDissCMSRap_M->GetXaxis()->SetTitle("|y|");
    grPionDissCMSRap_M->GetYaxis()->SetTitle("#pi Dissociation");
    grPionDissCMSRap_M->GetYaxis()->SetRangeUser(0.0,1.0);


    //Gluon diss vs Rap graphs
    TGraph *grGluonDissCMSRap_M = new TGraph(NNRapCMS,RapCMS,GluonDissCMSRap);
    grGluonDissCMSRap_M->SetName("grGluonDissCMSRap_M");
    grGluonDissCMSRap_M->SetTitle("grGluonDissCMSRap_M");
    grGluonDissCMSRap_M->SetLineWidth(2);
    grGluonDissCMSRap_M->SetLineColor(4);
    grGluonDissCMSRap_M->GetXaxis()->SetTitle("|y|");
    grGluonDissCMSRap_M->GetYaxis()->SetTitle("gluon Dissociation");
    grGluonDissCMSRap_M->GetYaxis()->SetRangeUser(0.0,1.0);

  
  
    TLegend *leg_CMSJPsiRaaRap = new TLegend( 0.22,0.70,0.77,0.84);
    leg_CMSJPsiRaaRap->SetBorderSize(0);
    leg_CMSJPsiRaaRap->SetFillStyle(0);
    leg_CMSJPsiRaaRap->SetFillColor(0);
    leg_CMSJPsiRaaRap->SetTextSize(0.040);
  
  
  
    
    new TCanvas;
    gPad->SetTicks();
    Draw_CMS_JPsi_RaaVsRap(leg_CMSJPsiRaaRap);
    leg_CMSJPsiRaaRap->AddEntry(grGluonDissCMSRap_M,"gluon Diss.","L");
    leg_CMSJPsiRaaRap->AddEntry(grPionDissCMSRap_M,"#pi Diss.","L");
    leg_CMSJPsiRaaRap->AddEntry(grRAACMSRap_M,"R_{AA}","L");
    grRAACMSRap_M->Draw("Lsame");
    grPionDissCMSRap_M->Draw("Lsame");
    grGluonDissCMSRap_M->Draw("Lsame");
    leg_CMSJPsiRaaRap->Draw("same"); 
    gPad->SaveAs("CMS_RAARap.eps");
    gPad->SaveAs("CMS_RAARap.png");

  

    // return;



    //========================================================================================//
    //=======================================================================================//
    // ======================== Main calculations for centrality ===========================//
    //=====================================================================================//
    //====================================================================================//

    Double_t nPartMin = 0.0;
    Double_t nPartMax = 500;
    Double_t nstep = 50;
    int NN = (int)((nPartMax-nPartMin)/nstep);
    
    Double_t nPart[100]={Npart(0,2),Npart(2,4),Npart(4,6),Npart(6,8),Npart(8,10),Npart(10,12),
			 Npart(12,14),Npart(14,16),Npart(16,18),Npart(18,20),Npart(20,24),
			 Npart(24,40)};
    

  //Double_t nPart[100]={Npart(0,4),Npart(4,16),Npart(16,40)};
    
    Double_t jpsiFormCMS[100], jpsiDissCMS[100], nJpsiFCMS[100], RAACMS[100];
    Double_t jpsiFormALICE[100], jpsiDissALICE[100], nJpsiFALICE[100], RAAALICE[100];
    
    Double_t CNMEffectsCMS[20],PionDissCMS[20];
    Double_t CNMEffectsALICE[20],PionDissALICE[20];
    
  
    // Access root file form stat model
    Double_t NJpsiStatALICE[100];
    double x1, y1;
    cout<<grNJpsiStat->GetN()<<" getN "<<endl;
    for (int i=0; i<grNJpsiStat->GetN();++i){
      grNJpsiStat->GetPoint(i,x1,y1);
      NJpsiStatALICE[i]=y1;    
  }
    
    NN=12;  

    //NN=0;  
 
    cout <<"nPart "  <<"  Temp "<<"  TauC  " <<"  TauH  "<<" R0Cent "<<" RAACMS  "<<"  RAAALICE "<<endl;
    
    // Loop over centrality
    for(int i=0; i<NN; i++) {
     
      Double_t nColl = fa2->Eval(nPart[i]);  
      Double_t nJpsi = nJpsi0*nColl/nColl0;
      Double_t nCC = nCC0*nColl/nColl0;
      
      Double_t T0Cent =T0*TMath::Power((funTwoComp->Eval(nPart[i]))/dNdEtabyNpartby2[0],1.0/3.0);
      Double_t R0Cent = R05*TMath::Power(nPart[i]/Npart(0,2),0.5);          
    
      Double_t tauCCent=Tau0ToTauC(2,T0Cent,R0Cent);
      Double_t tauHCent=TauCToTauh(2,tauCCent,R0Cent);
      Double_t tauFCent=TauhToTauf(2,tauHCent,R0Cent);
      
      CalculateTandf(2, T0Cent, R0Cent, tauCCent, tauHCent,tauFCent);
    
  
      //Jpsi Pt integrated 
      Double_t intdissCMS = 0.0;
      
      intdissCMS = IntDiss_PtInt(6.25);
      
      if(isUps==1){intdissCMS =IntDiss_PtInt(0.25);}

      Double_t intPiondissCMS = 0.0;
      intPiondissCMS = PionDiss_PtInt(6.25);
      if(isUps==1){PionDiss_PtInt(0.25);}
      PionDissCMS[i]=intPiondissCMS;
      Double_t intformCMS=0.0;
      jpsiDissCMS[i] = intdissCMS;
      jpsiFormCMS[i] = intdissCMS*intformCMS*nCC*nCC/(nJpsi);
      nJpsiFCMS[i] = (jpsiDissCMS[i] + jpsiFormCMS[i] );
      CNMEffectsCMS[i] =Shadowing(CNMSigmaMid,nPart[i]);
      
      //RAACMS[i] = nJpsiFCMS[i]*CNMEffectsCMS[i]*PionDissCMS[i];
      RAACMS[i] = nJpsiFCMS[i]*PionDissCMS[i];
    

      Double_t intdissALICE=0; 
      Double_t intformALICE=0;
    
      if(isUps==0){
	
	CNMEffectsALICE[i] =Shadowing(CNMSigmaFor,nPart[i]);
	
	PionDissALICE[i]= PionDiss_PtInt(0.25);
	intdissALICE = IntDiss_PtInt(0.25);
     	
	

	//RegenratedQuarkoniaNPart(NCCMB,NJPsiMB,R0MB)<<endl;
	//Formation rate from stat hadronization
	//intformALICE = NJpsiStatALICE[i];
 	cout<<" Running Big loop "<<endl;
	intformALICE = RegenratedQuarkoniaNPart(nCC,nJpsi,R0Cent);
      }
    
      jpsiDissALICE[i] = intdissALICE;
      jpsiFormALICE[i] = intformALICE;



      //nJpsiFALICE[i] = ( (jpsiDissALICE[i]*CNMEffectsALICE[i]*PionDissALICE[i]) + jpsiFormALICE[i] );
      
      nJpsiFALICE[i] = ( (jpsiDissALICE[i]*PionDissALICE[i]) + jpsiFormALICE[i] );
      RAAALICE[i] = nJpsiFALICE[i];
      cout << nPart[i]<<"  "<<"    " << T0Cent <<"     "<<tauCCent <<"  "<<tauHCent <<"  "<<R0Cent<<"  "<<RAACMS[i]<<"   "<<jpsiFormALICE[i]<<"  "<<RAAALICE[i]<<endl;
    }
  
    //////////////////////////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////////////////////////

    //====================== Calculation graphs for CMS ==========================//

    //PionDiss graph
    TGraph *grPionDissCMS_M = new TGraph(NN,nPart,PionDissCMS);
    grPionDissCMS_M->SetName("grPionDissCMS_M");
    grPionDissCMS_M->SetTitle("grPionDissCMS_M");
    grPionDissCMS_M->SetLineWidth(2);
    grPionDissCMS_M->SetLineColor(8);
    grPionDissCMS_M->SetLineStyle(2);
    grPionDissCMS_M->GetXaxis()->SetTitle("N_{Part}");
    grPionDissCMS_M->GetYaxis()->SetTitle("PionDiss");

    //CNM graph
    TGraph *grCNMCMS_M = new TGraph(NN,nPart,CNMEffectsCMS);
    grCNMCMS_M->SetName("grCNMCMS_M");
    grCNMCMS_M->SetTitle("grCNMCMS_M");
    grCNMCMS_M->SetLineWidth(2);
    grCNMCMS_M->SetLineColor(2);
    grCNMCMS_M->SetLineStyle(2);
    grCNMCMS_M->GetXaxis()->SetTitle("N_{Part}");
    grCNMCMS_M->GetYaxis()->SetTitle("CNM");

    // RAA graphs
    TGraph *grRAACMS_M = new TGraph(NN,nPart,RAACMS);
    grRAACMS_M->SetName("grRAACMS_M");
    grRAACMS_M->SetTitle("grRAACMS_M");
    grRAACMS_M->SetLineWidth(2);
    grRAACMS_M->GetXaxis()->SetTitle("N_{Part}");
    grRAACMS_M->GetYaxis()->SetTitle("R_{AA}");
  

    TGraph *grFormCMS_M = new TGraph(NN,nPart,jpsiFormCMS);
    grFormCMS_M->SetName("grFormCMS_M");
    grFormCMS_M->SetTitle("grFormCMS_M");
    grFormCMS_M->SetLineWidth(2);
    grFormCMS_M->SetLineColor(2);
    grFormCMS_M->SetLineStyle(4);
    
    TGraph *grDissCMS_M = new TGraph(NN,nPart,jpsiDissCMS);
    grDissCMS_M->SetName("grDissCMS_M");
    grDissCMS_M->SetTitle("grDissCMS_M");
    grDissCMS_M->SetLineWidth(2);
    grDissCMS_M->SetLineColor(4);
    grDissCMS_M->SetLineStyle(6);
    
    TLegend *legd7 = new TLegend(0.17,0.66,0.63,0.93);
    legd7->SetBorderSize(0);
    legd7->SetFillStyle(0);
    legd7->SetFillColor(0);
    legd7->SetTextSize(0.040);
    
    new TCanvas;
    gPad->SetTicks();
    Draw_CMS_JPsi_RaaVsNpart(legd7);
    legd7->AddEntry(grDissCMS_M,"Gluon Dissociation","L");
    legd7->AddEntry(grPionDissCMS_M,"Comover","L");
    legd7->AddEntry(grRAACMS_M,"Total (R_{AA})","L");
    //grCNMCMS_M->Draw("sameL");
    grPionDissCMS_M->Draw("sameL");
    //grFormCMS_M->Draw("sameL");
    grDissCMS_M->Draw("sameL");
    grRAACMS_M->Draw("sameL");
    legd7->Draw("same");
    gPad->SaveAs("Fig6b_CMS_RAA_JPsi.eps");
    gPad->SaveAs("Fig6b_CMS_RAA_JPsi.png");
    
    
    //====================== Calculation graphs for ALICE ==========================//
    //PionDiss graph
    TGraph *grPionDissALICE_M = new TGraph(NN,nPart,PionDissALICE);
    grPionDissALICE_M->SetName("grPionDissALICE_M");    
    grPionDissALICE_M->SetTitle("grPionDissALICE_M");    
    grPionDissALICE_M->SetLineWidth(2);
    grPionDissALICE_M->SetLineColor(8);
    grPionDissALICE_M->SetLineStyle(2);
    grPionDissALICE_M->GetXaxis()->SetTitle("N_{Part}");
    grPionDissALICE_M->GetYaxis()->SetTitle("PionDiss");
    
    //CNM graph
    TGraph *grCNMALICE_M = new TGraph(NN,nPart,CNMEffectsALICE);
    grCNMALICE_M->SetName("grCNMALICE_M");
    grCNMALICE_M->SetTitle("grCNMALICE_M");
    grCNMALICE_M->SetLineWidth(2);
    grCNMALICE_M->SetLineColor(2);
    grCNMALICE_M->SetLineStyle(2);
    grCNMALICE_M->GetXaxis()->SetTitle("N_{Part}");
    grCNMALICE_M->GetYaxis()->SetTitle("CNM");
    

    // RAA graphs
    TGraph *grRAAALICE_M = new TGraph(NN,nPart,RAAALICE);
    grRAAALICE_M->SetName("grRAAALICE_M");
    grRAAALICE_M->SetTitle("grRAAALICE_M");
    grRAAALICE_M->SetLineWidth(2);
    grRAAALICE_M->GetXaxis()->SetTitle("N_{Part}");
    grRAAALICE_M->GetYaxis()->SetTitle("R_{AA} ");
    
    TGraph *grFormALICE_M = new TGraph(NN,nPart,jpsiFormALICE);
    grFormALICE_M->SetName("grFormALICE_M");
    grFormALICE_M->SetTitle("grFormALICE_M");
    grFormALICE_M->SetLineWidth(2);
    grFormALICE_M->SetLineColor(2);
    grFormALICE_M->SetLineStyle(4);
    
    TGraph *grDissALICE_M = new TGraph(NN,nPart,jpsiDissALICE);
    grDissALICE_M->SetName("grDissALICE_M");
    grDissALICE_M->SetTitle("grDissALICE_M");
    grDissALICE_M->SetLineWidth(2);
    grDissALICE_M->SetLineColor(4);
    grDissALICE_M->SetLineStyle(6);
    
    TLegend *legd8 = new TLegend(0.17,0.56,0.54,0.91);
    legd8->SetBorderSize(0);
    legd8->SetFillStyle(0);
    legd8->SetFillColor(0);
    legd8->SetTextSize(0.035);
  
    new TCanvas;
    gPad->SetTicks();
    Draw_ALICEFor_JPsi_RaaVsNpart(legd8);  
    legd8->AddEntry(grDissALICE_M,"Gluon Dissociation","L");
    //legd8->AddEntry(grCNMALICE_M,"Nucl. Abs.","L");
    legd8->AddEntry(grPionDissALICE_M,"Comover","L");
    legd8->AddEntry(grFormALICE_M,"Formation","L");
    legd8->AddEntry(grRAAALICE_M,"Total","L");
  
    grFormALICE_M->Draw("sameL");
    grDissALICE_M->Draw("sameL");
    grRAAALICE_M->Draw("sameL");
    //grCNMALICE_M->Draw("sameL"); 
    grPionDissALICE_M->Draw("sameL"); 
    legd8->Draw("same");
    gPad->SaveAs("Fig6a_ALICE_RAA.eps");
    gPad->SaveAs("Fig6a_ALICE_RAA.png");
  
    TLegend *legd9 = new TLegend( 0.17,0.52,0.54,0.95);
    legd9->SetBorderSize(0);
    legd9->SetFillStyle(0);
    legd9->SetFillColor(0);
    legd9->SetTextSize(0.028);
    

    //new TCanvas;
    //gPad->SetTicks();
    //Draw_ALICEMid_JPsi_RaaVsNpart(legd9);  
    //legd9->AddEntry(grDissALICE_M,"Gluon Dissociation","L");
    //legd9->AddEntry(grCNMALICE_M,"Nucl. Abs.","L");
    //legd9->AddEntry(grPionDissALICE_M,"#pi Dissociation","L");
    //legd9->AddEntry(grFormALICE_M,"Formation","L");
    //legd9->AddEntry(grRAAALICE_M,"Total","L");
    //grFormALICE_M->Draw("sameL");
    //grDissALICE_M->Draw("sameL");
    //grRAAALICE_M->Draw("sameL");
    //grCNMALICE_M->Draw("sameL"); 
    //grPionDissALICE_M->Draw("sameL"); 
    //gPad->SaveAs("ALICEMid_RAA.eps");
    //gPad->SaveAs("ALICEMid_RAA.png");
        
    new TCanvas;
    grNJpsiStat->Draw("APL");
    grFormALICE_M->Draw("sameL");
  

  if(isUps==1){  
    //============================= CMS Upsilon Graphs Data =================================//
    TLegend *legd10 = new TLegend( 0.21,0.70,0.62,0.92);
    legd10->SetBorderSize(0);
    legd10->SetFillStyle(0);
    legd10->SetFillColor(0);
    legd10->SetTextSize(0.035);
    TCanvas *c1 =new TCanvas;
    gPad->SetTicks(1);
    Draw_CMS_Y1S_RaaVsNpart(legd10);
    legd10->AddEntry(grDissCMS_M,"Gluon Dissociation","L");
    //legd10->AddEntry(grCNMCMS_M,"Nucl. Abs.","L");
    legd10->AddEntry(grPionDissCMS_M,"Comover","L");
    //legd7->AddEntry(grFormCMS_M,"Formation","L");
    legd10->AddEntry(grRAACMS_M,"Total","L");
    grPionDissCMS_M->Draw("sameL");
    //grCNMCMS_M->Draw("sameL");
    grRAACMS_M->Draw("sameL"); 
    grDissCMS_M->Draw("sameL");
    
    legd10->Draw("same");
    c1->Update();
    gPad->SaveAs("Fig7a_CMS_RAA_Upsilon1S.eps");
    gPad->SaveAs("Fig7a_CMS_RAA_Upsilon1S.png");
    
    //============================= ALICE Upsilon Graphs Data =================================//
    
    TLegend *legd11 = new TLegend( 0.46,0.66,0.83,0.85);
    legd11->SetBorderSize(0);
    legd11->SetFillStyle(0);
    legd11->SetFillColor(0);
    legd11->SetTextSize(0.040);
    new TCanvas;
    gPad->SetTicks(1);
    Draw_ALICEFor_Y1S_RaaVsNpart(legd11);
    
    legd11->AddEntry(grDissCMS_M,"Gluon Dissociation","L");
    legd11->AddEntry(grCNMCMS_M,"Nucl. Abs.","L");
    legd11->AddEntry(grPionDissCMS_M,"#pi Dissociation","L");
    //legd7->AddEntry(grFormCMS_M,"Formation","L");
    legd11->AddEntry(grRAACMS_M,"Total","L");
    grCNMCMS_M->Draw("sameL");
    grRAACMS_M->Draw("sameL"); 
    grDissCMS_M->Draw("sameL");
        
    //return;
    TLegend *legd12 = new TLegend( 0.46,0.66,0.83,0.85);
    legd12->SetBorderSize(0);
    legd12->SetFillStyle(0);
    legd12->SetFillColor(0);
    legd12->SetTextSize(0.040);

    new TCanvas;
    gPad->SetTicks(1);
    Draw_CMS_Y2S_RaaVsNpart(legd12);
    legd12->AddEntry(grDissCMS_M,"Gluon Dissociation","L");
    legd12->AddEntry(grCNMCMS_M,"Nucl. Abs.","L");
    legd12->AddEntry(grPionDissCMS_M,"Comover","L");
    //legd12->AddEntry(grFormCMS_M,"Formation","L");
    legd12->AddEntry(grRAACMS_M,"Total","L");
    grCNMCMS_M->Draw("sameL");
    grRAACMS_M->Draw("sameL"); 
    grPionDissCMS_M->Draw("sameL"); 
    grDissCMS_M->Draw("sameL");
    legd7->Draw("same");
    
    gPad->SaveAs("Fig7b_CMS_RAA_Upsilon2S.eps");
    gPad->SaveAs("Fig7b_CMS_RAA_Upsilon2S.png");

  }


  
  grSigF->Write();
  grSigD->Write();
  grSigDQ0->Write();
  grTempVsTauAna->Write();
  grTempVsTauAnaB->Write();
  grFQGPVsTau->Write();
  grFQGPVsTau2->Write();
  
  grFormRateVsT_MCInt_P1->Write();
  grFormRateVsT_MCInt_P2->Write();
  grFormRateVsT_MCInt_P3->Write();
  
  grFormRate_TripleInt_P1->Write();
  grFormRate_TripleInt_P2->Write();
  grFormRate_TripleInt_P3->Write();


  DissRate_Khar->Write();
  DissRate_Khar36->Write();
  DissRate_Khar86->Write();
  

  grDissRateVsPt1->Write();
  grDissRateVsPt2->Write();
  grDissRateVsPt3->Write();

  /*
  grRAAALICEPt_M->Write();
  grPionDissALICEPt_M->Write();
  grGluonDissALICEPt_M->Write();
  grRegenALICEPt_M->Write();
 
  grRAACMSPt_M->Write();
  grPionDissCMSPt_M->Write();
  grGluonDissCMSPt_M->Write();
  grRegenCMSPt_M->Write();
  */
  grRAACMSRap_M->Write();
  grPionDissCMSRap_M->Write();
  grGluonDissCMSRap_M->Write();

  grCNMCMS_M->Write();
  grPionDissCMS_M->Write();
  grFormCMS_M->Write();
  grDissCMS_M->Write();
  grRAACMS_M->Write();
  
  grFormALICE_M->Write();
  grDissALICE_M->Write();
  grRAAALICE_M->Write();
  grCNMALICE_M->Write(); 
  grPionDissALICE_M->Write();
  
  
  //OutFile->Write();
  //OutFile->Close();
  
}




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

Double_t CalculateTandf(int Flag, Double_t T0Cent, Double_t R0Cent, Double_t tauCCent, Double_t tauhCent, Double_t taufCent)
{

  stepTau = 0.1;
  //NTau = (int)((tauhCent-tau0)/stepTau);
  NTau = (int)((taufCent-tau0)/stepTau);

  for (int i= 0; i<=NTau; i++) {
    Tau[i] = tau0 + stepTau*i;
    TempTau[i] = TauToTemp_All(Flag,T0Cent,R0Cent,Tau[i]);
    fQGP[i] = FQGP(Flag,R0Cent,tauCCent, tauhCent,Tau[i]);
  }
  return 0;
}


Double_t FQGP(Int_t Flag, Double_t R0Cent, Double_t TauCCent, Double_t TauHCent, Double_t Tau1)
{
  Double_t fqgp=0.0;
  Double_t Nomi=0.0;
  Double_t Deno=0.0;
  
  if(Tau1 <= TauCCent){fqgp =1.0; return fqgp;}
  if(Tau1 > TauHCent){fqgp =0.0; return fqgp;}

  if(Flag ==1){
    Nomi=aq*(Tau1-TauCCent);
    Deno=(aq-ah)*Tau1;
    fqgp = 1 - (Nomi/Deno); 
  }
 
  if(Flag ==2) { 
    Double_t Rtau = R0Cent+0.5*aT*Tau1*Tau1;
    Double_t RtauC = R0Cent+0.5*aT*TauCCent*TauCCent;
    Nomi=aq*TauCCent*RtauC*RtauC - ah*Tau1*Rtau*Rtau;
    Deno= (aq - ah)*Tau1*Rtau*Rtau;
    fqgp = Nomi/Deno;
  }
  return fqgp;
}


Double_t TauToTemp_All(Int_t Flag, Double_t T0Cent, Double_t R0Cent, Double_t Tau1) 
{
  Double_t TauC = 0.0;
  Double_t TauH = 0.0;
  Double_t TauF = 0.0;
  
  Double_t Temp = 0;
  if( Flag ==1) 
    {
      TauC = Tau0ToTauC(1,T0Cent,R0Cent);
      TauH = TauCToTauh(1,TauC, R0Cent);
      TauF = TauhToTauf(1,TauH, R0Cent);

      if(Tau1 >= tau0 && Tau1 <= TauC) {Temp = pow(T0Cent*T0Cent*T0Cent*tau0/Tau1, 1.0/3.0);}
      if(Tau1 > TauC && Tau1 <= TauH ) {Temp = TC;}
      if(Tau1 > TauH && Tau1 <= TauF ) {Temp = TC*pow(TauH/Tau1,1.0/3.0);}
    }
  
  if(Flag ==2) {
    TauC = Tau0ToTauC(2,T0Cent,R0Cent);
    TauH = TauCToTauh(2,TauC, R0Cent);
    TauF = TauhToTauf(2,TauH, R0Cent);
    
    if(Tau1 >= tau0 && Tau1 <= TauC) { 
      Double_t Num = T0Cent*T0Cent*T0Cent*(R0Cent+0.5*aT*tau0*tau0)*(R0Cent+0.5*aT*tau0*tau0)*(z0+vZ*tau0);   
      Double_t Deno = (R0Cent+0.5*aT*Tau1*Tau1)*(R0Cent+0.5*aT*Tau1*Tau1)*(z0+vZ*Tau1);
      Double_t Sum = Num/Deno;
      Temp = pow(Sum, 1.0/3.0);
    }
    if(Tau1 > TauC && Tau1 <= TauH ){Temp = TC;}
    if(Tau1 > TauH && Tau1 <= TauF ){
      Double_t Num=TauH*(R0Cent+0.5*aT*TauH*TauH)*(R0Cent+0.5*aT*TauH*TauH);
      Double_t Deno=Tau1*(R0Cent+0.5*aT*Tau1*Tau1)*(R0Cent+0.5*aT*Tau1*Tau1);
      Double_t Sum=Num/Deno;
      Temp = TC*pow((Sum),1.0/3.0);   
    }
  }


  return Temp; 
}

Double_t Tau0ToTauC(Int_t Flag, Double_t T0Cent, Double_t R0Cent) 
{
  Double_t TauCValLong=0;
  Double_t TauCValCylnd = 0;
  TauCValLong = T0Cent*T0Cent*T0Cent*tau0/(TC*TC*TC);
  
  if(Flag ==2) {
    Double_t TauCG = TauCValLong;
    Double_t delta;
    Int_t iters=0;
    do{
      Double_t sV0 =T0Cent*T0Cent*T0Cent*tau0*(R0Cent+0.5*aT*tau0*tau0)*(R0Cent+0.5*aT*tau0*tau0);
      Double_t Fx = TC*TC*TC*TauCG*(R0Cent+0.5*aT*TauCG*TauCG)*(R0Cent+0.5*aT*TauCG*TauCG)-sV0;     
      Double_t FxPrime= TC*TC*TC*2*(R0Cent*TauCG*TauCG+0.5*aT*TauCG*TauCG*TauCG*TauCG)*(2.0*R0Cent*TauCG + 2.0*aT*TauCG*TauCG*TauCG);
      TauCValCylnd = TauCG - 5.0*(Fx/FxPrime);
      delta=fabs(TauCValCylnd-TauCG);
      TauCG=TauCValCylnd;
      iters++;
      //cout<<delta<<" delta "<<TauCValCylnd<<endl;
    }while(delta > 0.001);
   
    //Double_t sV0 =T0Cent*T0Cent*T0Cent*tau0*(R0Cent+0.5*aT*tau0*tau0)*(R0Cent+0.5*aT*tau0*tau0);
    //Double_t Fx2 = TC*TC*TC*TauCG*(R0Cent+0.5*aT*TauCG*TauCG)*(R0Cent+0.5*aT*TauCG*TauCG)-sV0;     
    //cout<<" TauCG "<<TauCG<< "  Fx2 "<<Fx2<<" iter: "<<iters<<endl;
  }
  
  Double_t TauCVal=0;
  if(Flag==1) {TauCVal=TauCValLong;}
  if(Flag==2) {TauCVal=TauCValCylnd;}
  
  return TauCVal;
}


Double_t TauCToTauh(Int_t Flag, Double_t TauC, Double_t R0Cent)
{
  Double_t TauHLong =aq*TauC/ah;
  Double_t TauHCylnd=0;

  if(Flag ==2){
    Double_t TauHG=TauHLong;
    Double_t delta;
    Int_t iters=0;
    do{
      Double_t C = aq*TauC*(R0Cent+0.5*aT*TauC*TauC)*(R0Cent+0.5*aT*TauC*TauC);
      Double_t Fx = 0.25*ah*aT*aT*pow(TauHG,5) + R0Cent*ah*aT*pow(TauHG,3) + ah*R0Cent*R0Cent*TauHG - C;
      Double_t FPrimex = 1.25*ah*aT*aT*pow(TauHG,4) + 3.0*R0Cent*ah*aT*pow(TauHG,2) + ah*R0Cent*R0Cent;
      TauHCylnd = TauHG  - (Fx/FPrimex);
      delta=fabs(TauHCylnd-TauHG);
      TauHG=TauHCylnd;
      iters++;
    }while(delta > 0.001);
    
    //Double_t C =aq*TauC*(R0Cent+0.5*aT*TauC*TauC)*(R0Cent+0.5*aT*TauC*TauC);
    //Double_t Fx2 =  0.25*ah*aT*aT*pow(TauHG,5) + R0Cent*ah*aT*pow(TauHG,3) + ah*R0Cent*R0Cent*TauHG - C;
    // cout<<TauHLong << "  "<<TauHG<<" Fx2   "<<Fx2<<"   "<<iters<<endl;
  }
  Double_t TauHVal=0;
  
  if(Flag ==1){TauHVal=TauHLong;}
  if(Flag ==2){TauHVal=TauHCylnd;}

  return TauHVal;
}

Double_t TauhToTauf(Int_t Flag, Double_t Tauh, Double_t R0Cent)
{
  Double_t TauFCylnd=0;
  Double_t TauFLong=0;
  TauFLong = TC*TC*TC*Tauh/(TF*TF*TF);
  if(Flag ==2){
    Double_t TauFG=TauFLong ;
    Double_t delta;
    Int_t iters=0;
    do{
      Double_t C = TC*TC*TC*Tauh*(R0Cent+0.5*aT*Tauh*Tauh)*(R0Cent+0.5*aT*Tauh*Tauh);
      Double_t Fx =TF*TF*TF*TauFG*(R0Cent+0.5*aT*TauFG*TauFG)*(R0Cent+0.5*aT*TauFG*TauFG)-C;
      Double_t FPrimex = TF*TF*TF*(R0Cent+0.5*aT*TauFG*TauFG)*(R0Cent+0.5*aT*TauFG*TauFG)+2.0*TF*TF*TF*aT*TauFG*TauFG*(R0Cent+0.5*aT*TauFG*TauFG);
      TauFCylnd = TauFG  - (Fx/FPrimex);
      delta=fabs(TauFCylnd-TauFG);
      TauFG=TauFCylnd;
      iters++;
    }while(delta > 0.001);
  }
  Double_t TauFVal=0;
  if(Flag==1){TauFVal=TauFLong;}
  if(Flag==2){TauFVal=TauFCylnd;}
  return TauFVal;
}



//  Xu and Kharjeev /////////////////////////////////////////////////
Double_t DissRateIntpT(Double_t T)
{
  Double_t Ptmin= 0.1;
  Double_t Ptmax=30.0;
  Double_t Ptstep=0.2;
  int NN_Pt= (int)((Ptmax-Ptmin)/Ptstep);
  Double_t sum=0;
  
  for(int i=1;i<=NN_Pt;i++) {
    Double_t Pt=Ptmin+i*Ptstep;
    Double_t yield=Jpsi_Pt->GetBinContent(Jpsi_Pt->FindBin(Pt));
    sum=sum+ (yield*DissRateXu(Pt,T));
    //cout<<Pt<<"  "<<DissRateXu(Pt,T)<<endl;

  }
  return sum;
}

Double_t DissRateXu(Double_t pT, Double_t T)
{
  Double_t mT=TMath::Sqrt(pT*pT+mJpsi*mJpsi);
  Double_t lambdag =1.0;
  Double_t fac=(lambdag/(8*pi3))*2.0*pi*mJpsi*mJpsi/mT;
  int nmin = 1;
  int nmax = 20;
  int nstep = 1;
  int NNn=(nmax-nmin)/nstep;

  Double_t sum=0;

  for(int i=0;i<NNn;i++) {
    int n=nmin+i*nstep;
    sum=sum+DissFuncXu(pT,T,n)*T/n;   // does not include 16/(2pi)^3
  }
  Double_t func= sum*nstep;

  return (fac*func)/hbarc;
}

Double_t DissFuncXu(Double_t pT, Double_t T, Double_t n)
{
  Double_t mT=TMath::Sqrt(pT*pT + mJpsi*mJpsi);
  Double_t qmin=ep0;
  Double_t qmax=8.0+ep0;
  Double_t qstep=0.1;
  int NNq=(int)((qmax-qmin)/qstep);
  Double_t sum=0;
  for(int i=0;i <NNq;i++){
    Double_t q=qmin+i*qstep;
    Double_t qq = n*q/(mJpsi*T);
    Double_t fac = 2.0*qq*exp(-qq*mT);
    if (pT>0) fac = ( exp(-qq*(mT-pT)) - exp(-qq*(mT+pT)) )/pT;
    Double_t Func = q*SigmaD(1,q)*fac;
    sum=sum+Func;
  }

  Double_t DissFunc = sum*qstep;
  return DissFunc;;
}
// End  Xu and Kharjeev /////////////////////////////////////////////////


//////////////////////////////////////////////////////////
// Formation /////////////////////////////////////////////
/////////////////////////////////////////////////////////


Double_t RegenratedQuarkoniaNPart(Double_t NCC, Double_t NJPsi, Double_t R0) 
{
  
  Double_t Pt[25]={0.25,0.75,1.25,1.75,2.25,2.75,3.25,3.75,4.25,4.75,5.25,5.75,6.25,6.75,7.25,7.75,8.25,8.75,9.25,9.75,10.25};
  int NN=20;
    
  Double_t RegenQuarkNum=0.0;
  Double_t RegenQuarkDeno=0.0;
  Double_t RegenQuark=0.0;

  for(int i=0; i<NN; i++) {
    
    Double_t GluonDissALICEPt=IntDiss_All(Pt[i]);
    Double_t NJPsiRegenALICEPt=GluonDissALICEPt*NCC*NCC*IntFormVsPt(Pt[i],R0);

    RegenQuarkNum = RegenQuarkNum + NJPsiRegenALICEPt;   

    Double_t NJPsi0ALICEPt= Jpsi_Pt->GetBinContent(Jpsi_Pt->FindBin(Pt[i]));
    Double_t JPsiIntSh = 1.0/0.65;
    RegenQuarkDeno= RegenQuarkDeno + ( NJPsi* JPsiIntSh * NJPsi0ALICEPt);
  }


  RegenQuark=(RegenQuarkNum/RegenQuarkDeno);
  return  RegenQuark;

}













//Formation Rate MC
Double_t FormRate(Double_t Temp) {
  Double_t PMin=0.0001;
  Double_t PMax=10.0;
  Double_t ThetaMin=0.0;
  Double_t ThetaMax=TMath::Pi();
  Double_t PhiMin=0.0;
  Double_t PhiMax=2.0*TMath::Pi();
  
  //  int nTrials = 500000;

  int nTrials = 100000;
  
  Double_t Sum=0;
  Double_t Sum1=0;
  for(int i =1; i<= nTrials; i++) {
    Double_t RanNo1, RanNo2, RanNo3, RanNo4, RanNo5, RanNo6;
    RanNo1=gRandom->Rndm();
    RanNo2=gRandom->Rndm();
    
    RanNo3=gRandom->Rndm();
    RanNo4=gRandom->Rndm();
    RanNo5=gRandom->Rndm();
    RanNo6=gRandom->Rndm();
    
    Double_t p1=PMin+(PMax-PMin)*RanNo1;
    Double_t p2=PMin+(PMax-PMin)*RanNo2;
    
    Double_t theta1= ThetaMin + (ThetaMax -ThetaMin )*RanNo3;
    Double_t theta2= ThetaMin + (ThetaMax -ThetaMin )*RanNo4;
    Double_t phi1= PhiMin + (PhiMax -PhiMin )*RanNo5;
    Double_t phi2= PhiMin + (PhiMax -PhiMin )*RanNo6;
    Double_t fun = p1*p1*p2*p2*sin(theta1)*sin(theta2)*fcharm(p1,Temp)*fcharm(p2,Temp);
    Sum = Sum + FormFun(p1,p2,theta1,theta2,phi1,phi2)*fun;
    Sum1 = Sum1 + fun;
  }
  Double_t step = ((PMax- PMin)*(PMax- PMin)*(ThetaMax-ThetaMin)*(ThetaMax-ThetaMin)*(PhiMax-PhiMin)*(PhiMax-PhiMin))/nTrials;
  Double_t ForRate  = step*Sum;
  Double_t ForRateDeno  = step*Sum1;
  return (ForRate/ForRateDeno)*hbarc2;
}


Double_t FormFun(Double_t p1, Double_t p2, Double_t theta1, Double_t theta2, Double_t phi1, Double_t phi2)
{
  Double_t p1dotp2 = p1*p2*TMath::Sin(theta1)*TMath::Sin(theta2)*TMath::Cos(phi1-phi2) + p1*p2*TMath::Cos(theta1)*TMath::Cos(theta2);
  Double_t E1 = sqrt(p1*p1 + mQ2);
  Double_t E2 = sqrt(p2*p2 + mQ2);
  Double_t s = 2*mQ2 + 2*E1*E2 - 2.0*p1dotp2; 
  //  ccbar to Jpsi cross section
  //  Double_t FJPsi = 0;
  //  if(qSquare > 0 && (4*mD*mD - 4*mQ2 - qSquare) > 0) FJPsi = 0.01*sigmapp ; // sigmapp ???
  Double_t FJPsi = SigmaFS(s);
  //Double_t FJPsi = 1.0;
  // Relative Velocity 
  Double_t num = s-4.0*mQ2;
  Double_t RelVel = sqrt(s)*sqrt(num)/(2.0*E1*E2);
  Double_t allfactors = RelVel *FJPsi;

  return allfactors;
}




Double_t FormRateMC_P(Double_t Temp, Double_t Pt) 
{
  TH1D *Hist = new TH1D("HistPt","HistPt",100.0,0.0,50.0);
  //TH1D *Hist = new TH1D("HistPt","HistPt",500.0,0.0,50.0);
  Double_t PMin=0.0001;
  Double_t PMax=10.0;
  
  Double_t ThetaMin=0.0;
  Double_t ThetaMax=TMath::Pi();
  Double_t PhiMin=0.0;
  Double_t PhiMax=2.0*TMath::Pi();
  
  int nTrials = 500000;
  
  Double_t Sum=0;
  Double_t Sum1=0;

  for(int i =1; i<= nTrials; i++) {
    
    Double_t RanNo1, RanNo2;
    Double_t RanNo3, RanNo4, RanNo5, RanNo6;	
    
    RanNo1=gRandom->Rndm();
    RanNo2=gRandom->Rndm();
    RanNo3=gRandom->Rndm();
    RanNo4=gRandom->Rndm();
    RanNo5=gRandom->Rndm();
    RanNo6=gRandom->Rndm();
    
    Double_t p1=PMin+(PMax-PMin)*RanNo1;
    Double_t p2=PMin+(PMax-PMin)*RanNo2;
    Double_t theta1= ThetaMin + (ThetaMax -ThetaMin )*RanNo3;
    Double_t theta2= ThetaMin + (ThetaMax -ThetaMin )*RanNo4;
    Double_t phi1= PhiMin + (PhiMax -PhiMin )*RanNo5;
    Double_t phi2= PhiMin + (PhiMax -PhiMin )*RanNo6;
      
    Double_t Px1,Py1,Pz1,Px2,Py2,Pz2;
	
    Px1=p1*sin(theta1)*cos(phi1);
    Py1=p1*sin(theta1)*sin(phi1);
    Pz1=p1*cos(theta1);
    TVector3 PC;
    PC.SetXYZ(Px1,Py1,Pz1);
	
    Px2=p2*sin(theta2)*cos(phi2);
    Py2=p2*sin(theta2)*sin(phi2);
    Pz2=p2*cos(theta2);
    TVector3 PCbar;
    PCbar.SetXYZ(Px2,Py2,Pz2);
    
    TVector3 PCCbar = PC + PCbar;
    Double_t PJpsi=PCCbar.Mag();

    Double_t funNum = FormFun(p1,p2,theta1,theta2,phi1,phi2)*p1*p1*p2*p2*sin(theta1)*sin(theta2)*fcharm(p1,Temp)*fcharm(p2,Temp);
    Double_t funDeno = p1*p1*p2*p2*sin(theta1)*sin(theta2)*fcharm(p1,Temp)*fcharm(p2,Temp);
    
    Sum = Sum + funNum;
    Sum1 = Sum1 + funDeno;
    
    Hist->Fill(PJpsi,funNum);
  }
  
  Double_t step = ((PMax- PMin)*(PMax- PMin)*(ThetaMax-ThetaMin)*(ThetaMax-ThetaMin)*(PhiMax-PhiMin)*(PhiMax-PhiMin))/nTrials;
  
  Double_t ForRate  = step*Sum;
  Double_t ForRateDeno  = step*Sum1; 
  
  Hist->Scale(hbarc2*step/(ForRateDeno*Hist->GetBinWidth(0))); 
  Double_t ForRateAtPt = Hist->GetBinContent(Hist->FindBin(Pt));

  //new TCanvas;
  
  //cout<<" Hist Integral "<<Hist->Integral()*Hist->GetBinWidth(0)<<endl;

  Hist->Delete();

  //FormRateMC->Integral();
  //Double_t LambdaF_MC=(ForRate/ForRateDeno)*hbarc2;
  //cout<<"Hist Int  "<<Hist->Integral()<<"   "<<LambdaF_MC<<"   "<<(LambdaF_MC-Hist->Integral())/LambdaF_MC<<endl;
  //return LambdaF_MC;

  return ForRateAtPt;

}



Double_t FormFun2(Double_t p1, Double_t p2, Double_t CosTheta)
{
  Double_t p1dotp2 = p1*p2*CosTheta;

  double E1 = sqrt(p1*p1 + mQ2);
  Double_t E2 = sqrt(p2*p2 + mQ2);
  Double_t s = 2*mQ2 + 2*E1*E2 - 2.0*p1dotp2; 
  Double_t FJPsi = SigmaFS(s);
  //Double_t FJPsi = 1.0;
  // Relative Velocity 
  Double_t num = s-4.0*mQ2;
  Double_t RelVel = sqrt(s)*sqrt(num)/(2.0*E1*E2);
  Double_t allfactors = RelVel*FJPsi;
  return allfactors;
}













//============= Form Function Analytical integral ============================//
Double_t IntFormFun2(Double_t T)
{
  Double_t P1Step = 0.05;
  Double_t P1Start = 0.0001;
  Double_t P1End = 10.0;
  int P1N =(int)((P1End - P1Start)/P1Step);
  Double_t P2Step = 0.05;
  Double_t P2Start = 0.01;
  Double_t P2End = 10.0;
  int P2N =(int)((P2End - P2Start)/P2Step);
  Double_t CosThetaStep = 0.01;
  Double_t CosThetaStart = 1.0;
  Double_t CosThetaEnd = -1.0;
  int CosThetaN =(int)((CosThetaStart - CosThetaEnd)/CosThetaStep);
  Double_t IntP2=0;
  Double_t IntCosTheta =0;
  Double_t SumP1=0;  
  
  for(int i =0; i <= P1N ; i++) {
    Double_t p1 = P1Start + i*P1Step;
    Double_t SumP2=0;
    for(int j =0; j <= P2N ; j++) {
      Double_t p2 = P2Start + j*P2Step;
      Double_t SumCosTheta=0;
      for(int k =0; k <= CosThetaN ; k++)  {
	Double_t CosTheta = CosThetaStart - k *CosThetaStep;
	SumCosTheta = SumCosTheta + FormFun2(p1,p2,CosTheta);
      }//theta
      IntCosTheta = SumCosTheta*CosThetaStep;
      SumP2 = SumP2 + p2*p2*fcharm(p2,T)*IntCosTheta;
    }  //p2
    IntP2 =  SumP2*P2Step;
    SumP1=SumP1+ p1*p1*fcharm(p1,T)*IntP2;
  }//p1
  Double_t IntNum =  8.0*pi2*SumP1*P1Step;
  Double_t SumP1Deno=0.0;
  for(int i =0; i <= P1N ; i++)
    {
      Double_t p1 = P1Start + i*P1Step;
      SumP1Deno=SumP1Deno + p1*p1*fcharm(p1,T);
    }
  Double_t IntP1Deno=4.0*pi*SumP1Deno*P1Step;
  double IntDeno = IntP1Deno*IntP1Deno;
  return  IntNum*hbarc2/IntDeno;
}



Double_t IntFormFun2_P(Double_t P, Double_t T)
{
  // cos(theta) integration put p1 = -p2 cos(theta) + sqrt(p2^2 cos^2(theta) - 4.0 (p2^2-pjpsi)/2.0
  //Double_t P2Step = 0.05;
  //Double_t P2Start = 0.001;
  //Double_t P2End = 10.0;
  //int P2N =(int)((P2End - P2Start)/P2Step);
  
  int P2N =200;
  Double_t P2Start = 0.001;
  //Double_t P2End = TMath::Sqrt(4.0*P*P/3.0);
  Double_t P2End = (P-P2Start);
  Double_t P2Step = (P2End-P2Start)/P2N;

  Double_t CosThetaStep = 0.05;
  Double_t CosThetaStart = 1.0;
  Double_t CosThetaEnd = -1.0;
  int CosThetaN =(int)((CosThetaStart-CosThetaEnd)/CosThetaStep);
  Double_t IntCosTheta =0;
  
  Double_t SumP2=0;  
  for(int i =0; i <= P2N ; i++) {
    Double_t p2 = P2Start + i*P2Step;
    Double_t SumCosTheta=0;
    for(int k =0; k <= CosThetaN ; k++)  {
      Double_t CosTheta = CosThetaStart - k*CosThetaStep;
      
      Double_t p1t =0.5*(-p2*CosTheta + TMath::Sqrt( p2*p2*CosTheta*CosTheta - 4.0*(p2*p2-P*P)));
      
      if(p2*p2*CosTheta*CosTheta - 4.0*(p2*p2-P*P) <0 ) cout<<" p2 "<<p2<<" PJPsi "<<P<<"  "<<" CosTheta "<<CosTheta<<" "<< p2*p2*CosTheta*CosTheta - 4.0*(p2*p2-P*P)<<endl;

      SumCosTheta = SumCosTheta + p1t*p1t*fcharm(p1t,T)*FormFun2(p1t,p2,CosTheta);
    }//theta
    IntCosTheta = SumCosTheta*CosThetaStep;
    SumP2=SumP2 + p2*p2*fcharm(p2,T)*IntCosTheta;
  }//p2
  Double_t IntP2 =  SumP2*P2Step;
  
  Double_t SumP2Deno=0.0;
  for(int i =0; i <= P2N ; i++)
    {
      Double_t p2 = P2Start + i*P2Step;
      SumP2Deno=SumP2Deno + p2*p2*fcharm(p2,T);
    }
  Double_t IntP2Deno=SumP2Deno*P2Step;
  return  IntP2*hbarc2/(2.0*IntP2Deno*IntP2Deno);
}


Double_t IntFormFun2_P_IntP(Double_t T)
{
  
  Double_t PStep = 0.01;
  Double_t PStart = 0.1;
  Double_t PEnd = 5.0;
  int PN =(int)((PEnd - PStart)/PStep);
  
  Double_t SumP=0;  
  for(int i =0; i <= PN ; i++) {
    Double_t P = PStart + i*PStep;
    SumP=SumP + P*P*IntFormFun2_P(P,T);
    //cout<<"IntFormFun2_P(P,T); "<<IntFormFun2_P(P,T)<<endl;
  }

  Double_t IntP =  SumP*PStep;
  
  //cout<<"IntP "<<SumP<<endl;

  return IntP;

}


Double_t IntForm(Double_t PtMin, Double_t R0Cent)
{
  Double_t IntDrate[10000];
  Double_t sumd = 0.0;
  
  for (int i= 0; i<=NTau; i++) {
    Double_t theta =1.0;
    if(Tau[i] < FormTau * (PtMin/mJpsi) ) theta =0;
    sumd = sumd +  fQGP[i]*theta*SigmaQuasiGluon(1,PtMin,TempTau[i]);
    IntDrate[i] =  exp(-sumd*stepTau/hbarc); 
  }
  
  Double_t sum=0;
  for (int i= 0; i<=NTau; i++) {
    Double_t DeltaY=1.0;
    Double_t VTau=Tau[i]*pi*(R0Cent+0.5*aT*Tau[i]*Tau[i])*(R0Cent+0.5*aT*Tau[i]*Tau[i])*DeltaY;
    Double_t Frate = fQGP[i]*FormRate(TempTau[i])/(VTau*IntDrate[i]); 
    
    sum = sum + Frate;
  }
  return sum*stepTau*hbarc2;
}    


Double_t IntFormVsPt(Double_t PtMin, Double_t R0Cent)
{

  Double_t IntDrate[10000];
  Double_t sumd = 0.0;
  
  for (int i= 0; i<=NTau; i++) {
    Double_t theta =1.0;
    if(Tau[i] < FormTau * (PtMin/mJpsi) ) theta =0;
    sumd = sumd +  fQGP[i]*theta*SigmaQuasiGluon(1,PtMin,TempTau[i]);
    IntDrate[i] =  exp(-sumd*stepTau/hbarc); 
  }
  
  Double_t sum=0;
  for (int i= 0; i<=NTau; i++) {
    Double_t DeltaY=1.0;
    Double_t VTau=Tau[i]*pi*(R0Cent+0.5*aT*Tau[i]*Tau[i])*(R0Cent+0.5*aT*Tau[i]*Tau[i])*DeltaY;
    Double_t Frate = fQGP[i]*FormRateMC_P(TempTau[i],PtMin)/(VTau*IntDrate[i]); 
    sum = sum + Frate;
  }
  return sum*stepTau*hbarc2;
}





Double_t fcharm(Double_t p, Double_t T)
{
  Double_t gi=1.0;
  Double_t fq = gi /(TMath::Exp(sqrt(p*p + mQ2)/T) + 1.0);
  //Double_t fq = gi/(TMath::Exp(p/T)+1.0);
  return fq;
}




// Dissociation rates ///////////////////////////////////////////////

Double_t IntDiss_PtInt(Double_t PtMin)
{
  //for 500 bins and step = 0.1
  //PtMin=0.05;
  //PtMin=6.45;
  
  //for 100 bins and step = 0.5
  //PtMin=0.25;
  //PtMin=6.25;

  Double_t Ptmax=0;
  if(isUps==0)Ptmax=20.75;
  if(isUps==1)Ptmax=40.25;

  Double_t Ptstep=0.5;
  int NN_Pt= (int)((Ptmax-PtMin)/Ptstep);
  Double_t sum=0;
  Double_t sumPt=0;
  Double_t yield =0;
  Double_t ShadowingFactor=0;

  for(int i=0;i<=NN_Pt;i++) {
    Double_t Pt=PtMin+i*Ptstep;
    if(isUps==0){yield=Jpsi_Pt->GetBinContent(Jpsi_Pt->FindBin(Pt));}
    //if(isUps==1){yield=Y1S_Pt->GetBinContent(Y1S_Pt->FindBin(Pt));}
    if(isUps==1){yield=Y2S_Pt->GetBinContent(Y2S_Pt->FindBin(Pt));}
    //Multiply shadowing factor here sum= sum + (yield*IntDiss_All(Pt) );
    ShadowingFactor=HistJpsiRaaShVsPt->Interpolate(Pt);
    sum= sum + (ShadowingFactor*yield*IntDiss_All(Pt) );
    sumPt = sumPt+yield;  
  }
  return sum/sumPt;
}

Double_t IntDiss_All(Double_t PtMin)
{
  Double_t sumd = 0.0;
  for (int i= 0; i<=NTau; i++) {
    Double_t theta =1.0;
    if(Tau[i] < FormTau * (PtMin/mJpsi) ) theta =0;
    sumd = sumd +fQGP[i]*theta*SigmaQuasiGluon(1,PtMin,TempTau[i]);
  }
  return exp(-sumd*stepTau/hbarc);
}


Double_t SigmaQuasiGluon(Int_t Flag , Double_t P1, Double_t T)
{
  double m1Square =  mJpsi*mJpsi;
  double m2Square =  mg*mg;
  Double_t E1 = TMath::Sqrt( P1*P1 + m1Square);

  Double_t P2Step = 0.1;
  Double_t P2Start = 0.00001;
  Double_t P2End = 5.0;
  int P2N =(int)((P2End - P2Start)/P2Step);
  
  Double_t CosThetaStep = 0.1;
  Double_t CosThetaStart = 1.0;
  Double_t CosThetaEnd = -1.0;
  int CosThetaN =(int)((CosThetaStart - CosThetaEnd)/CosThetaStep);
  
  Double_t SumP2=0;  
  Double_t ThetaVal=0;
  if(Flag ==1) {ThetaVal=ep02;}
  if(Flag ==2) {ThetaVal=TMath::Power(EDiss(1,T),2);}
  if(Flag ==3) {ThetaVal=TMath::Power(EDiss(1,T),2);}
  
  for(int i =0; i <= P2N ; i++) {
    Double_t P2 = P2Start + i*P2Step;
    Double_t E2 = TMath::Sqrt(P2*P2 + m2Square);
    double fgluon = fGluon(P2,T);

    Double_t SumCosTheta=0;
    for(int k =0; k <= CosThetaN ; k++)  {
      Double_t CosTheta = CosThetaStart - k*CosThetaStep;
      Double_t fourP1DotP2 = E1*E2-P1*P2*CosTheta;
      Double_t S = m1Square + m2Square + 2*fourP1DotP2;
      if(S<= ThetaVal ) continue;
      Double_t VRel =TMath::Sqrt(fourP1DotP2*fourP1DotP2 - m1Square*m2Square)/(E1*E2);
      Double_t SGD = 0;
      
      if(Flag ==1) {SGD = SigmaGluonDissS(S);}
      if(Flag ==2) {SGD =SigmaGluonDissS_Med(S,T);}
      if(Flag ==3) {SGD = SigmaThermalAct(1,T);}
      SumCosTheta = SumCosTheta + SGD*VRel;
    }//theta
    
    double IntCosTheta = SumCosTheta*CosThetaStep;
    SumP2 = SumP2 + P2*P2*fgluon*IntCosTheta;  
  }//P2

  Double_t IntP2 = (SumP2*P2Step)/(4.0*pi2);
  return IntP2;
}


Double_t SigmaGluonDissS(Double_t s)
{
  Double_t q0 = (s-(mJpsi*mJpsi+mg*mg))/(2.0*mJpsi); 
  Double_t SigmaDq0 = 0.0;
  if(q0<ep0) return SigmaDq0;
  SigmaDq0 = epCon*pow(q0-ep0, 1.5)/pow(q0,5.0);  
  return SigmaDq0;
}

Double_t SigmaD(Int_t Flag, Double_t q0)
{
  Double_t SigmaDq0 = 0.0;
  if(q0<ep0) return SigmaDq0;
  if(Flag ==1 ) { SigmaDq0 = epCon*pow(q0-ep0, 1.5)/pow(q0,5.0);}  
  return SigmaDq0;

}

Double_t SigmaFS(Double_t s)
{
  Double_t q0 = (s-mJpsi*mJpsi)/(2.0*mJpsi); 
  Double_t SigmaF = 0.0;
  
  //cout<<" q0 "<<q0<<" 4.0 * MQ2 "<<4*mQ2<<endl;
  

    if(q0<ep0) return SigmaF;
  if(s<=4.0*mQ2) return SigmaF;

  Double_t kJpsi2 = pow(s-mJpsi*mJpsi, 2.0);
  Double_t kcc2 = s*(s-4.0*mQ2);
  Double_t SigmaD = epCon*pow(q0-ep0, 1.5)/pow(q0,5.0);  
  //SigmaF = SigmaD*48.0*kJpsi2/(36.0*kcc2);
  SigmaF = SigmaD*48.0*kJpsi2/(30.0*kcc2);
  //cout<<SigmaF<<" sigmaF "<<endl;
  return SigmaF;
}

Double_t SigmaThermalAct(Double_t Flag, Double_t T)
{
   Double_t DeltaEQT=EDiss(Flag,T);
   Double_t STA=pi*rJpsi2*TMath::Exp(-(DeltaEQT/T));
   return STA/hbarc2;
}

Double_t SigmaGluonDissS_Med(Double_t s, Double_t T)
{
  Double_t BE_Med=EDiss(1,T);
  Double_t epConL = 4.0*pi*pow(8./3.0, 3)*pow(BE_Med, 3)/pow(mQ, 1.5);
  Double_t q0 = (s-mJpsi*mJpsi)/(2.0*mJpsi); 
  Double_t SigmaDq0 = 0.0;
  if(q0<BE_Med) return SigmaDq0;
  SigmaDq0 = epConL*pow(q0-BE_Med, 1.5)/pow(q0,5.0);  
  return SigmaDq0;
}

Double_t EDiss(Double_t Flag, Double_t T )
{
  //  Double_t Tc = 0.200;
  //  Double_t Const = 24.0*pi2/33.0;
  //  Double_t Value = Const*(1.0/TMath::Log(19.0*1.78*T/Tc))*T*T;
  //  double Mu = TMath::Sqrt(Value);

  Double_t Mu = 1.75 * T;
  Double_t ED =0;

  Double_t MuJPsi[20]={0.18,0.22,0.26,0.29,0.34,0.39,0.43,0.48,0.52,0.55,0.58,0.60,0.63,0.64,0.66,0.67};
  Double_t EDJPsi[20]={0.6171,0.4670,0.3535,0.2726,0.1915,0.1227,0.0846,0.0542,0.0347,0.0239,0.0153,0.0104,0.0068,0.0045,0.0024,0.0014};
  
  Double_t MuUpsilon[20]={0.18,0.26,0.35,0.48,0.58,0.66,0.77,0.87,0.98,1.10,1.20,1.29,1.35,1.41,1.43,1.47};
  Double_t EDUpsilon[20]={1.0573,0.7569,0.5221,0.3282,0.2484,0.1846,0.1346,0.0964,0.0629,0.0381,0.0235,0.0137,0.0080,0.0041,0.0025,0.0012};

  Double_t x = Mu;
  Double_t y =0;
  Int_t NN = 16;
  
  Double_t xA[16]={0.0};
  Double_t yA[16]={0.0};

  for(int i=0;i<16;i++) {
    if(Flag ==1){
      xA[i]= MuJPsi[i];
      yA[i]= EDJPsi[i];
    }
    if(Flag ==2){
      xA[i]= MuUpsilon[i];
      yA[i]= EDUpsilon[i];
    }
  }
  
  if( x > xA[NN-1]){
    //y = yA[NN-1] +( (x-xA[NN-1])*(yA[NN-1]-yA[NN-2]) / (xA[NN-1] - xA[NN-2]) );
    y = 0.0;
    ED = y;
  }   
  
  if( x < xA[0]){
    y =yA[0];
    ED = y;
  }   
  
  for(int i=0; i<NN-1; i++) {
    if( x >= xA[i]  &&  x < xA[i+1] ){
      y=yA[i] + ( ( x - xA[i] ) * ( yA[i+1] - yA[i] )/ (xA[i+1] - xA[i]) );
      ED = y;
    }   
  }
  return ED;
}

Double_t fGluon(Double_t pg, Double_t T)
{
  Double_t gi=16.0;
  Double_t fg = gi / (TMath::Exp( sqrt(pg*pg + mg*mg) / T ) - 1 );
  return fg;
}



Double_t Shadowing(Double_t SigmaAbs, Double_t NPart)
{
  Double_t Rho0=0.14; //fm^-3
  //Double_t SigmaAbs=0.2; //fm^2
  Double_t L= 1.5*R0*TMath::Sqrt(NPart/416.0);
  //cout<<"L : "<<L<<endl;
  return TMath::Exp(-(Rho0*SigmaAbs*L));
}



//===============================================================================================//
//==================== JPsi pion dissociation ===================================================//
//===============================================================================================//

Double_t PionDiss_PtInt(Double_t PtMin)
{
  //for 500 bins and step = 0.1
  //PtMin=0.05;
  //PtMin=6.45;
  
  //for 100 bins and step = 0.5
  //PtMin=0.25;
  //PtMin=6.25;

  Double_t Ptmax=0;
  if(isUps==0)Ptmax=20.75;
  if(isUps==1)Ptmax=40.25;

  Double_t Ptstep=0.5;
  int NN_Pt= (int)((Ptmax-PtMin)/Ptstep);
  Double_t sum=0;
  Double_t sumPt=0;
  Double_t yield =0;
  for(int i=0;i<=NN_Pt;i++) {
    Double_t Pt=PtMin+i*Ptstep;
    if(isUps==0){yield=Jpsi_Pt->GetBinContent(Jpsi_Pt->FindBin(Pt));}
    //if(isUps==1){yield=Y1S_Pt->GetBinContent(Y1S_Pt->FindBin(Pt));}
    if(isUps==1){yield=Y2S_Pt->GetBinContent(Y2S_Pt->FindBin(Pt));}
    sum= sum + (yield*PionDiss_All(Pt));
    sumPt= sumPt + yield;  
  }
  return sum/sumPt;
}

Double_t PionDiss_All(Double_t PtMin)
{
  Double_t sumd = 0.0;
  for (int i= 0; i<=NTau; i++) {
    sumd = sumd + ( (1-fQGP[i])*PionJPsiDiss(PtMin,TempTau[i]));
  }
  return exp(-sumd*stepTau/hbarc);
}


Double_t PionJPsiDiss(Double_t P1, Double_t T)
{
  double m1Square =  mJpsi*mJpsi;
  double m2Square =  mPi*mPi;
  Double_t E1 = TMath::Sqrt( P1*P1 + m1Square);

  Double_t P2Step = 0.1;
  Double_t P2Start = 0.00001;
  Double_t P2End = 10.0;
  int P2N =(int)((P2End - P2Start)/P2Step);
  
  Double_t CosThetaStep = 0.1;
  Double_t CosThetaStart = 1.0;
  Double_t CosThetaEnd = -1.0;
  int CosThetaN =(int)((CosThetaStart - CosThetaEnd)/CosThetaStep);
  
  Double_t SumP2=0;  
  
  Double_t ThetaVal=4.0*mD*mD;
  
      
  for(int i =0; i <= P2N ; i++) {
    Double_t P2 = P2Start + i*P2Step;
    Double_t E2 = TMath::Sqrt(P2*P2 + m2Square);
    double fPion = fpion(P2,T);

    Double_t SumCosTheta=0;
    for(int k =0; k <= CosThetaN ; k++)  {
      Double_t CosTheta = CosThetaStart - k*CosThetaStep;
      Double_t fourP1DotP2 = E1*E2-P1*P2*CosTheta;
      Double_t S = m1Square + m2Square + 2*fourP1DotP2;
      if(S<= ThetaVal ) continue;
      Double_t VRel =TMath::Sqrt(fourP1DotP2*fourP1DotP2 - m1Square*m2Square)/(E1*E2);
      
     //sigma in (GeV)^{-2}
      //Double_t SGD = 0.1/hbarc2;
      
      Double_t SGD = SigmaPionDiss/hbarc2;
    
      SumCosTheta = SumCosTheta + SGD*VRel;
    }//theta
    
    double IntCosTheta = SumCosTheta*CosThetaStep;
    SumP2 = SumP2 + P2*P2*fPion*IntCosTheta;  
  }//P2

  Double_t IntP2 = (SumP2*P2Step)/(4.0*pi2);
  return IntP2;
}

Double_t RhoPi(Double_t T)
{
 
  Double_t P2Step = 0.1;
  Double_t P2Start = 0.00001;
  Double_t P2End = 10.0;
  int P2N =(int)((P2End - P2Start)/P2Step);
  Double_t SumP2=0;  
  
  for(int i =0; i <= P2N ; i++) {
    Double_t P2 = P2Start + i*P2Step;
    SumP2 = SumP2 + P2*P2*fpion(P2,T);
  }
  Double_t IntP2 = SumP2*P2Step/(2.0*pi2);
  return IntP2;
}




Double_t fpion(Double_t pPi, Double_t T)
{
  Double_t gi=3.0;
  Double_t fg = gi / (TMath::Exp( sqrt(pPi*pPi + mPi*mPi) / T ) - 1 );
  //Double_t fg = gi/TMath::Exp(sqrt(pPi*pPi + mPi*mPi)/T);
  
  return fg;
}

Double_t RateImag(Double_t T)
{
  double r0 = 0.5;
  double Lambda = 0.3;
  double Nc = 3.0;
  double CF = 0.5*(Nc*Nc-1)/Nc;
  double mDD = 2.0*pi*T/TMath::Sqrt((3.0*TMath::Log(7.547*T/Lambda)));
 
  double g2 = 8.0*pi2/(9.0*TMath::Log(9.082*T/Lambda));
  double cons  = g2*T*CF/(4.0*pi);
 
  double rstep = 0.1;
  double rmin = 0.0001;
  double rmax = 10.0001;
  int NN = (rmax-rmin)/rstep;

  double rsum = 0.0;
  for(int i=0; i<NN; i++) {
    double r = rmin + i*rstep;
    double phir = phi(r*mDD/hbarc);
    double psi = exp(-2.0*r/r0)/(r0*r0*r0*pi);
    rsum = rsum + 4*pi*r*r*phir*psi;
  }   
  double rate = cons*rsum*rstep;
  return rate; 
}

Double_t phi(Double_t r)
{
  double zstep = 0.2;
  double zmin = 0.0001;
  double zmax = 20.0001;

  int NN = (zmax-zmin)/zstep;

  double zsum = 0.0;
  for(int j=0; j<NN; j++) {
    double z = zmin + j*zstep;
    double sinFun = 0.0;
    if(z*r > 0.0) sinFun = 1.0 - sin(z*r)/(z*r);
    zsum = zsum + 2.0*sinFun*z/((z*z+1.0)*(z*z+1.0));
  }
  double zint = zsum*zstep;
  return zint; 
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

  lgd->AddEntry(grRaaPtCMS,"CMS Data p_{T}^{J/#psi}>6.5 GeV/c,|y^{J/#psi}|<2.4", "P");

}


void Draw_ALICEFor_JPsi_RaaVspT(TLegend *lgd)
{

  //================= ALICE Forward Rapidity Raa Vs Pt ===================================//
  int nbinsPtALICEFor=7;
  Double_t PtALICEFor[7]={0.50,1.50,2.50,3.50,4.50,5.50,7.0};
  Double_t ErrPtALICEFor[7]={0};
  Double_t RaaPtALICEFor[7] = {0.61,0.53,0.45,0.38,0.37,0.34,0.35}; 
  Double_t RaaPtStatErrALICEFor[7] = {0.06,0.04,0.03,0.04,0.05,0.06,0.07};
  Double_t RaaPtSystErrALICEFor[7] = {0.08,0.07,0.06,0.05,0.05,0.05,0.04};
  
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
  ALICEGlobalSysJPsiPtFor = new TBox(9.6-0.2, 1 - 0.14, 9.6+0.2, 1 + 0.14);
  ALICEGlobalSysJPsiPtFor->SetFillStyle(3001);
  ALICEGlobalSysJPsiPtFor->SetLineColor(4);
  ALICEGlobalSysJPsiPtFor->SetFillColor(4);
  ALICEGlobalSysJPsiPtFor->Draw("same"); 
    
  lgd->AddEntry(grRaaPtALICEFor,"ALICE Data p_{T}^{J/#psi} > 0.0 GeV/c, 2.5<y^{J/#psi}<4.0", "P");  

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
  Double_t NPartALICE[10]={357,262,187,128,86,53,30,16,8};
  Double_t ErrNPartALICE[10]={0};
  Double_t RaaALICE[10] = {0.47,0.48,0.51,0.51,0.52,0.61,0.70,0.74,0.94}; 
  Double_t SystErrALICE[10] = {0.03,0.02,0.02,0.02,0.03,0.05,0.06,0.09,0.1};
  
  TGraphErrors *grRaaALICE = new TGraphErrors(nbinsALICE, NPartALICE, RaaALICE, ErrNPartALICE, SystErrALICE);  
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
  RaaYCMS1Sdata->SetMarkerSize(1.1);
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
  
  lgd->AddEntry(RaaYCMS1Sdata,"CMS Data p_{T}^{#varUpsilon} > 0.0 GeV/c, |y^{#varUpsilon}| #leq 2.4", "P");
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
 
  lgd->AddEntry(RaaYCMS2Sdata,"CMS Data p_{T}^{#varUpsilon} > 0.0 GeV/c, |y^{#varUpsilon}| #leq 2.4", "P");

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
  lhALICE1S->SetLineWidth(2);
  lhALICE1S->Draw("same");
  
  lgd->AddEntry(RaaYALICE1Sdata,"ALICE Data p_{T}^{#varUpsilon} > 0.0 GeV/c, 2.5 #leq y^{#varUpsilon} #leq 4.0", "P");

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
