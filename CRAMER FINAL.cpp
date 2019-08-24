#include <iostream>
#include <cmath>
using namespace std;

typedef double* DArrayPtr;

int main()
{
	const int m1 = 2, m2 = 1, m3 = 1, g = 10, kk = 2;
	double f1, f2, f3, x, y, z;
	int d1, d2;

	cout << "Enter the matrix dimensions:\n";
	cin >> d1 >> d2;

	//setting up dynamic memory
	DArrayPtr *K = new DArrayPtr[d1];

	for (int i = 0; i < d1; i++)
		K[i] = new double[d2];

	//Setting values for dyanmic memory
	K[0][0] = 3 * kk;
	K[0][1] = -2 * kk;
	K[0][2] = 0;
	K[1][0] = -2 * kk;
	K[1][1] = 3 * kk;
	K[1][2] = -kk;
	K[2][0] = 0;
	K[2][1] = -kk;
	K[2][2] = kk;

	int W[3][1];

	W[0][0] = m1*g;
	W[1][0] = m2*g;
	W[2][0] = m3*g;

	//Determinants
	double detK = (K[0][0] * K[1][1] * K[2][2]) + (K[0][1] * K[1][2] * K[2][0]) + (K[0][2] * K[1][0] * K[2][1]) - (K[0][2] * K[1][1] * K[2][0]) - (K[0][1] * K[1][0] * K[2][2]) - (K[0][0] * K[1][2] * K[2][1]);
	double detx = (W[0][0] * K[1][1] * K[2][2]) + (K[0][1] * K[1][2] * W[2][0]) + (K[0][2] * W[1][0] * K[2][1]) - (K[0][2] * K[1][1] * W[2][0]) - (K[0][1] * W[1][0] * K[2][2]) - (W[0][0] * K[1][2] * K[2][1]);
	double dety = (K[0][0] * W[1][0] * K[2][2]) + (W[0][0] * K[1][2] * K[2][0]) + (K[0][2] * K[1][0] * W[2][0]) - (K[0][2] * W[1][0] * K[2][0]) - (W[0][0] * K[1][0] * K[2][2]) - (K[0][0] * K[1][2] * W[2][0]);
	double detz = (K[0][0] * K[1][1] * W[2][0]) + (K[0][1] * W[1][0] * K[2][0]) + (W[0][0] * K[1][0] * K[2][1]) - (W[0][0] * K[1][1] * K[2][0]) - (K[0][1] * K[1][0] * W[2][0]) - (K[0][0] * W[1][0] * K[2][1]);
	cout << "Fdetx\n" << detx << endl;
	cout << "dety" << dety << endl;
	cout << "detz" << detz << endl;


	//Cramer's Rule
	x = detx / detK;
	y = dety / detK;
	z = detz / detK;

	//Calculating force
	f1 = (2 * kk * (y - x)) + (m1 * g) - (kk * x);
	f2 = (kk * (z - y)) + (m2 * g) - (2 * kk * (y - x));
	f3 = (m3 * g) - (kk * (z - y));

	cout << "Displacement of mass m1: " << x << endl;
	cout << "Displacement of mass m2: " << y << endl;
	cout << "Displacement of mass m3: " << z << endl;
	cout << "Force on mass 1:\n" << f1 << endl;
	cout << "Force on mass 2:\n" << f2 << endl;
	cout << "Force on mass 3:\n" << f3 << endl;

	//Close dynamic memory
	for (int i = 0; i < d1; i++)
		delete[] K[i];

	delete[] K;
	system("pause");
	return 0;
}