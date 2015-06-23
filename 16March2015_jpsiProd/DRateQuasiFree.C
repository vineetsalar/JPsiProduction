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

const double RJPsi = 0.45;//fm
const double DeltaEQVac = 0.640;//GeV
const double DeltaEQVac2 = DeltaEQVac*DeltaEQVac;//GeV2

const double MJPsi = 3.0969;//GeV
//const double Mq = 0.400;//GeV
const double Mq = 0.600;//GeV
const double MQ = 1.86;//GeV
const double Mg = 0.0;//GeV

const double SumSeries=0.901543;




Double_t SigmaQuasiQuark(Double_t PJPsi, Double_t T);
Double_t FuncCosTheta(Double_t PJPsi, Double_t Pq, Double_t CosTheta, Double_t T);
Double_t Fq(Double_t p, Double_t T);
Double_t MuT(Double_t T);
Double_t EDiss(Double_t Flag, Double_t T );
Double_t SigmaThermalAct(Double_t Flag, Double_t T);



//gluon dissociation
Double_t SigmaQuasiGluon(Int_t Flag, Double_t PJPsi, Double_t T);
Double_t FuncCosThetaGluon(Int_t Flag, Double_t PJPsi, Double_t Pg, Double_t CosTheta, Double_t T);
Double_t SigmaGluonDiss(Double_t q0);
Double_t fGluon(Double_t pg, Double_t T);
Double_t SigmaGluonDissS(Double_t s);
Double_t SigmaGluonDissS_Med(Double_t s, Double_t T);



