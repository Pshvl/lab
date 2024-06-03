#include <fstream>
#include <iostream>
#include <string>



using namespace std;

void change(string& text)
{

	for (int i = 0; i < text.length(); i++)
	{
		if (text[i] == ' ')
		{
			text[i] = '*';
		}
	}

}


int main()
{
	setlocale(LC_ALL, "Russian"); // подключение русского языка


	int ans;
	do
	{

		ifstream filein; //чтение

		filein.open("C:\\Users\\polin\\OneDrive\\Рабочий стол\\in.txt");


		while (!filein.is_open())
		{
			cout << "невозможно открыть файл" << endl;

		}


		string text;
		cout << "исходный текст" << endl;
		while (!filein.eof())
		{
			text = "";
			getline(filein, text);
			cout << text;
		}
		cout << endl;
		filein.close();

		change(text);


		ofstream fileout; //запись
		fileout.open("C:\\Users\\polin\\OneDrive\\Рабочий стол\\out.txt");


		while (!fileout.is_open())
		{
			cout << "невозможно открыть файл" << endl;
		}
		cout << "измененный текст" << endl;
		for (int i = 0; i < text.length(); i++)
		{
			fileout << text[i];
			cout << text[i];
		}
		fileout.close();


		cout << endl;
		cout << "введите 1 для продолжения ввода чисел.любое другое число, чтобы закончить. " << endl;
		cin >> ans;
	} while (ans == 1);

	return 0; //возврат нулевого значения функции
}

