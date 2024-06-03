﻿/*Уровень 1
<логическое выражение> → <операнд> | <операнд><операция сравнения><операнд>
<операция сравнения> → < | > | <= | >= | = | <>
<операнд> → <идентификатор>|<константа>
<операторы> → <идентификатор> = <арифметическое выражение>
<арифметическое выражение> → <операнд> |
<арифметическое выражение><арифметическая операция><операнд>
<арифметическая операция> → + | –

Конструкция 8 - оператор ветвления.
select <арифметическое выражение>
case <константа> <операторы>
[ case <константа> <операторы> ]
[ default <операторы> ]
end

 */




#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <vector>
#include <ctype.h>
#include <cstring>

using namespace std;
enum  Ast { S, A, B, B2, B3, C, D, F, G, H, H1, H2, J, E, id_l, ao_l, co_l, vl_l, eq_l, Er }; // id_l, ao_l, co_l, vl_l, eq_l - последние нормальные состояния
const char lex_name[10][3]{ "id", "ao", "co", "vl", "eq",  "en", "se", "ca", "wl", "de" }; // имя типа лексемы для вывода в файл
enum LexType { id, ao, co, vl, eq, en, se, ca, wl, de }; // тип лексемы
const char* PosLex[]{ "if", "id vl", "th co", "id vl", "th", "id"," eq", "id vl", "ei ao en", "id vl", "id vl", "th co", "id vl", "th", "id", "eq", "id vl", "ao en", "id vl" };
const int matrix[8][8] = {     // матрица состояний
	// frst0 alf1  0-9(2)    +-3   <4    >5    =6    мусор 
		{A,	A,	  E,    ao_l,co_l,co_l,eq_l, E}, //0
		{B,	A,	  B,    ao_l,co_l,co_l,eq_l, E},//1
		{C, id_l, vl_l, ao_l,co_l,co_l,eq_l, S},//2
		{D, id_l, vl_l, ao_l,co_l,co_l,eq_l, S},//3
		{G, id_l, vl_l, ao_l, G,  co_l,eq_l, S},//4
		{H, id_l, vl_l, ao_l, G,  G,   eq_l, S},//5
		{S, id_l, vl_l, ao_l,co_l,co_l,eq_l, S},//6
		{E, E,	  E,    ao_l,co_l,co_l,eq_l, E},//7
};
//const int matrix_prov[10][9]{
//	//     S0  A1  B2  C3  D4  G5  H6  E7  J8
//	/*0*/ {Er, B,  Er, D,  B,  Er, E,  Er, J }, // id
//	/*1*/ {Er, Er, C,  Er, C,  Er, Er, Er, Er}, // +-  (ao)
//	/*2*/ {Er, Er, Er, Er, Er, Er, Er, N,  Er}, // <>  (co)
//	/*3*/ {Er, Er, Er, D,  Er, Er, E,  Er, J }, // 0-9 (vl)
//	/*4*/ {Er, Er, C,  Er, Er, Er, Er, Er, Er}, // =   (eq)
//	/*5*/ {A,  Er, Er, Er, Er, Er, Er, Er, Er}, // select
//	/*6*/ {Er, Er, C,  Er, G,  Er, Er, Er, Er}, // case
//	/*7*/ {Er, Er, Er, Er, Er, H,  Er, Er, Er}, // end
//	/*7*/ {Er, Er, Er, Er, Er, H,  Er, Er, Er}, // default
//	/*8*/ {Er, Er, Er, Er, Er, Er, Er, Er, Er}, // 
//};
const int matrix_prov[10][12]{
	//     S0  A   B   B2   B3  C   D   F   G  H  H1  H2   Y
	/*0*/ {Er, B,  Er, B3, Er, Er, F,  Er, H,  Er, H2, Er, }, // id
	/*1*/ {Er, Er, B2, Er, Er, Er, Er, Er, Er, H1, Er, Er, }, // +-  (ao)
	/*2*/ {Er, Er, Er, Er, Er, Er, Er, Er, Er, Er, Er, Er, }, // <>  (co)
	/*3*/ {Er, Er, Er, D,  Er, D,  Er, Er, Er, Er, H2, Er, }, // 0-9 (vl)
	/*4*/ {Er, Er, C,  Er, Er, Er, Er, G,  Er, Er, Er, Er, }, // =   (eq)
	/*5*/ {A,  Er, Er, Er, Er, Er, Er, Er, Er, Er, Er, Er, }, // select
	/*6*/ {Er, Er, C,  Er, C,  Er, Er, Er, Er, Er, Er, C,  }, // case 
	/*7*/ {Er, Er, Er, Er, Er, Er, Er, Er, J,  Er, Er, J,  }, // end
	/*7*/ {Er, Er, Er, Er, Er, Er, Er, Er, Er, Er, Er, C,  }, // default
	/*8*/ {Er, Er, Er, Er, Er, Er, Er, Er, Er, Er, Er, Er, }, // 
};

