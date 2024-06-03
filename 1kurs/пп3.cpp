#include <iostream>
#include <ctime>
#include <algorithm> 
#include <conio.h> 
#include <chrono>

using namespace std;
using namespace std::chrono;

void Merge(int* A, int first, int last) //сливает
{
	int middle, start, final, j;
	int* mas = new int[last + 1];
	middle = (first + last) / 2; //вычисление среднего элемента
	start = first; //начало левой части
	final = middle + 1; //начало правой части

	for (j = first; j <= last; j++) //выполнять от начала до конца
		if ((start <= middle) && ((final > last) || (A[start] < A[final])))
		{
			mas[j] = A[start];
			start++;
		}
		else
		{
			mas[j] = A[final];
			final++;
		}

	for (j = first; j <= last; j++)
		A[j] = mas[j]; //перезапись из мас в А
	delete[]mas;
}

void MergeSort(int* A, int first, int last)
{

	if (first < last)
	{
		MergeSort(A, first, (first + last) / 2); //сорт левой части(от first до middle)
		MergeSort(A, ((first + last) / 2) + 1, last); //сорт правой части (от final до last)
		Merge(A, first, last); //слияние двух частей
	}

}

void print(int* A, int size)
{
	int i;
	if (size > 20)
	{
		cout << "массив слишком большой, поэтому будет выведена часть значений" << endl;
		for (i = 1; i <= 20; i++)

			cout << "А[" << i << "]=" << A[i] << "   ";

	}
	else
	{
		for (i = 1; i <= size; i++)

			cout << "А[" << i << "]=" << A[i] << "   ";
	}

}

void printReverse(int* A, int size)
{
	int i;
	if (size > 20)
	{
		cout << "массив слишком большой, поэтому будет выведена часть значений" << endl;
		for (i = size; i >= size - 20; i--)

			cout << "А[" << i << "]=" << A[i] << "   ";

	}
	else
	{
		for (i = size; i >= 1; i--)

			cout << "А[" << i << "]=" << A[i] << "   ";
	}

}


int main()
{
	setlocale(LC_ALL, "Russian"); // подключение русского языка

	int ans;
	do
	{

		int n, choice;

		cout << "Введите размер массива" << endl;
		cin >> n;

		while (n < 2)
		{
			cout << "введено некорректное значение. Введите n>1" << endl;
			cin >> n;
		}
		cout << "как заполнить массив?\n 1 - случайные данные \n 2 - с клавиатуры\n 3 - 'отсортированные наоборот' случайные данные \n";
		cin >> choice;
		cout << endl;
		int* A = new int[n + 1]; // для слияния

		int* B = new int[n + 1]; //для библиотечной
		srand(time(0));
		double time1 = 0.0;
		double time2 = 0.0;
		switch (choice) {
		case 1:  //rand 

			for (int i = 1; i <= n; i++)
			{

				A[i] = (rand() % 11);
				B[i] = A[i];
				

			}
			cout << "изначальный массив:" << endl;
			print(A, n);
			cout << endl << endl;

			
			break;



		case 2:  //klava

			cout << "введите элементы массива:" << endl;
			int c;
			for (int i = 1; i <= n; i++)
			{
				cin >> c;
				A[i] = c;
				B[i] = c;

			}
			cout << "изначальный массив:" << endl;
			print(A, n);
			cout << endl << endl;

			
			break;

		case 3: //reverse


			for (int i = 1; i <= n; i++)
			{

				A[i] = (rand() % 11);
				B[i] = A[i];
				

			}
			cout << "изначальный массив:" << endl;
			MergeSort(A, 1, n); //вызов сортирующей процедуры
			printReverse(A, n);
			cout << endl << endl;
			

			break;
		}


		double boost = 0;

		auto start = high_resolution_clock::now();
		MergeSort(A, 1, n);
		auto stop = high_resolution_clock::now();
		auto duration = duration_cast<microseconds>(stop - start);
		cout << " массив отсортированный слиянием:" << endl;
		print(A, n);
		cout << endl;

		cout << "время за которое была выполнена сортировка слиянием: " << duration.count() << " microseconds" << endl;


		auto start2 = high_resolution_clock::now();
		sort(B, B + n + 1);
		auto stop2 = high_resolution_clock::now();
		auto duration2 = duration_cast<microseconds>(stop2 - start2);
		cout << endl;

		cout << " массив отсортированный библиотечной функцией :" << endl;
		print(B, n);
		cout << endl;

		cout << "время за которое была выполнена библиотечная сортировка : " << duration2.count() << " microseconds" << endl;

		boost = duration.count()/ duration2.count();
		cout << endl;
		cout << "ускорение библиотечной сортировки = " << boost << " microseconds" << endl;

		delete[]A; //удаление массива
		cout << endl;
		cout << "введите 1 для продолжения ввода чисел.любое другое число, чтобы закончить. " << endl;
		cin >> ans;
	} while (ans == 1);

	return 0; //возврат нулевого значения функции
}




