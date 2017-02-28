#include<cstdlib>
#include<cmath>
#include<iostream>

using namespace std;

class Cardinal
{    
  private:
      int P;
      double a;
      double b;
      int PC;
      double *AptPuntos;
      double *AptFu;
  public:
      Cardinal(int np=1,double A=0,double B=0,int PC1=0);
      ~Cardinal(void);
      Cardinal(const Cardinal &RefL);
      
      void Leer(void);
      void Imprimir(void)const;
      void Funcion(void);
      double Polinomio(double A)const;
      double Riemann(void)const;
};

Cardinal::Cardinal(int np,double A,double B,int PC1)
{
    P=(np<1)?1:np;
    a=A;
    b=B;
    PC=PC1;
    AptPuntos = new double[P];
    AptFu = new double[P];
    
    for(int i=0;i<P;i++)
        AptPuntos[i]=0.0;
    
    for(int j=0;j<P;j++)
        AptFu[j]=0.0;
    
}

Cardinal::~Cardinal(void)
{
    delete []AptPuntos;
    delete []AptFu;
}

Cardinal::Cardinal(const Cardinal &RefL)
{
    P=RefL.P;
    a=RefL.a;
    b=RefL.b;
    PC=RefL.PC;
    AptPuntos = new double[P];
    AptFu = new double[P];
     
    for(int i=0;i<P;i++)
        AptPuntos[i]=RefL.AptPuntos[i];
}

double Cardinal::Polinomio(double A)const
{
   double L,Y=0;
   for(int i=0;i<P;i++)
   {
    L=1;
       for(int j=0;j<P;j++)
       {
         if(i!=j)
         {   
         L=L*(A-AptPuntos[j])/(AptPuntos[i]-AptPuntos[j]);
         }
        }
     Y=Y+L*AptFu[i];
   }
 
  return Y;
}

double Cardinal::Riemann(void)const
{
	double J=0;
        double SR[PC],f[PC];
	double h;

	h=(b-a)/(PC);
	
	for(int i=0;i<PC;i++)
	{
		SR[i]=a+(i+1)*h;
	}
	
	for(int j=0;j<PC;j++)
	{
		f[j]=Polinomio(SR[j]);
		J=J+f[j];
	}
	
	cout<<J<<endl;
	
    return (h*J);
}

void Cardinal::Leer(void)
{
    cout<<"Ingrese las x a valuar"<<endl;
    
    for(int i=0;i<P;i++)
    {   
        cout<<"Ingrese la x"<<i<<endl;
        cin>>AptPuntos[i];
    }
    
   cout<<"ingrese el numero de particiones"<<endl;
   cin>>PC;

   cout<<"ingrese el lim inferior"<<endl;
   cin>>a;
    cout<<"ingrese el lim superior"<<endl;
   cin>>b;
}

void Cardinal::Funcion(void)
{
    for(int i=0;i<P;i++)
    {
      AptFu[i]=(sin(exp(pow(AptPuntos[i],2)))-1);
    }    
}

void Cardinal::Imprimir(void) const
{
    for(int i=0;i<P;i++)
    {
        cout<<"x"<<i+1<<" = "
            <<AptPuntos[i]
            <<", f(x) = "<<AptFu[i]<<endl;   
    }

    cout<<"Area ="<<Riemann()<<endl;
}

void Puntos(int &RefP);

int main(void)
{
    int P;
    
    Puntos(P);
    
    Cardinal *AptC;
    AptC = new Cardinal(P);
    
    AptC->Leer();
    AptC->Funcion();
    AptC->Imprimir();
    
    delete AptC;
    return 0;
}

void Puntos(int &RefP)
{
    int V;
    cout<<"ingrese numero de puntos"<<endl;
    
    do
    {
        cin>>V;
        
        if(V<=0)
        {
            cout<<"numero invalido"<<endl
                <<"ingrese nuevamente"<<endl;
        }
    }while(V<=0);
    
    RefP=V;
}
