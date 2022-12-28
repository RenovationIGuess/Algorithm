#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

FILE *f;
int n;

typedef struct 
{
    int id;
    char cpu[30];
    int ram;
} et;

#include "singlel.h"

int ram_invalid(int x)
{
    int i;
    for(i = 1; i <= 32; i *= 2)
    {
        if(x == i) return 1;
    }
    return 0;
}

int cpu_invalid(char *s)
{
    if(s[0] != 'i' || s[0] != 'I') return 0;
    int num = s[1] - '0';
    int i;
    for(i = 1; i <= 9; i += 2)
    {
        if(num == i) return 1;
    }
    return 0;
}

void func1()
{
    char *name = (char *)malloc(MAX * sizeof(char));
    printf("\nEnter the files name: ");
    fflush(stdin); gets(name);
    if((f = fopen(name, "r")) == NULL)
    {
        printf("\nFile doesn't existed!\n");
        return;
    }
    et add;
    //char c;
    int i;
    fscanf(f, "%d", &i);
    do
    {
        fscanf(f, "%s", add.cpu);
        /*do
        {
            c = fgetc(f);
        } while (c == ' ' || c == '\t'); */
        fgetc(f);
        fscanf(f, "%d", &add.ram);
        n++;
        if(n > 20)
        {
            printf("\nThe list is full, cannot add more!\n");
            return;
        }
        add.id = n;
        InsertTail(add);
        if(feof(f)) break;
    } while (1);
    //reverseList();
    printf("\nData read from file:\n");
    printf("%-10s%-10s%-10s\n", "ID", "CPU", "RAM");
    printList();
    printf("\nRead success!\n");
    fclose(f);
}

void func2()
{
    char *inp = (char *)malloc(MAX * sizeof(char));
    printf("\nEnter id: ");
    fflush(stdin); gets(inp);
    //int id = inp[0] - '0';
    int id = atoi(inp);
    while(id < 0 && id > n)
    {
        printf("\nInvalid! Enter again: ");
        fflush(stdin); gets(inp);
        id = atoi(inp);
    }
    node *p = l;
    while(p != NULL)
    {
        if(p->data.id == id)
            break;
        p = p->next;
    }
    while(p != NULL)
    {
        printf("\nUpdate CPU id - %d name: ", p->data.id);
        fflush(stdin); gets(inp);
        if(strcmp("STOP", inp) == 0)
            break;
        else strcpy(p->data.cpu, inp);
        p = p->next;
    }
    free(inp);
}

void func3()
{
    char *inp = (char *)malloc(MAX * sizeof(char));
    printf("\nEnter id: ");
    fflush(stdin); gets(inp);
    //int id = inp[0] - '0';
    int id = atoi(inp);
    while(id < 0 && id > n)
    {
        printf("\nInvalid! Enter again: ");
        fflush(stdin); gets(inp);
        id = atoi(inp);
    }
    node *p = l;
    while(p != NULL)
    {
        if(p->data.id == id)
            break;
        p = p->next;
    }
    while(p != NULL)
    {
        printf("\nUpdate RAM's (id: %d) value: ", p->data.id);
        fflush(stdin); gets(inp);
        if(strcmp("STOP", inp) == 0)
            break;
        else p->data.ram = atoi(inp);
        p = p->next;
    }
    free(inp);
}

void func4()
{
    char *inp = (char *)malloc(MAX * sizeof(char));
    printf("\nEnter CPU's name/RAM value: ");
    fflush(stdin); gets(inp);
    int check = inp[0] - '0';

    node *p;
    int found;
    if(check >= 1 && check <= 9)
    {
        int ram = atoi(inp);
        if(!ram_invalid(ram)) 
        {
            printf("\nThe value you input is invalid!\n");
            return;
        }
        found = 0;
        p = l;
        while(p != NULL)
        {
            if(p->data.ram == ram)
            {
                if(found == 0)
                {
                    found = 1;
                    printf("\n%-10s%-10s%-10s\n", "ID", "CPU", "RAM");
                }
                displayNode(p);
            }
            p = p->next;
        }
        if(found == 0) printf("\nThe value you input is invalid!\n");
    }
    else
    {
        if(cpu_invalid(inp)) 
        {
            printf("\nThe value you input is invalid!\n");
            return;
        }
        found = 0;
        p = l;
        while(p != NULL)
        {
            if(strcasecmp(p->data.cpu, inp) == 0)
            {
                if(found == 0)
                {
                    found = 1;
                    printf("\n%-10s%-10s%-10s\n", "ID", "CPU", "RAM");
                }
                displayNode(p);
            }
            p = p->next;
        }
        if(found == 0) printf("\nThe value you input is invalid!\n");
    }
    free(inp);
}

void menu()
{
    n = 0;
    int opt;
    do
    {
        printf("\n====Program for management computers====\n");
        printf("1) Load Data Files:\n2) Update CPU Info:\n3) Update Ram Info:\n4) Search:\n5) Quit\n");
        printf("\nEnter your option: "); 
        fflush(stdin); scanf("%d", &opt);
        switch(opt)
        {
            case 1:
                func1();
                break;
            case 2:
                func2();
                break;
            case 3:
                func3();
                break;
            case 4:
                func4();
                break;
            case 5:
                printf("\nThank you for using our services!\n");
                break;
            default:
                printf("\nInvalid!\n");
                break;
        }
    } while (opt != 5);
    
}

int main(int argc, char *argv[])
{
    l = prev = cur = NULL;
    menu();
    FreeList();
    return 0;
}