void DRateQuasiFree()
{
  cout<<"============= Quasi Free =================== "<<endl;
  

  Double_t TMax=0.450;
  Double_t TMin=0.180;
  
  Double_t TStep=0.001;
  Int_t NNT = (TMax-TMin)/TStep;
  cout<<NNT<<endl; 
  Double_t TT[1000];
  
  Double_t SigmaQuasiT[1000];

  Double_t SigmaGluonDissVacT[1000];

  Double_t SigmaQuasiFreeGluonT[1000];
 
  Double_t aMuT[1000];
  
  Double_t EDJPsi[1000];
  Double_t EDUpsilon[1000];
 
  Double_t Temp=0;
  cout<<" T:  "<<"  Mu  "<<"  EDiss J "<<"  EDiss Y "<<endl;

  //NNT =1;
  for(int i=0;i<NNT;i++)
    {
      Temp=TMin+(TStep*i);
      TT[i]=Temp;
      
      aMuT[i]= MuT(Temp);
      EDJPsi[i]=EDiss(1,Temp);
      EDUpsilon[i]=EDiss(2,Temp);

      SigmaQuasiT[i]=SigmaQuasiQuark(0.0,Temp);
      
      SigmaGluonDissVacT[i]= SigmaQuasiGluon(1,0.0, Temp);
      SigmaQuasiFreeGluonT[i]= SigmaQuasiGluon(2,0.0, Temp);

      

      cout<<TT[i]<<"  "<<aMuT[i]<<"  "<<EDJPsi[i]<<"  "<<EDUpsilon[i]<<endl;


    } 
  TGraph *GrfSigmaQ = new TGraph(NNT,TT,SigmaQuasiT);
  GrfSigmaQ->SetLineWidth(2);
  GrfSigmaQ->SetLineColor(2);
 
  GrfSigmaQ->GetXaxis()->SetTitle("T(MeV/c)");
  GrfSigmaQ->GetYaxis()->SetTitle("#Gamma (MeV)");

  new TCanvas;
  gPad->SetTicks(1);
  GrfSigmaQ->Draw("APL");

  
  TGraph *GrfSigmaGluonT = new TGraph(NNT,TT,SigmaGluonDissVacT);
  GrfSigmaGluonT->SetLineWidth(2);
  GrfSigmaGluonT->SetLineColor(2);
 
  GrfSigmaGluonT->GetXaxis()->SetTitle("T(MeV/c)");
  GrfSigmaGluonT->GetYaxis()->SetTitle("#Gamma_{J/#psig} (MeV)");

  GrfSigmaGluonT->GetXaxis()->SetRangeUser(0.15,0.45);
  GrfSigmaGluonT->GetYaxis()->SetRangeUser(1.0,1000.0);


  TGraph *GrfSigmaQuasiFreeGluonT = new TGraph(NNT,TT,SigmaQuasiFreeGluonT);
  GrfSigmaQuasiFreeGluonT->SetLineWidth(2);
  GrfSigmaQuasiFreeGluonT->SetLineColor(4);

  new TCanvas;
  gPad->SetTicks(1);
  gPad->SetLogy(1);

  GrfSigmaGluonT->Draw("APL");
  GrfSigmaQuasiFreeGluonT->Draw("PLsame");

  return;









  TGraph *GrfMuT = new TGraph(NNT,TT,aMuT);
  GrfMuT->SetLineWidth(2);
  GrfMuT->SetLineColor(4);

  GrfMuT->GetXaxis()->SetTitle("T(MeV/c)");
  GrfMuT->GetYaxis()->SetTitle("#mu_{D}(GeV)");

  new TCanvas;
  gPad->SetTicks(1);
  GrfMuT->Draw("APL");


  TGraph *GrfEDUpsilon = new TGraph(NNT,TT,EDUpsilon);
  GrfEDUpsilon->SetLineWidth(2);
  GrfEDUpsilon->SetLineColor(2);

  GrfEDUpsilon->GetXaxis()->SetTitle("T(MeV/c)");
  GrfEDUpsilon->GetYaxis()->SetTitle("E_{dis}(GeV)");
  GrfEDUpsilon->GetYaxis()->SetRangeUser(0.0,1.2);

  TGraph *GrfEDJPsi = new TGraph(NNT,TT,EDJPsi);
  GrfEDJPsi->SetLineWidth(2);
  GrfEDJPsi->SetLineColor(4);

  GrfEDJPsi->GetXaxis()->SetTitle("T(MeV/c)");
  GrfEDJPsi->GetYaxis()->SetTitle("E_{dis}(GeV)");

  new TCanvas;
  gPad->SetTicks(1);
  GrfEDUpsilon->Draw("APL");
  GrfEDJPsi->Draw("PLsame");



  cout<<" ========================= pT dependance ============================== "<<endl;

  Double_t PMax=10.0;
  Double_t PMin=0.1;
  Double_t PStep=0.1;
  Int_t NNP= (PMax-PMin)/PStep;
  cout<<NNP<<endl; 
  Double_t PP[1000];
  
  Double_t SigmaQuasiQuarkP1[1000];
  Double_t SigmaQuasiQuarkP2[1000];
  Double_t SigmaQuasiQuarkP3[1000];
  
  Double_t SigmaQuasiGluonP1[1000];
  Double_t SigmaQuasiGluonP2[1000];
  Double_t SigmaQuasiGluonP3[1000];
  

  Double_t P=0;

  //NNP=1;

  for(int i=0;i<NNP;i++)
    {
      P=PMin+(PStep*i);
      PP[i]=P;
      SigmaQuasiQuarkP1[i]=SigmaQuasiQuark(P,0.180);
      SigmaQuasiQuarkP2[i]=SigmaQuasiQuark(P,0.250);
      SigmaQuasiQuarkP3[i]=SigmaQuasiQuark(P,0.375);

      
      SigmaQuasiGluonP1[i]=SigmaQuasiGluon(2,P,0.180);
      SigmaQuasiGluonP2[i]=SigmaQuasiGluon(2,P,0.250);
      SigmaQuasiGluonP3[i]=SigmaQuasiGluon(2,P,0.375);

      cout<<PP[i]<<"  "<<SigmaQuasiQuarkP1[i]<<"   "<<SigmaQuasiGluonP1[i]<<endl;
   


    } 

  TGraph *GrfSigmaQP1 = new TGraph(NNP,PP,SigmaQuasiQuarkP1);
  GrfSigmaQP1->SetLineWidth(2);
  GrfSigmaQP1->SetLineColor(1);
 
  GrfSigmaQP1->GetXaxis()->SetTitle("p_{J/#psi}(GeV)");
  GrfSigmaQP1->GetYaxis()->SetTitle("#Gamma_{J/#psi q} (MeV)");

  GrfSigmaQP1->GetYaxis()->SetRangeUser(0.0,400.0);

  TGraph *GrfSigmaQP2 = new TGraph(NNP,PP,SigmaQuasiQuarkP2);
  GrfSigmaQP2->SetLineWidth(2);
  GrfSigmaQP2->SetLineColor(2);


  TGraph *GrfSigmaQP3 = new TGraph(NNP,PP,SigmaQuasiQuarkP3);
  GrfSigmaQP3->SetLineWidth(2);
  GrfSigmaQP3->SetLineColor(3);


  new TCanvas;
  gPad->SetTicks(1);
  GrfSigmaQP1->Draw("AL");
  GrfSigmaQP2->Draw("Lsame");
  GrfSigmaQP3->Draw("Lsame");



  TGraph *GrfSigmaGP1 = new TGraph(NNP,PP,SigmaQuasiGluonP1);
  GrfSigmaGP1->SetLineWidth(2);
  GrfSigmaGP1->SetLineColor(1);
 
  GrfSigmaGP1->GetXaxis()->SetTitle("p_{J/#psi}(GeV)");
  GrfSigmaGP1->GetYaxis()->SetTitle("#Gamma_{J/#psi g} (MeV)");

  GrfSigmaGP1->GetYaxis()->SetRangeUser(0.0,400.0);


  TGraph *GrfSigmaGP2 = new TGraph(NNP,PP,SigmaQuasiGluonP2);
  GrfSigmaGP2->SetLineWidth(2);
  GrfSigmaGP2->SetLineColor(2);

  TGraph *GrfSigmaGP3 = new TGraph(NNP,PP,SigmaQuasiGluonP3);
  GrfSigmaGP3->SetLineWidth(2);
  GrfSigmaGP3->SetLineColor(3);



  new TCanvas;
  gPad->SetTicks(1);
  GrfSigmaGP1->Draw("AL");
  GrfSigmaGP2->Draw("Lsame");
  GrfSigmaGP3->Draw("Lsame");




}
//////////////////////////////////////////////
///////////////////////////////////////////////


