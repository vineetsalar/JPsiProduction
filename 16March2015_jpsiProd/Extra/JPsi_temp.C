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
