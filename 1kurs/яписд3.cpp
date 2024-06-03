//
//#include <fstream>
//#include <iostream>
//using namespace std;
//
//class Node { //  элемент двусвязного списка
//public:
//	double data;
//	Node* prev, * next;
//public: //конструктор
//	Node(double data) {
//		this->data = data;
//		this->prev = this->next = NULL;
//	}
//};
//
//class LinkedList {
//public:
//	Node* head, * tail;
//public:
//	LinkedList() { //конструктор
//		head = tail = NULL;
//	}
//
//	~LinkedList() { //деструктор
//		while (head != NULL)
//			pop_front;
//	}
//
//	Node* push_front(double data) { //добавление в начало
//		Node* ptr = new Node(data);
//		ptr->next = head;
//		if (head != NULL) head->prev = ptr;
//		if (tail == NULL) tail = ptr; //добавляем самый первый объект
//		head = ptr;
//		return ptr; //cсылка на добавленный объект
//	}
//
//	Node* push_back(double data) { //добавление в конец
//		Node* ptr = new Node(data);
//		ptr->prev = tail;
//		if (tail != NULL) tail->next = ptr;
//		if (head == NULL) head = ptr; //если добавляем самый первый объект
//		tail = ptr;
//		return ptr; //cсылка на добавленный объект
//	}
//
//	void pop_front()//удаление с начала
//	{
//		if (head == NULL) return; //элементов нет
//
//		Node* ptr = head->next; //следующий элемент после head
//		if (ptr != NULL)
//			ptr->prev = NULL; //удаление первого, указ на него = NULL
//		else
//			tail = NULL; //если 1 элемент
//
//		delete head;
//		head = ptr;
//	}
//
//	void pop_back()//удаление с конца
//	{
//		if (tail == NULL) return; //элементов нет
//
//		Node* ptr = tail->prev; // элемент перед tail
//		if (ptr != NULL)
//			ptr->next = NULL; //удаление последнего, указ на него = NULL
//		else
//			head = NULL; //если 1 элемент
//
//		delete tail;
//		tail = ptr;
//	}
//
//	Node* getAt(int index) { //доступ к произвольному эл-ту списка
//		Node* ptr = head;
//		int n = 0;
//
//		while (n != index) { //проход до нужного индекса
//			if (ptr == NULL) //не сущ или конец
//				return NULL;
//			ptr = ptr->next;
//			n++;
//		}
//		return ptr;
//	}
//
//	Node* operator [] (int index) {
//		return getAt(index);
//	}
//
//	Node* insert(int index, double data) { //вставка 
//		Node* right = getAt(index);
//		if (right == NULL) return push_back(data);
//
//		Node* left = right->prev;
//		if (left == NULL) push_front(data);
//
//		Node* ptr = new Node(data);
//		//связи
//		ptr->prev = left;
//		ptr->next = right;
//		left->next = ptr;
//		right->prev = ptr;
//
//		return ptr;
//	}
//
//	void erase(int index) {//удаление
//		Node* ptr = getAt(index);
//		if (ptr == NULL) return;  //не сущ
//
//		if (ptr->prev == NULL) //птр первый эл-т
//		{
//			pop_front();
//			return;
//		}
//
//		if (ptr->next == NULL) { //птр последний
//			pop_back();
//			return;
//		}
//
//		Node* left = ptr->prev;
//		Node* right = ptr->next;
//		left->next = ptr;
//		right->prev = ptr;
//	}
//	
//	void print(LinkedList& list) {
//
//	 }
//
//	//объявление дружественных операторов
//	//cin>>
//
//	friend ifstream& operator>> (ifstream&, LinkedList&);
//	//cout<<
//	friend ostream& operator<< (ostream&, const LinkedList&);
//	friend ofstream& operator<< (ofstream&, const LinkedList&);
//
//	
//
//
//int main()
//{
//	LinkedList list;
//	return 0;
//}


#include <iostream>
#include <fstream>

using namespace std;

// объявление структуры двусвязного нециклического списка
struct doublyLinkedList
{
	int data; // значение
	doublyLinkedList* next; // указатель на следующий элемент
	doublyLinkedList* prev; // указатель на предыдущий элемент
};

