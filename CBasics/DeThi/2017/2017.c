#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

FILE *f;
int n, k;

typedef struct 
{
    char ten[30];
    int id, diem, win, lose;
} et;

#include "singlel.h"

typedef struct
{
    int id1[MAX], id2[MAX];
} round;

node *search(int id)
{
    node *p = l;
    while(p != NULL)
    {
        if(p->data.id == id)
            return p;
        p = p->next;
    }
}

void func4()
{
    node *p = l;
    int min = p->data.diem;
    while(p != NULL)
    {
        if(p->data.diem < min)
        {
            min = p->data.diem;
        }
        p = p->next;
    }
    p = l;
    printf("\nCac doi co diem thap nhat la:\n");
    printf("%-10s%-35s%-10s%-20s%-20s\n", "Id", "Tendoibong", "Diem", "Sobanthang", "Sobanthua");
    while(p != NULL)
    {
        cur = p;
        p = p->next;
        if(cur->data.diem == min)
        {
            displayNode(cur);
            if(cur == l)
            {
                deleteHead();
            }
            else if(cur->next == NULL) deleteTail();
            else deleteMiddle();
            
        }
    }
    printf("\nCac doi con lai la:\n");
    printf("%-10s%-35s%-10s%-20s%-20s\n", "Id", "Tendoibong", "Diem", "Sobanthang", "Sobanthua");
    printList();
}

void func3(round *b)
{
    int i, j;
    char *res = (char *)malloc(MAX * sizeof(char));
    for(i = 1; i <= n - 1; ++i)
    {
        printf("\nCap nhat ket qua vong %d:\n", i);
        printf("Vong %d\n", i);
        for(j = 1; j <= k; ++j)
        {
            node *n1 = search(b[i].id1[j]);
            node *n2 = search(b[i].id2[j]);
            printf("%s - %s: ", n1->data.ten, n2->data.ten);
            fflush(stdin); gets(res);
            int g1 = res[0] - '0';
            int g2 = res[4] - '0';
            n1->data.win += g1; n1->data.lose += g2;
            n2->data.win += g2; n2->data.lose += g1;
            if(g1 > g2) n1->data.diem += 3;
            else if(g1 < g2) n2->data.diem += 3;
            else
            {
                n1->data.diem++;
                n2->data.diem++;
            }
        }
    }
    printf("\n%-10s%-35s%-10s%-20s%-20s\n", "Id", "Tendoibong", "Diem", "Sobanthang", "Sobanthua");
    printList();
}

void func2(round *b)
{
    int i, j;
    for(i = 1; i <= n - 1; ++i)
    {
        printf("\nVong %d\n", i);
        for(j = 1; j <= k; ++j)
        {
            printf("%s - %s\n", search(b[i].id1[j])->data.ten, search(b[i].id2[j])->data.ten);
        }
    }
}

void func1(round *b, char *s)
{
    if((f = fopen(s, "r")) == NULL)
    {
        printf("\nKhong the mo file %s!\n", s);
        return;
    }
    et add;
    char c;
    int j;
    fscanf(f, "%d", &n);
    k = n / 2;
    int i;
    for(i = 1; i <= n; ++i)
    {
        fscanf(f, "%d", &add.id);
        do
        {
            c = fgetc(f);
        } while (c == ' ' || c == '\t');
        
        j = 0; add.ten[j] = c; j++;
        while((c = fgetc(f)) != '\n' && c != EOF)
        {
            add.ten[j] = c;
            j++;
        }
        add.ten[j] = '\0';
        add.diem = add.win = add.lose = 0;
        //printf("%-10d%-35s%-10d%-20d%-20d\n", add.id, add.ten, add.diem, add.win, add.lose);
        InsertAtHead(add);
    }
    reverseList();
    printf("\n%-10s%-35s%-10s%-20s%-20s\n", "Id", "Tendoibong", "Diem", "Sobanthang", "Sobanthua");
    printList();
    for(i = 1; i <= n - 1; ++i)
    {
        do
        {
            c = fgetc(f);
        } while (c == ' ' || c == '\t');
        
        j = 0; add.ten[j] = c; j++;
        while((c = fgetc(f)) != '\n' && c != EOF)
        {
            add.ten[j] = c;
            j++;
        }
        add.ten[j] = '\0';
        //printf("\n%s\n", add.ten);
        for(j = 1; j <= k; ++j)
        {
            fscanf(f, "%d", &b[i].id1[j]);
            fgetc(f);
            fscanf(f, "%d", &b[i].id2[j]);
            //printf("%-10d%-10d\n", b[i].id1[j], b[i].id2[j]);
        }
    }
}   

void menu(round *b, char *s)
{
    int opt;
    do
    {
        printf("\n==========Giai bong da!==========\n");
        printf("1. In thong tin cac doi bong\n2. In thong tin lich thi dau\n3. Cap nhat ket qua vong dau\n4. Thong ke\n5. Thoat\n");
        printf("\nHay nhap lua chon: ");
        fflush(stdin); scanf("%d", &opt);
        switch(opt)
        {
            case 1:
                func1(b, s);
                break;
            case 2:
                func2(b);
                break;
            case 3:
                func3(b);
                break;
            case 4:
                func4();
                break;
            case 5:
                printf("\nCam on va hen gap lai!\n");
                break;
            default:
                printf("\nKhong hop le!\n");
                break;
        }
    } while (opt != 5);
    
}

int main(int argc, char *argv[])
{
    l = cur = prev = NULL;
    round *bang = (round *)malloc(MAX * sizeof(round));
    menu(bang, argv[1]);
    FreeList();
    free(bang);
    return 0;
}