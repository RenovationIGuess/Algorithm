#include "StackList2.h"
#include<string.h>
#include<ctype.h>

int main()
{
    int i, val, check = 0;
    // check = 0 - <=, check = 1 - >
    char *s1 = (char *)malloc(MAX * sizeof(char));
    char *s2 = (char *) malloc(MAX * sizeof(char));
    StackType *a = NULL; 
    printf("\nEnter number 1: ");
    fflush(stdin); gets(s1);
    //printf("\nNumber 1: %s\n", s1);
    for(i = 0; i < strlen(s1); ++i)
    {
        val = s1[i] - '0';
        Push(val, &a);
    }

    StackType *b = NULL;
    printf("\nEnter number 2: ");
    fflush(stdin); gets(s2);
    //printf("\nNumber 2: %s\n", s2);
    for(i = 0; i < strlen(s2); ++i)
    {
        val = s2[i] - '0';
        Push(val, &b);
    }

    StackType *res = NULL;
    int re = 0, num1 = 0, num2 = 0, minus;

    if(strlen(s1) == strlen(s2))
    {
        for(i = 0; i < strlen(s1); ++i)
        {
            if((s1[i] - '0') < (s2[i] - '0'))
            {
                //printf("%d %d\n", s1[i] - '0', s2[i] - '0');
                check = 0;
                break;
            }
        }
        //printf("%d\n", check);
        if(check == 1)
        {
            minus = 0;
            while(!IsEmpty(&a))
            {
                num1 = pop(&a);
                num2 = pop(&b) + re;
                if(num1 < num2)
                {
                    Push((10 + num1) - num2, &res);
                    re = 1;
                }
                else
                {
                    Push(num1 - num2, &res);
                    re = 0;
                }
            }
        }
        else
        {
            minus = 1;
            while(!IsEmpty(&a))
            {
                num1 = pop(&b);
                num2 = pop(&a) + re;
                if(num1 < num2)
                {
                    Push((10 + num1) - num2, &res);
                    re = 1;
                }
                else
                {
                    Push(num1 - num2, &res);
                    re = 0;
                }
            }
        }
    }
    else if(strlen(s1) > strlen(s2))
    {
        minus = 0;
        while(!IsEmpty(&b))
        {
            num1 = pop(&a);
            num2 = pop(&b) + re;
            if(num1 < num2)
            {
                Push(10 + num1 - num2, &res);
                re = 1;
            }
            else
            {
                Push(num1 - num2, &res);
                re = 0;
            }
        }
        if(re != 0) Push(pop(&a) - re, &res);
        while(!IsEmpty(&a))
        {
            Push(pop(&a), &res);
        }
    }
    else if(strlen(s1) < strlen(s2))
    {
        minus = 1;
        while(!IsEmpty(&a))
        {
            num1 = pop(&b);
            num2 = pop(&a) + re;
            if(num1 < num2)
            {
                Push(10 + num1 - num2, &res);
                re = 1;
            }
            else
            {
                Push(num1 - num2, &res);
                re = 0;
            }
        }
        if(re != 0) Push(pop(&b) - re, &res);
        while(!IsEmpty(&b))
        {
            Push(pop(&b), &res);
        }
    }
    printf("\nSubtract result: ");
    if(minus != 0) printf("-");
    while(Top(&res) == 0) pop(&res);
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
