#include <stdlib.h>
#include <stdio.h>
 
//typedef int item; //kieu du lieu

typedef struct {
    int ID;
    int m;
}item;

struct node
{
	item Data;
	struct node * Next;
};
typedef struct node Node;

typedef struct
{
	Node * Front, *Rear; //Node dau va Node cuoi
	int count; //dem so phan tu
}Queue;

Queue mem, q;
int memory, num;
int Memory, Num;
int count = 0;
 
 #include "queue.h"

item readNode() {
    item tmp;
    printf("Nhap thong tin: \n");
    printf("ID: "); scanf("%d", &tmp.ID);
    printf("Memory: "); scanf("%d", &tmp.m);
    return tmp;
}
void check(Queue *q, Queue *mem, item tmp)
{
    if ((Memory+tmp.m <= memory) && (Num + 1 <= num))
    {
        Push(mem, tmp);
        Num++;
        Memory += tmp.m;
    }
    else {
        Push(q, tmp);
    }
}

void func1(Queue *q, Queue *mem)
{
    char c;
     do
    {
        printf("\nCreate new program run time: \n");
        item tmp;
        tmp = readNode();
        while (tmp.ID <= 0 || tmp.m <= 0)
        {
            printf("\nInvalid! Enter again!\n");
            tmp = readNode();
        }
        check(q, mem, tmp);
        
        printf("\nDo you want to continue [y/n]: ");
        fflush(stdin); scanf("%c", &c);
        while(c != 'y' && c != 'n')
        {
            printf("\nInvalid! Enter again: ");
            fflush(stdin); scanf("%c", &c);
        }
    } while (c == 'y');
   

}

void func2(Queue *q, Queue *mem)
{
    printf("Show status: ");
    printf("\n%-5s%-15s\n","ID", "Memory");
    Output(mem);
    //printf("%d       %d\n", Top(mem).ID, Top(mem).m);
    //printf("%d\n", size(mem));
    printf("\n%-5s%-15s\n", "ID", "Queue");
    Output(q);
}

void func3(Queue *q, Queue *mem)
{
    printf("Kill process! \n");
    item tmp;
    tmp = Pop(mem);
    
    Memory -= tmp.m;
    Num--;
    while(!Isempty(*q) && Memory + Top(q).m < memory && size(mem) < num)
    {
        tmp = Pop(q);
        check(q, mem, tmp);
    }
}

void menu(Queue *q, Queue *mem)
{
    int func;
    int cnt = 0;
	printf("Menu: ");
	do 
	{
        printf("\n1. Create new program.\n2. Kill a program.\n3. Show a status.\n4. Exit\n");
		printf("Enter option:");
		fflush(stdin);
		scanf("%d", &func);
		while(func < 1 || func > 4)
		{
			printf("Khong Hop Le! Nhap Lai: ");
			fflush(stdin);
			scanf("%d", &func);
		}
		switch(func)
		{
			case 1: 
                cnt = 1;
                func1(q, mem);
                break;
			case 2: 
                if(cnt == 0) {
                    printf("\nChoose 1 first!\n");
                    break;
                }
                func2(q, mem);
                break;
            case 3:
                if(cnt == 0) {
                    printf("\nChoose 1 first!\n");
                    break;
                }
                func3(q, mem);
                break;
            case 4:
				printf("\nThank you!\n");
				break;
		}
	} while(func != 4);
}


int main()
{
    printf("\nNumber of parallel process: ");
    fflush(stdin); scanf("%d", &num);
    while(num <= 0)
    {
        printf("\nInvalid! Enter again: ");
        fflush(stdin); scanf("%d", &num);
    }
    printf("\nMemory capacity: ");
    fflush(stdin); scanf("%d", &memory);
    while(memory <= 0)
    {
        printf("\nInvalid! Enter again: ");
        fflush(stdin); scanf("%d", &memory);
    }
    MakeNull(&mem);
    MakeNull(&q);
    menu(&q, &mem);
    return 0;
}