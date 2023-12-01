#include <iostream>

using namespace std;

struct Node
{
	int key;
	struct Node* left, * right;
};

// Служебная функция для создания нового узла дерева бинарного поиска 
struct Node* newNode(int item)
{
	struct Node* temp = new Node;
	temp->key = item;
	temp->left = temp->right = NULL;
	return temp;
}

// Хранит порядок обхода ДБП в arr[]
void storeSorted(Node* root, int arr[], int& i)
{
	if (root != NULL)
	{
		storeSorted(root->left, arr, i);
		arr[i++] = root->key;
		storeSorted(root->right, arr, i);
	}
}

/* Служебная функция, чтобы вставить новый
узел с заданным ключом по ДБП */
Node* insert(Node* node, int key)
{
	// Если дерево пусто, возвращаем новый узел
	if (node == NULL) return newNode(key);

	// В противном случае повторяем спуск по дереву
	if (key < node->key)
		node->left = insert(node->left, key);
	else if (key > node->key)
		node->right = insert(node->right, key);

	// Возвращает неизменный указатель узла
	return node;
}

// Эта функция сортирует arr[0..n-1] используя сортировку деревом
void treeSort(int arr[], int n)
{
	struct Node* root = NULL;

	// Построение ДБП 
	root = insert(root, arr[0]);
	for (int i = 1; i < n; i++)
		root = insert(root, arr[i]);

	// Хранит обход дерева по порядку в arr[]
	int i = 0;
	storeSorted(root, arr, i);
}

int main()
{
	int arr[] = { 5, 4, 7, 2, 11 };
	int n = sizeof(arr) / sizeof(arr[0]);

	treeSort(arr, n);

	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";

	return 0;
}
