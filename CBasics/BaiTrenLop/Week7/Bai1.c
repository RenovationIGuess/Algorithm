#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 101

typedef struct
{
    char name[41];
    char tel[31];
    char email[41];
} add;

struct Node
{
    add tp;
    struct Node *next;
};

typedef struct Node node;

//node *root, *cur, *prev;

node *createNode(add p)
{
    node *tmp = (node *)malloc(sizeof(node));
    tmp->tp = p;
    /*strcpy(tmp->tp.name, p.name);
    strcpy(tmp->tp.tel, p.tel);
    strcpy(tmp->tp.email, p.email);*/
    tmp->next = NULL;
    return tmp;
}

node *addEle(node *l, add p)
{
    node *tmp = createNode(p);
    l->next = tmp;
    return tmp;
}

node *InsertHead(node *l, add p)
{
    node *tmp = (node *)malloc(sizeof(node));
    tmp->tp = p;
    tmp->next = l;
    l = tmp;
    return l;
}

node *InsertAt(node *l, add x, int k)
{
    node *p = l;
    int i;
    for(i = 0; i < k - 1; ++i)
    {
        p = p->next;
    }
    node *tmp = (node *)malloc(sizeof(node));
    tmp->tp = x;
    tmp->next = p->next;
    p->next = tmp;
    return l;
}

node *InsertTail(node *l, add x)
{
    node *p = l;
    while(p->next != NULL)
    {
        p = p->next;
    }
    node *tmp = (node *)malloc(sizeof(node));
    tmp->tp = x;
    tmp->next = NULL;
    p->next = tmp;
    return l;
}

void inp(add *p)
{
    printf("\nNhap ten: "); fflush(stdin);
    gets(p->name);
    printf("\nNhap tel: "); fflush(stdin);
    gets(p->tel);
    printf("\nNhap email: "); fflush(stdin);
    gets(p->email);
}

void FreeList(node *l)
{
    node *p = l;
    while(p != NULL)
    {
        l = l->next;
        free(p);
        p = l;
    }
}

void printList(node *l)
{
    node *p = l;
    int i = 1;
    printf("\n%-5s%-30s%-30s%-30s\n", "", "Name", "Tel", "Email");
    while(p != NULL)
    {
        //for(i = 0; i < num; ++i)
        printf("%-5d%-30s%-30s%-30s\n", i, p->tp.name, p->tp.tel, p->tp.email);
        p = p->next;
        i++;
    }
    //printf("\n");
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
        add *a = (add *)malloc(MAX * sizeof(add));
        int num = fread(a, sizeof(add), MAX, f);
        int i;
        printf("\nRead value: %d.\n", num);
        /*printf("\n%-30s%-30s%-30s\n", "Name", "Tel", "Email");
        for(i = 0; i < num; ++i)
        {
            printf("%-30s%-30s%-30s\n", a[i].name, a[i].tel, a[i].email);
        }*/
        node *l = createNode(a[0]);
        node *p = l;
        for(i = 1; i < num; ++i)
        {
            p = addEle(p, a[i]);
        }
        printf("\nBan dau:\n");
        printList(l);

        int opt;
        add them;
        int vitri;
        do
        {
            printf("\n1. Insert At Head.\n2. Insert At Selected Position.\n3. Exit.\n");
            printf("\nEnter your option: "); fflush(stdin);
            scanf("%d", &opt);
            switch(opt)
            {
                case 1: 
                    printf("\nNhap thong tin danh ba muon them:\n");
                    inp(&them);
                    l = InsertHead(l, them);
                    /*printf("\nThong tin da nhap:\n\n%-30s%-30s%-30s\n", "Name", "Tel", "Email");
                    printf("%-30s%-30s%-30s\n", them.name, them.tel, them.email); */
                    printf("\nSau khi them:\n");
                    printList(l);
                    break;
                case 2:
                    printf("\nNhap thong tin danh ba muon them:\n");
                    inp(&them);
                    printf("\nNhap vi tri muon them: ");
                    fflush(stdin); scanf("%d", &vitri);
                    l = InsertAt(l, them, vitri);
                    /*printf("\nThong tin da nhap:\n\n%-30s%-30s%-30s\n", "Name", "Tel", "Email");
                    printf("%-30s%-30s%-30s\n", them.name, them.tel, them.email); */
                    printf("\nSau khi them:\n");
                    printList(l);
                    break;
                case 3:
                    printf("\nThanks!\n");
                    break;
                default:
                    printf("\nKhong ton tai chuc nang tuong ung!\n");
                    break;
            }
        } while (opt != 3);
        
        printf("\nClosing...!\n\n");
        free(a);
        fclose(f);
        return 0;
    }
    return 0;
}