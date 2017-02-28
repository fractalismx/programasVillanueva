#include<iomanip>
#include<iostream>
#include<cmath>
#include<cstdlib>

using namespace std;

class Dif
{
	private:
		double X;
		double h;
	public:
		Dif(double Xi=0,double hi=0.0001);
		~Dif(void);
		Dif(const Dif &RefD);
		
		void Leer(void);
		void Imprimir(void);
		double Val(void);
		double Funcion(double N)const;
		double Calculo(void)const;
};

Dif::Dif(double Xi,double hi)
{
	X=Xi;
	h=(hi<=0)?0.0001:hi;
}

Dif::~Dif(void)
{
	
}

Dif::Dif(const Dif &RefD)
{
	X=RefD.X;
	h=RefD.h;
}

void Dif::Leer(void)
{
	cout<<"ingrese el valor para calcular la derivada"<<endl;
	cin>>X;
	
	cout<<"ingrese el incremento"<<endl;
	cin>>h;
}

double Dif::Val(void)
{
	double V;
	
	do
	{
		cin>>V;
		if(V==0)
		{
			cout<<"ingrese un incremento valido"<<endl;
		}
	}while(V==0);
	
	return V;
}

void Dif::Imprimir(void)
{
	cout<<"La derivada en X "
	    <<setprecision(10)<<X<<endl
	    <<" con un incremento de "
		<<setprecision(10)<<h<<endl
		<<"es "<<setprecision(10)<<Calculo()<<endl;
}

double Dif::Funcion(double N)const
{
	return( log( sqrt(pow(N,3)-N )) / (pow((3*N-7),4) ) );
}

double Dif::Calculo(void)const
{
	double D,N;
	
	D=Funcion(X-2*h)-Funcion(X+2*h)-8*(Funcion(X-h)-Funcion(X+h));
	N=12*h;
	
	return(D/N);
}

int main(void)
{
	Dif *AptD;
	AptD=new Dif;
	
	AptD->Leer();
	
	system("cls");
	
	AptD->Imprimir();
	
	return 0;
}
