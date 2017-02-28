#include<iostream>
#include<cmath>
#include<cstdlib>
#include<iomanip>

using namespace std;

class Trap
{	
	private:
	     int Interv;
	     double *AptA;
	     double *AptB;
	     double *AptXi;
	public:
	    Trap(int I=1);
	    ~Trap(void);
	    Trap(const Trap &RefT);
	    
	    void Leer(void);
	    void Imprimir(void);
	    double Funcion(const double N);
	    double Trapecio(void);
};

Trap::Trap(int I)
{
  Interv=(I<1)?1:I;
  
  AptA = new double;
  AptB = new double;
  
  *AptA=0.0;
  *AptB=0.0;
  
  AptXi=new double[Interv+1];
  
  for(int i=0;i<=Interv;i++)
  {
	  AptXi[i]=0.0;
  }
}

Trap::~Trap(void)
{
	delete []AptXi;
	delete AptA;
	delete AptB;
}

Trap::Trap(const Trap &RefT)
{
	Interv=RefT.Interv;
	
	AptA=new double;
	AptB=new double;
	
	*AptA=*RefT.AptA;
	*AptB=*RefT.AptB;
	
	AptXi=new double[Interv+1];
	
	for(int i=0;i<(Interv+1);i++)
	{
		AptXi[i]=RefT.AptXi[i];
	}
}

void Trap::Leer(void)
{
	cout<<"Ingrese limite inferior del intervalo"<<endl;
	cin>>*AptA;
	
	cout<<"Ingrese limite superior del intervalo"<<endl;
	cin>>*AptB;
	
}

double Trap::Funcion(const double N)
{
	return (log(pow(N,3)-1)/N);
}

double Trap::Trapecio(void)
{
	double H=(*AptB-*AptA)/(Interv);
	
	cout<<H<<endl;
	
	for(int i=0;i<(Interv+1);i++)
	{
		AptXi[i]=*AptA+i*H;
	}
	
	double Suma[Interv+1],RTC=0;
	
	for(int i=0;i<(Interv+1);i++)
	{
		if(i==0||i==Interv)
		{
			Suma[i]=Funcion(AptXi[i]);
		}
		else
		{
			Suma[i]=2*Funcion(AptXi[i]);
		}
	}
	
	for(int i=0;i<=Interv;i++)
	{
		RTC=RTC+Suma[i];
	}
   
   return (H*RTC)/2.0;
}

void Trap::Imprimir(void)
{
		
	cout<<"Con el limite inferior de "<<setprecision(10)<<*AptA
	    <<endl<<"y limite superior  de "<<setprecision(10)<<*AptB
	    <<endl<<"con "<<Interv<<" intervalos"
	    <<endl<<"La integral definida es aproximadamente igual a"<<endl
	    <<setprecision(10)<<Trapecio()<<endl;
}

void Validar(int &RefN);

int main(void)
{
	int N;
	
	Validar(N);
	
	Trap *AptT;
	AptT=new Trap(N);
	
	AptT->Leer();
		
	AptT->Imprimir();
	
	delete AptT;
	
	return 0;
}

void Validar(int &RefN)
{
	int V;
	
	cout<<"ingrese numero de intervalos"<<endl;
	
	do
	{
		cin>>V;
		
		if(V<1)
		{
			cout<<"Ingrese numero de intervalos valido"<<endl;
		}
	}while(V<1);
	
	RefN=V;
}

