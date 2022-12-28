#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 512

FILE *f;
//so ma co phieu
int n;
//so ngay
int day;

struct cp
{
    char name[5];
    float open;
    float close;
    float tb;
};

typedef struct cp ElmType;
//typedef struct  et;
#include "treeformat.h"

void func1(char *s, treetype *t)
{
    if((f = fopen(s, "r")) == NULL)
    {
        printf("\nKhong the mo file!\n");
        return;
    }
    ElmType tmp;
    int i;
    day = 10;
    fscanf(f, "%d", &n);
    do
    {
        for(i = 0; i < n; ++i)
        {
            fscanf(f, "%s%f%f", tmp.name, &tmp.open, &tmp.close);
            tmp.tb = tmp.close - tmp.open;
            //printf("%s - %.3f - %.3f\n", tmp.name, tmp.open, tmp.close);
            InsertNode(tmp, t);
        }
        if(feof(f)) break;
    } while (1);
    printf("\n%-10s%-10s\n", "Ma CK", "GTTB");
    Inorder(*t);
    printf("\nNumber of node: %d\n", nb_nodes(*t));
    fclose(f);
}

int TimTen(treetype t, ElmType *tmp, char *find)
{
    treetype p = t;
    int cnt = 0;
    while(t)
    {
        if(t->left == NULL)
        {
            if(strcmp(t->element.name, find) == 0)
            {
                tmp[cnt] = t->element;
                cnt++;
            }
            t = t->right;
        }
        else
        {
            p = t->left;
            while(p->right && p->right != t)
            {
                p = p->right;
            }
            if(p->right == NULL)
            {
                p->right = t;
                t = t->left;
            }
            else
            {
                p->right = NULL;
                if(strcmp(t->element.name, find) == 0)
                {
                    tmp[cnt] = t->element;
                    cnt++;
                }
                t = t->right;
            }
        }
    }
    return cnt;
}

void func2(treetype *t)
{
    char *find = (char *)malloc(MAX * sizeof(char));
    ElmType *tmp = (ElmType *)malloc(MAX * sizeof(ElmType));
    int size, i;
    //kich thuoc cua mang tmp
    char opt;
    do
    {
        printf("\nNhap ma chung khoan: ");
        scanf("%s", find); getchar();
        if(Search(find, *t) != NULL)
        {
            size = TimTen(*t, tmp, find);
            float max = -100000, min = 100000;
            for(i = 0; i < size; ++i)
            {
                if(tmp[i].open > max)
                {
                    max = tmp[i].open;
                }
                if(tmp[i].open < min)
                {
                    min = tmp[i].open;
                }
            }
            printf("\n%-10s%-10s%-10s\n", "Ma CK", "Min", "Max");
            printf("%-10s%-10.3f%-10.3f\n", find, min, max);
        }
        else printf("\nKhong tim thay!\n");

        printf("\nBan co muon tiep tuc [y/n]: ");
        scanf("%c", &opt);
        getchar();
        while(opt != 'y' && opt != 'n')
        {
            printf("\nKhong hop le! Nhap lai: ");
            scanf("%c", &opt); getchar();
        }
        if(opt == 'n') break;
    } while (1);
}

void func3(char *s)
{
    if((f = fopen(s, "r")) == NULL)
    {
        printf("\nKhong the mo file!\n");
        return;
    }
    ElmType *tmp = (ElmType *)malloc(MAX * sizeof(ElmType));
    int i, j, found = 0;
    fscanf(f, "%d", &n);
    for(i = 0; i < 14; ++i)
    {
        fscanf(f, "%s%f%f", tmp[i].name, &tmp[i].open, &tmp[i].close);
    }
    for(i = 0; i < 7; ++i)
    {
        if(tmp[i].close > tmp[i].open)
        {
            for(j = 7; j < 14; ++j)
            {
                if(strcmp(tmp[i].name, tmp[j].name) == 0)
                {
                    if(tmp[j].close > tmp[j].open)
                    {
                        if(found == 0)
                        {
                            found = 1;
                            printf("\n%-10s%-10s%-10s\n", "Ma CK", "Open", "Close");
                        }
                        printf("%-10s%-10.3f%-10.3f\n", tmp[i].name, tmp[i].open, tmp[i].close);
                        printf("%-10s%-10.3f%-10.3f\n\n", tmp[j].name, tmp[j].open, tmp[j].close);
                    }
                }
            }
        }
    }
    if(found == 0) printf("\nKhong co ma ck thoa man yeu cau!\n");
    fclose(f);
}

