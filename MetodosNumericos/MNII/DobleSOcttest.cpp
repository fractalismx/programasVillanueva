#include <iostream>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <conio.h>

using namespace std;

double fcn(double x, double y)
{
	double fxy;
	
	fxy=exp(x+y);
	
	return fxy;
}

int main() 
{
  int n, i=0, j=0;
	double a, b, c, d, hx, hy, I=0, I1=0, I2=0, I3=0, S1=0, S2=0;
	
	cout << "Introduzca la cantidad de puntos: ";
	
	cin >> n;
	
	double x[3*n+1], y[3*n+1];
	
	cout << "\nIntroduzca el limite inferior en X: ";
	
	cin >> a;
	
	cout << "\nIntroduzca el limite superior en X: ";
	
	cin >> b;
	
	cout << "\nIntroduzca el limite inferior en Y: ";
	
	cin >> c;
	
	cout << "\nIntroduzca el limite superior en X: ";
	
	cin >> d;
	
	hx=(b-a)/(3*n);
	
	hy=(d-c)/(3*n);
		
	for(i=0; i<=3*n; i++)
	{
	  x[i]=a+i*hx;
	}
	
	for(i=0; i<=3*n; i++)
	{
	  y[i]=c+i*hy;
	}
	
	cout << "\n";
	
  for(i=0; i<=3*n; i++)
  {
    cout << setprecision(13)
     << "x[" << i << "]= " << x[i] << '\t'
     << "y[" << i << "]= " << y[i] << endl;
  }
  
  for(j=0; j<=3*n; j=j+3*n)
  {
	
	  for(i=0; i<=(n-1); i++)
	  {
	    S1=S1+3*fcn(x[3*i+1],y[j])+3*fcn(x[3*i+2],y[j]);
	  }
	
  	for(i=1; i<=(n-1); i++)
	  {
	    S2=S2+2*fcn(x[3*i],y[j]);
	  } 	
	
  	I1=I1+fcn(x[0],y[j])+S1+S2+fcn(x[3*n],y[j]);
  	
  	S1=0; S2=0;
	}
	
  for(j=0; j<=(n-1); j++)
  {
	
	  for(i=0; i<=(n-1); i++)
	  {
	    S1=S1+3*fcn(x[3*i+1],y[3*j+1])+3*fcn(x[3*i+2],y[3*j+1]);
	  }
	
  	for(i=1; i<=(n-1); i++)
	  {
	    S2=S2+2*fcn(x[3*i],y[3*j+1]);
	  } 	
	
  	I2=I2+3*fcn(x[0],y[3*j+1])+3*S1+3*S2+3*fcn(x[3*n],y[3*j+1]);
  	
  	S1=0; S2=0;
  }
  
  for(j=0; j<=(n-1); j++)
  {
	
	  for(i=0; i<=(n-1); i++)
	  {
	    S1=S1+3*fcn(x[3*i+1],y[3*j+2])+3*fcn(x[3*i+2],y[3*j+2]);
	  }
	
  	for(i=1; i<=(n-1); i++)
	  {
	    S2=S2+2*fcn(x[3*i],y[3*j+2]);
	  } 	
	
  	I2=I2+3*fcn(x[0],y[3*j+2])+3*S1+3*S2+3*fcn(x[3*n],y[3*j+2]);
  	
  	S1=0; S2=0;
  }
	
  for(j=1; j<=(n-1); j++)
  {
	
      for(i=0; i<=(n-1); i++)
	  {
	    S1=S1+3*fcn(x[3*i+1],y[3*j])+3*fcn(x[3*i+2],y[3*j]);
	  }
	
  	  for(i=1; i<=(n-1); i++)
	  {
	    S2=S2+2*fcn(x[3*i],y[3*j]);
	  } 	
	
  	I3=I3+2*fcn(x[0],y[3*j])+2*S1+2*S2+2*fcn(x[3*n],y[3*j]);
  	
  	S1=0; S2=0;
  }
	
	
	I=I1+I2+I3;
	
	I=9*hx*hy*I/64;
		
  cout << setprecision(13) << "\n\nI= " << I;
  
  getche();
	
  return 0;
}
