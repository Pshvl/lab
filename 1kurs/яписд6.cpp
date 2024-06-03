// яписд5.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <ctime> // для функции time()
#include <cstdlib> // для функции rand()

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
	~RGBColor(){};



	// Методы для получения и установки значений приватных переменных класса
	int red() const { return r; } //get
	void red(int value) { r = value; } //set

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
	friend std::istream& operator>>(std::istream& is, RGBColor& color)
	{
		char sep;
		// Чтение трех чисел из файла, разделенных точкой.
		is >> color.r >> sep >> color.g >> sep >> color.b;
		return is;
	}

	// Перегрузка оператора вывода <<.
	friend std::ostream& operator<<(std::ostream& os, RGBColor& color)
	{
		os << color.red() << "." << color.green() << "." << color.blue() << std::endl;
		return os;
	}
	friend std::ifstream& operator>>(std::ifstream& ifs, RGBColor& color)
	{
		char sep;
		// Чтение трех чисел из файла, разделенных точкой.
		ifs >> color.r >> sep >> color.g >> sep >> color.b;
		return ifs;
	}

	// Перегрузка оператора вывода <<.
	friend std::ofstream& operator<<(std::ofstream& ofs, RGBColor& color)
	{
		ofs << color.red() << "." << color.green() << "." << color.blue() << std::endl;
		return ofs;
	}
	friend struct LinkedList;
};




// объявление структуры двусвязного нециклического списка
struct LinkedList
{
	RGBColor data; // значение
	LinkedList* next; // указатель на след эл
	LinkedList* prev; // указатель на пред эл
};

// Функция вставки нового узла в список
void aDdNoDe(LinkedList** hEaD, LinkedList** tAiL, RGBColor variable)
{
	LinkedList* new_node = new LinkedList;
	new_node->data = variable;
	new_node->next = NULL;

	// Если список пустой, добавляем первый элемент
	if (*hEaD == NULL) {
		new_node->prev = NULL;
		*hEaD = new_node;
	}

	else {
		// Добавляем новый элемент в конец списка
		(*tAiL)->next = new_node;
		new_node->prev = *tAiL;
	}
	*tAiL = new_node;

}

// Функция для обмена значениями между двумя узлами списка
void swap(LinkedList* a, LinkedList* b) {
	RGBColor tp = a->data;//tp-temp,dt-data
	a->data = b->data;
	b->data = tp;
}

// Функция сортировки выбором списка
void selection_sort(LinkedList* hEaD)
{
	LinkedList* i, * j, * min;
	for (i = hEaD; i != NULL; i = i->next) {
		min = i;
		for (j = i->next; j != NULL; j = j->next) {
			if (j->data < min->data) {
				min = j;
			}
		}
		if (min != i) {
			swap(min, i);
		}
	}
}

// Функция удаления списка
void deleteList(LinkedList** hEaD) {
	LinkedList* real = *hEaD;
	LinkedList* nx;
	while (real != NULL) {
		nx = real->next;
		delete real;
		real = nx;
	}

	*hEaD = NULL;
}
//вывод в консоль
void print(LinkedList* hEaD)
{
	LinkedList* real = hEaD;
	while (real != NULL) {
		cout << real->data << " ";// Сохраняем значения элементов списка
		real = real->next;
	}
}
//проверка на упорядочнность
bool isSorted(LinkedList* hEaD) {
	if (hEaD == nullptr || hEaD->next == nullptr)  return true;//  список пустой или один элемент - упорядочен
		
	
	LinkedList* curr = hEaD;
	while (curr->next != nullptr) 
	{
		if (curr->data > curr->next->data) return false; // если текущий элемент больше следующего, то список неупорядочен
		curr = curr->next;
	}
	return true; // если мы дошли до конца списка без нарушения порядка, список упорядочен
}

int main()
{
	ifstream filein("input.txt", ios::binary);
	ofstream fileout("output.txt");
	int  liSt_sIzE = 0;

	//1.СЧИТЫВАЕМ ЧИСЛО ОБЪЕКТОВ
	filein >> liSt_sIzE;

	srand(time(nullptr)); // инициализируем генератор случайных чисел временем

	LinkedList* hEaD = NULL;
	LinkedList* tAiL = NULL;

	//2.ГЕНЕРИРУЕМ СПИСОК С УКАЗАННЫМ ЧИСЛОМ ОБЪЕКТОВ
	for (int i = 1; i <= liSt_sIzE; ++i)
	{ // генерируем случайные значения для компонентов RGB
		int r = rand() % 256;
		int g = rand() % 256;
		int b = rand() % 256;
		RGBColor color(r, g, b); // создаем новый объект RGBColor Color на основе сгенерированных значений
		cout << color;
		aDdNoDe(&hEaD, &tAiL, color); //добавляем в список
	}
	cout << endl;
	bool isListSorted = isSorted(hEaD);
	if (isListSorted) {
		cout << "4.LIST IS SORTED!!@##!!#@" << endl;
	}
	else {
		cout << "List is not sorted:((((" << endl;
	}
	//3.СОРТИРУЕМ СПИСОК
	selection_sort(hEaD);
	print(hEaD);

	 isListSorted = isSorted(hEaD);
	if (isListSorted) {
		cout << "4.LIST IS SORTED!!@##!!#@" << endl;
	}
	else {
		cout << "List is not sorted:((((" << endl;
	}


	//5.РАЗМЕР СПИСКА В ФАЙЛ
	fileout << liSt_sIzE;

	filein.close();
	fileout.close();
	deleteList(&hEaD);// Удаление списка
	return 0;
}




