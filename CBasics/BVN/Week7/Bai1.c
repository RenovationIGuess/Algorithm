#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#define MAX 256

typedef struct
{
    char name[41];
    char tel[31];
    char email[41];
} p;

struct Node
{
    p phone;
    struct Node *next;
};

typedef struct Node node;

int m_num; // so danh ba
//l - tree/ list, cur - con trỏ hiện tại, prev - con trỏ trước cur
node *l, *cur, *prev;

node *createNode(p x)
{
    node *tmp = (node *)malloc(sizeof(node));
    tmp->phone = x;
    tmp->next = NULL;
    return tmp;
}

void displayNode(node *x)
{
    if(x == NULL)
    {
        printf("\nCon tro loi - NULL!\n");
        return;
    }
    p tmp = x->phone;
    //printf("\n%-30s%-30s%-30s\n", "Name", "Tel", "Email");
    printf("%-30s%-30s%-30s\n", tmp.name, tmp.tel, tmp.email);
}

void InsertAtHead(p x)
{
    node *tmp = createNode(x);
    tmp->next = l;
    l = tmp;
    cur = l;
    //prev = NULL;
}

void InsertAfterCur(p x)
{
    node *tmp = createNode(x);
    if(cur == NULL) return;
    if(l == NULL)
    {
        l = tmp;
        cur = l;
        prev = NULL;
    }
    else
    {
        tmp->next = cur->next;
        cur->next = tmp;
        prev = cur;
        cur = cur->next;
    }
}

void InsertBeforeCur(p x)
{
    node *tmp = createNode(x);
    if(l == NULL)
    {
        l = tmp;
        cur = l;
        prev = NULL;
    }
    else
    {
        tmp->next = cur;
        prev->next = tmp;
        prev = tmp;
    }
}

void reverseList()
{
    node *p = l;
    node *tsugi, *pre;
    tsugi = pre = NULL;
    while(p != NULL)
    {
        tsugi = p->next;
        p->next = pre;
        pre = p;
        p = tsugi;
    }
    l = pre;
    cur = l;
    prev = NULL;
}

void ReadNode(p *a)
{
    printf("\nEnter name: ");
    fflush(stdin); gets(a->name);
    printf("\nEnter telephone: "); 
    fflush(stdin); //scanf("%s", &a->tel);
    gets(a->tel);
    printf("\nEnter email: ");
    fflush(stdin); //scanf("%s", &a->email);
    gets(a->email);
}

void printList()
{
    node *p = l;
    int i = 1;
    printf("\n%-5s%-30s%-30s%-30s\n", "", "Name", "Tel", "Email");
    while(p != NULL)
    {
        //for(i = 0; i < num; ++i)
        printf("%-5d%-30s%-30s%-30s\n", i, p->phone.name, p->phone.tel, p->phone.email);
        p = p->next;
        i++;
    }
    //printf("\n");
}

void FreeList()
{
    node *p = l;
    while(p != NULL)
    {
        l = l->next;
        free(p);
        p = l;
    }
}

void Option1()
{
    p them;
    // lua chon tiep tuc / khong
    char c;
    do
    {
        printf("\nNhap thong tin danh ba muon them:\n");
        ReadNode(&them);
        InsertAtHead(them);
        m_num++;
        /*printf("\nThong tin da nhap:\n\n%-30s%-30s%-30s\n", "Name", "Tel", "Email");
        printf("%-30s%-30s%-30s\n", them.name, them.tel, them.email); */
        printf("\nSau khi them:\n");
        printList(l);
        printf("\nDo you want to continue [y/n]: ");
        fflush(stdin); scanf("%c", &c);
        while(c != 'y' && c != 'n')
        {
            printf("\nInvalid! Enter again: ");
            fflush(stdin); scanf("%c", &c);
        }
    } while (c == 'y');
}

