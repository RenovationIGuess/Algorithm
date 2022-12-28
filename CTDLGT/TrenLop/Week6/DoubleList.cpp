#include<iostream>
#include<time.h>

using namespace std;

struct node
{
    int data;
    node *next;
    node *pre;
};

struct dList
{
    node *head;
    node *tail;
};

int random(int minN, int maxN)
{
    return minN + rand() % (maxN + 1 - minN);
}

//khoi tao
dList *createList(int x)
{
    dList *l = new dList;
    l->head = new node;
    l->head->data = x;
    l->head->pre = NULL;
    l->head->next = NULL;
    l->tail = l->head;
    return l;
}

//push_front()
dList *addHead(dList *l, int x)
{
    node *tmp = new node;
    tmp->data = x;
    tmp->pre = NULL;
    tmp->next = l->head;
    l->head->pre = tmp;
    l->head = tmp;
    return l;
}

//push_back()
dList *addTail(dList *l, int x)
{
    node *tmp = new node;
    tmp->data = x;
    tmp->next = NULL;
    tmp->pre = l->tail;
    l->tail->next = tmp;
    l->tail = tmp;
    return l;
}


//push
dList *addAt(dList *l, int k, int x)
{
    node *p = l->head;
    for(int i = 0; i < k - 1; ++i)
    {
        p = p->next;
    }
    node *tmp = new node;
    tmp->data = x;
    tmp->pre = p;
    tmp->next = p->next;
    p->next->pre = tmp;
    p->next = tmp;
    return l;
}

//pop_front()
dList *eraseHead(dList *l)
{
    node *p = l->head->next;
    node *tmp = l->head;
    p->pre = NULL;
    l->head = p;
    return l;
}

//pop_back()
dList *eraseTail(dList *l)
{
    node *p = l->tail->pre;
    node *tmp = l->tail;
    p->next = NULL;
    l->tail = p;
    return l;
}

//erase()
dList *eraseAt(dList *l, int k)
{
    node *p = l->head;
    for(int i = 0; i < k - 1; ++i)
    {
        p = p->next;
    }
    node *tmp = p->next;
    node *p1 = tmp->next;
    p->next = p1;
    p1->pre = p;
    return l;
}

int size(dList *l)
{
    int cnt = 0;
    node *p = l->head;
    while(p != NULL)
    {
        cnt++;
        p = p->next;
    }
    return cnt;
}

bool isempty(dList *l)
{
    if(l->head == NULL && l->tail == NULL)
    {
        return true;
    } else return false;
}

void clear(dList *l)
{
    while(!isempty(l))
    {
        //eraseHead...
        eraseTail(l);
    }
}

//Output
void printList(dList *l)
{
    node *p = l->head;
    while(p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    } cout << endl;
}

int main()
{
    srand((int)time(0));
    int n, x, k;
    n = random(1, 100);
    x = random(1, 100);
    dList *l = createList(x);
    for(int i = 1; i < n; ++i)
    {
        x = random(1, 100);
        l = addTail(l, x);
    }
    k = random(0, n - 1);

    //Xoa phan tu - pop
    if(k == 0)
    {
		l = eraseHead(l);
	} else if(k == n-1)
    {
		l = eraseTail(l);
	} else 
    {
		l = eraseAt(l, k);
	}
    n--;
    printList(l);

    //them phan tu - push
    k = random(0, n - 1);
    if (k == 0)
    {
		l = addHead(l, x);
	} else if (k == n)
    {
		l = addTail(l, x);
	} else
    {
		l = addAt(l, k, x);
	}
    n++;
    printList(l);

    cout << "So phan tu - size: " << size(l) << endl;
    
    //Xoa het
    //clear(l);
    return 0;
}