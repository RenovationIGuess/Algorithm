#include<stdio.h>
#include<stdlib.h>
#define MAX 1001

typedef int Eltype;
typedef struct StackType_t
{
    Eltype element;
    struct StackType_t *next;
} StackType;

int IsEmpty(StackType **top)
{
    return (*top) == NULL;
}

void Push(Eltype el, StackType **top)
{
    StackType *tmp = (StackType *)malloc(sizeof(StackType));
    if(tmp == NULL)
    {
        printf("\nNo memory available -> Error!\n");
        exit(0);
    }
    tmp->element = el;
    tmp->next = *top;
    *top = tmp;
}

Eltype pop(StackType **top)
{
    StackType *tmp;
    if(*top == NULL)
    {
        printf("\nThe stack is empty!\n");
        exit(0);
    }
    Eltype value;
    tmp = *top;
    value = tmp->element;
    *top = (*top)->next;
    free(tmp);
    return value;
}

Eltype Top(StackType **top)
{
    return (*top)->element;
}

void FreeStack(StackType **top)
{
    StackType *tmp;
    while(*top != NULL)
    {
        tmp = *top;
        *top = (*top)->next;
        free(tmp);
    }
}