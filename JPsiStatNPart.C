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


double NDOpenPlus();
double NDOpenMinus();
double NDJpsi();

double NDPiPlus();
double NDPiMinus();
double NDKPlus();
double NDKMinus();
double NDPPlus();
double NDPMinus();
double NDDsPlus();
double NDDsMinus();
double NDLambda();
double NDLambdabar();
double NDLambdac();
double NDLambdacbar();

Double_t jpsistat(Double_t N_ccbar, Double_t N_ch);
Double_t JpsiStatCanonical(Double_t N_ccbar, Double_t N_ch);
Double_t Gamma_CFunc(Double_t N_ccbar, Double_t N_ch, Double_t x);

Double_t Npart(int BinLow, int BinHigh);
Double_t NColl(int BinLow, int BinHigh);

const double hbarc = 0.197327;
const double hbarc3 = hbarc*hbarc*hbarc;
const double pi = TMath::Pi();
const double pi3 = pi*pi*pi;
/*
//SPS : from PLB 465
double T_f = 0.168;
double meub = 0.266;
double meus = 0.0711;
double meui3 = -0.005;
double meuc = -0.0418;
//const double N_ccbar = 0.2;
//const double N_ch = 1350.;
const double N_ccbar = 0.064;
const double N_ch = 430.;
const double vol = 861.;
*/

/*
//SPS : from PLB 490
double T_f = 0.168;
double meub = 0.266;
double meus = 0.071;
double meui3 = -0.005;
double meuc = -0.065;
const double N_ccbar = 0.2;
const double N_ch = 1350.;
//const double vol = 3085.;
const double vol = 1.;
*/

/*
//SPS : from PLB 571
double T_f = 0.170;
double meub = 0.253;
double meus = 0.068;
double meui3 = -0.0101;
double meuc = -0.0418;
//const double N_ccbar = 0.2;
//const double N_ch = 1350.;
const double N_ccbar = 0.064;
const double N_ch = 430.;
const double vol = 861.;
*/

/*
//RHIC : from PLB571
 double T_f = 0.170;
 double meub = 0.027.;
 double meus = 0.0067;
 double meui3 = -0.00096;
 double meuc = -0.00392;
// const double N_ccbar = 10.;
//const double N_ch = 3250.;
const double N_ccbar = 1.92;
const double N_ch = 730.;
const double vol = 1663.;
*/

//LHC : from PLB 571
///////////////////////

double T_f = 0.170;
double meub = 0.0;
double meus = 0.0;
double meui3 = 0.0;
double meuc = 0.0;



//const double vol = 4564.;

const double vol = 71536.4;
const double N_ccbar0 = 14.0;
const double N_ch0 = 12500.0;
const Double_t nPart0 = 393.0;
const Double_t nColl0 = 1747.0;

//const Double_t nCC0 = 10.0;
//const Double_t nJpsi0 = 0.18;


