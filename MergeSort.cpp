/******************************************************************************

Online C++ Compiler.
Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

struct node
{
	int val;
	node* next;
};

void Add(node*& H, int x)
{
	node* p = new node;
	p->val = x;
	p->next = H;
	H = p;
};

void Delete(node*& H)
{
	node* p = H;
	H = p->next;
	delete p;
};

void Show(node* H)
{
	cout << "H->";
	node* p = H;
	while (p != NULL)
	{
		cout << p->val << "->";
		p = p->next;
	}
	cout << "Null" << endl;
};

int returnListLength(node* H)
{
	node* p = H;
	if (H == NULL) return 0;
	else if (H->next == NULL) return 1;
	else
	{
		int counter = 1;
		while (p->next != NULL)
		{
			counter++;
			p = p->next;
		}
		return counter;
	}
};

void splitListInHalf(node*& H, node*& H1, node*& H2)
{
	if (H != NULL)
	{
		H1 = H;
		if (H->next != NULL)
		{
			int length = returnListLength(H);
			node* p = H;
			for (int i = 1; i < length / 2; i++) p = p->next;
			H2 = p->next;
			p->next = NULL;
		}
	}
	H = NULL;
};

void mergeTwoList(node*& H, node*& H1, node*& H2)
{
	if (H1 != NULL && H2 == NULL) H = H1;
	else if (H1 == NULL && H2 != NULL) H = H2;
	else if (H1 != NULL && H2 != NULL)
	{
		node* T = NULL;
		node* p = NULL;
		while (H1 != NULL && H2 != NULL)
		{
			if (H1->val < H2->val)
			{
				p = H1;
				H1 = H1->next;
				if (H == NULL)
				{
					H = p;
					T = p;
				}
				else
				{
					T->next = p;
					T = p;
				}
			}
			else
			{
				p = H2;
				H2 = H2->next;
				if (H == NULL)
				{
					H = p;
					T = p;
				}
				else
				{
					T->next = p;
					T = p;
				}
			}
		}
		if (H1 == NULL)
		{
			T->next = H2;
			H2 = NULL;
		}
		else
		{
			T->next = H1;
			H1 = NULL;
		}
	}
};

void mergeSort(node*& H)
{
	if (H != NULL && H->next != NULL)
	{
		node* H1 = NULL;
		node* H2 = NULL;
		splitListInHalf(H, H1, H2);
		mergeSort(H1);
		mergeSort(H2);
		mergeTwoList(H, H1, H2);
	}
}

int main()
{
	node* H = new node;
	Add(H, 4);
	Add(H, -8);
	Add(H, 22);
	Add(H, 5);
	Add(H, 16);
	Add(H, -6);
	Add(H, 2);
	Add(H, 3);
	Add(H, 8);
	Show(H);
	mergeSort(H);
	Show(H);
	return 0;
}
