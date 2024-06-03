// яписд5.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <fstream>
#include <iostream>
using namespace std;

class RGBColor {
private:
	int r; // Компонента красного цвета.
	int g; // Компонента зеленого цвета.
	int b; // Компонента синего цвета.
public:
	// Конструктор по умолчанию
	//RGBColor() = default;
	RGBColor() : r(0), g(0), b(0) {};
	RGBColor(int r, int g, int b) : r(r), g(g), b(b) {};
	// Конструктор копирования
	RGBColor(const RGBColor& color) : r(color.r), g(color.g), b(color.b) {}
	//// Деструктор
	//~RGBColor(){};


	//Пустой конструктор.
	//RGBColor() {}

	// Методы для получения и установки значений приватных переменных класса
	int red() const { return r; }
	void red(int value) { r = value; }

	int green() const { return g; }
	void green(int value) { g = value; }

	int blue() const { return b; }
	void blue(int value) { b = value; }


	//0 Методы для сложения  
	RGBColor operator+(const RGBColor& other) const {
		int red = (r + other.r) / 2;
		int green = (g + other.g) / 2;
		int blue = (b + other.b) / 2;
		return RGBColor(red, green, blue);
	}



	//1 вычитания цветов.
	RGBColor operator-(const RGBColor& other) const {
		int red = abs(r - other.r);
		int green = abs(g - other.g);
		int blue = abs(b - other.b);
		return RGBColor(red, green, blue);
	}




	//2 переход в другое цветовое пространство
	void RGBtoYF(double& y, double& f) const {
		double red = r / 255.0;
		double green = g / 255.0;
		double blue = b / 255.0;

		y = 0.299 * red + 0.587 * green + 0.114 * blue;
		f = -0.14713 * red - 0.28886 * green + 0.436 * blue;
	}

	//3 Перегрузка оператора равенства.
	bool operator==(const RGBColor& other) const {
		return r == other.r && g == other.g && b == other.b;
	}

	// 4 Оператор присваивания
	RGBColor& operator=(const RGBColor& color) {
		if (&color == this) {
			return *this; // Самоприсваивание
		}
		r = color.r;
		g = color.g;
		b = color.b;
		return *this;
	}
	//5 Перегрузка оператора меньше.
	bool operator<(const RGBColor& other) const {
		return r + g + b < other.r + other.g + other.b;
	}

	//6 Перегрузка оператора больше.
	bool operator>(const RGBColor& other) const {
		return r + g + b > other.r + other.g + other.b;
	}

	//7 Перегрузка оператора меньше или равно.
	bool operator<=(const RGBColor& other) const {
		return (*this < other) || (*this == other);
	}

	//8 Перегрузка оператора больше или равно.
	bool operator>=(const RGBColor& other) const {
		return (*this > other) || (*this == other);
	}



	// Перегрузка оператора ввода >>.
	friend std::istream& operator>>(std::istream& in, RGBColor& color)
	{
		char sep;
		// Чтение трех чисел из файла, разделенных точкой.
		in >> color.r >> sep >> color.g >> sep >> color.b;
		return in;
	}

	// Перегрузка оператора вывода <<.
	friend std::ostream& operator<<(std::ostream& out, RGBColor& color)
	{
		out << color.red() << "." << color.green() << "." << color.blue() << std::endl;
		return out;
	}

};


int main()
{
	ifstream filein("input.txt", ios::binary);
	ofstream fileout("output.txt");


	if (filein.is_open())
	{
		int choose;
		RGBColor color1, color2;
		filein >> choose >> color1 >> color2;


		std::cout << "Color from file: (" << color1.red() << " " << color1.green() << " " << color1.blue() << ")" << std::endl;
		std::cout << "Color from file: (" << color2.red() << ", " << color2.green() << ", " << color2.blue() << ")" << std::endl;
		cout << "method " << choose << endl;
		bool res;
		RGBColor new_color;
		switch (choose) {

			// Сложение цветов
		case 0:
			new_color = color1 + color2;
			cout << "res + : " << new_color.red() << " " << new_color.green() << " " << new_color.blue() << endl;
			fileout << "res + : " << new_color << endl;
			break;

		case 1:
			//1 вычитания цветов.
			new_color = color1 - color2;
			cout << "res - : " << new_color.red() << " " << new_color.green() << " " << new_color.blue() << endl;
			fileout << "res - : " << new_color << endl;
			break;

		case 2:
			double y, f;
			color1.RGBtoYF(y, f);
			fileout << color1;
			break;
		case 3:
			//==
			res = color1 == color2;
			cout << res;
			fileout << res;
			break;
		case 4:
			//<
			res = color1 < color2;
			cout << res;
			fileout << res;
			break;
		case 5:
			//>
			res = color1 > color2;
			cout << res;
			fileout << res;
			break;
		case 6:
			//<=
			res = color1 <= color2;
			cout << res;
			fileout << res;
			break;
		case 7:
			//>=
			res = color1 >= color2;
			cout << res;
			fileout << res;
			break;
		case 8:


			break;

		default:
			cout << " bad input\n";
			break;
		}

		filein.close();
		fileout.close();
		return 0;
	}

}











