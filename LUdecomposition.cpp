#include "stdafx.h"
#include <iostream> 
using namespace std;

//creates dynamic memory space
typedef double* DArrayPtr;

int main()
{
	double W[3], x[3], y[3];
	int a, b, c, d1, d2, d(3);
	const int m1 = 2, m2 = 1, m3 = 1, g = 10, kk = 2;
	double factor, sum;

	cout << "Enter the dimensions of the system's matrix:\n";
	cin >> d1 >> d2;

	//sets up dynamic memory
	DArrayPtr *K = new DArrayPtr[d1];

	for (int i = 0; i < d1; i++)
		K[i] = new double[d2];

	//establishes dynamic memory
	K[0][0] = 3 * kk;
	K[0][1] = -2 * kk;
	K[0][2] = 0;
	K[1][0] = -2 * kk;
	K[1][1] = 3 * kk;
	K[1][2] = -kk;
	K[2][0] = 0;
	K[2][1] = -kk;
	K[2][2] = kk;

	W[0] = m1*g;
	W[1] = m2*g;
	W[2] = m3*g;

	//L-U decomposition
	for (c = 1; c< d - 1; c++)
	{
		for (a = c + 1; a<d; a++)
		{
			factor = K[a][c] / K[c][c];
			K[a][c] = factor;
			for (b = c + 1; b<d; b++)
			{
				K[a][b] = K[a][b] - (factor*K[c][b]);
			}
		}
	}

	// forward substitution
	y[0] = W[0]; //stops W from overwriting itself
	for (a = 1; a < d; a++)
	{
		sum = W[a];
		for (b = 0; b <= a - 1; b++)
		{
			sum = sum - (K[a][b] * y[b]);
		}
		y[a] = sum;
	}

	// backward substitution
	x[d - 1] = y[d - 1] / K[d - 1][d - 1];
	for (a = d - 1; a >= 0; a--)
	{
		sum = 0;
		for (b = a + 1; b < d; b++)
		{
			sum = sum + (K[a][b] * x[b]);
		}
		x[a] = (y[a] - sum) / K[a][a];
	}

	//displays displacement of masses
	cout << "Displacement of mass m1 is: " << x[0] << endl;
	cout << "Displacement of mass m2 is: " << x[1] << endl;
	cout << "Displacement of mass m3 is: " << x[2] << endl;

	//free dynamic memory
	for (int i = 0; i < d1; i++)
		delete[] K[i];

	delete[] K;
	system("pause");
	return 0;
}