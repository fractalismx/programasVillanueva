#include<cmath>
#include<iostream>
#include<cstdlib>
#include<iomanip>

using namespace std;

double Validar(void);
double Funcion(const double X);
void Biseccion(const double Xa, const double Xb, const double Er);
void Imprimir(const double Xa, const double Xb, const double Er);

int main(void)
{
  double Xa;
  double Xb;
  double Er;
  
  cout << "este programa utiliza el metodo de Biseccion" << endl
	  << "optimiza la funcion e^(X^2)-ln(X)+sin(2*X-1)" << endl;

  cout<<"Ingrese limite inferior"<<endl;
  cin>>Xa;
  
  cout<<"Ingrese Limite superior"<<endl;
  cin>>Xb;
  
  cout<<"Ingrese el epsilon deseado"<<endl;
  Er=Validar();
  
  Biseccion(Xa,Xb,Er);
  
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

double Funcion(const double X)
{
	return (exp(pow(X,2))-log(X)+sin(2*X-1));
}

void Biseccion(const double Xa, const double Xb, const double Er)
{
	double Xm;
	double Xl;
	double Xr;
	
	Xm=(Xa+Xb)/2.0;
	Xl=(Xa+Xm)/2.0;
	Xr=(Xm+Xb)/2.0;
	
	if(abs(Xb-Xa)<Er)
	{
		Imprimir(Xa,Xb,Er);
	}
	else
	{
		if((Funcion(Xa)<Funcion(Xl) && Funcion(Xa)<Funcion(Xm) && Funcion(Xa)<Funcion(Xr) && Funcion(Xa)<Funcion(Xb)) 
		   ||(Funcion(Xl)<Funcion(Xa) && Funcion(Xl)<Funcion(Xm) && Funcion(Xl)<Funcion(Xr) && Funcion(Xl)<Funcion(Xb)))
		{
			Biseccion(Xa,Xm,Er);
	    }
	    else if(Funcion(Xm)<Funcion(Xa) && Funcion(Xm)<Funcion(Xl) && Funcion(Xm)<Funcion(Xr) && Funcion(Xm)<Funcion(Xb)) 
		{
			Biseccion(Xl,Xr,Er);
		}
		else if((Funcion(Xb)<Funcion(Xa) && Funcion(Xb)<Funcion(Xl) && Funcion(Xb)<Funcion(Xm) && Funcion(Xa)<Funcion(Xr)) 
		   ||(Funcion(Xr)<Funcion(Xa) && Funcion(Xr)<Funcion(Xl) && Funcion(Xr)<Funcion(Xm) && Funcion(Xr)<Funcion(Xb)))
		{
			Biseccion(Xm,Xb,Er);
		}
	}
}

void Imprimir(const double Xa, const double Xb, const double Er)
{
	double Xm;
	
	Xm=(Xa+Xb)/2.0;
	
	cout<<"Su optimo aproximado"
	    <<endl
	    <<"con un error de "
	    <<setprecision(16)
	    <<Er<<" es ";
	
	if(Funcion(Xm)<Funcion(Xa) && Funcion(Xm)<Funcion(Xb))
	{
		cout<<"Xo= "<<setprecision(16)<<Xm<<endl;
	}
	else if(Funcion(Xa)<Funcion(Xb) && Funcion(Xa)<Funcion(Xm))
	{
		cout<<"Xo= "<<setprecision(16)<<Xa<<endl;
	}
	else if(Funcion(Xb)<Funcion(Xm) && Funcion(Xb)<Funcion(Xa))
	{
		cout<<"Xo= "<<setprecision(16)<<Xb<<endl;
	}
}
