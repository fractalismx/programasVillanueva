#include<cmath>
#include<iostream>
#include<cstdlib>
#include<iomanip>
#include<cstdio>
#include"C:\Users\Pablo\Desktop\Op No lineal\inversa.hpp"

using namespace std;

double Validar(void);
void NM(const double X[2]);
double Funcion(const double X, const double Y);
double DePO1X(const double X, const double Y);
double DePO1Y(const double X, const double Y);

int main(void)
{
	double X[2];

	cout << "Este Programa realiza la aproximacion" << endl
		<< "de optimos por el metodo de Newton Modificado para 2 variables" << endl
		<< "optimiza -1/(x^2+y^2+1)" << endl
		<< "Ingrese la coordenada en X" << endl;

	cin >> X[0];

	cout<< "Ingrese la coordenada en Y" << endl;
	cin >> X[1];

	NM(X);

	system("pause=>NULL");

	return 0;
}

double Funcion(const double X, const double Y)
{
	return(1.0/(pow(X, 2) + pow(Y, 2) + 2));
}

double DePO1X(const double X, const double Y)
{
	return ((Funcion(X + 0.00000001,Y) - Funcion(X - 0.00000001,Y)) / (0.00000002));
}

double DePO1Y(const double X, const double Y)
{
	return ((Funcion(X, 0.00000001+Y) - Funcion(X,Y-0.00000001)) / (0.00000002));
}

double DePO2X(const double X,const double Y)
{
	return ((Funcion(X + 0.0000001,Y) - 2 * Funcion(X,Y) + Funcion(X - 0.0000001,Y)) / pow(0.0000001, 2));
}

double DePO2XY(const double X, const double Y)
{
	double A, B;

	A = Funcion(X + 0.0000001, Y + 0.0000001) + Funcion(X - 0.0000001, Y - 0.0000001);
	B = Funcion(X + 0.0000001, Y - 0.0000001) + Funcion(X - 0.0000001, Y + 0.0000001);

	return ((A - B) / pow(0.0000002, 2));
}

double DePO2Y(const double X, const double Y)
{
	return ((Funcion(X , 0.0000001+Y) - 2 * Funcion(X, Y) + Funcion(X, Y-0.0000001)) / pow(0.0000001, 2));
}

void NM(const double X[2])
{
	double d[2] = {0,0};
	double **He;
	double **ainv;
	double determ;
	He = new double*[2];

	for (int j = 0; j < 2; j++)
	{
		He[j] = new double[2];
	}

	ainv = new double*[2];

	for (int j = 0; j < 2; j++)
	{
		ainv[j] = new double[2];
	}

	He[0][0] = DePO2X(X[0], X[1]);
	He[0][1] = DePO2XY(X[0], X[1]);
	He[1][0] = DePO2XY(X[0], X[1]);
	He[1][1] = DePO2Y(X[0], X[1]);

	invermat(2, He, ainv, determ);
    
	d[0] = ainv[0][0] * X[0] + ainv[0][1] * X[1];
	d[1] = ainv[1][0] * X[0] + ainv[1][1] * X[1];

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			cout << He[i][j] << ' ';
		}
		cout << endl;
	}

	cout << endl;

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			cout << ainv[i][j] << ' ';
		}
		cout << endl;
	}

	cout << endl;

	for (int i = 0; i<2; i++)
	{
		cout<<d[i]<<endl;
	}

	for (int i = 0; i<2; i++)
	{
		delete []He[i];
	}

	delete []He;

	for (int i = 0; i<2; i++)
	{
		delete[]ainv[i];
	}

	delete[]ainv;
}

double Validar(void)
{
	double V;

	do
	{
		cin >> V;

		if (V <= 0)
		{
			cout << "No es posible determinar el valor" << endl;
		}
	} while (V <= 0);

	return V;
}