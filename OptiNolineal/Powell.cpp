#include<iostream>
#include<cstdlib>
#include<iomanip>
#include<cstdio>
#include<cmath>

using namespace std;

void Primera(double X[], const double P);
double Funcion(const double X);
void PowE1(double X[], const double E1);
void PowE2(double X[], const double E2);
void Parametros(double &a0, double &a1, double &a2, const double X[3]);
double Comp1(const double Xm, const double Ve);
double Comp2(const double Xm, const double Ve);
double Validar(void);

int main (void)
{
	double X[3];
	double P;
	char O;
	
	cout<<"Este programa calcula min de una variable por el metodo de Powell"<<endl
		<<"optimiza 2*pow(X,2.0)+16.0/X"<<endl<<endl
	    <<"Teclee una X cercana"<<endl;
	cin>>X[0];
	
	cout<<"Teclee Tamaño de paso"<<endl;
	P=Validar();
	
	double E1,E2;
	
	cout<<"teclee la tolerencia deseada 1"<<endl;
	E1=Validar();
	
	cout<<"teclee la tolerancia deseada 2"<<endl;
	E2=Validar();
	
	Primera(X,P);
	
	   cout<<"Ingrese el tipo de tolerancia con el que se desea trabajar"<<endl
	       <<"Elija una opcion"<<endl
	       <<"a) Error 1"<<endl
	       <<"b) Error 2"<<endl;
	   cin>>O;
	   O=toupper(O);
	   
	   switch (O)
	   {
		   case 'A':
		   {
			   PowE1(X,E1);
		   }
		   break;
		   case 'B':
		   {
			   PowE2(X,E2);
		   }
		   break;
		   default:
		   cout<<"caso no valido"<<endl;
		   break;
	   }
	 
	   system("pause=>NULL");
    return 0;
}

void Primera(double X[], const double P)
{
	X[1]=X[0]+P;
	
	if(Funcion(X[0])>Funcion(X[1]))
	{
		X[2]=X[0]+2.0*P;
	}
	else
	{
		X[2]=X[0]-P;
	}
}

double Funcion(const double X)
{
	return (2*pow(X,2.0)+16.0/X);
}

void PowE1(double X[], const double E1)
{
	double Xm;
	double Fmin;
	double f[3];
	double Ve;
	double a0, a1, a2;

	for (int i = 0; i < 3; i++)
	{
		f[i] = Funcion(X[i]);
	}

		Fmin = f[0];

		for (int i = 0; i < 3; i++)
		{
			if (Fmin > f[i])
			{
				Xm = X[i];
				Fmin = Funcion(X[i]);
			}
		}

		Parametros(a0, a1, a2, X);

		Ve = ((X[0] + X[1]) - a1 / a2) / 2.0;
		
		if (Comp1(Xm, Ve) < E1)
		{
			if (Funcion(Ve) > Funcion(Xm))
			{
				for (int i = 0; i < 3; i++)
				{
					cout << setprecision(16) << X[i]<<endl;
				}

				cout << setprecision(16)<< Ve << endl
					 << "Su optimo fue " << setprecision(16) << Xm << endl;
			}
			else
			{
				for (int i = 0; i < 3; i++)
				{
					cout << setprecision(16) << X[i] << endl;
				}

				cout << setprecision(16) << Ve << endl
					<< "Su optimo fue " << setprecision(16)
					<< Ve << endl;
			}
		}
		else
		{
			if (Xm<=X[1] && Ve<=X[1])
			{
				X[2] = X[1];
				X[1] = Ve;

				for (int i = 0; i < 3; i++)
				{
					cout << setprecision(16) << X[i] << endl;
				}

				cout << Ve << endl;

				if (Funcion(Ve) > Funcion(Xm))
				{
					cout << "Su optimo fue " << setprecision(16) << Xm << endl;
				}
				else
				{
					cout << "Su optimo fue " << setprecision(16) << Ve << endl;
				}

			}
			else
			{
				X[0] = X[1];
				X[1] = Ve;

				for (int i = 0; i < 3; i++)
				{
					cout << setprecision(16) << X[i] << endl;
				}

				cout << Ve << endl;

				if (Funcion(Ve) > Funcion(Xm))
				{
					cout << "Su optimo fue " << setprecision(16) << Xm << endl;
				}
				else
				{
					cout << "Su optimo fue " << setprecision(16) << Ve << endl;
				}

			}

			PowE1(X, E1);
		}
}

void PowE2(double X[], const double E2)
{
	double Xm;
	double Fmin;
	double f[3];
	double Ve;
	double a0, a1, a2;

	for (int i = 0; i < 3; i++)
	{
		f[i] = Funcion(X[i]);
	}

	Fmin = f[0];

	for (int i = 0; i < 3; i++)
	{
		if (Fmin > f[i])
		{
			Xm = X[i];
			Fmin = Funcion(X[i]);
		}
	}

	Parametros(a0, a1, a2, X);

	Ve = ((X[0] + X[1]) - a1 / a2) / 2.0;

	if (Comp2(Xm, Ve) < E2)
	{
		if (Funcion(Ve) > Funcion(Xm))
		{
			for (int i = 0; i < 3; i++)
			{
				cout << setprecision(16) << X[i] << endl;
			}

			cout << setprecision(16) << Ve << endl
				<< "Su optimo fue " << setprecision(16) << Xm << endl;
		}
		else
		{
			for (int i = 0; i < 3; i++)
			{
				cout << setprecision(16) << X[i] << endl;
			}

			cout << setprecision(16) << Ve << endl
				<< "Su optimo fue " << setprecision(16)
				<< Ve << endl;
		}
	}
	else
	{
		if (Xm <= X[1] && Ve <= X[1])
		{
			X[2] = X[1];
			X[1] = Ve;

			for (int i = 0; i < 3; i++)
			{
				cout << setprecision(16) << X[i] << endl;
			}

			cout << Ve << endl;

			if (Funcion(Ve) > Funcion(Xm))
			{
				cout << "Su optimo fue " << setprecision(16) << Xm << endl;
			}
			else
			{
				cout << "Su optimo fue " << setprecision(16) << Ve << endl;
			}

		}
		else
		{
			X[0] = X[1];
			X[1] = Ve;

			for (int i = 0; i < 3; i++)
			{
				cout << setprecision(16) << X[i] << endl;
			}

			cout << Ve << endl;

			if (Funcion(Ve) > Funcion(Xm))
			{
				cout << "Su optimo fue " << setprecision(16) << Xm << endl;
			}
			else
			{
				cout << "Su optimo fue " << setprecision(16) << Ve << endl;
			}

		}

		PowE2(X, E2);
	}
}

double Comp1(const double Xm, const double Ve)
{
	return (abs((Funcion(Xm) - Funcion(Ve)) / Funcion(Ve)));
}
double Comp2(const double Xm, const double Ve)
{
	return (abs((Xm - Ve) / Ve));
}
void Parametros(double &a0, double &a1, double &a2,const double X[3])
{
	a0 = Funcion(X[0]);

	a1 = (Funcion(X[1]) - a0) / (X[1] - X[0]);

	double V;

	V = ((Funcion(X[2]) - Funcion(X[0])) / (X[2] - X[0])) - a1;

	a2 = V / (X[2] - X[1]);
}

double Validar(void)
{
	double V;
	
	do
	{
		cin>>V;
		
		if(V<=0)
		{
			cout<<"No es posible determinar el valor"<<endl;
		}
	}while(V<=0);
	
	return V;
}