// инициализация списка
doublyLinkedList* initialisationList(int num)  // а- значение первого узла
{
	doublyLinkedList* list;
	list = (struct doublyLinkedList*)malloc(sizeof(struct doublyLinkedList)); // // выделение памяти под корень списка
	list->data = num;
	list->next = NULL; // указатель на следующий узел
	list->prev = NULL; // указатель на предыдущий узел
	return list;
}

// добавление элемента в список
doublyLinkedList* addElement(doublyLinkedList* newList, int num)
{
	doublyLinkedList* temp, * temp2;
	temp = (doublyLinkedList*)malloc(sizeof(doublyLinkedList));
	temp2 = newList->next; // сохранение указателя на следующий узел
	newList->next = temp; // предыдущий узел указывает на создаваемый
	temp->data = num; // сохранение поля данных добавляемого узла
	temp->next = temp2; // созданный узел указывает на следующий узел
	temp->prev = newList; // созданный узел указывает на предыдущий узел
	if (temp2) temp2->prev = temp;
	return temp;
}
// удаление элемента из списка
void deleteElements(doublyLinkedList*& head)
{              //удаление элемента
	if (head)
	{                          //рассматриваем только непустую голову
		doublyLinkedList* temp = head->next;
		delete head;
		head = temp;
	}
}
// функция обмена указателями, возвращает новый корень списка
doublyLinkedList* swap1(struct doublyLinkedList* l1, struct doublyLinkedList* l2, struct doublyLinkedList* head)
{
	doublyLinkedList* firstPrev, * secondPrev, * firstNext, * secondNext;
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

void swap2(doublyLinkedList* innerCurrent, doublyLinkedList* prev) {
	innerCurrent->prev->next = innerCurrent->next;
	if (innerCurrent->next) innerCurrent->next->prev = innerCurrent->prev;
	innerCurrent->prev = prev;
	innerCurrent->next = prev->next;
	if (prev->next) prev->next->prev = innerCurrent;
	prev->next = innerCurrent;
}
// функция для вывода в файл списка

doublyLinkedList* insertionSort(doublyLinkedList* head) {
	if (!head || !head->next) return head; // если список пустой или содержит 1 элемент, то он уже отсортирован, поэтому сразу возвращаем голову

	// ищем минимальный элемент
	// так как сортировка вставками начинается со 2го, то необходимо, чтобы голова была минимальным элементом, иначе первые несколько элементов не отсортируются
	// поэтому я ищу минимальный элемент и вставляю его в начало списка
	doublyLinkedList* minNode = head;
	doublyLinkedList* current = head->next;
	while (current) {
		if (current->data < minNode->data)
			minNode = current;
		current = current->next;
	}

	// Перестановка минимального элемента в начало списка
	if (minNode != head)
	{
		head = swap1(head, minNode, head);
		current = head->next;
	}

	while (current) {
		doublyLinkedList* innerCurrent = current;
		int value = innerCurrent->data;
		doublyLinkedList* prev = innerCurrent->prev;
		while (prev && prev->data > value)
			prev = prev->prev;
		if (!prev)
			head = swap1(innerCurrent, innerCurrent->prev, head);
		else
			swap2(innerCurrent, prev);
		current = current->next;
	}
	return head;
}

void listToFile(doublyLinkedList* head, int size) //вывод в файл
{
	ofstream toFile("output.txt");
	doublyLinkedList* p = head;
	toFile << size << " ";
	do {
		toFile << p->data << " ";
		p = p->next;
	} while (p);
	toFile.close();
}

int main()
{
	int whichSort, listSize = 1, headList, number; // listSize = 1, потому что голова списка считывается заранее и не учитывается при подсчете размера списка

	ifstream fromFile("input.txt");
	fromFile >> whichSort;
	fromFile >> headList;
	doublyLinkedList* listForLaba = initialisationList(headList);

	while (!fromFile.eof())
	{
		fromFile >> number;
		addElement(listForLaba, number);
		cout << number;
		++listSize;
	}

	listForLaba = insertionSort(listForLaba);
	listToFile(listForLaba, listSize);
	for (int i = 0; i < listSize; i++) deleteElements(listForLaba);
	
	return 0;
}