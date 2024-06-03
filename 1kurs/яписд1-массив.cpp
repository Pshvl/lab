
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int counter()
{
	string str;
	int counter = 0;
	ifstream filein("input.txt");



	getline(filein, str);
	cout << str << endl;
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == ' ') counter++;
	}
	cout << "кол-во чисел= " << counter + 1 << endl;

	return counter + 1;


}

double mm (double *A, int n)
{

	double min = A[0];
	double max = A[0];

	for (int i = 1; i < n; i++)
	{
		if (A[i] <= min)
			min = A[i];
		if (A[i] >= max)
			max = A[i];
	}
	return max * min;
}

int main()
{
	setlocale(LC_ALL, "Russian"); // подключение русского языка

		ifstream filein; //чтение

		filein.open("input.txt");


		while (!filein.is_open())
		{
			cout << "невозможно открыть файл" << endl;

		}
		cout << "кол-во чисел" << endl;

		int n = counter();
		double* A = new double[n];


		cout << "исходный массив" << endl;

		double c;
		for (int i = 0; i < n; i++)
		{
			filein >> A[i]; 
			cout << A[i] << " ";
		}
		cout << endl;

		filein.close();

		double m_m=mm(A,n);

	
		ofstream fileout; //запись
		fileout.open("output.txt");


		while (!fileout.is_open())
		{
			cout << "невозможно открыть файл" << endl;
		}
		cout << "ответ" << endl;



		fileout << m_m;


		fileout.close();

		
		delete[] A;

	return 0; //возврат нулевого значения функции
}