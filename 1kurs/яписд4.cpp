// Дерево поиска. Процедура: Отражение дерева. Обход дерева: Симметричный.
//у каждого узла не более 2х потомков
//все значения узлов левого потомков<=корневого узла, все значения узлов правого потомков>=корневого узла

#include <iostream>
#include <fstream>

using namespace std;

struct tree
{
	int val; //ключ
	tree* left; //указатель на левого потомка
	tree* right; //на правого потомка
};

tree* createnode(int a)  //создание узла
{
	tree* T = new tree;
	T->val = a;
	T->left = T->right = NULL;
	return T;

}

//заполнение дерева
void push(tree*& root, tree* node) //принимает указатель на корень и на узел
{
	if (root) //существование дерева(корень)
	{
		if (node->val <= root->val) //если значения узла <= значением в корне
			push(root->left, node); //в левое поддерево

		else push(root->right, node); //иначе в правое поддерево

	}

	else root = node; //создание корня

}

//чтение
tree* readtree(const char* filename) //возвращает указатель на корень дерева
{
	tree* T = NULL;

	ifstream filein;
	filein.open(filename);

	int a;

	while (!filein.eof())  //считывание узлов
	{
		filein >> a;
		push(T, createnode(a));
	}

	filein.close();

	return T;
}

//свап для узлов
void swap_nodes(tree** node1, tree** node2)
{
	tree* buff = *node1;
	*node1 = *node2;
	*node2 = buff;
}

// Функция отражения дерева
//принимает указатель на корень бинарного дерева и рекурсивно обходит его
void MIRROR(tree* node)
{

	if (node)
	{
		//левое поддерево
		MIRROR(node->left);

		//правое поддерево
		MIRROR(node->right);

		// поменять местами левое поддерево с правым поддеревом
		swap_nodes(&node->left, &node->right);
	}
}


//вывод рекурсивным симметричным обходом
void simmetr(ofstream& fout_name, tree* node)
{
	if (node) 
	{
		simmetr(fout_name, node->left);
		fout_name << node->val << " ";
		simmetr(fout_name, node->right);
	}
}


void erasetree(tree*& node) //удаление дерева
{
	if (node)
	{
		erasetree(node->left);
		erasetree(node->right);
		delete node;
	}
}


int main()
{
	ofstream fileout;
	fileout.open("output.txt");
	//создание дерева
	tree* T;
	T = readtree("input.txt");
	//отражение
	MIRROR(T);
	//симметричный вывод
	simmetr(fileout, T);
	//очистка памяти
	erasetree(T);
	return 0;
}
