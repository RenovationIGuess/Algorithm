//#define _GNU_SOURCE
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include "DoubleL.h"
#define MAX 256

//dieu khien file
FILE *f;

//Import from PhoneDB.dat (insert after cur)
void Func1(char *s, doublelist *root, doublelist *cur, doublelist *tail)
{
    printf("\nProcessing...\n");
    if ((f = fopen(s, "rb")) == NULL) 
    {
        printf("Cannot open %s.", s);
        exit(1);
    }

    et *a = (et *)malloc(MAX * sizeof(et));
    fseek(f, 0, SEEK_END);
    m_num = ftell(f) / sizeof(et);  
    int i = 0, num;
    fseek(f, 0, SEEK_SET);
    num = fread(a, sizeof(et), m_num, f);
    printf("\nNumber of phone models: %d.\n", m_num);
    for(i = 0; i < m_num; ++i)
    {
        InsertAfterCurrent(a[i], root, tail, cur);
    }

    fclose(f);
    printf("\nSuccess!\n");
}

//Display List - traverse
void Func2(doublelist *root)
{
    printf("\nProcessing...\n");
    printf("\n%-5s%-20s%-25s%-25s%-20s\n", "", "Model", "Memory Space(GB)", "Screen Size(inches)", "Price($)");
    node *p = *root;
    if(p == NULL)
    {
        printf("\nDanh sach rong!\n");
        return;
    }
    int i = 0;
    while(p != NULL)
    {
        printf("%-5d%-20s%-25.2f%-25.2f%-20.2f\n", i, p->data.model, p->data.ms, p->data.ss, p->data.price);
        i++;
        p = p->next;
    }
    printf("\nReturning to main menu...\n");
}

//Insert Before
void Func3_1(doublelist *root, doublelist *cur, doublelist *tail)
{
    printf("\nProcessing...\n");
    et add;
    printf("\nHay nhap thong tin muon them:\n");
    ReadNode(&add);
    InsertBeforeCurrent(add, root, tail, cur);
    m_num++;
    printf("\nSuccess!\n");
}

//Insert After
void Func3_2(doublelist *root, doublelist *cur, doublelist *tail)
{
    printf("\nProcessing...\n");
    et add;
    printf("\nHay nhap thong tin muon them:\n");
    ReadNode(&add);
    InsertAfterCurrent(add, root, tail, cur);
    m_num++;
    printf("\nSuccess!\n");
}

//Insert At First
void Func3_3(doublelist *root, doublelist *cur, doublelist *tail)
{
    printf("\nProcessing...\n");
    et add;
    printf("\nHay nhap thong tin muon them:\n");
    ReadNode(&add);
    InsertAtHead(add, root, tail, cur);
    m_num++;
    printf("\nSuccess!\n");
}

//Append
void Func3_4(doublelist *root, doublelist *cur, doublelist *tail)
{
    printf("\nProcessing...\n");
    et add;
    printf("\nHay nhap thong tin muon them:\n");
    ReadNode(&add);
    InsertAtTail(add, root, tail, cur);
    m_num++;
    printf("\nSuccess!\n");
}

//Add new phone (before/after)
void Func3(doublelist *root, doublelist *cur, doublelist *tail)
{
    printf("\nProcessing...\n");
    int opt, vitri;
    char ok;
    do
    {
        printf("\n1. Insert Before Current Position\n2. Insert After Current Position\n3. Insert At First\n4. Append\n5. Exit\n");
        node *current = *cur;
        printf("\nCurrent pointer is now at:\n");
        printf("\n%-20s%-25s%-25s%-20s\n", "Model", "Memory Space(GB)", "Screen Size (inches)", "Price");
        displayNode(current);

        printf("\nDo you want to change current pointer? [y/n]: ");
        fflush(stdin); scanf("%c", &ok);
        while(ok != 'y' && ok != 'n')
        {
            printf("\nInvalid! Enter again: ");
            fflush(stdin); scanf("%c", &ok);
        }
        if(ok == 'y')
        {
            printf("\nNhap vi tri muon thay doi [1; %d]: ", m_num);
            fflush(stdin); scanf("%d", &vitri);
            while(vitri <= 0 || vitri > m_num)
            {
                printf("\nInvalid! Enter again: ");
                fflush(stdin); scanf("%d", &vitri);
            }
            int i;
            node *p = *root;
            for(i = 0; i < vitri - 1; ++i)
            {
                p = p->next;
            }
            current = *cur = p;
            printf("\nCurrent pointer is now at:\n");
            printf("\n%-20s%-25s%-25s%-20s\n", "Model", "Memory Space(GB)", "Screen Size (inches)", "Price");
            displayNode(current);
        }

        printf("\n1. Insert Before Current Position\n2. Insert After Current Position\n3. Insert At First\n4. Append\n5. Exit\n");
        printf("\nEnter option: "); fflush(stdin); scanf("%d", &opt);
        switch(opt)
        {
            case 1: 
                Func3_1(root, cur, tail);
                break;
            case 2: 
                Func3_2(root, cur, tail);
                break;
            case 3: 
                Func3_3(root, cur, tail);
                break;
            case 4:
                Func3_4(root, cur, tail);
                break;
            case 5:
                break;
            default:
                printf("\nInvalid!\n");
                break;
        }
    } while (opt != 5);
    
    printf("\nReturning to main menu...\n");
}

