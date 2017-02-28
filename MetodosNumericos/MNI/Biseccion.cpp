#include<iostream>
#include<cstdlib>
#include<cmath>

using namespace std;

double Validar(void);
double Funcion(double A);
bool Bandera(double &A, double &B);
void Biseccion(double &A, double &B, const double &E);

int main(void)
{
	double a,b,e;
	char o;
	
  do
  {
    cout<<"Este Programa realiza la aproximacion"<<endl
	    <<"de raices por el metodo de Biseccion"<<endl<<endl 
	    <<"Ingrese limite inferior"<<endl;
	cin>>a;
	
	cout<<"Ingrese limite superior"<<endl;
	cin>>b;

	cout<<"Ingrese error"<<endl;
	e=Validar();
	cout<<endl<<endl;
	
	if(Bandera(a,b)==true)
	Biseccion(a,b,e);
	else
	cout<<"intervalo no valido"<<endl;
    
    cout<<"Desea repetir el programa?"<<endl;
    cin>>o;
    
    o=toupper(o);
    
  }while(o=='S');

	system("pause => NULL");
	return 0;
}

double Validar(void)
{
	double V;
	
	do
	{
		cin>>V;
		
		if(V==0)
		{
			cout<<"No es posible determinar el valor con 0"<<endl;
		}
	}while(V==0);
	
	return V;
}

bool Bandera(double &A,double &B)
{
	return((Funcion(A)*Funcion(B)<0));
}

double Funcion(double A)
{
	return (2*sin(A)-exp(-A));
}

void Biseccion(double &A, double &B, const double &E)
{
	double c;

       if(Bandera(A,B)==true)
	   {
		  c=(A+B)/2.0;
		  
		  if(abs(B-A)<E)//error
		  	cout<<"la raiz aproximada x= "<<c<<endl;
		  else
		  {
		     cout<<"los limites son "<<A<<" y "<<B<<endl; 	
			 Biseccion(A,c,E);
			 Biseccion(c,B,E);	
	      }
	   }
}