void Option2()
{
    // lua chon tiep tuc / khong
    p them;
    int vitri;
    char c, ok;
    do
    {
        printf("\nVi tri con tro current hien tai:\n");
        printf("\n%-30s%-30s%-30s\n", "Name", "Tel", "Email");
        displayNode(cur);
        printf("\nBan co muon thay doi vi tri con tro current khong? [y/n]: ");
        fflush(stdin); scanf("%c", &ok);
        while(ok != 'y' && ok != 'n')
        {
            printf("\nInvalid! Enter again: ");
            fflush(stdin); scanf("%c", &ok);
        }
        if(ok == 'y')
        {
            printf("\nNhap vi tri muon thay doi: ");
            fflush(stdin); scanf("%d", &vitri);
            while(vitri <= 0 || vitri > m_num)
            {
                printf("\nInvalid! Enter again: ");
                fflush(stdin); scanf("%d", &vitri);
            }
            int i;
            node *p = l;
            for(i = 0; i < vitri - 1; ++i)
            {
                p = p->next;
            }
            cur = p;
            printf("\nVi tri con tro current hien tai:\n");
            printf("\n%-30s%-30s%-30s\n", "Name", "Tel", "Email");
            displayNode(cur);
        }
        printf("\nNhap thong tin danh ba muon them:\n");
        ReadNode(&them);
        InsertAfterCur(them);
        m_num++;
        /*printf("\nThong tin da nhap:\n\n%-30s%-30s%-30s\n", "Name", "Tel", "Email");
        printf("%-30s%-30s%-30s\n", them.name, them.tel, them.email); */
        printf("\nSau khi them:\n");
        printList(l);
        printf("\nDo you want to continue [y/n]: ");
        fflush(stdin); scanf("%c", &c);
        while(c != 'y' && c != 'n')
        {
            printf("\nInvalid! Enter again: ");
            fflush(stdin); scanf("%c", &c);
        }
    } while (c == 'y');
    
}