//Insert at position
void Func4(doublelist *root, doublelist *cur, doublelist *tail)
{
    printf("\nProcessing:\n");
    //position
    int posi;
    printf("\nEnter position you want [0; %d]: ", m_num - 1);
    fflush(stdin); scanf("%d", &posi);
    while(posi < 0 || posi > m_num - 1)
    {
        printf("\nInvalid! Enter again: ");
        fflush(stdin); scanf("%d", &posi);
    }
    et add;
    ReadNode(&add);
    InsertAtPosition(posi, add, root, tail, cur);
    m_num++;
    printf("\nSuccess! Use Function 2 to check.\n");
}

//Delete at position
void Func5(doublelist *root, doublelist *cur, doublelist *tail)
{
    printf("\nProcessing:\n");
    int posi;
    printf("\nEnter position you want [0; %d]: ", m_num - 1);
    fflush(stdin); scanf("%d", &posi);
    while(posi < 0 || posi > m_num - 1)
    {
        printf("\nInvalid! Enter again: ");
        fflush(stdin); scanf("%d", &posi);
    }
    DeleteAtPosition(posi, root, tail, cur);
    m_num--;
    printf("\nSuccess! Use Function 2 to check.\n");
}

//Delete current
void Func6(doublelist *root, doublelist *cur, doublelist *tail)
{
    printf("\nProcessing:\n");
    int vitri;
    char ok;
    node *current = *cur;
    printf("\nCurrent pointer is now at:\n");
    printf("\n%-20s%-25s%-25s%-20s\n", "Model", "Memory Space(GB)", "Screen Size (inches)", "Price");
    displayNode(current);

    printf("\nDo you want to change current pointer? [y/n]: ");
    fflush(stdin); scanf("%c", &ok);
    while(ok != 'y' && ok != 'n')
    {
        printf("\nInvalid! Enter again: ");
        fflush(stdin); scanf("%c", &ok);
    }
    if(ok == 'y')
    {
        printf("\nNhap vi tri muon thay doi [1; %d]: ", m_num);
        fflush(stdin); scanf("%d", &vitri);
        while(vitri <= 0 || vitri > m_num)
        {
            printf("\nInvalid! Enter again: ");
            fflush(stdin); scanf("%d", &vitri);
        }
        int i;
        node *p = *root;
        for(i = 0; i < vitri - 1; ++i)
        {
            p = p->next;
        }
        current = *cur = p;
        printf("\nCurrent pointer is now at:\n");
        printf("\n%-20s%-25s%-25s%-20s\n", "Model", "Memory Space(GB)", "Screen Size (inches)", "Price");
        displayNode(current);
    }     
    DeleteCurrent(root, tail, cur);
    m_num--;
    printf("\nSuccess! Use Function 2 to check.\n");
}

//Delete First
void Func7(doublelist *root, doublelist *cur)
{
    printf("\nProcessing:\n");
    DeleteHead(root, cur);
    m_num--;
    printf("\nSuccess! Use Function 2 to check.\n");
}

//Delete Last
void Func8(doublelist *root, doublelist *cur, doublelist *tail)
{
    printf("\nProcessing...\n");
    DeleteTail(root, tail, cur);
    m_num--;
    printf("\nSuccess! Use Function 2 to check.\n");
}

