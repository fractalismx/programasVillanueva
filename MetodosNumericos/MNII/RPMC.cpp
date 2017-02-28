#include<iomanip>
#include<iostream>
#include<cmath>
#include<cstdlib>

using namespace std;

class Medio
{
	private:
	    int I;
	    double *AptA;
	    double *AptB;
	    double *AptX;
	    double *AptY;
	public:
	    Medio(int Interv=1);
	    ~Medio(void);
	    Medio(const Medio &RefM);
	    
	    void Leer(void);
	    void Llenar(void);
	    void Imprimir(void)const;
	    double Funcion(double N)const;
	    double RPM(void)const;
};

Medio::Medio(int Interv)
{
	I=(Interv<1)?1:Interv;
	AptA=new double;
	AptB=new double;
	
    *AptA=0.0;
    *AptB=0.0;
    
    AptX=new double[I+1];
    AptY=new double[I];
    
    for(int i=0;i<(I+1);i++)
    {
		AptX[i]=0.0;
	}
	for(int i=0;i<I;i++)
    {
		AptY[i]=0.0;
	}
}

Medio::~Medio(void)
{
	delete AptA;
	delete AptB;
	delete []AptX;
	delete []AptY;
}

Medio::Medio(const Medio &RefM)
{
	I=RefM.I;
	AptA=new double;
	AptB=new double;
	
	*AptA=*RefM.AptA;
	*AptB=*RefM.AptB;
	
	AptX=new double[I+1];
	AptY=new double[I];
	
	for(int i=0;i<(I+1);i++)
	{
		AptX[i]=RefM.AptX[i];
	}
	
	for(int i=0;i<I;i++)
	{
		AptY[i]=RefM.AptY[i];
	}
	
}

void Medio::Leer(void)
{
	cout<<"Ingrese limite inferior"<<endl;
	cin>>*AptA;
	
	cout<<"Ingrese limite superior"<<endl;
	cin>>*AptB;
	
	Llenar();
}

void Medio::Llenar(void)
{
	double H=(*AptB-*AptA)/I;
	
	for(int i=0;i<(I+1);i++)
	{
		AptX[i]=*AptA+i*H;
	}
	
	for(int j=1;j<(I+1);j++)
	{
		AptY[j-1]=AptX[j-1]+(AptX[j]-AptX[j-1])/2;
	}
}

void Medio::Imprimir(void)const
{
	cout<<"Sus puntos intermedios son"<<endl;
	
	for(int i=0;i<I;i++)
	{
		cout<<"x["<<i<<"] = "<<setprecision(10)<<AptY[i]<<endl;
	}
	
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
   double H=(*AptB-*AptA)/I;
   
   double P[I],RPMC=0;
   
   for(int j=0;j<I;j++)
   {
	   P[j]=Funcion(AptY[j]);
   }
   
   for(int j=0;j<I;j++)
   {
	   RPMC=RPMC+P[j];
   }
   
   return H*RPMC;
}

void Validar(int &RefN);

int main(void)
{
	int N;
	
	Validar(N);
	
	Medio *AptM;
	AptM=new Medio(N);
	
	AptM->Leer();
	AptM->Imprimir();
	
	delete AptM;
	return 0;
}


void Validar(int &RefN)
{
	int V;
	cout<<"Ingrese el numero de Intervalos"<<endl;
	
	do
	{
		cin>>V;
		
		if(V<0)
		{
			cout<<"Ingrese un valor valido"<<endl;
		}
		
	}while(V<0);
	
	RefN=V;
}