/*int mini4(treetype t, ElmType *tmp)
{
    treetype p = t;
    int cnt = 0;
    while(t)
    {
        if(t->left == NULL)
        {
            tmp[cnt] = t->element;
            cnt++;
            t = t->right;
        }
        else
        {
            p = t->left;
            while(p->right && p->right != t)
            {
                p = p->right;
            }
            if(p->right == NULL)
            {
                p->right = t;
                t = t->left;
            }
            else
            {
                p->right = NULL;
                tmp[cnt] = t->element;
                cnt++;
                t = t->right;
            }
        }
    }
    return cnt;
} */

void QuickSort(ElmType *a, int l, int r)
{
    ElmType tmp;
    ElmType p = a[(l + r)/2];
    int i = l, j = r;
    while(i < j)
    {
        while(strcmp(a[i].name, p.name) < 0) i++;
        while(strcmp(a[j].name, p.name) > 0) j--;
        if(i <= j)
        {
            tmp = a[i];
            a[i] = a[j];
            a[j] = tmp;
            i++; j--;
        }
    }
    if(i < r) QuickSort(a, i, r);
    if(j > l) QuickSort(a, l, j);
}

void func4(char *s)
{
    if((f = fopen(s, "r")) == NULL)
    {
        printf("\nKhong the mo file!\n");
        return;
    }
    ElmType *tmp = (ElmType *)malloc(MAX * sizeof(ElmType));
    char *ma = (char *)malloc(MAX * sizeof(char));
    int size = 0;
    int i, j;
    /*for(i = 0; i < size; ++i)
    {
        printf("%-10s%-10.3f%-10.3f\n", tmp[i].name, tmp[i].open, tmp[i].close);
    } */
    fscanf(f, "%d", &n);
    do
    {
        fscanf(f, "%s%f%f", tmp[size].name, &tmp[size].open, &tmp[size].close);
        //printf("%-10s%-10.3f%-10.3f\n", tmp[size].name, tmp[size].open, tmp[size].close);
        size++;
        if(feof(f)) break;
    } while (1);
    printf("\nNumber of nodes: %d\n", size);
    QuickSort(tmp, 0, size - 1);
    int max = -10000;
    int cnt = 0;
    for(i = 0; i < size; i += 10)
    {
        //printf("%-10s%-10.3f%-10.3f\n", tmp[i].name, tmp[i].open, tmp[i].close);
        for(j = i; j < i + 10; ++j)
        {
            //printf("%-10s%-10.3f%-10.3f\n", tmp[j].name, tmp[j].open, tmp[j].close);
            if(tmp[j].close > tmp[j].open) cnt++;
            //else cnt = 0;
        }
        //printf("\n");
        if(cnt > max) 
        {
            //strcpy(ma, tmp[i].name);
            max = cnt;
        }
        cnt = 0;
    }
    //printf("%d\n", max);
    cnt = 0;
    printf("\n%-10s%-20s\n", "Ma CK", "So ngay tang");
    for(i = 0; i < size; i += 10)
    {
        for(j = i; j < i + 10; ++j)
        {
            if(tmp[j].close > tmp[j].open) 
            {
                printf("%-10s%-10.3f%-10.3f\n", tmp[j].name, tmp[j].open, tmp[j].close);
                cnt++;
            }
            //else cnt = 0;
        }
        printf("\n");
        if(cnt == max) 
        {
            printf("%-10s%-20d\n", tmp[i].name, max);
        }
        cnt = 0;
    }
    fclose(f);
}

void menu(char *s, treetype *t)
{
    int opt;
    char c;
    do
    {
        printf("\n1. Doc file\n2. Tim kiem theo ma chung khoan\n3. Tim kiem ma ck co xu huong tang\n4. Tim ma co so ngay tang max\n5. Thoat\n");
        printf("\nHay nhap lua chon: ");           
        scanf("%d", &opt);    
        //while(c = getchar() == '\n')  
        getchar();    
        switch(opt)
        {
            case 1:
                func1(s, t);
                break;
            case 2:
                func2(t);
                break;
            case 3:
                func3(s);
                break;
            case 4:
                func4(s);
                break;
            case 5:
                printf("\nHo va ten: Nguyen Tung Lam\n");
                printf("MSSV: 20204998\n");
                break;
            default:
                printf("\nInvalid!\n");
                break;
        }                                                                                                                              
    } while(opt != 5);
}

int main(int argc, char *argv[])
{
    treetype t;
    MakeNullTree(&t);
    menu(argv[1], &t);
    MakeNullTree(&t);
    FreeTree(&t);
    return 0;
}