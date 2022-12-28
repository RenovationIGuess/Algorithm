#include<string.h>
#include "StackList2.h"
#include<ctype.h>

int Precedence(char x)
{
    if(x == '^') return 4;
    if(x == '*' || x == '/' || x == '%') return 3;
    if(x == '+' || x == '-') return 2;
    return 1; // x == '('
}

//Kiem tra toan hang hay toan tu
int check(char x)
{
    if(x == '*' || x == '/' || x == '+' || x == '-') return 2;
    else return 1;
}

int KtraSo(char x)
{
    return (x - '0' >= 0 && x - '0' <= 9);
}

int KiemTra(char *s)
{
    StackType *stack = NULL;
    int i;
    for(i = 0; i < strlen(s); ++i)
    {
        if(check(s[i]) == 2 && !KtraSo(s[i - 1]) || !KtraSo(s[i + 1])) return 0;
        if(IsEmpty(&stack) && s[i] == ')') return 0;
        if(s[i] == '(')
        {
            Push((int)s[i], &stack);
        }
        else if(s[i] == ')') 
        {
            pop(&stack);
        }
    }
    // Neu stack rong thi tra ve dung
    if(IsEmpty(&stack)) return 1;
    else return 0;
}

void Func1(char *infix)
{
    printf("\nEnter Infix Notation: ");
    fflush(stdin); gets(infix);
    //printf("\nInfix Notation: %s\n", infix);
    while(!KiemTra(infix))
    {
        printf("\nWrong expression! Enter again: ");
        fflush(stdin); gets(infix);
    }
    printf("\nInfix Notation: %s\n", infix);
} 

void Func2(char *infix, char *postfix)
{
    int i, j = 0;
    char x;
    StackType *stack = NULL;
    for(i = 0; i < strlen(infix); ++i)
    {
        if(isalnum(infix[i])) postfix[j++] = infix[i];
        else
        {
            if(infix[i] == '(')
            {
                Push((int)infix[i], &stack);
            }
            else if(infix[i] == ')')
            {
                while((x = (char)pop(&stack)) != '(')
                {
                    postfix[j++] = x;
                }
            }
            else
            {
                while(!IsEmpty(&stack) && Precedence(infix[i]) <= Precedence((char)Top(&stack)))
                {
                    x = (char)pop(&stack);
                    postfix[j++] = x;
                }
                Push((int)infix[i], &stack);
            }
        }
    }
    while(!IsEmpty(&stack))
    {
        x = (char)pop(&stack);
        postfix[j++] = x;
    }
    postfix[j] = '\0';
    printf("\nPostfix Notation: %s\n", postfix);
}

int Tinh(int a, int b, char tmp)
{
    int result;
    switch(tmp)
    {
        case '+':
            result = a + b;
            break;
        case '-':
            result = b - a;
            break;
        case '*':
            result = b * a;
            break;
        case '/':
            result = b / a;
            break;
        default: 
            printf("\nInvalid Operator!\n");
            exit(1);
    }
    return result;
}

void CalTrungTo(char *s)
{
    //toan tu, toan hang
    StackType *tt = NULL, *th = NULL;
    int i, a, b, result;
    char tmp;
    for(i = 0; i < strlen(s); ++i)
    {
        if(check(s[i]) == 1 && s[i] != '(' && s[i] != ')') Push(s[i] - '0', &th);
        else 
        {
            if(s[i] == '(') Push((int)s[i], &tt);
            else if (check(s[i]) == 2)
            {
                while(!IsEmpty(&tt) && Precedence(s[i]) <= Precedence((char)Top(&tt)))
                {
                    a = pop(&th);
                    b = pop(&th);
                    tmp = (char)pop(&tt);
                    Push(Tinh(a, b, tmp), &th); 
                }
                Push((int)s[i], &tt);
            }
            else if(s[i] == ')')
            {
                while((char)Top(&tt) != '(')
                {
                    a = pop(&th);
                    b = pop(&th);
                    tmp = (char)pop(&tt);
                    Push(Tinh(a, b, tmp), &th);
                }
                pop(&tt);
            }
        }
    }
    while(!IsEmpty(&tt))
    {
        a = pop(&th);
        b = pop(&th);
        tmp = (char)pop(&tt);
        Push(Tinh(a, b, tmp), &th);
    }
    result = pop(&th);
    printf("\nResult is: %d\n", result);
}

void HauTo(char *postfix)
{
    int i, a, b, result;
    StackType *stack = NULL;
    for(i = 0; i < strlen(postfix); ++i)
    {
        if((postfix[i] - '0') <= 9 && (postfix[i] - '0') >= 0)
        {
            //printf("%d\n", postfix[i] - '0');
            Push(postfix[i] - '0', &stack);
        }
        else
        {
            a = pop(&stack);
            b = pop(&stack);
            Push(Tinh(a, b, postfix[i]), &stack);
        }
    }
    result = pop(&stack);
    printf("\nResult is: %d\n", result);
}

void Func3(char *infix, char *postfix)
{
    int opt;
    do
    {
        printf("\n1. Infix\n2. Postfix\n3. Exit\n");
        printf("\nEnter your option: ");
        fflush(stdin); scanf("%d", &opt);
        switch(opt)
        {
            case 1:
                CalTrungTo(infix);
                break;
            case 2:
                HauTo(postfix);
                break;
            case 3:
                printf("\nQuitting...\n");
                break;
            default:
                printf("\nInvalid!\n");
                break;
        }
    } while (opt != 3);
}

void Menu(char *infix, char *postfix)
{
    int opt, cnt;
    printf("\nMENU:\n");
    do
    {
        printf("\n1. Enter Infix\n2. Change to postfix\n3. Calculating value\n4. Exit\n");
        printf("\nEnter your option: ");
        fflush(stdin); scanf("%d", &opt);
        switch(opt)
        {
            case 1: 
                if(cnt == 0) cnt++;
                Func1(infix);
                break;
            case 2:
                if(cnt == 0)
                {
                    printf("\nYou must choose 1 first!\n");
                }
                else Func2(infix, postfix);
                break;
            case 3:
                if(cnt == 0)
                {
                    printf("\nYou must choose 1 first!\n");
                }
                else Func3(infix, postfix);
                break;
            case 4:
                printf("\nThank you!\n");
                break;
        } 
    } while (opt != 4);
}

int main()
{
    char *infix = (char *)malloc(MAX * sizeof(char));
    char *postfix = (char *)malloc(MAX * sizeof(char));
    Menu(infix, postfix);
    free(infix);
    free(postfix);
    return 0;
}
