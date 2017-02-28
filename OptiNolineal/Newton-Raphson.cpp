#include<iostream>
#include<cstdlib>
#include<cmath>
#include<iomanip>

using namespace std;

double Validar(void);
double DeO1(double A);
double DeO2(double A);
double Funcion(double A);
void NR(double &A, const double &E);

int main(void)
{	
	double a,e;
	char o;
	
  do
  {
    cout<<"Este Programa realiza la aproximacion"<<endl
	    <<"de optimos por el metodo de Newton-Raphson"<<endl
		<<"optimiza e^(X^2)-ln(X)+sin(2*X-1)"<<endl<<endl 
	    <<"Ingrese numero cercano al optimo"<<endl;
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
    return(exp(pow(A,2))-log(A)+sin(2*A-1));
}

double DeO1(double A)
{
	return ((Funcion(A+0.0000001)-Funcion(A-0.0000001))/(0.0000002));
}
double DeO2(double A)
{
	return ((Funcion(A+0.0000001)-2*Funcion(A)+Funcion(A-0.0000001))/pow(0.0000001,2));
}

void NR(double &A, const double &E)
{
    double c;
    
       if(abs(DeO1(A))<E)
	   {
		  	cout<<"el optimo aproximado es x= "<<setprecision(16)<<A<<endl;
       }
       else
       {
		    cout<<"el optimo aproximado es x= "<<setprecision(16)<<A<<endl;
            
            c=A-(DeO1(A))/(DeO2(A));
            NR(c,E);
       }
	   
}
