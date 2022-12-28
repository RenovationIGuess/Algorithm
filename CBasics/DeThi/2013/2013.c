#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define MAX 256

FILE *f;
int e_num;

struct team
{
    char name[35];
    int score;
};
typedef struct team ElmType;
#include "Tree.h"

void Func2(treetype *t)
{
    printf("\n%-20s%-10s\n", "Ma doi bong", "Diem so");
    Inorder(*t);
}

void Func1(treetype *t, char *s)
{
    if((f = fopen(s, "r")) == NULL)
    {
        printf("\nCannot open file %s!\n", s);
        exit(1);
    }
    ElmType a, b;
    treetype f1 = NULL, f2 = NULL;
    int i = 0;
    char c;
    int score1, score2;
    while(fscanf(f, "%s%s%d%d", a.name, b.name, &score1, &score2) != EOF)
    {
        //printf("%-20s%-20s%-10d%-10d\n", a.name, b.name, score1, score2);
        f1 = Search(a.name, *t);
        f2 = Search(b.name, *t);
        if(f1 == NULL)
        {
            a.score = 0;
            InsertNode(a, t);
            f1 = Search(a.name, *t);
            i++;
            printf("\nNode duoc them thu %d - ma %s - dia chi: %p\n", i, f1->element.name, &f1);
        }
        if(f2 == NULL)
        {
            b.score = 0;
            InsertNode(b, t);
            f2 = Search(b.name, *t);
            i++;
            printf("\nNode duoc them thu %d - ma %s - dia chi: %p\n", i, f2->element.name, &f2);
        }
        if(score1 > score2)
        {
            f1->element.score += 3;
        }
        else if(score1 < score2)
        {
            f2->element.score += 3;
        }
        else 
        {
            f1->element.score++;
            f2->element.score++;
        } 
        //printf("%d %d\n", f1->element.score, f2->element.score);
    }
    e_num = i;
    Func2(t);
    fclose(f);
}

void Func3(treetype *t)
{
    char *find = (char *)malloc(MAX * sizeof(char));
    char opt;
    do
    {
        Func2(t);
        printf("\nNhap ma doi bong can tim: ");
        fflush(stdin); gets(find);
        treetype res = Search(find, *t);
        if(res != NULL)
        {
            printf("Diem cua doi %s la %d diem\n", res->element.name, res->element.score);        
        }
        else printf("\nKhong co doi bong nay!\n");
        printf("\nBan co muon tiep tuc ? [y/n]: ");
        fflush(stdin); scanf("%c", &opt);
        while(opt != 'y' && opt != 'n')
        {
            printf("\nInvalid! Enter again: ");
            fflush(stdin); scanf("%c", &opt);
        }
    } while (opt == 'y');
}

void Oper4(int x, treetype *t)
{
    if((*t) != NULL)
    {
        Oper4(x, &(*t)->left);
        if((*t)->element.score < x)
        {
            printf("%-20s%-10d\n", (*t)->element.name, (*t)->element.score);
            DeleteNode((*t)->element.name, t);
        }
        Oper4(x, &(*t)->right);
    }
}

void Func4(treetype *t)
{
    int x;
    printf("\nHay nhap so X: ");
    fflush(stdin); scanf("%d", &x);
    printf("\nCac doi bong bi xuong hang:\n");
    printf("\n%-20s%-10s\n", "Ma doi bong", "Diem so");
    Oper4(x, t);
    printf("\nCac doi khong xuong hang:\n");
    Func2(t);
}

void Oper5(treetype t)
{
    if(t != NULL)
    {
        Oper5(t->left);
        fprintf(f, "%-20s%-10d\n", t->element.name, t->element.score);
        Oper5(t->right);
    }
}

void Func5(treetype *t, char *s1)
{
    if((f = fopen(s1, "w")) == NULL)
    {
        printf("\nCannot open file %s!\n", s1);
        exit(1);
    }
    Oper5(*t);
    printf("\nXuat ra file thanh cong!\n");
    fclose(f);    
}

void Menu(treetype *t, char *s, char *s1)
{
    printf("\nMenu:\n");
    int opt;
    do
    {
        printf("\n1. Tao cay\n2. Ket qua\n3. Tim kiem\n4. Xuong hang\n5. Xuat file\n6. Exit\n");
        printf("\nHay nhap lua chon: ");
        fflush(stdin); scanf("%d", &opt);
        switch(opt)
        {
            case 1:
                Func1(t, s);
                break;
            case 2:
                Func2(t);
                break;
            case 3:
                Func3(t);
                break;
            case 4:
                Func4(t);
                break;
            case 5:
                Func5(t, s1);
                break;
            case 6:
                printf("\nHen gap lai!\n");
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
    Menu(&t, argv[1], argv[2]);
    return 0;
}