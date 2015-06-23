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
#include "TGraph.h"

#include <fstream>
#include <map>
#include <string>
#include <iostream>
#include <stdio.h>
#include <string.h>
#include "TObjArray.h"
#include "TRandom.h"

Double_t pi = TMath::Pi();
Double_t pi3=pi*pi*pi;
Double_t twopi3 = 8.0*pi*pi*pi;
Double_t hbarc = 0.197327;
Double_t hbarc2 = hbarc*hbarc;
Double_t hbarc3 = hbarc*hbarc*hbarc;
Double_t MassD = 1.868;

//Double_t MassC = 1.86;

Double_t MassJPsi = 3.1;
Double_t MassC = 1.5;

// Kharjeev paper values
Double_t mQ=MassC;
Double_t epsilon0=0.644;

//Double_t epsilon0=(2*mQ-MassJPsi);

Double_t ReducedMass = MassC*MassC/(MassC+MassC);
Double_t sigmapp = 7.0 ; //fm^2

//For LHC
const Double_t Tau_0 = 0.1; // fm
const Double_t R = 7.1;//fm
const Double_t V_0 = pi*R*R*Tau_0;
const Double_t T_0 = 0.620; //in GeV
//const Double_t Njpsi_0 = 0.177; 
const Double_t Njpsi_0 = 0.177; 
const Double_t N_ccbar = 17.8; 
const Double_t T_f = 0.170; //in GeV
const Double_t Tau_f = pow(T_0/T_f, 3.)*Tau_0;

const Double_t GeVMinus2ToMiliBarn=0.3894;


Double_t FormRate(Double_t Tau, int flag);
Double_t FormFun(Double_t, Double_t, Double_t, Double_t, Double_t, Double_t, Double_t);
Double_t FormFunDenoFunc(Double_t, Double_t, Double_t, Double_t, Double_t);
Double_t FCharm(Double_t, Double_t);

Double_t DissRate(Double_t Tau, int flag);
Double_t DissFun(Double_t,Double_t, Double_t, Double_t, Double_t, Double_t, Double_t);
Double_t FGluon(Double_t,Double_t);
Double_t FJPsi(Double_t,Double_t);
Double_t LambdaD(Double_t);
Double_t DissFunDenoFunc(Double_t, Double_t, Double_t, Double_t, Double_t);
Double_t RhoG(Double_t);


Double_t Integral1(int);
Double_t Integral2();

Double_t TempToTau(Double_t); 
Double_t TauToTemp(Double_t);
Double_t DissFuncSecond(Double_t q0);
Double_t FormFuncSecond(Double_t q0);

Double_t DissFuncAvIntPt(Double_t T);
Double_t DissFuncAv(Double_t Pt,Double_t T);

//Double_t DissFuncIntN(Double_t Pt,Double_t T);

Double_t DissFuncIntX(Double_t Pt, Double_t T, Double_t n);
Double_t DissFuncX(Double_t Pt, Double_t T, Double_t n, Double_t x);
Double_t Q0ToRootS(Double_t q0);
Double_t RootSToQ0(Double_t RootS);

Double_t DissFuncSecondRootS(Double_t RootS);
Double_t FormFuncSecondRootS(Double_t RootS);

Double_t IntFormFunction2(Double_t Pt, Double_t T);
Double_t FormFunction2(Double_t Pt, Double_t Pt1, Double_t Phi, Double_t Phi1,Double_t T);

Double_t ThetaFunction(Double_t x);
Double_t ThetaFunctionArg(Double_t Pt, Double_t Pt1, Double_t Phi, Double_t Phi1);

Double_t DeltaFunction(Double_t x);
Double_t DeltaFunctionArg1(Double_t Pt, Double_t Pt1, Double_t Pt2, Double_t Phi, Double_t Phi1, Double_t Phi2);
Double_t DeltaFunctionArg2(Double_t Pt, Double_t Pt1, Double_t Pt2, Double_t Phi, Double_t Phi1, Double_t Phi2);

Double_t QuarkDiss(Double_t Mt,Double_t T);

Double_t Mt1(Double_t Pt, Double_t M);
Double_t Mt2(Double_t Pt, Double_t Pt1, Double_t Phi, Double_t Phi1, Double_t M);
Double_t IntFormFunction2Pt(Double_t T);


Double_t Taa(int BinLow, int BinHigh);
Double_t Npart(int BinLow, int BinHigh);
Double_t NColl(int BinLow, int BinHigh);


Double_t AlphaJPsi(Double_t T);
Double_t AlphaC(Double_t T);
Double_t LambdaD_Bessel(Double_t Z, Double_t T);
Double_t LambdaD_BesselIntZ(Double_t T);
Double_t LambdaF_BesselIntZ(Double_t T);
Double_t LambdaD_BesselIntZ_2(Double_t T);
Double_t LambdaD_BesselIntgrant(Double_t Z, Double_t T);
Double_t LambdaF_BesselIntZ_2(Double_t T);

//Double_t Integral(int N, Double_t Tau1, Double_t Tau2, Double_t Int1, Double_t Int2);

///////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////

Double_t TauMax;
Double_t TauMin;

Double_t Te[1000], FRate[1000], DRate[1000];
Double_t Taue[1000];
Double_t TauStep = 0.01;
int NN;

TFile *filejpsi=new TFile("JPsiPt.root","R");
TH1D *Jpsi_Pt = (TH1D*)filejpsi->Get("diMuonsPt_Gen");


//////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////  Main Program /////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////


