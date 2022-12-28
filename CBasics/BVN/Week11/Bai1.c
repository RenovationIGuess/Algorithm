#include<string.h>
#include "stacklist.h"
#include<ctype.h>

void Func1(StackType **integer, StackType **operator)
{
    int num;
    printf("\nEnter number to add: ");
    fflush(stdin); scanf("%d", &num);
    Push(num, integer);
    Push(1, operator);
}

void Func2(StackType **integer)
{
    if(!IsEmpty(integer))
    {
        printf("\nTop of the stack: %d\n", Top(integer));
    }
    else printf("\nStack has no element!\n");
}

void Func3(StackType **integer, StackType **operator)
{
    if(!IsEmpty(integer))
    {
        int val = pop(integer);
        printf("\nRemoved Element: %d\n", val);
        Push(val, operator);
        Push(3, operator);
    }
    else printf("\nNo elements to remove from stack!\n");
}

void Func4(StackType **integer, StackType **operator)
{
    if(!IsEmpty(operator))
    {
        int opt = pop(operator);
        if(opt == 1)
        {
            printf("\nUndo add: remove %d\n", pop(integer));
        }
        else if(opt == 3)
        {
            int val = pop(operator);
            printf("\nUndo remove: add %d\n", val);
            Push(val, integer);
        }
    }
    else printf("\nNo action has been made!\n");
}

void Menu(StackType **integer, StackType **operator)
{
    int opt;
    do
    {
        printf("\n1. Add 1 integer to the stack\n2. View top\n");
        printf("3. Remove from the stack contains integers 1 element\n4. Undo\n5. Exit\n");
        printf("\nEnter your option: ");
        fflush(stdin); scanf("%d", &opt);
        switch(opt)
        {
            case 1:
                Func1(integer, operator);
                break;
            case 2:
                Func2(integer);
                break;
            case 3:
                Func3(integer, operator);
                break;
            case 4:
                Func4(integer, operator);
                break;
            case 5:
                printf("\nThank you!\n");
                break;
            default:
                printf("\nInvalid!\n");
                break;
        }
    } while(opt != 5);
}

int main()
{
    StackType *integer = NULL;
    StackType *operator = NULL;
    Menu(&integer, &operator);
    return 0;
}