void JPsiStatNPart()
{
  TFile *OutFile =new TFile("FormOut.root","RECREATE");
  
  Double_t nPartA[100]={Npart(0,2),Npart(2,4),Npart(4,6),Npart(6,8),Npart(8,10),Npart(10,12),
			Npart(12,14),Npart(14,16),Npart(16,18),Npart(18,20),Npart(20,24),
			Npart(24,40)};
  Double_t nCollA[100]={NColl(0,2),NColl(2,4),NColl(4,6),NColl(6,8),NColl(8,10),NColl(10,12),
			NColl(12,14),NColl(14,16),NColl(16,18),NColl(18,20),NColl(20,24),NColl(24,40)};
  
  Double_t jpsiFormALICE[100];
  Double_t jpsiFormALICE_Can[100];

  Double_t Gamma_C[1000];
  Double_t xx[1000];
  Double_t x=0;
  for(int i=0;i<60;i++)
    {
      x=0.0+0.1*i;
      xx[i]=x;
      Gamma_C[i]=Gamma_CFunc(N_ccbar0,N_ch0,xx[i]);
      cout<<xx[i]<<"   "<<Gamma_C[i]<<endl;
    }

  TGraph *grGammC = new TGraph(60,xx,Gamma_C);

  new TCanvas;
  grGammC->Draw("AL");

  Double_t NN=12;  
  
  for(int i=0; i<NN; i++) {
    
    Double_t nColl = nCollA[i];  
    Double_t nCC = N_ccbar0*nColl/nColl0;
    Double_t nPart = nPartA[i];
    Double_t N_ch= N_ch0*nPart/nPart0;
    jpsiFormALICE[i]=jpsistat(nCC, N_ch);
    jpsiFormALICE_Can[i]=JpsiStatCanonical(nCC, N_ch);
  }
  
  TGraph *grFormALICE_M = new TGraph(NN,nPartA,jpsiFormALICE);
  grFormALICE_M->SetName("FormALICE");
  grFormALICE_M->SetTitle("FormALICE");
  grFormALICE_M->SetLineWidth(2);
  grFormALICE_M->SetLineColor(2);
  
  TGraph *grFormALICE_Can_M = new TGraph(NN,nPartA,jpsiFormALICE_Can);
  grFormALICE_Can_M->SetLineWidth(2); 
  grFormALICE_Can_M->SetLineColor(4); 

  new TCanvas;
  grFormALICE_M->GetXaxis()->SetTitle("N_{Part}");
  grFormALICE_M->GetYaxis()->SetTitle("N_{J/#psi}");
  grFormALICE_M->GetYaxis()->SetRangeUser(0.0,1.0);
  grFormALICE_M->Draw("APL");
  grFormALICE_Can_M->Draw("Lsame");
  grFormALICE_M->Write();
  OutFile->Write();
  
}

 
Double_t jpsistat(Double_t N_ccbar, Double_t N_ch)
{
  //  cout<< str1<<"/"<<str2<<" ratio is: "<<ratio(str1,str2)<<endl;

  double totalCh = NDPiPlus()+ NDPiMinus() + NDKPlus() + NDKMinus() + NDPPlus() + NDPMinus();
  cout<<endl;
  cout << " Total charge density =   " << totalCh << endl;
  cout<<endl;
  cout<<"pi+: "<<NDPiPlus()*vol<<"   pi-: "<<NDPiMinus()*vol<<"   K+: "<<NDKPlus()*vol<<"   K-: "<<NDKMinus()*vol<<"   p: "<<NDPPlus()*vol<<"   pbar: "<<NDPMinus()*vol<<"   total: "<<totalCh*vol<<endl;
  cout<<endl;
  
  cout<<"D+: "<<NDOpenPlus()*vol<<"   D-: "<<NDOpenMinus()*vol<<"   Jpsi: "<<NDJpsi()*vol<<"   Lambda: "<<NDLambda()*vol<<"   Lambdabar: "<<NDLambdabar()*vol<<endl;
  cout<<"Ds+: "<< NDDsPlus()*vol<<"    Ds-: "<<NDDsMinus()*vol<<"   Lambdac+: "<<NDLambdac()<<"   Lambdac-:  "<<NDLambdacbar()<<endl;
  cout<<endl;
  
  double n_open = 2.0*(NDOpenPlus() + NDOpenMinus())+ NDDsPlus() + NDDsMinus()+NDLambdac() + NDLambdacbar();
  
  cout<<"gamma_c =  "<< 2.0*N_ccbar/(n_open*vol)  << endl;
  cout<<endl;
  cout <<" Ratio of thermal densities =   " << totalCh * NDJpsi() / (n_open*n_open) << endl;
  cout<<endl;
  
  //cout <<  4.* totalCh * NDJpsi()* N_ccbar*(N_ccbar+1. ) / (N_ch*n_open*n_open)<<endl;
  cout <<  4.* totalCh * NDJpsi()* N_ccbar * N_ccbar / (N_ch*n_open*n_open)<<endl;
  
  cout<<" ============= "<<totalCh<<"    "<<NDJpsi()<<"   "<<N_ccbar<<"  "<<N_ch<<"   "<<n_open<<endl<<endl;

  Double_t JPsiYield = 4.* totalCh * NDJpsi()* N_ccbar * N_ccbar / (N_ch*n_open*n_open);

  return JPsiYield;
}

//================= nJ/Psi Canoniacal Ensemble ===================================================//