//=============================== Parton Dissociation ===============================//
Double_t SigmaQuasiQuark(Double_t PJPsi, Double_t T)
{
  
  Double_t PqStep = 0.05;
  Double_t PqStart = 0.0;
  Double_t PqEnd = 10.0;
  int PqN =(int)((PqEnd - PqStart)/PqStep);
    
  Double_t CosThetaStep = 0.1;
  Double_t CosThetaStart = 1.0;
  Double_t CosThetaEnd = -1.0;
  int CosThetaN =(int)((CosThetaStart - CosThetaEnd)/CosThetaStep);
  
  Double_t SumPq=0;  
  for(int i =0; i <= PqN ; i++) {
    Double_t Pq = PqStart + i*PqStep;
    Double_t SumCosTheta=0;
    Double_t IntCosTheta =0;
    
    for(int k =0; k <= CosThetaN ; k++)  {
      Double_t CosTheta = CosThetaStart - k*CosThetaStep;
      SumCosTheta = SumCosTheta + FuncCosTheta(PJPsi, Pq, CosTheta, T);
  
      //cout<< FuncCosTheta(PJPsi, Pq, CosTheta, T)<<endl;   

    }//theta
    IntCosTheta = SumCosTheta*CosThetaStep;
    
    //cout<<IntCosTheta<<endl;

    SumPq = SumPq + Pq*Pq*Fq(Pq,T)*IntCosTheta;  
    //cout<<SumPq<<endl;
  }//Pq
  

  Double_t IntPq =  (SumPq*PqStep)/(4.0*pi2);
  //cout<<IntPq<<endl;
  return (IntPq*1000.0);

  
}


