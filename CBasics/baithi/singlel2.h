#include<stdio.h>
#include<stdlib.h>
#define MAX 256

struct Node
{
    et data;
    struct Node *next;
};

typedef struct Node node;

//l - tree/ list/ root, cur - con tr? hi?n t?i, prev - con tr? tru?c cur
//node *l, *cur, *prev, *search;
//FILE *f, *f1;

//tao node
node *createNode(et x)
{
    node *tmp = (node *)malloc(sizeof(node));
    tmp->next = NULL;
    tmp->data = x;
    return tmp;
}

//Insert dau
void InsertAtHead(et x, node *l, node *cur, node *prev)
{
    //node *tmp = createNode(x);
    node *tmp = (node *)malloc(sizeof(node));
    tmp->data = x;
    tmp->next = l;
    l = tmp;
    cur = l;
    prev = NULL;
}

//Insert sau cur
void InsertAfterCur(et x, node *l, node *cur, node *prev)
{
    node *tmp = createNode(x);
    if(cur == NULL) return;
    if(l == NULL)
    {
        l = tmp;
        cur = l;
        prev = NULL;
    }
    else
    {
        tmp->next = cur->next;
        cur->next = tmp;
        prev = cur;
        cur = cur->next;
    }
}

//Insert truoc cur
void InsertBeforeCur(et x, node *l, node *cur, node *prev)
{
    node *tmp = createNode(x);
    if(l == NULL)
    {
        l = tmp;
        cur = l;
        prev = NULL;
    }
    else
    {
        tmp->next = cur;
        prev->next = tmp;
        prev = tmp;
    }
}

void InsertTail(et x, node *l, node *cur, node *prev)
{
    node *tmp = createNode(x);
    if(l == NULL)
    {
        l = tmp;
        cur = l;
        prev = NULL;
    }
    else
    {
        while(cur->next != NULL)
        {
            cur = cur->next;
        }
        cur->next = tmp;
        prev = cur;
        cur = tmp;
    }
}

//cap nhat con tro prev neu cur != l
void update(node *l, node *cur, node *prev)
{
    node *tmp = l;
    while(tmp != NULL && cur != NULL && tmp->next != cur)
    {
        tmp = tmp->next;
    }
    prev = tmp;
}

//delete head
void deleteHead(node *l, node *cur, node *prev)
{
    node *del = l;
    if(del == NULL) return;
    l = del->next;
    free(del);
    cur = l;
    prev = NULL;
}

//delete current
void deleteMiddle(node *l, node *cur, node *prev)
{
    node *del = l;
    if(del == NULL) return;
    if(cur != l)
    {
        update(l, cur, prev);
    }
    prev->next = cur->next;
    cur = NULL;
    free(cur);
    cur = prev->next;
}

//xoa duoi
void deleteTail(node *l, node *cur, node *prev)
{
    node *del = l;
    if(del == NULL && del->next == NULL) return;
    while(del->next->next != NULL)
    {
        del = del->next;
    }
    del->next = NULL;
    free(del->next);
    cur = del;
    update(l, cur, prev);
}

//dao list
void reverseList(node *l, node *cur, node *prev)
{
    node *p = l;
    node *tsugi, *pre;
    tsugi = pre = NULL;
    while(p != NULL)
    {
        tsugi = p->next;
        p->next = pre;
        pre = p;
        p = tsugi;
    }
    l = pre;
    cur = l;
    prev = NULL;
}

//Input
/*void ReadNode(et *a)
{
    
} */

//Output
void displayNode(node *x)
{
    if(x == NULL)
    {
        printf("\nCon tro loi - NULL!\n");
        return;
    }
    et tmp = x->data;
    //printf("%-10d%-10s%-10d\n", tmp.id, tmp.cpu, tmp.ram);
} 

void FreeList(node *l)
{
    node *p = l;
    while(p != NULL)
    {
        l = l->next;
        free(p);
        p = l;
    }
}

void printList(node *l)
{
    node *p = l;
    //int i = 1;
    if(p == NULL) 
    {
        printf("\nCon tro NULL!\n");
        return;
    }
    while(p != NULL)
    {
        displayNode(p);
        p = p->next;
    }
    //printf("\n");
}

//Phan bai tap tuan 8
node *insertAtPosition(node *t, node *cur, node *prev, et ad, int n)
{
    node *tmp = createNode(ad);
    if(t == NULL)
    {
        t = tmp;
        cur = t;
        prev = NULL;
    }
    else
    {
        node *root = t;
        int i;
        for(i = 0; i < n - 1; ++i)
        {
            root = root->next;
        }
        cur = root;
        //cap nhat con tro prev
        update(t, cur, prev);
        tmp->next = cur->next;
        cur->next = tmp;
        prev = cur;
        cur = tmp;
        return t;
    }
}

node *deleteAtPosition(node *t, node *cur, node *prev, int n)
{
    if(t == NULL) return NULL;
    else
    {
        node *root = t;
        int i;
        for(i = 0; i < n - 1; ++i)
        {
            root = root->next;
        }    
        node *tmp = root->next;
        root->next = tmp->next;
        free(tmp);
        cur = root;
        update(t, cur, prev);   
        return t;    
    }
}

node *split(node *t, node *l, node *cur, node *prev, int n1, int n2)
{
    node *res = NULL;
    if(t == NULL) return NULL;
    else
    {
        node *tmp = t;
        int i;
        if(n1 > 0)
        {
            for(i = 0; i < n1; ++i)
                tmp = tmp->next;
            cur = tmp;
            if(cur != t)
                update(t, cur, prev);
            //danh dau vi tri ket thuc
            node *mark = cur;
            for(i = 0; i < n2 - 1; ++i)
                mark = mark->next;
            //neu n1 + 1 + n2 = n
            if(mark->next == NULL) 
            {
                res = cur;
                prev->next = NULL;
                return res;
            }
            else
            {
                res = cur;
                prev->next = mark->next;
                mark->next = NULL;
                return res;
            }
        }
        else
        {
            res = t;
            node *mark = res;
            for(i = 0; i < n2 - 1; ++i)
                mark = mark->next;
            l = mark->next;
            cur = l; prev = NULL;
            mark->next = NULL;
            return res;
        }
    }
} 