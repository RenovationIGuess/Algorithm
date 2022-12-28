#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define MAX 256

FILE *f;
int total;

struct info
{
    int num;
    char toy[35];
};

typedef struct
{
    char name[35];
    int app;
} toys;

typedef struct info ElmType;

#include "tree.h"

void Func1(treetype *t, char *s1)
{
    if((f = fopen(s1, "r")) == NULL)
    {
        printf("\nCannot open file %s!\n", s1);
        exit(1);
    }
    ElmType tmp;
    char c, opt;
    int j;
    do
    {
        fscanf(f, "%d", &tmp.num);
        fgetc(f);
        j = 0;
        while((c = fgetc(f)) != '\n' && c != EOF)
        {
            tmp.toy[j] = c;
            j++;
        }
        tmp.toy[j] = '\0'; 
        //printf("%-10d%-35s\n", tmp.num, tmp.toy);
        //printf("%d\n", strlen(tmp.toy));
        if(tmp.toy[0] == '\0')
        {
            printf("\nThong tin do choi cua ma %d dang bi thieu, ban co muon bo sung? [y/n]: ", tmp.num);
            fflush(stdin); scanf("%c", &opt);
            while(opt != 'y' && opt != 'n')
            {
                printf("\nKhong hop le! Hay nhap lai: ");
                fflush(stdin); scanf("%c", &opt);
            }
            if(opt == 'y')
            {
                printf("\nHay nhap ten do choi: ");
                fflush(stdin); gets(tmp.toy);
            }
        }
        InsertNode(tmp, t);
        if(feof(f)) break;
    } while(1);

    printf("\nDoc thanh cong!\n");
    printf("\n%-10s%-35s\n", "Ma so", "Do choi");
    Inorder(*t);
    fclose(f);
}

void Func2(ElmType *a, char *s2)
{
    if((f = fopen(s2, "r")) == NULL)
    {
        printf("\nCannot open file %s\n", s2);
        exit(1);
    }
    char c, opt;
    int i = 0, j;
    do
    {
        fscanf(f, "%d", &a[i].num);
        fgetc(f);
        j = 0;
        while((c = fgetc(f)) != '\n' && c != EOF)
        {
            a[i].toy[j] = c;
            j++;
        }
        a[i].toy[j] = '\0'; 
        //printf("%d\n", strlen(a[i].toy));
        if(a[i].toy[0] == '\0')
        {
            printf("\nThong tin do choi cua ma %d dang bi thieu, ban co muon bo sung? [y/n]: ", a[i].num);
            fflush(stdin); scanf("%c", &opt);
            while(opt != 'y' && opt != 'n')
            {
                printf("\nKhong hop le! Hay nhap lai: ");
                fflush(stdin); scanf("%c", &opt);
            }
            if(opt == 'y')
            {
                printf("\nHay nhap ten do choi: ");
                fflush(stdin); gets(a[i].toy);
            }
        }
        if(i == 0) printf("\n%-10s%-35s\n", "Ma so", "Do choi");
        printf("%-10d%-35s\n", a[i].num, a[i].toy);
        i++;
        if(feof(f)) break;
    } while(1);
    total = i;
    printf("\nDoc thanh cong!\n");
    fclose(f);
}

void Func3(ElmType *a, treetype *t)
{
    int i, found = 0;
    treetype find;
    for(i = 0; i < total; ++i)
    {
        find = Search(a[i], *t);
        if(find != NULL)
        {
            if(!found) found = 1;
            if(i == 0) 
            {
                printf("\nThong tin nhung em bi lap:\n");
                printf("%-10s%-35s\n", "Ma so", "Do choi");
            }
            printf("%-10d%-35s\n", a[i].num, a[i].toy);
            DeleteNode(a[i], t);
        }
    }
    printf("\nCay A sau khi tim kiem:\n");
    printf("%-10s%-35s\n", "Ma so", "Do choi");
    Inorder(*t);
}

void Func4(ElmType *a, treetype *t)
{
    int i;
    for(i = 0; i < total; ++i)
    {
        InsertNode(a[i], t);
    }
    RNL(*t);
}

