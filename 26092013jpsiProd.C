// c++ classes
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <iomanip>
#include <fstream>
#include <ctime>

// ROOT classes
#include "TH1F.h"
#include "TF1.h"
#include "TGraph.h"
#include "TGraphErrors.h"
#include <TMath.h>
#include <TLegend.h>
#include "TCanvas.h"
#include <TPad.h>
#include "TStyle.h"
#include "TFile.h"
#include "TRandom.h"
#include "TLine.h"
#include "TLatex.h"

// constants
Double_t pi = TMath::Pi();
Double_t pi2 = pi*pi;
Double_t pi3 = pi2*pi;
Double_t twopi3 = 8.0*pi*pi*pi;
Double_t hbarc = 0.197327;
Double_t hbarc2 = hbarc*hbarc;
Double_t hbarc3 = hbarc2*hbarc;


int isUps=0;


//Parameters JPsi
Double_t mJpsi = 3.1;
Double_t mD = 1.87;
Double_t mQ = 1.87;
Double_t mQ2 = mQ*mQ;
Double_t ep0=2.0*mQ-mJpsi;
Double_t epCon = 4.0*pi*pow(8./3.0, 3)*pow(ep0, 3)/pow(mQ, 1.5);
Double_t redMass = mQ/2.0;
const Double_t nCC0 = 10.0;
const Double_t nJpsi0 = 0.18; 
const Double_t FormTau=0.89;
const Double_t CNMSigma=0.35;
//fm2



/*
//Parameters Y(1S)
Double_t mJpsi = 9.46;
Double_t mD = 5.280;
Double_t mQ = 5.280;
Double_t mQ2 = mQ*mQ;
Double_t ep0=2.0*mQ-mJpsi;
Double_t epCon = 4.0*pi*pow(8./3.0, 3)*pow(ep0, 3)/pow(mQ, 1.5);
Double_t redMass = mQ/2.0;
const Double_t nCC0 = 0.5;
const Double_t nJpsi0 = 0.01; 
const Double_t FormTau=0.76;
const Double_t CNMSigma=0.20;
*/

/*
//Parameters Y(2S)
Double_t mJpsi = 10.02;
Double_t mD = 5.280;
Double_t mQ = 5.280;
Double_t mQ2 = mQ*mQ;
Double_t ep0=2.0*mQ-mJpsi;
//Double_t ep0=2.0*mQ-mJpsi;
Double_t epCon = 4.0*pi*pow(8./3.0, 3)*pow(ep0, 3)/pow(mQ, 1.5);
Double_t redMass = mQ/2.0;
const Double_t nCC0 = 0.5;
const Double_t nJpsi0 = 0.01; 
const Double_t FormTau=1.9;
const Double_t CNMSigma=0.20;
*/


const Double_t R0 = 7.11;
const Double_t R05 = 0.92*R0;
const Double_t tau0 = 0.1;
const Double_t SS=3.6*1.5*1600;
const Double_t Nf=2.0;
const Double_t aq = (7.0*Nf/60.0 + 16.0/90.0)*pi2;
const Double_t ah = 3.0*pi2/90.0;

Double_t aT = 0.1;   // 0
//Double_t z0=1.8*tau0; //0
//Double_t vZ=1.4;     //1.0

//for longitudnal
//Double_t aT = 0.0;   // 0
Double_t z0=0.0; //0
Double_t vZ=1.0;     //1.0

const Double_t VTau0 = (R05+0.5*aT*tau0*tau0)*(R05+0.5*aT*tau0*tau0)*(z0+vZ*tau0)*pi;
const Double_t T0=TMath::Power(SS/(4.0*aq*VTau0),1.0/3.0)*hbarc;
const Double_t TC = 0.160;
const Double_t tauf = pow(T0/TC, 3.)*tau0;
const Double_t nPart0 = 393;
const Double_t nColl0 = 1747;





// Functions

Double_t DissRateIntpT(Double_t T);
Double_t DissRateXu(Double_t pT, Double_t T);
Double_t DissFuncXu(Double_t pT, Double_t T, Double_t n);

Double_t SigmaD(Int_t Flag, Double_t q0);

Double_t DissRateR(Double_t T);
Double_t fGluon(Double_t p, Double_t T);

Double_t DissRateZhang(Double_t T);
Double_t SigmaDS(Double_t s);
Double_t SigmaFS(Double_t s);
Double_t FormRateZhang(Double_t T);

Double_t FormRateR(Double_t T);
Double_t fcharm(Double_t p, Double_t T);

Double_t FormRate(Double_t Temp);
Double_t FormFun(Double_t p1, Double_t p2, Double_t theta1, Double_t theta2, Double_t phi1, 
		 Double_t phi2, Double_t T);

//Vineet
Double_t FormFun2(Double_t p1, Double_t p2, Double_t CosTheta);
Double_t IntFormFun2(Double_t T);
Double_t IntFormFun2_P(Double_t P, Double_t T);
Double_t IntFormFun2_IntP(Double_t T);

Double_t IntDiss();
Double_t IntDiss(Double_t T0Cent, Double_t R0Cent, Double_t taufCent, Double_t PtMin);
Double_t IntDiss_PtInt(Double_t T0Cent, Double_t R0Cent, Double_t taufCent, Double_t PtMin);

Double_t IntForm();
Double_t IntForm(Double_t T0Cent, Double_t R0Cent, Double_t taufCent);

Double_t Npart(int BinLow, int BinHigh);
Double_t NColl(int BinLow, int BinHigh);

Double_t TauToTemp(Int_t Flag, Double_t Tau);
Double_t TauToTemp(Int_t Flag, Double_t T0Cent, Double_t R0Cent, Double_t Tau);

Double_t T0ToTauf(Int_t Flag, Double_t T0Cent, Double_t R0Cent);

Double_t Shadowing(Double_t SigmaAbs, Double_t NPart);


Double_t Tau0ToTauC(Int_t Flag, Double_t T0Cent, Double_t R0Cent);
Double_t TauCToTauh(Int_t Flag, Double_t TauC, Double_t R0Cent);




// Jpsi pT from Pythia
TFile *filejpsi=new TFile("JPsiPt.root","R");
TH1D *Jpsi_Pt = (TH1D*)filejpsi->Get("diMuonsPt_Gen");
TH1D *JPsiPtCut;

TFile *fileUpsilon=new TFile("dimuonGenPt1s2sPbPb_Pt.root","R");
TH1D *Y1S_Pt = (TH1D*)fileUpsilon->Get("diMuonsPt_Gen1S");
TH1D *Y2S_Pt = (TH1D*)fileUpsilon->Get("diMuonsPt_Gen2S");