Double_t JpsiStatCanonical(Double_t N_ccbar, Double_t N_ch)
{

  double totalCh = NDPiPlus()+ NDPiMinus() + NDKPlus() + NDKMinus() + NDPPlus() + NDPMinus();
  double n_open = 2.0*(NDOpenPlus() + NDOpenMinus())+ NDDsPlus() + NDDsMinus()+NDLambdac() + NDLambdacbar();
  
  cout<<"gamma_c =  "<< 2.0*N_ccbar/(n_open*vol)  << endl;
  //============= NR method ====================================//
  
  Double_t GammC_Guess = 2.0*N_ccbar/(n_open * (N_ch/totalCh) );
  cout<<"GammC_Guess : "<<GammC_Guess<<endl;
  Double_t GammC=0.0;
  Double_t delta;
  Int_t iters=0;
  Double_t deltaDer = 0.0001;
  
  do{
    
    Double_t Fx0 = Gamma_CFunc(N_ccbar,  N_ch, GammC_Guess ) ;
    Double_t Fx1 = ( Gamma_CFunc(N_ccbar,  N_ch, GammC_Guess+deltaDer)  - Gamma_CFunc(N_ccbar,  N_ch, GammC_Guess-deltaDer ) ) / (2*deltaDer); 

    GammC = GammC_Guess - Fx0 / Fx1;  

    delta=fabs(GammC-GammC_Guess);
    GammC_Guess=GammC;
    iters++;
    
    cout<<" iters: "<<iters<<" GammC "<<GammC<<endl;

  }while(delta > 0.0001 && iters <=30);

  //Double_t JPsiYield = GammC*GammC* totalCh * NDJpsi() / (N_ch);
  Double_t JPsiYield = GammC*GammC*NDJpsi()*N_ch/totalCh; 

  cout<<"GammC "<<GammC<<"  totalCh "<<totalCh<< " NDJpsi  "<<NDJpsi()<<" N_ch "<<N_ch<<endl;
  cout<<" JPsiYield "<<JPsiYield<<endl;
  
  return JPsiYield;
}


Double_t Gamma_CFunc(Double_t N_ccbar, Double_t N_ch, Double_t x)
{
  Double_t n_open = 2.0*(NDOpenPlus() + NDOpenMinus())+ NDDsPlus() + NDDsMinus()+NDLambdac() + NDLambdacbar();
  Double_t totalCh = NDPiPlus()+ NDPiMinus() + NDKPlus() + NDKMinus() + NDPPlus() + NDPMinus();
  Double_t Vol=N_ch/totalCh;

  Double_t a=Vol*NDJpsi();
  Double_t b=0.5*Vol*n_open;
  Double_t c=-N_ccbar;
  Double_t Ir = TMath::BesselI1(2.0*b*x)/TMath::BesselI0(2.0*b*x);
  //Ir=1;
  //Double_t Fx = b*x*x + 0.5*a*x*(TMath::BesselI1(a*x)/TMath::BesselI0(a*x))-c;

  Double_t Fx = a*x*x + b*Ir*x + c;
  Double_t FPrimex1 = (-b + TMath::Sqrt(b*b - 4.0*a*c) )/ (2.0*a);
  Double_t FPrimex2 = (-b - TMath::Sqrt(b*b - 4.0*a*c) )/ (2.0*a);
  
  //cout<<a<<" "<<b<<" "<<c<<endl;
  //cout<<" quardetic "<<FPrimex1<<"   "<<FPrimex2<<endl;
  return Fx;
}


double ratio(char *str1, char *str2)
{
  double a1,a2;
  if(!strcmp("pi+",str1))a1 = NDPiPlus();
  else if(!strcmp("pi-",str1)) a1 = NDPiMinus();
  else if(!strcmp("K+",str1)) a1 = NDKPlus();
  else if(!strcmp("K-",str1)) a1 = NDKMinus();
  else if(!strcmp("p",str1)) a1 = NDPPlus();
  else if(!strcmp("pbar",str1)) a1 = NDPMinus();
  else if(!strcmp("open+",str1)) a1 = NDOpenPlus();
  else if(!strcmp("open-",str1)) a1 = NDOpenMinus();
  else if(!strcmp("jpsi",str1)) a1 = NDJpsi();
  else if(!strcmp("lambda",str1)) a1 = NDLambda();
  else if(!strcmp("lambdabar",str1)) a1 = NDLambdabar();

  if(!strcmp("pi+",str2))a2 = NDPiPlus();
  else if(!strcmp("pi-",str2)) a2 = NDPiMinus();
  else if(!strcmp("K+",str2)) a2 = NDKPlus();
  else if(!strcmp("K-",str2)) a2 = NDKMinus();
  else if(!strcmp("p",str2)) a2 = NDPPlus();
  else if(!strcmp("pbar",str2)) a2 = NDPMinus();
  else if(!strcmp("open+",str2)) a2 = NDOpenPlus();
  else if(!strcmp("open-",str2)) a2 = NDOpenMinus();
  else if(!strcmp("jpsi",str2)) a2 = NDJpsi();
  else if(!strcmp("lambda",str2)) a2 = NDLambda();
  else if(!strcmp("lambdabar",str2)) a2 = NDLambdabar();
  return a1/a2;
}


