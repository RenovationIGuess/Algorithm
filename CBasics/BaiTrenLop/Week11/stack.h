#include<stdio.h>
#include<stdlib.h>
#define MAX 256
typedef int Eltype;
typedef Eltype StackType[MAX];
int top;

void initialize(StackType stack)
{
    top = 0;
}

int IsEmpty(StackType stack)
{
    return top == 0;
}

int IsFull(StackType stack)
{
    return top == MAX;
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
        printf("\nStack underflow!\n");
    }
    else return stack[--top];
}

Eltype Peek(StackType stack)
{
    if(IsEmpty(stack))
    {
        printf("\nStack underflow!\n");
        return -107;
    }
    else return stack[top - 1];
}