#include<cmath>
#include<iostream>
#include<cstdlib>
#include<iomanip>
#include<cstdio>

using namespace std;

void EstImp(double &A, double &B, double &E);
double Funcion(double X);
void Parametros(double &a0, double &a1, double &a2,double &A, double &B, double &X2);
double Validar(void);

int main (void)
{
	double A,B,E;
	
	cout<<"Este programa calcula min de una variable por el metodo de interpolacion"<<endl
		<<"optimiza (2*(X^2)+16/X)"<<endl<<endl
	    <<"Teclee Limite inferior"<<endl;
	cin>>A;
	
	cout<<"Teclee limite superior"<<endl;
	cin>>B;
	
	cout<<"teclee el error deseado"<<endl;
	E=Validar();

	cout<<endl;
	
	EstImp(A,B,E);

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
		{
			cout<<"No es posible determinar el valor"<<endl;
		}
	}while(V<=0);
	
	return V;
}

double Funcion(double X)
{
	return(2*pow(X,2)+16/X);
}

void EstImp(double &A, double &B, double &E)
{
     double X2=(A+B)/2.0;
     double Ve;
     double a0,a1,a2;
     
     Parametros(a0,a1,a2,A,B,X2);
     
     Ve=((A+X2)-a1/a2)/2.0;
    
    if(abs(B-A)<E)
    {
        if(Funcion(Ve)<Funcion(X2))
        {
			cout<<A<<endl
			    <<B<<endl
			    <<Ve<<endl
			    <<X2<<endl;
			    
			cout<<"Su optimo fue "<<setprecision(16)<<Ve<<endl<<endl;
        }
        else if(Funcion(X2)<Funcion(Ve))
        {
			cout<<setprecision(16)<<A<<endl
			    <<setprecision(16)<<B<<endl
			    <<setprecision(16)<<Ve<<endl
			    <<setprecision(16)<<X2<<endl;
			    
			cout<<"Su optimo fue "<<setprecision(16)<<X2<<endl<<endl;
        }
    }
    else
    {
        if(Funcion(Ve)<Funcion(X2) && Ve<X2)
        {
			cout<<setprecision(16)<<A<<endl
			    <<setprecision(16)<<B<<endl
			    <<setprecision(16)<<Ve<<endl
			    <<setprecision(16)<<X2<<endl;
			    
			cout<<"Su optimo fue "<<setprecision(16)<<Ve<<endl<<endl;
			EstImp(A,X2,E);
		}
		else if(Funcion(Ve)>Funcion(X2) && Ve<X2)
		{
			cout<<setprecision(16)<<A<<endl
			    <<setprecision(16)<<B<<endl
			    <<setprecision(16)<<Ve<<endl
			    <<setprecision(16)<<X2<<endl;
			    
			cout<<"Su optimo fue "<<setprecision(16)<<X2<<endl<<endl;
			EstImp(Ve,B,E);
		}
		else if(Funcion(Ve)<Funcion(X2) && Ve>X2)
		{
		    cout<<setprecision(16)<<A<<endl
			    <<setprecision(16)<<B<<endl
			    <<setprecision(16)<<Ve<<endl
			    <<setprecision(16)<<X2<<endl;
			    
			cout<<"Su optimo fue "<<setprecision(16)<<Ve<<endl<<endl;
			EstImp(X2,B,E);	
		}
		else
		{
		    cout<<setprecision(16)<<A<<endl
			    <<setprecision(16)<<B<<endl
			    <<setprecision(16)<<Ve<<endl
			    <<setprecision(16)<<X2<<endl;
			    
			cout<<"Su optimo fue "<<setprecision(16)<<Ve<<endl<<endl;
			EstImp(A,Ve,E);	
		}
    }   
}

void Parametros(double &a0, double &a1, double &a2, double &A, double &B, double &X2)
{
	a0=Funcion(A);
	
	a1=(Funcion(X2)-a0)/(X2-A);
	
	double V;
	
	V=((Funcion(B)-Funcion(A))/(B-A))-a1;
	
	a2=V/(B-X2);
}
