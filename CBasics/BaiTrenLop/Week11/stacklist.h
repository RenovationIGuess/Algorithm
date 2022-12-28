#include<stdio.h>
#include<stdlib.h>
#define MAX 101

typedef struct Node
{
    int element;
    struct Node *next;
} node;

int IsEmpty(node *p)
{
    return p == NULL;
}

int IsFull(node *p)
{
    node *tmp = p;
    int i = 0;
    while(tmp != NULL)
    {
        i++;
        tmp = tmp->next;
    }
    return i == MAX;
}

node *push(node *p, int value)
{
    node *tmp = (node *)malloc(sizeof(node));
    if(tmp == NULL)
    {
        printf("\nNo memory available -> Error!\n");
        exit(0);
    }
    tmp->element = value;
    tmp->next = p;
    p = tmp;
    return p;
}

node *pop(node *p, int *value)
{
    node *tmp;
    if(p == NULL)
    {
        printf("\nThe stack is empty!\n");
        exit(0);
    }
    *value = p->element;
    tmp = p;
    p = p->next;
    free(tmp);
    return p;
}

int top(node *p)
{
    /*node *tmp = p;
    while(tmp != NULL)
    {
        tmp = tmp->next;
    }
    return tmp->element;*/
    return p->element;
}

void FreeStack(node *p)
{
    node *tmp;
    while(p != NULL)
    {
        tmp = p;
        p = p->next;
        free(tmp);
    }
}

