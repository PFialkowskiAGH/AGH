// BTSTree.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>

using namespace std;

struct node
{
	int val;
	node* L;
	node* R;
	node* up;
};

void insertBST(node*& root, int x, node*& up)
{
	if (root == NULL)
	{
		root = new node;
		root->val = x;
		root->R = root->L = NULL;
		root->up = up;
	}
	else
	{
		if (x < root->val) insertBST(root->L, x, root);
		else insertBST(root->R, x, root);
	}
}

void inOrder(node* root)
{
	if (root != NULL)
	{
		inOrder(root->L);
		cout << root->val << " ";
		inOrder(root->R);
	}
}

void findMax(node*& root, node*& max)
{
	if (root != NULL)
	{
		if (root->R != NULL) findMax(root->R, max);
		else max = root;
	}
}

void findMin(node*& root, node*& min)
{
	if (root != NULL)
	{
		if (root->L != NULL) findMin(root->L, min);
		else min = root;
	}
}

void findSuccessor(node*& root, node*& successor)
{
	if (root != NULL)
	{
		if (root->R != NULL) findMin(root->R, successor);
		else if(root->up != NULL && root->up->L == root) successor = root->up;
		else successor = NULL;
	}
}

void findPredecessor(node*& root, node*& predecessor)
{
	if (root != NULL)
	{
		if (root->L != NULL) findMax(root->L, predecessor);
		else if (root->up != NULL && root->up->R == root) predecessor = root->up;
		else predecessor = NULL;
	}
}

void deleteNode(node*& root)
{
	if (root != NULL)
	{
		if (root->L == NULL && root->R == NULL)
		{
			if (root->up != NULL)
			{
				if (root->up->L == root) root->up->L = NULL;
				else root->up->R = NULL;
			}
			//cout << "usuwam" << root->val;
			delete root;
		}
		else
		{
			node* succOrPred = NULL;
			findSuccessor(root, succOrPred);
			//cout << succOrPred->val << endl;
			if (succOrPred == NULL) findPredecessor(root, succOrPred);
			node* p = new node;
			p->val = succOrPred->val;
			p->up = root->up;
			p->L = root->L;
			p->R = root->R;
			if (root->up != NULL)
			{
				if (root->up->L == root) root->up->L = p;
				else root->up->R = p;
			}
			//cout << "usuwam" << root->val;
			delete root;
			deleteNode(succOrPred);
			
		}
	}
}


int main()
{
	node* root = NULL;
	node* up = NULL;
	node* max = NULL;
	node* min = NULL;
	node* successor = NULL;
	node* predecessor = NULL;
	insertBST(root, 13, up);
	insertBST(root, 8, up);
	insertBST(root, 10, up);
	insertBST(root, -3, up);
	insertBST(root, 8, up);
	insertBST(root, 12, up);
	insertBST(root, 36, up);
	insertBST(root, 18, up);
	insertBST(root, 22, up);

	inOrder(root);
	cout << endl;

	findMax(root, max);
	cout << "Maksimum to: " << max->val << endl;

	findMin(root, min);
	cout << "Minimum to: " << min->val << endl;

	findSuccessor(root, successor);
	cout << "Nastepnik " << root->val << " to: " << successor->val << endl;

	findPredecessor(root, predecessor);
	cout << "Poprzednik " << root->val << " to: " << predecessor->val << endl;

	deleteNode(root);
	inOrder(root);
	cout << endl;

	//system("PAUSE");
	return 0;
}

// Uruchomienie programu: Ctrl + F5 lub menu Debugowanie > Uruchom bez debugowania
// Debugowanie programu: F5 lub menu Debugowanie > Rozpocznij debugowanie

// Porady dotyczące rozpoczynania pracy:
//   1. Użyj okna Eksploratora rozwiązań, aby dodać pliki i zarządzać nimi
//   2. Użyj okna programu Team Explorer, aby nawiązać połączenie z kontrolą źródła
//   3. Użyj okna Dane wyjściowe, aby sprawdzić dane wyjściowe kompilacji i inne komunikaty
//   4. Użyj okna Lista błędów, aby zobaczyć błędy
//   5. Wybierz pozycję Projekt > Dodaj nowy element, aby utworzyć nowe pliki kodu, lub wybierz pozycję Projekt > Dodaj istniejący element, aby dodać istniejące pliku kodu do projektu
//   6. Aby w przyszłości ponownie otworzyć ten projekt, przejdź do pozycji Plik > Otwórz > Projekt i wybierz plik sln
