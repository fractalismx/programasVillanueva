#include<cstdlib>
#include<cmath>
#include<iostream>
#include<iomanip>

using namespace std;

class Newton
{
  private:
          int P;
          double A;
          double *AptX;
          double **AptY;
  public:
         Newton(int Pu=2,double h=1);
         ~Newton(void);
         Newton(const Newton &RefN);

         void Leer(void);
         void Imprimir(void)const;
         bool Validar(double h[]);
         void Diferencias(void);
         double Polinomio(void)const;
};

Newton::Newton(int Pu,double h)
{
  P=Pu;
  A=h;

  AptX=new double[P];
  AptY=new double *[P];
  
  for(int j=0;j<P;j++)
  {
  	AptY[j]= new double[P];
  }

  for(int i=0;i<P;i++)
  {
   AptX[i]=0;
  }
  
  for(int i=0;i<P;i++)
  {
  	for(int j=0;j<P;j++)
  	{
  	  AptY[i][j]=0;
	}
  }
}

Newton::~Newton(void)
{
  delete []AptX;
  
  for(int i=0;i<P;i++)
   delete []AptY[i];
  
  delete []AptY;
}

Newton::Newton(const Newton &RefN)
{
   P=RefN.P;
   A=RefN.A;
   
   AptX=new double[P];
   AptY=new double *[P];
   
   for(int i=0;i<P;i++)
   {
   	AptY[i]=new double[P];
   }
   
   for(int i=0;i<P;i++)
   {
   	for(int j=0;j<P;j++)
   	{
   		AptY[i][j]=RefN.AptY[i][j];
	}
   }

   for(int i=0;i<P;i++)
   {
    AptX[i]=RefN.AptX[i];
   }
}

void Newton::Leer(void)
{
  cout<<"ingrese los valores para aproximar en x "<<endl;
  
  double h[P];

  do
  {
    for(int i=0;i<P;i++)
    {
      cout<<"Ingrese la X_"<<i<<endl;
      cin>>h[i];
    }
   
    if(Validar(h)==false)
    {
     cout<<"no ingrese X repetidas"<<endl;
    }

  }while(Validar(h)==false);

  for(int i=0;i<P;i++)
  {
   AptX[i]=h[i];
  }

  for(int i=0;i<P;i++)
  {
    cout<<"Ingrese la Y_"<<i<<endl;
    cin>>AptY[i][0];
  }
  
  cout<<"ingrese el valor a calcular su f(X)"<<endl;
  cin>>A;
  
  Diferencias();
}

double Newton::Polinomio(void)const
{
	int B=P;
	double V[B];
	double H=0;
	
    	for(int j=0;j<B;j++)
		{
			V[j]=1;
		}

	for(int i=P;i>=1;i--)
	{
		for(int j=0;j<B;j++)
		{   
			V[i]=V[i]*(A-AptX[j]);
		}
	  B--;
    }
    
    for(int k=0;k<P;k++)
    {
    	H=H+V[k]*AptY[0][k];
	}
    
    return H;
}

bool Newton::Validar(double h[])
{
  bool Bandera;
 for(int j=0;j<P;j++)
 {
   for(int i=j;i<P;i++)
   {
      if(h[i]==h[i+1])
      {
        Bandera=false;
      }
      else
      {
       Bandera=true;
      }
    break;
   }
  if(Bandera==false)
  break;
 }
  return Bandera;
}

void Newton::Imprimir(void)const
{
 for(int i=0;i<P;i++)
  {
    cout<<"X= "<<setprecision(10)
        <<AptX[i]<<endl;
  }
  
  for(int i=0;i<P;i++)
  {
    for(int j=0;j<P;j++)
    {
      if(AptY[j][i]!=0)
	  cout<<"diferencia dividida de "<<i
	      <<" orden = "
	      <<setprecision(10)
	      <<AptY[j][i]<<endl;
	  else
	  cout<<' ';
    }
    
    cout<<endl;
  }
  
  cout<<"f("<<A<<")="
      <<setprecision(10)
      <<Polinomio()<<endl;
}

void Newton::Diferencias(void)
{
  for(int j=1;j<P;j++)
  {
  	for(int i=0;i<P-j;i++)
  	{
  		AptY[i][j]=(AptY[i+1][j-1]-AptY[i][j-1])/(AptX[i+j]-AptX[i]);
	}
  }
}

void NP(int &RefP);

int main(void)
{
  int p;
  
  NP(p);

  Newton *AptN;
  AptN = new Newton(p);

  AptN->Leer();
  AptN->Imprimir();

  delete AptN;
  return 0;
}

void NP(int &RefP)
{
  int V;
  do
  {
   cout<<"Teclee numero de puntos a valuar"<<endl;
   cin>>V;
   
   if(V<=0)
   {
    cout<<"Valor no valido"<<endl;
   }
  }while(V<=0);
RefP=V;
}
