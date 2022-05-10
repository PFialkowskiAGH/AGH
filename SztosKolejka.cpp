// SztosKolejka.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>

using namespace std;

struct node
{
    int val;
    node* next;
};

//stos/stack
void push(node*& S, int val)
{
    node* p = new node;
    p->val = val;
    p->next = S;
    S = p;
}

void pop(node*& S)
{
    node* p = S;
    S = p->next;
    delete p;
}

bool isEmpty(node*& S)
{
    if (S == NULL) return true;
    else return false;
}

int top(node*& S)
{
    if (S != NULL) return S->val;
    else return NULL;
}

//Kolejka/Queue
void engueue(node*& QT, node*& QH, int val)
{
    node* p = new node;
    p->val = val;
    p->next = NULL;
    if (QH == NULL)
    {
        QH = QT = p;
    }
    else
    {
        QT->next = p;
        QT = p;
    }
}

void dequeue(node*& QH, node*& QT)
{
    if (QH != NULL)
    {
        node* p = QH;
        QH = p->next;
        if (QH == NULL) QT = QH;
        delete p;
    }
}

bool isEmptyQueue(node*& QH)
{
    if (QH == NULL) return true;
    else return false;
}

int front(node*& QH)
{
    if (QH != NULL) return QH->val;
    else return NULL;
}

int tail(node*& QT)
{
    if (QT != NULL) return QT->val;
    else return NULL;
}

int main()
{
    //Stos/Stack
    cout << "----Stos----" << endl;
    node* S = NULL;
    cout << "Pusty: " << boolalpha << isEmpty(S) << endl;
    int check = top(S);
    if(check == NULL) cout << "Wartosc wierzcholka: Stos jest pusty" << endl;
    else cout << "Wartosc wierzcholka: " << check << endl;
    push(S, 4);
    push(S, 2);
    push(S, 12);
    pop(S);
    cout << "Pusty: " << boolalpha << isEmpty(S) << endl;
    check = front(S);
    if (check == NULL) cout << "Wartosc wierzcholka: Stos jest pusty" << endl;
    else cout << "Wartosc wierzcholka: " << check << endl;

    //Kolejka/Queue
    cout << endl;
    cout << "----Kolejka----" << endl;
    node* QH = NULL;
    node* QT = QH;
    cout << "Pusty: " << boolalpha << isEmptyQueue(QH) << endl;
    check = front(QH);
    if (check == NULL) cout << "Wartosc przodu: Kolejka jest pusta" << endl;
    else cout << "Wartosc przodu: " << check << endl;
    check = tail(QT);
    if (check == NULL) cout << "Wartosc tylu: Kolejka jest pusta" << endl;
    else cout << "Wartosc tyłu: " << check << endl;
    engueue(QT, QH, 1);
    engueue(QT, QH, 2);
    engueue(QT, QH, 3);
    engueue(QT, QH, 4);
    dequeue(QH, QT);
    cout << "Pusty: " << boolalpha << isEmptyQueue(QH) << endl;
    check = front(QH);
    if (check == NULL) cout << "Wartosc przodu: Kolejka jest pusta" << endl;
    else cout << "Wartosc przodu: " << check << endl;
    check = tail(QT);
    if (check == NULL) cout << "Wartosc tylu: Kolejka jest pusta" << endl;
    else cout << "Wartosc tylu: " << check << endl;
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
