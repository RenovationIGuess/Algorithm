//#include<stdio.h>
//#include<stdlib.h>
//#include "DoubleL.h"
#include "stackarr.h"

int main()
{
    int a[6] = {1, 3, 5, 9, 4, 2}; int i;
    StackType s;
    initialize(s);
    for(i = 0; i < 6; ++i) push(a[i], s);
    printf("\nPop all element in stack:\n");
    while(!IsEmpty(s))
    {
        printf("%d\n", pop(s));
    }
    return 0;
}