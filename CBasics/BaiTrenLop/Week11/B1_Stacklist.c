#include "StackList2.h"
#include<string.h>
#include<ctype.h>

int main()
{
    int i, val;
    char *s1 = (char *)malloc(MAX * sizeof(char));
    char *s2 = (char *) malloc(MAX * sizeof(char));
    StackType *a = NULL; 
    printf("\nEnter number 1: ");
    fflush(stdin); gets(s1);
    for(i = 0; i < strlen(s1); ++i)
    {
        val = s1[i] - '0';
        Push(val, &a);
    }

    StackType *b = NULL;
    printf("\nEnter number 2: ");
    fflush(stdin); gets(s2);
    for(i = 0; i < strlen(s2); ++i)
    {
        val = s2[i] - '0';
        Push(val, &b);
    }
    
    StackType *res = NULL;
    int re = 0; //bien nho
    if(strlen(s1) == strlen(s2))
    {
        int total = 0;
        while(!IsEmpty(&a))
        {
            total = pop(&a) + pop(&b) + re;
            if(total >= 10)
            {
                re = 1;
                Push(total - 10, &res);
            }
            else 
            {
                Push(total, &res);
                re = 0;
            }
        }
        if(re != 0) Push(re, &res);
    }
    else if(strlen(s1) > strlen(s2))
    {
        int total = 0;
        while(!IsEmpty(&b))
        {
            total = pop(&a) + pop(&b) + re;
            if(total >= 10)
            {
                re = 1;
                Push(total - 10, &res);
            }
            else 
            {
                Push(total, &res);
                re = 0;
            }
        }
        while(!IsEmpty(&a))
        {
            total = pop(&a) + re;
            if(total >= 10)
            {
                re = 1;
                Push(total - 10, &res);
            }
            else 
            {
                Push(total, &res);
                re = 0;
            }
        }
    }
    else if(strlen(s1) < strlen(s2))
    {
        int total = 0;
        while(!IsEmpty(&a))
        {
            total = pop(&a) + pop(&b) + re;
            if(total >= 10)
            {
                re = 1;
                Push(total - 10, &res);
            }
            else 
            {
                Push(total, &res);
                re = 0;
            }
        }
        while(!IsEmpty(&b))
        {
            total = pop(&b) + re;
            if(total >= 10)
            {
                re = 1;
                Push(total - 10, &res);
            }
            else 
            {
                Push(total, &res);
                re = 0;
            }
        }
    }
    printf("\nSum of num 1 and 2: ");
    while(!IsEmpty(&res))
    {
        printf("%d", pop(&res));
    }
    FreeStack(&a);
    FreeStack(&b);
    FreeStack(&res);
    free(s1);
    free(s2);
    return 0;
}