Double_t FuncCosTheta(Double_t PJPsi, Double_t Pq, Double_t CosTheta, Double_t T)
{

  Double_t STA=SigmaThermalAct(1,T);

  Double_t DeltaEQ2L=EDiss(1,T)*EDiss(1,T);

  Double_t EJPsi = TMath::Sqrt( PJPsi*PJPsi + MJPsi*MJPsi );
  Double_t Eq = TMath::Sqrt(Pq*Pq + Mq*Mq);
  Double_t S = MJPsi*MJPsi + Mq*Mq + 2.0*EJPsi*Eq-2.0*PJPsi*Pq*CosTheta;
  Double_t Value=0;
  
  //cout<<EJPsi<<"  "<<Eq<<"  "<<S<<endl;


  if(S > DeltaEQ2L ){
    Double_t PJPsiDotPq = 0.5*(S - (MJPsi*MJPsi + Mq*Mq));
    Double_t VRel2 = (PJPsiDotPq*PJPsiDotPq)-(MJPsi*MJPsi*Mq*Mq);
    Double_t VRel =0.0;
    if(VRel2 > 0.0) {VRel =TMath::Sqrt(VRel2)/(EJPsi*Eq);}
    
    //cout<< PJPsiDotPq<<"  "<<VRel<<endl;

    Value= STA*VRel;
    }
  return Value;

}

Double_t Fq(Double_t p, Double_t T)
{

  //Quark degenracy should be fixed ?
  Double_t gi=1.0;
  Double_t fq = gi / (TMath::Exp(sqrt(p*p+Mq*Mq)/T)+1);
  return fq;
}


Double_t SigmaThermalAct(Double_t Flag, Double_t T)
{
   Double_t DeltaEQT=EDiss(Flag,T);
   Double_t STA=pi*RJPsi*RJPsi*TMath::Exp(-(DeltaEQT/T));
   return STA/hbarc2;
}




Double_t MuT(Double_t T)
{
  Double_t Tc = 0.200;
  Double_t Const = 24.0*pi2/33.0;
  Double_t Value = Const*(1.0/TMath::Log(19.0*1.78*T/Tc))*T*T;
  Value = TMath::Sqrt(Value);
  Value = 1.75 * T;
  return Value;

}



