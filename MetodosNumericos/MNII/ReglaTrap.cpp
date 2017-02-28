#include<iostream>
#include<cmath>
#include<iomanip>
#include<cstdlib>

using namespace std;

class Trap
{
	private:
	     double *AptA;
	     double *AptB;
	public:
	    Trap(void);
	    ~Trap(void);
	    Trap(const Trap &RefT);
	    
	    void Leer(void);
	    void Imprimir(void)const;
	    double Funcion(const double N)const;
	    double Trapecio(void)const;
};

Trap::Trap(void)
{
  AptA = new double;
  AptB = new double;
  
  *AptA=0.0;
  *AptB=0.0;
}

Trap::~Trap(void)
{
	delete AptA;
	delete AptB;
}

Trap::Trap(const Trap &RefT)
{
	AptA=new double;
	AptB=new double;
	
	*AptA=*RefT.AptA;
	*AptB=*RefT.AptB;
}

void Trap::Leer(void)
{
	cout<<"Ingrese limite inferior del intervalo"<<endl;
	cin>>*AptA;
	
	cout<<"Ingrese limite superior del intervalo"<<endl;
	cin>>*AptB;
}

double Trap::Funcion(const double N)const
{
	return (exp(pow(N,2)));
}

double Trap::Trapecio(void)const
{
	double M,L;
	M=*AptA; L=*AptB;
	
	return ((*AptB-*AptA)*(Funcion(M)+Funcion(L))/2.0);
}

void Trap::Imprimir(void)const
{
	cout<<"Con el limite inferior de "<<setprecision(10)<<*AptA
	    <<endl<<"y limite superior  de "<<setprecision(10)<<*AptB
	    <<endl<<"La integral definida es aproximadamente igual a"<<endl
	    <<setprecision(10)<<Trapecio()<<endl;
}

int main(void)
{
	Trap *AptT;
	AptT=new Trap;
	
	AptT->Leer();
	
	system("clear");
	
	AptT->Imprimir();
	
	delete AptT;
	
	return 0;
}
