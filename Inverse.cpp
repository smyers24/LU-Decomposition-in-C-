#include <iostream> 
using namespace std;

//creating dynamic memory
typedef double* DArrayPtr;

int main()
{
	double W[3], x[3], y[3], ai[3][3];
	int a, b, c, d1, d2, d(3);
	const int m1 = 2, m2 = 1, m3 = 1, g = 10, k = 2;
	double factor, sum;

	cout << "Enter matrix dimensions:\n";
	cin >> d1 >> d2;

	//gives exact space for dynamic memory
	DArrayPtr *A = new DArrayPtr[d1];

	for (int i = 0; i < d1; i++)
		A[i] = new double[d2];

	//setting up dynamic memory
	A[0][0] = 3 * k;
	A[0][1] = -2 * k;
	A[0][2] = 0;
	A[1][0] = -2 * k;
	A[1][1] = 3 * k;
	A[1][2] = -k;
	A[2][0] = 0;
	A[2][1] = -k;
	A[2][2] = k;

	//L-U decomposition
	for (c = 0; c< d - 1; c++)
	{
		for (a = c + 1; a<d; a++)
		{
			factor = A[a][c] / A[c][c];
			A[a][c] = factor;
			for (b = c + 1; b<d; b++)
			{
				A[a][b] = A[a][b] - (factor*A[c][b]);
			}
		}
	}
	for (int i = 0; i < d; i++)
	{
		for (int j = 0; j<d; j++)
		{
			if (i == j)
			{
				W[j] = 1;
			}
			else
			{
				W[j] = 0;
			}
		}
		// forward substitution
		y[0] = W[0];
		for (a = 1; a < d; a++)
		{
			sum = W[a];

			for (b = 0; b <= a - 1; b++)
			{
				sum = sum - (A[a][b] * y[b]);
			}
			y[a] = sum;
		}

		// backward substitution
		x[d - 1] = y[d - 1] / A[d - 1][d - 1];
		for (a = d - 1; a >= 0; a--)
		{
			sum = 0;
			for (b = a + 1; b < d; b++)
			{
				sum = sum + (A[a][b] * x[b]);
			}
			x[a] = (y[a] - sum) / A[a][a];
		}
		for (int j = 0; j<d; j++)
		{
			ai[j][i] = x[j];
		}
	}

	//displays inverse
	cout << "A^(-1): \n";
	for (int i = 0; i<d; i++){
		for (int j = 0; j<3; j++){
			cout << ai[i][j] << "  ";
		}
		cout << endl;
	}

	//free dynamic memory
	for (int i = 0; i < d1; i++)
		delete[] A[i];

	delete[] A;
	system("pause");
	return 0;
}