void JPsi_SuppReg()
{


  cout<<" main "<<endl;



  //=========== Put here all centrality dependent things ========================================// 
  Double_t CentBin[11]={0,2,4,8,12,16,20,24,28,32,40};
  Double_t RaaJPsi[10];
  Double_t RaaJPsiErr[10];
  Double_t TaaVal[10];
  Double_t NmbVal[10];
  Double_t NpartVal[10];
  Double_t NCollVal[10];
  Double_t Temp_Cent[10];
  Double_t Tau_Cent[10];

  Double_t Cent[11] = {0,5,10,20,30,40,50,60,70,80,100}; 
  Double_t dNdEtabyNpartby2[20] = {8.4,7.9,7.4,7.0,6.6,6.1,5.7,5.1,4.4,3.7};
  Double_t Raa[10];

  //2A
  Double_t Npart0=416;
  Double_t Radius_Pb = 7.8;
  Double_t NCollMB=NColl(0,40);
  Double_t MRadius[10]; 
  Double_t NJPsi_T[10];
  Double_t Nccbar_T[10];
  Double_t PiR2;
  Double_t Supp_T[10];
  Double_t ReGen_T[10];

  
  //========================================================================================//
  //=========================== CMS JPsi Data Raa ==========================================//
  //========================================================================================//
  int NCentBins =12;
  Double_t JPsiRaaCentCMS[20]={0.23,0.24,0.29,0.33,0.38,0.40,0.45,0.41,0.52,0.52,0.64,0.64};
  Double_t StatErr_JPsiRaaCentCMS[20]={0.01,0.01,0.02,0.02,0.02,0.03,0.03,0.03,0.04,0.04,0.05,0.05};
  Double_t SystErr_JPsiRaaCentCMS[20]={0.03,0.03,0.03,0.04,0.05,0.05,0.06,0.06,0.08,0.08,0.11,0.13};
  Double_t JPsiRaaNPartCMS[20]={Npart(0,2),Npart(2,4),Npart(4,6),Npart(6,8),Npart(8,10),Npart(10,12),
				Npart(12,14),Npart(14,16),Npart(16,18),Npart(18,20),Npart(20,24),
				Npart(24,40)};
  
  Double_t Err_JPsiRaaNPartCMS[20]={0};

  TBox *BoxRaaCent[10];
  
  for(int i=0;i< NCentBins;i++)
    {
      BoxRaaCent[i]=new TBox(JPsiRaaNPartCMS[i]-4,  JPsiRaaCentCMS[i]-SystErr_JPsiRaaCentCMS[i], JPsiRaaNPartCMS[i]+4,JPsiRaaCentCMS[i]+SystErr_JPsiRaaCentCMS[i]); 
      BoxRaaCent[i]->SetFillStyle(0000);
      BoxRaaCent[i]->SetLineColor(2);
    }


  TGraphErrors *RaaCMSData = new TGraphErrors(NCentBins,JPsiRaaNPartCMS,JPsiRaaCentCMS,Err_JPsiRaaNPartCMS,StatErr_JPsiRaaCentCMS);  
  RaaCMSData->SetMarkerStyle(21);
  RaaCMSData->SetMarkerColor(2);
  RaaCMSData->GetYaxis()->SetRangeUser(0,1.5);
  
  RaaCMSData->GetXaxis()->SetTitle("N_{Part}");
  RaaCMSData->GetXaxis()->CenterTitle();

  TLatex *tb = new TLatex();
  //tb->SetNDC(); 
  tb->SetTextAlign(12);
  tb->SetTextColor(1);
  tb->SetTextSize(0.043);
  
  new TCanvas;
  gPad->SetTicks();
  RaaCMSData->Draw("AP");
  for(int i=0;i< NCentBins;i++)
    {
      BoxRaaCent[i]->Draw("same");
    }
   
  tb->DrawLatex(13.06,1.3,"CMS Simulation");
  tb->DrawLatex(0.22,0.85,"PbPb  #sqrt{s_{NN}} = 2.76 TeV");
 
  
  //========================================================================================//
  //=========================== CMS JPsi Data Raa GRAPH END ================================//
  //========================================================================================//






  //==========================  Graphs for Different Dissosiation Functions to Compare =================//
  Double_t Q0[1000]={0};
  Double_t SigmaQ0Val[1000]={0};
  Double_t SigmaQ0Val1[1000]={0};
  
  Double_t Q0Max=10.0;
  Double_t Q0Min=0.01;
  
  Double_t Q0Step=0.01;
  
  cout<<Q0Max<<"  "<<Q0Min<<endl;
  int NVal= (Q0Max-Q0Min)/Q0Step;
  
  cout<<"RootS "<<"  "<<"DissFunc"<<"  "<<"FormFunc"<<endl;
  
  for(int k = 0; k<=NVal; k++)
    {
      Q0[k]=Q0Min+Q0Step*k;
      

      SigmaQ0Val[k]=DissFuncSecond(Q0[k]);
      SigmaQ0Val1[k]=FormFuncSecond(Q0[k]);
            
      cout<<Q0[k]<<"  "<<SigmaQ0Val[k]<<"  "<<SigmaQ0Val1[k]<<endl;
      
    }

  
  TGraph *DissFunc_2 = new TGraph(NVal,Q0,SigmaQ0Val);
  DissFunc_2->SetLineWidth(2);
  DissFunc_2->GetXaxis()->SetTitle("q^{0}");
  DissFunc_2->GetYaxis()->SetTitle("DissFunc");
  new TCanvas;
  gPad->SetTicks();
  DissFunc_2->Draw("APL");


  TGraph *FormFunc_2 = new TGraph(NVal,Q0,SigmaQ0Val1);
  FormFunc_2->SetLineWidth(2);
  FormFunc_2->GetXaxis()->SetTitle("q^{0}");
  FormFunc_2->GetYaxis()->SetTitle("FormFunc");

  new TCanvas;
  gPad->SetTicks();
  FormFunc_2->Draw("APL");
 

  //=============================================== End Compare Diss Functions ================================================//
  



  //=============================================== Graphs to compare Diss rate and for rate =================================//
  
 
  Double_t Temp[1000];

  Double_t TempMax=0.8;
  Double_t TempMin=0.031;
  Double_t TempStep=0.01;
 
  Double_t LambdaD_Para[1000]={0};

  Double_t LambdaD_Org[1000]={0};
  Double_t LambdaF_Org[1000]={0};

  Double_t LambdaD_Khar[1000]={0};
  Double_t LambdaF_Khar[1000]={0};

  Double_t LambdaDBessel[1000]={0};
  Double_t LambdaFBessel[1000]={0};



  Double_t LambdaF_Coll[1000]={0};


  int NTemp= (TempMax-TempMin)/TempStep;

   cout<<"Temp[l]"<<"   "<<"LambdaD_Para[l]"<<"   "<<"LambdaD_Org[l]"<<"   "<<"LambdaD_Khar[l]"<<"   "<<"LambdaDBessel[l]"<<endl;

   //  cout<<" T(GeV) "<<" LambdaD "<<" LambdaF "<<endl;

  for(int l = 0; l<=NTemp; l++)
    {
      Temp[l]=TempMin+TempStep*l;

      
      LambdaD_Para[l]=(0.005*TMath::Exp(9.28*Temp[l])) /hbarc;

      LambdaD_Org[l]=DissRate(Temp[l],1);
      LambdaF_Org[l]=FormRate(Temp[l],1);
      

      //      LambdaD_Khar[l]=DissFuncAvIntPt(Temp[l]);

      LambdaD_Khar[l]= DissFuncAv(2.0, Temp[l]);

      //LambdaF_Khar[l]=(Temp[l]);

      LambdaDBessel[l]=LambdaD_BesselIntZ(Temp[l]);
      LambdaFBessel[l]= LambdaF_BesselIntZ(Temp[l]);
      
      //LambdaDBessel[l]=LambdaD_BesselIntZ_2(Temp[l]);
      //LambdaFBessel[l]= LambdaF_BesselIntZ_2(Temp[l]);

      

      LambdaF_Coll[l]= IntFormFunction2Pt(Temp[l])/(hbarc3);

      cout<<Temp[l]<<"   "<<LambdaD_Para[l]<<"   "<<LambdaD_Org[l]<<"   "<<LambdaD_Khar[l]<<"   "<<LambdaDBessel[l]<<endl;

    }



  TGraph *DissRate_Para = new TGraph(NTemp,Temp,LambdaD_Para);
  DissRate_Para->SetLineWidth(2);
  DissRate_Para->GetXaxis()->SetTitle("T(GeV)");
  DissRate_Para->GetYaxis()->SetTitle("DissRate Para (fm^{2})");
  new TCanvas;
  gPad->SetTicks();
  DissRate_Para->Draw("APL");


  TGraph *DissRate_Org = new TGraph(NTemp,Temp,LambdaD_Org);
  DissRate_Org->SetLineWidth(2);
  DissRate_Org->GetXaxis()->SetTitle("T(GeV)");
  DissRate_Org->GetYaxis()->SetTitle("DissRate Org (fm^{2})");
  new TCanvas;
  gPad->SetTicks();
  DissRate_Org->Draw("APL");



  TGraph *FormRate_Org = new TGraph(NTemp,Temp,LambdaF_Org);
  FormRate_Org->SetLineWidth(2);
  FormRate_Org->GetXaxis()->SetTitle("T(GeV)");
  FormRate_Org->GetYaxis()->SetTitle("FormRate Org (fm^{2})");
  new TCanvas;
  gPad->SetTicks();
  FormRate_Org->Draw("APL");





  TGraph *DissRate_Khar = new TGraph(NTemp,Temp,LambdaD_Khar);
  DissRate_Khar->SetLineWidth(2);
  DissRate_Khar->SetLineColor(2);
  DissRate_Khar->GetXaxis()->SetTitle("T(GeV)");
  DissRate_Khar->GetYaxis()->SetTitle("DissRate Khar (fm^{2})");
  //DissRate_Khar->GetYaxis()->SetRangeUser(0.0,0.4);
  
  new TCanvas;
  gPad->SetTicks();
  DissRate_Khar->Draw("APL");


  return;



  TGraph *DissRate_Bessel = new TGraph(NTemp,Temp,LambdaDBessel);
  DissRate_Bessel->SetLineWidth(2);
  DissRate_Bessel->SetLineColor(4);
  DissRate_Bessel->GetXaxis()->SetTitle("T(GeV)");
  DissRate_Bessel->GetYaxis()->SetTitle("DissRate Bassel (fm^{2})");
  DissRate_Bessel->GetYaxis()->SetRangeUser(0.0,0.4);
  new TCanvas;
  gPad->SetTicks();
  DissRate_Bessel->Draw("APL");

  TGraph *FormRate_Bessel = new TGraph(NTemp,Temp,LambdaFBessel);
  FormRate_Bessel->SetLineWidth(2);
  FormRate_Bessel->SetLineColor(4);
  FormRate_Bessel->GetXaxis()->SetTitle("T(GeV)");
  FormRate_Bessel->GetYaxis()->SetTitle("FormRate Bassel (fm^{2})");
  //FormRate_Bessel->GetYaxis()->SetRangeUser(0.0,0.4);
  new TCanvas;
  gPad->SetTicks();
  FormRate_Bessel->Draw("APL");
  


  TGraph *FormRate_Coll = new TGraph(NTemp,Temp,LambdaF_Coll);
  FormRate_Coll->SetLineWidth(2);
  FormRate_Coll->SetLineColor(9);
  FormRate_Coll->GetXaxis()->SetTitle("T(GeV)");
  FormRate_Coll->GetYaxis()->SetTitle("FormRate Coll (fm^{2})");
  new TCanvas;
  gPad->SetTicks();
  FormRate_Coll->Draw("APL");


  new TCanvas;
  gPad->SetTicks();
  FormRate_Bessel->Draw("APL");
  FormRate_Org->Draw("PLsame");
  FormRate_Coll->Draw("PLsame");

  new TCanvas;
  gPad->SetTicks();
  DissRate_Org->Draw("APL");
  DissRate_Khar->SetLineColor(2);
  DissRate_Khar->Draw("PLsame");
  DissRate_Bessel->SetLineColor(4);
  DissRate_Bessel->Draw("PLsame");
  DissRate_Para->SetLineColor(6);
  DissRate_Para->Draw("PLsame");








  return;











  /*   
  for(int i=0;i<10;i++){
    NpartVal[i]= Npart(CentBin[i],CentBin[i+1]);
    NCollVal[i]=NColl(CentBin[i],CentBin[i+1]);
    
    NJPsi_T[i]=(NCollVal[i]/NCollMB)*Njpsi_0;
    Nccbar_T[i]=(NCollVal[i]/NCollMB)*N_ccbar;
    
    Temp_Cent[i]=T_0*TMath::Power((dNdEtabyNpartby2[i]/dNdEtabyNpartby2[0]),1.0/3); 
    
    Tau_Cent[i]=TempToTau(Temp_Cent[i]);
    
    TauMax=Tau_f;
    TauMin=Tau_Cent[i];
    
    NN = (TauMax-TauMin)/TauStep;
    
    cout<<" cent "<<CentBin[i]<<" - "<<CentBin[i+1]<<endl;
    cout<<" NN "<<NN<<endl;
    cout<<" TauMin "<<TauMin<<" tauMax "<<TauMax<<endl;
    cout<<" TMin "<<Temp_Cent[i] <<" TMax "<<T_0<<endl;

    
    
    for(int j = 0; j<=NN ; j++){
      
      Taue[j]=TauMin+TauStep*j;
      Te[j] = TauToTemp(Taue[j]);
      
      //FRate[j] = FormRate(Te[j],1);
      //FRate[j] =0; 
      //IntFormFunction2Pt(Te[j]);
      

      //Parameterization
      //DRate[j] = 0.005*TMath::Exp(9.28*Te[j])/hbarc;
      //DRate[j] = DissFuncAv(6.5,Te[j]);
      DRate[j] =DissFuncAvIntPt(Te[j]);
      
      
      
      //DRate[j]=LambdaD_BesselIntZ(Te[j]);
      //FRate[j]=LambdaF_BesselIntZ(Te[j]);

      //if(j%10==0)  cout<<" T "<<Te[j]<<" Tau "<<TempToTau(Te[j])<<" For Rate "<<FRate[j]<<" Diss Rate "<<DRate[j]<<" Diss Rate Pt "<<DissFuncAvIntPt(Te[j])
      //	       <<endl;
      
      // cout<< DRate[j]<<"  "<<FRate[j]<<endl;

      
    }
    
    
    MRadius[i] = Radius_Pb*TMath::Sqrt(NpartVal[i]/NpartVal[0]);
    //cout<<" MRadius "<<MRadius[i]<<endl;
    PiR2=pi*MRadius[i]*MRadius[i];
    
    // Final expression
    Double_t intg1, e_tauf, intg2, N_jpsi;
    
    
    
    
    intg1 = Integral1(NN);
    e_tauf = exp(-intg1);
    intg2 =Integral2();
  
    //cout<<" Integral1 =  " << intg1 << endl;
    //cout<<" e_tauf =  " << e_tauf << endl;
    //cout<<" Integral2 =  " << intg2 <<endl;
    
    N_jpsi = e_tauf * NJPsi_T[i] + e_tauf * (Nccbar_T[i]*Nccbar_T[i]/PiR2) * intg2 *hbarc*hbarc;  
    
    //Supp_T[i]=e_tauf * NJPsi_T[i];
    //ReGen_T[i]=e_tauf * (Nccbar_T[i]*Nccbar_T[i]/PiR2) * intg2 ; 

    Supp_T[i]=(e_tauf*NJPsi_T[i])/NJPsi_T[i] ;
    ReGen_T[i]=(e_tauf*Nccbar_T[i]*Nccbar_T[i]*intg2*hbarc*hbarc)/PiR2; 
    Raa[i]=(N_jpsi/NJPsi_T[i]);

    

    cout<<"intg2: "<<intg2<<endl;
    cout<<"Supp: "<<Supp_T[i]<<" ReGen  "<<ReGen_T[i]<<" Raa "<<Raa[i]<<endl;

    TGraph *FR2 = new TGraph(NN, Taue, FRate);
     
    TGraph *DR2 = new TGraph(NN, Taue, DRate);
    DR2->GetYaxis()->SetTitle("Rate");
    DR2->GetXaxis()->SetTitle("#tau(fm)");
    DR2->GetYaxis()->SetRangeUser(0.00001,10.0);
 
    if(i==0){
      new TCanvas;
      gPad->SetLogy();
      gPad->SetTicks();
    }
    
    DR2->SetLineColor(2);
    DR2->SetLineWidth(2);

    FR2->SetLineColor(1);
    FR2->SetLineWidth(2);

    if(i==0)
      {
	DR2->Draw("ALP");
	FR2->Draw("LPsame");
      }
    
    else{
      DR2->Draw("LPsame");
      FR2->Draw("LPsame");
    }
    //lcat->Draw("same");


  }

  //================== Centrality dependent loop ends ====================================//
  
  TGraph *GrfRaa = new TGraph(10, NpartVal, Raa);
  GrfRaa->GetYaxis()->SetTitle("J/#psi R_{AA}");
  GrfRaa->GetXaxis()->SetTitle("N_{part}");
  new TCanvas;
  gPad->SetTicks();
  
  GrfRaa->SetLineColor(2);
  GrfRaa->SetLineWidth(2);
  GrfRaa->Draw("ALP");
  

  new TCanvas;
  gPad->SetTicks();
  RaaCMSData->Draw("AP");
  for(int i=0;i< NCentBins;i++)
    {
      BoxRaaCent[i]->Draw("same");
    }
  GrfRaa->Draw("Lsame");
  



  
  TGraph *GrfDnDeta = new TGraph(10, NpartVal, dNdEtabyNpartby2);
  GrfDnDeta->GetYaxis()->SetTitle("(dN/d#eta)/(N_{part}/2)");
  GrfDnDeta->GetXaxis()->SetTitle("N_{part}");

  new TCanvas;
  gPad->SetTicks();
  GrfDnDeta->SetLineColor(2);
  GrfDnDeta->SetLineWidth(2);
  GrfDnDeta->Draw("ALP");
  

  TGraph *GrfTemp = new TGraph(10, NpartVal,Temp_Cent);
  GrfTemp->GetYaxis()->SetTitle("T (GeV)");
  GrfTemp->GetXaxis()->SetTitle("N_{part}");

  new TCanvas;
  gPad->SetTicks();
  GrfTemp->SetLineColor(2);
  GrfTemp->SetLineWidth(2);
  GrfTemp->Draw("ALP");
  

  TGraph *GrfSupp = new TGraph(10, NpartVal, Supp_T);
  GrfSupp->GetXaxis()->SetTitle("N_{part}");
  GrfSupp->GetYaxis()->SetTitle("Suppression");
  GrfSupp->SetLineColor(2);
  GrfSupp->SetLineWidth(2);

  new TCanvas;
  gPad->SetTicks();
  GrfSupp->Draw("ALP");  


  TGraph *GrfReGen = new TGraph(10, NpartVal, ReGen_T);
  GrfReGen->GetXaxis()->SetTitle("N_{part}");
  GrfReGen->GetYaxis()->SetTitle("ReGenration");
  GrfReGen->SetLineColor(4);
  GrfReGen->SetLineWidth(1);
  new TCanvas;
  gPad->SetTicks();
  GrfReGen->Draw("ALP");  

  
  new TCanvas;
  gPad->SetTicks();
  GrfReGen->Draw("ALP");  
  GrfSupp->Draw("LP");
  
  //=============================================================================================//
  //=============================================================================================//
  
  Double_t XRan[20000];  
  Double_t DelFunc[20000];  
  
  Double_t x=0;
  Double_t xmin=-1.0;
  Double_t xmax=1.0;
  
  Double_t xstep=0.0001;
  
  int NStep=0;
  
  NStep=(xmax-xmin)/xstep;
  
  

  Double_t RanNo;
  Double_t xRan;

  Double_t sum1=0;
  Double_t sum2=0;
  

  for(int i=0;i<=NStep;i++)
    {
     
      RanNo=gRandom->Rndm();
      xRan=xmin+(xmax-xmin)*RanNo;
      
      x=xmin+i*xstep;
      //sum=sum+TMath::Cos(x)*DeltaFunction(x);
      sum1=sum1+DeltaFunction(x);
      sum2=sum2+DeltaFunction(xRan);

      //cout<<x<<" 1 "<<DeltaFunction(x)<<endl;
      cout<<xRan<<"  "<<DeltaFunction(xRan)<<endl;
      XRan[i]=xRan;
      DelFunc[i]=DeltaFunction(xRan);
    }
  

  //cout<<" integral1 "<<sum1*xstep<<endl;
  cout<<" NTrials "<<NStep<<endl;  
  cout<<" integral2 "<<(sum2*(xmax-xmin))/NStep<<endl;
  
  TGraph *GrfDeltaFunc = new TGraph(NStep,XRan,DelFunc);
  GrfDeltaFunc->GetXaxis()->SetTitle("Delta Function");

  GrfDeltaFunc->SetLineWidth(2);
  
  new TCanvas;
  gPad->SetTicks();
  GrfDeltaFunc->SetMarkerStyle(20);
  GrfDeltaFunc->Draw("AP");
  */    
}

