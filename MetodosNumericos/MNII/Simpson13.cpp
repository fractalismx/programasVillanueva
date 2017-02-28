#include<iostream>
#include<cmath>
#include<cstdlib>
#include<iomanip>

using namespace std;

class Simpson13
{
	private:
	     double *AptA;
	     double *AptB;
	public:
	    Simpson13(void);
	    ~Simpson13(void);
	    Simpson13(const Simpson13 &RefS);
	    
	    void Leer(void);
	    void Imprimir(void)const;
	    double Funcion(const double N)const;
	    double S13(void)const;
};

Simpson13::Simpson13(void)
{
  AptA = new double;
  AptB = new double;
  
  *AptA=0.0;
  *AptB=0.0;
}

Simpson13::~Simpson13(void)
{
	delete AptA;
	delete AptB;
}

Simpson13::Simpson13(const Simpson13 &RefS)
{
	AptA=new double;
	AptB=new double;
	
	*AptA=*RefS.AptA;
	*AptB=*RefS.AptB;
}

void Simpson13::Leer(void)
{
	cout<<"Ingrese limite inferior del intervalo"<<endl;
	cin>>*AptA;
	
	cout<<"Ingrese limite superior del intervalo"<<endl;
	cin>>*AptB;
}

void Simpson13::Imprimir(void)const
{
	cout<<"Con el limite inferior de "<<setprecision(10)<<*AptA
	    <<endl<<"y limite superior  de "<<setprecision(10)<<*AptB
	    <<endl<<"La integral definida es aproximadamente igual a"<<endl
	    <<setprecision(10)<<S13()<<endl;
}

double Simpson13::Funcion(const double N)const
{
	return (exp(pow(N,2)));
}

double Simpson13::S13(void)const
{
	double P[3];
	
	double J=(*AptB-*AptA)/2.0;
	
	for(int i=0;i<3;i++)
	{
		P[i]=*AptA+i*J;
	}
	
	return J*(Funcion(P[0])+4*Funcion(P[1])+Funcion(P[2]))/3.0;
}

int main(void)
{
	Simpson13 *AptS13;
	AptS13=new Simpson13;
	
	AptS13->Leer();
	
	system("clear");
	
	AptS13->Imprimir();
	
	delete AptS13;
}
