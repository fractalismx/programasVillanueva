#include<iostream>
#include<cstdlib>
#include<cmath>

using namespace std;

double Validar(void);
double FuncionD(double A);
double Funcion(double A);
void NR(double &A, const double &E);

int main(void)
{	
	double a,e;
	char o;
	
  do
  {
    cout<<"Este Programa realiza la aproximacion"<<endl
	    <<"de raices por el metodo de Newton-Raphson"<<endl<<endl 
	    <<"Ingrese numero cercano a la raiz"<<endl;
	cin>>a;

	cout<<"Ingrese error"<<endl;
	e=Validar();
	cout<<endl<<endl;
	
    NR(a,e);
    
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
    return(3*pow(A,2)-exp(A));
}

double FuncionD(double A)
{
    return(6*A-exp(A));
}

void NR(double &A, const double &E)
{
    double c;
    
    cout<<A<<endl
        <<E<<endl
        <<Funcion(A)<<endl
        <<FuncionD(A)<<endl;
    
       if(abs(Funcion(A))<E)
	   {
		  	cout<<"la raiz aproximada x= "<<A<<endl;
       }
       else
       {
            c=A-(Funcion(A))/(FuncionD(A));
            NR(c,E);
       }
	   
}
