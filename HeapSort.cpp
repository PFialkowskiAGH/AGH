// HeapSort.cpp : Defines the entry point for the console application.
//

#include <iostream>

using namespace std;

void heapify(int* T, int heapsize, int i)
{
	int L = 2 * i;
	int R = L + 1;
	int largest = i;
	if (L <= heapsize && T[L] > T[i]) largest = L;
	if (R <= heapsize && T[R] > T[largest]) largest = R;
	if (largest != i)
	{
		int pom = T[i];
		T[i] = T[largest];
		T[largest] = pom;
		heapify(T, heapsize, largest);
	}
};

void buildHeap(int* T, int heapsize)
{
	for (int i = heapsize / 2; i > 0; i--) heapify(T, heapsize, i);
};

void heapSort(int* T, int heapsize)
{
	buildHeap(T, heapsize);
	while (heapsize > 1)
	{
		int pom = T[1];
		T[1] = T[heapsize];
		T[heapsize] = pom;
		heapsize--;
		heapify(T, heapsize, 1);
	}
};

void showTable(int* T, int size)
{
	for (int i = 1; i < size; i++)
	{
		cout << T[i] << " ";
	}
	cout << endl;
};


int main()
{
	int T[10] = { 0, 20, -10, 6, -6, 3, 15, 8, 8, 30 };
	showTable(T, 10);
	heapSort(T, 9);
	showTable(T, 10);
	return 0;
}

