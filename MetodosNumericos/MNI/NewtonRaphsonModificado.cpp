#include<iostream>
#include<cstdlib>
#include<cmath>

using namespace std;

double Validar(void);
double Num(double A);
double Ren(double A);
double Funcion(double A);
double FuncionD(double A);
double FuncionD2(double A);
void NRM (double A, const double E);

int main(void)
{
	double a,e;
	char o;
	
  do
  {
    cout<<"Este Programa realiza la aproximacion"<<endl
	    <<"de raices por el metodo de N-R Mejorado"<<endl<<endl 
	    <<"Ingrese valor proximo"<<endl;
	cin>>a;

	cout<<"Ingrese error"<<endl;
	e=Validar();
	cout<<endl<<endl;

	NRM(a,e);
    
    cout<<"Desea repetir el programa?"<<endl;
    cin>>o;
    
    o=toupper(o);
    
  }while(o=='S');

	return 0;
}

double Validar(void)
{
	double V;
	
	do
	{
		cin>>V;
		
		if(V<=0)
		{
			cout<<"No es posible determinar el valor con 0"<<endl;
		}
	}while(V<=0);
	
	return V;
}

double Funcion(double A)
{ 
  double h;
  
  h=3*pow(A,2)-exp(A);
	return h;
}

double FuncionD(double A)
{ 
  double h;
  
  h=6*A-exp(A);
	return h;
}

double FuncionD2(double A)
{ 
  double h;
  
  h=6-exp(A);
	return h;
}

double Num(double A)
{
   return (Funcion(A)*FuncionD(A));	
}

double Den(double A)
{
	return (pow(FuncionD(A),2)-Funcion(A)*FuncionD2(A));
}

void NRM(double A, const double E)
{
	double c;
		  
		  if(abs(Funcion(A))<E)//error
		  	cout<<"la raiz aproximada x= "<<A<<endl;
		  else
		  {	
		     c=A-(Num(A)/Den(A));
			 NRM(c,E);	
	          }
}
