#include <iostream>
#include <ctime>

using namespace std;

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

int main()
{
	setlocale(LC_ALL, "Russian"); // подключение русского языка

	int ans;
	do
	{
		srand(time(0));
		int n;

		cout << "Введите размер массива" << endl;
		cin >> n;

		/*while (!(n > 0) || (cin.fail()))
		{
			cout << "введено некорректное значение. Введите n>0" << endl;
			cin.clear();
			while (cin.get() != '\n');
			cin >> n;
		}*/

		while (n < 2)
		{
			cout << "введено некорректное значение. Введите n>1" << endl;
			cin >> n;
		}

		cout << "первая версия массива:" << endl;
		int* A = new int[(int)n + 1];
		for (int i = 1; i <= (int)n; i++) //или от 1
		{
			A[i] = (rand() % 11);

		}

		print(A, (int)n);
		cout << endl;
		MergeSort(A, 1, (int)n); //вызов сортирующей процедуры
		cout << "Упорядоченный массив" << endl;

		print(A, (int)n); //вывод готового массива
		cout << endl;

		delete[]A; //удаление массива

		cout << "введите 1 для продолжения ввода чисел.любое другое число, чтобы закончить. " << endl;
		cin >> ans;
	} while (ans == 1);

	return 0; //возврат нулевого значения функции
}