double NDPiPlus()
{
  double mass = 0.13957;
  double meu = meui3 * 1.; 
  double  g = 1.;
  ///////////////////
  double sum  = 0.;
  double size = 0.01;
  double min = 0.0;
  double max = 3.0; // GeV momentum
  int nn = int(max/size);
  for(int i =0; i<nn ; i++) {
    double p = min + size*i;
    double E  = sqrt(mass*mass + p*p);
    double intg = p*p/(exp((E - meu)/T_f) - 1.);
    sum = sum + intg;
  }
  return sum*size*g/(2.*pi*pi*hbarc3);
}


double NDPiMinus()
{
  double mass = 0.13957;
  double meu = meui3 * (-1.); 
  double  g = 1.;
  ///////////////////
  double sum  = 0.;
  double size = 0.01;
  double min = 0.0;
  double max = 3.0; // GeV
  int nn = int(max/size);
  for(int i =0; i<nn ; i++) {
    double p = min + size*i;
    double E  = sqrt(mass*mass + p*p);
    double intg = p*p/(exp((E - meu)/T_f) - 1.);
    sum = sum + intg;
  }
  return sum*size*g/(2.*pi*pi*hbarc3);
}

double NDKPlus()
{
  double mass = 0.493677;
  double meu = meus * 1. + meui3 * 0.5; 
  double  g = 1.;
  ///////////////////
  double sum  = 0.;
  double size = 0.01;
  double min = 0.0;
  double max = 3.0; // GeV
  int nn = int(max/size);
  for(int i =0; i<nn ; i++) {
    double p = min + size*i;
    double E  = sqrt(mass*mass + p*p);
    double intg = p*p/(exp((E - meu)/T_f) - 1.);
    sum = sum + intg;
  }
  return sum*size*g/(2.*pi*pi*hbarc3);
}

double NDKMinus()
{
  double mass = 0.493677;
  double meu = meus * (-1.) + meui3 * (-0.5); 

  double  g = 1.;
  ///////////////////
  double sum  = 0.;
  double size = 0.01;
  double min = 0.0;
  double max = 3.0; // GeV
  int nn = int(max/size);
  for(int i =0; i<nn ; i++) {
    double p = min + size*i;
    double E  = sqrt(mass*mass + p*p);
    double intg = p*p/(exp((E - meu)/T_f) - 1.);
    sum = sum + intg;
  }
  return sum*size*g/(2.*pi*pi*hbarc3);
}

double NDPPlus()
{
  double mass = 0.938272;
  double meu = meub * 1.+ meui3 * 0.5; 
  double  g = 2.;
  ///////////////////
  double sum  = 0.;
  double size = 0.01;
  double min = 0.0;
  double max = 3.0; // GeV
  int nn = int(max/size);
  for(int i =0; i<nn ; i++) {
    double p = min + size*i;
    double E  = sqrt(mass*mass + p*p);
    double intg = p*p/(exp((E - meu)/T_f) + 1.);
    sum = sum + intg;
  }
  return sum*size*g/(2.*pi*pi*hbarc3);
}

double NDPMinus()
{
  double mass = 0.938272;
  double meu = meub * (-1.) + meui3 * (-0.5); 
  double  g = 2.;
  ///////////////////
  double sum  = 0.;
  double size = 0.01;
  double min = 0.0;
  double max = 3.0; // GeV
  int nn = int(max/size);
  for(int i =0; i<nn ; i++) {
    double p = min + size*i;
    double E  = sqrt(mass*mass + p*p);
    double intg = p*p/(exp((E - meu)/T_f) + 1.);
    sum = sum + intg;
  }
  return sum*size*g/(2.*pi*pi*hbarc3);
}

double NDOpenPlus()
{
  double mass = 1.8693;
  double meu = meui3 * 0.5 + meuc * 1.; 
  double  g = 1.;
  ///////////////////
  double sum  = 0.;
  double size = 0.01;
  double min = 0.0;
  double max = 3.0; // GeV
  int nn = int(max/size);
  for(int i =0; i<nn ; i++) {
    double p = min + size*i;
    double E  = sqrt(mass*mass + p*p);
    double intg = p*p/(exp((E - meu)/T_f) - 1);
    sum = sum + intg;
  }
  return sum*size*g/(2.*pi*pi*hbarc3);
}

double NDOpenMinus()
{
  double mass = 1.8693;
  double meu = meui3 * (-0.5) + meuc * (-1.); 
  double  g = 1.;
  ///////////////////
  double sum  = 0.;
  double size = 0.01;
  double min = 0.0;
  double max = 3.0; // GeV
  int nn = int(max/size);
  for(int i =0; i<nn ; i++) {
    double p = min + size*i;
    double E  = sqrt(mass*mass + p*p);
    double intg = p*p/(exp((E - meu)/T_f) - 1);
    sum = sum + intg;
  }
  return sum*size*g/(2.*pi*pi*hbarc3);
}

