#include<stdio.h>
#include<stdlib.h>
#include<string.h>

const int MAX = 1001;

int n;

int fibo(int x, int *a)
{
    if(x <= 1) return 1;
    else
    {
        if(a[x] == 0) a[x] = fibo(x - 1, a) + fibo(x - 2, a);
    }
    return a[x];
}

int main()
{
    printf("Nhap n: ");
    fflush(stdin);
    scanf("%d", &n);
    int *a = (int *)malloc(sizeof(int) * n);
    memset(a, 0, sizeof(int) * n);
    for(int i = 0; i < n; ++i)
    {
        printf("%d ", fibo(i, a));
    }
    free(a);
    return 0;
}