/////////////////////////////////////////////////////////////////////////////////////
/////////////////////  Main Program Ends ////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////




//Formation Rate

Double_t FormRate(Double_t xx, int flag) {
  
  Double_t Temp;
  Temp = T_0 * TMath::Power( (Tau_0/xx),1.0/3.0);
  if(flag==1) Temp = xx;
  
  Double_t PMin=0.0001;
  Double_t PMax=2.0;

  Double_t ThetaMin=0.0001;
  Double_t ThetaMax=TMath::Pi();

  Double_t PhiMin=0.0001;
  Double_t PhiMax=2*TMath::Pi();

  int nTrials = 10000;

  Double_t P1,P2,Theta1,Theta2,Phi1,Phi2;

  Double_t Sum = 0;
  Double_t Sum1=0;

  for(int i =1; i<= nTrials; i++) {
      
    Double_t RanNo1,RanNo2,RanNo3, RanNo4, RanNo5, RanNo6;
    
    RanNo1=gRandom->Rndm();
    RanNo2=gRandom->Rndm();
    RanNo3=gRandom->Rndm();
    RanNo4=gRandom->Rndm();
    RanNo5=gRandom->Rndm();
    RanNo6=gRandom->Rndm();
    
    P1=PMin+(PMax-PMin)*RanNo1;
    P2=PMin+(PMax-PMin)*RanNo2;
    
    Theta1= ThetaMin + (ThetaMax -ThetaMin )*RanNo3;
    Theta2= ThetaMin + (ThetaMax -ThetaMin )*RanNo4;
    
    Phi1= PhiMin + (PhiMax -PhiMin )*RanNo5;
    Phi2= PhiMin + (PhiMax -PhiMin )*RanNo6;

    Sum = Sum + FormFun(P1,P2,Theta1,Theta2,Phi1,Phi2,Temp);
    Sum1 = Sum1 + FormFunDenoFunc(P1,P2,Theta1,Theta2,Temp);

  }
  
  Double_t ForRate =0; 
  ForRate  = (PMax- PMin)*(PMax- PMin)*(ThetaMax-ThetaMin)*(ThetaMax-ThetaMin)*(PhiMax-PhiMin)*(PhiMax-PhiMin)*Sum/nTrials;
  Double_t ForRateDeno =0;
  ForRateDeno  = (PMax- PMin)*(PMax- PMin)*(ThetaMax-ThetaMin)*(ThetaMax-ThetaMin)*(PhiMax-PhiMin)*(PhiMax-PhiMin)*Sum1/nTrials;

  return (ForRate/ForRateDeno);
}



