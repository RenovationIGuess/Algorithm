#include<stdio.h>
#define MAX 50
typedef int Eltype;
typedef Eltype StackType[MAX];
int top;

void initialize(StackType stack)
{
    top = 0;
}

int IsEmpty(StackType stack)
{
    if(top == 0) return 1;
    else return 0;
}

int IsFull(StackType stack)
{
    if(top == MAX) return 1;
    else return 0;
}

void push(Eltype el, StackType stack)
{
    if(IsFull(stack))
    {
        printf("\nStack overflow!\n");
    }
    else stack[top++] = el;
}

Eltype pop(StackType stack)
{
    if(IsEmpty(stack))
    {
        printf("\nStack overflow!\n");
    }
    else return stack[--top];
}

Eltype peek(StackType stack)
{
    if(IsEmpty(stack))
    {
        printf("\nStack overflow!\n");
        return (-171);
    }
    else return stack[top - 1];
}