TFile *fileFormRateALICE=new TFile("FormOut.root","R");
TGraph *grNJpsiStat = (TGraph*)fileFormRateALICE->Get("FormALICE");

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

  gStyle->SetOptStat(0);
  gStyle->SetTitleOffset(1.7,"y");
  gStyle->SetTitleSize(0.043, "xyz");
  gStyle->SetPadLeftMargin(0.17);
  //  gStyle->SetPadBottomMargin(0.10);
  //  gStyle->SetPadTopMargin(0.03);
  //  gStyle->SetPadRightMargin(0.04);  
  
  cout<<" T0 "<<T0<<"  aq "<<aq<<" ah "<<ah<<endl;


  TFile *OutFile =new TFile("Out.root","RECREATE");


  TLatex *tb = new TLatex();
  tb->SetNDC(); 
  tb->SetTextAlign(12);
  tb->SetTextColor(1);
  tb->SetTextSize(0.040);

  int CheckFunctions =0;
  int Disso=1;
  int Form =0;
 
  
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
  for(int i = 0;i<Jpsi_Pt->GetSize();i++)
    {	
      //Jpsi_Pt->SetBinContent(i,Jpsi_Pt->GetBinContent(i));
      cout<<i<<"   "<<Jpsi_Pt->GetBinCenter(i)<< "    "<<Jpsi_Pt->GetBinContent(i)<<endl;
    }
  
  cout << "J/psi hist Integral = " << Jpsi_Pt->Integral() << endl;
  cout<<Jpsi_Pt->GetMean()<<"   "<<Jpsi_Pt->GetRMS()<<"  "<<Jpsi_Pt->GetSize()<<"  "<<Jpsi_Pt->FindBin(6.5)<<"  "<<Jpsi_Pt->GetBinWidth(1)<<endl;
 
  





  Y1S_Pt->Rebin(5); 
  for(int i = 0;i<Y1S_Pt->GetSize();i++)
    {	
      cout<<i<<"   "<<Y1S_Pt->GetBinCenter(i)<< "    "<<Y1S_Pt->GetBinContent(i)<<endl;
    }
  
  cout << "Y1S hist Integral = " << Y1S_Pt->Integral() << endl;
  cout<<Y1S_Pt->GetMean()<<"   "<<Y1S_Pt->GetRMS()<<"  "<<Y1S_Pt->GetSize()<<"  "<<Y1S_Pt->FindBin(6.5)<<"  "<<Y1S_Pt->GetBinWidth(1)<<endl;






  Y2S_Pt->Rebin(5); 
  for(int i = 0;i<Y2S_Pt->GetSize();i++)
    {	
      //cout<<i<<"   "<<Y2S_Pt->GetBinCenter(i)<< "    "<<Y2S_Pt->GetBinContent(i)<<endl;
    }
  
  cout << "Y2S hist Integral = " << Y2S_Pt->Integral() << endl;
  cout<<Y2S_Pt->GetMean()<<"   "<<Y2S_Pt->GetRMS()<<"  "<<Y2S_Pt->GetSize()<<"  "<<Y2S_Pt->FindBin(6.5)<<"  "<<Y2S_Pt->GetBinWidth(1)<<endl;

  // return;

  //============== JPsi gluon dissociation cross section graph =======================//
    Double_t smin=0.0;
    Double_t smax = 60.0;
    Double_t step = 0.2;
    int NS = (int)((smax-smin)/step); 
    Double_t ss[2000], sig[2000];
    for(int i=0; i<NS; i++) {
      ss[i] = smin + step*i;
      sig[i] = SigmaFS(ss[i])*hbarc2;
    }
    
    TGraph *grSigD = new TGraph(NS, ss, sig);
    grSigD->SetLineWidth(2);
    grSigD->GetXaxis()->SetTitle("s (GeV^{2})");
    grSigD->GetYaxis()->SetTitle("#sigma (fm^{2}) ");
    new TCanvas;
    gPad->SetTicks();
    grSigD->Draw("APL");
    

    Double_t q0min=0.0;
    Double_t q0max = 3.0;
    Double_t q0step = 0.01;
    int NQ0 = (int)((q0max-q0min)/q0step); 
    Double_t Q0[2000], SigDQ0[2000], SigDQ0Mod[2000];
    
    for(int i=0; i<NQ0; i++) {
      Q0[i] = q0min + q0step*i;
      SigDQ0[i] = SigmaD(1,Q0[i])*hbarc2*10.0;
      SigDQ0Mod[i] = SigmaD(2,Q0[i])*hbarc2*10.0;
      //cout<< Q0[i] <<"  "<<SigDQ0Mod[i]<<endl;
    }
    
    TGraph *grSigDQ0 = new TGraph(NQ0, Q0, SigDQ0);
    grSigDQ0->SetLineWidth(2);
    grSigDQ0->GetXaxis()->SetTitle("q^{0} (GeV)");
    grSigDQ0->GetYaxis()->SetTitle("#sigma (mb)");
    
    TGraph *grSigDQ0Mod = new TGraph(NQ0, Q0, SigDQ0Mod);
    grSigDQ0Mod->SetLineWidth(2);
    grSigDQ0Mod->SetLineColor(2);
    
    lcat[2] = new TLegend( 0.45,0.67,0.95,0.77);
    lcat[2]->SetBorderSize(0);
    lcat[2]->SetFillStyle(0);
    lcat[2]->SetFillColor(0);
    lcat[2]->SetTextSize(0.040);
    lcat[2]->AddEntry(grSigDQ0,"Dipole Approx","L");
    lcat[2]->AddEntry(grSigDQ0Mod,"Beyond Dipole","L");
    
    new TCanvas;
    gPad->SetTicks();
    grSigDQ0->Draw("APL");
    grSigDQ0Mod->Draw("Lsame");
    tb->DrawLatex(0.46,0.82,"g+J/#psi #rightarrow c+#bar{c}");
    lcat[2]->Draw("same");
    gPad->SaveAs("SigmaDQ0.eps");
    gPad->SaveAs("SigmaDQ0.pdf");
  

  

 // Npart vs Ncoll graphs =========================================
  
    Double_t NPartVal[50];
    Double_t NCollVal[50];

    Double_t dNdEtaNPartBy2Val[50];
    
    Double_t NuclShadowing[50];
  
    for(int i=0;i<40;i++)
      {
	NuclShadowing[i]=Shadowing(0.2,Npart(i,i+1));
	NPartVal[i]=Npart(i,i+1);
	NCollVal[i]=NColl(i,i+1);
	dNdEtaNPartBy2Val[i]= ( 2.441*(0.788*NPartVal[i] + (1-0.788)*NCollVal[i]) )/(0.5*NPartVal[i]) ;
      }
  
    TGraph *grNPartVsNColl = new TGraph(40, NPartVal,NCollVal);
    grNPartVsNColl->SetLineWidth(2);
    grNPartVsNColl->SetMarkerStyle(20);
    grNPartVsNColl->GetXaxis()->SetTitle("N_{Part}");
    grNPartVsNColl->GetYaxis()->SetTitle("N_{Coll}");
    
    TF1 *fa2 = new TF1("fa2","pol2",0.1,500.0);
    grNPartVsNColl->Fit("fa2","M","",0.0,400.0);
  
    new TCanvas;
    gPad->SetTicks();
    grNPartVsNColl->Draw("AP");
  
    gPad->SaveAs("NCollVsNpart.png");  
    gPad->SaveAs("NCollVsNpart.eps");  
 
 
 
    TGraph *grTwoCompModel = new TGraph(40, NPartVal, dNdEtaNPartBy2Val);
    grTwoCompModel->SetLineWidth(2);
    grTwoCompModel->SetMarkerStyle(21);
    grTwoCompModel->GetXaxis()->SetTitle("N_{Part}");
    grTwoCompModel->GetYaxis()->SetTitle("#frac{dN}{d#eta}/(#frac{N_{Part}}{2})");
    

    new TCanvas;
    gPad->SetTicks();
    // grdNDetaNpart->Draw("AP");
    grTwoCompModel->Draw("Psame");
    



    TGraph *grNPartVsNuclAbs = new TGraph(40, NPartVal,NuclShadowing);
    grNPartVsNuclAbs->SetLineWidth(2);
    grNPartVsNuclAbs->SetMarkerStyle(20);
    grNPartVsNuclAbs->GetXaxis()->SetTitle("N_{Part}");
    grNPartVsNuclAbs->GetYaxis()->SetTitle("S_{Nucl Abs}");
    grNPartVsNuclAbs->GetYaxis()->SetRangeUser(0.0,1.0);

    new TCanvas;
    grNPartVsNuclAbs->Draw("AL");
    
    
    Double_t NCollAna[400];
    Double_t NPartAna[400];
    
  for(int i=0;i<400;i++)
    {
      
      NPartAna[i]=i;
      //NCollAna[i]=TMath::Power(NPartAna[i],4.0/3.0);      
      NCollAna[i]=fa2->Eval(NPartAna[i]);
    }
  
  TGraph *grNPartVsNCollAna = new TGraph(400,NPartAna,NCollAna);
  grNPartVsNCollAna->SetLineColor(2);
  grNPartVsNCollAna->SetMarkerColor(2);
  grNPartVsNCollAna->SetMarkerStyle(20);
  grNPartVsNCollAna->GetXaxis()->SetTitle("N_{part}");
  grNPartVsNCollAna->GetYaxis()->SetTitle("N_{Coll}");
  new TCanvas;  
  grNPartVsNCollAna->Draw("AP");
  grNPartVsNColl->Draw("Psame");












    // dn/deta graph for makin Temp as a function of nPart ==========================================
    
    //Double_t NPartdNdEta[10] = {Npart(0,2),Npart(2,4),Npart(4,8),Npart(8,12),Npart(12,16),Npart(16,20),
    //				Npart(20,24),Npart(24,28),Npart(28,32),Npart(32,40)}; 
    //Double_t dNdEtabyNpartby2[10] = {8.4,7.9,7.4,7.0,6.6,6.1,5.7,5.1,4.4,3.7};



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
    
    new TCanvas;
    gPad->SetTicks();
    gPad->SetBottomMargin(0.14);
    grdNDetaNpart->Draw("AP");
    gPad->SaveAs("dNdEtaVsNpart.png");  
  gPad->SaveAs("dNdEtaVsNpart.eps");     
   
  
  TF1 *funDnDetaNPart = new TF1("funDnDetaNPart","[0]*TMath::Power(x,[1])/(0.5*x)",0.0,500);
  funDnDetaNPart->SetParameters(1.317,1.190);
  funDnDetaNPart->SetLineColor(4);

  TF1 *funPol3 = new TF1("funPol3","pol3",10.0,400);
  funPol3->SetLineColor(1);



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
  lcat[3]->AddEntry(funPol3,"pol3","L");
  lcat[3]->AddEntry(funTwoComp,"fN_{Part} + (1-f)N_{Coll}","L");
    


  new TCanvas;
  grdNDetaNpart->Fit("funDnDetaNPart","M","",10.0,400.0);
  grdNDetaNpart->Fit("funPol3","M","",10.0,400.0);
  grdNDetaNpart->Fit("funTwoComp","M","",10.0,400.0);

  grdNDetaNpart->Draw("AP");
  funPol3->Draw("same");
  funDnDetaNPart->Draw("same");
  funTwoComp->Draw("same");
  lcat[3]->Draw("same");
  
  Double_t TempNpart[400];
  Double_t TempNpart2[400];
  Double_t TempNpart3[400];
 
  Double_t NpartVal[400];
  
  //return;

  for(int i=0;i<=80;i++)
    {
      NpartVal[i]=i*5;
      TempNpart[i]=T0*TMath::Power(funDnDetaNPart->Eval(NpartVal[i])/dNdEtabyNpartby2[0],1.0/3); //ALICE Func
      TempNpart2[i]=T0*TMath::Power(funPol3->Eval(NpartVal[i])/dNdEtabyNpartby2[0],1.0/3); //Pol3
      TempNpart3[i]=T0*TMath::Power(funTwoComp->Eval(NpartVal[i])/dNdEtabyNpartby2[0],1.0/3); //Two Comp model
      //cout<< NpartVal[i]<<"   "<<TempNpart[i]<<endl;
    }

  TGraph *grTempVsNpart = new TGraph(80, NpartVal,TempNpart);
  grTempVsNpart->SetLineWidth(2);
  grTempVsNpart->SetMarkerStyle(20);
  grTempVsNpart->SetMarkerColor(4);
  
  grTempVsNpart->GetXaxis()->SetTitle("N_{Part}");
  grTempVsNpart->GetYaxis()->SetTitle("T (GeV)");
  grTempVsNpart->GetYaxis()->SetRangeUser(0.44,0.70);
  
  TGraph *grTempVsNpart2 = new TGraph(80, NpartVal,TempNpart2);
  grTempVsNpart2->SetLineWidth(2);
  grTempVsNpart2->SetMarkerStyle(20);


  TGraph *grTempVsNpart3 = new TGraph(80, NpartVal,TempNpart3);
  grTempVsNpart3->SetLineWidth(2);
  grTempVsNpart3->SetMarkerStyle(20);
  grTempVsNpart3->SetMarkerColor(2);




  new TCanvas;
  gPad->SetTicks();
  grTempVsNpart->Draw("AP");
  grTempVsNpart2->Draw("Psame");
  grTempVsNpart3->Draw("Psame");
  lcat[3]->Draw("same");
  gPad->SaveAs("NpartVsTemp.png");  
  gPad->SaveAs("NpartVsTemp.eps");  
  
  
  //================================= Temp Vs Tau Graphs ======================================//
  
  Double_t TauA[1000];
  Double_t TempA[1000];
  Double_t TempB[1000];
  
  Double_t TauAMax= 10;
  Double_t TauAMin=tau0;
  Double_t TauStep=0.1;
  int TauN = (TauAMax-TauAMin)/TauStep;
  cout<<"TauN: "<<TauN<<endl;  

  cout<<"T0: "<<T0<<" R05 "<<R05<<endl;

  for(int i=0;i<TauN;i++)
    {
      TauA[i]=TauAMin+0.1*i;
    
      //TempA[i]=TauToTemp(1,T0*TMath::Power((funDnDetaNPart->Eval(Npart(0,2)))/dNdEtabyNpartby2[0],1.0/3.0),R05,TauA[i]);      
      //TempB[i]=TauToTemp(2,T0*TMath::Power((funDnDetaNPart->Eval(Npart(0,2)))/dNdEtabyNpartby2[0],1.0/3.0),R05,TauA[i]);      
      
      TempA[i]=TauToTemp(1,T0*TMath::Power((funTwoComp->Eval(Npart(0,2)))/dNdEtabyNpartby2[0],1.0/3.0),R05,TauA[i]);      
      TempB[i]=TauToTemp(2,T0*TMath::Power((funTwoComp->Eval(Npart(0,2)))/dNdEtabyNpartby2[0],1.0/3.0),R05,TauA[i]);      
    
    }

  
  TGraph *grTempVsTauAna = new TGraph(TauN,TauA,TempA);
  grTempVsTauAna->SetLineColor(2);
  grTempVsTauAna->GetYaxis()->SetTitle("Temperature (GeV)");
  grTempVsTauAna->GetXaxis()->SetTitle("#tau (fm)");
  
  TGraph *grTempVsTauAnaB = new TGraph(TauN,TauA,TempB);
  grTempVsTauAnaB->SetLineColor(4);


  TLegend *legd5 = new TLegend( 0.31,0.71,0.95,0.85);
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
  grTempVsTauAna->Draw("AL");
  grTempVsTauAnaB->Draw("Lsame");
  l1->Draw("Lsame");
  legd5->Draw("Lsame");
  gPad->SaveAs("TauVsTemp.eps");
  gPad->SaveAs("TauVsTemp.png");

  
  new TCanvas;  
  gPad->SetTicks(1);
  grTempVsTauAna->SetMarkerStyle(20);
  grTempVsTauAna->Draw("AP");
  
  cout<<tauf<<endl;
  
  
  cout<<" ======================= Temp vs Tau for Centrality ================="<<endl;
  
  Double_t TempA1[20][1000];
  Double_t NPartTempVsTau[20]={Npart(0,2),Npart(2,4),Npart(4,6),Npart(6,8),Npart(8,10),Npart(10,12),
			       Npart(12,14),Npart(14,16),Npart(16,18),Npart(18,20),Npart(20,24),
			       Npart(24,40)};
  
  Double_t T0TempVsTau[20]={0};
  Double_t TaufA[20];  
  Double_t TauhA[20];  


  cout<<" NPart "<<"   "<<" T0 "<<" R0Cent  "<<"  Tauf "<< " Tauh "<<endl;

  for(int i=0;i<12;i++)
    {
      //T0TempVsTau[i]=T0*TMath::Power((funDnDetaNPart->Eval(NPartTempVsTau[i]))/dNdEtabyNpartby2[0],1.0/3.0);
      //T0TempVsTau[i]=T0*TMath::Power((funPol3->Eval(NPartTempVsTau[i]))/dNdEtabyNpartby2[0],1.0/3.0);
      T0TempVsTau[i]=T0*TMath::Power((funTwoComp->Eval(NPartTempVsTau[i]))/dNdEtabyNpartby2[0],1.0/3.0);

      Double_t R0Cent1 = R05*TMath::Power(NPartTempVsTau[i]/Npart(0,2),0.5);
      
      TaufA[i]=T0ToTauf(2,T0TempVsTau[i],R0Cent1);

      //TaufA[i]=Tau0ToTauC(2,T0TempVsTau[i],R0Cent1);
      

      TauhA[i]=TauCToTauh(2, TaufA[i], R0Cent1);
      
      cout<< NPartTempVsTau[i] <<"  "<< T0TempVsTau[i] <<"  "<<R0Cent1<<"   "<<TaufA[i] <<"  "<<TauhA[i]<<"  "<<(aq*TaufA[i])/ah<<endl;
    

    }
 
  for(int i=0;i<12;i++){
    
    cout<<" ---> "<<T0TempVsTau[i]<<endl;

    for(int j=0;j<TauN;j++){
      // cout<<TauA[j]<<" tauAj "<<endl;
      Double_t R0Cent = R05*TMath::Power(NPartTempVsTau[i]/Npart(0,2),0.5);
      TempA1[i][j]=TauToTemp(2,T0TempVsTau[i],R0Cent,TauA[j]); 
      //cout<<TempA1[i][j]<<endl;
    }
  }
  
  TGraph *grTempVsTauAnaCent[20]; 
  for(int i=0;i<12;i++){
    grTempVsTauAnaCent[i]  = new TGraph(TauN,TauA,TempA1[i]);
  }
  grTempVsTauAnaCent[0]->GetYaxis()->SetTitle("Temperature (GeV)");
  grTempVsTauAnaCent[0]->GetXaxis()->SetTitle("#tau (fm)");
  grTempVsTauAnaCent[0]->SetLineWidth(2);
  grTempVsTauAnaCent[0]->SetLineColor(4);
  
  new TCanvas;
  gPad->SetTicks(1);
  //grTempVsTauAnaCent[0]->GetYaxis()->SetRangeUser(0.0,0.62);
  grTempVsTauAnaCent[0]->Draw("AL");

  for(int i=1;i<12;i++)
    {
      grTempVsTauAnaCent[i]->SetLineWidth(2); 
      grTempVsTauAnaCent[i]->SetLineColor(i); 
      grTempVsTauAnaCent[10]->SetLineColor(13);
      grTempVsTauAnaCent[4]->SetLineColor(14);
      grTempVsTauAnaCent[i]->Draw("Lsame");
    }

  l1->Draw("same");
  tb->DrawLatex(0.40,0.85,"Cylinderical expansion");
  // ================= Npart Vs tauf graph ===================//
  TGraph *grTaufNPart=new TGraph(12,NPartTempVsTau,TaufA);
  
  new TCanvas;
  gPad->SetTicks(1);
  grTaufNPart->GetXaxis()->SetTitle("N_{part}");
  grTaufNPart->GetYaxis()->SetTitle("#tau_{f}");
  grTaufNPart->SetMarkerStyle(20);
  grTaufNPart->SetMarkerColor(1);
  grTaufNPart->SetLineWidth(2);
  grTaufNPart->Draw("AP");
  TF1 *fa3 = new TF1("fa3","pol3",0.0,400.0);
  grTaufNPart->Fit("fa3","M","",0.0,400.0);
  fa3->Draw("same");
  tb->DrawLatex(0.20,0.80,"Cylinderical Expansion");
  
    

  // ========================================= Shadowing ALICE JPsi =========================//
   
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
  
  for(int i=0;i<=10;i++)
    {
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
  
  new TCanvas;
  grRapVsNuclAbs->Draw("AP");

  new TCanvas;
  gPad->SetTicks();
  grRpPbALICE->Draw("AP");
  grRapVsNuclAbs->Draw("Lsame");


  TF1 *FuncCNM =new TF1("FuncCNM","TMath::Exp(-([0]*[1]*x))",-5.0,5.0);
  FuncCNM->FixParameter(0,0.14);
 
  new TCanvas;
  gPad->SetTicks();
  grRpPbALICE->Draw("AP");
  grRpPbALICE->Fit("FuncCNM","M","",-4.5,5.0);



  return;
  
  //=========================================================================//
  //========================================================================//
  if( CheckFunctions ==1){
    // Dissociation rates as a function of temp.
    Double_t Temp[1000];  
    Double_t LambdaD_Khar[1000]={0},  LambdaD_KharAll[1000]={0};
    Double_t LambdaD_Khar36[1000]={0},  LambdaD_Khar86[1000]={0};
    
    Double_t LambdaR[1000]={0},  LambdaZ[1000]={0};
    Double_t LambdaFZ[1000]={0}, LambdaFR[1000]={0},LambdaFR0[1000]={0};
    Double_t LambdaF_TripleInt[1000]={0};
    Double_t LambdaF[1000]={0};
    
    Double_t TempMin=0.031;
    Double_t TempMax=1.0;
    Double_t TempStep=0.05;
    int NTemp= (int)((TempMax-TempMin)/TempStep);
    
    // ================ Dissociation and Formation Rates ==================================//
    cout<<" ==================== Formation Rate ===================== " <<endl;
    cout<<"Temp: "<<" MC Int  "<< " Triple Int " << "    " << " TripleInt (p2 = p-p1)" <<endl;
    
    for(int l = 0; l<=NTemp; l++) {
      
      Temp[l]=TempMin+TempStep*l;
      
      //Dissociation Rates
      if(Disso ==1){
	
	Double_t Rhog = 8*pi*1.202*pow(Temp[l], 3.0);
	LambdaD_Khar[l]= Rhog*DissRateXu(0.0, Temp[l]); // Xu and Kharjeev as a function of pT
	LambdaD_Khar36[l]= Rhog*DissRateXu(3.6, Temp[l]); // Xu and Kharjeev as a function of pT
	LambdaD_Khar86[l]= Rhog*DissRateXu(8.6, Temp[l]); // Xu and Kharjeev as a function of pT
	LambdaD_KharAll[l]= Rhog*DissRateIntpT(Temp[l]); // Xu and Kharjeev int pT
	
	LambdaR[l] = DissRateR(Temp[l]); //at pT=0
	LambdaZ[l] = DissRateZhang(Temp[l]);
	LambdaFZ[l] = FormRateZhang(Temp[l]);
      }
      

      //Formation Rates
      if(Form ==1){
	LambdaFR0[l] = FormRateR(Temp[l]); //MC pT =0
	LambdaFR[l] = FormRate(Temp[l]); //MC
	LambdaF[l] = IntFormFun2(Temp[l]);  //Triple int
	LambdaF_TripleInt[l] = IntFormFun2_IntP(Temp[l]); //triple int after p2 = p-p1
      }
      cout<<Temp[l]<<"   "<< LambdaFR[l]<<"     "<<LambdaF[l] << "    " << LambdaF_TripleInt[l] <<endl;
    }
    
    Double_t DissRateKharVsPt1[10000]={0};
    Double_t DissRateKharVsPt2[10000]={0};
    Double_t DissRateKharVsPt3[10000]={0};


    Double_t LambdaF_P1[10000]={0};
    Double_t LambdaF_P2[10000]={0};
    Double_t LambdaF_P3[10000]={0};
    
    Double_t P[10000];
    Double_t PMax=0.0;
    Double_t PMin=0.1;
    Double_t PStep=0.1;
    
    if(Disso==1){PMax=20.0;}
    if(Form==1){PMax=2.0;PStep = 0.01;}
    
    int NP=int((PMax-PMin)/PStep);

    cout<<NP<<" NP"<<endl;
    cout<<"Pt[l]"<<"  "<<" DissRate"<<"  "<<" LambdaF_P[l] "<<endl;
   
    for(int l = 0; l<=NP; l++) 
      {
	P[l]=PMin+PStep*l;
	if(Disso ==1){
	  
	  Double_t Rhog2 = 8*pi*1.202*pow(0.200, 3.0);
	  Double_t Rhog4 = 8*pi*1.202*pow(0.400, 3.0);
	  Double_t Rhog6 = 8*pi*1.202*pow(0.600, 3.0);

	  DissRateKharVsPt1[l]= Rhog2*DissRateXu(P[l],0.200);
	  DissRateKharVsPt2[l]=Rhog4*DissRateXu(P[l],0.400);
	  DissRateKharVsPt3[l]= Rhog6*DissRateXu(P[l],0.600);
	}
	if(Form ==1){
	  LambdaF_P1[l]=IntFormFun2_P(P[l],0.200);
	  LambdaF_P2[l]=IntFormFun2_P(P[l],0.400);
	  LambdaF_P3[l]=IntFormFun2_P(P[l],0.600);
	}
	
	cout<<P[l]<<"  "<< DissRateKharVsPt1[l]<<"   "<<DissRateKharVsPt2[l]<<"   "<<DissRateKharVsPt3[l]<<endl;

      }
       
    TGraph *grFormRate_TripleInt_P1 = new TGraph(NP,P,LambdaF_P1);
    grFormRate_TripleInt_P1->SetMarkerStyle(20);
    grFormRate_TripleInt_P1->SetLineWidth(2);
    grFormRate_TripleInt_P1->SetLineColor(2);
    grFormRate_TripleInt_P1->GetXaxis()->SetTitle("P(GeV)");
    grFormRate_TripleInt_P1->GetYaxis()->SetTitle("FormRate(Triple Int)");
    
    TGraph *grFormRate_TripleInt_P2 = new TGraph(NP,P,LambdaF_P2);
    grFormRate_TripleInt_P2->SetLineWidth(2);
    grFormRate_TripleInt_P2->SetLineColor(1);
    
    TGraph *grFormRate_TripleInt_P3 = new TGraph(NP,P,LambdaF_P3);
    grFormRate_TripleInt_P3->SetLineWidth(2);
    grFormRate_TripleInt_P3->SetLineColor(4);
    
    
    
    lcat[0]->AddEntry(grFormRate_TripleInt_P1, "T=0.2", "L");
    lcat[0]->AddEntry(grFormRate_TripleInt_P2, "T=0.4", "L");
    lcat[0]->AddEntry(grFormRate_TripleInt_P3, "T=0.6", "L");
    
    new TCanvas;
    gPad->SetTicks();
    grFormRate_TripleInt_P1->GetXaxis()->SetTitle("P (GeV/c)");
    grFormRate_TripleInt_P1->GetYaxis()->SetTitle("Formation Rate (fm^{2})");
    grFormRate_TripleInt_P1->GetYaxis()->SetRangeUser(0.0,0.022);
    grFormRate_TripleInt_P1->Draw("AL");
    grFormRate_TripleInt_P2->Draw("L");
    grFormRate_TripleInt_P3->Draw("L");
    lcat[0]->Draw("same");
    tb->DrawLatex(0.55,0.83,"Triple Integral");
    gPad->SaveAs("FormRate_TriInt.png");
    gPad->SaveAs("FormRate_TriInt.eps");

    //return;


    //====================== Dissociation rates =====================//
    TGraph *DissRate_Khar = new TGraph(NTemp,Temp,LambdaD_Khar);
    DissRate_Khar->SetLineWidth(2);
    DissRate_Khar->SetLineColor(1);
    DissRate_Khar->SetLineStyle(1);
    DissRate_Khar->GetXaxis()->SetTitle("Temperature (GeV)");
    DissRate_Khar->GetYaxis()->SetTitle("Dissociation Rate #lambda_{D} (fm^{2})");
    
    TGraph *DissRate_KharAll = new TGraph(NTemp,Temp,LambdaD_KharAll);
    DissRate_KharAll->SetLineWidth(2);
    DissRate_KharAll->SetLineColor(2);
    DissRate_KharAll->SetLineStyle(1);
    
    TGraph *grDissRateR = new TGraph(NTemp,Temp,LambdaR);
    grDissRateR->SetLineWidth(2);
    grDissRateR->SetLineColor(6);
    
    TGraph *DissRate_Khar36 = new TGraph(NTemp,Temp,LambdaD_Khar36);
    DissRate_Khar36->SetLineWidth(2);
    DissRate_Khar36->SetLineColor(4);
    DissRate_Khar36->SetLineStyle(4);
    
    TGraph *DissRate_Khar86 = new TGraph(NTemp,Temp,LambdaD_Khar86);
    DissRate_Khar86->SetLineWidth(2);
    DissRate_Khar86->SetLineColor(6);
    DissRate_Khar86->SetLineStyle(6);


    // Diss rates
    TLegend *legd1 = new TLegend( 0.31,0.67,0.76,0.86);
    legd1->SetBorderSize(0);
    legd1->SetFillStyle(0);
    legd1->SetFillColor(0);
    legd1->SetTextSize(0.040);

    legd1->AddEntry(DissRate_Khar, "p_{T}= 0", "L");
    legd1->AddEntry(DissRate_Khar36, "p_{T}= 3.6 GeV/c", "L");
    legd1->AddEntry(DissRate_Khar86, "p_{T}= 8.6 GeV/c", "L");
    legd1->AddEntry(DissRate_KharAll, "p_{T} integrated", "L");
           
    new TCanvas;
    gPad->SetTicks();
    //DissRate_Khar->GetYaxis()->SetRangeUser(0.0,0.14);
    DissRate_Khar->Draw("APL");
    DissRate_Khar36->Draw("PLsame");
    DissRate_Khar86->Draw("PLsame");
    DissRate_KharAll->Draw("samePL");
    //grDissRateR->Draw("sameL");
    legd1->Draw("same");
    gPad->SaveAs("DRateVsT.png");    
    gPad->SaveAs("DRateVsT.eps");    

    new TCanvas;
    gPad->SetTicks();
    DissRate_Khar->Draw("AL");
    grDissRateR->Draw("sameL");

    //DRate vs Pt graph
    TGraph *grDissRateVsPt1 = new TGraph(NP,P,DissRateKharVsPt1);
    grDissRateVsPt1->SetMarkerStyle(20);
    grDissRateVsPt1->SetLineWidth(2);
    grDissRateVsPt1->SetLineColor(2);
    grDissRateVsPt1->GetXaxis()->SetTitle("p_{T}(GeV/c)");
    grDissRateVsPt1->GetYaxis()->SetTitle("Dissociation Rate #lambda_{D} (fm^{2})");
    
    TGraph *grDissRateVsPt2 = new TGraph(NP,P,DissRateKharVsPt2);
    grDissRateVsPt2->SetLineWidth(2);
    grDissRateVsPt2->SetLineColor(1);
    
    TGraph *grDissRateVsPt3 = new TGraph(NP,P,DissRateKharVsPt3);
    grDissRateVsPt3->SetLineWidth(2);
    grDissRateVsPt3->SetLineColor(4);
    
    lcat[1] = new TLegend( 0.31,0.67,0.76,0.86);
    lcat[1]->SetBorderSize(0);
    lcat[1]->SetFillStyle(0);
    lcat[1]->SetFillColor(0);
    lcat[1]->SetTextSize(0.040);
    lcat[1]->AddEntry(grDissRateVsPt1, "T=0.2 GeV", "L");
    lcat[1]->AddEntry(grDissRateVsPt2, "T=0.4 GeV", "L");
    lcat[1]->AddEntry(grDissRateVsPt3, "T=0.6 GeV", "L");
    
    new TCanvas;
    gPad->SetTicks();
    grDissRateVsPt1->GetYaxis()->SetRangeUser(0.0,0.6);
    grDissRateVsPt1->Draw("AL");
    grDissRateVsPt2->Draw("Lsame");
    grDissRateVsPt3->Draw("Lsame");
    lcat[1]->Draw("same");
    gPad->SaveAs("DRateVsPt.png");    
    gPad->SaveAs("DRateVsPt.eps");
    
    //return;
    TGraph *grDissRateZ = new TGraph(NTemp,Temp,LambdaZ);
    grDissRateZ->SetLineWidth(2);
    grDissRateZ->SetLineColor(4);
    grDissRateZ->GetXaxis()->SetTitle("Temperature (GeV)");
    grDissRateZ->GetYaxis()->SetTitle("Diss. Rate (fm^{2}) ");
    
    TLegend *legd2 = new TLegend( 0.50,0.70,0.90,0.89);
    legd2->SetBorderSize(0);
    legd2->SetFillStyle(0);
    legd2->SetFillColor(0);
    legd2->SetTextSize(0.040);
    legd2->AddEntry(DissRate_KharAll, "Diss Kharjeev all p_{T}", "L");
    legd2->AddEntry(grDissRateZ, "Diss Zhang", "L");
    
    new TCanvas;
    gPad->SetTicks();
    DissRate_KharAll->Draw("ALP");
    grDissRateZ->Draw("sameL");
    legd2->Draw("same");
  
    // Formation Rates
    TGraph *grFormRateZ = new TGraph(NTemp,Temp,LambdaFZ);
    grFormRateZ->SetLineWidth(2);
    grFormRateZ->SetLineColor(2);
    grFormRateZ->GetXaxis()->SetTitle("Temperature (GeV)");
    grFormRateZ->GetYaxis()->SetTitle("Form Rate (fm^{2}) ");
       
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
    legd3->AddEntry(grFormRateZ, "Form Zhang", "L");
    legd3->AddEntry(grFormRateR, "Form (MC) Full Integral", "L");
    legd3->AddEntry(grFormRate_TripleInt, "Form Triple Integral p2=P-p1", "L");
    

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
    grFormRateZ->GetYaxis()->SetRangeUser(0.0,0.3);
    grFormRateZ->Draw("ALP");
    grFormRateR->Draw("sameL");
    grFormRate_TripleInt->Draw("samePL");
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
    gPad->SaveAs("FormRateVsT.png");
    gPad->SaveAs("FormRateVsT.eps");


  }

  if( CheckFunctions ==0 || CheckFunctions ==1){
    
    // Solve Kinetic equation 
    cout << endl <<" J/psi RAA " << endl;
    Double_t nPartMin = 0.0;
    Double_t nPartMax = 500;
    Double_t nstep = 50;
    int NN = (int)((nPartMax-nPartMin)/nstep);

    Double_t nPart[100]={Npart(0,2),Npart(2,4),Npart(4,6),Npart(6,8),Npart(8,10),Npart(10,12),
				 Npart(12,14),Npart(14,16),Npart(16,18),Npart(18,20),Npart(20,24),
				 Npart(24,40)};


    Double_t nCollA[100]={NColl(0,2),NColl(2,4),NColl(4,6),NColl(6,8),NColl(8,10),NColl(10,12),
			 NColl(12,14),NColl(14,16),NColl(16,18),NColl(18,20),NColl(20,24),NColl(24,40)};
    
    Double_t jpsiFormCMS[100], jpsiDissCMS[100], nJpsiFCMS[100], RAACMS[100];
    Double_t jpsiFormALICE[100], jpsiDissALICE[100], nJpsiFALICE[100], RAAALICE[100];
     
    cout <<"nPart "  <<"  Temp "<<"  Tauf  " <<" R0Cent "<<" RAACMS  "<<"  RAAALICE "<<endl;
    

    Double_t CNMEffects[20];


    ///////////// STAT MODEL //////////////////
    Double_t NJpsiStatALICE[100];
    double x1, y1;
    cout<<" trying to acsess "<<endl;
    cout<<grNJpsiStat->GetN()<<" getN "<<endl;
    for (int i=0; i<grNJpsiStat->GetN();++i){
      grNJpsiStat->GetPoint(i,x1,y1);
      NJpsiStatALICE[i]=y1;    
    }


    NN=12;  
   
    for(int i=0; i<NN; i++) {

      Double_t nColl = fa2->Eval(nPart[i]);  
      Double_t nJpsi = nJpsi0*nColl/nColl0;
      Double_t nCC = nCC0*nColl/nColl0;
      //Double_t T0Cent =T0*TMath::Power((funDnDetaNPart->Eval(NPartTempVsTau[i]))/dNdEtabyNpartby2[0],1.0/3.0);
      //Double_t T0Cent =T0*TMath::Power((funPol3->Eval(NPartTempVsTau[i]))/dNdEtabyNpartby2[0],1.0/3.0);
      Double_t T0Cent =T0*TMath::Power((funTwoComp->Eval(NPartTempVsTau[i]))/dNdEtabyNpartby2[0],1.0/3.0);
      Double_t taufCent=fa3->Eval(nPart[i]); 
      Double_t R0Cent = R05*TMath::Power(nPart[i]/Npart(0,2),0.5);          
      
      //JPsi fixed pT
      //Double_t intdissCMS = IntDiss(T0Cent,R0Cent,taufCent,8.0);
      //Upsilon fixed pT
      //Double_t intdissCMS = IntDiss(T0Cent,R0Cent,taufCent,5.0);
      
      //Jpsi Pt integrated 
      Double_t intdissCMS = IntDiss_PtInt(T0Cent,R0Cent,taufCent,6.25);
    
      //Upsilon Pt integrated 
      //Double_t intdissCMS = IntDiss_PtInt(T0Cent,R0Cent,taufCent,0.25);
      Double_t intformCMS=0.0;
      jpsiDissCMS[i] = intdissCMS;
      jpsiFormCMS[i] = intdissCMS * intformCMS * nCC*nCC/(nJpsi);
      nJpsiFCMS[i] = ( jpsiDissCMS[i] + jpsiFormCMS[i] );
      CNMEffects[i] =Shadowing(CNMSigma,nPart[i]);
      RAACMS[i] = nJpsiFCMS[i]*CNMEffects[i];
      
      
      //Double_t intdissALICE = IntDiss(T0Cent,R0Cent,taufCent,3.6);
      //Read file for formation rate
      

      Double_t intdissALICE=0; 
      Double_t intformALICE=0;
      if(isUps==0){
	intdissALICE = IntDiss_PtInt(T0Cent,R0Cent,taufCent,0.25);
	intformALICE =NJpsiStatALICE[i];
      }
      
      //Double_t intformALICE=IntForm(T0Cent,R0Cent,taufCent);
      jpsiDissALICE[i] = intdissALICE;
      jpsiFormALICE[i] = intformALICE/(nJpsi);
      nJpsiFALICE[i] = ( (jpsiDissALICE[i] *CNMEffects[i]) + jpsiFormALICE[i] );
      

      RAAALICE[i] = nJpsiFALICE[i];
      
      cout << nPart[i]<<"  "<<"    " << T0Cent <<"     "<<taufCent <<"  "<<R0Cent<<"  "<<RAACMS[i]*CNMEffects[i]<<"   "<<RAAALICE[i]*CNMEffects[i]<<endl;
      //IntForm( Double_t T0Cent, Double_t R0Cent, Double_t taufCent)
    }
    
    //CNM graph
    TGraph *grCNMCMS_M = new TGraph(NN,nPart,CNMEffects);
    grCNMCMS_M->SetLineWidth(2);
    grCNMCMS_M->SetLineColor(2);
    grCNMCMS_M->SetLineStyle(2);
    grCNMCMS_M->GetXaxis()->SetTitle("N_{Part}");
    grCNMCMS_M->GetYaxis()->SetTitle("CNM");
  
    // RAA graphs
    TGraph *grRAACMS_M = new TGraph(NN,nPart,RAACMS);
    grRAACMS_M->SetLineWidth(2);
    grRAACMS_M->GetXaxis()->SetTitle("N_{Part}");
    grRAACMS_M->GetYaxis()->SetTitle("R_{AA}");
    
    TGraph *grFormCMS_M = new TGraph(NN,nPart,jpsiFormCMS);
    grFormCMS_M->SetLineWidth(2);
    grFormCMS_M->SetLineColor(2);
    
    TGraph *grDissCMS_M = new TGraph(NN,nPart,jpsiDissCMS);
    grDissCMS_M->SetLineWidth(2);
    grDissCMS_M->SetLineColor(4);
    grDissCMS_M->SetLineStyle(6);
 
    TGraph *grRAAALICE_M = new TGraph(NN,nPart,RAAALICE);
    grRAAALICE_M->SetLineWidth(2);
    grRAAALICE_M->GetXaxis()->SetTitle("N_{Part}");
    grRAAALICE_M->GetYaxis()->SetTitle("R_{AA} ");
    
    TGraph *grFormALICE_M = new TGraph(NN,nPart,jpsiFormALICE);
    grFormALICE_M->SetLineWidth(2);
    grFormALICE_M->SetLineColor(2);
    
    TGraph *grDissALICE_M = new TGraph(NN,nPart,jpsiDissALICE);
    grDissALICE_M->SetLineWidth(2);
    grDissALICE_M->SetLineColor(4);
    grDissALICE_M->SetLineStyle(6);

        
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
    grRaaCMS->GetYaxis()->SetRangeUser(0,1.5);
    grRaaCMS->GetXaxis()->SetTitle("N_{Part}");
    grRaaCMS->GetYaxis()->SetTitle("R_{AA}");

   
    TLegend *legd7 = new TLegend( 0.39,0.67,0.82,0.86);
    legd7->SetBorderSize(0);
    legd7->SetFillStyle(0);
    legd7->SetFillColor(0);
    legd7->SetTextSize(0.040);
    legd7->AddEntry(grRaaCMS,"CMS Data","P");
    legd7->AddEntry(grDissCMS_M,"Gluon Dissociation","L");
    legd7->AddEntry(grCNMCMS_M,"Nucl. Abs.","L");
    //legd7->AddEntry(grFormCMS_M,"Formation","L");
    legd7->AddEntry(grRAACMS_M,"Total","L");
    

    
    new TCanvas;
    gPad->SetTicks();
    grRaaCMS->Draw("AP");
   grCNMCMS_M->Draw("sameL");
   //grFormCMS_M->Draw("sameL");
   grDissCMS_M->Draw("sameL");
   grRAACMS_M->Draw("sameL");
   legd7->Draw("same");


    
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
    lh2->SetLineWidth(1.5);
    lh2->Draw("same");
    
    TBox *GlobalSysJPsi;
    GlobalSysJPsi = new TBox(400-5, 1 - 0.06, 400+5, 1 + 0.06);
    GlobalSysJPsi->SetFillStyle(3001);
    GlobalSysJPsi->SetLineColor(6);
    GlobalSysJPsi->SetFillColor(6);
    GlobalSysJPsi->Draw("same"); 

    tb->DrawLatex(0.22,0.22,"PbPb #sqrt{s_{NN}} = 2.76 TeV");
    tb->DrawLatex(0.22,0.16,"J/#psi #rightarrow #mu^{+} #mu^{-}, p_{T}^{J/#psi} > 6.5 GeV/c");

    gPad->SaveAs("CMS_RAA_JPsi.eps");
    gPad->SaveAs("CMS_RAA_JPsi.png");



    int nbinsALICE=9;
    //Double_t NPartALICE[10]={360,262,187,130,82,51,30,15,10};
    //Double_t ErrNPartALICE[10]={0};
    //Double_t RaaALICE[10] = {0.47,0.485,0.5,0.5,0.52,0.62,0.69,0.75,0.93}; 
    //Double_t StatErrALICE[10] = {0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0};


    //ALICE Forward rapidity
    Double_t NPartALICE[10]={357,262,187,128,86,53,30,16,8};
    Double_t ErrNPartALICE[10]={0};
    Double_t RaaALICE[10] = {0.47,0.48,0.51,0.51,0.52,0.61,0.70,0.74,0.94}; 
    Double_t SystErrALICE[10] = {0.03,0.02,0.02,0.02,0.03,0.05,0.06,0.09,0.1};


    //ALICE MID rapidity
    int nbinsALICEMid=3;
    Double_t NPartALICEMid[3]={357,193,46};
    Double_t ErrNPartALICEMid[3]={0};
    Double_t RaaALICEMid[3] = {0.82,0.65,0.73}; 
    Double_t SystErrALICEMid[3] = {0.15,0.10,0.16};

    

    TGraphErrors *grRaaALICE = new TGraphErrors(nbinsALICE, NPartALICE, RaaALICE, ErrNPartALICE, SystErrALICE);  
    grRaaALICE->SetMarkerStyle(20);
    grRaaALICE->SetMarkerColor(4);
    grRaaALICE->GetYaxis()->SetRangeUser(0,1.5);
    
    TAxis *Xaxis2 = grRaaALICE->GetXaxis();
    Xaxis2->SetLimits(0.,430.0);

    grRaaALICE->GetXaxis()->SetTitle("N_{Part}");
    grRaaALICE->GetYaxis()->SetTitle("R_{AA}");
    
    TLegend *legd8 = new TLegend( 0.46,0.66,0.83,0.85);
    legd8->SetBorderSize(0);
    legd8->SetFillStyle(0);
    legd8->SetFillColor(0);
    legd8->SetTextSize(0.040);
    legd8->AddEntry(grRaaALICE,"ALICE Data","P");
    legd8->AddEntry(grDissALICE_M,"Gluon Dissociation","L");
    legd8->AddEntry(grCNMCMS_M,"Nucl. Abs.","L");
    legd8->AddEntry(grFormALICE_M,"Formation","L");
    legd8->AddEntry(grRAAALICE_M,"Total","L");

    TLine *lh3 = new TLine(0.0,1.0,420,1.0);
    lh3->SetLineColor(1);
    lh3->SetLineStyle(1);
    lh3->SetLineWidth(1.5);
    lh3->Draw("same");

    new TCanvas;
    gPad->SetTicks();
    grRaaALICE->Draw("AP");
    grFormALICE_M->Draw("sameL");
    grDissALICE_M->Draw("sameL");
    grRAAALICE_M->Draw("sameL");
    grCNMCMS_M->Draw("sameL");
    tb->DrawLatex(0.22,0.22,"PbPb #sqrt{s_{NN}} = 2.76 TeV");
    tb->DrawLatex(0.22,0.16,"J/#psi #rightarrow #mu^{+} #mu^{-}, p_{T}^{J/#psi} > 0.0 GeV/c");  
    lh3->Draw("same");
    legd8->Draw("same");
  

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



    gPad->SaveAs("ALICE_RAA.eps");
    gPad->SaveAs("ALICE_RAA.png");
  




    TGraphErrors *grRaaALICEMid = new TGraphErrors(nbinsALICEMid, NPartALICEMid, RaaALICEMid, ErrNPartALICEMid, SystErrALICEMid);  
    grRaaALICEMid->SetMarkerStyle(20);
    grRaaALICEMid->SetMarkerColor(4);
    grRaaALICEMid->GetYaxis()->SetRangeUser(0,1.5);
    
    TAxis *Xaxis = grRaaALICEMid->GetXaxis();
    Xaxis->SetLimits(0.,430.0);

    //grRaaALICEMid->GetXaxis()->SetRangeUser(0,450.0);
    
    grRaaALICEMid->GetXaxis()->SetTitle("N_{Part}");
    grRaaALICEMid->GetYaxis()->SetTitle("R_{AA}");


    new TCanvas;
    gPad->SetTicks();
    grRaaALICEMid->Draw("AP");
    grFormALICE_M->Draw("sameL");
    grDissALICE_M->Draw("sameL");
    grRAAALICE_M->Draw("sameL");
    grCNMCMS_M->Draw("sameL");
    tb->DrawLatex(0.22,0.22,"PbPb #sqrt{s_{NN}} = 2.76 TeV");
    tb->DrawLatex(0.22,0.16,"J/#psi #rightarrow #mu^{+} #mu^{-}, p_{T}^{J/#psi} > 0.0 GeV/c");  
    lh3->Draw("same");
    legd8->Draw("same");


    TBox *RaaJPsiALICEMidSys[12];
    for(int j=0;j<3;j++){
      RaaJPsiALICEMidSys[j] = new TBox(NPartALICEMid[j]-3,  RaaALICEMid[j]-SystErrALICEMid[j], NPartALICEMid[j]+3, RaaALICEMid[j]+SystErrALICEMid[j]);
    }
    
    for(int j=0;j<3;j++){
      RaaJPsiALICEMidSys[j]->SetFillStyle(0000);
      RaaJPsiALICEMidSys[j]->SetLineColor(4);
      RaaJPsiALICEMidSys[j]->Draw("same"); 
    }



    TBox *ALICEMidGlobalSysJPsi;
    ALICEMidGlobalSysJPsi = new TBox(400-5, 1 - 0.26, 400+5, 1 + 0.26);

    ALICEMidGlobalSysJPsi->SetFillStyle(3001);
    ALICEMidGlobalSysJPsi->SetLineColor(4);
    ALICEMidGlobalSysJPsi->SetFillColor(4);
    ALICEMidGlobalSysJPsi->Draw("same"); 

    gPad->SaveAs("ALICEMid_RAA.eps");
    gPad->SaveAs("ALICEMid_RAA.png");



    new TCanvas;
    grNJpsiStat->Draw("APL");
    grFormALICE_M->Draw("sameL");


    if(isUps ==1){  
    //============================= CMS Upsilon Graphs =================================//

    int NptbinD =7;
    int MBbin=1;
    double NpartMB[7]={Npart(0,40)};
    double ErNpart[7]={0};
    double NpartD[7]={Npart(0,2),Npart(2,4),Npart(4,8),Npart(8,12),Npart(12,16),Npart(16,20),Npart(20,40)}; 
    double Raa1sdata[7] = {0.41,0.43,0.48,0.61,0.68,0.59,1.01};
    double ErRaa1sdata[7] = {0.04,0.05,0.04,0.05,0.07,0.10,0.12};
    double ErSysRaa1sdata[7] = {0.05,0.05,0.05,0.07,0.08,0.08,0.17};
    
    double Raa2sdata[7] = {0.11,0.04,0.07,0.26,0.24,0.25,0.30};
    double ErRaa2sdata[7] = {0.06,0.06,0.05,0.08,0.1,0.14,0.16};
    double ErSysRaa2sdata[7] = {0.02,0.02,0.02,0.04,0.04,0.05,0.07};
    
    
    TGraphErrors *RaaY1sdata = new TGraphErrors(NptbinD,NpartD,Raa1sdata,ErNpart,ErRaa1sdata);
    RaaY1sdata->SetMarkerStyle(21);
    RaaY1sdata->SetMarkerColor(kRed+0);
    RaaY1sdata->SetMarkerSize(1.1);
    
    TCanvas *c1 =new TCanvas;
    gPad->SetTicks(1);
    RaaY1sdata->GetYaxis()->SetRangeUser(0.0,1.5);
    RaaY1sdata->GetXaxis()->SetTitle("N_{part}");
    RaaY1sdata->GetYaxis()->SetTitle("R_{AA}");
    RaaY1sdata->Draw("AP");
    grCNMCMS_M->Draw("sameL");
    grRAACMS_M->Draw("sameL"); 
    grDissCMS_M->Draw("sameL");
    legd7->Draw("same");
    
    TBox *Raa1sSys[10];
    for(int j=0;j<7;j++){
      Raa1sSys[j] = new TBox(NpartD[j]-3,Raa1sdata[j]-ErSysRaa1sdata[j],NpartD[j]+3,Raa1sdata[j]+ErSysRaa1sdata[j]);
    }
    
    for(int j=0;j<7;j++){
      Raa1sSys[j]->SetFillStyle(0000);
      Raa1sSys[j]->SetLineColor(6);
      Raa1sSys[j]->Draw("same"); 
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

    tb->DrawLatex(0.21,0.30,"PbPb #sqrt{s_{NN}} = 2.76 TeV");
    tb->DrawLatex(0.21,0.24,"#varUpsilon(1S) #rightarrow #mu^{+} #mu^{-}");
    c1->Update();
    // gPad->Update();
    gPad->SaveAs("CMS_RAA_Upsilon.eps");
    gPad->SaveAs("CMS_RAA_Upsilon.png");
    


    //return;


    
    TGraphErrors *RaaY2sdata = new TGraphErrors(NptbinD,NpartD,Raa2sdata,ErNpart,ErRaa2sdata);
    RaaY2sdata->SetMarkerStyle(21);
    RaaY2sdata->SetMarkerColor(kRed+0);
    RaaY2sdata->SetMarkerSize(1.1);
    
    new TCanvas;
    gPad->SetTicks(1);
    RaaY2sdata->GetYaxis()->SetRangeUser(0.0,1.5);
    RaaY2sdata->GetXaxis()->SetTitle("N_{part}");
    RaaY2sdata->GetYaxis()->SetTitle("R_{AA}");
    RaaY2sdata->Draw("AP");
    grCNMCMS_M->Draw("sameL");
    grRAACMS_M->Draw("sameL"); 
    grDissCMS_M->Draw("sameL");

    TBox *Raa2sSys[10];
    for(int j=0;j<7;j++){
      if(j<7){
	Raa2sSys[j] = new TBox(NpartD[j]-3,Raa2sdata[j]-ErSysRaa2sdata[j],NpartD[j]+3,Raa2sdata[j]+ErSysRaa2sdata[j]);
      }
    }
    
    for(int j=0;j<7;j++){
      Raa2sSys[j]->SetFillStyle(0000);
      Raa2sSys[j]->SetLineColor(6);
      Raa2sSys[j]->Draw("same"); 
    }
    
    lh->Draw("same");
    GlobalSys1->Draw("same"); 
    GlobalSys2->Draw("same"); 

    }
    tb->DrawLatex(0.21,0.30,"PbPb #sqrt{s_{NN}} = 2.76 TeV");
    tb->DrawLatex(0.21,0.24,"#varUpsilon(2S) #rightarrow #mu^{+} #mu^{-}");





    grSigDQ0->Write();
    OutFile->Write();

  }
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

Double_t TauToTemp(Int_t Flag, Double_t Tau) 
{
  Double_t Temp = 0;
  if(Flag ==1) {Temp = pow(T0*T0*T0*tau0/Tau, 1.0/3.0);}
  if(Flag ==2) {
    Double_t Deno = (R05+0.5*aT*Tau*Tau)*(R05+0.5*aT*Tau*Tau)*(z0+vZ*Tau);
    Double_t Num = T0*T0*T0*(R05+0.5*aT*tau0*tau0)*(R05+0.5*aT*tau0*tau0)*(z0+vZ*tau0);
    Double_t Sum = Num/Deno;
    Temp = pow( Sum, 1.0/3.0);
  }
  return Temp;
}


Double_t TauToTemp(Int_t Flag, Double_t T0Cent, Double_t R0Cent, Double_t Tau) 
{
  Double_t Temp = 0;
  if(Flag ==1) {Temp = pow(T0Cent*T0Cent*T0Cent*tau0/Tau, 1.0/3.0);}
  
  if(Flag ==2) {
    Double_t Num = T0Cent*T0Cent*T0Cent*(R0Cent+0.5*aT*tau0*tau0)*(R0Cent+0.5*aT*tau0*tau0)*(z0+vZ*tau0);   
    Double_t Deno = (R0Cent+0.5*aT*Tau*Tau)*(R0Cent+0.5*aT*Tau*Tau)*(z0+vZ*Tau);
    Double_t Sum = Num/Deno;
    Temp = pow(Sum, 1.0/3.0);
  }
  return Temp;
}



Double_t T0ToTauf(Int_t Flag, Double_t T0Cent, Double_t R0Cent) 
{

  Double_t TaufValLong=0;
  Double_t TaufValCylnd = 0;
  
  //Double_t TC=0.170;
  TaufValLong = T0Cent*T0Cent*T0Cent*tau0/(TC*TC*TC);
  
  if(Flag ==2) {
    Double_t TaufG=TaufValLong;
    Double_t delta;
    Int_t iters=0;
    do{
      Double_t C =T0Cent*T0Cent*T0Cent*(R0Cent+0.5*aT*tau0*tau0)*(R0Cent+0.5*aT*tau0*tau0)*(z0+vZ*tau0);
      TaufValCylnd = TaufG -  ( (TC*TC*TC*( (0.25*vZ*pow(aT,2)*pow(TaufG,5))
					    +(0.25*z0*pow(aT,2)*pow(TaufG,4))
					    +(R0Cent*aT*vZ*pow(TaufG,3))
					    +(z0*R0Cent*aT*pow(TaufG,2))
					    +(pow(R0Cent,2)*vZ*TaufG)
					    +(z0*R0Cent*R0Cent)) -C)/( TC*TC*TC*( (1.25*vZ*pow(aT,2)*pow(TaufG,4))
										  +(z0*pow(aT,2)*pow(TaufG,3))
										  +(3*R0Cent*aT*vZ*pow(TaufG,2))
										  +(2*z0*R0Cent*aT*pow(TaufG,1))
										  +(pow(R0Cent,2)*vZ)))
				);
      delta=fabs(TaufValCylnd-TaufG);
      TaufG=TaufValCylnd;
      iters++;
      //cout<<delta<<"  "<<TaufValCylnd<<endl;
 
    }while(delta > 0.001 && iters <=30);

  }
  
  Double_t TaufVal=0;
  if(Flag==1) {TaufVal=TaufValLong;}
  if(Flag==2) {TaufVal=TaufValCylnd;}
  
  return TaufVal;
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
      
      Double_t C =T0Cent*T0Cent*T0Cent*tau0*(R0Cent+0.5*aT*tau0*tau0)*(R0Cent+0.5*aT*tau0*tau0);
      Double_t Fx= 0.25*TC*TC*TC*aT*pow(TauCG,5) + R0Cent*aT*TC*TC*TC*pow(TauCG,3)+TC*TC*TC*R0Cent*R0Cent*TauCG - C;        
      Double_t FPrimex= 1.25*TC*TC*TC*aT*pow(TauCG,4) + 3.0*R0Cent*aT*TC*TC*TC*pow(TauCG,2)+TC*TC*TC*R0Cent*R0Cent;        

      TauCValCylnd = TauCG -  (Fx/FPrimex);

      delta=fabs(TauCValCylnd-TauCG);
      TauCG=TauCValCylnd;
      iters++;
      //cout<<delta<<"  "<<TauCValCylnd<<endl;
    }while(delta > 0.001 && iters <=30);

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
     Double_t C =aq*TauC*(R0Cent+0.5*aT*TauC*TauC)*(R0Cent+0.5*aT*TauC*TauC);
     Double_t Fx=0.25*ah*aT*aT*pow(TauHG,5) + R0Cent*ah*aT*pow(TauHG,3) + ah*R0Cent*R0Cent*TauHG - C;
     Double_t FPrimex=1.25*ah*aT*aT*pow(TauHG,4) + 3.0*R0Cent*ah*aT*pow(TauHG,2) + ah*R0Cent*R0Cent;
     TauHCylnd = TauHG  - (Fx/FPrimex);
     
     delta=fabs(TauHCylnd-TauHG);
     TauHG=TauHCylnd;
     iters++;
     
     //cout<<iters<<"  "<<delta<<"  "<<TauHCylnd<<endl;
     
    }while(delta > 0.001 && iters <=30);
    

  }
  Double_t TauHVal=0;
  
  if(Flag ==1){TauHVal=TauHLong;}
  if(Flag ==2){TauHVal=TauHCylnd;}

  return TauHVal;

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
  //Double_t lambdag =16.0;
  Double_t fac=2.0*pi*mJpsi*mJpsi/mT;
  int nmin = 1;
  int nmax = 20;
  int nstep = 1;
  int NNn=(nmax-nmin)/nstep;

  Double_t sum=0;

  for(int i=0;i<NNn;i++) {
    int n=nmin+i*nstep;
    sum=sum+DissFuncXu(pT,T,n)*T/n;
  }
  Double_t func= sum*nstep;
  Double_t Deno = 8*pi*1.202*pow(T, 3.0);
  return (fac*func/Deno)*hbarc2;
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

