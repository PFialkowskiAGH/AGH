// conbSort.cpp : Defines the entry point for the console application.
//

#include <iostream>

using namespace std;

int partitionLomuto(int* tab, int l, int r) 
{
	int x = tab[r];
	int i = l - 1;
	for (int j = l; j < r; j++)
		if (tab[j] < x) { i++; swap(tab[i], tab[j]); }
	swap(tab[i + 1], tab[r]);
	return i + 1;
}

int partitionHoare(int* tab, int l, int r)
{
	int x = tab[l];
	int i = l, j = r + 1;
	while (true) {
		do { i++; } while (i <= r && tab[i] < x);
		do { j --; } while (tab[j] > x);
		if (i > j) break;
		swap(tab[i], tab[j]);
	}
	swap(tab[j], tab[l]);
	return j;
}

int partitionMedium(int* tab, int l, int r)
{
    swap(tab[l+1], tab[(l+r)>>1]);
    if (tab[l+1] > tab[r]) swap(tab[l+1], tab[r]);
    if (tab[l] > tab[r]) swap(tab[l], tab[r]);
    if (tab[l] > tab[l+1]) swap(tab[l+1], tab[l]);
    int x = tab[l];
	int i = l, j = r + 1;
	while (true) {
		do { i++; } while (i <= r && tab[i] < x);
		do { j --; } while (tab[j] > x);
		if (i > j) break;
		swap(tab[i], tab[j]);
	}
	swap(tab[j], tab[l]);
	return j;
}

void quickSort(int* tab, int l, int r)
{
	if (l >= r) return;
	int p = partitionMedium(tab, l, r); // Hoare ’s , Lomuto, medium
	quickSort(tab, l, p - 1);
	quickSort(tab, p + 1, r);
}

void bubbleSort(int* tab, int l, int r)
{
	for (int i = l; i < r; i++)
	{
		for (int j = l; j < r-1; j++)
		{
			if (tab[j] > tab[j + 1])
				swap(tab[j], tab[j + 1]);

		}
	}
}

void quickSortHybrid(int* tab, int l, int r)
{
    if (r-l >= 10)
    {
        int p = partitionMedium(tab, l, r);
        quickSortHybrid(tab, l, p-1);
        quickSortHybrid(tab, p+1, r);
    }
    else bubbleSort(tab, l, r);
}

void showTable(int* tab, int size)
{
	for (int i = 0; i < size; i++) cout << tab[i] << endl;
}

int main()
{
	int tab[100];
	for (int i = 0; i < 100; i++)
	{
		tab[i] = rand() % 100;
	}
	int tab2[1000];
	for (int i = 0; i < 1000; i++)
	{
		tab2[i] = rand() % 100;
	}
	int tab3[10000];
	for (int i = 0; i < 10000; i++)
	{
		tab3[i] = rand() % 100;
	}
	//showTable(tab, 100);
	int* tab21 = tab2;
	int* tab22 = tab2;
	
	//Pierwsza wersja
	int start = clock();
    quickSortHybrid(tab2, 0, 999);
    int end = clock();
    cout << "Hybrid, it took " << end - start << "ticks, or " << ((float)end - start)/CLOCKS_PER_SEC << "seconds." << endl;
    
    //Druga wersja
    start = clock();
    quickSort(tab21, 0, 999);
    end = clock();
    cout << "Qucik, it took " << end - start << "ticks, or " << ((float)end - start)/CLOCKS_PER_SEC << "seconds." << endl;
    
    //Trzecia wersja
    start = clock();
    bubbleSort(tab22, 0, 999);
    end = clock();
    cout << "Bubble, it took " << end - start << "ticks, or " << ((float)end - start)/CLOCKS_PER_SEC << "seconds." << endl;

	return 0;
}