Double_t FormFun(Double_t p1, Double_t p2, Double_t theta1, Double_t theta2, Double_t phi1, Double_t phi2, Double_t T)
{

  Double_t p1dotp2 = p1*p2*(TMath::Sin(theta1)*TMath::Sin(theta2)*TMath::Cos(phi1-phi2) + TMath::Cos(theta1)*TMath::Cos(theta2));
  Double_t qSquare = p1*p1 + p2*p2 - 2 * p1dotp2;
  // ccbar to Jpsi cross section

  Double_t FJPsi = 0;
  if(qSquare > 0 && (4*MassD*MassD - 4*MassC*MassC - qSquare) > 0) FJPsi = 0.01*sigmapp ; // sigmapp ???

  // Relative Velocity 
  Double_t m = ReducedMass;
  Double_t m4 = m*m*m*m;

  Double_t Num = 0;
  if( (p1dotp2*p1dotp2 -  m4)  > 0 )  Num = TMath::Sqrt(p1dotp2*p1dotp2 - m4);
  Double_t Deno =  TMath::Sqrt(p1*p1 + MassC*MassC) * TMath::Sqrt(p2*p2 + MassC*MassC) ;

  Double_t RelVel = Num/Deno; 

  Double_t allfactors = p1*p1*p2*p2*TMath::Sin(theta1)*TMath::Sin(theta2)* RelVel *FJPsi* FCharm(p1,T) * FCharm(p2,T);
  return allfactors;
}