Double_t SigmaD(Int_t Flag, Double_t q0)
{
  Double_t SigmaDq0 = 0.0;
  if(q0<ep0) return SigmaDq0;
  if(Flag ==1 ) { SigmaDq0 = epCon*pow(q0-ep0, 1.5)/pow(q0,5.0);}  
  

  if(Flag ==2 ) { 
    Double_t x = q0;
    Double_t y =0;
    Int_t NN = 52;
    Double_t xA[52]={0.586136, 0.665164, 0.715606, 0.730504, 0.745326, 0.760149, 0.767863, 0.782609, 0.797432, 0.819514, 0.834337, 0.856268, 0.87109, 0.90013, 
		     0.92917, 0.958134, 0.994207, 1.07331, 1.10908, 1.13767, 1.1807, 1.21639, 1.25216, 1.27349, 1.31637, 1.35206, 1.39502, 1.43079, 1.47367, 
		     1.52373, 1.56661, 1.61675, 1.66689, 1.71695, 1.78138, 1.83871, 1.89596, 1.95335, 1.99631, 2.07519, 2.14688, 2.21139, 2.28315, 2.34766, 
		     2.4338, 2.52704, 2.61318, 2.68487, 2.74953, 2.82137, 2.90025, 2.96491};
    Double_t yA[52]={0.0, 0.0, 0.00987356, 0.0689213, 0.119547, 0.170174, 0.229173, 0.271378, 0.322004, 0.3811, 0.431726, 0.473979, 
		     0.524605, 0.558485, 0.592365, 0.617823, 0.634908, 0.643862, 0.627261, 0.610612, 0.60248, 0.577458, 0.560857, 0.535737, 0.510763, 
		     0.48574, 0.469187, 0.452586, 0.427612, 0.402686, 0.377712, 0.361208, 0.344703, 0.319777, 0.294948, 0.278492, 0.253615, 0.24558, 
		     0.229028, 0.212717, 0.196358, 0.17995, 0.172013, 0.155605, 0.147765, 0.131551, 0.12371, 0.107351, 0.107786, 0.10827, 0.0919596, 
		     0.0923952};
    
    
    if( x > xA[NN-1]){
      y = yA[NN-1] +( (x-xA[NN-1])*(yA[NN-1]-yA[NN-2]) / (xA[NN-1] - xA[NN-2]) );
      SigmaDq0 = y;
    }   
 
    if( x < xA[0]){
      y =0.0;
      SigmaDq0 = y;
    }   

    for(int i=0; i<NN-1; i++) {
      if( x >= xA[i]  &&  x < xA[i+1] ){
	y=yA[i] + ( ( x - xA[i] ) * ( yA[i+1] - yA[i] )/ (xA[i+1] - xA[i]) );
	SigmaDq0 = y;
      }   
    }


  }

  //SigmaDq0=0.4; pT 3.6
  //SigmaDq0=0.5; pT 8.6
  
  //mb to GeV-2
  if(Flag ==2){SigmaDq0 = SigmaDq0 / (10.0 * hbarc2); }  
  
  return SigmaDq0;

}


