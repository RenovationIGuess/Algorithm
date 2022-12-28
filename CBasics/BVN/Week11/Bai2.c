#include "queue.h"

int num, count;
// num - process, num1 - waiting
float memory;

void Func3(queue *process, queue *waiting)
{
    printf("\n%-15s%-15s%-15s\n", "ID", "Memory", "Queue");
    int i;
    ElementType tmp;
    if(!IsEmpty(process))
    {
        for(i = 0; i < size(process); ++i)
        {
            tmp = Dequeue(process);
            printf("%-15d%-15.2f%-15s\n", tmp.id, tmp.memory, "");
            EnQueue(tmp, process);
        }
    }
    if(!IsEmpty(waiting))
    {
        for(i = 0; i < size(waiting); ++i)
        {
            tmp = Dequeue(waiting);
            printf("%-15d%-15s%-15.2f\n", tmp.id, "", tmp.memory);
            EnQueue(tmp, waiting);
        }
    }
}

void Func1(queue *process, queue *waiting)
{
    ElementType tmp;
    //int cnt = 1;
    //float amount = memory;
    //while(cnt <= num)
    //{
        if(count == 1)
        {
            printf("\nCreate new program run %dst time:\n", count);
        }
        else if(count == 2)
        {
            printf("\nCreate new program run %dnd time:\n", count);
        }
        else if(count == 3)
        {
            printf("\nCreate new program run %drd time:\n", count);
        }
        else
        {
            printf("\nCreate new program run %dth time:\n", count);
        }
            printf("\nThe memory size of program? ");
            fflush(stdin); scanf("%f", &tmp.memory);
            while(tmp.memory <= 0)
            {
                printf("\nInvalid! Enter again: ");
                fflush(stdin); scanf("%f", &tmp.memory);
            }
            printf("\nProgram ID? "); 
            fflush(stdin); scanf("%d", &tmp.id);
            while(tmp.id <= 0)
            {
                printf("\nInvalid! Enter again: ");
                fflush(stdin); scanf("%f", &tmp.id);
            }
            //
            if(memory - tmp.memory >= 0 && size(process) < num)
            {
                EnQueue(tmp, process);
                memory -= tmp.memory;
                printf("\nSuccessful! Process created!\n");
                Func3(process, waiting);
                count++;
            }
            //
            else
            {
                if(memory - tmp.memory >= 0 && size(process) >= num)
                {
                    EnQueue(tmp, waiting);
                    printf("\nIn queue as there is already full processes\n", num);
                }
                else if(memory - tmp.memory < 0)
                {
                    EnQueue(tmp, waiting);
                    printf("\nIn queue as there is not enough memory (%.2f vs %.2f)\n", memory, tmp.memory);
                }
            }
    //}
}

void Func2(queue *process, queue *waiting)
{
    int del, cnt = 0, i, cnt1 = 0;
    ElementType find;
    printf("\nProgram ID? ");
    fflush(stdin); scanf("%d", &del);
    while(1)
    {
        cnt++;
        if(cnt > num)
        {
            printf("\nNot found!\n");
            break;
        }
        else
        {
            find = Dequeue(process);
            if(find.id == del)
            {
                if(cnt > 1 && cnt < num)
                {
                    for(i = cnt; i < num; ++i)
                        EnQueue(Dequeue(process), process);
                }
                memory += find.memory;
                
                while(!IsEmpty(waiting) && memory - top(waiting).memory >= 0 && cnt1 < num)
                {
                    memory -= top(waiting).memory;
                    EnQueue(Dequeue(waiting), process);
                    cnt1++;
                } 
                
                printf("\nSuccess!\n");
                break;
            }
            else EnQueue(find, process);
        }        
    }
    Func3(process, waiting);
}

void Menu(queue *process, queue *waiting)
{
    int opt;
    int cnt = 0;
    count = 1;
    char c;
    do
    {
        printf("\nNumber of parallel process: ");
        fflush(stdin); scanf("%d", &num);
        while(num <= 0)
        {
            printf("\nInvalid! Enter again: ");
            fflush(stdin); scanf("%f", &num);
        }
        printf("\nMemory capacity: ");
        fflush(stdin); scanf("%f", &memory);
        while(memory <= 0)
        {
            printf("\nInvalid! Enter again: ");
            fflush(stdin); scanf("%f", &memory);
        }
        do
        {
            printf("\n1. Create new program (ID and memory)\n2. Kill a program\n3. Show status\n4. Exit\n");
            printf("\nEnter your option: ");
            fflush(stdin); scanf("%d", &opt);
            switch (opt)
            {
            case 1:
                //if(count == 0) count = 1;
                Func1(process, waiting);
                if(cnt == 0) cnt++;
                break;
            case 2:
                if(cnt == 0)
                {
                    printf("\nUse 1 first!\n");
                    break;
                }
                Func2(process, waiting);
                break;
            case 3:
                if(cnt == 0)
                {
                    printf("\nUse 1 first!\n");
                    break;
                } 
                Func3(process, waiting);
                break;
            case 4:
                printf("\nQuitting...\n");
                break;
            default:
                printf("\nInvalid!\n");
                break;
            }
        } while (opt != 4);

        printf("\nDo you want to continue [y/n]: ");
        fflush(stdin); scanf("%c", &c);
        while(c != 'y' && c != 'n')
        {
            printf("\nInvalid! Enter again: ");
            fflush(stdin); scanf("%c", &c);
        }
    } while (c == 'y');
    printf("\nSee you again!\n");
}

int main()
{
    queue process, waiting;
    MakeNull(&process);
    MakeNull(&waiting);
    Menu(&process, &waiting);
    return 0;
}