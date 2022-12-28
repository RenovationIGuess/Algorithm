#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#define MAX 100001

int a[MAX];
int n;

int random(int minN, int maxN)
{
    return minN + rand() % (maxN + 1 - minN);
}

void insert(int p, int value)
{
    if(p > n - 1)
    {
        a[n] = value;
        n++;
        return;
    }
    int j;
    for(j = n - 1; j >= p; --j)
    {
        a[j + 1] = a[j];
    }
    a[p] = value;
    n++;
}

void delete(int p)
{
    if(p > n - 1) 
    {
        printf("\nNon - existed!\n");
        return;
    }
    int j;
    for(j = p + 1; j < n; ++j)
    {
        a[j - 1] = a[j];
    }
    n--;
}

int retrieve(int p)
{
    return a[p];
}

int locate(int x)
{
    int j;
    for(j = 0; j < n; ++j)
    {
        if(a[j] == x) return j;
    }
    return -1;
}

void makeNULL()
{
    n = 0;
}

int next(int p)
{
    if(p >= 0 && p < n - 1) return p + 1;
    return -1;
}

int prev(int p)
{
    if(p > 0 && p <= n - 1) return p - 1;
    return -1;
}

int next1(int p)
{
    if(p >= 0 && p < n - 1) return a[p + 1];
    return -1;
}

int prev1(int p)
{
    if(p > 0 && p <= n - 1) return a[p - 1];
    return -1;
}

void print()
{
    int i;
    printf("So phan tu : %d.\nMang:\n", n);
    for(i = 0; i < n; ++i)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main()
{
    srand((int)time(0));

    printf("Nhap n: ");
    fflush(stdin);
    scanf("%d", &n);
    printf("\n");

    int i;

    for(i = 0; i < n; ++i)
    {
        a[i] = random(1, n + 1);
    }
    print();
    /*
    for(i = 0; i < n; ++i)
    {
        printf("Phan tu mang a[%d] = ", i);
        fflush(stdin);
        scanf("%d", &a[i]);
    }
    printf("\n");
    */

    //Xoa 50 vi tri random
    for(i = 0; i < 50; ++i)
    {
        int p = random(0, n - 1);
        delete(p);
    }
    printf("\nSau khi xoa:\n");
    print();

    for(i = 0; i < 50; ++i)
    {
        int p = random(0, n - 1);
        int x = random(1, n);
        insert(p, x);
    }
    printf("\nSau khi them:\n");
    print();

    delete(n + 2);
    printf("\nSau khi xoa:\n");
    print();

    insert(n + 2, 0);
    printf("\nSau khi them:\n");
    print();
    return 0;
}