Double_t DissRateR(Double_t T) {  // J/psi assumed at rest 

  Double_t pMin=0;
  Double_t pMax=8.0;

  Double_t sumN = 0;
  Double_t sumD = 0;

  int nTrials = 500000;
  for(int i =1; i<= nTrials; i++) {
    
    Double_t ran1=gRandom->Rndm();
    Double_t p = pMin + (pMax-pMin)*ran1;

    Double_t funD = fGluon(p, T)*4.0*pi*p*p;
    Double_t funN = SigmaD(2,p)*funD;
    
    sumN = sumN + funN;
    sumD = sumD + funD;
  }
  
  Double_t step = (pMax-pMin)/nTrials;

  Double_t rateN = sumN*step;
  Double_t rateD = sumD*step;

  Double_t DissRate = rateN/rateD;
  
  return DissRate*hbarc2;
}


Double_t fGluon(Double_t p, Double_t T)
{
  Double_t gi=1.0;
  Double_t fg = gi / (TMath::Exp(p/T)-1);
  return fg;
}



Double_t DissRateZhang(Double_t T)
{
  Double_t alphaJpsi = mJpsi/T;
  Double_t alphaC = mQ/T;

  Double_t z0=alphaJpsi;
  if(alphaJpsi<2.0*alphaC) z0 = 2.0*alphaC; 


  Double_t alphaJpsi2 = alphaJpsi*alphaJpsi;

  Double_t deno = 8.0*alphaJpsi2*TMath::BesselK(2,alphaJpsi);

  Double_t zmin = z0;
  Double_t zmax = 10.0*z0;
  Double_t zstep = 0.05;
  int NZ = (int) ((zmax-zmin)/zstep);

  Double_t sum =0.0;
  for(int i=0; i<NZ; i++) {
   
    Double_t z = zmin + i*zstep;
    Double_t z2 = z*z;

    Double_t fun = pow(z2-alphaJpsi2, 2)*TMath::BesselK(1,z)*SigmaDS(z2*T*T);
    sum = sum+fun;
  }

  Double_t lamdaD = sum*zstep/deno;

  return lamdaD*hbarc2;
}


