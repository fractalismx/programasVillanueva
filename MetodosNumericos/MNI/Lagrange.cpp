#include<cstdlib>
#include<cmath>
#include<iostream>

using namespace std;

class Lagrage
{    
  private:
      int P;
      double A;
      double *AptPuntos;
      double *AptFu;
  public:
      Lagrage(int np=1);
      ~Lagrage(void);
      Lagrage(const Lagrage &RefL);
      
      void Leer(void);
      void Imprimir(void)const;
      void Funcion(void);
      double Polinomio(void)const;
};

Lagrage::Lagrage(int np)
{
    P=(np<1)?1:np;
    A=0;
    AptPuntos = new double[P];
    AptFu = new double[P];
    
    for(int i=0;i<P;i++)
        AptPuntos[i]=0.0;
    
    for(int j=0;j<P;j++)
        AptFu[j]=0.0;
    
}

Lagrage::~Lagrage(void)
{
    delete []AptPuntos;
    delete []AptFu;
}

Lagrage::Lagrage(const Lagrage &RefL)
{
    P=RefL.P;
    AptPuntos = new double[P];
    AptFu = new double[P];
     
    for(int i=0;i<P;i++)
        AptPuntos[i]=RefL.AptPuntos[i];
}

double Lagrage::Polinomio(void)const
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

void Lagrage::Leer(void)
{
    cout<<"Ingrese las x a valuar"<<endl;
    
    for(int i=0;i<P;i++)
    {   
        cout<<"Ingrese la x"<<i<<endl;
        cin>>AptPuntos[i];
    }

   cout<<"ingrese una x a aproximar"<<endl;
   cin>>A;
}

void Lagrage::Funcion(void)
{
    for(int i=0;i<P;i++)
    {
        AptFu[i]=exp(pow(AptPuntos[i],2));
    }    
}

void Lagrage::Imprimir(void) const
{
    for(int i=0;i<P;i++)
    {
        cout<<"x"<<i+1<<" = "
            <<AptPuntos[i]
            <<", f(x) = "<<AptFu[i]<<endl;   
    }

    cout<<"f("<<A<<")="<<Polinomio()<<endl;
}

void Puntos(int &RefP);

int main(void)
{
    int P;
    
    Puntos(P);
    
    Lagrage *AptL;
    AptL = new Lagrage(P);
    
    AptL->Leer();
    AptL->Funcion();
    AptL->Imprimir();
    
    delete AptL;
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
