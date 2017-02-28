#include<iostream>
#include<cmath>
#include<iomanip>
#include<cstdlib>

using namespace std;

double Serie(int n);

int main(void)
{
  int n;
  cout<<"ingrese hasta que termino no se ignorara"<<endl;
  cin>>n;
  cout<<"la serie hasta "<<n<<" es"<<endl
      <<setprecision(64)<<Serie(n)<<endl;
  
  return 0;
}

double Serie(int n)
{
	double D;
	D=0;
	
	for(int i=0;i<n;i++)
	{
		D=D+pow(-1,i)/pow((2*i+1),2);
	}
	
	return D*(4/M_PI);
}
