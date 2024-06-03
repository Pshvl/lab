// яписд2 матрица.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <fstream>
#include <iostream>
using namespace std;
void maxx(double** A, int n, int m)
{
	ofstream fileout; //запись
	fileout.open("output.txt");


	for (int i = 0; i < n; i++)
	{
		double max = A[i][0];
		for (int j = 1; j < m; j++)
		{
			if (A[i][j] > max)
				max = A[i][j];

		}


		fileout << max << ' ';
	}
	fileout.close();
}

int main()
{
	setlocale(LC_ALL, "Russian"); // подключение русского языка

	ifstream filein; //чтение

	filein.open("input.txt");

	int n, m;
	filein >> n >> m;

	double** A = new double* [n];
	for (int i = 0; i < n; i++)
		A[i] = new double[m];



	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			filein >> A[i][j];
	}
	cout << endl;

	filein.close();

	maxx(A, n, m);

	for (int i = 0; i < n; ++i)
		delete[] A[i];
	delete[] A;

	return 0; //возврат нулевого значения функции
}