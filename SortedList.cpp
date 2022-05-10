// SortedList.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>

using namespace std;

struct node
{
    int val;
    node* next;
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

void swapFirstWithSecond(node*& H)
{
    if (H->next != NULL)
    {
        node* p = H;
        H = p->next;
        p->next = H->next;
        H->next = p;
    }
};

void insertSortedList(node*& H, int x)
{
    if (H == NULL) Add(H, x);
    else 
    {
        if (H->val > x) Add(H, x);
        else
        {
            node* p = H;
            while (p->next != NULL && p->next->val < x) p = p->next;
            Add(p->next, x);
        }
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

void bubbleSort(node*& H)
{
    if (H != NULL) {
        node* p = NULL;
        bool isSorted = false;
        while (isSorted == false)
        {
            isSorted = true;
            p = H;
            while (p->next != NULL)
            {
                if (p->val > p->next->val)
                {
                    swapFirstWithSecond(p);
                    isSorted = false;
                }
                p = p->next;
            }
        }
    }
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

int main()
{
    //SortedAdd
    node* H = NULL;
    insertSortedList(H, 2);
    insertSortedList(H, 5);
    insertSortedList(H, 3);
    insertSortedList(H, 1);
    Show(H);

    //Split
    node* H1 = NULL;
    node* H2 = NULL;
    splitListInHalf(H, H1, H2);
    Show(H1);
    Show(H2);
    Show(H);

    //Merge
    node* H3 = NULL;
    node* H4 = NULL;
    insertSortedList(H3, -6);
    insertSortedList(H3, 3);
    insertSortedList(H3, 7);
    insertSortedList(H3, 16);
    insertSortedList(H4, 3);
    insertSortedList(H4, 18);
    insertSortedList(H4, 22);
    Show(H3);
    Show(H4);
    mergeTwoList(H, H3, H4);
    Show(H);
    Show(H3);
    Show(H4);

    //Sort
    cout << "Sortowanie: " << endl;
    node* H5 = NULL;
    Add(H5, 5);
    Add(H5, 12);
    Add(H5, -7);
    Add(H5, 6);
    Add(H5, 3);
    Add(H5, 8);
    Show(H5);
    bubbleSort(H5);
    Show(H5);
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
