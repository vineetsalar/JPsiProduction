#include "TMath.h"
#include "TCanvas.h"
#include "TGraph.h"
#include <iostream.h>

double NDPionPlus();
double NDPionMinus();
double NDOpenPlus();
double NDOpenMinus();
double NDJpsi();

const double hbarc = 0.197327;

const double hbarc3 = hbarc*hbarc*hbarc;
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
double meub = 0.001;
double meus = 0.000304;
double meui3 = -0.000037;
double meuc = -0.000156;
/*
double T_f = 0.200;
double meub = 0.000;
double meus = 0.0000;
double meui3 = -0.00;
double meuc = -0.000;
*/
//const double N_ccbar = 200.;
//const double N_ch = 16500.;
const double N_ccbar = 17.8;
const double N_ch = 12500.;
const double vol = 4564.;



const double pi = TMath::Pi();

//void jpsistat(char *str1, char *str2)

void jpsistat()

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
   //   cout <<  4.* totalCh * NDJpsi()* N_ccbar*(N_ccbar+1. ) / (N_ch*n_open*n_open)<<endl;

   cout <<  4.* totalCh * NDJpsi()* N_ccbar * N_ccbar / (N_ch*n_open*n_open)<<endl;

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