Double_t FCharm(Double_t p1, Double_t T)
{
  Double_t fc = 6.0 /( 1.0 +TMath::Exp( TMath::Sqrt(p1*p1+MassC*MassC) )/T);
  return fc;
}

Double_t FormFunDenoFunc(Double_t p1, Double_t p2, Double_t theta1, Double_t theta2,Double_t T)
{

   Double_t allfactors = p1*p1*p2*p2*TMath::Sin(theta1)*TMath::Sin(theta2)*FCharm(p1,T)*FCharm(p2,T);
   return allfactors;
   
}


///////////////////////////////////////////////////////////
// Dissociation Rate

Double_t DissRate(Double_t xx, int flag) {

  Double_t Temp;
  Temp = T_0 * TMath::Power( (Tau_0/xx),1.0/3.0);
  if(flag==1) Temp = xx;

  Double_t PMin=0.0001;
  Double_t PMax=2.0;

  Double_t ThetaMin=0.0001;
  Double_t ThetaMax=TMath::Pi();

  Double_t PhiMin=0.0001;
  Double_t PhiMax=2*TMath::Pi();

  int nTrials = 10000;

  Double_t P1,P2,Theta1,Theta2,Phi1,Phi2;
  Double_t P11,P21,Theta11,Theta21;

  Double_t Sum = 0;
  Double_t Sum1 = 0;

  for(int i =1; i<= nTrials; i++) {
      
    Double_t RanNo1,RanNo2,RanNo3, RanNo4, RanNo5, RanNo6;
    Double_t RanNo11,RanNo21,RanNo31, RanNo41;
    
    RanNo1=gRandom->Rndm();
    RanNo2=gRandom->Rndm();
    RanNo3=gRandom->Rndm();
    RanNo4=gRandom->Rndm();
    RanNo5=gRandom->Rndm();
    RanNo6=gRandom->Rndm();

    RanNo11=gRandom->Rndm();
    RanNo21=gRandom->Rndm();
    RanNo31=gRandom->Rndm();
    RanNo41=gRandom->Rndm();
    
    
    P1=PMin+(PMax-PMin)*RanNo1;
    P2=PMin+(PMax-PMin)*RanNo2;
    
    Theta1= ThetaMin + (ThetaMax -ThetaMin )*RanNo3;
    Theta2= ThetaMin + (ThetaMax -ThetaMin )*RanNo4;
    
    Phi1= PhiMin + (PhiMax -PhiMin )*RanNo5;
    Phi2= PhiMin + (PhiMax -PhiMin )*RanNo6;

    P11=PMin+(PMax-PMin)*RanNo11;
    P21=PMin+(PMax-PMin)*RanNo21;
    
    Theta11= ThetaMin + (ThetaMax -ThetaMin )*RanNo31;
    Theta21= ThetaMin + (ThetaMax -ThetaMin )*RanNo41;
        
    Sum = Sum + DissFun(P1,P2,Theta1,Theta2,Phi1,Phi2,Temp);
    Sum1 = Sum1 + DissFunDenoFunc(P11,P21,Theta11,Theta21,Temp);
  }
  
  Double_t DissRate =  (PMax- PMin)*(PMax- PMin)*(ThetaMax-ThetaMin)*(ThetaMax-ThetaMin)*(PhiMax-PhiMin)*(PhiMax-PhiMin)*Sum/nTrials;
  Double_t DissRate1 = (PMax- PMin)*(PMax- PMin)*(ThetaMax-ThetaMin)*(ThetaMax-ThetaMin)*(PhiMax-PhiMin)*(PhiMax-PhiMin)*Sum1/nTrials;
  
   return DissRate/DissRate1/hbarc;

  

}


Double_t DissFun(Double_t p1, Double_t p2, Double_t theta1, Double_t theta2, Double_t phi1, Double_t phi2, Double_t T)
{
  
  Double_t p1dotp2 = p1*p2*(TMath::Sin(theta1)*TMath::Sin(theta2)*TMath::Cos(phi1-phi2) + TMath::Cos(theta1)*TMath::Cos(theta2));
  Double_t Num = TMath::Abs(p1dotp2);    // To be checked
  Double_t Deno =  TMath::Sqrt(p1*p1 + MassJPsi*MassJPsi) * p2;
  Double_t RelVel = Num/Deno; 

  Double_t qSquare = p1*p1 + p2*p2 - 2 * p1dotp2;
  
  Double_t allfactors = p1*p1*p2*p2*TMath::Sin(theta1)*TMath::Sin(theta2)* RelVel * LambdaD(qSquare) * FGluon(p1,T) * FJPsi(p2,T);
  return allfactors;
  
}

Double_t LambdaD(Double_t qSquare)
{
  
  Double_t BEJPsi = 0.64; //GeV

  //Double_t lambdaDConstt= (2.0*pi*32.0*32.0/27.0)*TMath::Sqrt(2*ReducedMass/BEJPsi)*(1.0/(4*ReducedMass*ReducedMass));
  Double_t lambdaDConstt= (2.0*pi*32.0*32.0/27.0)*TMath::Sqrt(2*MassC/BEJPsi)*(1.0/(4*MassC*MassC));
  

  Double_t lambdaD =0.0;

  if(qSquare < BEJPsi*BEJPsi) return lambdaD;

  Double_t p=TMath::Sqrt(qSquare);
  Double_t fac = TMath::Power((p/BEJPsi-1.0), 1.5);
  
  lambdaD = lambdaDConstt * fac / TMath::Power(p/BEJPsi, 5.0);
  return lambdaD;
}


