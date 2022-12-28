#include "StackList2.h"
#include<string.h>
#include<ctype.h>

// a + b
void Tong(char *s1, char *s2, StackType **a, StackType **b, int check)
{
    StackType *res = NULL;
    int re = 0; //bien nho
    if(strlen(s1) == strlen(s2))
    {
        int total = 0;
        while(!IsEmpty(a))
        {
            total = pop(a) + pop(b) + re;
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
        while(!IsEmpty(b))
        {
            total = pop(a) + pop(b) + re;
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
        while(!IsEmpty(a))
        {
            total = pop(a) + re;
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
        while(!IsEmpty(a))
        {
            total = pop(a) + pop(b) + re;
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
        while(!IsEmpty(b))
        {
            total = pop(b) + re;
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
    if(check == 1) printf("-");
    while(!IsEmpty(&res))
    {
        printf("%d", pop(&res));
    } printf("\n");
}

// a tru b
void Hieu(char *s1, char *s2, StackType **a, StackType **b)
{
    int i, check = 0;
    // check = 0 - <=, check = 1 - >
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
            while(!IsEmpty(a))
            {
                num1 = pop(a);
                num2 = pop(b) + re;
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
            while(!IsEmpty(a))
            {
                num1 = pop(b);
                num2 = pop(a) + re;
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
        while(!IsEmpty(b))
        {
            num1 = pop(a);
            num2 = pop(b) + re;
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
        if(re != 0) Push(pop(a) - re, &res);
        while(!IsEmpty(a))
        {
            Push(pop(a), &res);
        }
    }
    else if(strlen(s1) < strlen(s2))
    {
        minus = 1;
        while(!IsEmpty(a))
        {
            num1 = pop(b);
            num2 = pop(a) + re;
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
        if(re != 0) Push(pop(b) - re, &res);
        while(!IsEmpty(b))
        {
            Push(pop(b), &res);
        }
    }
    printf("\nSubtract result: ");
    if(minus != 0) printf("-");
    while(Top(&res) == 0) pop(&res);
    while(!IsEmpty(&res))
    {
        printf("%d", pop(&res));
    } printf("\n");
}

int main()
{
    printf("\nMenu:\n");
    int opt; char c;
    do
    {
        int i, val;
        int mark1 = 0, mark2 = 0;
        // 0 - (+), 1 - (-)
        char *s1 = (char *)malloc(MAX * sizeof(char));
        char *s2 = (char *) malloc(MAX * sizeof(char));

        StackType *a = NULL; 
        printf("\nEnter number 1: ");
        fflush(stdin); gets(s1);
        for(i = 0; i < strlen(s1); ++i)
        {
            if(s1[i] == '-')
            {
                mark1 = 1;
                continue;
            }
            val = s1[i] - '0';
            Push(val, &a);
        }

        StackType *b = NULL;
        printf("\nEnter number 2: ");
        fflush(stdin); gets(s2);
        for(i = 0; i < strlen(s2); ++i)
        {
            if(s2[i] == '-')
            {
                mark2 = 1;
                continue;
            }
            val = s2[i] - '0';
            Push(val, &b);
        }
        
        do
        {
            printf("\n1. Add\n2. Subtract\n3. Exit\n");
            printf("\nEnter your option: ");
            fflush(stdin); scanf("%d", &opt);
            switch(opt)
            {
                case 1:
                    if(mark1 == 1 && mark2 == 1) Tong(s1, s2, &a, &b, 1);
                    else if(mark1 == 0 && mark2 == 0) Tong(s1, s2, &a, &b, 0);
                    else if(mark1 == 1 && mark2 == 0) Hieu(s1, s2, &b, &a);
                    else if(mark1 == 0 && mark2 == 1) Hieu(s1, s2, &a, &b);
                    break;
                case 2:
                    if(mark1 == 1 && mark2 == 1) Hieu(s1, s2, &b, &a);
                    else if(mark1 == 0 && mark2 == 0) Hieu(s1, s2, &a, &b);
                    else if(mark1 == 1 && mark2 == 0) Tong(s1, s2, &a, &b, 1);
                    else if(mark1 == 0 && mark2 == 1) Tong(s1, s2, &a, &b, 0);
                    break;
                case 3:
                    printf("\nThank you!\n");
                    break;
                default:
                    printf("\nInvalid!\n");
                    break;
            }
            //reset stack
            for(i = 0; i < strlen(s1); ++i)
            {
                if(s1[i] == '-')
                {
                    mark1 = 1;
                    continue;
                }
                val = s1[i] - '0';
                Push(val, &a);
            }
            for(i = 0; i < strlen(s2); ++i)
            {
                if(s2[i] == '-')
                {
                    mark2 = 1;
                    continue;
                }
                val = s2[i] - '0';
                Push(val, &b);
            }
        } while (opt != 3);
        
        FreeStack(&a);
        FreeStack(&b);
        //FreeStack(&res);
        free(s1);
        free(s2);

        printf("\nDo you want to continue [y/n]: ");
        fflush(stdin); scanf("%c", &c);
        while(c != 'y' && c != 'n')
        {
            printf("\nInvalid! Enter again: ");
            fflush(stdin); scanf("%c", &c);
        }
    } while (c == 'y');
    return 0;
}