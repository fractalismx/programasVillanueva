#include<iostream>
#include<cmath>
#include<iomanip>
#include<cstdlib>

using namespace std;

class Simpson38
{
	private:
	     double *AptA;
	     double *AptB;
	public:
	    Simpson38(void);
	    ~Simpson38(void);
	    Simpson38(const Simpson38 &RefS);
	    
	    void Leer(void);
	    void Imprimir(void)const;
	    double Funcion(const double N)const;
	    double S38(void)const;
};

Simpson38::Simpson38(void)
{
  AptA = new double;
  AptB = new double;
  
  *AptA=0.0;
  *AptB=0.0;
}

Simpson38::~Simpson38(void)
{
	delete AptA;
	delete AptB;
}

Simpson38::Simpson38(const Simpson38 &RefS)
{
	AptA=new double;
	AptB=new double;
	
	*AptA=*RefS.AptA;
	*AptB=*RefS.AptB;
}

void Simpson38::Leer(void)
{
	cout<<"Ingrese limite inferior del intervalo"<<endl;
	cin>>*AptA;
	
	cout<<"Ingrese limite superior del intervalo"<<endl;
	cin>>*AptB;
}

void Simpson38::Imprimir(void)const
{
	cout<<"Con el limite inferior de "<<setprecision(10)<<*AptA
	    <<endl<<"y limite superior  de "<<setprecision(10)<<*AptB
	    <<endl<<"La integral definida es aproximadamente igual a"<<endl
	    <<setprecision(10)<<S38()<<endl;
}

double Simpson38::Funcion(const double N)const
{
	return (exp(pow(N,2)));
}

double Simpson38::S38(void)const
{
	double P[4];
	
	double J=(*AptB-*AptA)/3;
	
	for(int i=0;i<4;i++)
	{
		P[i]=*AptA+i*J;
	}
	
	return 3.0*J*(Funcion(P[0])+3*Funcion(P[1])
	                     +3*Funcion(P[2])+Funcion(P[3]))/8.0;
}

int main(void)
{
	Simpson38 *AptS38;
	AptS38=new Simpson38;
	
	AptS38->Leer();
	
	system("clear");
	
	AptS38->Imprimir();
	
	delete AptS38;
}