//Search and Update
void Func9(doublelist *root, doublelist *cur, doublelist *tail)
{
    printf("\nProcessing...\n");
    int i;
    char c;
    char mod[MAX];
    do
    {
        // xem model can tim co ko
        int found = 0;
        printf("\nEnter Phone Model you want to search: ");
        fflush(stdin);
        gets(mod);
        node *p = *root;
        while(p != NULL)
        {
            if(strcasecmp(p->data.model, mod) == 0)
            {
                found = 1; 
                printf("\n%-20s%-25s%-25s%-20s\n", "Model", "Memory Space(GB)", "Screen Size (inches)", "Price");
                displayNode(p);
                ReadNode(&p->data);
                break;
            }
            p = p->next;
        }
        if(found == 0) printf("\nNon - existed!\n");
        printf("\nDo you want to continue [y/n]: ");
        fflush(stdin);
        scanf("%c", &c);
        while(c != 'y' && c != 'n')
        {
            printf("\nInvalid! Enter again: ");
            fflush(stdin); scanf("%c", &c);
        }
    } while(c == 'y');
    printf("\nReturning to main menu...\n");
}

//reverse list - l
void Func10(doublelist *root, doublelist *cur)
{
    printf("\nProcessing...\n");
    Reverse(root);
    printf("\nSuccess! Use Function 2 to check.\n");
}

//Export to dat - Save to file
void Func11(char *s, doublelist *root)
{
    printf("\nProcessing...\n");
    if ((f = fopen(s, "wb")) == NULL) 
    {
        printf("Cannot open %s.", s);
        exit(1);
    }
    et *a = (et *)malloc(MAX * sizeof(et));
    node *p = *root;
    int num;
    fseek(f, 0, SEEK_SET);
    int i = 0;
    while(p != NULL)
    {
        a[i] = p->data;
        i++;
        p = p->next;
    }
    num = fwrite(a, sizeof(et), i, f);
    printf("\nSuccess! Returning to main menu...\n");
    fclose(f);
}

void Menu(char *s, doublelist *root, doublelist *cur, doublelist *tail)
{
    printf("\nMenu:\n");
    int cnt = 0;
    int i;
    do
    {
        // option
        int opt;
        printf("\n1. Import from PhoneDB.dat\n2. Display (traverse)\n3. Add new phone\n4. Insert at position\n5. Delete at position\n6. Delete current\n7. Delete first\n8. Delete last\n9. Search and update\n10. Reverse List\n11. Save to file\n12. Quit (free)\n");
        printf("\nEnter option: ");
        fflush(stdin);
        scanf("%d", &opt);
        switch(opt)
        {
            case 1:
                //Import from text
                if(cnt != 0)
                {
                    FreeList(root);
                    //Func3();
                }
                Func1(s, root, cur, tail);
                cnt++;
                break;
            case 2:
                if(cnt == 0)
                {
                    printf("\nChoose 1 first!\n");
                    break;
                }
                Func2(root);
                break;
            case 3:
                if(cnt == 0)
                {
                    printf("\nChoose 1 first!\n");
                    break;
                }
                Func3(root, cur, tail);
                break;
            case 4:
                if(cnt == 0)
                {
                    printf("\nChoose 1 first!\n");
                    break;
                }
                Func4(root, cur, tail);
                break;
            case 5:
                if(cnt == 0)
                {
                    printf("\nChoose 1 first!\n");
                    break;
                }
                Func5(root, cur, tail);
                break;
            case 6: 
                if(cnt == 0)
                {
                    printf("\nChoose 1 first!\n");
                    break;
                }
                Func6(root, cur, tail);
                break;
            case 7: 
                if(cnt == 0)
                {
                    printf("\nChoose 1 first!\n");
                    break;
                }
                Func7(root, cur);
                break;
            case 8: 
                if(cnt == 0)
                {
                    printf("\nChoose 1 first!\n");
                    break;
                }
                Func8(root, cur, tail);
                break;
            case 9:
                if(cnt == 0)
                {
                    printf("\nChoose 1 first!\n");
                    break;
                }
                Func9(root, cur, tail);
                break;
            case 10:
                if(cnt == 0)
                {
                    printf("\nChoose 1 first!\n");
                    break;
                }
                Func10(root, cur);
                break;
            case 11:
                if(cnt == 0)
                {
                    printf("\nChoose 1 first!\n");
                    break;
                }
                Func11(s, root);
                break;
            case 12: 
                printf("\nThank you!\n");
                return;
            default:
                printf("\nInvalid!\n");
                break;
        }
    } while(1);
}

int main(int argc, char *argv[])
{
        printf("\nProcessing...\n");
        doublelist root = NULL, cur = NULL, tail = NULL;
        Menu(argv[1], &root, &cur, &tail);
        FreeList(&root);
        return 0;
}