Double_t FJPsi(Double_t p, Double_t T)
{
  Double_t gi=3;
  Double_t fjpsi = gi / (TMath::Exp(TMath::Sqrt(p*p + MassJPsi*MassJPsi)/T) -1);
  return fjpsi;
}

Double_t FGluon(Double_t p, Double_t T)
{
  Double_t gi=16;
  Double_t fg = gi / (TMath::Exp(p/T)-1);
  return fg;
}

Double_t DissFunDenoFunc(Double_t p1, Double_t p2, Double_t theta1, Double_t theta2,Double_t T)
{
  Double_t allfactors = p1*p1*p2*p2*TMath::Sin(theta1)*TMath::Sin(theta2)*FGluon(p1,T)*FJPsi(p2,T);
  return allfactors;
}




Double_t Integral1(int N1)
{
  
  Double_t sum=0;
  for (int i= 0; i<=N1; i++) {
    
    //cout<<" int 1 "<<DRate[i]<<endl;
    sum = sum +DRate[i];
  }
  return sum*TauStep;
}





Double_t Integral2()
{
  Double_t sum=0;
  
  for (int i =0; i<=NN; i++) {
    
    Double_t fun = FRate[i]/(Taue[i]*exp(-Integral1(i)));
    sum = sum + fun;
  }
  return sum*TauStep;
}    











//============================== Function from Kharz paper =====================================//



Double_t DissFuncSecond(Double_t q0)
{
  Double_t Sigmaq0Constt=0;
  Double_t Sigmaq0=0;


  Sigmaq0Constt=(2.0*pi*1024.0)/(27.0*TMath::Power(mQ,3.0/2.0)*TMath::Power(epsilon0,1.0/2.0));
  
  if(q0/epsilon0 >1.0){Sigmaq0=(Sigmaq0Constt*TMath::Power( ((q0/epsilon0)-1) ,3.0/2.0)) / TMath::Power((q0/epsilon0),5.0)  ;}else{Sigmaq0=0;}
  
  return GeVMinus2ToMiliBarn*Sigmaq0;


}







Double_t FormFuncSecond(Double_t q0)
{
  Double_t RootS=Q0ToRootS(q0);
  Double_t S=TMath::Power(RootS,2);
  Double_t Value=0;
  Double_t SigmaD=DissFuncSecond(q0);
  Double_t Num=0;
  Double_t Deno=0;
  Num=TMath::Power((S-(MassJPsi*MassJPsi)),2);
  Deno=S*(S-4*mQ*mQ);
  Value=48*SigmaD*Num/(36*Deno);
  return Value;

}




Double_t DissFuncSecondRootS(Double_t RootS)
{
  Double_t S=RootS*RootS;
  Double_t Sigmaq0Constt=0;
  Double_t Sigmaq0=0;
  Double_t xx=0;
  xx=(S-TMath::Power(MassJPsi,2))/(2*epsilon0*MassJPsi);

  Sigmaq0Constt=(2.0*pi*1024.0)/(27*TMath::Power(mQ,3.0/2.0)*TMath::Power(epsilon0,1.0/2.0));
  if(xx>1.0)Sigmaq0=Sigmaq0Constt*TMath::Power((xx-1),3.0/2.0)/TMath::Power(xx,5.0);
  
  return GeVMinus2ToMiliBarn*Sigmaq0;


}




Double_t FormFuncSecondRootS(Double_t RootS)
{
  Double_t S=TMath::Power(RootS,2.0);
  Double_t Value=0;
  Double_t SigmaD=DissFuncSecondRootS(RootS);
  Double_t Num=0;
  Double_t Deno=0;
  Num=TMath::Power((S-(MassJPsi*MassJPsi)),2.0);
  Deno=S*(S-4*mQ*mQ);
  if(S>4*mQ*mQ) Value=(48*SigmaD*Num)/(36*Deno);
  return Value;
  
}























//  Xu and Kharjeev /////////////////////////////////////////////////

Double_t DissFuncAvIntPt(Double_t T)
{
  Double_t Ptmin=0.1;
  Double_t Ptmax=30.0;
  Double_t Ptstep=0.1;
  int NN_Pt=(Ptmax-Ptmin)/Ptstep;
  Double_t sum=0;
    
  for(int i=0;i<NN_Pt;i++) {
    double Pt=Ptmin+i*Ptstep;
    double PtVal=Jpsi_Pt->GetBinContent(Jpsi_Pt->FindBin(Pt));
    sum=sum+PtVal*DissFuncAv(Pt,T);
    
    }
  return sum*Ptstep;
}


Double_t DissFuncAv(Double_t Pt, Double_t T)
{
  Double_t mT=TMath::Sqrt(Pt*Pt+MassJPsi*MassJPsi);
  //  Double_t Rhog=2.0*8.0*1.202*TMath::Power(T,3)/(pi*pi);
  
  double fac1=pow(8.0/3.0,3.0)*(pi/1.202)*pow(MassJPsi,2.0)*pow(epsilon0/mQ,1.5);
  double fac2=1.0/(Pt*mT*T*T*T);

  int nmin = 1;
  int nmax = 20;
  int nstep = 1;
  int NN_N=(nmax-nmin)/nstep;

  Double_t sum=0;

  for(int i=0;i<NN_N;i++) {
    int n=nmin+i*nstep;
    sum=sum+DissFuncIntX(Pt,T,n);
  }
  
  double Integral= sum*nstep;

  return fac1*fac2*Integral*hbarc2;
}


Double_t DissFuncIntX(Double_t Pt, Double_t T, Double_t n)
{
  Double_t xmin=1.0;
  Double_t xmax=5.0;
  Double_t xstep=0.01;
  int NStep=(xmax-xmin)/xstep;
  Double_t sum=0;

  for(int i=0;i <NStep;i++){
    double x=xmin+i*xstep;
    sum=sum+DissFuncX(Pt,T,n,x);
    
  }
  return sum*xstep*T/n;
}

Double_t DissFuncX(Double_t Pt, Double_t T, Double_t n, Double_t x)
{
  Double_t mT=TMath::Sqrt(Pt*Pt+MassJPsi*MassJPsi);

  double an1=TMath::Exp(-(n*epsilon0/T)*(mT-Pt)*x/MassJPsi);
  double an2=TMath::Exp(-(n*epsilon0/T)*(mT+Pt)*x/MassJPsi);
  double Func= pow(x-1, 1.5)/(x*x*x*x)*(an1-an2);

  return Func;
}

  



//====================================================================================//
//======================== Bassel Starts =============================================//
//====================================================================================//
Double_t AlphaJPsi(Double_t T)
{
  Double_t Value=0;
  Value=MassJPsi/T;
  return Value;
}

Double_t AlphaC(Double_t T)
{
  Double_t Value=0;
  Value=mQ/T;
  return Value;
}


