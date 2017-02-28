#include<iostream>
#include<cmath>
#include<iomanip>
#include<cstdlib>

using namespace std;

class Simpson38
{
	private:
	     int Interv;
	     double *AptA;
	     double *AptB;
	     double *AptXi;
	public:
	    Simpson38(int I=3);
	    ~Simpson38(void);
	    Simpson38(const Simpson38 &RefS);
	    
	    void Leer(void);
	    void Llenar(void);
	    void Imprimir(void)const;
	    double Funcion(const double N)const;
	    double S38(void)const;
};

Simpson38::Simpson38(int I)
{
  Interv=(I<3)?3:I;
  
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

Simpson38::~Simpson38(void)
{
	delete AptA;
	delete AptB;
	delete []AptXi;
}

Simpson38::Simpson38(const Simpson38 &RefS)
{
	Interv=RefS.Interv;
	
	AptA=new double;
	AptB=new double;
	
	*AptA=*RefS.AptA;
	*AptB=*RefS.AptB;
	
	AptXi=new double[Interv+1];
	
	for(int i=0;i<(Interv+1);i++)
	{
		AptXi[i]=RefS.AptXi[i];
	}
	
}

void Simpson38::Leer(void)
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

void Simpson38::Llenar(void)
{
	double H=(*AptB-*AptA)/Interv;
	for(int i=0;i<(Interv+1);i++)
	{
		AptXi[i]=*AptA+i*H;
	}
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
	return (log(pow(N,3)-1)/N);
}

double Simpson38::S38(void)const
{
	double P[Interv+1];
	
	double H=(*AptB-*AptA)/Interv;
	double RS38=0;
	
	for(int i=0;i<(Interv+1);i++)
	{
		if(i==0||i==Interv)
		{
			P[i]=Funcion(AptXi[i]);
		}
		else if(i%3!=0)
		{
		    P[i]=3*Funcion(AptXi[i]);
		}
		else
		{
			P[i]=2*Funcion(AptXi[i]);
		}
	}
	
	for(int i=0;i<(Interv+1);i++)
	{
		RS38=RS38+P[i];
	}
	
	return 3.0*H*RS38/8.0;
}

void Validar(int &RefN);

int main(void)
{
	int N;
	
	Validar(N);
	
	Simpson38 *AptS38;
	AptS38=new Simpson38(N);
	
	AptS38->Leer();
	
	AptS38->Imprimir();
	
	delete AptS38;
}

void Validar(int &RefN)
{
	int V;
	
	cout<<"Ingrese el numero de intervalos"<<endl;
	
	do
	{
		cin>>V;
		
		if(V<3 || V%3!=0)
		{
			cout<<"Ingrese numero de intervalos valido"<<endl;
		}
	}while(V<3 || V%3!=0);
	
	RefN=V;
}