int find(toys *a, int num)
{
    //if(num == 0) return -1;
    int i;
    for(i = 0; i < num; ++i)
    {
        if(strcmp(a[i].name, a[num].name) == 0) return i;
    }
    return -1;
}

void mini5(treetype t)
{
    toys *names = (toys *)malloc(MAX * sizeof(toys));
    int i = 0, j, pos; 
    treetype p = t;
    while(t)
    {
        if((t)->left == NULL)
        {
            if(isalpha(t->element.toy[0]) != 0)
            {
                strcpy(names[i].name, (t)->element.toy);
                pos = find(names, i);
                //printf("%s - %d\n", names[i].name, pos);
                if(pos == -1)
                {
                    //printf("%d - %s\n", i + 1, names[i].name);
                    names[i].app = 1;
                    i++;
                }
                else names[pos].app++;
            }
            (t) = (t)->right;
        }
        else
        {
            p = (t)->left;
            while(p->right && p->right != t)
            {
                p = p->right;
            }
            if(p->right == NULL)
            {
                p->right = t;
                t = (t)->left;
            }
            else
            {
                p->right = NULL;
                if(isalpha(t->element.toy[0]) != 0)
                {
                    strcpy(names[i].name, (t)->element.toy);
                    pos = find(names, i);
                    //printf("%s - %d\n", names[i].name, pos);
                    if(pos == -1)
                    {
                        //printf("%d - %s\n", i + 1, names[i].name);
                        names[i].app = 1;
                        i++;
                    }
                    else names[pos].app++;
                }
                t = (t)->right;
            }
        }
    }
    for(j = 0; j < i; ++j)
        printf("%d - %-20s%-5d\n", j + 1, names[j].name, names[j].app);
}

void Func5(treetype *t)
{
    printf("\nTen do choi:\n");   
    mini5(*t);
    //Preorder(*t);
    //printf("\nSo em nho da lua chon: %d\n", nb_nodes(*t));
}

void menu(ElmType *a, treetype *t, char *s1, char *s2)
{
    int opt, pick1 = 0, pick2 = 0, pick3 = 0, pick4 = 0;
    printf("\nMenu:\n");
    do
    {
        printf("\n1. Doc file A\n2. Doc file B\n3. Tim kiem\n4. Tong hop\n5. Thong ke\n6. Thoat\n");
        printf("\nLua chon chuc nang: ");
        fflush(stdin); scanf("%d", &opt);
        switch (opt)
        {
        case 1:
            if(pick1 == 0) pick1 = 1;
            Func1(t, s1);
            break;
        case 2:
            if(pick2 == 0) pick2 = 1;
            Func2(a, s2);
            break;
        case 3:
            if(pick1 == 0 && pick2 == 0)
            {
                printf("\nHay chon 1 va 2 truoc!\n");
                break;
            }
            if(pick3 == 0) pick3 = 1;
            Func3(a, t);
            break;
        case 4:
            if(pick1 == 0 && pick2 == 0)
            {
                printf("\nHay chon 1 va 2 truoc!\n");
                break;
            }
            if(pick3 == 0) 
            {
                printf("\nHay chon 3 truoc!\n");
                break;
            }
            if(pick4 == 0) pick4 = 1;
            Func4(a, t);
            break;
        case 5:
            if(pick1 == 0 && pick2 == 0)
            {
                printf("\nHay chon 1 va 2 truoc!\n");
                break;
            }
            if(pick3 == 0) 
            {
                printf("\nHay chon 3 truoc!\n");
                break;
            }
            if(pick4 == 0) 
            {
                printf("\nHay chon 4 truoc!\n");
                break;
            }
            Func5(t);
            break;
        case 6:
            printf("\nCam on va hen gap lai!\n");
            break;
        default:
            printf("\nKhong hop le!\n");
            break;
        }
    } while (opt != 6);
    
}

int main(int argc, char *argv[])
{
    treetype t;
    MakeNullTree(&t);
    ElmType *a = (ElmType *)malloc(MAX * sizeof(ElmType));
    menu(a, &t, argv[1], argv[2]);
    MakeNullTree(&t);
    FreeTree(&t);
    free(a);
    return 0;
}