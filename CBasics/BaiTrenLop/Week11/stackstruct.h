#include<stdio.h>
#include<stdlib.h>
#define MAX 256

typedef int Eltype;
struct StackRec
{
    Eltype storage[MAX];
    int top;
};
typedef struct StackRec StackType;

void initialize(StackType *stack)
{
    (*stack).top = 0;
}

int IsEmpty(StackType stack)
{
    return stack.top == 0;
}

int IsFull(StackType stack)
{
    return stack.top == MAX;
}

void push(Eltype el, StackType *stack)
{
    if(IsFull(*stack))
    {
        printf("\nStack Overflow!\n");
    }
    else (*stack).storage[(*stack).top++] = el;
}

Eltype pop(StackType *stack)
{
    if(IsEmpty(*stack))
    {
        printf("\nStack Underflow!\n");
    }
    else return (*stack).storage[--(*stack).top];
}

Eltype peek(StackType stack)
{
    if (IsEmpty(stack)) 
    {
        printf("\nStack is empty! Can't get top!\n");
        return -107; 
    }
    else return stack.storage[stack.top - 1];
}                                                
