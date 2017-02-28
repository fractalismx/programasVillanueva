#include<iostream>
#include<cstdlib>
#include<cmath>

using namespace std;

double Validar(void);
double Num(double A,double B);
double Ren(double A,double B);
double Funcion(double A);
void MS(double A, double B, const double E);

int main(void)
{

   system("clear");
	double a,b,e;
	char o;
	
  do
  {
    cout<<"Este Programa realiza la aproximacion"<<endl
	    <<"de raices por el metodo de la secante"<<endl<<endl 
	    <<"Ingrese valor proximo 1"<<endl;
	cin>>a;
    cout<<"Ingrese valor proximo 2"<<endl;
        cin>>b;        

	cout<<"Ingrese error"<<endl;
	e=Validar();
	cout<<endl<<endl;

	MS(a,b,e);
    
    cout<<"Desea repetir el programa?"<<endl;
    cin>>o;
    
    o=toupper(o);
    
  }while(o=='S');
        
        system("clear");
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
  
  h=1.4*pow(10,-5.0)*pow(A,1.5)+1.15*pow(10,-5.0)*pow(A,2)-0.002*9.81;
  
	return h;
}

double Num(double A,double B)
{
   return (Funcion(B)*(B-A));	
}

double Den(double A,double B)
{
	return (Funcion(B)-Funcion(A));
}

void MS(double A,double B, const double E)
{
	double c;
		  c=B-(Num(A,B)/Den(A,B));

		  if(abs(Funcion(c))<E)
		  {
			cout<<"Valor cercano1 ="<<A<<endl
			    <<"Valor cercano2 ="<<B<<endl
				<<"la raiz aproximada x= "<<c<<endl;
		  }
		  else
		  {	
		    cout<<"Valor cercano1 ="<<A<<endl
			    <<"Valor cercano2 ="<<B<<endl
				<<"la raiz aproximada x= "<<c<<endl;
			 MS(B,c,E);	
	      }
}