Double_t EDiss(Double_t Flag, Double_t T ){

  Double_t Mu=MuT(T);

  //Double_t Mu=T;

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

  for(int i=0;i<16;i++)
    {
      if(Flag ==1)
	{
	  xA[i]= MuJPsi[i];
	  yA[i]= EDJPsi[i];
	}
    
      if(Flag ==2)
	{
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







// =================== Gluon Dissociation ===================================//

Double_t SigmaQuasiGluon(Int_t Flag , Double_t PJPsi, Double_t T)
{
  
  Double_t PgStep = 0.05;
  Double_t PgStart = 0.00001;
  Double_t PgEnd = 10.0;
  int PgN =(int)((PgEnd - PgStart)/PgStep);
  
  Double_t CosThetaStep = 0.05;
  Double_t CosThetaStart = 1.0;
  Double_t CosThetaEnd = -1.0;
  int CosThetaN =(int)((CosThetaStart - CosThetaEnd)/CosThetaStep);
  
  Double_t SumPg=0;  
  
  for(int i =0; i <= PgN ; i++) {
    Double_t Pg = PgStart + i*PgStep;
    Double_t SumCosTheta=0;
    Double_t IntCosTheta =0;
  
    for(int k =0; k <= CosThetaN ; k++)  {
      Double_t CosTheta = CosThetaStart - k*CosThetaStep;
    
      SumCosTheta = SumCosTheta + FuncCosThetaGluon(Flag, PJPsi,Pg,CosTheta,T);
  
    }//theta

 
    IntCosTheta = SumCosTheta*CosThetaStep;
    SumPg = SumPg + Pg*Pg*IntCosTheta*fGluon(Pg,T);  
    
  

  }//Pg

  Double_t IntPg =  (SumPg*PgStep)/(4.0*pi2);
  
  Double_t Value =IntPg*1000.0;
  return Value;
  
}


Double_t FuncCosThetaGluon(Int_t Flag, Double_t PJPsi, Double_t Pg, Double_t CosTheta,Double_t T)
{

  Double_t EJPsi = TMath::Sqrt( PJPsi*PJPsi + MJPsi*MJPsi );
  Double_t Eg = TMath::Sqrt(Pg*Pg + Mg*Mg);
  Double_t S = MJPsi*MJPsi + Mg*Mg + 2.0*EJPsi*Eg-2.0*PJPsi*Pg*CosTheta;
  Double_t Value=0;
  
  Double_t ThetaVal=0;
  
  if(Flag ==1) {ThetaVal=DeltaEQVac2;}
  if(Flag ==2) {ThetaVal=EDiss(1,T)*EDiss(1,T);}

  if(S >  ThetaVal){
  
    Double_t SGD = 0;
    
    if(Flag ==1) {SGD = SigmaGluonDissS(S);}
    if(Flag ==2) {SGD =SigmaGluonDissS_Med(S,T);}
    if(Flag ==3) {SGD = SigmaThermalAct(1,T);}

    Double_t PJPsiDotPg = 0.5*(S - (MJPsi*MJPsi + Mg*Mg));
    Double_t VRel =TMath::Sqrt((PJPsiDotPg*PJPsiDotPg)-(MJPsi*MJPsi*Mg*Mg))/(EJPsi*Eg);
    Value= SGD*VRel;
  }
  
  return Value;

}




Double_t SigmaGluonDiss(Double_t q0)
{
  Double_t epCon = 4.0*pi*pow(8./3.0, 3)*pow(DeltaEQVac, 3)/pow(MQ, 1.5);
  Double_t SigmaDq0 = 0.0;
  if(q0<DeltaEQVac) return SigmaDq0;
  SigmaDq0 = epCon*pow(q0-DeltaEQVac, 1.5)/pow(q0,5.0);  
  return SigmaDq0;

}

Double_t fGluon(Double_t pg, Double_t T)
{
  Double_t gi=16.0;
  Double_t fg = gi / (TMath::Exp( sqrt(pg*pg + Mg*Mg) / T ) - 1 );
  return fg;
}


Double_t SigmaGluonDissS(Double_t s)
{
  Double_t epCon = 4.0*pi*pow(8./3.0, 3)*pow(DeltaEQVac, 3)/pow(MQ, 1.5);
  Double_t q0 = (s-MJPsi*MJPsi)/(2.0*MJPsi); 
  Double_t SigmaDq0 = 0.0;
  if(q0<DeltaEQVac) return SigmaDq0;
  SigmaDq0 = epCon*pow(q0-DeltaEQVac, 1.5)/pow(q0,5.0);  
  return SigmaDq0;


}

Double_t SigmaGluonDissS_Med(Double_t s, Double_t T)
{
  Double_t BE_Med=EDiss(1,T);

  Double_t epCon = 4.0*pi*pow(8./3.0, 3)*pow(BE_Med, 3)/pow(MQ, 1.5);
  Double_t q0 = (s-MJPsi*MJPsi)/(2.0*MJPsi); 
  Double_t SigmaDq0 = 0.0;
  if(q0<BE_Med) return SigmaDq0;
  SigmaDq0 = epCon*pow(q0-BE_Med, 1.5)/pow(q0,5.0);  
  return SigmaDq0;


}





