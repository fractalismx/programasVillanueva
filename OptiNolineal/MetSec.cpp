#include<iostream>
#include<cstdlib>
#include<cmath>
#include<iomanip>

using namespace std;

double Validar(void);
double Num(double A,double B);
double Ren(double A,double B);
double Funcion(double A);
void MS(double A, double B, const double E);

int main(void)
{
	double a,b,e;
	char o;
	
  do
  {
    cout<<"Este Programa realiza la aproximacion"<<endl
	    <<"de optimos por el metodo de Cuasi-Newton"<<endl
		<<"optimiza e^(A^2)-ln(A)+sin(2*A-1)"<<endl 
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

  system("pause =>NULL");
        
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
			cout<<"No es posible determinar el valor"<<endl;
		}
	}while(V<=0);
	
	return V;
}

double Funcion(double A)
{ 
    double h;
  
    h=exp(pow(A,2))-log(A)+sin(2*A-1);
	
	return h;
}

double DeO1(double A)
{
	return ((Funcion(A+0.00000001)-Funcion(A-0.00000001))/(2*0.00000001));
}

double Num(double A,double B)
{
   return (DeO1(B)*(B-A));	
}

double Den(double A,double B)
{
	return (DeO1(B)-DeO1(A));
}

void MS(double A,double B, const double E)
{
	double c;
		  c=B-(Num(A,B)/Den(A,B));

		  if(abs(DeO1(c))<E)
		  {
			cout<<"Valor cercano1 ="
			    <<setprecision(16)<<A<<endl
			    <<"Valor cercano2 ="
			    <<setprecision(16)<<B<<endl
				<<"el optimo aproximado x= "
				<<setprecision(16)<<c<<endl;
		  }
		  else
		  {	
		    cout<<"Valor cercano1 ="
		        <<setprecision(16)<<A<<endl
			    <<"Valor cercano2 ="
			    <<setprecision(16)<<B<<endl
				<<"la raiz aproximada x= "
				<<setprecision(16)<<c<<endl;
			 MS(B,c,E);	
	      }
}
