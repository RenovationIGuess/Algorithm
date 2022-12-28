#include<iostream>

using namespace std;

struct node 
{
    int data;
    node *next;
};

node *createNode(int x)
{
    node *tmp = new node;
    //cấp phát động
    tmp->next = NULL;
    tmp->data = x;
    return tmp;
}

void printList(node *l)
{
    node *p = l;
    while(p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
}

node *addElement(node *p, int x)
{
    node *tmp = createNode(x);
    p->next = tmp;
    return tmp;
}

int main()
{
    int n, x;
    cin >> n;
    cin >> x;
    node *l = createNode(x);
    node *p = l;
    for(int i = 1; i < n; ++i)
    {
        cin >> x;
        p = addElement(p, x);
    }
    printList(l);
    return 0;
}