Double_t SigmaDS(Double_t s)
{
 
  Double_t q0 = (s-mJpsi*mJpsi)/(2.0*mJpsi); 

  Double_t SigmaDq0 = 0.0;

  if(q0<ep0) return SigmaDq0;

  SigmaDq0 = epCon*pow(q0-ep0, 1.5)/pow(q0,5.0);  
  return SigmaDq0;
}


Double_t SigmaFS(Double_t s)
{
 
  Double_t q0 = (s-mJpsi*mJpsi)/(2.0*mJpsi); 

  Double_t SigmaF = 0.0;

  if(q0<ep0) return SigmaF;

  if(s<=4.0*mQ2) return SigmaF;


  Double_t kJpsi2 = pow(s-mJpsi*mJpsi, 2.0);
  Double_t kcc2 = s*(s-4.0*mQ2);

  Double_t SigmaD = epCon*pow(q0-ep0, 1.5)/pow(q0,5.0);  

  SigmaF = SigmaD*48.0*kJpsi2/(36.0*kcc2);

  return SigmaF;

}


Double_t FormRateZhang(Double_t T)
{
  Double_t alphaJpsi = mJpsi/T;
  Double_t alphaC = mQ/T;

  Double_t z0=alphaJpsi;
  if(alphaJpsi<2.0*alphaC) z0 = 2.0*alphaC; 

  Double_t alphaJpsi2 = alphaJpsi*alphaJpsi;

  Double_t deno = 4.0*pow(alphaC, 4)*pow(TMath::BesselK(2,alphaC),2);

  Double_t zmin = z0;
  Double_t zmax = 10.0*z0;
  Double_t zstep = 0.05;
  int NZ = (int) ((zmax-zmin)/zstep);

  Double_t sum =0.0;
  for(int i=0; i<NZ; i++) {
   
    Double_t z = zmin + i*zstep;
    Double_t z2 = z*z;

    Double_t fun = pow(z2-alphaJpsi2, 2)*TMath::BesselK(1,z)*SigmaDS(z2*T*T);
    sum = sum+fun;
  }

  Double_t lamdaD = sum*zstep/deno;

  return lamdaD*hbarc2*48.0/36.0;
}


