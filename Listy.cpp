#include<iostream>

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

void DeleteSelectNode(node*& H, int x)
{
    if (H != NULL)
    {
        if (H->val == x) Delete(H);
        else 
        {
            node* p = H;
            while (p->next != NULL && p->next->val != x) p = p->next;
            if (p->next != NULL) Delete(p->next);
        }
    }
};

void DeleteNodeBeforeSelectedVal(node*& H, int x)
{
    if (H != NULL)
    {

        node* p = H;
        if (p->next != NULL && p->next->val == x) delete(p);
        else 
        {
            while (p->next->next != NULL && p->next->next->val != x) p = p->next;
            if (p->next->next != NULL) Delete(p->next);
        }
    }
};

void DuplicateAllNodes(node*& H)
{
    if (H != NULL)
    {
        node* p = H;
        while (p != NULL)
        {
            Add(p->next, p->val);
            p = p->next->next;
        }
    }
};

void DuplicateNodesByVal(node*& H)
{
    if (H != NULL)
    {
        node* p = H;
        node* r = H;

        while (p != NULL)
        {
            int nodeVal = p->val;
            r = p->next;
            for (int i = 1; i < nodeVal; i++) Add(p->next, nodeVal);
            p = r;
        }
    }
};

void DuplicateReverseList(node*& H)
{
    if (H != NULL)
    {
        node* p = H;
        node* n = NULL;
        while (p != NULL)
        {
            Add(n, p->val);
            p = p->next;
        }
        p = H;
        while (p->next != NULL) p = p->next;
        p->next = n;
    }
};

void DuplicateList(node*& H)
{
    if (H != NULL)
    {
        node* p = H;
        node* n = NULL;
        node* p2 = NULL;
        while (p != NULL)
        {
            Add(n, p->val);
            p = p->next;
        }

        //odwraca tablice
        //p -> next
        //n -> current
        //p2 -> previous
        while (n != NULL)
        {
            p = n->next;
            n->next = p2;
            p2 = n;
            n = p;
        }
        n = p2;

        p = H;
        while (p->next != NULL) p = p->next;
        p->next = n;
    }
};

void SwapFirstWithSecond(node*& H)
{
    if (H->next != NULL) 
    {
        node* p = H;
        H = p->next;
        p->next = H->next;
        H->next = p;
    }
};

void SwapFirstWithLast(node*& H)
{
    if (H->next != NULL) 
    {
        if (H->next->next == NULL) 
        {
            SwapFirstWithSecond(H);
        }
        else 
        {
            node* p = H;
            node* p2 = H;
            while (p->next->next != NULL) p = p->next;
            H = p->next;
            H->next = p2->next;
            p->next = p2;
            p2->next = NULL;
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
    node* T = NULL;
    Add(T, 10);
    Add(T, 8);
    Add(T, 3);
    Add(T, 4);
    Show(T);
    DeleteSelectNode(T, 3);
    Show(T);
    /*
    node* H = NULL;
    node* p = new node;
    Add(H, 5);
    Add(H, 10);
    Add(H, 0);
    Show(H);
    Add(H->next, 12);
    Show(H);
    Delete(H);
    Show(H);
    Delete(H->next);
    Show(H);
    Add(H, 3);
    Add(H, 4);
    Show(H);
    DeleteSelectNode(H, 3);
    Show(H);
    Add(H, 4);
    Add(H, 3);
    Add(H, 2);
    Add(H, 1);
    Show(H);
    DuplicateAllNodes(H);
    Show(H);
    */

    //Zadanie 1
    node* H = NULL;
    Add(H, 5);
    Add(H, 2);
    Add(H, 1);
    DuplicateNodesByVal(H);
    Show(H);

    //Zadanie 2
    node* H2 = NULL;
    Add(H2, 7);
    Add(H2, 6);
    Add(H2, 5);
    Add(H2, 2);
    Add(H2, 1);
    Add(H2, 4);
    DeleteNodeBeforeSelectedVal(H2, 2);
    DeleteNodeBeforeSelectedVal(H2, 7);
    Show(H2);

    //Zadanie 3
    node* H3 = NULL;
    Add(H3, 4);
    Add(H3, 3);
    Add(H3, 2);
    Add(H3, 1);
    DuplicateReverseList(H3);
    Show(H3);

    //Zadanie 4
    node* H4 = NULL;
    Add(H4, 4);
    Add(H4, 3);
    Add(H4, 2);
    Add(H4, 1);
    DuplicateList(H4);
    Show(H4);

    //Zadanie 5
    node* H5 = NULL;
    Add(H5, 4);
    Add(H5, 3);
    Add(H5, 2);
    Add(H5, 1);
    SwapFirstWithSecond(H5);
    Show(H5);

    //Zadanie 6
    node* H6 = NULL;
    Add(H6, 4);
    Add(H6, 3);
    Add(H6, 2);
    Add(H6, 1);
    SwapFirstWithLast(H6);
    Show(H6);

    return 0;
};