Double_t LambdaD_Bessel(Double_t Z, Double_t T)
{
    
  Double_t const1=0;
  Double_t const2=0;

  Double_t part1=0;
  Double_t part2=0;
  Double_t xx=0;
  Double_t part3=0; 
  
  Double_t Value=0;
  Double_t ValueFm2=0;
  Double_t Valuemb=0;
  Double_t Rhog_Bassel=2.0*8.0*1.202*TMath::Power(T,3)/(pi*pi); 

 const1=1.0/(8.0*TMath::Power(AlphaJPsi(T),2)*TMath::BesselK(2,AlphaJPsi(T)));
  
  const2=(2.0*pi/3.0)*TMath::Power(32.0/3.0,2.0)*(1.0/(TMath::Power(AlphaJPsi(T),3.0/2.0)*TMath::Power(T,3.0/2.0)*TMath::Power(epsilon0,1.0/2.0)));

  part1=TMath::Power((Z*Z-TMath::Power(AlphaJPsi(T),2)),2)  ;

  part2=TMath::BesselK(1,Z);

  xx=(Z*Z*T*T-TMath::Power(AlphaJPsi(T),2)*T*T)/(2*epsilon0*AlphaJPsi(T)*T);
  
  if(xx>1){part3=TMath::Power((xx-1),3.0/2.0)/TMath::Power(xx,5.0);}

  
  //bipolar
  Value=const1*const2*part1*part2*part3;
  ValueFm2=Value*(hbarc*hbarc);
  Valuemb= ValueFm2*10.0;
  
  return (Valuemb*Rhog_Bassel)/hbarc;


}



Double_t LambdaD_BesselIntZ(Double_t T)
{
  //Double_t Tmax=0.616;

  Double_t Z=0;
  Double_t Zmin=TMath::Max(AlphaC(T)+AlphaC(T),AlphaJPsi(T));
  Double_t Zmax=100.0;
  Double_t Zstep=0.1;
  int NStep=0;
  //cout<<"Zmax :"<<Zmax<<" Zmin: "<<Zmin<<endl;
  NStep=(Zmax-Zmin)/Zstep;
  Double_t sum=0;
  //cout<<"NStep "<<NStep<<endl;
  // cout<<" Z "<<" T "<<" LamdaDBessel  "<<endl;
  for(int i=0;i<=NStep;i++)
    {
      Z=Zmin+i*Zstep;
      sum=sum+LambdaD_Bessel(Z,T);
      //cout<<Z<<"  "<<T<<"  "<<LambdaD_Bessel(Z,T)<<endl;
    }
  return sum*Zstep;
}

Double_t LambdaF_BesselIntZ(Double_t T)
{
  Double_t LambdaD_Bessel=0;
  Double_t Constt=0;
  Double_t Part1;
  Double_t Part2;
  Double_t Value=0;

  LambdaD_Bessel=LambdaD_BesselIntZ(T);
  Constt=(48.0/36.0);
  Part1=2.0*TMath::Power(AlphaJPsi(T),2.0)/TMath::Power(AlphaC(T),4.0);
  Part2=TMath::BesselK(2,AlphaJPsi(T))/TMath::Power(TMath::BesselK(2,AlphaC(T)),2.0);
  Value=Constt*Part1*Part2*LambdaD_Bessel;
  return Value;
}




Double_t LambdaD_BesselIntZ_2(Double_t T)
{
  
  Double_t Z=0;
  Double_t Zmin=TMath::Max(AlphaC(T)+AlphaC(T),AlphaJPsi(T));
  Double_t Zmax=100.0;
  Double_t Zstep=0.1;
  int NStep=0;
 
  NStep=(Zmax-Zmin)/Zstep;
  Double_t sum=0;
  for(int i=0;i<=NStep;i++)
    {
      Z=Zmin+i*Zstep;
      sum=sum+LambdaD_BesselIntgrant(Z,T);
    }
  return sum*Zstep;
}


Double_t LambdaD_BesselIntgrant(Double_t Z, Double_t T)
{
  Double_t SigmaDiss=0.3;//fm2 
  Double_t Constt=1.0/(8.0*AlphaJPsi(T)*AlphaJPsi(T)*TMath::BesselK(2,AlphaJPsi(T)));
  Double_t Part1=(Z*Z - AlphaJPsi(T)*AlphaJPsi(T));
  Double_t Part2=TMath::BesselK(1,Z);

  Double_t Value=0;
  Value=Constt*Part1*Part1*Part2*SigmaDiss;
  return Value;


}


Double_t LambdaF_BesselIntZ_2(Double_t T)
{
  Double_t LambdaD_Bessel=0;
  Double_t Constt=0;
  Double_t Part1;
  Double_t Part2;
  Double_t Value=0;

  LambdaD_Bessel=LambdaD_BesselIntZ_2(T);
  Constt=(48.0/36.0);
  Part1=2.0*TMath::Power(AlphaJPsi(T),2.0)/TMath::Power(AlphaC(T),4.0);
  
  //cout<<"AlphaJpsi "<<AlphaJPsi(T)<<" AlphaC "<<AlphaC(T)<<endl;

  Part2=TMath::BesselK(2,AlphaJPsi(T))/ (TMath::BesselK(2,AlphaC(T))*TMath::BesselK(2,AlphaC(T)));
  
  Value=Constt*Part1*Part2*LambdaD_Bessel;
  //cout<<Part1<<" part2-> "<<Part2<<"  "<<LambdaD_Bessel<<endl;
  return Value;
}










//====================== Formation rate from Coaleses model ============================//



Double_t DeltaFunction(Double_t x)
{
  Double_t Epsilon_Delta=0.2;
  Double_t Value=0;
  Value=TMath::Exp(-x*x/(Epsilon_Delta*Epsilon_Delta))/(Epsilon_Delta*TMath::Sqrt(pi));
  return Value;

}





Double_t DeltaFunctionArg1(Double_t Pt, Double_t Pt1, Double_t Pt2, Double_t Phi, Double_t Phi1, Double_t Phi2)
{
  Double_t Value=0;
  Value= (Pt*TMath::Cos(Phi)) - (Pt1*TMath::Cos(Phi1)) - (Pt2*TMath::Cos(Phi2));
  return Value;
}


Double_t DeltaFunctionArg2(Double_t Pt, Double_t Pt1, Double_t Pt2, Double_t Phi, Double_t Phi1, Double_t Phi2)
{
  Double_t Value=0;
  Value= (Pt*TMath::Sin(Phi)) - (Pt1*TMath::Sin(Phi1)) - (Pt2*TMath::Sin(Phi2));
  return Value;
}

Double_t Mt1(Double_t Pt, Double_t M)
{
  Double_t Value=0;
  Value=TMath::Sqrt((Pt*Pt)+(M*M));
  return Value;
}


Double_t Mt2(Double_t Pt, Double_t Pt1, Double_t Phi, Double_t Phi1, Double_t M)
{
  Double_t Value=0;
  Value=TMath::Sqrt( M*M + Pt*Pt + Pt1*Pt1 - 2*Pt*Pt1*TMath::Cos(Phi-Phi1) );
  return Value;
}




Double_t ThetaFunction(Double_t x)
{  
  Double_t Value=0;
  if(x>0){Value=1;}
  else{Value=0;}
  return Value;
}

Double_t ThetaFunctionArg(Double_t Pt, Double_t Pt1, Double_t Phi, Double_t Phi1)
{
  Double_t Mtt1=Mt1(Pt1,MassC);
  Double_t Mtt2=Mt2(Pt,Pt1,Phi,Phi1,MassC);
  
  Double_t Value=0;
  
  Double_t Part1=0;
  Double_t Part2=0;
  
  Part1=4*Pt1*Pt1+Pt*Pt-4*Pt1*Pt*TMath::Cos(Phi-Phi1);
  Part2=TMath::Power((Mtt1-Mtt2),2);
  
  Value= Part1 + Part2;
  
  return Value;
}





