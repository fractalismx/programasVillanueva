#include<cmath>
#include<iostream>
#include<cstdlib>
#include<iomanip>
#include<cstdio>

using namespace std;

void SDorada(const double A,const double B,int I);
double Funcion(const double X);
double Numero(const double U);
double Validar(void);

int main(void)
{
  double Xa;
  double Xb;
  double Er;
  double U;
  double I;
  int Aux;
  
  cout<<"Este programa optimiza"<<endl
      <<"la funcion x^2+2x"<<endl<<endl
      <<"Ingrese limite inferior"<<endl;
  cin>>Xa;
  
  cout<<"Ingrese Limite superior"<<endl;
  cin>>Xb;
  
  cout<<"Ingrese el epsilon deseado"<<endl;
  Er=Validar();
  
  U=Er/(Xb-Xa);
  
  I=Numero(U);//Parseo
  Aux=I;//Parseo
  
  double h=I-Aux;//Parseo
  
  if(h == 0)
  {
	cout<<"Iteraciones restantes "<<Aux<<endl;
    SDorada(Xa,Xb,I);
  }
  else
  { 
	Aux++;
	cout<<"Iteraciones restantes "<<Aux<<endl;
	SDorada(Xa,Xb,Aux);
  }
  
  system("pause=>NULL");

  return 0;
}

double Validar(void)
{
	double V;
	
	do
	{
		cin>>V;
		
		if(V<=0)
		   cout<<"No es posible determinar el valor"<<endl;
		
	}while(V<=0);
	
	return V;
}

void SDorada(const double A,const double B,int I)
{
	double X1,X2,L;
	
	L=B-A;
	
	X1=A+L*(1-2.0/(1+sqrt(5)));
	X2=A+L*(2.0/(1+sqrt(5)));
	
	if(I==0)
	{
		cout<<"Su optimo es aproxidamente igual a "
            <<setprecision(16)<<(B+A)/2.0<<endl;	
	}
	else if(Funcion(X1)>Funcion(X2))
	{
		I--;
		cout<<"X1= "<<setprecision(16)
		    <<X1<<endl
		    <<"X2= "<<setprecision(16)
		    <<X2<<endl
		    <<"Iteraciones restantes "<<I<<endl;
		
		SDorada(X1,B,I);
	}
	else
	{
		I--;
		cout<<"X1= "<<setprecision(16)
		    <<X1<<endl
		    <<"X2= "<<setprecision(16)
		    <<X2<<endl
		    <<"Iteraciones restantes "<<I<<endl;
		
		SDorada(A,X2,I);
	}
}
double Funcion(const double X)
{
	return -1.0*(-1.5*pow(X,6)-2*pow(X,4)+12*X);
}
double Numero(const double U)
{ 
	double V;
	
	V=log(U)/log(2/(1+sqrt(5)))+1;
	
	return V;
}
