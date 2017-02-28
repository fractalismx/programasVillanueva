#include<cmath>
#include<iostream>
#include<cstdlib>
#include<iomanip>

using namespace std;

void BFibonacci(const double A,const double B,int I);
double Fibonacci(int i);
double Funcion(const double X);
int Numero(const double U);
double Validar(void);

int main(int argc, char **argv)
{
  double Xa;
  double Xb;
  double Er;
  double U;
  int I;
  
  cout<<"Este programa optimiza"<<endl
      <<"la funcion e^(X^2)-ln(X)+sin(2*X-1)"<<endl<<endl
      <<"Ingrese limite inferior"<<endl;
  cin>>Xa;
  
  cout<<"Ingrese Limite superior"<<endl;
  cin>>Xb;
  
  cout<<"Ingrese el epsilon deseado"<<endl;
  Er=Validar();
  
  U=(Xb-Xa)/Er;
  
  I=Numero(U);
  
  cout<<"Iteraciones restantes "<<I-1<<endl;
  BFibonacci(Xa,Xb,I);
  
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

int Numero(const double U)
{
 int i=0;
 bool T=true;
  
    while(T==true)
    {
		if(U<Fibonacci(i))
		break;
                
		i++;
    }
	
  return i;
}

void BFibonacci(const double A,const double B,int I)
{
	double X1,X2,L;
	
	L=B-A;
	
	X1=A+L*(Fibonacci(I-2)/Fibonacci(I));
	X2=A+L*(Fibonacci(I-1)/Fibonacci(I));
	
	if(Funcion(X1)==Funcion(X2))
	{
		cout<<"Su optimo es aproxidamente igual a "
                    <<setprecision(16)<<X1<<endl;	
	}
	else if(Funcion(X1)>Funcion(X2))
	{
		I--;
		cout<<"X1= "<<setprecision(16)
		    <<X1<<endl
		    <<"X2= "<<setprecision(16)
		    <<X2<<endl
		    <<"Iteraciones restantes "<<I-1<<endl;
		
		BFibonacci(X1,B,I);
	}
	else
	{
		I--;
		cout<<"X1= "<<setprecision(16)
		    <<X1<<endl
		    <<"X2= "<<setprecision(16)
		    <<X2<<endl
		    <<"Iteraciones restantes "<<I-1<<endl;
		
		BFibonacci(A,X2,I);
	}
	
}

double Fibonacci(int i)
{
	double F;
	
	if(i==0 || i==1)
	        F=1;
	else
		F=Fibonacci(i-1)+Fibonacci(i-2);
	
	return F;
}

double Funcion(const double X)
{
	return (exp(pow(X,2))-log(X)+sin(2*X-1));
}