///special case c cbar centre of mass at rest
Double_t FormRateR(Double_t T) {

  Double_t pMin=0;
  Double_t pMax=8.0;

  Double_t sumN = 0;
  Double_t sumD = 0;

  int nTrials = 500000;
  for(int i =1; i<= nTrials; i++) {
    
    Double_t ran1=gRandom->Rndm();
    Double_t p = pMin + (pMax-pMin)*ran1;

    Double_t E1 = p*p + mQ2;
    Double_t E2 = p*p + mQ2;
    Double_t s = (E1+E2)*(E1+E2);

    Double_t FJPsi = SigmaFS(s);
  
    // Relative Velocity 
     Double_t num = s-4.0*mQ2;
    Double_t RelVel = sqrt(s)*sqrt(num)/(2.0*E1*E2);
    Double_t funN = 4.0*pi*4.0*pi*p*p*p*p*fcharm(p, T)*fcharm(p,T)*FJPsi*RelVel;
    Double_t funD = 4.0*pi*p*p*fcharm(p, T);
    
    sumN = sumN + funN;
    sumD = sumD + funD;
  }
  
  Double_t step = (pMax-pMin)/nTrials;

  Double_t rateN = sumN*step;
  Double_t rateD = sumD*step;

  Double_t FormRate = rateN/(rateD*rateD);
  
  return FormRate*hbarc2;
}