double NDDsPlus()
{
  double mass = 1.9682;
  double meu = meus*(1.) + meuc * 1.; 
  double  g = 1.;
  ///////////////////
  double sum  = 0.;
  double size = 0.01;
  double min = 0.0;
  double max = 3.0; // GeV
  int nn = int(max/size);
  for(int i =0; i<nn ; i++) {
    double p = min + size*i;
    double E  = sqrt(mass*mass + p*p);
    double intg = p*p/(exp((E - meu)/T_f) - 1);
    sum = sum + intg;
  }
  return sum*size*g/(2.*pi*pi*hbarc3);
}

double NDDsMinus()
{
  double mass = 1.9682;
  double meu = meus * (-1.) + meuc * (-1.); 
  double  g = 1.;
  ///////////////////
  double sum  = 0.;
  double size = 0.01;
  double min = 0.0;
  double max = 3.0; // GeV
  int nn = int(max/size);
  for(int i =0; i<nn ; i++) {
    double p = min + size*i;
    double E  = sqrt(mass*mass + p*p);
    double intg = p*p/(exp((E - meu)/T_f) - 1);
    sum = sum + intg;
  }
  return sum*size*g/(2.*pi*pi*hbarc3);
}


double NDJpsi()
{
  double mass = 3.096916;
  double meu = 0.; 
  double  g = 3.;
  ///////////////////
  double sum  = 0.;
  double size = 0.01;
  double min = 0.0;
  double max = 3.0; // GeV
  int nn = int(max/size);
  for(int i =0; i<nn ; i++) {
    double p = min + size*i;
    double E  = sqrt(mass*mass + p*p);
    double intg = p*p/(exp((E - meu)/T_f) - 1);
    sum = sum + intg;
  }
  return sum*size*g/(2.*pi*pi*hbarc3);
}

double NDLambda()
{
  double mass = 1.115683;
  double meu = meub * 1. + meus * (-1.);
  double  g = 2.;
  ///////////////////
  double sum  = 0.;
  double size = 0.01;
  double min = 0.0;
  double max = 3.0; // GeV
  int nn = int(max/size);
  for(int i =0; i<nn ; i++) {
    double p = min + size*i;
    double E  = sqrt(mass*mass + p*p);
    double intg = p*p/(exp((E - meu)/T_f) + 1);
    sum = sum + intg;
  }
  return sum*size*g/(2.*pi*pi*hbarc3);
}

double NDLambdabar()
{
  double mass = 1.115683;
  double meu = meub * (-1.) + meus * (1.);
  double  g = 2.;
  ///////////////////
  double sum  = 0.;
  double size = 0.01;
  double min = 0.0;
  double max = 3.0; // GeV
  int nn = int(max/size);
  for(int i =0; i<nn ; i++) {
    double p = min + size*i;
    double E  = sqrt(mass*mass + p*p);
    double intg = p*p/(exp((E - meu)/T_f) + 1);
    sum = sum + intg;
  }
  return sum*size*g/(2.*pi*pi*hbarc3);
}

double NDLambdac()
{
  double mass = 2.28646;
  double meu = meub * 1. + meuc * (1.);
  double  g = 2.;
  ///////////////////
  double sum  = 0.;
  double size = 0.01;
  double min = 0.0;
  double max = 3.0; // GeV
  int nn = int(max/size);
  for(int i =0; i<nn ; i++) {
    double p = min + size*i;
    double E  = sqrt(mass*mass + p*p);
    double intg = p*p/(exp((E - meu)/T_f) + 1);
    sum = sum + intg;
  }
  return sum*size*g/(2.*pi*pi*hbarc3);
}

double NDLambdacbar()
{
  double mass = 2.28646;
  double meu = meub * (-1.) + meuc * (-1.);
  double  g = 2.;
  ///////////////////
  double sum  = 0.;
  double size = 0.01;
  double min = 0.0;
  double max = 3.0; // GeV
  int nn = int(max/size);
  for(int i =0; i<nn ; i++) {
    double p = min + size*i;
    double E  = sqrt(mass*mass + p*p);
    double intg = p*p/(exp((E - meu)/T_f) + 1);
    sum = sum + intg;
  }
  return sum*size*g/(2.*pi*pi*hbarc3);
}

/*
double NccbarDirect()
{
  double Noc_th = 2.*(NDOpenPlus() + NDOpenMinus()) * vol;
  double g_c = 2.*NDJpsi()*vol/Noc_th;
  double Nccbar_th = NDJpsi() * vol;
  double x = g_c * Noc_th;

Double Nccbar_dir = 1./2.* Noc_th * TMath

}
*/
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

