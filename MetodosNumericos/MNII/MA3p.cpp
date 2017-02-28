#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstdlib>

using namespace std;

class Puntos3
{
  private:
	double *AptA;
	double *AptB;
	double *AptX;
  public:
  	Puntos3(void);
  	~Puntos3(void);
  	Puntos3(const Puntos3 &RefP);
  	
  	void Leer(void);
  	void Imprimir(void)const;
  	double Integral(void)const;
  	double Funcion(double N)const;
};

Puntos3::Puntos3(void)
{
	AptA=new double;
	AptB=new double;
	
	AptX=new double[3];
	
	for(int i=0;i<3;i++)
	{
		AptX[i]=0.0;
	}
}

Puntos3::~Puntos3(void)
{
	delete AptA;
	delete AptB;
	delete []AptX;
}

Puntos3::Puntos3(const Puntos3 &RefP)
{
	AptA=new double;
	AptB=new double;
	
	AptX=new double[3];
	
	for(int i=0;i<3;i++)
	{
		AptX[i]=RefP.AptX[i];
	}
}

void Puntos3::Leer(void)
{
	cout<<"ingrese limite inferior"<<endl;
	cin>>*AptA;
	
	cout<<"ingrese limite superior"<<endl;
	cin>>*AptB;
	
	double H=(*AptB-*AptA)/4;
	
	for(int i=0;i<3;i++)
	{
		AptX[i]=*AptA+(i+1)*H;
	}
	for(int i=0;i<3;i++)
	{
		cout<<setprecision(10)<<AptX[i]<<endl;
	}
}

void Puntos3::Imprimir(void)const
{
   cout<<"Con un limite inferior de "<<setprecision(10)
       <<*AptA<<endl
       <<"y superior de "<<setprecision(10)
       <<*AptB<<endl
       <<"es "<<setprecision(10)<<Integral()<<endl;
}

double Puntos3::Funcion(double N)const
{
	return(sin(N)/sqrt(N));
}

double Puntos3::Integral(void)const
{
	double H=(*AptB-*AptA)/4;
	
	double G;
	
	G=2*Funcion(AptX[0])-Funcion(AptX[1])+2*Funcion(AptX[2]);
	
	return (4*H*G)/3;
}

int main(void)
{
	Puntos3 *AptP;
	AptP=new Puntos3;
	
	AptP->Leer();
	
	AptP->Imprimir();
	
	delete AptP;
	return 0;
}
