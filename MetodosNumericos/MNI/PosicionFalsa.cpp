#include<iostream>
#include<cstdlib>
#include<cmath>

using namespace std;

double Validar(void);
double Funcion(double A);
bool Bandera(double &A, double &B);
void PF(double &A, double &B, const double &E);

int main(void)
{	
	system("color 4F");
	
	double a,b,e;
	char o;
	
  do
  {
    cout<<"Este Programa realiza la aproximacion"<<endl
	    <<"de raices por el metodo de Posicion Falsa"<<endl<<endl 
	    <<"Ingrese limite inferior"<<endl;
	cin>>a;
	
	cout<<"Ingrese Limite superior"<<endl;
	cin>>b;

	cout<<"Ingrese error"<<endl;
	e=Validar();
	cout<<endl<<endl;
	
	if(Bandera(a,b)==true)
	PF(a,b,e);
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

double Funcion(double A)
{
   return (2*sin(A)-exp(-A));
}

bool Bandera(double &A,double &B)
{
	return((Funcion(A)*Funcion(B)<0));
}

void PF(double &A, double &B, const double &E)
{
	double c;

       if(Bandera(A,B)==true)
	   {
		  c=A+((B-A)*Funcion(A))/(Funcion(A)-Funcion(B));
		  
		  if(abs(Funcion(c))<E)//error
		  	cout<<"la raiz aproximada x= "<<c<<endl;
		  else
		  {
		     cout<<"los limites son "<<A<<" y "<<B<<endl; 	
			 PF(A,c,E);
			 PF(c,B,E);	
	      }
	   }
}