Double_t QuarkDiss(Double_t Mt,Double_t T)
{
  Double_t Value=0;
  Value= Mt*TMath::Exp(-(Mt/T));
  return Value;
  
}





Double_t FormFunction2(Double_t Pt, Double_t Pt1, Double_t Phi, Double_t Phi1,Double_t T)
{
  Double_t DeltaY=1;
  Double_t Rt=8.3;
  Double_t DeltaP=0.24;
  Double_t DeltaPCube=DeltaP*DeltaP*DeltaP;

  Double_t Constant=0;
  
  Double_t Part1=0;
  Double_t Part2=0;
  
  Double_t ThetaIn=0;
  Double_t Thetak=0;
  
  
  Double_t Value=0;

  Constant=(3.0*TempToTau(T)*Rt*Rt)/(32*pi3*DeltaY*DeltaPCube);
  
  Part1=Pt1*QuarkDiss(Mt1(Pt1,MassC),T);
  Part2=QuarkDiss(Mt2(Pt,Pt1,Phi,Phi1,MassC),T);
  
  
  ThetaIn= TMath::Power(DeltaP,2) - ThetaFunctionArg(Pt,Pt1,Phi,Phi1);

  Thetak=ThetaFunction(ThetaIn);
  Value=Pt*Constant*Part1*Part2*Thetak;

  return Value;
}


Double_t IntFormFunction2(Double_t Pt, Double_t T)
{
  Double_t PtMin=0.001;
  Double_t PtMax=4.0;

  Double_t PhiMin=0.0001;
  Double_t PhiMax=2*TMath::Pi();

  int nTrials = 5000;

  Double_t Pt1,Phi,Phi1;
  Double_t Sum = 0;
 

  for(int i =1; i<= nTrials; i++) {
      
    Double_t RanNo1,RanNo2,RanNo3;
        
    RanNo1=gRandom->Rndm();
    RanNo2=gRandom->Rndm();
    RanNo3=gRandom->Rndm();
            
    Pt1=PtMin+(PtMax-PtMin)*RanNo1;
    Phi= PhiMin + (PhiMax -PhiMin )*RanNo2;
    Phi1= PhiMin + (PhiMax -PhiMin )*RanNo3;
   
    Sum = Sum + FormFunction2(Pt,Pt1,Phi,Phi1,T);
    //cout<<" Sum "<<Sum<<endl;  

  }
  
  Double_t Value = ( (PtMax- PtMin)*(PhiMax-PhiMin)*(PhiMax-PhiMin)*Sum )/nTrials;
 
  return Value;


}


Double_t IntFormFunction2Pt(Double_t T)
{

  Double_t Pt;
  Double_t Ptmin=0.01;
  Double_t Ptmax=5.0;
  Double_t Ptstep=0.1;
  int NStep=0;
  NStep=(Ptmax-Ptmin)/Ptstep;
  Double_t sum=0;
  
  for(int i=0;i<=NStep;i++)
    {
      Pt=Ptmin+i*Ptstep;
      sum=sum+IntFormFunction2(Pt,T);
    }
  
  return sum*Ptstep;
  
}

//========================================= Coalense ends ===================================//


Double_t TempToTau(Double_t Temp) 
{
  Double_t Tau=0;
  Tau = TMath::Power(T_0/Temp,3)*Tau_0;  
  return Tau;
}


Double_t TauToTemp(Double_t Tau) 
{
  Double_t Temp=0;
  Temp = T_0*TMath::Power(Tau_0/Tau,1.0/3);  
  return Temp;
}


Double_t Q0ToRootS(Double_t q0)
{
  Double_t Value=0;
  Value=MassJPsi*(2*q0+MassJPsi);
  return TMath::Sqrt(Value);
}

Double_t RootSToQ0(Double_t RootS)
{
  Double_t Value=0;
  Double_t S=RootS*RootS;
  Value=(S/(2*MassJPsi))-(MassJPsi/2);
  return Value;
}










//////////////////////////////////////////////////////////////////////////////

//================================== Integral of gluon diss function to check ============================================//

Double_t RhoG(Double_t T) {

  Double_t PMin=0.0001;
  Double_t PMax=50.0;

  Double_t ThetaMin=0.0001;
  Double_t ThetaMax=TMath::Pi();

  Double_t PhiMin=0.0001;
  Double_t PhiMax=2*TMath::Pi();

  int nTrials = 1000000;
  Double_t Sum = 0;

  for(int i =1; i<= nTrials; i++) {
     
    Double_t RanNo1=gRandom->Rndm();
    Double_t RanNo2=gRandom->Rndm();
    
    Double_t p = PMin+(PMax-PMin)*RanNo1;
    Double_t theta = ThetaMin + (ThetaMax -ThetaMin )*RanNo2;
    
    Sum = Sum + p*p*TMath::Sin(theta)*FGluon(p,T);
  }
  
  Double_t rhog = (PMax- PMin)*(ThetaMax-ThetaMin)*(PhiMax-PhiMin)*Sum/nTrials;
  return rhog;
}





Double_t Taa(int BinLow, int BinHigh)
{
  
  Double_t TaaArray[40]={27.3103,24.4927,21.6936,19.2464,17.1594,15.3194,13.4626,11.9694,
		       10.5705,9.2730,8.1549,7.1335,6.2273,5.4164,4.6766,4.0366,3.4565,
		       2.9481,2.4842,2.1047,1.7585,1.4602,1.2177,0.9922,0.8132,0.6618,
		       0.5300,0.4268,0.3407,0.2688,0.2123,0.1665,0.1306,0.1001,0.0802,
		       0.0583,0.0479,0.0378,0.0331,0.0276};

  
  Double_t sum=0;
  
  for(int i=BinLow;i<BinHigh;i++){
    sum+=TaaArray[i];
  }
  
  Double_t TaaAv = sum/(BinHigh-BinLow);

  return TaaAv;
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



Double_t Comp()
{
  double Px1=0.0,Py1=0.0,Pz1=2.0;
  double m1=0.0;
  double P1=TMath::Sqrt(Px1*Px1+Py1*Py1+Pz1*Pz1);
  double E1=TMath::Sqrt(P1*P1+m1*m1);
  double beta1 = P1/E1;

  double Px2=0.0,Py2=0.0,Pz2=-2.0;
  double m2=0.0;
  double P2=TMath::Sqrt(Px2*Px2+Py2*Py2+Pz2*Pz2);
  double E2=TMath::Sqrt(P2*P2+m2*m2);
  double beta2 = P2/E2;
  cout << beta1 <<"    "  << beta2 << endl;

  double p1p2 = (Px1*Px2 + Py1*Py2 + Pz1*Pz2);

  cout << "p1.p2 = " << p1p2 << endl;

  double Value1 = (E1*E2 - p1p2)/(E1*E2);

  cout << Value1 << endl;

  double m = 0;
  if (m1+m2 > 0)  m = m1*m2/(m1 + m2);
  double Value2 = TMath::Sqrt(p1p2*p1p2-m*m*m*m)/(E1*E2);

  cout << Value2 << endl;

  return 0;
}
