// яписд32.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>

using namespace std;

// объявление структуры двусвязного нециклического списка
struct LinkedList
{
	int data; // значение
	LinkedList* next; // указатель на след эл
	LinkedList* prev; // указатель на пред эл
};

// инициализация списка
LinkedList* init(int datta)  // значение первого узла
{
	LinkedList* list;
	list = (struct LinkedList*)malloc(sizeof(struct LinkedList)); // // выделение памяти под корень списка
	list->data = datta;
	list->next = NULL;
	list->prev = NULL;
	return list;
}

//LinkedList* addElement(LinkedList* newList, int num)
//{
//	LinkedList* temp, * temp2;
//	temp = (LinkedList*)malloc(sizeof(LinkedList));
//	temp2 = newList->next; // сохранение указателя на следующий узел
//	newList->next = temp; // предыдущий узел указывает на создаваемый
//	temp->data = num; // сохранение поля данных добавляемого узла
//	temp->next = temp2; // созданный узел указывает на следующий узел
//	temp->prev = newList; // созданный узел указывает на предыдущий узел
//	if (temp2) temp2->prev = temp;
//	return temp;
//}

//void addElement(LinkedList** head, int data) {
//	LinkedList* newNode = new LinkedList{ data, nullptr };
//
//	if (*head == nullptr) {
//		*head = newNode;
//	}
//	else {
//		LinkedList* current = *head;
//		while (current->next != nullptr) {
//			current = current->next;
//		}
//
//		current->next = newNode;
//	}
//}

LinkedList* addElement(LinkedList* newList, int num)
{
	LinkedList* temp, * temp2;
	temp = (LinkedList*)malloc(sizeof(LinkedList));
	temp2 = newList->next; // сохранение указателя на следующий узел
	newList->next = temp; // предыдущий узел указывает на создаваемый
	temp->data = num; // сохранение поля данных добавляемого узла
	temp->next = temp2; // созданный узел указывает на следующий узел
	temp->prev = newList; // созданный узел указывает на предыдущий узел
	if (temp2) temp2->prev = temp;
	return temp;
}
// удаление элемента из списка
void deleteElements(LinkedList*& head)
{              //удаление элемента
	if (head)
	{                          //рассматриваем только непустую голову
		LinkedList* temp = head->next;
		delete head;
		head = temp;
	}
}


LinkedList* swap(struct LinkedList* l1, struct LinkedList* l2, struct LinkedList* head)
{
	LinkedList* firstPrev, * secondPrev, * firstNext, * secondNext;
	firstPrev = l1->prev;  // узел предшествующий l1
	secondPrev = l2->prev;  // узел предшествующий l2
	firstNext = l1->next; // узел следующий за l1
	secondNext = l2->next; // узел следующий за l2
	if (l2 == firstNext)  // обмениваются соседние узлы
	{
		l2->next = l1;
		l2->prev = firstPrev;
		l1->next = secondNext;
		l1->prev = l2;
		if (secondNext != NULL) secondNext->prev = l1;
		if (l1 != head) firstPrev->next = l2;
	}
	else if (l1 == secondNext)  // обмениваются соседние узлы
	{
		l1->next = l2;
		l1->prev = secondPrev;
		l2->next = firstNext;
		l2->prev = l1;
		if (firstNext != NULL) firstNext->prev = l2;
		if (l2 != head) secondPrev->next = l1;
	}
	else  // обмениваются отстоящие узлы
	{
		if (l1 != head)  // указатель prev можно установить только для элемента,
			firstPrev->next = l2; // не являющегося корневым
		l2->next = firstNext;
		if (l2 != head) secondPrev->next = l1;
		l1->next = secondNext;
		l2->prev = firstPrev;
		if (secondNext != NULL) // указатель next можно установить только для элемента,
			secondNext->prev = l1; // не являющегося последним
		l1->prev = secondPrev;
		if (firstNext != NULL) firstNext->prev = l2;
	}
	if (l1 == head)
		return l2;
	if (l2 == head)
		return l1;
	return head;
}


void selectionSort(LinkedList* start) {
	for (LinkedList* i = start; i->next != NULL; i = i->next) {
		LinkedList* min = i;
		for (LinkedList* j = i->next; j != NULL; j = j->next) {
			if (j->data < min->data) {
				min = j;
			}
		}
		if (min != i) {
			swap(i, min);
		}
	}
}

void print(LinkedList* head, int size) //вывод в файл
{
	ofstream fileout("output.txt");
	LinkedList* p = head;
	fileout << size << " ";
	do {
		fileout << p->data << " ";
		p = p->next;
	} while (p);
	fileout.close();
}

int main()
{
	int whichSort, listSize = 1, headList, number;
	LinkedList* head = nullptr;
	ifstream filein("input.txt");
	filein >> whichSort;
	filein >> headList;
	LinkedList* LIST = init(headList);

	while (!filein.eof())
	{
		filein >> number;
		addElement(LIST, number);
		cout << number;
		++listSize;
	}

	selectionSort(LIST);
	print(LIST, listSize);
	for (int i = 0; i < listSize; i++) deleteElements(LIST);

	return 0;
}


