#include<iomanip>
#include<iostream>
#include<cmath>
#include<cstdlib>

using namespace std;

class Medio
{
	private:
	    double *AptA;
	    double *AptB;
	public:
	    Medio(void);
	    ~Medio(void);
	    Medio(const Medio &RefM);
	    
	    void Leer(void);
	    void Imprimir(void)const;
	    double Funcion(double N)const;
	    double RPM(void)const;
};

Medio::Medio(void)
{
	AptA=new double;
	AptB=new double;
	
    *AptA=0.0;
    *AptB=0.0;
}

Medio::~Medio(void)
{
	delete AptA;
	delete AptB;
}

Medio::Medio(const Medio &RefM)
{
	AptA=new double;
	AptB=new double;
	
	*AptA=*RefM.AptA;
	*AptB=*RefM.AptB;
}

void Medio::Leer(void)
{
	cout<<"Ingrese limite inferior"<<endl;
	cin>>*AptA;
	
	cout<<"Ingrese limite superior"<<endl;
	cin>>*AptB;
}

void Medio::Imprimir(void)const
{
	cout<<"La integral con limite inferior "<<setprecision(10)
	    <<*AptA<<endl
	    <<"y limite superior "<<setprecision(10)
	    <<*AptB<<endl
	    <<"es "<<setprecision(10)<<RPM()<<endl;
}

double Medio::Funcion(double N)const
{
	return(sin(N)/N);
}

double Medio::RPM(void)const
{
   double H=*AptB-*AptA;
   
   cout<<setprecision(10)<<H<<endl
       <<setprecision(10)<<*AptA+H/2<<endl;
   
   return (H*Funcion(*AptA+H/2));
}

int main(void)
{
	Medio *AptM;
	AptM=new Medio;
	
	AptM->Leer();
	AptM->Imprimir();
	
	delete AptM;
	return 0;
}