int main(int argc, char *argv[])
{
    FILE *f;
    if((f = fopen(argv[1], "rb")) == NULL)
    {
        printf("\nCannot open %s!\n", argv[1]);
        return 1;
    }
    else
    {
        printf("\nProcessing...\n");
        printf("\n                  ⢀⣤⣶⡟\n");
        printf("        ⠀⠀⠀⠀⠀⠀⣀⡤⠖⣻⣿⣿⣿⣿⣿⣶⣶⣶⣶⣿⡟\n");
        printf("        ⠀⠀⠀⢀⡴⠞⠁⢀⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⡀\n");
        printf("        ⠀⠀⣰⠟⠀⠀⠀⡾⠁⠀⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣦⡀\n");
        printf("        ⠀⡼⠃⠀⠀⠀⠀⣇⠀⣠⡟⠻⣿⠋⠀⠀⢸⣿⣿⣿⣿⣿⣿⣿⡄\n");
        printf("        ⢰⠇⠀⠀⠀⠀⠀⢻⣿⡿⣃⢾⣿⣄⣀⣀⣿⣿⣿⣿⣿⣿⣿⣿⣧\n");
        printf("        ⣿⠀⠀⠀⠀⠀⠀⠀⠻⣿⣿⣿⡿⣿⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠇\n");
        printf("        ⣏⠀⠀⠀⠀⠀⠀⠀⠀⠈⠙⠛⠃⠻⠀⣿⠸⣿⣿⣿⣿⣿⣿⣿⣿⡇\n");
        printf("        ⢻⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠸⣿⣿⣿⣿⣿⣿⣿⣿⠁\n");
        printf("        ⠘⡆⠀⠀⠀⠀⠀⠀⠀⢠⣾⣿⣦⠀⢦⡆⢠⣤⠸⣿⣿⣿⣿⣿⡏\n");
        printf("        ⠀⠹⡄⠀⠀⠀⠀⠀⠀⢻⣿⣿⡏⠀⠘⠀⣿⣿⠇⣿⣿⣿⣿⡟\n");
        printf("        ⠀⠀⠙⣆⠀⠀⠀⠀⠀⠀⠉⠁⠀⠀⠀⠀⠈⠉⢠⣿⣿⣿⠟⠁\n");
        printf("        ⠀⠀⠀⠈⠳⢄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣾⡿⠛⠁\n");
        printf("        ⠀⠀⠀⠀⠀⠀⠉⠓⠲⢤⣄⣀⣀⣀⣤⡴⠛⠉\n");
        p *a = (p *)malloc(MAX * sizeof(p));
        int num = fread(a, sizeof(p), MAX, f);
        int i;
        printf("\nRead value: %d.\n", num);
        m_num = num;
        /*printf("\n%-30s%-30s%-30s\n", "Name", "Tel", "Email");
        for(i = 0; i < num; ++i)
        {
            printf("%-30s%-30s%-30s\n", a[i].name, a[i].tel, a[i].email);
        }*/
        /*l = createNode(a[0]);
        cur = prev = NULL;
        for(i = 1; i < num; ++i)
        {
            InsertAfterCur(a[i]);
        } */
        for(i = 0; i < m_num; ++i)
        {
            InsertAtHead(a[i]);
        }
        reverseList();
        printf("\nDu lieu doc duoc ban dau:\n");
        printList(l);

        int opt;
        do
        {
            printf("\n1. Insert At Head.\n2. Insert After Current Position.\n3. Exit.\n");
            printf("\nEnter your option: "); fflush(stdin);
            scanf("%d", &opt);
            switch(opt)
            {
                case 1: 
                    Option1();
                    break;
                case 2:
                    Option2();
                    break;
                case 3:
                    printf("\nThanks!\n");
                    break;
                default:
                    printf("\nKhong ton tai chuc nang tuong ung!\n");
                    break;
            }
        } while (opt != 3);
        
        printf("\nClosing...!\n");
        printf("\n⣿⣿⣿⢋⣉⠛⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡟⣡⠖⠳⡘⣿⣿⣿⣿\n");
        printf("⣿⣿⡇⢸⢉⣙⠢⡉⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠏⡔⣡⣾⡆⢣⢸⣿⣿⣿\n");
        printf("⣿⣿⡇⠈⢸⣿⣷⣌⢢⡙⣿⣿⣿⣿⣿⣿⣿⠏⡼⢰⣿⣿⣷⢸⠈⣿⣿⣿\n");
        printf("⣿⣿⣇⢸⢸⣿⣿⣿⡆⣷⣘⣋⣉⣭⣭⣭⣭⣴⣧⠘⠿⠿⠟⣸⠄⣿⣿⣿\n");
        printf("⣿⣿⣿⡌⢌⣋⣉⣥⣶⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣶⣾⣿⠐⣿⣿⣿\n");
        printf("⣿⣿⡟⠡⣾⣿⣿⣿⣿⡟⠻⣿⡟⠋⠙⢿⡏⠉⣿⣿⣿⣿⣿⣿⣧⠸⣿⣿\n");
        printf("⢋⠥⠦⢤⠙⣿⣿⣿⣿⣷⣾⣏⠹⠃⡘⠛⣸⣿⣿⣿⣿⣿⣿⣿⣿⣇⢹⣿\n");
        printf("⠘⡆⠉⣿⣦⣍⡛⢿⣿⣿⣿⣿⣿⠄⣴⡘⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣤⠙\n");
        printf("⣌⠻⣿⣿⣿⣿⣿⣦⣿⣿⣿⣿⣿⣆⠿⠷⢘⣿⣿⣿⣿⣿⡿⠛⣡⠌⣍⣀\n");
        printf("⣿⡆⢻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣶⣿⣿⣿⣿⣿⣿⠰⣧⡜⢒⠪⣩\n");
        printf("⣿⣿⣤⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣬⣑⣒⣊⣩\n");
        free(a);
        FreeList();
        fclose(f);
        return 0;
    }    
}