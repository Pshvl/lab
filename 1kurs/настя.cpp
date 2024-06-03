#include <iostream>
#include <ctime>
#include <algorithm> 
#include <conio.h> 
#include <chrono>
#include <vector>

using namespace std;
using namespace std::chrono;

void Merge(vector<int>& A, int first, int last) //сливает
{
	int middle, start, final, j;
	vector<int> mas;
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

}

void MergeSort(vector<int>& A, int first, int last)
{

	if (first < last)
	{
		MergeSort(A, first, (first + last) / 2); //сорт левой части(от first до middle)
		MergeSort(A, ((first + last) / 2) + 1, last); //сорт правой части (от final до last)
		Merge(A, first, last); //слияние двух частей
	}

}

void print(vector<int>& A, int size)
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

void printReverse(vector<int>& A, int size)
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

int check()
{
	int x;
	while (!(cin >> x) || (cin.peek() != '\n') || !(x > 1))
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Введено некорректное значение. Введите заново: ";
	}
	return x;
}

int main()
{
	setlocale(LC_ALL, "Russian"); // подключение русского языка

	int ans;
	do
	{

		int n, choice;

		cout << "Введите размер массива" << endl;
		n = check();


		cout << "как заполнить массив?\n 1 - случайные данные \n 2 - с клавиатуры\n 3 - 'отсортированные наоборот' случайные данные \n";
		cin >> choice;
		cout << endl;
		vector<int> A; // для слияния


		vector<int> B; //для библиотечной
		srand(time(0));
		double time1 = 0.0;
		double time2 = 0.0;
		switch (choice) {
		case 1:  //rand 
			int x;
			for (int i = 0; i < A.size()+1; i++)
			{

				x = (rand() % 11);
				A.push_back(x);
				B.push_back(x);



			}
			cout << "изначальный массив:" << endl;
			print(A, n);
			cout << endl << endl;


			break;



		case 2:  //klava

			cout << "введите элементы массива:" << endl;
			int x=0;
			for (int i = 0; i < A.size(); i++)
			{
				x = check();
				A.push_back(x);
				B.push_back(x);

			}
			cout << "изначальный массив:" << endl;
			print(A, n);
			cout << endl << endl;


			break;

		case 3: //reverse

			int x;
			for (int i = 0; i < A.size(); i++)
			{
				x = (rand() % 11);
				A.push_back(x);
				B.push_back(x);


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
		sort(A.begin(), B.begin());
		auto stop2 = high_resolution_clock::now();
		auto duration2 = duration_cast<microseconds>(stop2 - start2);
		cout << endl;

		cout << " массив отсортированный библиотечной функцией :" << endl;
		print(B, n);
		cout << endl;

		cout << "время за которое была выполнена библиотечная сортировка : " << duration2.count() << " microseconds" << endl;

		if (duration2.count() <= 0)  cout << "ускорение библиотечной сортировки стремится к 0 " << endl;
		else
		{
			boost = duration.count() / duration2.count();
			cout << endl;
			cout << "ускорение библиотечной сортировки = " << boost << " microseconds" << endl;
		}




		cout << endl;
		cout << "введите 1 для продолжения ввода чисел.любое другое число, чтобы закончить. " << endl;
		cin >> ans;
	} while (ans == 1);

	return 0; //возврат нулевого значения функции
}




