// яписд5.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <fstream>
#include <iostream>
using namespace std;

/* class RGBColor {
public:
	RGBColor(int r, int g, int b) : r_(r), g_(g), b_(b) {}

	int r() const { return r_; }
	int g() const { return g_; }
	int b() const { return b_; }

	RGBColor operator+(const RGBColor& other) const {
		return RGBColor(r_ + other.r_, g_ + other.g_, b_ + other.b_);
	}

	RGBColor operator-(const RGBColor& other) const {
		return RGBColor(r_ - other.r_, g_ - other.g_, b_ - other.b_);
	}

private:
	int r_, g_, b_;
};*/


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


	//// Конструктор класса.
	//RGBColor(int red, int green, int blue)
	//{
	//	r = red;
	//	g = green;
	//	b = blue;
	//}

	////Пустой конструктор.
	//RGBColor() {}

	//// Методы для получения и изменения составляющих цвета.
	//int getRed() const {
	//	return r;
	//}

	//int getGreen() const {
	//	return g;
	//}

	//int getBlue() const {
	//	return b;
	//}

	//void setRed(int red) {
	//	r = red;
	//}

	//void setGreen(int green) {
	//	g = green;
	//}

	//void setBlue(int blue) {
	//	b = blue;
	//}

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

	/*RGBColor add(RGBColor& color1, RGBColor& color2) const {
		return RGBColor(color1.r + color2.r, color1.g + color2.g, color1.b + color2.b);
	}*/

	//1 вычитания цветов.
	RGBColor operator-(const RGBColor& other) const {
		int red = abs(r - other.r);
		int green = abs(g - other.g);
		int blue = abs(b - other.b);
		return RGBColor(red, green, blue);
	}
	/*RGBColor subtract(RGBColor color1, RGBColor color2) const {
		return RGBColor(color1.r - color2.r, color1.g - color2.g, color1.b - color2.b);
	}*/


	////2 Метод для перевода RGB в HSV
	//void toHSV(double& h, double& s, double& v) const {
	//	double red = static_cast<double>(r) / 255.0;
	//	double green = static_cast<double>(g) / 255.0;
	//	double blue = static_cast<double>(b) / 255.0;
	//	double cmax = std::max({ red, green, blue });
	//	double cmin = std::min({ red, green, blue });
	//	double delta = cmax - cmin;
	//	// hue calculation
	//	double hue;
	//	if (delta == 0) {
	//		hue = 0;
	//	}
	//	else if (cmax == red) {
	//		hue = fmod((green - blue) / delta, 6);
	//	}
	//	else if (cmax == green) {
	//		hue = ((blue - red) / delta) + 2;
	//	}
	//	else {
	//		hue = ((red - green) / delta) + 4;
	//	}
	//	hue = hue * 60;
	//	if (hue < 0) {
	//		hue += 360;
	//	}
	//	// saturation calculation
	//	double saturation;
	//	if (cmax == 0) {
	//		saturation = 0;
	//	}
	//	else {
	//		saturation = delta / cmax;
	//	}
	//	// value calculation
	//	double value = cmax;
	//	h = hue;
	//	s = saturation;
	//	v = value;
	//}



	//3 Перегрузка оператора равенства.
	bool operator==(const RGBColor& other) const {
		return r == other.r && g == other.g && b == other.b;
	}

	//4 Перегрузка оператора неравенства.
	bool operator!=(const RGBColor& other) const {
		return !(*this == other);
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

	void convertRGBtoYF(int r, int g, int b, double& y, double& f) {
		double red = r / 255.0;
		double green = g / 255.0;
		double blue = b / 255.0;

		y = 0.299 * red + 0.587 * green + 0.114 * blue;
		f = -0.14713 * red - 0.28886 * green + 0.436 * blue;
	}

	// Перегрузка оператора ввода >>.
	friend std::istream& operator>>(std::istream& is, RGBColor& color)
	{
		char sep;

		// Чтение трех чисел из файла, разделенных точкой.
		is >> color.r >> sep >> color.g >> sep >> color.b;
		return is;
	}
};

/* class Color {
public:
	int red;
	int green;
	int blue;

	// Конструктор
	Color(int r, int g, int b) {
		red = r;
		green = g;
		blue = b;
	}
	// Метод для сложения цветов
	Color add(Color c) {
		int r = red + c.red;
		int g = green + c.green;
		int b = blue + c.blue;
		return Color(r, g, b);
	}
	// Метод для вычитания цветов
	Color subtract(Color c) {
		int r = red - c.red;
		int g = green - c.green;
		int b = blue - c.blue;
		return Color(r, g, b);
	}

	void toHSV(double& h, double& s, double& v)
		const {
		double r = red / 255.0;
		double g = green / 255.0;
		double b = blue / 255.0;

		double cmax = std::max(std::max(r, g), b);
		double cmin = std::min(std::min(r, g), b);
		double delta = cmax - cmin;

		double h = 0;
		if (delta != 0) {
			if (cmax == r) {
				h = fmod((g - b) / delta, 6);
			}
			else if (cmax == g) {
				h = (b - r) / delta + 2;
			}
			else {
				h = (r - g) / delta + 4;
			}
			h *= 60;
			if (h < 0) {
				h += 360;
			}
		}
	}
};
*/



int main()
{
	ifstream filein("input.txt", ios::binary);

	if (filein.is_open())
	{
		int choose;
		filein >> choose;
		RGBColor color1, color2;
		filein >> color1;
		std::cout << "Color from file: (" << color1.red() << " " << color1.green() << " " << color1.blue() << ")" << std::endl;
		filein >> color2;
		std::cout << "Color from file: (" << color2.red() << ", " << color2.green() << ", " << color2.blue() << ")" << std::endl;
		cout << "method " << choose << endl;
		/*if (choose == 0)
		{
			RGBColor new_color = color1 + color2;
			cout << "res + : " << new_color.red() << " " << new_color.green() << " " << new_color.blue() << endl;

		}
		if (choose == 1)
		{
			RGBColor new_color = color1 - color2;
			cout << "res - : " << new_color.red() << " " << new_color.green() << " " << new_color.blue() << endl;
		}*/

		switch (choose) {
		case 0:// Сложение цветов
			RGBColor new_color = color1 + color2;
			cout << "res + : " << new_color.red() << " " << new_color.green() << " " << new_color.blue() << endl;
			break;

		case 1: //1 вычитания цветов.
			RGBColor new_color = color1 - color2;
			cout << "res - : " << new_color.red() << " " << new_color.green() << " " << new_color.blue() << endl;
			break;

		case 2:
			//break;
		case 3: //==
			bool res = color1 == color2;
			cout << res;
			break;
		case 4://<
			bool res = color1 < color2;
			cout << res;
			break;
		case 5://>
			bool res = color1 > color2;
			cout << res;
			break;
		case 6://<=
			bool res = color1 <= color2;
			cout << res;
			break;
		case 7://>=
			bool res = color1 >= color2;
			cout << res;
			break;
		case 8:
			//break;

		default:
			cout << "Error, bad input, quitting\n";
			break;
		}


	}

	return 0;
}
















//// Перегрузка оператора взятия из файла.
//friend std::istream& operator>>(std::istream& in, RGBColor& color) {
//    std::string line;
//    std::getline(in, line);
//    sscanf(line.c_str(), "%d %d %d", &color.r, &color.g, &color.b);
//    return in;
//}
// 



//// Перегрузка оператора взятия из файла.
//friend std::istream& operator>>(std::istream& in, RGBColor& color) {
//	in >> color.r >> color.g >> color.b;
//	return in;
//}