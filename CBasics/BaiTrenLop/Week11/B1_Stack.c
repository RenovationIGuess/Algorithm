#include "stack.h"
#include<string.h>
#include<ctype.h>

int main()
{
    int i, val;
    char *s1 = (char *)malloc(sizeof(char));
    char *s2 = (char *) malloc(sizeof(char));
    StackType a; 
    initialize(a);
    printf("\nEnter number 1: ");
    fflush(stdin); gets(s1);
    //printf("\nNum 1: %s\n", s1);
    for(i = 0; i < strlen(s1); ++i)
    {
        val = s1[i] - '0';
        push(val, a);
        //printf("%d", s1[i] - '0');
    }

    StackType b;
    initialize(b);
    printf("\nEnter number 2: ");
    fflush(stdin); gets(s2);
    //printf("\nNum 2: %s\n", s2);
    for(i = 0; i < strlen(s2); ++i)
    {
        val = s2[i] - '0';
        push(val, b);
        //printf("%d", s2[i] - '0');
    }
    
    StackType res;
    initialize(res);
    while(!IsEmpty(b))
    {
        printf("%d", pop(b));
    }
    int re = 0; //bien nho
    if(strlen(s1) == strlen(s2))
    {
        int total = 0;
        
        /*while(!IsEmpty(a))
        {
            //int num1 = pop(a);
            //int num2 = pop(b);
            
            total = pop(a) + pop(b) + re;
            if(total >= 10)
            {
                re = 1;
                push(total - 10, res);
            }
            else 
            {
                push(total, res);
                re = 0;
            }
        }*/
        //if(re != 0) push(re, res);
    }
    else if(strlen(s1) > strlen(s2))
    {
        
    }
    else if(strlen(s1) < strlen(s2))
    {

    }
    printf("\nSum of num 1 and 2:\n");
    while(!IsEmpty(res))
    {
        printf("%d", pop(res));
    }
    free(s1);
    free(s2);
    return 0;
}