struct Lex {
	char* lex;
	int type; // тип лексемы
};
// берём состояние из матрицы так:
// столбец - что за сивмол (st) строка - текущее состояние(его номер)
int fun_matrix(int state, char letter) {     // проходим по матрице состояний
	int state1 = 7;
	if (isalpha(letter)) state1 = 0;
	else if (letter >= '0' && letter <= '9') state1 = 1;
	else if (letter == '+' || letter == '-') state1 = 2;
	else if (letter == '<') state1 = 3;
	else if (letter == '>') state1 = 4;
	else if (letter == '=') state1 = 5;
	else if (iscntrl(letter) || isspace(letter)) state1 = 6; // если \n,\t,\r, пробел
	return matrix[state1][state];
}
int prov_kw(const Lex& l) { // проверка на ключевое слово 
	if (!strcmp(l.lex, "end")) return 8; // strcmp если строки равны, возвращает ноль
	if (!strcmp(l.lex, "select")) return 9;
	if (!strcmp(l.lex, "case")) return 10;
	if (!strcmp(l.lex, "default")) return 11;
	return 6;
}
void push(char*& line, vector<Lex>& v, int& first, int& end, int type) { // добавление в вектор слова
	Lex lexem; // создаём пустою лексему
	int len = end - first;
	char* slovo = new char[len + 1]; // создаём массив для слова
	strncpy(&slovo[0], &line[first], len); // Вычленение подстроки и запись в лексему
	slovo[len] = '\0'; // Постановка финализирующего 0
	first = end--;
	lexem.lex = slovo; // записываем в лексему
	// проверка на ключевое слово и на диапазон инта
	if (type == id) lexem.type = prov_kw(lexem);
	else if (type == vl) { atoi(lexem.lex) > 32767 ? lexem.type = wl : lexem.type = vl; }
	else lexem.type = type;
	v.push_back(lexem);  // добавляем лексему в вектор

}
	void lex_analis(char* line, vector<Lex>& v) {  // анализ лексемы
		int first = 0, curr = first, state = S;
		bool valid = true;
		do {
	
			state = fun_matrix(state, line[curr]);   // берём состояние из матрицы
			switch (state) { // заходим в свитч если состояние последнее
			case S:
				if (valid) first = curr + 1;  // заходим сюда если пробел и двигаем начало слова на один
				else { // сюда заходим если слово делает вид что правильное но это не так
					push(line, v, first, curr, wl);
					state = S;
					valid = true;
				}
				break;
			case E:   // если что-то не так то валид ровно неправда
				valid = false;
				break;
			}
			if (state >= 10) { // если состояние конечное
	
				push(line, v, first, curr, state - 10);
				state = S;
			}
	
		} while (line[curr++]); // ходим по строке
	}

	//void analysis(vector<Lex>&words, ofstream & ofile)
	//{
	//	int current_state = S; int previous_state = S;
	//	size_t i;
	//	//Непосредственно алгоритм синтаксического анализа
	//	for (i = 0; i < words.size(); ++i) {
	//		current_state = table[words[i].type][current_state];
	//		if (current_state == E) {
	//			error_throw(i, previous_state, ofile);
	//			break;
	//		}
	//		if (current_state == F) {
	//			current_state = S;
	//			OK_throw(ofile);
	//		}
	//		previous_state = current_state;
	//	}
	//	//Проверка на пустой файлик
	//	if (current_state == S && !i)
	//		error_throw(i, previous_state, ofile);
	//	else if (current_state != E && current_state != S)
	//		error_throw(i, previous_state, ofile);
	//}

	void out_error(int state, ofstream & fout) { // обнаружение и вывод типов которые должны быть
		int* Array; // в массиве будут номера возможных типов
		int n = 0, j = 0;
		for (int i = 0; i < 9; ++i)if (matrix_prov[i][state] != Er) ++n; // проходим по столбцу, номер которого - номер состояния и ищем все правильные исходы
		Array = new int[n]; // создаём массив с найденым размером
		for (int i = 0; i < 9; ++i) {
			if (matrix_prov[i][state] != Er) { // проходим ещё раз но теперь записываем номера состояний в матрицу
				Array[j] = i;
				j++; // проход по массиву
			}
		}
		for (int i = 0; i < n; i++)fout << lex_name[Array[i]] << " "; // выводим типы в соответствии с номером
		delete[] Array;
	}

	/*void Synt_analis(vector <Lex>& LEX, ofstream& file2)
	{

		Ast curState = S;
		Ast prevState;
		int Cur = 0;
		int Size = LEX.size();
		while (Size-- && curState != Er) {
			prevState = curState;
			curState = matrix_provv[LEX[Cur].type][curState];
			++Cur;
		}
		if (curState == S) {
			file2 << "OK";
			cout << "OK";
		}
		else if (curState == Er) {
			file2 << --Cur << " " << PosLex[prevState];
			cout << Cur << ' ' << PosLex[prevState];
		}
		else {
			file2 << Cur << " " << PosLex[curState];
			cout << Cur << ' ' << PosLex[curState];
		}
	}*/

	void proverka(vector<Lex>& v, ofstream& fout) { // функция проверки на правильность
	
		int State = S, pred;
		// состояние pred нужно на случай если выпадет ошибка во время перехода по матрице (Er), потому что Er = 15, а матрица не настолько большая(
		// ну если сказать по другому, я вывожу те типы которые идут после последнего правильного состояния, а если у меня Er то беру предыдущий
		for (size_t i = 0; i < v.size(); ++i) { // проходим по вектору лексем
			if (State != Er) { // чтобы лишний раз не ходить после ошибки
				pred = State;
				State = matrix_prov[v[i].type][State]; // гуляем
				if ((State == E && i == v.size() - 1) || (i != v.size() - 1 && v[i + 1].type == 5) || State == J) {
					// если дошли до совсем конца(J) или дошли до например while a, а дальше нет ничего или новая конструкция, то окей
	
					if (i != v.size() - 1) State = S; // если ещё есть конструкия, идём дальше
					else fout << endl << "OK";
				}
				if ((i == v.size() - 1 && State != J && State != E) || (State == Er)) { // конструкция правильная но не дошла до конца, или есть ошибка
	
					State == Er ? fout << endl << i << " " : fout << endl << i + 1 << " "; // выводим место ошибки (если не ошибочное состояние, то ошибка дальше)
					if (State == Er) out_error(pred, fout); // залезаем в функцию поиска нужных типов
					else out_error(State, fout);
				}
			}
		}
	
	}

	void Synt_analis(vector <Lex>&LEX, ofstream & file2)
	{

		int curState = S;
		int prevState;
		int Cur = 0;
		int Size = LEX.size();
		while (Size-- && curState != Er) {
			prevState = curState;
			curState = matrix_prov[LEX[Cur].type][curState];
			++Cur;
		}
		if (curState == S) {
			file2 << "OK";
			cout << "OK";
		}
		else if (curState == Er) {
			file2 << --Cur << " " << PosLex[prevState];
			cout << Cur << ' ' << PosLex[prevState];
		}
		else {
			file2 << Cur << " " << PosLex[curState];
			cout << Cur << ' ' << PosLex[curState];
		}
	}

	int main() {
		// читаем файл
		ofstream vivod("output.txt");
		ifstream vvod("input.txt");
		vvod.seekg(0, ios::end);
		int size = vvod.tellg();
		vvod.seekg(0, ios::beg);
		char* line;
		line = new char[(size_t)size + 1];
		vvod.getline(line, size + 1, '\0');
		vvod.close();
		vector<Lex> v;
		// анализируем файл
		lex_analis(line, v);
		// выводим что получилось
		for (size_t i = 0; i < v.size(); ++i) {
			vivod << v[i].lex << '[' << lex_name[v[i].type];
			(i == v.size() - 1) ? vivod << ']' : vivod << "] ";
		}
		proverka(v, vivod); // функция проверки на правильность
		for (size_t i = 0; i < v.size(); ++i) delete[] v[i].lex;
		delete[] line;
		vivod.close();
	}
