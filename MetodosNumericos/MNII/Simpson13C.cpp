#include<iostream>
#include<cmath>
#include<cstdlib>

using namespace std;

class Simpson13
{
	private:
	     int Interv;
	     double *AptA;
	     double *AptB;
	     double *AptXi;
	public:
	    Simpson13(int I=2);
	    ~Simpson13(void);
	    Simpson13(const Simpson13 &RefS);
	    
	    void Leer(void);
	    void Imprimir(void)const;
	    void Llenar(void);
	    double Funcion(const double N)const;
	    double S13(void)const;
};

Simpson13::Simpson13(int I)
{
  Interv=(I<2)?2:I;
	
  AptA = new double;
  AptB = new double;
  
  *AptA=0.0;
  *AptB=0.0;
  
  AptXi=new double[Interv+1];
  
  for(int i=0;i<(Interv+1);i++)
  {
	  AptXi[i]=0.0;
  }
}

Simpson13::~Simpson13(void)
{
	delete AptA;
	delete AptB;
	delete []AptXi;
}

Simpson13::Simpson13(const Simpson13 &RefS)
{
	Interv=RefS.Interv;
	
	AptA=new double;
	AptB=new double;
	
	*AptA=*RefS.AptA;
	*AptB=*RefS.AptB;
	
	AptXi=new double[Interv];
	
	for(int i=0;i<(Interv+1);i++)
	{
		AptXi[i]=RefS.AptXi[i];
	}
}

void Simpson13::Leer(void)
{
	cout<<"Ingrese limite inferior del intervalo"<<endl;
	cin>>*AptA;
	
	cout<<"Ingrese limite superior del intervalo"<<endl;
	cin>>*AptB;
	
	Llenar();
	
	for(int i=0;i<(Interv+1);i++)
	{
		cout<<AptXi[i]<<endl;
	}
}

void Simpson13::Imprimir(void)const
{
	cout<<"Con el limite inferior de "<<*AptA
	    <<endl<<"y limite superior  de "<<*AptB
	    <<endl<<"La integral definida es aproximadamente igual a"<<endl
	    <<S13()<<endl;
}

void Simpson13::Llenar(void)
{
    double J=(*AptB-*AptA)/Interv;
	
	for(int i=0;i<(Interv+1);i++)
	{
		AptXi[i]=*AptA+i*J;
	}
}

double Simpson13::Funcion(const double N)const
{
	return (exp(pow(N,2)));
}

double Simpson13::S13(void)const
{
	double P[Interv+1],RS13=0;
	
	double J=(*AptB-*AptA)/Interv;
	
	for(int i=0;i<(Interv+1);i++)
	{
		if(i==0 || i==Interv)
		{
			P[i]=Funcion(AptXi[i]);
		}
		else if(i%2!=0)
		{
			P[i]=4*Funcion(AptXi[i]);
		}
		else
		{
			P[i]=2*Funcion(AptXi[i]);
		}
	}
	
	for(int i=0;i<(Interv+1);i++)
	{
		RS13=RS13+P[i];
	}
	
	return J*RS13/3;
}

void Validar(int &RefI);

int main(void)
{
	int N;
	
	Validar(N);
	
	Simpson13 *AptS13;
	AptS13=new Simpson13(N);
	
	AptS13->Leer();
	
	AptS13->Imprimir();
	
	delete AptS13;
}

void Validar(int &RefN)
{
	int V;
	
	cout<<"ingrese numero de intervalos"<<endl;
	
	do
	{
		cin>>V;
		
		if(V<2 || V%2!=0)
		{
			cout<<"Ingrese numero de intervalos valido"<<endl;
		}
		
	}while(V<2 || V%2!=0);
	
	RefN=V;
}
