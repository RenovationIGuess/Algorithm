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
    tmp->next = NULL;
    tmp->data = x;
    return tmp;
}

void printList(node*l)
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

node *addHead(node *l, int x)
{
    node *tmp = new node;
    tmp->data = x;
    tmp->next = l;
    l = tmp;
    return l;
}

node *addAt(node *l, int k, int x)
{
    node *p = l;
    for(int i = 0; i < k - 1; ++i)
    {
        p = p->next;
    }
    node *tmp = new node;
    tmp->data = x;
    tmp->next = p->next;
    p->next = tmp;

    return l;
}

node *addEnd(node *l, int x)
{
    node *p = l;
    while(p->next != NULL)
    {
        p = p->next;
    }

    node *tmp = new node;
    tmp->data = x;
    tmp->next = NULL;
    p->next = tmp;
    return l;
}

int main()
{
    int n, x, k;
    cin >> n >> x;
    node *l = createNode(x);
    node *p = l;
    for(int i = 1; i < n; ++i)
    {
        cin >> x;
        p = addElement(p, x);
    }

    cin >> k >> x;
    if(k == 0) l = addHead(l, x);
    else if(k == n) l = addEnd(l, x);
    else l = addAt(l, k, x);

    printList(l);
    return 0;
}