//#include "stack.h"
//#include "stacklist.h"
//#include "stackstruct.h"
#include "StackList2.h"

int main()
{
    int val;
    int n;
    StackType *a = NULL;
    //initialize(&a);
    //node *a = NULL;
    printf("\nStack A:\n");
    printf("\nEnter number of elements: ");
    fflush(stdin); scanf("%d", &n);
    int i;
    for(i = 0; i < n; ++i)
    {
        printf("\nEnter elements value: ");
        fflush(stdin); scanf("%d", &val);
        //push(val, a);
        //a = push(a, val);
        //Push(val, &a);
    }
    //printf("\nStacks peek = %d\n", Peek(a));
    //printf("\nStacks peek = %d\n", top(a));
    //printf("\nStacks peek = %d\n", peek(a));
    printf("\nPop all elements:\n");
    while(!IsEmpty(&a))
    {
        //a = pop(a, &val);
        //printf("%d ", val);
        printf("%d ", pop(&a));
    }
    FreeStack(&a);

    StackType *b = NULL;
    //initialize(&b);
    //node *b = NULL;
    printf("\n\nStack B:\n");
    printf("\nEnter number of elements: ");
    fflush(stdin); scanf("%d", &n);
    for(i = 0; i < n; ++i)
    {
        printf("\nEnter elements value: ");
        fflush(stdin); scanf("%d", &val);
        //push(val, b);
        //b = push(b, val);
        //Push(val, &b);
    }
    //printf("\nStacks peek = %d\n", peek(b));
    //printf("\nStacks peek = %d\n", top(b));
    printf("\nPop all elements:\n");
    while(!IsEmpty(&b))
    {
        printf("%d ", pop(&b));
        //b = pop(b, &val);
        //printf("%d ", val);
    }
    FreeStack(&b);
    return 0;
}