#include <iostream>
#include <cmath>
#include <cstdlib>
#include <iomanip>

using namespace std;

double fcn(double x, double y, double z)
{
	double fxyz;
	
	fxyz=sin(x+y+z);
	
	return fxyz;
}

int main() 
{
  int n, i=0, j=0, k=0;
	double a, b, c, d, e, f, hx, hy, hz, I=0, I1=0, I2=0, I3=0, R1=0, R2=0, R3=0, S1=0, S2=0;
	
	cout << "Introduzca el valor de puntos: ";
	
	cin >> n;
	
	double x[3*n+1], y[3*n+1], z[3*n+1];
	
	cout << "\nIntroduzca limite inferior en X: ";
	
	cin >> a;
	
	cout << "\nIntroduzca limite superior en X: ";
	
	cin >> b;
	
	cout << "\nIntroduzca limite inferior en Y: ";
	
	cin >> c;
	
	cout << "\nIntroduzca limite superior en Y: ";
	
	cin >> d;
	
	cout << "\nIntroduzca limite inferior en Z: ";
	
	cin >> e;
	
	cout << "\nIntroduzca limite superior en Z";
	
	cin >> f;
	
	hx=(b-a)/(3*n);
	
	hy=(d-c)/(3*n);
	
	hz=(f-e)/(3*n);
		
	for(i=0; i<=3*n; i++)
	{
	  x[i]=a+i*hx;
	}
	
	for(i=0; i<=3*n; i++)
	{
	  y[i]=c+i*hy;
	}
	
	for(i=0; i<=3*n; i++)
	{
	  z[i]=e+i*hz;
	}
	
	cout << "\n";
	
  for(i=0; i<=3*n; i++)
  {
    cout << setprecision(13)
     << "x[" << i << "]= " << x[i] << '\t'
     << "y[" << i << "]= " << y[i] << '\t'
	 << "z[" << i << "]= " << z[i] << endl;
  }
  
  for(k=0; k<=3*n; k=k+3*n)
  {
  
  	  for(j=0; j<=3*n; j=j+3*n)
      {
	
	    for(i=0; i<=(n-1); i++)
	    {
	      S1=S1+3*fcn(x[3*i+1],y[j],z[k])+3*fcn(x[3*i+2],y[j],z[k]);
	    }
	
  	    for(i=1; i<=(n-1); i++)
	    {
	      S2=S2+2*fcn(x[3*i],y[j],z[k]);
	    } 	
	
  	    I1=I1+fcn(x[0],y[j],z[k])+S1+S2+fcn(x[3*n],y[j],z[k]);
  	
  	    S1=0; S2=0;
	  }
	
	 for(j=0; j<=(n-1); j++)
     {
	
	   for(i=0; i<=(n-1); i++)
	   {
	    S1=S1+3*fcn(x[3*i+1],y[3*j+1],z[k])+3*fcn(x[3*i+2],y[3*j+1],z[k]);
	   }
	
  	   for(i=1; i<=(n-1); i++)
	   {
	    S2=S2+2*fcn(x[3*i],y[3*j+1],z[k]);
	   } 	
	
  	   I2=I2+3*fcn(x[0],y[3*j+1],z[k])+3*S1+3*S2+3*fcn(x[3*n],y[3*j+1],z[k]);
  	
  	   S1=0; S2=0;
	 }
	 
	 for(j=0; j<=(n-1); j++)
     {
	
	   for(i=0; i<=(n-1); i++)
	   {
	    S1=S1+3*fcn(x[3*i+1],y[3*j+2],z[k])+3*fcn(x[3*i+2],y[3*j+2],z[k]);
	   }
	
  	   for(i=1; i<=(n-1); i++)
	   {
	    S2=S2+2*fcn(x[3*i],y[3*j+2],z[k]);
	   } 	
	
  	   I2=I2+3*fcn(x[0],y[3*j+2],z[k])+3*S1+3*S2+3*fcn(x[3*n],y[3*j+2],z[k]);
  	
  	   S1=0; S2=0;
	 }
	
	 for(j=1; j<=(n-1); j++)
     {
	
	  for(i=0; i<=(n-1); i++)
	  {
	    S1=S1+3*fcn(x[3*i+1],y[3*j],z[k])+3*fcn(x[3*i+2],y[3*j],z[k]);
	  }
	
  	  for(i=1; i<=(n-1); i++)
	  {
	    S2=S2+2*fcn(x[3*i],y[3*j],z[k]);
	  } 	
	
  	  I3=I3+2*fcn(x[0],y[3*j],z[k])+2*S1+2*S2+2*fcn(x[3*n],y[3*j],z[k]);
  	
  	   S1=0; S2=0;
	 }
	
	R1=R1+I1+I2+I3;
	
	I1=0; I2=0; I3=0;
  }
  
  for(k=0; k<=(n-1); k++)
  {
  
  	  for(j=0; j<=3*n; j=j+3*n)
      {
	
	    for(i=0; i<=(n-1); i++)
	    {
	      S1=S1+3*fcn(x[3*i+1],y[j],z[3*k+1])+3*fcn(x[3*i+2],y[j],z[3*k+1]);
	    }
	
  	    for(i=1; i<=(n-1); i++)
	    {
	      S2=S2+2*fcn(x[3*i],y[j],z[3*k+1]);
	    } 	
	
  	    I1=I1+fcn(x[0],y[j],z[3*k+1])+S1+S2+fcn(x[3*n],y[j],z[3*k+1]);
  	
  	    S1=0; S2=0;
	  }
	
	 for(j=0; j<=(n-1); j++)
     {
	
	   for(i=0; i<=(n-1); i++)
	   {
	    S1=S1+3*fcn(x[3*i+1],y[3*j+1],z[3*k+1])+3*fcn(x[3*i+2],y[3*j+1],z[3*k+1]);
	   }
	
  	   for(i=1; i<=(n-1); i++)
	   {
	    S2=S2+2*fcn(x[3*i],y[3*j+1],z[3*k+1]);
	   } 	
	
  	   I2=I2+3*fcn(x[0],y[3*j+1],z[3*k+1])+3*S1+3*S2+3*fcn(x[3*n],y[3*j+1],z[3*k+1]);
  	
  	   S1=0; S2=0;
	 }
	 
	 for(j=0; j<=(n-1); j++)
     {
	
	   for(i=0; i<=(n-1); i++)
	   {
	    S1=S1+3*fcn(x[3*i+1],y[3*j+2],z[3*k+1])+3*fcn(x[3*i+2],y[3*j+2],z[3*k+1]);
	   }
	
  	   for(i=1; i<=(n-1); i++)
	   {
	    S2=S2+2*fcn(x[3*i],y[3*j+2],z[3*k+1]);
	   } 	
	
  	   I2=I2+3*fcn(x[0],y[3*j+2],z[3*k+1])+3*S1+3*S2+3*fcn(x[3*n],y[3*j+2],z[3*k+1]);
  	
  	   S1=0; S2=0;
	 }
	
	 for(j=1; j<=(n-1); j++)
     {
	
	  for(i=0; i<=(n-1); i++)
	  {
	    S1=S1+3*fcn(x[3*i+1],y[3*j],z[3*k+1])+3*fcn(x[3*i+2],y[3*j],z[3*k+1]);
	  }
	
  	  for(i=1; i<=(n-1); i++)
	  {
	    S2=S2+2*fcn(x[3*i],y[3*j],z[3*k+1]);
	  } 	
	
  	   I3=I3+2*fcn(x[0],y[3*j],z[3*k+1])+2*S1+2*S2+2*fcn(x[3*n],y[3*j],z[3*k+1]);
  	
  	   S1=0; S2=0;
	 }
	
	R2=R2+3*I1+3*I2+3*I3;
	
	I1=0; I2=0; I3=0;
  }
  
  for(k=0; k<=(n-1); k++)
  {
  
  	  for(j=0; j<=3*n; j=j+3*n)
      {
	
	    for(i=0; i<=(n-1); i++)
	    {
	      S1=S1+3*fcn(x[3*i+1],y[j],z[3*k+2])+3*fcn(x[3*i+2],y[j],z[3*k+2]);
	    }
	
  	    for(i=1; i<=(n-1); i++)
	    {
	      S2=S2+2*fcn(x[3*i],y[j],z[3*k+2]);
	    } 	
	
  	    I1=I1+fcn(x[0],y[j],z[3*k+2])+S1+S2+fcn(x[3*n],y[j],z[3*k+2]);
  	
  	    S1=0; S2=0;
	  }
	
	 for(j=0; j<=(n-1); j++)
     {
	
	   for(i=0; i<=(n-1); i++)
	   {
	    S1=S1+3*fcn(x[3*i+1],y[3*j+1],z[3*k+2])+3*fcn(x[3*i+2],y[3*j+1],z[3*k+2]);
	   }
	
  	   for(i=1; i<=(n-1); i++)
	   {
	    S2=S2+2*fcn(x[3*i],y[3*j+1],z[3*k+2]);
	   } 	
	
  	   I2=I2+3*fcn(x[0],y[3*j+1],z[3*k+2])+3*S1+3*S2+3*fcn(x[3*n],y[3*j+1],z[3*k+2]);
  	
  	   S1=0; S2=0;
	 }
	 
	 for(j=0; j<=(n-1); j++)
     {
	
	   for(i=0; i<=(n-1); i++)
	   {
	    S1=S1+3*fcn(x[3*i+1],y[3*j+2],z[3*k+2])+3*fcn(x[3*i+2],y[3*j+2],z[3*k+2]);
	   }
	
  	   for(i=1; i<=(n-1); i++)
	   {
	    S2=S2+2*fcn(x[3*i],y[3*j+2],z[3*k+2]);
	   } 	
	
  	   I2=I2+3*fcn(x[0],y[3*j+2],z[3*k+2])+3*S1+3*S2+3*fcn(x[3*n],y[3*j+2],z[3*k+2]);
  	
  	   S1=0; S2=0;
	 }
	
	 for(j=1; j<=(n-1); j++)
     {
	
	  for(i=0; i<=(n-1); i++)
	  {
	    S1=S1+3*fcn(x[3*i+1],y[3*j],z[3*k+2])+3*fcn(x[3*i+2],y[3*j],z[3*k+2]);
	  }
	
  	  for(i=1; i<=(n-1); i++)
	  {
	    S2=S2+2*fcn(x[3*i],y[3*j],z[3*k+2]);
	  } 	
	
  	   I3=I3+2*fcn(x[0],y[3*j],z[3*k+2])+2*S1+2*S2+2*fcn(x[3*n],y[3*j],z[3*k+2]);
  	
  	   S1=0; S2=0;
	 }
	
	R2=R2+3*I1+3*I2+3*I3;
	
	I1=0; I2=0; I3=0;
  }
  
  for(k=1; k<=(n-1); k++)
  {
  
  	  for(j=0; j<=3*n; j=j+3*n)
      {
	
	    for(i=0; i<=(n-1); i++)
	    {
	      S1=S1+3*fcn(x[3*i+1],y[j],z[3*k])+3*fcn(x[3*i+2],y[j],z[3*k]);
	    }
	
  	    for(i=1; i<=(n-1); i++)
	    {
	      S2=S2+2*fcn(x[3*i],y[j],z[3*k]);
	    } 	
	
  	    I1=I1+fcn(x[0],y[j],z[3*k])+S1+S2+fcn(x[3*n],y[j],z[3*k]);
  	
  	    S1=0; S2=0;
	  }
	
	 for(j=0; j<=(n-1); j++)
     {
	
	   for(i=0; i<=(n-1); i++)
	   {
	    S1=S1+3*fcn(x[3*i+1],y[3*j+1],z[3*k])+3*fcn(x[3*i+2],y[3*j+1],z[3*k]);
	   }
	
  	   for(i=1; i<=(n-1); i++)
	   {
	    S2=S2+2*fcn(x[3*i],y[3*j+1],z[3*k]);
	   } 	
	
  	   I2=I2+3*fcn(x[0],y[3*j+1],z[3*k])+3*S1+3*S2+3*fcn(x[3*n],y[3*j+1],z[3*k]);
  	
  	   S1=0; S2=0;
	 }
	 
	 for(j=0; j<=(n-1); j++)
     {
	
	   for(i=0; i<=(n-1); i++)
	   {
	    S1=S1+3*fcn(x[3*i+1],y[3*j+2],z[3*k])+3*fcn(x[3*i+2],y[3*j+2],z[3*k]);
	   }
	
  	   for(i=1; i<=(n-1); i++)
	   {
	    S2=S2+2*fcn(x[3*i],y[3*j+2],z[3*k]);
	   } 	
	
  	   I2=I2+3*fcn(x[0],y[3*j+2],z[3*k])+3*S1+3*S2+3*fcn(x[3*n],y[3*j+2],z[3*k]);
  	
  	   S1=0; S2=0;
	 }
	
	 for(j=1; j<=(n-1); j++)
     {
	
	  for(i=0; i<=(n-1); i++)
	  {
	    S1=S1+3*fcn(x[3*i+1],y[3*j],z[3*k])+3*fcn(x[3*i+2],y[3*j],z[3*k]);
	  }
	
  	  for(i=1; i<=(n-1); i++)
	  {
	    S2=S2+2*fcn(x[3*i],y[3*j],z[3*k]);
	  } 	
	
  	   I3=I3+2*fcn(x[0],y[3*j],z[3*k])+2*S1+2*S2+2*fcn(x[3*n],y[3*j],z[3*k]);
  	
  	   S1=0; S2=0;
	 }
	
	R3=R3+2*I1+2*I2+2*I3;
	
	I1=0; I2=0; I3=0;
  }
  	
	I=R1+R2+R3;
	
	I=27*hx*hy*hz*I/512;
	
  cout << setprecision(13) << "\n\nI= " << I;
	
  return 0;
}
