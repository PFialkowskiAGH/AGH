// conbSort.cpp : Defines the entry point for the console application.
//

#include <iostream>

using namespace std;

void bubbleSort(int* tab, int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size - 1; j++)
		{
			if (tab[j] > tab[j + 1])
				swap(tab[j], tab[j + 1]);

		}
	}
}

int getGap(int current)
{
	current = current / 1.3;
	if (current < 1) current = 1;
	return current;
}

void combSort(int* tab, int size, int gap)
{
	gap = getGap(gap);
	if (gap == 1) bubbleSort(tab, size);
	else
	{
		for (int i = 0; i + gap < size; i++)
		{
			if (i + gap < size)
			{
				if (tab[i] > tab[i + gap]) swap(tab[i], tab[i + gap]);
			}
		}
		combSort(tab, size, gap);
	}
}

void showTable(int* tab, int size)
{
	for (int i = 0; i < size; i++) cout << tab[i] << endl;
}


int main()
{
	int tab[8] = { 8,1,6,-5,33,-16,25,7 };
	showTable(tab, 8);

	cout << "Posortowane:" << endl;
	combSort(tab, 8, 8);
	showTable(tab, 8);

	return 0;
}