Double_t fcharm(Double_t p, Double_t T)
{
  Double_t gi=1.0;
  Double_t fg = gi / (TMath::Exp(sqrt(p*p*mQ2)/T)+1);
  return fg;
}


//Formation Rate MC
Double_t FormRate(Double_t Temp) {
  
  Double_t PMin=0.1;
  Double_t PMax=15.0;

  Double_t ThetaMin=0.0001;
  Double_t ThetaMax=TMath::Pi();

  Double_t PhiMin=0.0001;
  Double_t PhiMax=2*TMath::Pi();

  int nTrials = 500000;
  //int nTrials = 5000;
  
  Double_t Sum = 0;
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

    Sum = Sum + FormFun(p1,p2,theta1,theta2,phi1,phi2,Temp);
    Sum1 = Sum1 + p1*p1*p2*p2*sin(theta1)*sin(theta2)*fcharm(p1,Temp) * fcharm(p2,Temp);
  }

  Double_t step = (PMax- PMin)*(PMax- PMin)*(ThetaMax-ThetaMin)*(ThetaMax-ThetaMin)*(PhiMax-PhiMin)*(PhiMax-PhiMin)/nTrials;
  
  Double_t ForRate  = step*Sum;

  Double_t ForRateDeno  = step*Sum1;

  return (ForRate/ForRateDeno)*hbarc2;

}


