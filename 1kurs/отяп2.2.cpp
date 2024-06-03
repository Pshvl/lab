//Словом текста считается любая последовательность букв русского алфавита. Найти те слова, которые начинаются и заканчиваются на гласную (слово из одной гласной удовлетворяет условию). 
#define _CRT_SECURE_NO_WARNINGS 
#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>


using namespace std;

enum signals { glasn, soglasn, kon, other };
enum states { s, after_glasn, middle, error, f };

bool isglasn(char c) // проверка на гласнуюну
{
	char glasn[]{ 'а','о', 'у', 'ы', 'э', 'е', 'ё', 'и', 'ю', 'я','А','О', 'У', 'Ы', 'Э', 'Е', 'Ё', 'И', 'Ю', 'Я' };
	return(std::find(std::begin(glasn), std::end(glasn), c) != std::end(glasn));
}


bool isRussian(char c) //проверка на русскую букву
{
	return (c >= 'а' && c <= 'я') || (c >= 'А' && c <= 'Я') || c == 'Ё' || c == 'ё';
}

bool issoglasn(char c) //проверка на согласную
{
	return (isRussian(c) && !isglasn(c));
}

bool my_iscntrl(char c) //проверка на концы
{
	return (c == '\t' || c == '\n' || c == '\r' || c == '\0' || c == ' ');
	
}

signals check(char c)
{
	if (isglasn(c)) return glasn;
	if (issoglasn(c)) return soglasn;
	if (my_iscntrl(c) || c==' ') return kon;
	return other;
}


void createtable(states(*table)[5]) //создание таблицы автомата
{
	table[glasn][s] = after_glasn;
	table[glasn][after_glasn] = after_glasn;
	table[glasn][middle] = after_glasn;
	table[glasn][error] = error;
	

	table[soglasn][s] = error;
	table[soglasn][after_glasn] = middle;
	table[soglasn][middle] = middle;
	table[soglasn][error] = error;
	

	table[kon][s] = s;
	table[kon][after_glasn] = f;
	table[kon][middle] = s;
	table[kon][error] = s;


	table[other][s] = error;
	table[other][after_glasn] = error;
	table[other][middle] = error;
	table[other][error] = error;
	
}


vector<char*> processText(char* t, int size, states(*table)[5]) // функция обработки массива символов
{
	vector<char*> name;
	enum states  current_state = states::s; //стартовое состояние
	int start = 0; //старт для записи

	

	for (int position = 0; position < size; ++position)
	{
		

		if (current_state == states::s && t[position] != ' ') start = position; //начало нового слова 
		

		current_state = table[check(t[position])][current_state]; //получаем состояние
		

		if (current_state == states::f) //если слово подходит (дошло до состояния f)
		{
			int len = position - start; //длина найденного слова (для записи в массив)
			char* word = new char[len + 1];//создание динамического массива для найденного слова

			strncpy(word, &t[0] + start, len); //t->word

			word[len] = '\0';
			name.push_back(word);  // запись подходящего слова в вектор результата
			
			current_state = states::s; //возвращаемся в стартовое состояние
		}
	}
	return name;
}


int main()
{
	setlocale(LC_ALL, "Russian"); // подключение русского языка
	ifstream filein("input.txt", ios::binary);
	
	//размер файла
	int SIZE = 0;
	filein.seekg(0, ios::end);
	SIZE = filein.tellg();
	filein.seekg(0, ios::beg);

	//считывание файла
	char* text = new char[SIZE + 1];
	filein.read(&text[0], SIZE);
	text[SIZE] = 0;
	filein.close();
	cout << "text:" << endl;

	for (int i = 0; i < SIZE; ++i) // Вывод результата из файла
	{
		cout << text[i];

	}
	cout << endl;


	/*создание таблицы*/
	states current_table[4][5];
	createtable(current_table);

	//обработка текста
	vector<char*> list=processText(text, SIZE + 1, current_table);

	SIZE = list.size();

	ofstream fileout; //запись
	fileout.open("output.txt");

	cout << "new text:" << endl;
	for (int i = 0; i < SIZE; ++i)
	{
		fileout << list[i] << " "; // запись ответа в файл и в консоль
		cout << list[i] << " ";
	}

	fileout.close();
	delete[] text;
	for (int i = 0; i < SIZE; i++) delete[] list[i]; // очистки


	return 0; //возврат нулевого значения функции
}