Double_t FormFun(Double_t p1, Double_t p2, Double_t theta1, Double_t theta2, Double_t phi1, Double_t phi2, Double_t T)
{

  Double_t p1dotp2 = p1*p2*(sin(theta1)*sin(theta2)*cos(phi1-phi2) + cos(theta1)*cos(theta2));
  Double_t p1plusp2Square = p1*p1 + p2*p2 + 2.0*p1dotp2;

  double E1 = p1*p1 + mQ2;
  Double_t E2 = p2*p2 + mQ2;
  Double_t s = (E1+E2)*(E1+E2) - p1plusp2Square; 

  //  ccbar to Jpsi cross section
  //  Double_t FJPsi = 0;
  //  if(qSquare > 0 && (4*mD*mD - 4*mQ2 - qSquare) > 0) FJPsi = 0.01*sigmapp ; // sigmapp ???

  Double_t FJPsi = SigmaFS(s);

  // Relative Velocity 

  Double_t num = s-4.0*mQ2;
  Double_t RelVel = sqrt(s)*sqrt(num)/(2.0*E1*E2);

  Double_t allfactors = p1*p1*p2*p2*sin(theta1)*sin(theta2)* RelVel *FJPsi* fcharm(p1,T) * fcharm(p2,T);
  return allfactors;
}


// triple integral function
Double_t FormFun2(Double_t p1, Double_t p2, Double_t CosTheta)
{
  
  Double_t E1 = p1*p1 + mQ2;
  Double_t E2 = p2*p2 + mQ2;
  Double_t s = 2*mQ2 + 2*E1*E2 - 2*p1*p2*CosTheta; 

  Double_t FJPsi = SigmaFS(s);
  // Relative Velocity 
  Double_t num = s-4.0*mQ2;
  Double_t RelVel = sqrt(s)*sqrt(num)/(2.0*E1*E2);
  Double_t allfactors = RelVel*FJPsi;
  return allfactors;
}


Double_t IntFormFun2(Double_t T)
{
  Double_t P1Step = 0.05;
  Double_t P1Start = 0.0;
  Double_t P1End = 15.0;
  int P1N =(int)((P1End - P1Start)/P1Step);
  Double_t P2Step = 0.05;
  Double_t P2Start = 0.0;
  Double_t P2End = 15.0;
  int P2N =(int)((P2End - P2Start)/P2Step);
  Double_t CosThetaStep = 0.05;
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
  Double_t IntP1 =  SumP1*P1Step;
  
  Double_t SumP1Deno=0.0;
  for(int i =0; i <= P1N ; i++)
    {
      Double_t p1 = P1Start + i*P1Step;
      SumP1Deno=SumP1Deno + p1*p1*fcharm(p1,T);
    }
  Double_t IntP1Deno=SumP1Deno*P1Step;
  //return  IntP1*hbarc2/(2*IntP1Deno*IntP1Deno)/4.0; why divided by 4
  return  IntP1*hbarc2/(2*IntP1Deno*IntP1Deno);
  
}


// put p2 = p-p1 and integrate P 
Double_t IntFormFun2_IntP(Double_t T)
{
  
  Double_t PStep = 0.05;
  Double_t PStart = 0.1;
  Double_t PEnd = 30.0;
  
  int PN =(int)((PEnd - PStart)/PStep);
  Double_t SumP=0;
  for(int i =0; i <= PN ; i++) 
    { 
      Double_t p = PStart + i*PStep;
      SumP=SumP+IntFormFun2_P(p,T);
    }
  return SumP*PStep; 
}


// put p2 = p-p1
Double_t IntFormFun2_P(Double_t P, Double_t T)
{
  Double_t P1Step = 0.05;
  Double_t P1Start = 0.0;
  Double_t P1End = 10.0;
  
  int P1N =(int)((P1End - P1Start)/P1Step);
    
  Double_t CosThetaStep = 0.05;
  Double_t CosThetaStart = 1.0;
  Double_t CosThetaEnd = -1.0;
  
  int CosThetaN =(int)((CosThetaStart - CosThetaEnd)/CosThetaStep);
  
  Double_t IntCosTheta =0;
  Double_t SumP1=0;  
  for(int i =0; i <= P1N ; i++) {
    Double_t p1 = P1Start + i*P1Step;
    Double_t SumCosTheta=0;
    for(int k =0; k <= CosThetaN ; k++)  {
      Double_t CosTheta = CosThetaStart - k *CosThetaStep;
      SumCosTheta = SumCosTheta + FormFun2(p1,(P-p1),CosTheta);
    }//theta
    IntCosTheta = SumCosTheta*CosThetaStep;
    SumP1=SumP1+ p1*p1*fcharm(p1,T)*(P-p1)*(P-p1)*fcharm((P-p1),T)*IntCosTheta;
  }//p1
  Double_t IntP1 =  SumP1*P1Step;
  
  Double_t SumP1Deno=0.0;
  for(int i =0; i <= P1N ; i++)
    {
      Double_t p1 = P1Start + i*P1Step;
      SumP1Deno=SumP1Deno + p1*p1*fcharm(p1,T);
    }

  Double_t IntP1Deno=SumP1Deno*P1Step;
  return  IntP1*hbarc2/(2*IntP1Deno*IntP1Deno);

}

Double_t IntDiss()
{
  Double_t step = 0.1;
  int N1 = (int)((tauf-tau0)/step);
  Double_t sumd = 0.0;
  for (int i= 0; i<=N1; i++) {
    Double_t tau = tau0 + step*i;
    Double_t T = TauToTemp(2,tau);
    Double_t Rhog = 2*8*1.202*pow(T, 3.0)/pi2;
    sumd = sumd + DissRateIntpT(T)*Rhog;
  }
  return exp(-sumd*step/hbarc3);
}


Double_t IntDiss(Double_t T0Cent, Double_t R0Cent, Double_t taufCent, Double_t PtMin)
{

  Double_t step = 0.1;
  int N1 = (int)((taufCent-tau0)/step);
  Double_t sumd = 0.0;
  for (int i= 0; i<=N1; i++) {
    Double_t tau = tau0 + step*i;
    Double_t theta =1.0;
    if(tau < FormTau* (PtMin/mJpsi) ) theta =0;
    Double_t T = TauToTemp(1,T0Cent,R0Cent,tau);
    Double_t Rhog = 2*8*1.202*pow(T, 3.0)/pi2;
    sumd = sumd +  theta*DissRateXu(PtMin,T)*Rhog;
  }
  return exp(-sumd*step/hbarc3);
}





Double_t IntDiss_PtInt(Double_t T0Cent, Double_t R0Cent, Double_t taufCent, Double_t PtMin)
{
  //for 500 bins and step = 0.1
  //PtMin=0.05;
  //PtMin=6.45;
  
  //for 100 bins and step = 0.5
  //PtMin=0.25;
  //PtMin=6.25;


  Double_t Ptmax=0;
  if(isUps==0)Ptmax=30.0;
  if(isUps==1)Ptmax=40.0;

  Double_t Ptstep=0.5;
  int NN_Pt= (int)((Ptmax-PtMin)/Ptstep);
  Double_t sum=0;
  Double_t sumPt=0;
  
  Double_t yield =0;

  for(int i=0;i<=NN_Pt;i++) {
    Double_t Pt=PtMin+i*Ptstep;
    //Y1S_Pt->GetBinCenter(i
    if(isUps==0){yield=Jpsi_Pt->GetBinContent(Jpsi_Pt->FindBin(Pt));}
    //if(isUps==1){yield=Y1S_Pt->GetBinContent(Y1S_Pt->FindBin(Pt));}
    if(isUps==1){yield=Y2S_Pt->GetBinContent(Y1S_Pt->FindBin(Pt));}
    sum= sum + ( yield*IntDiss(T0Cent,R0Cent,taufCent,Pt) );
    sumPt= sumPt+ yield;  
    //cout<<Pt<<"  "<<Y1S_Pt->FindBin(Pt)<<"    "<<Y1S_Pt->GetBinContent(Y1S_Pt->FindBin(Pt))<<endl;
  }
  return sum/sumPt;
}


Double_t IntForm()
{
  Double_t step = 0.1;
  int N1 = (int)((tauf-tau0)/step);
  Double_t IntDrate[10000];
  Double_t sumd = 0.0;
  for (int i= 0; i<=N1; i++) {
    Double_t tau = tau0 + step*i;
    Double_t T =  TauToTemp(2,tau);
    Double_t Rhog = 2*8*1.202*pow(T, 3.0)/pi2;
    sumd = sumd + DissRateIntpT(T)*Rhog;
    IntDrate[i] =  exp(-sumd*step/hbarc3); 
  }
  
  Double_t sum=0;
  for (int i= 0; i<=N1; i++) {
    Double_t tau = tau0 + step*i;
    Double_t T = TauToTemp(2,tau);
    Double_t Frate =  IntFormFun2_IntP(T)/(tau*IntDrate[i]); 
    sum = sum + Frate;
  }
  return sum*step;
}    


Double_t IntForm( Double_t T0Cent, Double_t R0Cent, Double_t taufCent)
{
  Double_t step = 0.1;
  int N1 = (int)((taufCent - tau0)/step);
  Double_t IntDrate[10000];
  Double_t sumd = 0.0;
  for (int i= 0; i<=N1; i++) {
    Double_t tau = tau0 + step*i;
    Double_t T = TauToTemp(2,T0Cent,R0Cent,tau);
    Double_t Rhog = 2*8*1.202*pow(T, 3.0)/pi2;
    sumd = sumd +  DissRateXu(3.6,T)*Rhog;
    IntDrate[i] =  exp(-sumd*step/hbarc3); 
  }

  Double_t sum=0;
  for (int i= 0; i<=N1; i++) {
    Double_t tau = tau0 + step*i;
    Double_t T = TauToTemp(2,T0Cent,R0Cent,tau);
    Double_t VTau=(z0+vZ*tau)*pi*(R0Cent+0.5*aT*tau*tau)*(R0Cent+0.5*aT*tau*tau);
    Double_t Frate = FormRate(T)/(VTau*IntDrate[i]); 
    sum = sum + Frate;
  }
  return sum*step;
}    




Double_t Shadowing(Double_t SigmaAbs, Double_t NPart)
{
  Double_t Rho0=0.14; //fm^-3
  //Double_t SigmaAbs=0.2; //fm^2
  Double_t L= 1.5*R0*TMath::Sqrt(NPart/416.0);
  cout<<"L : "<<L<<endl;
  return TMath::Exp(-(Rho0*SigmaAbs*L));
}


